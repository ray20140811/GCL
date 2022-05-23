#  Compiling gcl
# select a machine-type from ./MACHINES

# ./add-defs machine-type
# make

# For more details see README

PREFIX_DIR=/usr/local
# This would cause make install to create /usr/local/bin/gcl and
# /usr/local/lib/gcl-1-??/* with some basic files.
##########################

# begin makedefs
GCLDIR=/d11/wfs/newakcl
SHELL=/bin/sh
MACHINE=sun4

LBINDIR=/usr/local/bin
OFLAG	=  -O
LIBS	= -lm 

#include "sparc.h"

# the commercial (for money) C compiler has never been able
# to compile akcl/gcl correctly.  Perhaps it does not like the idea
# that this is free software.   However the standard C compiler is ok.

CC = cc  -DVOL=  -I$(GCLDIR)/o -Bstatic -temp=. -pipe
CC = cc  -DVOL=  -I$(GCLDIR)/o -Bstatic  -pipe
ODIR_DEBUG=-O4

#gcc 2.1 and 2.2 compile gcl correctly as far as I have been able to determine.
#gcc 2.3.3 does not compile gcl correctly
# gcc 2.5.7 is correct as far as I can tell
#CC = gcc -I${GCLDIR}/o -static -DVOL=volatile -W 

AS=as -P

CFLAGS	= -c $(DEFS)  -I../h

MAIN    = ../o/main.o

MPFILES=$(MPDIR)/mpi-sparc.o $(MPDIR)/sparcdivul3.o $(MPDIR)/libmport.a
#MPFILES=${MPDIR}/mpi.o ${MPDIR}/libmport.a

RSYM	= rsym
SFASL	= $(ODIR)/sfasl.o

# This function will be run before dumping.
# When using SFASL it is good to have (si::build-symbol-table)
INITFORM=(si::build-symbol-table)



# Use symbolic links
SYMB=-s
# the  make to use for saved_kcp the profiler.
KCP=kcp-sun

NULLFILE = ../h/secondary_sun_magic

# end makedefs









BINDIR	= bin
HDIR	= h
CDIR	= c
ODIR	= o
LSPDIR	= lsp
CMPDIR	= cmpnew
PORTDIR	= unixport

all:   
	make command
	(cd $(BINDIR); make all)
	(cd mp ; make all)
	-if [ -f o/cmpinclude.h ] ; then true; else ln  h/cmpinclude.h o ; fi
	(cd $(ODIR); make all)
	(cd $(LSPDIR); make all)
	(cd $(CMPDIR); make all)
	(cd $(PORTDIR); make saved_gcl)
	
# 	After making successfully send in a notification to
#	gcl@nicolas.ma.utexas.edu.   This is extremely helpful in
#	tracking on which machines and OS versions there are problems.
#	This will be done automatically by the  xbin/notify line.
	(cd  cmpnew ; make collectfn.o)
	@- if  [ -f cmpnew/collectfn.o ]  ; \
	then echo "Make of GCL `cat majvers`.`cat minvers` completed." ; \
	xbin/notify "CC=${CC}" ; \
	else echo "The new image failed to compile collectfn.lsp" ;fi

	

/usr/include/cmpinclude.h:	$(HDIR)/cmpinclude.h
	@ if [ "$(SU)" != "SKIP" ] ; then echo "su and make cmpinclude.h" ;\
	exit 1 ; \
	else echo "Warning: ask root to cp $(HDIR)/cmpinclude.h /usr/include/cmpinclude.h" \
	;fi

cmpinclude.h:
	cp $(HDIR)/cmpinclude.h /usr/include

command:
	rm -f xbin/gcl ; echo "#!/bin/sh" > xbin/gcl; \
	echo "${PWD}/unixport/saved_gcl -dir ${PWD}/unixport/ \$$@ " \
	>> xbin/gcl
	chmod 755 xbin/gcl

merge:
	${CC} -o merge merge.c

LISP_LIB=cmpnew/collectfn.o lsp/gprof.* lsp/profile.lsp

install: 
	make install1 "INSTALL_LIB_DIR=${PREFIX_DIR}/lib/gcl-`cat majvers`.`cat minvers`" "PREFIX_DIR=${PREFIX_DIR}"
INSTALL_LIB_DIR=
install1:
	-if [ -d ${PREFIX_DIR}/lib ] ;then true; else mkdir ${PREFIX_DIR}/lib ; fi
	-if [ -d ${PREFIX_DIR}/bin ] ;then true; else mkdir ${PREFIX_DIR}/bin ; fi
	-if [ -d ${INSTALL_LIB_DIR} ] ; then true; else mkdir ${INSTALL_LIB_DIR} ;fi 
	(echo      "#!/bin/sh" > ${PREFIX_DIR}/bin/gcl; \
	echo ${INSTALL_LIB_DIR}/unixport/saved_gcl -dir ${INSTALL_LIB_DIR}/unixport/ -libdir ${INSTALL_LIB_DIR}/ >> \
	${PREFIX_DIR}/bin/gcl)
	chmod a+x ${PREFIX_DIR}/bin/gcl
	tar cvf - unixport/saved_gcl doc/DOC doc/*.el ${LISP_LIB} | \
	  (cd ${INSTALL_LIB_DIR} ;tar xvf -)
	-(cd doc ; make install)


install-elisp-files:
	(cd doc ; make install)

clean:
	(cd $(BINDIR); make clean)
	(cd mp ; make clean)
	(cd $(ODIR); make clean)
	(cd $(LSPDIR); make clean)
	(cd $(CMPDIR); make clean)
	(cd $(PORTDIR); make clean)

TARFILE=../gcl.tgz
tar:
	xbin/distribute ${TARFILE}

kcp:
	(cd go ; make  "CFLAGS = -I../h -pg  -c -g ")
	(cd unixport ; make gcp)
