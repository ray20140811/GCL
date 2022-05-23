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

	error.c

	Errors
*/

#include "include.h"
#include <varargs.h>
object siSuniversal_error_handler;

static object null_string;

object siSterminal_interrupt;

terminal_interrupt(correctable)
{
	ifuncall1(siSterminal_interrupt, correctable?Ct:Cnil);
}

object
ihs_function_name(x)
object x;
{
	object y;

	switch (type_of(x)) {
	case t_symbol:
		return(x);

	case t_cons:
		y = x->c.c_car;
		if (y == Slambda)
			return(Slambda);
		if (y == Slambda_closure)
			return(Slambda_closure);
		if (y == Slambda_block || y == siSlambda_block_expanded) {
			x = x->c.c_cdr;
			if (type_of(x) != t_cons)
				return(Slambda_block);
			return(x->c.c_car);
		}
		if (y == Slambda_block_closure) {
			x = x->c.c_cdr;
			if (type_of(x) != t_cons)
				return(Slambda_block_closure);
			x = x->c.c_cdr;
			if (type_of(x) != t_cons)
				return(Slambda_block_closure);
			x = x->c.c_cdr;
			if (type_of(x) != t_cons)
				return(Slambda_block_closure);
			x = x->c.c_cdr;
			if (type_of(x) != t_cons)
				return(Slambda_block_closure);
			return(x->c.c_car);
		}
		/* a general special form */
		if (y->s.s_sfdef != NOT_SPECIAL)
		  return y;
		return(Cnil);

	case t_cfun:
        case t_sfun:
        case t_vfun:
        case t_cclosure:
        case t_gfun:

		return(x->cf.cf_name);

	default:
		return(Cnil);
	}
}

object
ihs_top_function_name()
{
	object x;
	ihs_ptr h = ihs_top;

	while (h >= ihs_org) {
		x = ihs_function_name(h->ihs_function);
		if (x != Cnil)
			return(x);
		h--;
	}
	return(Cnil);
}


call_error_handler()
{
	super_funcall(siSuniversal_error_handler);
}


FEerror(s, num, arg1, arg2, arg3, arg4)
char *s;
int num;
object arg1, arg2, arg3, arg4;
{
	vs_base = vs_top;

	vs_push(Kerror);			/*  :ERROR  */
	vs_push(Cnil);				/*  not correctable  */
	vs_push(ihs_top_function_name());	/*  function  */
	vs_push(null_string);			/*  continue-format-string  */
	vs_push(Cnil);
	if(num >= 1) vs_push(arg1);		/*  arguments  */
	if(num >= 2) vs_push(arg2);
	if(num >= 3) vs_push(arg3);
	if(num >= 4) vs_push(arg4);
	vs_base[4] = make_simple_string(s);	/*  error-format-string  */
	call_error_handler();
}

FEwrong_type_argument(type, value)
object type, value;
{
	vs_base = vs_top;
	vs_push(Kwrong_type_argument);
	vs_push(Cnil);
	vs_push(ihs_top_function_name());
	vs_push(null_string);
	vs_push(Cnil);
	vs_push(value);
	vs_push(type);
	vs_base[4] = make_simple_string("~S is not of type ~S.");
	call_error_handler();
}

FEtoo_few_arguments(base, top)
object *base, *top;
{
	vs_base = vs_top;
	vs_push(Ktoo_few_arguments);
	vs_push(Cnil);
	vs_push(ihs_top_function_name());
	vs_push(null_string);
	vs_push(make_simple_string("~S [or a callee] requires more than ~R argument~:p."));
	vs_push(ihs_top_function_name());
	vs_push(make_fixnum(top - base));
	call_error_handler();
}

FEtoo_few_argumentsF(args)
object args;
{
	vs_base = vs_top;
	vs_push(Ktoo_few_arguments);
	vs_push(Cnil);
	vs_push(ihs_top_function_name());
	vs_push(null_string);
	vs_push(Cnil);
	vs_push(ihs_top_function_name());
	vs_push(args);
	vs_base[4] = make_simple_string("Too few arguments.");
	call_error_handler();
}

