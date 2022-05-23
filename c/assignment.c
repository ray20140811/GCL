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

	assignment.c

	Assignment
*/

#include "include.h"

object Ssetf;

object Sget;
object Saref;
object Ssvref;
object Selt;
object Schar;
object Sschar;
object Sfill_pointer;
object Sgethash;
object Scar;
object Scdr;

object Spush;
object Spop;
object Sincf;
object Sdecf;

object siSstructure_access;
object siSsetf_lambda;



object siSclear_compiler_properties;

object Swarn;

object siVinhibit_macro_special;


setq(sym, val)
object sym, val;
{
	object vd;
	enum stype type;

	if(type_of(sym) != t_symbol)
		not_a_symbol(sym);
	type = (enum stype)sym->s.s_stype;
	if(type == stp_special)
		sym->s.s_dbind = val;
	else
	if (type == stp_constant)
		FEinvalid_variable("Cannot assign to the constant ~S.", sym);
	else {
		vd = lex_var_sch(sym);
		if(MMnull(vd) || endp(MMcdr(vd)))
			sym->s.s_dbind = val;
		else
			MMcadr(vd) = val;
	}
}

Fsetq(form)
object form;
{
	if (endp(form)) {
		vs_base = vs_top;
		vs_push(Cnil);
	} else {
		object *top = vs_top;
		do {
			vs_top = top;
			if (endp(MMcdr(form)))
			FEinvalid_form("No value for ~S.", form->c.c_car);
			eval(MMcadr(form));
			setq(MMcar(form), vs_base[0]);
			form = MMcddr(form);
		} while (!endp(form));
		vs_top = vs_base+1;
	}
}

Fpsetq(arg)
object arg;
{
	object *old_top = vs_top;
	object *top;
	object argsv = arg;
	for (top = old_top;  !endp(arg);  arg = MMcddr(arg), top++) {
		if(endp(MMcdr(arg)))
			FEinvalid_form("No value for ~S.", arg->c.c_car);
		eval(MMcadr(arg));
		top[0] = vs_base[0];
		vs_top = top + 1;
	}
	for (arg = argsv, top = old_top; !endp(arg); arg = MMcddr(arg), top++)
		setq(MMcar(arg),top[0]);
	vs_base = vs_top = old_top;
	vs_push(Cnil);
}

Lset()
{
	check_arg(2);
	if (type_of(vs_base[0]) != t_symbol)
		not_a_symbol(vs_base[0]);
	if ((enum stype)vs_base[0]->s.s_stype == stp_constant)
		FEinvalid_variable("Cannot assign to the constant ~S.",
				   vs_base[0]);
	vs_base[0]->s.s_dbind = vs_base[1];
	vs_base++;
}

siLfset()
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
	vs_base[0] = clear_compiler_properties(vs_base[0],vs_base[1]);
	if (vs_base[0]->s.s_hpack == lisp_package &&
	    vs_base[0]->s.s_gfdef != OBJNULL && initflag) {
		vs_push(make_simple_string(
			"~S is being redefined."));
		ifuncall2(Swarn, vs_head, vs_base[0]);
		vs_pop;
	}
	if (type_of(vs_base[1]) == t_cfun ||
	    type_of(vs_base[1]) == t_sfun ||
	    type_of(vs_base[1]) == t_vfun ||
	    type_of(vs_base[1]) == t_gfun ||
	    type_of(vs_base[1]) == t_cclosure
	    ) {
		vs_base[0]->s.s_gfdef = vs_base[1];
		vs_base[0]->s.s_mflag = FALSE;
	} else if (car(vs_base[1]) == Sspecial)
		FEerror("Cannot define a special form.", 0);
	else if (vs_base[1]->c.c_car == Smacro) {
		vs_base[0]->s.s_gfdef = vs_base[1]->c.c_cdr;
		vs_base[0]->s.s_mflag = TRUE;
	} else {
		vs_base[0]->s.s_gfdef = vs_base[1];
		vs_base[0]->s.s_mflag = FALSE;
	}
	vs_base++;
}

Fmultiple_value_setq(form)
object form;
{
	object vars;
	int n, i;

