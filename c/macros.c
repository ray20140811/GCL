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
	macros.c
*/

#include "include.h"


object Swarn;

object siVinhibit_macro_special;

siLdefine_macro()
{
	check_arg(2);
	if (type_of(vs_base[0]) != t_symbol)
		not_a_symbol(vs_base[0]);
	if (vs_base[0]->s.s_sfdef != NOT_SPECIAL) {
		if (vs_base[0]->s.s_mflag) {
			if (symbol_value(siVinhibit_macro_special) != Cnil)
				vs_base[0]->s.s_sfdef = NOT_SPECIAL;
		} else if (symbol_value(siVinhibit_macro_special) != Cnil)
			FEerror("~S, a special form, cannot be redefined.",
				1, vs_base[0]);
	}
	clear_compiler_properties(vs_base[0],MMcaddr(vs_base[1]));
	if (vs_base[0]->s.s_hpack == lisp_package &&
	    vs_base[0]->s.s_gfdef != OBJNULL && initflag) {
		vs_push(make_simple_string(
			"~S is being redefined."));
		ifuncall2(Swarn, vs_head, vs_base[0]);
		vs_pop;
	}
	vs_base[0]->s.s_gfdef = MMcaddr(vs_base[1]);
	vs_base[0]->s.s_mflag = TRUE;
	if (MMcar(vs_base[1]) != Cnil) {
		vs_base[0]->s.s_plist
		= putf(vs_base[0]->s.s_plist,
		       MMcar(vs_base[1]),
		       siSfunction_documentation);
	}
	if (MMcadr(vs_base[1]) != Cnil) {
		vs_base[0]->s.s_plist
		= putf(vs_base[0]->s.s_plist,
		       MMcadr(vs_base[1]),
		       siSpretty_print_format);
	}
	vs_top = vs_base+1;
}

Fdefmacro(form)
object form;
{
	object *top = vs_top;
	object name;

	if (endp(form) || endp(MMcdr(form)))
		FEtoo_few_argumentsF(form);
	name = MMcar(form);
	if (type_of(name) != t_symbol)
		not_a_symbol(name);
	vs_push(ifuncall3(siSdefmacroA,
			  name,
			  MMcadr(form),
			  MMcddr(form)));
	if (MMcar(top[0]) != Cnil)
		name->s.s_plist
		= putf(name->s.s_plist,
		       MMcar(top[0]),
		       siSfunction_documentation);
	if (MMcadr(top[0]) != Cnil)
		name->s.s_plist
		= putf(name->s.s_plist,
		       MMcadr(top[0]),
		       siSpretty_print_format);
	if (name->s.s_sfdef != NOT_SPECIAL) {
		if (name->s.s_mflag) {
			if (symbol_value(siVinhibit_macro_special) != Cnil)
				name->s.s_sfdef = NOT_SPECIAL;
		} else if (symbol_value(siVinhibit_macro_special) != Cnil)
			FEerror("~S, a special form, cannot be redefined.",
				1, name);
	}
	clear_compiler_properties(name,MMcaddr(top[0]));
	if (name->s.s_hpack == lisp_package &&
	    name->s.s_gfdef != OBJNULL && initflag) {
		vs_push(make_simple_string(
			"~S is being redefined."));
		ifuncall2(Swarn, vs_head, name);
		vs_pop;
	}
	name->s.s_gfdef = MMcaddr(top[0]);
	name->s.s_mflag = TRUE;
	vs_base = vs_top = top;
	vs_push(name);
}

/*
	MACRO_EXPAND1 is an internal function which simply applies the
	function EXP_FUN to FORM.  On return, the expanded form is stored
	in VS_BASE[0].
*/
macro_expand1(exp_fun, form)
object exp_fun,form;
{
	vs_base = vs_top;
	vs_push(exp_fun);
	vs_push(form);
/***/
/*	
	Macros may well need their functional environment to expand properly.
	For example setf needs to expand the place which may be a local
	macro.  They are not supposed to need the other parts of the
	environment
*/
#define VS_PUSH_ENV \
	if(lex_env[1]){ \
	  vs_push(list(3,lex_env[0],lex_env[1],lex_env[2]));} \
	else {vs_push(Cnil);}
        VS_PUSH_ENV ;
/***/
	super_funcall(symbol_value(Vmacroexpand_hook));
	if (vs_top == vs_base)
		vs_push(Cnil);
}

/*
	MACRO_DEF is an internal function which, given a form, returns
	the expansion function if the form is a macro form.  Otherwise,
	MACRO_DEF returns NIL.
*/
object
macro_def(form)
object form;
{
	object head, fd;

	if (type_of(form) != t_cons)
		return(Cnil);
	head = MMcar(form);
	if (type_of(head) != t_symbol)
		return(Cnil);
	fd = lex_fd_sch(head);
	if (MMnull(fd))
		if (head->s.s_mflag)
			return(head->s.s_gfdef);
		else
			return(Cnil);
	else if (MMcadr(fd) == Smacro)
		return(MMcaddr(fd));
	else
		return(Cnil);
}

