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
	typespec.c

	type specifier routines
*/

#include "include.h"
#include "mp.h"

object Sfat_string;

object Skeyword;


check_type_integer(p)
object *p;
{
	enum type t;

	while ((t = type_of(*p)) != t_fixnum && t != t_bignum)
		*p = wrong_type_argument(Sinteger, *p);
}

check_type_non_negative_integer(p)
object *p;
{
	enum type t;

	for (;;) {
		t = type_of(*p);
		if (t == t_fixnum) {
			if (fix((*p)) >= 0)
				break;
		} else if (t == t_bignum) {
			if (big_sign((*p)) >= 0)
				break;
		}
		*p = wrong_type_argument(TSnon_negative_integer, *p);
	}
}

check_type_rational(p)
object *p;
{
	enum type t;

	while ((t = type_of(*p)) != t_fixnum &&
	       t != t_bignum && t != t_ratio)
		*p = wrong_type_argument(Srational, *p);
}

check_type_float(p)
object *p;
{
	enum type t;

	while ((t = type_of(*p)) != t_shortfloat && t != t_longfloat)
		*p = wrong_type_argument(Sfloat, *p);
}

check_type_or_integer_float(p)
object *p;
{
	enum type t;

	while ((t = type_of(*p)) != t_fixnum && t != t_bignum &&
	       t != t_shortfloat && t != t_longfloat)
		*p = wrong_type_argument(TSor_integer_float, *p);
}

check_type_or_rational_float(p)
object *p;
{
	enum type t;

	while ((t = type_of(*p)) != t_fixnum && t != t_bignum &&
	       t != t_ratio && t != t_shortfloat && t != t_longfloat)
		*p = wrong_type_argument(TSor_rational_float, *p);
}

check_type_number(p)
object *p;
{
	enum type t;

	while ((t = type_of(*p)) != t_fixnum && t != t_bignum &&
	       t != t_ratio && t != t_shortfloat && t != t_longfloat &&
	       t != t_complex)
		*p = wrong_type_argument(Snumber, *p);
}

check_type_bit(p)
object *p;
{
	while (type_of(*p) != t_fixnum ||
	       fix((*p)) != 0 && fix((*p)) != 1)
		*p = wrong_type_argument(Sbit, *p);
}

check_type_character(p)
object *p;
{
	while (type_of(*p) != t_character)
		*p = wrong_type_argument(Scharacter, *p);
}

check_type_string_char(p)
object *p;
{
	while (type_of(*p) != t_character ||
	       char_font((*p)) != 0 ||
	       char_bits((*p)) != 0)
		*p = wrong_type_argument(Scharacter, *p);
}

check_type_symbol(p)
object *p;
{
	while (type_of(*p) != t_symbol)
		*p = wrong_type_argument(Ssymbol, *p);
}

check_type_or_symbol_string(p)
object *p;
{
	while (type_of(*p) != t_symbol && type_of(*p) != t_string)
		*p = wrong_type_argument(TSor_symbol_string, *p);
}

check_type_or_string_symbol(p)
object *p;
{
	while (type_of(*p) != t_symbol && type_of(*p) != t_string)
		*p = wrong_type_argument(TSor_string_symbol, *p);
}

check_type_or_symbol_string_package(p)
object *p;
{
	while (type_of(*p) != t_symbol &&
	       type_of(*p) != t_string &&
	       type_of(*p) != t_package)
		*p = wrong_type_argument(TSor_symbol_string_package,
 					   *p);
}

check_type_package(p)
object *p;
{
	while (type_of(*p) != t_package)
		*p = wrong_type_argument(Spackage, *p);
}

check_type_string(p)
object *p;
{
	while (type_of(*p) != t_string)
		*p = wrong_type_argument(Sstring, *p);
}

check_type_bit_vector(p)
object *p;
{
	while (type_of(*p) != t_bitvector)
		*p = wrong_type_argument(Sbit_vector, *p);
}

check_type_cons(p)
object *p;
{
	while (type_of(*p) != t_cons)
		*p = wrong_type_argument(Scons, *p);
}

check_type_stream(p)
object *p;
{
	while (type_of(*p) != t_stream)
		*p = wrong_type_argument(Sstream, *p);
}

check_type_readtable(p)
object *p;
{
	while (type_of(*p) != t_readtable)
		*p = wrong_type_argument(Sreadtable, *p);
}

#ifdef UNIX
check_type_or_Pathname_string_symbol(p)
object *p;
{
	enum type t;