	if (endp(form) || endp(form->c.c_cdr) ||
	    !endp(form->c.c_cdr->c.c_cdr))
	    FEinvalid_form("~S is an illegal argument to MULTIPLE-VALUE-SETQ",
			   form);
	vars = form->c.c_car;
	vs_push(vars);
	eval(form->c.c_cdr->c.c_car);
	n = vs_top - vs_base;
	for (i = 0;  !endp(vars);  i++, vars = vars->c.c_cdr)
		if (i < n)
			setq(vars->c.c_car, vs_base[i]);
		else
			setq(vars->c.c_car, Cnil);
	vs_top = vs_base+1;
}

Lmakunbound()
{
	check_arg(1);
	if (type_of(vs_base[0]) != t_symbol)
		not_a_symbol(vs_base[0]);
	if ((enum stype)vs_base[0]->s.s_stype == stp_constant)
		FEinvalid_variable("Cannot unbind the constant ~S.",
				   vs_base[0]);
	vs_base[0]->s.s_dbind = OBJNULL;
}

object siLtraced;

Lfmakunbound()
{
	check_arg(1);
	if(type_of(vs_base[0]) != t_symbol)
		not_a_symbol(vs_base[0]);
	if (vs_base[0]->s.s_sfdef != NOT_SPECIAL) {
		if (vs_base[0]->s.s_mflag) {
			if (symbol_value(siVinhibit_macro_special) != Cnil)
				vs_base[0]->s.s_sfdef = NOT_SPECIAL;
		} else if (symbol_value(siVinhibit_macro_special) != Cnil)
			FEerror("~S, a special form, cannot be redefined.",
				1, vs_base[0]);
	}
	remf(&(vs_base[0]->s.s_plist),siLtraced);
	clear_compiler_properties(vs_base[0],Cnil);
	if (vs_base[0]->s.s_hpack == lisp_package &&
	    vs_base[0]->s.s_gfdef != OBJNULL && initflag) {
		vs_push(make_simple_string(
			"~S is being redefined."));
		ifuncall2(Swarn, vs_head, vs_base[0]);
		vs_pop;
	}
	vs_base[0]->s.s_gfdef = OBJNULL;
	vs_base[0]->s.s_mflag = FALSE;
}

Fsetf(form)
object form;
{
	if (endp(form)) {
		vs_base = vs_top;
		vs_push(Cnil);
	} else {
		object *top = vs_top;
		do {
			vs_top = top;
			if (endp(MMcdr(form)))
			FEinvalid_form("No value for ~S.", form->c.c_car);
			setf(MMcar(form), MMcadr(form));
			form = MMcddr(form);
		} while (!endp(form));
		vs_top = vs_base+1;
	}
}

#define	eval_push(form)  \
{  \
	object *old_top = vs_top;  \
  \
	eval(form);  \
	*old_top = vs_base[0];  \
	vs_top = old_top + 1;  \
}

setf(place, form)
object place, form;
{
	object fun;
	object *vs = vs_top;
	int (*f)();
	object args;
	object x;
	int i;
	extern siLaset();
	extern siLsvset();
	extern siLelt_set();
	extern siLchar_set();
	extern siLfill_pointer_set();
	extern siLhash_set();

