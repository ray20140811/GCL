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


;;;; This file is IMPLEMENTATION-DEPENDENT.


(in-package 'lisp)


(export 'time)
(export '(decode-universal-time encode-universal-time))


(in-package 'system)


(proclaim '(optimize (safety 2) (space 3)))


(defmacro time (form)
  `(let (real-start real-end run-start run-end x)
     (setq real-start (get-internal-real-time))
     (setq run-start (get-internal-run-time))
     (setq x (multiple-value-list ,form))
     (setq run-end (get-internal-run-time))
     (setq real-end (get-internal-real-time))
     (fresh-line *trace-output*)
     (format *trace-output*
             "real time : ~,3F secs~%~
              run time  : ~,3F secs~%"
             (/ (- real-end real-start) internal-time-units-per-second)
             (/ (- run-end run-start) internal-time-units-per-second))
     (values-list x)))


(defconstant month-days-list '(31 28 31 30 31 30 31 31 30 31 30 31))
(defconstant seconds-per-day #.(* 24 3600))

(defun leap-year-p (y)
  (and (zerop (mod y 4))
       (or (not (zerop (mod y 100))) (zerop (mod y 400)))))

(defun number-of-days-from-1900 (y)
  (let ((y1 (1- y)))
    (+ (* (- y 1900) 365)
       (floor y1 4) (- (floor y1 100)) (floor y1 400)
       -460)))

(defun decode-universal-time (ut &optional (tz *default-time-zone*))
  (let (sec min h d m y dow)
    (decf ut (* tz 3600))
    (multiple-value-setq (d ut) (floor ut seconds-per-day))
    (setq dow (mod d 7))
    (multiple-value-setq (h ut) (floor ut 3600))
    (multiple-value-setq (min sec) (floor ut 60))
    (setq y (+ 1900 (floor d 366)))  ; Guess!
    (do ((x))
        ((< (setq x (- d (number-of-days-from-1900 y)))
            (if (leap-year-p y) 366 365))
         (setq d (1+ x)))
      (incf y))
    (when (leap-year-p y)
          (when (= d 60)
                (return-from decode-universal-time
                             (values sec min h 29 2 y dow nil tz)))
          (when (> d 60) (decf d)))
    (do ((l month-days-list (cdr l)))
        ((<= d (car l)) (setq m (- 13 (length l))))
      (decf d (car l)))
    (values sec min h d m y dow nil tz)))

(defun encode-universal-time (sec min h d m y
                              &optional (tz *default-time-zone*))
  (incf h tz)
  (when (<= 0 y 99)
        (multiple-value-bind (sec min h d m y1 dow dstp tz)
            (get-decoded-time)
          (declare (ignore sec min h d m dow dstp tz))
          (incf y (- y1 (mod y1 100)))
          (cond ((< (- y y1) -50) (incf y 100))
                ((>= (- y y1) 50) (decf y 100)))))
  (unless (and (leap-year-p y) (> m 2)) (decf d 1))
  (+ (* (apply #'+ d (number-of-days-from-1900 y)
               (butlast month-days-list (- 13 m)))
        seconds-per-day)
     (* h 3600) (* min 60) sec))

