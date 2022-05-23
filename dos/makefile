.SUFFIXES: .o .c

HDIR	= ../h

OFLAG	= -O
ODIR	= .

# begin makedefs
GCLDIR=/gcl
SHELL=/bin/sh
MACHINE=dos-go32

LBINDIR=d:/unix
OFLAG	=
#  -O
LIBS	= -lm -lg 

CAT=cat -B
EXE_PREFIX=

#gcc 2.1 compiles gcl correctly as far as I have been able to determine.
CC = gcc -I${GCLDIR}/o -DVOL=volatile -W 
ODIR_DEBUG=
# -O -g

AS=as

MAINDIR = /gcl
CFLAGS	= -c $(DEFS)  -I../h

MAIN    = ../o/main.o

MPFILES=${MPDIR}/mpi-386.o ${MPDIR}/libmport.a
# objs for libmport.a
MPOBJS= mp_divul3.o mp_bfffo.o mp_mulul3.o mp2.o mp_dblrsl3.o mp_dblremul3.o ${MPDIR}/gnulib1.o

RSYM	= rsym
SFASL	= $(ODIR)/sfasl.o
EXTRA_OTARGETS=
# ${ODIR}/dostimes.o

# extras for dos (in dos directory)
DOS_ODIR=../dos
EXX_DOS=${DOS_ODIR}/dostimes.o ${DOS_ODIR}/read.o ${DOS_ODIR}/signal.o ${DOS_ODIR}/sigman.o ${DOS_ODIR}/dum_dos.o

# This function will be run before dumping.
# When using SFASL it is good to have (si::build-symbol-table)
INITFORM=(si::build-symbol-table)

DPP = ..\bin\dpp

# end makedefs

DOS_ODIR=.

CFLAGS	= -I. -I$(HDIR) $(ODIR_DEBUG)

.s.o:
	$(CC) -c $(OFLAG) $(CFLAGS) $*.c

.c.o:
	$(CC) -c $(OFLAG) $(CFLAGS) $*.c

OBJS	= $(EXX_DOS)

all:	$(OBJS)

clean:
	rm -f $(OBJS)


