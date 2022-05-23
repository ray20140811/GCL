
HDIR	= ../h
ODIR	= ../o
LSPDIR	= ../lsp
CMPDIR	= ../cmpnew
PORTDIR	= ../unixport
MPDIR	= ../mp

CFLAGS	= -c $(DEFS) -I$(HDIR)
LDCC    = $(CC)

LIBS	= -lm # -lpixrect -lc
OLDDATE = "DATE"
GCLIB	= $(ODIR)/gcllib.a
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

LIBS1= $(LIBS) $(GCLIB)


















OBJS	= $(ODIR)/main.o $(ODIR)/alloc.o $(ODIR)/gbc.o \
	$(ODIR)/bitop.o $(ODIR)/typespec.o $(ODIR)/eval.o \
	$(ODIR)/macros.o $(ODIR)/lex.o $(ODIR)/bds.o \
	$(ODIR)/frame.o $(ODIR)/predicate.o $(ODIR)/reference.o \
	$(ODIR)/assignment.o $(ODIR)/bind.o $(ODIR)/let.o \
	$(ODIR)/conditional.o $(ODIR)/block.o $(ODIR)/iteration.o \
	$(ODIR)/mapfun.o $(ODIR)/prog.o $(ODIR)/multival.o \
	$(ODIR)/catch.o $(ODIR)/symbol.o $(ODIR)/cfun.o \
	$(ODIR)/cmpaux.o $(ODIR)/package.o $(ODIR)/big.o \
	$(ODIR)/number.o $(ODIR)/num_pred.o $(ODIR)/num_comp.o \
	$(ODIR)/num_arith.o $(ODIR)/num_sfun.o $(ODIR)/num_co.o \
	$(ODIR)/num_log.o $(ODIR)/num_rand.o $(ODIR)/earith.o \
	$(ODIR)/character.o  $(ODIR)/sequence.o \
	$(ODIR)/list.o $(ODIR)/hash.o $(ODIR)/array.o \
	$(ODIR)/string.o $(ODIR)/structure.o $(ODIR)/toplevel.o \
	$(ODIR)/file.o $(ODIR)/read.o $(ODIR)/backq.o \
	$(ODIR)/print.o $(ODIR)/format.o $(ODIR)/pathname.o \
	$(ODIR)/unixfsys.o $(ODIR)/unixfasl.o $(ODIR)/error.o \
	$(ODIR)/unixtime.o $(ODIR)/unixsys.o $(ODIR)/unixsave.o \
	$(ODIR)/unixint.o $(ODIR)/funlink.o  \
	$(ODIR)/fat_string.o ${ODIR}/run_process.o \
	$(ODIR)/init_pari.o $(MPFILES) $(SFASL) $(EXTRAS)

LSPOBJS	= $(LSPDIR)/defmacro.o $(LSPDIR)/evalmacros.o $(LSPDIR)/top.o \
	$(LSPDIR)/module.o $(LSPDIR)/predlib.o $(LSPDIR)/setf.o \
	$(LSPDIR)/arraylib.o $(LSPDIR)/assert.o $(LSPDIR)/defstruct.o \
	$(LSPDIR)/describe.o $(LSPDIR)/iolib.o $(LSPDIR)/listlib.o \
	$(LSPDIR)/mislib.o $(LSPDIR)/numlib.o $(LSPDIR)/packlib.o \
	$(LSPDIR)/seq.o $(LSPDIR)/seqlib.o $(LSPDIR)/trace.o \
	$(LSPDIR)/sloop.o  $(LSPDIR)/debug.o 

CMPOBJS	= $(CMPDIR)/cmpinline.o $(CMPDIR)/cmputil.o $(CMPDIR)/cmptype.o \
	$(CMPDIR)/cmpbind.o $(CMPDIR)/cmpblock.o $(CMPDIR)/cmpcall.o \
	$(CMPDIR)/cmpcatch.o $(CMPDIR)/cmpenv.o $(CMPDIR)/cmpeval.o \
	$(CMPDIR)/cmpflet.o $(CMPDIR)/cmpfun.o $(CMPDIR)/cmpif.o \
	$(CMPDIR)/cmplabel.o $(CMPDIR)/cmplam.o $(CMPDIR)/cmplet.o \
	$(CMPDIR)/cmploc.o $(CMPDIR)/cmpmap.o $(CMPDIR)/cmpmulti.o \
	$(CMPDIR)/cmpspecial.o $(CMPDIR)/cmptag.o $(CMPDIR)/cmptop.o \
	$(CMPDIR)/cmpvar.o $(CMPDIR)/cmpvs.o $(CMPDIR)/cmpwt.o

GCL=gcl

saved_$(GCL):	raw_$(GCL) $(RSYM) init_gcl.lsp \
		$(CMPDIR)/cmpmain.lsp \
		$(CMPDIR)/lfun_list.lsp \
		$(CMPDIR)/cmpopt.lsp
