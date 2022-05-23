.SUFFIXES: .o .c .lsp .lisp .fn


PORTDIR	= ../unixport
CAT=cat

OBJS	= cmpbind.o cmpblock.o cmpcall.o cmpcatch.o cmpenv.o cmpeval.o \
	cmpflet.o cmpfun.o cmpif.o cmpinline.o cmplabel.o cmplam.o cmplet.o \
	cmploc.o cmpmap.o cmpmulti.o cmpspecial.o cmptag.o cmptop.o \
	cmptype.o cmputil.o cmpvar.o cmpvs.o cmpwt.o

COMPILE_FILE=$(PORTDIR)/saved_gcl $(PORTDIR) -system-p -no-o -compile
CFLAGS	= -c -O -I../h

.lsp.c:
	@ ../xbin/if-exists $(PORTDIR)/saved_gcl \
	"rm -f $*.c $*.h $*.data $*.o" \
	"$(COMPILE_FILE) $* "

.lsp.o:
	@ ../xbin/if-exists $(PORTDIR)/saved_gcl \
	"rm -f $*.c $*.h $*.data $*.o" \
	"$(COMPILE_FILE) $* " \
	"$(CC) $(OFLAG) $(CFLAGS) $*.c" \
	"../xbin/append ${NULLFILE} $*.data $*.o"


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

all:	$(OBJS)

.lsp.fn: ../cmpnew/collectfn.o
	../xbin/make-fn $*.lsp


.c.o:  
	$(CC) $(OFLAG) $(CFLAGS) $*.c
	$(CAT) ${NULLFILE} $*.data >> $*.o

collectfn.o:
	$(PORTDIR)/saved_gcl $(PORTDIR)/ -compile $*

.lisp.o:
	@ ../xbin/if-exists $(PORTDIR)/saved_gcl \
	"$(PORTDIR)/saved_gcl $(PORTDIR)/ -compile $*.lisp " 
sys-proclaim.lisp:
	echo '(in-package "COMPILER")' \
	'(load "../cmpnew/collectfn")(load "../lsp/sys-proclaim.lisp")'\
	'(compiler::make-all-proclaims "*.fn")' | ../xbin/gcl


newfn:	
	make `echo $(OBJS) | sed -e 's:\.o:.fn:g'`



remake:
	for v in `"ls" *.lsp.V | sed -e "s:\.lsp\.V::g"` ; \
	do rm -f $$v.c $$v.h $$v.data $$v.lsp $$v.o ; \
	ln -s  $(MAINDIR)/cmpnew/$$v.c . ; ln -s $(MAINDIR)/cmpnew/$$v.h . ; \
	ln -s $(MAINDIR)/cmpnew/$$v.data . ; \
	done
	rm -f ../unixport/saved_gcl 
	(cd .. ; make sources)
	(cd .. ; make)
	(cd .. ; make)

clean:
	rm -f *.o core a.out
allclean:
	rm -f *.h *.data *.c
