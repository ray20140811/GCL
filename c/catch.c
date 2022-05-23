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

	catch.c

	dynamic non-local exit
*/

#include "include.h"

Fcatch(args)
object args;
{
	object *top = vs_top;
	object tag;

	if (endp(args))
		FEtoo_few_argumentsF(args);
	eval(MMcar(args));
	vs_top = top;
	vs_push(vs_base[0]);
	frs_push(FRS_CATCH, vs_base[0]);
	if (nlj_active)
		nlj_active = FALSE;
	else
		Fprogn(MMcdr(args));
	frs_pop();
}

siLerror_set()
{
	object *old_base = vs_base;
	object *value_top;
	object *old_lex = lex_env;

	check_arg(1);
	vs_push(Cnil);
	frs_push(FRS_CATCHALL, Cnil);
	if (nlj_active) {
		nlj_active = FALSE;
		old_base[0] = nlj_tag;
		frs_pop();
		vs_base = old_base;
		vs_top = vs_base+1;
		lex_env = old_lex;
		return;
	} else {
		lex_env = vs_top;
		vs_push(Cnil);
		vs_push(Cnil);
		vs_push(Cnil);
		eval(vs_base[0]);
		old_base[0] = Cnil;
	}
	frs_pop();
	lex_env = old_lex;
	value_top = vs_top;
	vs_top = old_base + 1;
	while(vs_base<value_top) {
		vs_push(vs_base[0]);
		vs_base++;
	}
	vs_base = old_base;
}

Funwind_protect(args)
object args;
{
	object *top = vs_top;
	object *value_top;
	if (endp(args))
		FEtoo_few_argumentsF(args);
	frs_push(FRS_PROTECT, Cnil);
	if (nlj_active) {
		object tag = nlj_tag;
		frame_ptr fr = nlj_fr;
		object *base;

		value_top = vs_top;
		vs_top = top;
		while(vs_base<value_top) {
		 	vs_push(vs_base[0]);
			vs_base++;
		}
		value_top = vs_top;
		nlj_active = FALSE;
		frs_pop();
		Fprogn(MMcdr(args));
		vs_base = top;
		vs_top = value_top;
		if (vs_top == vs_base) vs_base[0] = Cnil;
		unwind(fr, tag);
		/* never reached */
	} else {
		eval(MMcar(args));
		frs_pop();
		value_top = vs_top;
		vs_top = top;
		while(vs_base<value_top) {
		 	vs_push(vs_base[0]);
			vs_base++;
		}
		value_top = vs_top;
		Fprogn(MMcdr(args));
		vs_base = top;
		vs_top = value_top;
		if (vs_top == vs_base) vs_base[0] = Cnil;
	}
}

Fthrow(args)
object args;
{
	object *top = vs_top;
	object tag;
	frame_ptr fr;
	if (endp(args) || endp(MMcdr(args)))
		FEtoo_few_argumentsF(args);
	if (!endp(MMcddr(args)))
		FEtoo_many_argumentsF(args);
	eval(MMcar(args));
	vs_top = top;
	tag = vs_base[0];
	vs_push(tag);
	fr = frs_sch_catch(tag);
	if (fr == NULL)
		FEerror("~S is an undefined tag.", 1, tag);
	eval(MMcadr(args));
	unwind(fr, tag);
	/* never reached */
}

init_catch()
{
	make_special_form("CATCH", Fcatch);
	make_si_function("ERROR-SET", siLerror_set);
	make_special_form("UNWIND-PROTECT", Funwind_protect);
	make_special_form("THROW", Fthrow);
}
