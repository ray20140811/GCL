;; Copyright (C) 1994 M. Hagiya, W. Schelter, T. Yuasa

;; This file is part of GNU Common Lisp, herein referred to as GCL
;;
;; GCL is free software; you can redistribute it and/or modify it under
;;  the terms of the GNU LIBRARY GENERAL PUBLIC LICENSE as published by
;; the Free Software Foundation; either version 2, or (at your option)
;; any later version.
;; 
;; GCL is distributed in the hope that it will be useful, but WITHOUT
;; ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
;; FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public 
;; License for more details.
;; 
;; You should have received a copy of the GNU Library General Public License 
;; along with GCL; see the file COPYING.  If not, write to the Free Software
;; Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.


;;;;    numlib.lsp
;;;;
;;;;                           number routines


(in-package 'lisp)
(export
 '(isqrt abs phase signum cis asin acos sinh cosh tanh
   asinh acosh atanh
   rational rationalize
   ffloor fround ftruncate fceiling
   lognand lognor logandc1 logandc2 logorc1 logorc2
   lognot logtest
   byte byte-size byte-position
   ldb ldb-test mask-field dpb deposit-field
   ))


(in-package 'system)


(proclaim '(optimize (safety 2) (space 3)))


(defconstant imag-one #C(0.0d0 1.0d0))


(defun isqrt (i)
       (unless (and (integerp i) (>= i 0))
               (error "~S is not a non-negative integer." i))
       (if (zerop i)
           0
           (let ((n (integer-length i)))
                (do ((x (ash 1 (ceiling n 2)))
                     (y))
                    (nil)
                    (setq y (floor i x))
                    (when (<= x y)
                          (return x))
                    (setq x (floor (+ x y) 2))))))

(defun abs (x)
       (if (complexp x)
           (sqrt (+ (* (realpart x) (realpart x))
                    (* (imagpart x) (imagpart x))))
           (if (minusp x)
               (- x)
               x)))

(defun phase (x)
       (atan (imagpart x) (realpart x)))

(defun signum (x) (if (zerop x) x (/ x (abs x))))

(defun cis (x) (exp (* imag-one x)))

(defun asin (x)
       (let ((c (- (* imag-one
                      (log (+ (* imag-one x)
                              (sqrt (- 1.0d0 (* x x)))))))))
            (if (or (and (not (complexp x))
			  (<= x 1.0d0)
			   (>= x -1.0d0)
			    )
		        (zerop (imagpart c)))
                (realpart c)
                c)))

(defun acos (x)
       (let ((c (- (* imag-one
                      (log (+ x (* imag-one
                                   (sqrt (- 1.0d0 (* x x))))))))))
            (if (or (and (not (complexp x))
			  (<= x 1.0d0)
			   (>= x -1.0d0)
			    )
		        (zerop (imagpart c)))
                (realpart c)
                c)))


(defun sinh (x) (/ (- (exp x) (exp (- x))) 2.0d0))
(defun cosh (x) (/ (+ (exp x) (exp (- x))) 2.0d0))
(defun tanh (x) (/ (sinh x) (cosh x)))

(defun asinh (x) (log (+ x (sqrt (+ 1.0d0 (* x x))))))
(defun acosh (x)
       (log (+ x
               (* (1+ x)
                    (sqrt (/ (1- x) (1+ x)))))))
(defun atanh (x)
       (when (or (= x 1.0d0) (= x -1.0d0))
             (error "The argument, ~s, is a logarithmic singularity.~
                    ~%Don't be foolish, GLS."
                    x))
       (log (/ (1+ x) (sqrt (- 1.0d0 (* x x))))))


(defun rational (x)
  (etypecase x
    (float	  
      (multiple-value-bind (i e s) (integer-decode-float x)
			   (if (>= s 0)
			       (* i (expt (float-radix x) e))
			     (- (* i (expt (float-radix x) e))))))
    (rational x)))


(setf (symbol-function 'rationalize) (symbol-function 'rational))

;; although the following is correct code in that it approximates the
;; x to within eps, it does not preserve (eql (float (rationalize x) x) x)
;; since the test for eql is more strict than the float-epsilon

;;; Rationalize originally by Skef Wholey.
;;; Obtained from Daniel L. Weinreb.
;(defun rationalize (x)
;  (typecase x
;    (rational x)
;    (short-float (rationalize-float x short-float-epsilon 1.0s0))
;    (long-float (rationalize-float x long-float-epsilon 1.0d0))
;    (otherwise (error "~S is neither rational nor float." x))))
;
;(defun rationalize-float (x eps one)
;  (cond ((minusp x) (- (rationalize (- x))))
;        ((zerop x) 0)
;        (t (let ((y ())
;                 (a ()))
;             (do ((xx x (setq y (/ one
;                                   (- xx (float a x)))))
;                  (num (setq a (truncate x))
;                       (+ (* (setq a (truncate y)) num) onum))
;                  (den 1 (+ (* a den) oden))
;                  (onum 1 num)
;                  (oden 0 den))
;                 ((and (not (zerop den))
;                       (not (> (abs (/ (- x (/ (float num x)
;                                               (float den x)))
;                                       x))
;                               eps)))
;                  (/ num den)))))))


(defun ffloor (x &optional (y 1.0s0))
       (multiple-value-bind (i r) (floor (float x) (float y))
        (values (float i r) r)))

(defun fceiling (x &optional (y 1.0s0))
       (multiple-value-bind (i r) (ceiling (float x) (float y))
        (values (float i r) r)))

(defun ftruncate (x &optional (y 1.0s0))
       (multiple-value-bind (i r) (truncate (float x) (float y))
        (values (float i r) r)))

(defun fround (x &optional (y 1.0s0))
       (multiple-value-bind (i r) (round (float x) (float y))
        (values (float i r) r)))


(defun lognand (x y) (boole boole-nand x y))
(defun lognor (x y) (boole boole-nor x y))
(defun logandc1 (x y) (boole boole-andc1 x y))
(defun logandc2 (x y) (boole boole-andc2 x y))
(defun logorc1 (x y) (boole boole-orc1 x y))
(defun logorc2 (x y) (boole boole-orc2 x y))

(defun lognot (x) (logxor -1 x))
(defun logtest (x y) (not (zerop (logand x y))))


(defun byte (size position)
  (cons size position))

(defun byte-size (bytespec)
  (car bytespec))

(defun byte-position (bytespec)
  (cdr bytespec))

(defun ldb (bytespec integer)
  (logandc2 (ash integer (- (byte-position bytespec)))
            (- (ash 1 (byte-size bytespec)))))

(defun ldb-test (bytespec integer)
  (not (zerop (ldb bytespec integer))))

(defun mask-field (bytespec integer)
  (ash (ldb bytespec integer) (byte-position bytespec)))

(defun dpb (newbyte bytespec integer)
  (logxor integer
          (mask-field bytespec integer)
          (ash (logandc2 newbyte
                         (- (ash 1 (byte-size bytespec))))
               (byte-position bytespec))))

(defun deposit-field (newbyte bytespec integer)
  (dpb (ash newbyte (- (byte-position bytespec))) bytespec integer))