	while ((t = type_of(*p)) != t_pathname &&
	       t != t_string && t != t_symbol)
		*p = wrong_type_argument(
			TSor_pathname_string_symbol, *p);
}
#endif

check_type_or_pathname_string_symbol_stream(p)
object *p;
{
	enum type t;

	while ((t = type_of(*p)) != t_pathname &&
	       t != t_string && t != t_symbol && t != t_stream)
		*p = wrong_type_argument(
			TSor_pathname_string_symbol_stream, *p);
}

check_type_random_state(p)
object *p;
{
	while (type_of(*p) != t_random)
		*p = wrong_type_argument(Srandom_state, *p);
}

check_type_hash_table(p)
object *p;
{
	while (type_of(*p) != t_hashtable)
		*p = wrong_type_argument(Shash_table, *p);
}

check_type_array(p)
object *p;
{
BEGIN:
	switch (type_of(*p)) {
	case t_array:
	case t_vector:
	case t_string:
	case t_bitvector:
		return;

	default:
		*p = wrong_type_argument(Sarray, *p);
		goto BEGIN;
	}
}

check_type_vector(p)
object *p;
{
BEGIN:
	switch (type_of(*p)) {
	case t_vector:
	case t_string:
	case t_bitvector:
		return;

	default:
		*p = wrong_type_argument(Svector, *p);
		goto BEGIN;
	}
}

void
check_type(x,t)
     object x;
     int t;
{if (type_of(x) !=t)
   FEerror("~s is not a ~a",2,
	   x,make_simple_string(tm_table[t].tm_name +1));
}
   


Ltype_of()
{
	int i;

	check_arg(1);

	switch (type_of(vs_base[0])) {
	case t_fixnum:
		vs_base[0] = Sfixnum;
		break;
	      case t_fat_string:
		vs_base[0] = Sfat_string;
		break;
	case t_bignum:
		vs_base[0] = Sbignum;
		break;

	case t_ratio:
		vs_base[0] = Sratio;
		break;

	case t_shortfloat:
		vs_base[0] = Sshort_float;
		break;

	case t_longfloat:
		vs_base[0] = Slong_float;
		break;

	case t_complex:
		vs_base[0] = Scomplex;
		break;

	case t_character:
		if (char_font(vs_base[0]) != 0
		 || char_bits(vs_base[0]) != 0)
			vs_base[0] = Scharacter;
		else {
			i = char_code(vs_base[0]);
			if (' ' <= i && i < '\177' || i == '\n')
				vs_base[0] = Sstandard_char;
			else
				vs_base[0] = Sstring_char;
		}
		break;

	case t_symbol:
		if (vs_base[0]->s.s_hpack == keyword_package)
			vs_base[0] = Skeyword;
		else
			vs_base[0] = Ssymbol;
		break;

	case t_package:
		vs_base[0] = Spackage;
		break;

	case t_cons:
		vs_base[0] = Scons;
		break;

	case t_hashtable:
		vs_base[0] = Shash_table;
		break;

	case t_array:
		if (vs_base[0]->a.a_adjustable ||
		    vs_base[0]->a.a_displaced->c.c_car == Cnil)
			vs_base[0] = Sarray;
		else
			vs_base[0] = Ssimple_array;
		break;

	case t_vector:
		if (vs_base[0]->v.v_adjustable ||
		    vs_base[0]->v.v_hasfillp ||
		    vs_base[0]->v.v_displaced->c.c_car == Cnil ||
		    (enum aelttype)vs_base[0]->v.v_elttype != aet_object)
			vs_base[0] = Svector;
		else
			vs_base[0] = Ssimple_vector;
		break;

	case t_string:
		if (vs_base[0]->st.st_adjustable ||
		    vs_base[0]->st.st_hasfillp ||
		    vs_base[0]->st.st_displaced->c.c_car == Cnil)
			vs_base[0] = Sstring;
		else
			vs_base[0] = Ssimple_string;
		break;

	case t_bitvector:
		if (vs_base[0]->bv.bv_adjustable ||
		    vs_base[0]->bv.bv_hasfillp ||
		    vs_base[0]->bv.bv_displaced->c.c_car == Cnil)
			vs_base[0] = Sbit_vector;
		else
			vs_base[0] = Ssimple_bit_vector;
		break;

	case t_structure:
		
		vs_base[0] = S_DATA(vs_base[0]->str.str_def)->name;
		break;

	case t_stream:
#ifdef USER_DEFINED_STREAMS
		if (vs_base[0]->sm.sm_mode == (int)smm_user_defined)
		   vs_base[0]= vs_base[0]->sm.sm_object1->str.str_self[8];
		else
#endif
		vs_base[0] = Sstream;
		break;

	case t_readtable:
		vs_base[0] = Sreadtable;
		break;

	case t_pathname:
		vs_base[0] = Spathname;
		break;

	case t_random:
		vs_base[0] = Srandom_state;
		break;

	case t_sfun:
	case t_gfun:	
	case t_cfun:
        case t_vfun:
	case t_cclosure:
        case t_dclosure:
		vs_base[0] = Scompiled_function;
		break;

	default:
		error("not a lisp data object");
	}
}

