
(load-library "find-doc")
(if (file-exists-p ".edoc")(load ".edoc"))
(setq args (cdr (cdr (cdr command-line-args))))
(cond ((equal (car args) "-k")
       (snarf-doc (expand-file-name (car (cdr args)))))
      (t
	(setq out (expand-file-name "DOC"))
	(if (file-exists-p out)
	    (delete-file out))
	(let ((buf (generate-new-buffer "joe")))
	  (switch-to-buffer buf)
	  (prin1 command-line-args buf ))
	(make-all-doc out args)
	(snarf-doc out)))





    
    