FEtoo_many_arguments(base, top)
object *base, *top;
{
	vs_base = vs_top;
	vs_push(Ktoo_many_arguments);
	vs_push(Cnil);
	vs_push(ihs_top_function_name());
	vs_push(null_string);
	vs_push(make_simple_string("~S [or a callee] requires less than ~R argument~:p."));
	vs_push(ihs_top_function_name());
	vs_push(make_fixnum(top - base));
	call_error_handler();
}

FEtoo_many_argumentsF(args)
object args;
{
	vs_base = vs_top;
	vs_push(Ktoo_many_arguments);
	vs_push(Cnil);
	vs_push(ihs_top_function_name());
	vs_push(null_string);
	vs_push(Cnil);
	vs_push(ihs_top_function_name());
	vs_push(args);
	vs_base[4] = make_simple_string("Too many arguments.");
	call_error_handler();
}

FEinvalid_macro_call()
{
	vs_base = vs_top;
	vs_push(Kinvalid_form);
	vs_push(Cnil);
	vs_push(ihs_top_function_name());
	vs_push(null_string);
	vs_push(make_simple_string("Invalid macro call to ~S."));
	vs_push(ihs_top_function_name());
	call_error_handler();
}

FEunexpected_keyword(key)
object key;
{
	if (!keywordp(key))
		not_a_keyword(key);
	vs_base = vs_top;
	vs_push(Kunexpected_keyword);
	vs_push(Cnil);
	vs_push(ihs_top_function_name());
	vs_push(null_string);
	vs_push(Cnil);
	vs_push(ihs_top_function_name());
	vs_push(key);
	vs_base[4]
	= make_simple_string("~S does not allow the keyword ~S.");
	call_error_handler();
}

FEinvalid_form(s, form)
char *s;
object form;
{
	vs_base = vs_top;
	vs_push(Kinvalid_form);
	vs_push(Cnil);
	vs_push(ihs_top_function_name());
	vs_push(null_string);
	vs_push(Cnil);
	vs_push(form);
	vs_base[4] = make_simple_string(s);
	call_error_handler();
}

FEunbound_variable(sym)
object sym;
{
	vs_base = vs_top;
	vs_push(Kunbound_variable);
	vs_push(Cnil);
	vs_push(ihs_top_function_name());
	vs_push(null_string);
	vs_push(Cnil);
	vs_push(sym);
	vs_base[4] = make_simple_string("The variable ~S is unbound.");
	call_error_handler();
}

FEinvalid_variable(s, obj)
char *s;
object obj;
{
	vs_base = vs_top;
	vs_push(Kinvalid_variable);
	vs_push(Cnil);
	vs_push(ihs_top_function_name());
	vs_push(null_string);
	vs_push(Cnil);
	vs_push(obj);
	vs_base[4] = make_simple_string(s);
	call_error_handler();
}

FEundefined_function(fname)
object fname;
{
	vs_base = vs_top;
	vs_push(Kundefined_function);
	vs_push(Cnil);
	vs_push(ihs_top_function_name());
	vs_push(null_string);
	vs_push(Cnil);
	vs_push(fname);
	vs_base[4] = make_simple_string("The function ~S is undefined.");
	call_error_handler();
}

FEinvalid_function(obj)
object obj;
{
	vs_base = vs_top;
	vs_push(Kinvalid_function);
	vs_push(Cnil);
	vs_push(ihs_top_function_name());
	vs_push(null_string);
	vs_push(Cnil);
	vs_push(obj);
	vs_base[4] = make_simple_string("~S is invalid as a function.");
	call_error_handler();
}


CEerror(err_str, cont_str, num, arg1, arg2, arg3, arg4)
char *err_str, *cont_str;
int num;
object arg1, arg2, arg3, arg4;
{
	object *old_base = vs_base;
	object *old_top = vs_top;

	vs_base = vs_top;

