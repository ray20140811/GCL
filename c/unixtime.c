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
	unixtime.c
*/

#define IN_UNIXTIME

#include "include.h"
#include <sys/types.h>
#ifdef UNIX
/* all we want from this is HZ the number of clock ticks per second
which is usually 60 maybe 100 or something else. */
#undef PAGESIZE
#include <sys/param.h>
#endif
#ifndef HZ
#define HZ 60
#endif

#ifdef USE_ATT_TIME
#undef BSD
#define ATT
#endif

#ifdef BSD
#include <sys/timeb.h>
#include <sys/times.h>
#include <sys/time.h>
static struct timeb beginning;
#endif

#ifdef ATT
#include <sys/times.h>
long beginning;
#endif

#ifdef E15
#include <sys/times.h>
long beginning;
#endif

#ifdef DGUX


#endif

runtime()
{
	struct tms buf;

	times(&buf);
	return(buf.tms_utime);
}

object
unix_time_to_universal_time(i)
int i;
{
	object x;
	vs_mark;

	vs_push(make_fixnum(24*60*60));
	vs_push(make_fixnum(70*365+17));
	x = number_times(vs_top[-1], vs_top[-2]);
	vs_push(x);
	vs_push(make_fixnum(i));
	x = number_plus(vs_top[-1], vs_top[-2]);
	vs_reset;
	return(x);
}

Lget_universal_time()
{
	check_arg(0);
	vs_push(unix_time_to_universal_time(time(0)));
}

Lsleep()
{
	object z;
	
	check_arg(1);
	check_type_or_rational_float(&vs_base[0]);
	if (number_minusp(vs_base[0]) == TRUE)
		FEerror("~S is not a non-negative number.", 1, vs_base[0]);
	Lround();
	z = vs_base[0];
	if (type_of(z) == t_fixnum)
		sleep(fix(z));
	else
		for(;;)
			sleep(1000);
	vs_top = vs_base;
	vs_push(Cnil);
}

Lget_internal_run_time()
{
	struct tms buf;

	check_arg(0);
	times(&buf);
	vs_push(make_fixnum(buf.tms_utime));
	vs_push(make_fixnum(buf.tms_cutime));
	
}

Lget_internal_real_time()
{
#ifdef BSD
	static struct timeval begin_tzp;
	struct timeval tzp;
	check_arg(0);
	if (begin_tzp.tv_sec==0)
	  gettimeofday(&begin_tzp,0);
	gettimeofday(&tzp,0);
/* the value returned will be relative to the first time this is called,
   plus the fraction of a second.  We must make it relative, so this
   will only wrap if the process lasts longer than 818 days
   */
	vs_push(make_fixnum((tzp.tv_sec-begin_tzp.tv_sec)*HZ
			    + ((tzp.tv_usec)*HZ)/1000000));

#endif

#ifdef ATT
	check_arg(0);
	vs_push(make_fixnum((time(0) - beginning)*HZ));
#endif

#ifdef E15
	check_arg(0);
	vs_push(make_fixnum((time(0) - beginning)*HZ));
#endif

#ifdef DGUX


#endif
}

init_unixtime()
{
#ifdef BSD
	ftime(&beginning);
#endif
#ifdef ATT
	beginning = time(0);
#endif
#ifdef E15
	beginning = time(0);
#endif
#ifdef DGUX

#endif

	make_si_special("*DEFAULT-TIME-ZONE*", make_fixnum(TIME_ZONE));
	make_constant("INTERNAL-TIME-UNITS-PER-SECOND", make_fixnum(HZ));

	make_function("GET-UNIVERSAL-TIME", Lget_universal_time);
	make_function("SLEEP", Lsleep);
	make_function("GET-INTERNAL-RUN-TIME", Lget_internal_run_time);
	make_function("GET-INTERNAL-REAL-TIME", Lget_internal_real_time);
}
