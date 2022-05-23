AR = ar qc
MPDIR=.
RANLIB=ranlib
# if you are using gcc for the main link you probably dont need this:
GNULIB1= ${MPDIR}/gnulib1.o
NATIVE_CC=cc

# default mp files (overridden by machine.defs)
MPFILES= $(MPDIR)/mpi.o $(MPDIR)/mp2.o  $(MPDIR)/libmport.a

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


OBJS= mp_divul3.o  mp_bfffo.o mp_mulul3.o mp2.o mp_dblrsl3.o mp_dblrul3.o ${GNULIB1}

all:
	make all1 "MPFILES=$(MPFILES)"

all1: ${MPFILES}

$(MPDIR)/libmport.a: $(OBJS)
	rm -f libmport.a
	$(AR) libmport.a ${OBJS}
	${RANLIB} libmport.a

.s.o:
	$(AS) $*.s -o $*.o

.c.o:
	$(CC)  -c $(OFLAG) -I../h -I. $(CFLAGS) $(ODIR_DEBUG) $*.c

mpi-bsd68k.s: mpi.c
	gcc -S  -I../h -O mpi.c -o mpi-bsd68k.s

mpi-sparc.s: mpi.c
	gcc -S -I../h -O mpi.c -o mpi-sparc.s

mpi-sol-sparc.s: mpi.c
	gcc -S -I../h -O mpi.c -o mpi-sol-sparc.s

${MPDIR}/mpi-386.o: ${MPDIR}/mpi-386.s
	$(AS) $*.s -o $*.o

${MPDIR}/mpi-386.s: mpi.c
	gcc -S -I../h -O mpi.c -o mpi-386.s

${MPDIR}/mpi-gcc.o: mpi.c
	gcc -c -O -I../h mpi.c -o mpi-gcc.o

${MPDIR}/gnulib1.o:
	${NATIVE_CC} -c -O gnulib1.c

clean:
	rm *.o *.a

make.defs:
	(cd .. ; for v in h/*.defs; do echo $$v: ; fgrep MPFILES $$v ; done ; true) > make.defs


tar:
	(cd .. ; ls mp/*.c mp/*.s h/*.h h/*.defs mp/makefile mp/make.defs)  | sed -e '/foo/d' > tmpx
	(cd .. ; tar cvf - `cat mp/tmpx`) | compress -c > ${HOME}/tmp/mp.tar.Z
	rm -f tmpx