	if (type_of(place) != t_cons) {
		eval(form);
		setq(place, vs_base[0]);
		return;
	}
	fun = place->c.c_car;
	if (type_of(fun) != t_symbol)
		goto OTHERWISE;
	args = place->c.c_cdr;
	if (fun == Sget) {
		eval_push(car(args));
		eval_push(form);
		eval_push(car(args->c.c_cdr));
		vs_base = vs;
		siLputprop();
		return;
	}
	if (fun == Saref) { f = siLaset; goto EVAL; }
	if (fun == Ssvref) { f = siLsvset; goto EVAL; }
	if (fun == Selt) { f = siLelt_set; goto EVAL; }
	if (fun == Schar) { f = siLchar_set; goto EVAL; }
	if (fun == Sschar) { f = siLchar_set; goto EVAL; }
	if (fun == Sfill_pointer) { f = siLfill_pointer_set; goto EVAL; }
	if (fun == Sgethash) { f = siLhash_set; goto EVAL; }
	if (fun == Scar) {
		eval_push(args->c.c_car);
		eval(form);
		if (type_of(*vs) != t_cons)
			FEerror("~S is not a cons.", 1, *vs);
		(*vs)->c.c_car = vs_base[0];
		return;
	}
	if (fun == Scdr) {
		eval_push(args->c.c_car);
		eval(form);
		if (type_of(*vs) != t_cons)
			FEerror("~S is not a cons.", 1, *vs);
		(*vs)->c.c_cdr = vs_base[0];
		return;
	}
	x = getf(fun->s.s_plist, siSstructure_access, Cnil);
	if (x == Cnil || type_of(x) != t_cons)
		goto OTHERWISE;
	if (getf(fun->s.s_plist, siSsetf_lambda, Cnil) == Cnil)
		goto OTHERWISE;
	if (type_of(x->c.c_cdr) != t_fixnum)
		goto OTHERWISE;
	i = fix(x->c.c_cdr);
/*
	if (i < 0)
		goto OTHERWISE;
*/
	x = x->c.c_car;
	if (x == Svector) {
		eval_push(args->c.c_car);
		x = *vs;
		if (type_of(x) != t_vector || i >= x->v.v_fillp)
			goto OTHERWISE;
		eval(form);
		x->v.v_self[i] = vs_base[0];
	} else if (x == Slist) {
		eval_push(args->c.c_car);
		for (x = *vs;  i > 0;  --i)
			x = cdr(x);
		if (type_of(x) != t_cons)
			goto OTHERWISE;
		eval(form);
		x->c.c_car = vs_base[0];
	} else {
		eval_push(args->c.c_car);
		eval(form);
		structure_set(*vs, x, i, vs_base[0]);
	}
	return;

EVAL:
	for (;  !endp(args);  args = args->c.c_cdr) {
		eval_push(args->c.c_car);
	}
	eval_push(form);
	vs_base = vs;
	(*f)();
	return;

OTHERWISE:
	vs_base = vs_top;
	vs_push(Ssetf);
	vs_push(place);
	vs_push(form);
	vs_push(Cnil);
	stack_cons();
	stack_cons();
	stack_cons();
/***/
#define VS_PUSH_ENV \
	if(lex_env[1]){ \
	  vs_push(list(3,lex_env[0],lex_env[1],lex_env[2]));} \
	else {vs_push(Cnil);}
        VS_PUSH_ENV ;
/***/
	if (!Ssetf->s.s_mflag || Ssetf->s.s_gfdef == OBJNULL)
		FEerror("Where is SETF?", 0);
	funcall(Ssetf->s.s_gfdef);
	eval(vs_base[0]);
}

Fpush(form)
object form;
{
	object var;

	if (endp(form) || endp(MMcdr(form)))
		FEtoo_few_argumentsF(form);
	if (!endp(MMcddr(form)))
		FEtoo_many_argumentsF(form);
	var = MMcadr(form);
	if (type_of(var) != t_cons) {
		eval(MMcar(form));
		form = vs_base[0];
		eval(var);
		vs_base[0] = MMcons(form, vs_base[0]);
		setq(var, vs_base[0]);
		return;
	}
	vs_base = vs_top;
	vs_push(Spush);
	vs_push(form);
	stack_cons();
/***/
         VS_PUSH_ENV ;
/***/
	if (!Spush->s.s_mflag || Spush->s.s_gfdef == OBJNULL)
		FEerror("Where is PUSH?", 0);
	funcall(Spush->s.s_gfdef);
	eval(vs_base[0]);
}

Fpop(form)
object form;
{
	object var;

	if (endp(form))
		FEtoo_few_argumentsF(form);
	if (!endp(MMcdr(form)))
		FEtoo_many_argumentsF(form);
	var = MMcar(form);
	if (type_of(var) != t_cons) {
		eval(var);
		setq(var, cdr(vs_base[0]));
		vs_base[0] = car(vs_base[0]);
		return;
	}
	vs_base = vs_top;
	vs_push(Spop);
	vs_push(form);
	stack_cons();
/***/
	VS_PUSH_ENV ;
/***/
	if (!Spop->s.s_mflag || Spop->s.s_gfdef == OBJNULL)
		FEerror("Where is POP?", 0);
	funcall(Spop->s.s_gfdef);
	eval(vs_base[0]);
}

Fincf(form)
object form;
{
	object var;
	object one_plus(), number_plus();

