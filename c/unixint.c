/*
 Copyright (C) 1994 M. Hagiya, W. Schelter, T. Yuasa

This file is part of GNU Common Lisp, herein referred to as GCL

GCL is free software; you can redistribute it and/or modify it under
the terms of the GNU LIBRARY GENERAL PUBLIC LICENSE as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GCL is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public 
License for more details.

You should have received a copy of the GNU Library General Public License 
along with GCL; see the file COPYING.  If not, write to the Free Software
Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.

*/

/*
	unixint.c
*/

#include "include.h"
#include <signal.h>
#include "page.h"
  
#define SS1(a,b) b = a ;
#define RS1(a,b) a = b ;

#define SAVE_STATE \
 { struct call_data fd1; \
  struct bds_bd bd1,*bd1p; \
  object* vs_top1,*vs_base1,vs_top_val ; \
     SS1(bds_top,bd1p) \
     SS1(*bd1p, bd1) \
     SS1(vs_base,vs_base1) \
     SS1( vs_top ,vs_top1) \
     SS1(*vs_top1, vs_top_val) \
     SS1(fcall, fd1) \
       ;

		     
#define RESTORE_STATE \
     RS1(bds_top,bd1p) \
     RS1(*bd1p, bd1) \
     RS1(vs_base,vs_base1) \
     RS1( vs_top ,vs_top1) \
     RS1(*vs_top1, vs_top_val) \
     RS1(fcall, fd1) \
		      }

		     
object SVinterrupt_enable;

sigalrm()
{
	if (interrupt_flag) {
		interrupt_flag = FALSE;
		SAVE_STATE
		terminal_interrupt(TRUE);
		RESTORE_STATE
	}
}

sigint()
{
	if (!interrupt_enable || interrupt_flag) {

		if (!interrupt_enable)
			{fprintf(stdout, "\n;;Interrupt delayed.\n");
			 fflush(stdout);
			 interrupt_flag=TRUE;}

		gcl_signal(SIGINT, sigint);
		return;
	}
	if (symbol_value(SVinterrupt_enable) == Cnil) {
		SVinterrupt_enable->s.s_dbind = Ct;
		gcl_signal(SIGINT, sigint);
		return;
	}
#ifdef DOS
	if(interrupt_flag)
	  { sigalrm();}
#endif
	interrupt_flag = TRUE;
	gcl_signal(SIGALRM, sigalrm);
	alarm(1);
	gcl_signal(SIGINT, sigint);
}

sigfpe()
{
	gcl_signal(SIGFPE, sigfpe);
	FEerror("Floating-point exception.", 0);
}

#ifdef BSD
signal_catcher(sig, code, scp)
{
	char str[64];

	if (!interrupt_enable) {
		sprintf(str, "signal %d caught (during GBC)", sig);
		error(str);
	} else {
		vs_push(make_fixnum(sig));
		FEerror("Signal ~D caught.~%\
The internal memory may be broken.~%\
You should check the signal and exit from Lisp.", 1, vs_head);
	}
}

#ifndef SIGPROTV
#define SIGPROTV SIGSEGV
#endif

siLcatch_bad_signals()
{
	check_arg(0);

	gcl_signal(SIGILL, signal_catcher);
	gcl_signal(SIGIOT, signal_catcher);
	gcl_signal(SIGEMT, signal_catcher);
	if (SIGPROTV != SIGBUS || !sgc_enabled)
 	  gcl_signal(SIGBUS, signal_catcher);
 	if(SIGPROTV != SIGSEGV || !sgc_enabled)
 	  gcl_signal(SIGSEGV, signal_catcher);
	gcl_signal(SIGSYS, signal_catcher);
	vs_push(Ct);
}

siLuncatch_bad_signals()
{
	check_arg(0);

	gcl_signal(SIGILL, SIG_DFL);
	gcl_signal(SIGIOT, SIG_DFL);
	gcl_signal(SIGEMT, SIG_DFL);
 	if(SIGPROTV != SIGBUS || !sgc_enabled)
 	  gcl_signal(SIGBUS, SIG_DFL);
 	if(SIGPROTV != SIGSEGV || !sgc_enabled)
 	  gcl_signal(SIGSEGV, SIG_DFL);	
	gcl_signal(SIGSYS, SIG_DFL);
	vs_push(Ct);
}
#endif

init_interrupt()
{
	gcl_signal(SIGFPE, sigfpe);
	gcl_signal(SIGINT, sigint);
}

init_interrupt1()
{
	SVinterrupt_enable
	= make_si_special("*INTERRUPT-ENABLE*", Ct);
#ifdef BSD
	make_si_function("CATCH-BAD-SIGNALS", siLcatch_bad_signals);
	make_si_function("UNCATCH-BAD-SIGNALS", siLuncatch_bad_signals);
#endif
}