init_typespec()
{
	St = make_ordinary("T");
	enter_mark_origin(&St);
	Snil = make_ordinary("NIL");
	enter_mark_origin(&Snil);
	Scommon = make_ordinary("COMMON");
	enter_mark_origin(&Scommon);
	Snull = make_ordinary("NULL");
	enter_mark_origin(&Snull);
	Scons = make_ordinary("CONS");
	enter_mark_origin(&Scons);
	Slist = make_ordinary("LIST");
	enter_mark_origin(&Slist);
	Ssymbol = make_ordinary("SYMBOL");
	enter_mark_origin(&Ssymbol);
	Sarray = make_ordinary("ARRAY");
	enter_mark_origin(&Sarray);
	Svector = make_ordinary("VECTOR");
	enter_mark_origin(&Svector);
	Sbit_vector = make_ordinary("BIT-VECTOR");
	enter_mark_origin(&Sbit_vector);
	Sstring = make_ordinary("STRING");
	enter_mark_origin(&Sstring);
	Ssequence = make_ordinary("SEQUENCE");
	enter_mark_origin(&Ssequence);
	Ssimple_array = make_ordinary("SIMPLE-ARRAY");
	enter_mark_origin(&Ssimple_array);
	Ssimple_vector = make_ordinary("SIMPLE-VECTOR");
	enter_mark_origin(&Ssimple_vector);
	Ssimple_bit_vector = make_ordinary("SIMPLE-BIT-VECTOR");
	enter_mark_origin(&Ssimple_bit_vector);
	Ssimple_string = make_ordinary("SIMPLE-STRING");
	enter_mark_origin(&Ssimple_string);
	Sfunction = make_ordinary("FUNCTION");
	enter_mark_origin(&Sfunction);
	Scompiled_function = make_ordinary("COMPILED-FUNCTION");
	enter_mark_origin(&Scompiled_function);
	Spathname = make_ordinary("PATHNAME");
	enter_mark_origin(&Spathname);
	Scharacter = make_ordinary("CHARACTER");
	enter_mark_origin(&Scharacter);
	Snumber = make_ordinary("NUMBER");
	enter_mark_origin(&Snumber);
	Srational = make_ordinary("RATIONAL");
	enter_mark_origin(&Srational);
	Sfloat = make_ordinary("FLOAT");
	enter_mark_origin(&Sfloat);
	Sstring_char = make_ordinary("STRING-CHAR");
	enter_mark_origin(&Sstring_char);
	Sinteger = make_ordinary("INTEGER");
	enter_mark_origin(&Sinteger);
	Sratio = make_ordinary("RATIO");
	enter_mark_origin(&Sratio);
	Sshort_float = make_ordinary("SHORT-FLOAT");
	enter_mark_origin(&Sshort_float);
	Sstandard_char = make_ordinary("STANDARD-CHAR");
	enter_mark_origin(&Sstandard_char);
	Sfixnum = make_ordinary("FIXNUM");
	enter_mark_origin(&Sfixnum);
	Scomplex = make_ordinary("COMPLEX");
	enter_mark_origin(&Scomplex);
	Ssingle_float = make_ordinary("SINGLE-FLOAT");
	enter_mark_origin(&Ssingle_float);
	Spackage = make_ordinary("PACKAGE");
	enter_mark_origin(&Spackage);
	Sbignum = make_ordinary("BIGNUM");
	enter_mark_origin(&Sbignum);
	Srandom_state = make_ordinary("RANDOM-STATE");
	enter_mark_origin(&Srandom_state);
	Sdouble_float = make_ordinary("DOUBLE-FLOAT");
	enter_mark_origin(&Sdouble_float);
	Sstream = make_ordinary("STREAM");
	enter_mark_origin(&Sstream);
	Sbit = make_ordinary("BIT");
	enter_mark_origin(&Sbit);
	Sreadtable = make_ordinary("READTABLE");
	enter_mark_origin(&Sreadtable);
	Slong_float = make_ordinary("LONG-FLOAT");
	enter_mark_origin(&Slong_float);
	Shash_table = make_ordinary("HASH-TABLE");
	enter_mark_origin(&Shash_table);
	
	Skeyword = make_ordinary("KEYWORD");
	enter_mark_origin(&Skeyword);

	Sstructure = make_ordinary("STRUCTURE");
	enter_mark_origin(&Sstructure);

	Ssatisfies = make_ordinary("SATISFIES");
	enter_mark_origin(&Ssatisfies);
	
	Smember = make_ordinary("MEMBER");
	enter_mark_origin(&Smember);
	Snot = make_ordinary("NOT");
	enter_mark_origin(&Snot);
	Sor = make_ordinary("OR");
	enter_mark_origin(&Sor);
	Sand = make_ordinary("AND");
	enter_mark_origin(&Sand);
	
	Svalues = make_ordinary("VALUES");
	enter_mark_origin(&Svalues);
	
	Smod = make_ordinary("MOD");
	enter_mark_origin(&Smod);
	Ssigned_byte = make_ordinary("SIGNED-BYTE");
	enter_mark_origin(&Ssigned_byte);
	Sunsigned_byte = make_ordinary("UNSIGNED-BYTE");
	enter_mark_origin(&Sunsigned_byte);
	Ssigned_char = make_ordinary("SIGNED-CHAR");
	enter_mark_origin(&Ssigned_char);
	Sunsigned_char = make_ordinary("UNSIGNED-CHAR");
	enter_mark_origin(&Sunsigned_char);
	Ssigned_short = make_ordinary("SIGNED-SHORT");
	enter_mark_origin(&Ssigned_short);
	Sunsigned_short = make_ordinary("UNSIGNED-SHORT");
	enter_mark_origin(&Sunsigned_short);
	Sfat_string = make_ordinary("FAT-STRING");
	enter_mark_origin(&Sfat_string);
	
	SA = make_ordinary("*");
	enter_mark_origin(&SA);
	Splusp = make_ordinary("PLUSP");
	enter_mark_origin(&Splusp);
}

