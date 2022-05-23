
HDIR	= ../h
CDIR	= ../c

OFLAG	= -O
ODIR	= .
GCLIB  = gcllib.a
RANLIB=ranlib
AR = ar qc
LIBFILES= bcmp.o bcopy.o bzero.o
# compile main.c with -g, since signalling may not be ok on -O
MAIN_DEBUG= -g
DPP	= ../bin/dpp

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

CFLAGS	=  -I$(HDIR) $(ODIR_DEBUG)




MP 	= $(HDIR)/mp.h

HFILES	= $(HDIR)/include.h \
	$(HDIR)/object.h $(HDIR)/vs.h $(HDIR)/symbol.h $(HDIR)/bds.h \
	$(HDIR)/frame.h $(HDIR)/lex.h $(HDIR)/eval.h $(HDIR)/external.h \
	$(HDIR)/rgbc.h $(HDIR)/config.h

OBJS	= alloc.o array.o assignment.o backq.o bds.o big.o bind.o \
	bitop.o block.o catch.o cfun.o cmpaux.o conditional.o earith.o \
	error.o eval.o format.o frame.o gbc.o iteration.o let.o lex.o \
	macros.o main.o mapfun.o multival.o num_arith.o num_co.o \
	num_comp.o num_log.o num_pred.o num_rand.o num_sfun.o number.o \
	predicate.o prog.o reference.o structure.o toplevel.o typespec.o \
	unixfasl.o unixfsys.o unixint.o unixsave.o unixsys.o unixtime.o \
	character.o file.o hash.o list.o package.o pathname.o print.o \
	read.o sequence.o string.o symbol.o \
	funlink.o  fat_string.o run_process.o \
	init_pari.o   $(EMUL) $(SFASL) ${EXTRA_OTARGETS}

all:	$(OBJS) $(LIBFILES)  $(GCLIB)

ALIB=${LIBFILES} user_init.o

$(GCLIB): ${ALIB} 
	rm -f gcllib.a
	$(AR) gcllib.a ${ALIB}
	${RANLIB} gcllib.a
clean:
	rm -f $(OBJS)
bcmp.o: $(CDIR)/bcmp.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/bcmp.c

user_init.o: $(CDIR)/user_init.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/user_init.c

bcopy.o: $(CDIR)/bcopy.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/bcopy.c
bzero.o: $(CDIR)/bzero.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/bzero.c

bsearch.o: $(CDIR)/bsearch.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/bsearch.c


char_table.o: $(CDIR)/$(CHTAB)
	as $(CDIR)/$(CHTAB) -o char_table.o


character.o:	$(CDIR)/character.d $(DPP)
	$(DPP) $(CDIR)/character
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/character.c
	rm $(CDIR)/character.c

$(EMUL) dummy:
	as $(CDIR)/$(@:.o=.s)  -o $(EMUL)

file.o:	$(CDIR)/file.d $(DPP)
	$(DPP) $(CDIR)/file
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/file.c
	rm $(CDIR)/file.c
hash.o:	$(CDIR)/hash.d $(DPP)
	$(DPP) $(CDIR)/hash
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/hash.c
	rm $(CDIR)/hash.c
list.o:	$(CDIR)/list.d $(DPP)
	$(DPP) $(CDIR)/list
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/list.c
	rm $(CDIR)/list.c
package.o:	$(CDIR)/package.d $(DPP)
	$(DPP) $(CDIR)/package
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/package.c
	rm $(CDIR)/package.c
pathname.o:	$(CDIR)/pathname.d $(DPP)
	$(DPP) $(CDIR)/pathname
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/pathname.c
	rm $(CDIR)/pathname.c
print.o:	$(CDIR)/print.d $(DPP)
	$(DPP) $(CDIR)/print
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/print.c
	rm $(CDIR)/print.c
read.o:	$(CDIR)/read.d $(DPP)
	$(DPP) $(CDIR)/read
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/read.c
	rm $(CDIR)/read.c