	vs_push(Kerror);			/*  :ERROR  */
	vs_push(Ct);				/*  correctable  */
	vs_push(ihs_top_function_name());	/*  function  */
	vs_push(make_simple_string(cont_str));
						/*  continue-format-string  */
	vs_push(Cnil);
	if(num >= 1) vs_push(arg1);		/*  arguments  */
	if(num >= 2) vs_push(arg2);
	if(num >= 3) vs_push(arg3);
	if(num >= 4) vs_push(arg4);
	vs_base[4] = make_simple_string(err_str);
						/*  error-format-string  */
	call_error_handler();

	vs_top = old_top;
	vs_base = old_base;
}

/*
	Lisp interface to IHS
*/

ihs_ptr get_ihs_ptr(x)
object x;
{
	ihs_ptr p;

	if (type_of(x) != t_fixnum)
		goto ILLEGAL;
	p = ihs_org + fix(x);
	if (ihs_org <= p && p <= ihs_top)
		return(p);
ILLEGAL:
	FEerror("~S is an illegal ihs index.", 1, x);
}

siLihs_top()
{
	check_arg(0);
	vs_push(make_fixnum(ihs_top - ihs_org));
}

siLihs_fun()
{
	check_arg(1);
	vs_base[0] = get_ihs_ptr(vs_base[0])->ihs_function;
}

siLihs_vs()
{
	check_arg(1);
	vs_base[0] = make_fixnum(get_ihs_ptr(vs_base[0])->ihs_base - vs_org);
}

frame_ptr get_frame_ptr(x)
object(x);
{
	frame_ptr p;

	if (type_of(x) != t_fixnum)
		goto ILLEGAL;
	p = frs_org + fix(x);
	if (frs_org <= p && p <= frs_top)
		return(p);
ILLEGAL:
	FEerror("~S is an illegal frs index.", 1, x);
}

siLfrs_top()
{
	check_arg(0);
	vs_push(make_fixnum(frs_top - frs_org));
}

siLfrs_vs()
{
	check_arg(1);
	vs_base[0] = make_fixnum(get_frame_ptr(vs_base[0])->frs_lex - vs_org);
}

siLfrs_bds()
{
	check_arg(1);
	vs_base[0]
	= make_fixnum(get_frame_ptr(vs_base[0])->frs_bds_top - bds_org);
}

siLfrs_class()
{
	enum fr_class c;

	check_arg(1);

	c = get_frame_ptr(vs_base[0])->frs_class;
	if (c == FRS_CATCH) vs_base[0] = Kcatch;
	else if (c == FRS_PROTECT) vs_base[0] = Kprotect;
	else if (c == FRS_CATCHALL) vs_base[0] = Kcatchall;
	else FEerror("Unknown frs class was detected.", 0);
}

siLfrs_tag()
{
	check_arg(1);
	vs_base[0] = get_frame_ptr(vs_base[0])->frs_val;
}

siLfrs_ihs()
{
	check_arg(1);
	vs_base[0]
	= make_fixnum(get_frame_ptr(vs_base[0])->frs_ihs - ihs_org);
}

bds_ptr get_bds_ptr(x)
object(x);
{
	bds_ptr p;

	if (type_of(x) != t_fixnum)
		goto ILLEGAL;
	p = bds_org + fix(x);
	if (bds_org <= p && p <= bds_top)
		return(p);
ILLEGAL:
	FEerror("~S is an illegal bds index.", 1, x);
}

siLbds_top()
{
	check_arg(0);
	vs_push(make_fixnum(bds_top - bds_org));
}

siLbds_var()
{
	check_arg(1);
	vs_base[0] = get_bds_ptr(vs_base[0])->bds_sym;
}

siLbds_val()
{
	check_arg(1);
	vs_base[0] = get_bds_ptr(vs_base[0])->bds_val;
}

object *get_vs_ptr(x)
object(x);
{
	object *p;

