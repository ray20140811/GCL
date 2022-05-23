
;; This file sets up machinery to build a doc string file from
;; a number of lisp files.  Then it allows building of key pointers
;; into that file.  These can be used to complete and view documentation
;; in emacs.  I have tried to emulate the usage pattern of the tags facility
;; in order to make the doc facility easier to use.
;;  edoc <--> etags
;;  DOC  <--> TAGS
;;  visit-doc-file <--> visit-tags-table
;;  C-h d  <--> M-.

;; To create the doc strings file use edoc.
;; Usage: 
;; % edoc *.lisp
;; This creates a DOC file and a DOC-keys.el file.
;; Normally comments which appear where a doc string would have
;; been, will be used instead of the doc string.  Also comments
;; preceding or following a defvar will be used depending
;; on the setting of the variable comments-for-defvar.
;; You may set that variable in a .edoc file.
;; For c files you may use the appropriate primitive in emacs/etc
;; in order to create the DOC file.
;; For a lisp system for which you do not have sources (why are you using it!),
;; you may build a DOC file using the common lisp function doc-file
;; provided in this file.  You must then use the snarf-doc command, to
;; build the keys into the DOC file you have just created.
;; You may concatenate two DOC files.  Again you must use snarf-doc,
;; to build the keys.

;; To use the documentation so created do
;; M-x visit-doc-file to set up for using a particular DOC file.
;; Then C-hd (find-doc) will allow you to query the doc data base.