init_typespec_function()
{
	TSor_symbol_string
	= make_cons(Sor, make_cons(Ssymbol, make_cons(Sstring, Cnil)));
	enter_mark_origin(&TSor_symbol_string);
	TSor_string_symbol
	= make_cons(Sor, make_cons(Sstring, make_cons(Ssymbol, Cnil)));
	enter_mark_origin(&TSor_string_symbol);
	TSor_symbol_string_package
	= make_cons(Sor,
		    make_cons(Ssymbol,
			      make_cons(Sstring,
					make_cons(Spackage, Cnil))));
	enter_mark_origin(&TSor_symbol_string_package);

	TSnon_negative_integer
	= make_cons(Sinteger,
		    make_cons(make_fixnum(0), make_cons(SA, Cnil)));
	enter_mark_origin(&TSnon_negative_integer);
	TSpositive_number = make_cons(Ssatisfies, make_cons(Splusp, Cnil));
	enter_mark_origin(&TSpositive_number);
	TSor_integer_float
	= make_cons(Sor, make_cons(Sinteger, make_cons(Sfloat, Cnil)));
	enter_mark_origin(&TSor_integer_float);
	TSor_rational_float
	= make_cons(Sor, make_cons(Srational, make_cons(Sfloat, Cnil)));
	enter_mark_origin(&TSor_rational_float);
#ifdef UNIX
	TSor_pathname_string_symbol
	= make_cons(Sor,
		    make_cons(Spathname,
			      make_cons(Sstring,
					make_cons(Ssymbol,
						  Cnil))));
	enter_mark_origin(&TSor_pathname_string_symbol);
#endif
	TSor_pathname_string_symbol_stream
	= make_cons(Sor,
		    make_cons(Spathname,
			      make_cons(Sstring,
					make_cons(Ssymbol,
						  make_cons(Sstream,
							    Cnil)))));
	enter_mark_origin(&TSor_pathname_string_symbol_stream);

	make_function("TYPE-OF", Ltype_of);
}				