	if (type_of(x) != t_fixnum)
		goto ILLEGAL;
	p = vs_org + fix(x);
	if (vs_org <= p && p < vs_top)
		return(p);
ILLEGAL:
	FEerror("~S is an illegal vs index.", 1, x);
}

siLvs_top()
{
	object x;
	check_arg(0);
	/* shouldn't ref vs_top in a vs_push */
	x = (make_fixnum(vs_top - vs_org));
	vs_push(x);
}

siLvs()
{
	check_arg(1);
	vs_base[0] = *get_vs_ptr(vs_base[0]);
}

siLsch_frs_base ()
{
	frame_ptr x;
	ihs_ptr y;

	check_arg(2);
	y = get_ihs_ptr(vs_base[1]);
	for (x = get_frame_ptr(vs_base[0]);
	     x <= frs_top && x->frs_ihs < y; 
	     x++);
	if (x > frs_top) vs_base[0] = Cnil;
	else vs_base[0] = make_fixnum(x - frs_org);
	vs_top--;
}

siLinternal_super_go()
{
	frame_ptr fr;

	check_arg(3);

	fr = frs_sch(vs_base[0]);
	if (fr == NULL)
		FEerror("The tag ~S is missing.", 1, vs_base[0]);
	if (vs_base[2] == Cnil)
		vs_base[0] = vs_base[1];
	else
		vs_base[0] = MMcons(vs_base[0], vs_base[1]);
	vs_base++;
	vs_top = vs_base;
	unwind(fr,vs_base[-1]);
}

siLuniversal_error_handler()
{
	int i;

	for (i = 0;  i < vs_base[4]->st.st_fillp;  i++)
		putchar(vs_base[4]->st.st_self[i]);
	printf("\nLisp initialization failed.\n");
	exit(0);
}

check_arg_failed(n)
int n;
{
	object *base = vs_base, *top = vs_top;

	vs_base = vs_top;
	if (top - base < n)
		vs_push(Ktoo_few_arguments);
	else
		vs_push(Ktoo_many_arguments);
	vs_push(Cnil);
	vs_push(ihs_top_function_name());
	vs_push(null_string);
	if (top - base < n)
	    vs_push(make_simple_string("~S [or a callee] requires ~R argument~:p,~%but only ~R ~:*~[were~;was~:;were~] supplied."));
	else
	    vs_push(make_simple_string("~S [or a callee] requires only ~R argument~:p,~%but ~R ~:*~[were~;was~:;were~] supplied."));
	vs_push(ihs_top_function_name());
	vs_push(make_fixnum(n));
	vs_push(make_fixnum(top - base));
	call_error_handler();
}

too_few_arguments()
{
	FEtoo_few_arguments(vs_base, vs_top);
}

too_many_arguments()
{
	FEtoo_many_arguments(vs_base, vs_top);
}

ck_larg_at_least(n, x)
int n; object x;
{
	for(; n > 0; n--, x = x->c.c_cdr)
		if(endp(x))
		  FEerror("APPLY sended too few arguments to LAMBDA.", 0);
}

ck_larg_exactly(n, x)
int n; object x;
{
	for(; n > 0; n--, x = x->c.c_cdr)
		if(endp(x))
		  FEerror("APPLY sended too few arguments to LAMBDA.", 0);
	if(!endp(x)) FEerror("APPLY sended too many arguments to LAMBDA.", 0);
}

invalid_macro_call()
{
	FEinvalid_macro_call();
}

keyword_value_mismatch()
{
	FEerror("Keywords and values do not match.", 0);
}

not_a_keyword(x)
object x;
{
	FEerror("~S is not a keyword.", 1, x);
}

unexpected_keyword(key)
object key;
{
	FEunexpected_keyword(key);
}

object
wrong_type_argument(typ, obj)
object typ, obj;
{
	FEwrong_type_argument(typ, obj);
	/*  no return  */
}

illegal_declare(form)
{
	FEinvalid_form("~S is an illegal declaration form.", form);
}

not_a_symbol(obj)
{
	FEinvalid_variable("~S is not a symbol.", obj);
}