	if (endp(form))
		FEtoo_few_argumentsF(form);
	if (!endp(MMcdr(form)) && !endp(MMcddr(form)))
		FEtoo_many_argumentsF(form);
	var = MMcar(form);
	if (type_of(var) != t_cons) {
		if (endp(MMcdr(form))) {
			eval(var);
			vs_base[0] = one_plus(vs_base[0]);
			setq(var, vs_base[0]);
			return;
		}
		eval(MMcadr(form));
		form = vs_base[0];
		eval(var);
		vs_base[0] = number_plus(vs_base[0], form);
		setq(var, vs_base[0]);
		return;
	}
	vs_base = vs_top;
	vs_push(Sincf);
	vs_push(form);
	stack_cons();
/***/
	VS_PUSH_ENV ;
/***/
	if (!Sincf->s.s_mflag || Sincf->s.s_gfdef == OBJNULL)
		FEerror("Where is INCF?", 0);
	funcall(Sincf->s.s_gfdef);
	eval(vs_base[0]);
}

Fdecf(form)
object form;
{
	object var;
	object one_minus(), number_minus();

	if (endp(form))
		FEtoo_few_argumentsF(form);
	if (!endp(MMcdr(form)) && !endp(MMcddr(form)))
		FEtoo_many_argumentsF(form);
	var = MMcar(form);
	if (type_of(var) != t_cons) {
		if (endp(MMcdr(form))) {
			eval(var);
			vs_base[0] = one_minus(vs_base[0]);
			setq(var, vs_base[0]);
			return;
		}
		eval(MMcadr(form));
		form = vs_base[0];
		eval(var);
		vs_base[0] = number_minus(vs_base[0], form);
		setq(var, vs_base[0]);
		return;
	}
	vs_base = vs_top;
	vs_push(Sdecf);
	vs_push(form);
	stack_cons();
/***/
	VS_PUSH_ENV ;
/***/
	if (!Sdecf->s.s_mflag || Sdecf->s.s_gfdef == OBJNULL)
		FEerror("Where is DECF?", 0);
	funcall(Sdecf->s.s_gfdef);
	eval(vs_base[0]);
}


object
clear_compiler_properties(sym,code)
object sym;
object code;
{ object tem;
  use_fast_links(2,Cnil,sym);
  tem = getf(sym->s.s_plist,siLtraced,Cnil);
  if (symbol_value(siVinhibit_macro_special) != Cnil)
    (void)ifuncall2(siSclear_compiler_properties, sym,code);
  if (tem != Cnil) return tem;
  return sym;
  
}

siLclear_compiler_properties()
{
	check_arg(2);
}


init_assignment()
{
	make_special_form("SETQ", Fsetq);
	make_special_form("PSETQ", Fpsetq);
	make_function("SET", Lset);
	make_si_function("FSET", siLfset);

	make_special_form("MULTIPLE-VALUE-SETQ", Fmultiple_value_setq);

	make_function("MAKUNBOUND", Lmakunbound);
	make_function("FMAKUNBOUND", Lfmakunbound);

	Ssetf = make_ordinary("SETF");

	Sget = make_ordinary("GET");
	Saref = make_ordinary("AREF");
	Ssvref = make_ordinary("SVREF");
	Selt = make_ordinary("ELT");
	Schar = make_ordinary("CHAR");
	Sschar = make_ordinary("SCHAR");
	Sfill_pointer = make_ordinary("FILL-POINTER");
	Sgethash = make_ordinary("GETHASH");
	Scar = make_ordinary("CAR");
	Scdr = make_ordinary("CDR");

	make_special_form("SETF", Fsetf);

	Spush = make_ordinary("PUSH");
	Spop = make_ordinary("POP");
	Sincf = make_ordinary("INCF");
	Sdecf = make_ordinary("DECF");

	make_special_form("PUSH", Fpush);
	make_special_form("POP", Fpop);
	make_special_form("INCF", Fincf);
	make_special_form("DECF", Fdecf);

	siSstructure_access = make_si_ordinary("STRUCTURE-ACCESS");
	siLtraced = make_si_ordinary("TRACED");
	enter_mark_origin(&siSstructure_access);
	siSsetf_lambda = make_si_ordinary("SETF-LAMBDA");
	enter_mark_origin(&siSsetf_lambda);
	Svector = make_ordinary("VECTOR");
	Slist = make_ordinary("LIST");

	siSclear_compiler_properties
	= make_si_function("CLEAR-COMPILER-PROPERTIES",
			   siLclear_compiler_properties);
}
