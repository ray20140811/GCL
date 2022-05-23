# a facility for displaying DOC files and completing on them
# requires gnu emacs, to be in the search path

# A directory on peoples search path.
LBINDIR=/usr/local/bin
EMACS=emacs
ELISP=gcl.el dbl.el find-doc.el ansi-doc.el lisp-complete.el sshell.el

FILES= print_doc.c edoc ${ELISP} makefile


install: current-emacs-path print_doc edoc DOC-keys.el



print_doc: print_doc.c
	$(CC) -o print_doc print_doc.c

DOC-keys.el: DOC
	echo '(load-file "find-doc.el")(snarf-doc "DOC")' > tmp.el~
	${EMACS} -batch -l tmp.el~ 	
	rm -f lsp/tmp.el~


current-emacs-path: print_doc
	@echo ">>>>>>You may need to be superuser to install the .el files and
	@echo ">>>>>> the other executables  <<<<<<<<<<<<<"
	sleep 1
	echo '(generate-new-buffer "emacs-path")' \
	'(insert (nth (1- (length load-path)) load-path))' \
	'(write-file "emacs-path")' > tmp.el~
	${EMACS} -batch -l tmp.el~
	-cp ${ELISP} `cat emacs-path`
	echo '(generate-new-buffer "emacs-path")' \
	'(insert (nth (1- (length exec-path)) exec-path))' \
	'(write-file "emacs-path")' > tmp.el~
	${EMACS} -batch -l tmp.el~
	-cp print_doc   `cat emacs-path`
	-cp edoc   `cat emacs-path`






