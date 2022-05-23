

(defun atypes (llist)
  (sloop::sloop for v in llist
	 when (member v '(&rest &key &optional &allow-other-keys))
	 do (return (nconc ans '(*)))
	 else
	 collect t into ans
	 finally (return ans)))

(defun from-doc-file (file &optional add-rest)
  ;; read from file of form (defun cons (a b) t)
  ;; (defun truncate (a &optional b) (mv))
  (with-open-file (st file)
    (sloop::sloop  while (setq tem (read st nil nil)) with fname
	 when (get (setq fname (second tem)) 'compiler::lfun)
	 with atypes with has-ctypes
	 do (setq atypes (atypes (third tem)))
	 (multiple-value-setq
	  (ctypes has-ctypes)
	  (get fname 'compiler::arg-types))
	 (cond (nil (and (equal (length atypes)
			    (length ctypes))
		     (equal (member '* atypes)
			    (member '* ctypes))))
	       (t
		(setf (gethash fname *done*) t)
		(print `(defsysfun ',fname
			       ,(get fname 'lfun)
			       ',(cond  ((and nil(equal (length ctypes)
						    (- (length atypes) 1))
					     (member '* atypes))
					 (append ctypes '(*)))
					((not has-ctypes)
					 atypes)
					(t `(question  ,atypes ,ctypes)))
			       ',(cond ((get fname 'return-type))
				       ((equal (fourth tem) '(mv)) '*)
				       (t t))
			       ,(get fname 'no-sp-change)
			       ,(get fname 'predicate)))))))
  (if add-rest (add-rest-lfuns add-rest)))


(setq *done* (make-hash-table))

(defun add-rest-lfuns (file)
  (with-open-file (st file)
    (sloop::sloop while (setq tem (read st nil nil))
		  when (and (consp tem)
			    (equal (car tem) 'defsysfun)
			    (consp (second tem))
			    (not (gethash (second (second tem)) *done*)))
		  do
		  (print tem))))

		  
			    

