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
	predicate.c

	predicates
*/

#include "include.h"

Lnull()
{
	check_arg(1);

	if (vs_base[0] == Cnil)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Lsymbolp()
{
	check_arg(1);

	if (type_of(vs_base[0]) == t_symbol)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Latom()
{
	check_arg(1);

	if (type_of(vs_base[0]) != t_cons)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Lconsp()
{
	check_arg(1);

	if (type_of(vs_base[0]) == t_cons)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Llistp()
{
	check_arg(1);

	if (vs_base[0] == Cnil || type_of(vs_base[0]) == t_cons)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Lnumberp()
{
	enum type t;
	check_arg(1);

	t = type_of(vs_base[0]);
	if (t == t_fixnum || t == t_bignum || t == t_ratio ||
	    t == t_shortfloat || t == t_longfloat ||
	    t == t_complex)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Lintegerp()
{
	enum type t;
	check_arg(1);

	t = type_of(vs_base[0]);
	if (t == t_fixnum || t == t_bignum)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Lrationalp()
{
	enum type t;
	check_arg(1);

	t = type_of(vs_base[0]);
	if (t == t_fixnum || t == t_bignum || t == t_ratio)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Lfloatp()
{
	enum type t;
	check_arg(1);

	t = type_of(vs_base[0]);
	if (t == t_longfloat || t == t_shortfloat)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Lcomplexp()
{
	check_arg(1);

	if (type_of(vs_base[0]) == t_complex)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Lcharacterp()
{
	check_arg(1);

	if (type_of(vs_base[0]) == t_character)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Lstringp()
{
	check_arg(1);

	if (type_of(vs_base[0]) == t_string)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Lbit_vector_p()
{
	check_arg(1);

	if (type_of(vs_base[0]) == t_bitvector)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Lvectorp()
{
	enum type t;
	check_arg(1);

	t = type_of(vs_base[0]);
	if (t == t_vector || t == t_string || t == t_bitvector)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Lsimple_string_p()
{
	check_arg(1);

	if (type_of(vs_base[0]) == t_string &&
	    !vs_base[0]->st.st_adjustable &&
	    !vs_base[0]->st.st_hasfillp &&
	    vs_base[0]->st.st_displaced->c.c_car == Cnil)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Lsimple_bit_vector_p()
{
	check_arg(1);

	if (type_of(vs_base[0]) == t_bitvector &&
	    !vs_base[0]->bv.bv_adjustable &&
	    !vs_base[0]->bv.bv_hasfillp &&
	    vs_base[0]->bv.bv_displaced->c.c_car == Cnil)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Lsimple_vector_p()
{
	enum type t;
	check_arg(1);

	t = type_of(vs_base[0]);
	if (t == t_vector &&
	    !vs_base[0]->v.v_adjustable &&
	    !vs_base[0]->v.v_hasfillp &&
	    vs_base[0]->v.v_displaced->c.c_car == Cnil &&
	    (enum aelttype)vs_base[0]->v.v_elttype == aet_object)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Larrayp()
{
	enum type t;
	check_arg(1);

	t = type_of(vs_base[0]);
	if (t == t_array ||
	    t == t_vector || t == t_string || t == t_bitvector)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Lpackagep()
{
	check_arg(1);

	if (type_of(vs_base[0]) == t_package)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Lfunctionp()
{
	enum type t;
	object x;

	check_arg(1);
	t = type_of(vs_base[0]);
	if (t == t_cfun || t == t_cclosure || t == t_sfun || t == t_gfun
	    || t == t_vfun)
		vs_base[0] = Ct;
	else if (t == t_symbol) {
		if (vs_base[0]->s.s_gfdef != OBJNULL &&
		    vs_base[0]->s.s_mflag == FALSE)
			vs_base[0] = Ct;
		else
			vs_base[0] = Cnil;
	} else if (t == t_cons) {
		x = vs_base[0]->c.c_car;
		if (x == Slambda || x == Slambda_block ||
		    x == siSlambda_block_expanded ||
		    x == Slambda_closure || x == Slambda_block_closure)
			vs_base[0] = Ct;
		else
			vs_base[0] = Cnil;
	} else
		vs_base[0] = Cnil;
}

Lcompiled_function_p()
{
	check_arg(1);

	if (type_of(vs_base[0]) == t_cfun ||
	    type_of(vs_base[0]) == t_cclosure  ||
	    type_of(vs_base[0]) == t_sfun   ||
	    type_of(vs_base[0]) == t_gfun ||
	    type_of(vs_base[0]) == t_vfun
	    
	    
	    )
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Lcommonp()
{
	check_arg(1);

	if (type_of(vs_base[0]) != t_spice)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Leq()
{
	check_arg(2);

	if (vs_base[0] == vs_base[1])
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
	vs_pop;
}

bool
eql(x, y)
object x, y;
{
	enum type t;

	if (x == y)
		return(TRUE);
	if ((t = type_of(x)) != type_of(y))
		return(FALSE);
	switch (t) {

	case t_fixnum:
		if (fix(x) == fix(y))
			return(TRUE);
		else
			return(FALSE);

	case t_bignum:
		if (big_compare((struct bignum *)x,
				(struct bignum *)y) == 0)
			return(TRUE);
		else
			return(FALSE);

	case t_ratio:
		if (eql(x->rat.rat_num, y->rat.rat_num) &&
		    eql(x->rat.rat_den, y->rat.rat_den))
			return(TRUE);
		else
			return(FALSE);

	case t_shortfloat:
		if (sf(x) == sf(y))
			return(TRUE);
		else
			return(FALSE);

	case t_longfloat:
		if (lf(x) == lf(y))
			return(TRUE);
		else
			return(FALSE);

	case t_complex:
		if (eql(x->cmp.cmp_real, y->cmp.cmp_real) &&
		    eql(x->cmp.cmp_imag, y->cmp.cmp_imag))
			return(TRUE);
		else
			return(FALSE);

	case t_character:
		if (char_code(x) == char_code(y) &&
		    char_bits(x) == char_bits(y) &&
		    char_font(x) == char_font(y))
			return(TRUE);
		else
			return(FALSE);
	}
	return(FALSE);
}

Leql()
{
	check_arg(2);

	if (eql(vs_base[0], vs_base[1]))
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
	vs_pop;
}

bool

equal(x, y)
register object x;
#ifdef UNIX   /* in non unix case cs_check want's an address */
register
#endif
object y;
{
register enum type t;

	cs_check(y);

BEGIN:
	if ((t = type_of(x)) != type_of(y))
		return(FALSE);
	if (x==y)
		return(TRUE);
	switch (t) {

	case t_cons:
		if (!equal(x->c.c_car, y->c.c_car))
			return(FALSE);
		x = x->c.c_cdr;
		y = y->c.c_cdr;
		goto BEGIN;

        case t_structure:
	case t_symbol: 
	case t_vector:
        case t_array:
		return FALSE;

	case t_fixnum :
	return(fix(x)==fix(y));
	case t_shortfloat:
	return(x->SF.SFVAL==y->SF.SFVAL);
	case t_longfloat:
	return(x->LF.LFVAL==y->LF.LFVAL);

 	case t_string:
		return(string_eq(x, y));

	case t_bitvector:
	{
		int i, ox, oy;

		if (x->bv.bv_fillp != y->bv.bv_fillp)
			return(FALSE);
		ox = x->bv.bv_offset;
		oy = y->bv.bv_offset;
		for (i = 0;  i < x->bv.bv_fillp;  i++)
			if((x->bv.bv_self[(i+ox)/8] & (0200>>(i+ox)%8))
			 !=(y->bv.bv_self[(i+oy)/8] & (0200>>(i+oy)%8)))
				return(FALSE);
		return(TRUE);
	}

	case t_pathname:
#ifdef UNIX
		if (equal(x->pn.pn_host, y->pn.pn_host) &&
		    equal(x->pn.pn_device, y->pn.pn_device) &&
		    equal(x->pn.pn_directory, y->pn.pn_directory) &&
		    equal(x->pn.pn_name, y->pn.pn_name) &&
		    equal(x->pn.pn_type, y->pn.pn_type) &&
		    equal(x->pn.pn_version, y->pn.pn_version))
#endif
			return(TRUE);
		else
			return(FALSE);

	}
	return(eql(x,y));
}

Lequal()
{
	check_arg(2);

	if (equal(vs_base[0], vs_base[1]))
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
	vs_pop;
}

bool
equalp(x, y)
object x, y;
{
	enum type tx, ty;
	int j;

	cs_check(x);

BEGIN:
	if (eql(x, y))
		return(TRUE);
	tx = type_of(x);
	ty = type_of(y);

	switch (tx) {
	case t_fixnum:
	case t_bignum:
	case t_ratio:
	case t_shortfloat:
	case t_longfloat:
	case t_complex:
		if (ty == t_fixnum || ty == t_bignum || ty == t_ratio ||
		    ty == t_shortfloat || ty == t_longfloat ||
		    ty == t_complex)
			return(!number_compare(x, y));
		else
			return(FALSE);

	case t_vector:
	case t_string:
	case t_bitvector:
		if (ty == t_vector || ty == t_string || ty == t_bitvector)
			{ j = x->v.v_fillp;
			  if (j != y->v.v_fillp)
			    return FALSE;
			  goto ARRAY;}
		else
			return(FALSE);

	case t_array:
		if (ty == t_array && x->a.a_rank == y->a.a_rank)
		  { if (x->a.a_rank > 1)
		     {int i=0;
		      for (i=0; i< x->a.a_rank; i++)
			{if (x->a.a_dims[i]!=y->a.a_dims[i])
			   return(FALSE);}}
		    if (x->a.a_dim != y->a.a_dim)
		      return(FALSE);
		    j=x->a.a_dim;
		    goto ARRAY;}
		else
			return(FALSE);
	}
	if (tx != ty)
		return(FALSE);
	switch (tx) {
	case t_character:
		return(char_equal(x, y));

	case t_cons:
		if (!equalp(x->c.c_car, y->c.c_car))
			return(FALSE);
		x = x->c.c_cdr;
		y = y->c.c_cdr;
		goto BEGIN;

	case t_structure:
		{
		int i;
		if (x->str.str_def != y->str.str_def)
			return(FALSE);
		{int leng= S_DATA(x->str.str_def)->length;
		 unsigned char *s_type= & SLOT_TYPE(x->str.str_def,0);
		 unsigned short *s_pos= & SLOT_POS(x->str.str_def,0);
		for (i = 0;  i < leng;  i++,s_pos++)
		 {if (s_type[i]==0)
		   {if (!equalp(STREF(object,x,*s_pos),STREF(object,y,*s_pos)))
		       return FALSE;}
		  else
		   if (! (*s_pos & (sizeof(object)-1)))
		    switch(s_type[i]){
		    case aet_lf:
		     if(STREF(longfloat,x,*s_pos) != STREF(longfloat,y,*s_pos))
			return(FALSE);
		      break;
		    case aet_sf:
		     if(STREF(shortfloat,x,*s_pos)!=STREF(shortfloat,y,*s_pos))
			return(FALSE);
		      break;
		    default:
		      if(STREF(int,x,*s_pos)!=STREF(int,y,*s_pos))
			return(FALSE);
		      break;}}
		return(TRUE);
	}}

	case t_pathname:
		return(equal(x, y));
	}
	return(FALSE);

ARRAY:

	{
		int i;

		vs_push(Cnil);
		vs_push(Cnil);
		for (i = 0;  i < j;  i++) {
			vs_top[-2] = aref(x, i);
			vs_top[-1] = aref(y, i);
			if (!equalp(vs_top[-2], vs_top[-1])) {
				vs_pop;
				vs_pop;
				return(FALSE);
			}
		}
		vs_pop;
		vs_pop;
		return(TRUE);
	}
}

Lequalp()
{
	check_arg(2);

	if (equalp(vs_base[0], vs_base[1]))
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
	vs_pop;
}

Fand(args)
object args;
{
	object *top = vs_top;

	if (endp(args)) {
		vs_base = vs_top;
		vs_push(Ct);
		return;
	}
	while (!endp(MMcdr(args))) {
		eval(MMcar(args));
		if (vs_base[0] == Cnil) {
			vs_base = vs_top = top;
			vs_push(Cnil);
			return;
		}
		vs_top = top;
		args = MMcdr(args);
	}
	eval(MMcar(args));
}

For(args)
object args;
{
	object *top = vs_top;

	if (endp(args)) {
		vs_base = vs_top;
		vs_push(Cnil);
		return;
	}
	while (!endp(MMcdr(args))) {
		eval(MMcar(args));
		if (vs_base[0] != Cnil) {
			top[0] = vs_base[0];
			vs_base = top;
			vs_top = top+1;
			return;
		}
		vs_top = top;
		args = MMcdr(args);
	}
	eval(MMcar(args));
}

/*
	Contains_sharp_comma returns TRUE, iff the argument contains
	a cons whose car is si:|#,| or a STRUCTURE.
	Refer to the compiler about this magic.
*/
bool
contains_sharp_comma(x)
object x;
{
	enum type tx;

	cs_check(x);

BEGIN:
	tx = type_of(x);
	if (tx == t_complex)
		return(contains_sharp_comma(x->cmp.cmp_real) ||
		       contains_sharp_comma(x->cmp.cmp_imag));
	if (tx == t_vector)
	{
		int i;
	   if (x->v.v_elttype == aet_object)
		for (i = 0;  i < x->v.v_fillp;  i++)
			if (contains_sharp_comma(x->v.v_self[i]))
				return(TRUE);
		return(FALSE);
	}
	if (tx == t_cons) {
		if (x->c.c_car == siSsharp_comma)
			return(TRUE);
		if (contains_sharp_comma(x->c.c_car))
			return(TRUE);
		x = x->c.c_cdr;
		goto BEGIN;
	}
	if (tx == t_array)
	{
		int i, j;
	   if (x->a.a_elttype == aet_object) {
		for (i = 0, j = 1;  i < x->a.a_rank;  i++)
			j *= x->a.a_dims[i];
		for (i = 0;  i < j;  i++)
			if (contains_sharp_comma(x->a.a_self[i]))
				return(TRUE);
	      }
		return(FALSE);
	}
	if (tx == t_structure)
		return(TRUE);		/*  Oh, my god!  */
	return(FALSE);
}

siLcontains_sharp_comma()
{
	check_arg(1);

	if (contains_sharp_comma(vs_base[0]))
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

siLspicep()
{
	check_arg(1);
	if (type_of(vs_base[0]) == t_spice)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

siLfixnump()
{
	check_arg(1);
	if (type_of(vs_base[0]) == t_fixnum)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

init_predicate_function()
{
	make_function("NULL", Lnull);
	make_function("SYMBOLP", Lsymbolp);
	make_function("ATOM", Latom);
	make_function("CONSP", Lconsp);
	make_function("LISTP", Llistp);
	make_function("NUMBERP", Lnumberp);
	make_function("INTEGERP", Lintegerp);
	make_function("RATIONALP", Lrationalp);
	make_function("FLOATP", Lfloatp);
	make_function("COMPLEXP", Lcomplexp);
	make_function("CHARACTERP", Lcharacterp);
	make_function("STRINGP", Lstringp);
	make_function("BIT-VECTOR-P", Lbit_vector_p);
	make_function("VECTORP", Lvectorp);
	make_function("SIMPLE-STRING-P", Lsimple_string_p);
	make_function("SIMPLE-BIT-VECTOR-P", Lsimple_bit_vector_p);
	make_function("SIMPLE-VECTOR-P", Lsimple_vector_p);
	make_function("ARRAYP", Larrayp);
	make_function("PACKAGEP", Lpackagep);
	make_function("FUNCTIONP", Lfunctionp);
	make_function("COMPILED-FUNCTION-P", Lcompiled_function_p);
	make_function("COMMONP", Lcommonp);

	make_function("EQ", Leq);
	make_function("EQL", Leql);
	make_function("EQUAL", Lequal);
	make_function("EQUALP", Lequalp);

	make_function("NOT", Lnull);
	make_special_form("AND",Fand);
	make_special_form("OR",For);

	make_si_function("CONTAINS-SHARP-COMMA", siLcontains_sharp_comma);

	make_si_function("FIXNUMP", siLfixnump);
	make_si_function("SPICEP", siLspicep);
}