sequence.o:	$(CDIR)/sequence.d $(DPP)
	$(DPP) $(CDIR)/sequence
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/sequence.c
	rm $(CDIR)/sequence.c
string.o:	$(CDIR)/string.d $(DPP)
	$(DPP) $(CDIR)/string
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/string.c
	rm $(CDIR)/string.c
symbol.o:	$(CDIR)/symbol.d $(DPP)
	$(DPP) $(CDIR)/symbol
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/symbol.c
	rm $(CDIR)/symbol.c

alloc.o:	$(CDIR)/alloc.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/alloc.c
array.o:	$(CDIR)/array.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/array.c
assignment.o:	$(CDIR)/assignment.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/assignment.c
backq.o:	$(CDIR)/backq.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/backq.c
bds.o:	$(CDIR)/bds.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/bds.c
big.o:	$(CDIR)/big.c
	rm -f $(CDIR)/num_include.h  # don't want one in c directory
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/big.c
bind.o:	$(CDIR)/bind.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/bind.c
bitblt2.o:	$(CDIR)/bitblt2.c
	$(CC) -c $(CFLAGS) $(CDIR)/bitblt2.c
bitop.o:	$(CDIR)/bitop.c
	$(CC) -c $(CFLAGS) $(CDIR)/bitop.c
block.o:	$(CDIR)/block.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/block.c
catch.o:	$(CDIR)/catch.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/catch.c
cfun.o:	$(CDIR)/cfun.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/cfun.c
cmpaux.o:	$(CDIR)/cmpaux.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/cmpaux.c
conditional.o:	$(CDIR)/conditional.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/conditional.c
earith.o:	$(CDIR)/earith.c
	$(CC) -c $(CFLAGS) $(CDIR)/earith.c
error.o:	$(CDIR)/error.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/error.c
eval.o:	$(CDIR)/eval.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/eval.c
format.o:	$(CDIR)/format.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/format.c
frame.o:	$(CDIR)/frame.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/frame.c
gbc.o:	$(CDIR)/gbc.c $(HDIR)/page.h $(CDIR)/sgbc.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/gbc.c
iteration.o:	$(CDIR)/iteration.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/iteration.c
let.o:	$(CDIR)/let.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/let.c
lex.o:	$(CDIR)/lex.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/lex.c
macros.o:	$(CDIR)/macros.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/macros.c
main.o:	$(CDIR)/main.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(MAIN_DEBUG) $(CDIR)/main.c
mapfun.o:	$(CDIR)/mapfun.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/mapfun.c
multival.o:	$(CDIR)/multival.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/multival.c
num_arith.o:	$(CDIR)/num_arith.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/num_arith.c
num_co.o:	$(CDIR)/num_co.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/num_co.c
num_comp.o:	$(CDIR)/num_comp.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/num_comp.c
num_log.o:	$(CDIR)/num_log.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/num_log.c
num_pred.o:	$(CDIR)/num_pred.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/num_pred.c
num_rand.o:	$(CDIR)/num_rand.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/num_rand.c
num_sfun.o:	$(CDIR)/num_sfun.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/num_sfun.c
number.o:	$(CDIR)/number.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/number.c
init_pari.o:	$(CDIR)/init_pari.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/init_pari.c
predicate.o:	$(CDIR)/predicate.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/predicate.c
prog.o:	$(CDIR)/prog.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/prog.c
reference.o:	$(CDIR)/reference.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/reference.c
run_process.o: $(CDIR)/run_process.c ${HFILES}
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/run_process.c
structure.o:	$(CDIR)/structure.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/structure.c
toplevel.o:	$(CDIR)/toplevel.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/toplevel.c
typespec.o:	$(CDIR)/typespec.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/typespec.c
unixfasl.o:	$(CDIR)/unixfasl.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/unixfasl.c
unixfsys.o:	$(CDIR)/unixfsys.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/unixfsys.c
unixint.o:	$(CDIR)/unixint.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/unixint.c
unixsave.o:	$(CDIR)/unixsave.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/unixsave.c
unixsys.o:	$(CDIR)/unixsys.c ${HFILES}
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/unixsys.c
unixtime.o:	$(CDIR)/unixtime.c ${HFILES}
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/unixtime.c
funlink.o:	$(CDIR)/funlink.c ${CDIR}/xdrfuns.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/funlink.c

