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

	toplevel.c

	Top-Level Forms and Declarations
*/

#include "include.h"

object Scompile, Sload, Seval;
object Sprogn;


object Swarn;

object siVinhibit_macro_special;

object Stypep;

Fdefun(args)
object args;
{
	object name;
	object body, form;

	if (endp(args) || endp(MMcdr(args)))
		FEtoo_few_argumentsF(args);
	if (MMcadr(args) != Cnil && type_of(MMcadr(args)) != t_cons)
		FEerror("~S is an illegal lambda-list.", 1, MMcadr(args));
	name = MMcar(args);
	if (type_of(name) != t_symbol)
		not_a_symbol(name);
	if (name->s.s_sfdef != NOT_SPECIAL) {
		if (name->s.s_mflag) {
			if (symbol_value(siVinhibit_macro_special) != Cnil)
				name->s.s_sfdef = NOT_SPECIAL;
		} else if (symbol_value(siVinhibit_macro_special) != Cnil)
		 FEerror("~S, a special form, cannot be redefined.", 1, name);
	}
	if (name->s.s_hpack == lisp_package &&
	    name->s.s_gfdef != OBJNULL && initflag) {
		vs_push(make_simple_string(
			"~S is being redefined."));
		ifuncall2(Swarn, vs_head, name);
		vs_pop;
	}
	vs_base = vs_top;
	if (lex_env[0] == Cnil && lex_env[1] == Cnil && lex_env[2] == Cnil) {
		vs_push(MMcons(Slambda_block, args));
	} else {
		vs_push(MMcons(lex_env[2], args));
		vs_base[0] = MMcons(lex_env[1], vs_base[0]);
		vs_base[0] = MMcons(lex_env[0], vs_base[0]);
		vs_base[0] = MMcons(Slambda_block_closure, vs_base[0]);
	}
	{object fname =  clear_compiler_properties(name,vs_base[0]);
	 fname->s.s_gfdef = vs_base[0];
	 fname->s.s_mflag = FALSE;}
	vs_base[0] = name;
	for (body = MMcddr(args);  !endp(body);  body = body->c.c_cdr) {
		form = macro_expand(body->c.c_car);
		if (type_of(form) == t_string) {
			if (endp(body->c.c_cdr))
				break;
			vs_push(form);
			name->s.s_plist =
			putf(name->s.s_plist,
			     form,
			     siSfunction_documentation);
			vs_pop;
			break;
		}
		if (type_of(form) != t_cons || form->c.c_car != Sdeclare)
			break;
	}
}
	
siLAmake_special()
{
	check_arg(1);
	check_type_symbol(&vs_base[0]);
	if ((enum stype)vs_base[0]->s.s_stype == stp_constant)
		FEerror("~S is a constant.", 1, vs_base[0]);
	vs_base[0]->s.s_stype = (short)stp_special;
}

siLAmake_constant()
{
	check_arg(2);
	check_type_symbol(&vs_base[0]);
	if ((enum stype)vs_base[0]->s.s_stype == stp_special)
		FEerror(
		 "The argument ~S to DEFCONSTANT is a special variable.",
		 1, vs_base[0]);
	vs_base[0]->s.s_stype = (short)stp_constant;
	vs_base[0]->s.s_dbind = vs_base[1];
	vs_pop;
}

Feval_when(arg)
object arg;
{
	object *base = vs_base;
	object ss;
	bool flag = FALSE;

	if(endp(arg))
		FEtoo_few_argumentsF(arg);
	for (ss = MMcar(arg);  !endp(ss);  ss = MMcdr(ss))
		if(MMcar(ss) == Seval)
			flag = TRUE;
		else if(MMcar(ss) != Sload && MMcar(ss) != Scompile)
		 FEinvalid_form("~S is an undefined situation for EVAL-WHEN.",
				MMcar(ss));
	if(flag) {
		vs_push(make_cons(Sprogn, MMcdr(arg)));
		eval(vs_head);
	} else {
		vs_base = base;
		vs_top = base+1;
		vs_base[0] = Cnil;
	}
}

Fdeclare(arg)
object arg;
{
	FEerror("DECLARE appeared in an invalid position.", 0);
}

Flocally(body)
object body;
{
	object *oldlex = lex_env;
	object x, ds, vs, v;

	lex_copy();
	body = find_special(body, NULL, NULL);
	vs_push(body);
	Fprogn(body);
	lex_env = oldlex;
}

Fthe(args)
object args;
{
	object *vs;

	if(endp(args) || endp(MMcdr(args)))
		FEtoo_few_argumentsF(args);
	if(!endp(MMcddr(args)))
		FEtoo_many_argumentsF(args);
	eval(MMcadr(args));
	args = MMcar(args);
	if (type_of(args) == t_cons && MMcar(args) == Svalues) {
		vs = vs_base;
		for (args=MMcdr(args); !endp(args); args=MMcdr(args), vs++){
			if (vs >= vs_top)
				FEerror("Too many return values.", 0);
			if (ifuncall2(Stypep, *vs, MMcar(args)) == Cnil)
				FEwrong_type_argument(MMcar(args), *vs);
		}
		if (vs < vs_top)
			FEerror("Too few return values.", 0);
	} else {
		if (ifuncall2(Stypep, vs_base[0], args) == Cnil)
			FEwrong_type_argument(args, vs_base[0]);
	}
}

init_toplevel()
{
	make_special_form("DEFUN",Fdefun);
	make_si_function("*MAKE-SPECIAL", siLAmake_special);
	make_si_function("*MAKE-CONSTANT", siLAmake_constant);
	make_special_form("EVAL-WHEN", Feval_when);
	make_special_form("THE", Fthe);
	Scompile = make_ordinary("COMPILE");
	enter_mark_origin(&Scompile);
	Sload = make_ordinary("LOAD");
	enter_mark_origin(&Sload);
	Seval = make_ordinary("EVAL");
	enter_mark_origin(&Seval);
	make_special_form("DECLARE",Fdeclare);
	Sdeclare = make_ordinary("DECLARE");
	enter_mark_origin(&Sdeclare);
	Sprogn = make_ordinary("PROGN");
	enter_mark_origin(&Sprogn);
	Seval = make_ordinary("EVAL");
	enter_mark_origin(&Seval);
	make_special_form("LOCALLY",Flocally);

	siSvariable_documentation
	= make_si_ordinary("VARIABLE-DOCUMENTATION");
	siSfunction_documentation
	= make_si_ordinary("FUNCTION-DOCUMENTATION");

	Swarn = make_ordinary("WARN");
	enter_mark_origin(&Swarn);

	Svalues = make_ordinary("VALUES");
	Stypep = make_ordinary("TYPEP");
	enter_mark_origin(&Stypep);
}