not_a_variable(obj)
{
	FEinvalid_variable("~S is not a variable.", obj);
}

illegal_index(x, i)
object x, i;
{
	FEerror("~S is an illegal index to ~S.", 2, i, x);
}

     

Lerror()
{
	object *base = vs_base, *top = vs_top;

	if (top - base == 0)
		too_few_arguments();
	vs_base = vs_top;
	vs_push(Kerror);
	vs_push(Cnil);
	vs_push( (ihs_top > ihs_org) ?
		ihs_function_name((ihs_top - 1)->ihs_function)
		: Cnil);
	vs_push(null_string);
	while (base < top)
		vs_push(*base++);
	call_error_handler();
}

object
LVerror(va_alist)
     va_dcl
{va_list ap;
 va_start(ap);
 fcall.fun= make_cfun(Lerror,Cnil,Cnil,0,0);
 fcalln_general(ap);
 va_end(ap);
 return Cnil;
}
     
Lcerror()
{
	object *base = vs_base, *top = vs_top;

	if (top - base < 2)
		too_few_arguments();
	vs_base = vs_top;
	vs_push(Kerror);
	vs_push(Ct);
	vs_push(ihs_function_name((ihs_top - 1)->ihs_function));
	while (base < top)
		vs_push(*base++);
	super_funcall(siSuniversal_error_handler);
	vs_base = vs_top;
	vs_push(Cnil);
}
int
vfun_wrong_number_of_args(x)
     object x;
{FEerror("Expected ~S args but received ~S args",2,
	 x,make_fixnum(VFUN_NARGS));
}

init_error()
{
	make_function("ERROR", Lerror);
	make_function("CERROR", Lcerror);

	Kerror = make_keyword("ERROR");
	Kwrong_type_argument = make_keyword("WRONG-TYPE-ARGUMENT");
	Ktoo_few_arguments = make_keyword("TOO-FEW-ARGUMENTS");
	Ktoo_many_arguments = make_keyword("TOO-MANY-ARGUMENTS");
	Kunexpected_keyword = make_keyword("UNEXPECTED-KEYWORD");
	Kinvalid_form = make_keyword("INVALID-FORM");
	Kunbound_variable = make_keyword("UNBOUND-VARIABLE");
	Kinvalid_variable = make_keyword("INVALID-VARIABLE");
	Kundefined_function = make_keyword("UNDEFINED-FUNCTION");
	Kinvalid_function = make_keyword("INVALID-FUNCTION");

	make_si_function("IHS-TOP", siLihs_top);
	make_si_function("IHS-FUN", siLihs_fun);
	make_si_function("IHS-VS", siLihs_vs);

	Kcatch = make_keyword("CATCH");
	Kprotect = make_keyword("PROTECT");
	Kcatchall = make_keyword("CATCHALL");

	make_si_function("FRS-TOP", siLfrs_top);
	make_si_function("FRS-VS", siLfrs_vs);
	make_si_function("FRS-BDS", siLfrs_bds);
	make_si_function("FRS-CLASS", siLfrs_class);
	make_si_function("FRS-TAG", siLfrs_tag);
	make_si_function("FRS-IHS", siLfrs_ihs);

	make_si_function("BDS-TOP", siLbds_top);
	make_si_function("BDS-VAR", siLbds_var);
	make_si_function("BDS-VAL", siLbds_val);

	make_si_function("VS-TOP", siLvs_top);
	make_si_function("VS", siLvs);

	make_si_function("SCH-FRS-BASE", siLsch_frs_base);

	make_si_function("INTERNAL-SUPER-GO", siLinternal_super_go);

	siSuniversal_error_handler =
	make_si_function("UNIVERSAL-ERROR-HANDLER",
			 siLuniversal_error_handler);

	null_string = make_simple_string("");
	enter_mark_origin(&null_string);

	siSterminal_interrupt = make_si_ordinary("TERMINAL-INTERRUPT");
	enter_mark_origin(&siSterminal_interrupt);
}