# if you are wfs on rascal increment the minor version number.
	../xbin/if-exists /usr/u9/wfs/schelter "../xbin/inc-version"
	../xbin/if-exists saved_$(GCL) "rm -f saved_$(GCL)"
	cat init_gcl.lsp | \
	sed -e "s$(OLDDATE)Version(`cat ../majvers`.`cat ../minvers`) `date`g" \
	-e 'ssaved_gclsaved_$(GCL)g' \
	-e 'slinks t)links t)(setq compiler::*cc* "$(CC)")$(INITFORM)g' \
	-e "sGCLDIR${GCLDIR}g" \
	-e "s(defun lisp-imp(setq si::*gcl-version* '`cat ../minvers`)(defun lisp-imp'g" | \
	./raw_$(GCL) $(PORTDIR)/ 

rsym:	rsym.c $(HDIR)/mdefs.h
	$(LDCC) $(DEFS) -I../h -o rsym rsym.c 

$(HDIR)/mdefs.h: $(HDIR)/include.h
	cat $(HDIR)/include.h | sed -e "/include/d" > $(HDIR)/mdefs.h

saved_kcn:	
	make -f make_kcn "MPFILES=$(MPFILES)"

FOR_RAW=$(OBJS) $(LSPOBJS) $(CMPOBJS)
SYS_GCL=sys_gcl.o

# on boot strapping the gcl compiler because of structure changes,
# some files need to be loaded as lisp files.
raw_$(GCL): $(FOR_RAW)
	rm -f raw_$(GCL) 
	- if  [ -f ../lsp/sloop.c ] ; \
		then make raw_$(GCL)1 "GCL=${GCL}" "ODIR=${ODIR}" "EXTRAS=${EXTRAS}" "LIBS=${LIBS}" "LDCC=${LDCC}" "MPFILES=$(MPFILES)" ; \
		else make raw_$(GCL)1 "SYS_GCL=sys_boot.o" ; fi 

raw_$(GCL)1: $(SYS_GCL)
	$(LDCC)  -o raw_$(GCL) $(FOR_RAW) $(SYS_GCL) -lc $(LIBS1)

saved_gcl_boot:
	make raw_$(GCL)1 "SYS_GCL=sys_boot.o"
	make saved_gcl

HFILES	= $(HDIR)/include.h \
	$(HDIR)/object.h $(HDIR)/vs.h $(HDIR)/symbol.h $(HDIR)/bds.h \
	$(HDIR)/frame.h $(HDIR)/lex.h $(HDIR)/eval.h $(HDIR)/external.h \
	$(HDIR)/rgbc.h

sys_gcl.o:	sys_gcl.c $(HFILES)
	$(CC) $(CFLAGS) sys_gcl.c


# create a sed script.
boots : lspboots cmpboots
	rm -f boots ; \
	echo "# edit lspboots or cmpboots " >> boots ;\
	for v in `cat lspboots cmpboots` ; \
	do echo "s:$$v.o:$$v.lsp:g" >> boots ;\
	echo "s:init_or_load(init_$$v,:load1(:g" >> boots ; \
	done 

sys_boot.o: sys_gcl.c $(HFILES) boots
	rm -f sys_boot.c ; cat sys_gcl.c | sed -f boots > sys_boot.c
	$(CC) $(CFLAGS) sys_boot.c
	
kcp-sun:	gcrt0-mod.o
	(cd ../go ; make  "CFLAGS = -I../h -pg -g -c")
	make -e "GCL=kcp" "ODIR=../go"  "EXTRAS= gcrt0-mod.o" "LDCC=${LDCC}" "CC = ${CC} -pg"

kcp-bsd: ncrt0.o
	(cd ../go ; make  "CFLAGS = -I../h -pg -g -c")
	make "GCL=kcp" "ODIR=../go" "EXTRAS = gcrt0-mod.o ${EXTRAS} " "CC = ${CC} -pg" "LDCC = gcc -nostdlib  ncrt0.o "

aix_crt0.o:
	emacs -batch -l aix-crt0.el

kcp-aix: aix_crt0.o
	(cd ../go ; make  "CFLAGS = -I../h -pg -g -c")
	make "GCL=kcp" "ODIR=../go" "EXTRAS = /lib/gcrt0.o ${EXTRAS} " "CC = ${CC} -pg" "LDCC = ld  -H4096 -D0 -T512 -bhalt:4  -bnso -bI:/lib/syscalls.exp -L/lib/profiled aix_crt0.o     "	

kcp: ${KCP}
	
ncrt0.o: /lib/crt0.o
	emacs -batch -l ncrt0.el

gcrt0-mod.o:
	../xbin/if-exists /lib/gcrt0.o  "cp /lib/gcrt0.o ."
	../xbin/if-exists /usr/lib/gcrt0.o  "cp /usr/lib/gcrt0.o ."
	emacs -batch -l gcrt0.el


hpbsd-crt0-mod.o:
	cp /lib/crt0.o .
	emacs -batch -l hpbsd-crt0.el


clean:
	rm -f saved_$(GCL) raw_$(GCL) *.o core a.out
