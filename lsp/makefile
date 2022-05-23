.SUFFIXES: .fn .o .c .lsp



PORTDIR	= ../unixport
CAT=cat

OBJS	= arraylib.o assert.o defmacro.o defstruct.o describe.o evalmacros.o \
	iolib.o listlib.o mislib.o module.o numlib.o packlib.o predlib.o \
	seq.o seqlib.o setf.o top.o trace.o sloop.o debug.o



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
	"$(CC) $(OFLAG) $(CFLAGS) $*.c " \
	"../xbin/append ${NULLFILE} $*.data $*.o "

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



.c.o:
	$(CC) $(OFLAG) $(CFLAGS) $*.c
	$(CAT) ${NULLFILE} $*.data >> $*.o

.lsp.fn: ../cmpnew/collectfn.o
	../xbin/make-fn $*.lsp

all:	$(OBJS)

fns1:	$(FNS)

fns:	../cmpnew/collectfn.o
	make fns1 -e "FNS=`echo ${OBJS} | sed -e 's:\.o:\.fn:g'`"

../cmpnew/collectfn.o: ../cmpnew/collectfn.lsp
	(cd ../cmpnew ; $(PORTDIR)/saved_gcl $(PORTDIR)/ collectfn.lisp collectfn S1000)


clean:
	rm -f *.o core a.out
allclean:
	rm -f *.h *.data *.c

dummy3 $(NEWCFILES): sys-proclaim.lisp

sys-proclaim.lisp:
	echo '(in-package "SYSTEM")' \
	'(load "../cmpnew/collectfn")'\
	'(compiler::make-all-proclaims "*.fn")' | ../xbin/gcl


newc:	
	make $(OBJS) -e "NEWCFILES=`echo $(OBJS) | sed -e 's:\.o:.c:g'`"