(defvar comments-for-defvar 'after)
;; If nil only use comments inside the defvar,
;; If the symbol 'after use comment following, and if 'before
;; use the comment before.

(defvar doc-start "")
;; The special string which starts each doc record. key used
(defvar doc-key-length 1)
;; The length of the description immediately following doc-start
;; which says if this is a function,...:  This field contains
;; F for function or M for macro V for variable,...


(defvar find-doc-name)
(defvar find-doc-args)
;Used internally by find-doc-args.

(defvar include-all-functions-and-args nil)
;;If t all functions, not just those with documentation, will be included.
(defvar include-args t)
;;If t a macro or function's args will be included.

;;Set up the common lisp syntax table.
(defvar common-lisp-syntax-table (copy-syntax-table lisp-mode-syntax-table))

(let* ((const "!$%&*+-./0123456789:<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz[]^_{}~")
       (i 0))
  (while (< i (length const))
    (modify-syntax-entry (aref const i) "w" common-lisp-syntax-table)
    (setq i (1+ i))))


(defun forward-over-white()
  (while (looking-at "[ 	\n]")
    (forward-char 1)))

(defun back-over-white()
  (let (tem)
  (while (looking-at "[ 	\n]")
    (setq tem t)
    (forward-char -1))
  (if tem (forward-char 1))
  ))


(defun make-doc (file out)
  "Create documentation for file"
  (find-file file)
  (let ((file-buf (current-buffer)))
  (if buffer-read-only (toggle-read-only))
  (goto-char (point-min))
  (set-syntax-table common-lisp-syntax-table)
  (setq doc-buf (generate-new-buffer "doc-buf"))
  (while (re-search-forward "^(def"  nil t)
          (condition-case er
	      (parse-one-def out)
	    (error  (end-of-line) er)))
  (set-buffer-modified-p nil)
  (kill-buffer file-buf)
   doc-buf
   
    ))


(defun make-all-doc (out-file  file-list)
;Write doc strings to OUT-FILE for all files in FILE-LIST.
;Currently lisp syntax is assumed for files in file-list.

  (if (file-exists-p out-file) (delete-file out-file))
  (while file-list
    (setq file (car file-list))
    (message (format "for %s.."file))
    (setq buf (make-doc file nil))
    (switch-to-buffer buf)
    (append-to-file (point-min) (point-max) out-file)
    (kill-buffer buf)
    (setq file-list (cdr file-list))
    ))

(global-set-key "d" 'find-doc)
(global-set-key "/" 'apropos-doc)


(defun apropos-doc (test)
  (interactive "sApropos doc string: ")
  (require-doc-file)
  (let  (ans (alist my-lisp-doc))
    (while alist
      (cond ((string-match test (car  (car alist)))
	     (setq ans (cons (car (car alist)) ans))))
      (setq alist (cdr alist)))
    (with-output-to-temp-buffer "*Completions*"
      (display-completion-list ans))))



(defun string-next-sexp (pt)
  (save-excursion
    (goto-char pt)
    (let ((beg pt)
	  (end (progn (forward-sexp 1) (point)))
	  )
      (goto-char beg)
      (cond ((and (looking-at "(")
		  (re-search-forward  "\\b&aux" end t))
	     (forward-char (- (length "&aux")))
	     (skip-chars-backward " 	\n")
	     (concat (buffer-substring beg (point))
		     ")"))
	    (t(buffer-substring beg end))))))





(defun skip-to-doc (type)
  (forward-char 2)
  (setq find-doc-name (progn (forward-sexp 1)
			     (forward-over-white) (point)))
  (cond ((equal type "V")
	 (forward-sexp 1) ;skip the name
	 (forward-over-white)
	 (or (looking-at ")") (forward-sexp 1))
	 (forward-over-white)
	 (cond ((and  comments-for-defvar
		     (looking-at ")"))
		(cond ((eq comments-for-defvar 'after)
		       (forward-char 1)
		       (forward-over-white))
		      ((eq comments-for-defvar 'before)
		       (goto-char find-doc-name)
		       (previous-line 1)
		       (back-over-white)
		       (beginning-of-line)
		       
		       ))))
	 (setq find-doc-args nil))
	(t 
	 (setq find-doc-args
	       (progn (forward-sexp 1)(forward-over-white) (point)))
	 ;skip name
	 
	 (forward-sexp 1)  (forward-over-white) ;skip the args
	))
  (read-doc type)
  )

(defun parse-one-def (out)
  (let (name)
    (beginning-of-line)
    (cond ((looking-at "(defun")
	   (skip-to-doc "F"))
	  ((looking-at "(defmacro")
	    (skip-to-doc "M"))
	  ((or (looking-at "(defvar")
	       (looking-at "(defconstant")
	       (looking-at "(defparameter"))
	   (skip-to-doc "V"))
	  )
    (end-of-line)
    ))

(defvar find-doc-comment-start nil)
(defun mark-very-long-comment ()
  (interactive)
;  (mm "call mark comment at %d" (point))

  (setq comment-start (or find-doc-comment-start comment-start))
  (let ((at (point)))
    (beginning-of-line)
    (while(and (not (eobp))
	       (or  (looking-at comment-start)
		    (looking-at "[ 	]*\n")
		   ))
      (forward-line 1))
    (back-over-white)
    (set-mark (point))
    (goto-char at)
    (while(and (not (bobp))
	       (or (looking-at comment-start)
		    (looking-at "[ 	]*\n")
		    ))
      (forward-line -1))
    (if (not (looking-at comment-start))(forward-line 1))
    (forward-over-white)
    ))


(defmacro mm (&rest b)
  (list 'progn (list 'message (cons  'format b)) '(sleep-for 1)))
;;narrows to the long-comment, and removes the ;
(defun copy-long-comment (to-buf)
  (mark-very-long-comment)
  (let ((beg (min (dot) (mark)))
	(end (max (dot) (mark))) (n 0)m)
;    (mm "Beg %d end %d" beg end)
    (narrow-to-region beg end)
    (goto-char (point-min))
    (forward-over-white)
    (let ((tem (point)))
;      (mm "check at %d" tem)
      (while (looking-at ";")
	(forward-char 1))
      (setq n (- (point) tem)))
    (goto-char (point-min))
    (while (not (eobp))
      (setq m n)
      (while (> m  0)
	(cond (;(looking-at ";")
	       (looking-at comment-start)
	       (delete-char 1)
	       (cond ((looking-at " ")(delete-char 1)(setq m 0)))
	       (setq m (- m 1)))
	      (t (setq m 0))))
      (forward-line 1)))
        (my-copy-to-buffer 
	 doc-buf (point-min) (point-max))
    (widen)
    )

(defun my-copy-to-buffer (buf beg end)
  (let ((tem (current-buffer)))
    (switch-to-buffer buf)
    (insert-buffer-substring tem beg end)
    (switch-to-buffer tem)))


(defun write-doc (string)
  (let ((buf (current-buffer)))
    (switch-to-buffer doc-buf)
    (goto-char (point-max))
    (insert string)
    (switch-to-buffer buf)))

(defun write-doc-string-begin  (type)
  (let ((name  (string-next-sexp find-doc-name))
	(args  (if find-doc-args (string-next-sexp find-doc-args))))
    (let ((buf (current-buffer)))
      (switch-to-buffer doc-buf)
      (goto-char (point-max))
      (insert doc-start type name)
      (insert (cdr (assoc type
			  '(("F" . "\n Function ")
			    ("M" . "\n Macro ")
			    ("T" . "\n Topic ")
			    ("V" . "\n Variable: ")))))
      (cond ((and args include-args)
	     (insert "Args: " args "\n"))
	    (t (insert "\n")))
      (switch-to-buffer buf)
      )))
  
(defun read-doc (type)
  "Reads the documentation and puts in doc file"
  (skip-chars-forward " 	\n" )
  (cond ((looking-at comment-start)
	 (write-doc-string-begin type)
	 (copy-long-comment doc-buf))
	((looking-at "\"")
         (let ((tem (point))
	       (end (progn (forward-sexp 1)(point))))
	   (write-doc-string-begin type)
	   (my-copy-to-buffer doc-buf (+ 1 tem) (-  end 1))))
	(include-all-functions-and-args
	 (write-doc-string-begin type))))


(defun snarf-doc (file)
  "Takes a doc string file, and records the pointers into that file.
It writes out a list of doc pointers into file-keys.el.  The list is suitable
for the find-doc command."
  (interactive "FMake -keys.el for file: ")
  (find-file file)
  (set-syntax-table common-lisp-syntax-table)
  (goto-char (point-min))
  (let (tem lis)
    (while (search-forward doc-start nil t)
      (setq tem (point))
      (setq lis (cons
		 (cons (buffer-substring (setq tem (+ doc-key-length tem))
					 (progn (forward-sexp 1) (point)))
		       (- tem 1)
		       )
		 lis)))
    (let ((buf (generate-new-buffer "-keys.el"))(tem lis))
      (switch-to-buffer buf)
      (insert "(setq my-lisp-doc '(")
      (while tem
	(prin1 (car tem) buf)
	(terpri buf)
	(setq tem (cdr tem))
	)
      (insert "))")
      (write-file (concat file "-keys.el")))
    (setq my-lisp-doc lis)))

(defvar find-doc-buffer nil)
; buffer where the lisp documentation lives

(defvar doc-file-name nil)
; File name of the current doc file.  Usually ../DOC should be used
; and ../DOC-keys.el will hold the keys to the file.


(defun visit-doc-file (file)
  (interactive (list (read-file-name "Visit doc table: (default DOC) "
				     default-directory
				     (concat default-directory "DOC")
				     t)))
  (setq file (expand-file-name file))
  (if (file-directory-p file)
      (setq file (concat file "DOC")))
  (setq doc-file-name file)
  (load (concat file "-keys.el")))

(defun require-doc-file()
  (or doc-file-name
      (visit-doc-file    (read-file-name "Visit doc table: (default DOC) "
				     default-directory
				     (concat default-directory "DOC")
				     t))))
(defvar find-doc-edit nil "If non nil, instead of just printing out
a copy of the documentation in the other window, we actually visit
the DOC file.  This is useful for editing it.")
(defun find-doc()
  (interactive)
  (require-doc-file)
  (require 'sshell)
  
  (or find-doc-edit(and find-doc-buffer (get-buffer-process find-doc-buffer))
      (progn (setq find-doc-buffer
		   (make-shell "find-doc"
			       "/bin/sh" nil "-i"))
	     (sleep-for 2)
	     (send-string (get-buffer-process find-doc-buffer)
			  "PS1=\n \n")
	     ))
  
  (let (tem result (completion-ignore-case  t))
    (save-excursion
      (condition-case er
	  (progn
	    (forward-sexp -1)
	    (setq tem
		  (buffer-substring (point) (progn (forward-sexp 1) (point)))))
	(error)))
    (or (and tem (assoc (setq tem (upcase tem)) my-lisp-doc))
	(setq tem nil))
    (let ((symbol (completing-read "Describe symbol: "
				   my-lisp-doc nil t tem)))
      (setq result (assoc symbol my-lisp-doc))
      (or result
	  (setq result (assoc (downcase symbol) my-lisp-doc)))
      (or result
	  (setq result (assoc (upcase symbol) my-lisp-doc)))
      (or result (error (format "case mix up: %s not in my-lisp-doc keys" symbol))))
       

    (cond (find-doc-edit
	     (find-file-other-window doc-file-name)
	     (goto-char (cdr result))
	     (set-fill-column 79)
	     (cond ((looking-at (concat "[A-Z]"
					(car result)))
		    (recenter 0)
		    )
		   (t (goto-char (point-min))
		      (re-search-forward (concat "[A-Z\n]" (car result) "\\b"))
		      (recenter 0)
		      ))
	     )
	  ( t
	    (let ((old (current-buffer)))
	      (switch-to-buffer find-doc-buffer)
	      (erase-buffer)
	      (goto-char (point-max))
	      (send-string  (get-buffer-process find-doc-buffer)
			    "echo Documentation: \n"
			    )

	      (process-send-string (get-buffer-process find-doc-buffer)
				   (format "print_doc %s %d \n"
					   doc-file-name (cdr result)))
	      (switch-to-buffer old)
      
	      (display-buffer find-doc-buffer)
	      result)))))


;;common lisp for creating a doc file.



(defun doc-file (file packages)
;;Write FILE of doc strings for all symbols in PACKAGES
;;This file is suitable for use with the find-doc function.  
  (with-open-file (st file :direction :output)
   (sloop:sloop
    for v in packages
    do (sloop:sloop
	for w in-package (if (packagep v) (package-name v) v)
	when  (setq doc (documentation w 'function))
	do (format st "F~a~%~a~a" w
		   (cond ((special-form-p w) "Special Form: ")
			 ((functionp w) "Function: ")
			 ((macro-function w) "Macro: ")
			 (t ""))
		   doc)
	when (setq doc (documentation w 'variable))
	do (format st "VVariable:~a~%~a" w doc)
	))))