fat_string.o:	$(CDIR)/fat_string.c ${HFILES} $(CDIR)/fasdump.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/fat_string.c

fasdump.o:	$(CDIR)/fasdump.c ${HFILES} 
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/fasdump.c



$(SFASL) dummy2.o:	$(CDIR)/sfasl.c ${HFILES}
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/sfasl.c

./littleXwin.o:  ${CDIR}/littleXwin.c
	$(CC) -c $(OFLAG) $(CFLAGS) $(CDIR)/littleXwin.c

IBMAIX3_NEAR_LIB = fsavres.o

$(ODIR)/ibmaix3.a: /lib/libc.a
	mkdir tmpx
	(cd tmpx ; ar xv /lib/libc.a ${IBMAIX3_NEAR_LIB} ; ar qc ../ibmaix3.a ${IBMAIX3_NEAR_LIB})
	rm -rf tmpx

${GCLDIR}/aix3_mprotect/command:
	(cd ../aix3_mprotect ; make)

character.o: $(HFILES)
file.o:	$(HFILES)
hash.o: $(HFILES) ${MP}
list.o:	$(HFILES)
package.o: $(HFILES)
pathname.o: $(HFILES)
print.o: $(HFILES) ${MP}
read.o: $(HFILES) ${MP}
sequence.o: $(HFILES)
string.o: $(HFILES)
symbol.o: $(HFILES)

alloc.o: $(HFILES)
array.o: $(HFILES)
assignment.o: $(HFILES)
backq.o: $(HFILES)
bds.o: $(HFILES)
big.o: $(HFILES) ${MP}
bind.o: $(HFILES) 
bitop.o: $(HFILES)
block.o: $(HFILES)
catch.o: $(HFILES)
cfun.o: $(HFILES)
cmpaux.o: $(HFILES) ${MP}
conditional.o: $(HFILES)
earith.o: $(HFILES)
error.o: $(HFILES)
eval.o: $(HFILES)
format.o: $(HFILES)
frame.o: $(HFILES)
gbc.o: $(HFILES) ${MP}
interrupt.o: $(HFILES)
iteration.o: $(HFILES)
let.o: $(HFILES)
lex.o: $(HFILES)
macros.o: $(HFILES)
main.o: $(HFILES)
mapfun.o: $(HFILES)
multival.o: $(HFILES)
mpi.o: $(MP)
num_arith.o: $(HFILES) $(HDIR)/num_include.h ${MP}
num_co.o: $(HFILES) $(HDIR)/num_include.h ${MP}
num_comp.o: $(HFILES) $(HDIR)/num_include.h ${MP}
num_log.o: $(HFILES) $(HDIR)/num_include.h ${MP}
num_pred.o: $(HFILES) $(HDIR)/num_include.h ${MP}
num_rand.o: $(HFILES) $(HDIR)/num_include.h ${MP}
num_sfun.o: $(HFILES) $(HDIR)/num_include.h ${MP}
number.o: $(HFILES) $(HDIR)/num_include.h ${MP}
predicate.o: $(HFILES)
prog.o: $(HFILES)
reference.o: $(HFILES)
structure.o: $(HFILES)
toplevel.o: $(HFILES)
typespec.o: $(HFILES) ${MP}
unixfasl.o: $(HFILES)
unixfsys.o: $(HFILES)
unixint.o: $(HFILES)
unixsave.o: $(HFILES)
unixsys.o: $(HFILES)
unixtime.o: $(HFILES)
funlink.o: $(HFILES)
fat_string.o: $(HFILES)
fasdump.o: $(HFILES)
bitblit2.o: $(HFILES)