Lmacroexpand()
{
	object exp_fun, env;
	object *base = vs_base;
	object *lex=lex_env;

	lex_env = vs_top;
	if (vs_top-vs_base < 1)
		too_few_arguments();
	else if (vs_top-vs_base == 1) {
		vs_top[0] = vs_top[1] = vs_top[2] = Cnil;
		vs_top += 3;
	} else if (vs_top - vs_base == 2) {
		env = vs_base[1];
		vs_push(car(env));
		env = cdr(env);
		vs_push(car(env));
		env = cdr(env);
		vs_push(car(env));
	} else
		too_many_arguments();
	exp_fun = macro_def(base[0]);
	if (MMnull(exp_fun)) {
		lex_env = lex;
		vs_base = base;
		vs_top = base + 1;
		vs_push(Cnil);
	} else {
		object *top = vs_top;

		do {
			macro_expand1(exp_fun, base[0]);
			base[0] = vs_base[0];
			vs_top = top;
			exp_fun = macro_def(base[0]);
		} while (!MMnull(exp_fun));
		lex_env = lex;
		vs_base = base;
		vs_top = base+1;
		vs_push(Ct);
	}
}

Lmacroexpand_1()
{
	object exp_fun;
	object *base=vs_base;
	object *lex=lex_env;

	lex_env = vs_top;
	if (vs_top-vs_base<1)
		too_few_arguments();
	else if (vs_top-vs_base == 1) {
		vs_push(Cnil);
		vs_push(Cnil);
		vs_push(Cnil);
	} else if (vs_top-vs_base == 2) {
		vs_push(car(vs_base[1]));
		vs_push(car(cdr(vs_base[1])));
		vs_push(car(cdr(cdr(vs_base[1]))));
	} else
		too_many_arguments();
	exp_fun = macro_def(base[0]);
	if (MMnull(exp_fun)) {
		lex_env = lex;
		vs_base = base;
		vs_top = base+1;
		vs_push(Cnil);
	} else {
		macro_expand1(exp_fun, base[0]);
		base[0] = vs_base[0];
		lex_env = lex;
		vs_base = base;
		vs_top = base+1;
		vs_push(Ct);
	}
}

/*
	MACRO_EXPAND is an internal function which, given a form, expands it
	as many times as possible and returns the finally expanded form.
	The argument 'form' need not be marked for GBC and the result is not
	marked.
*/
object
macro_expand(form)
object form;
{
	object exp_fun, head, fd;
	object *base = vs_base;
	object *top = vs_top;

	/* Check if the given form is a macro form.  If not, return
	   immediately.  Macro definitions are superseded by special-
	   form definitions.
	*/
	if (type_of(form) != t_cons)
		return(form);
	head = MMcar(form);
	if (type_of(head) != t_symbol)
		return(form);
	if (head->s.s_sfdef != NOT_SPECIAL)
		return(form);
	fd = lex_fd_sch(head);
	if (MMnull(fd))
		if (head->s.s_mflag)
			exp_fun = head->s.s_gfdef;
		else
			return(form);
	else if (MMcadr(fd) == Smacro)
		exp_fun = MMcaddr(fd);
	else
		return(form);
	
	vs_top = top;
	vs_push(form);			/* saves form in top[0] */
	vs_push(exp_fun);		/* saves exp_fun in top[1] */
LOOP:
	/*  macro_expand1(exp_fun, form);  */
	vs_base = vs_top;
	vs_push(exp_fun);
	vs_push(form);
/***/
/*	vs_push(Cnil); */
	VS_PUSH_ENV ;
/***/
	super_funcall(symbol_value(Vmacroexpand_hook));
	if (vs_base == vs_top)
		vs_push(Cnil);
	top[0] = form = vs_base[0];
	/* Check if the expanded form is again a macro form.  If not,
	   reset the stack and return.
	*/
	if (type_of(form) != t_cons)
		goto END;
	head = MMcar(form);
	if (type_of(head) != t_symbol)
		goto END;
	if (head->s.s_sfdef != NOT_SPECIAL)
		goto END;
	fd=lex_fd_sch(head);
	if (MMnull(fd))
		if (head->s.s_mflag)
			exp_fun = head->s.s_gfdef;
		else
			goto END;
	else if (MMcadr(fd) == Smacro)
		exp_fun = MMcaddr(fd);
	else
		goto END;
	/* The expanded form is a macro form.  Continue expansion.  */
	top[1] = exp_fun;
	vs_top = top + 2;
	goto LOOP;
END:
	vs_base = base;
	vs_top = top;
	return(form);
}

init_macros()
{
	make_si_function("DEFINE-MACRO", siLdefine_macro);
	Vmacroexpand_hook
	= make_special("*MACROEXPAND-HOOK*", Sfuncall);
	make_function("MACROEXPAND", Lmacroexpand);
	make_function("MACROEXPAND-1", Lmacroexpand_1);
	make_special_form("DEFMACRO", Fdefmacro);
	siSdefmacroA = make_si_ordinary("DEFMACRO*");
	enter_mark_origin(&siSdefmacroA);

	siVinhibit_macro_special =
	make_si_special("*INHIBIT-MACRO-SPECIAL*", Cnil);
}
