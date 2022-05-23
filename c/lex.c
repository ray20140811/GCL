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

	lex.c

	lexical environment
*/

#include "include.h"


object
assoc_eq(key, alist)
object key, alist;
{
	while (!endp(alist)) {
		if (MMcaar(alist) == key)
			return(MMcar(alist));
		alist = MMcdr(alist);
	}
	return(Cnil);
}

lex_fun_bind(name, fun)
object name, fun;
{
	object *top = vs_top;

	vs_push(make_cons(fun, Cnil));
	top[0] = make_cons(Sfunction, top[0]);
	top[0] = make_cons(name, top[0]);
	lex_env[1] = make_cons(top[0],lex_env[1]);
	vs_top = top;
}

lex_macro_bind(name, exp_fun)
object name, exp_fun;
{
	object *top = vs_top;
	vs_push(make_cons(exp_fun, Cnil));
	top[0] = make_cons(Smacro, top[0]);
	top[0] = make_cons(name, top[0]);
	lex_env[1]=make_cons(top[0], lex_env[1]);			  
	vs_top = top;
}

lex_tag_bind(tag, id)
object tag, id;
{
	object *top = vs_top;

	vs_push(make_cons(id, Cnil));
	top[0] = make_cons(Stag, top[0]);
	top[0] = make_cons(tag, top[0]);
	lex_env[2] =make_cons(top[0], lex_env[2]);
	vs_top = top;
}

lex_block_bind(name, id)
object name, id;
{
	object *top = vs_top;

	vs_push(make_cons(id, Cnil));
	top[0] = make_cons(Sblock, top[0]);
	top[0] = make_cons(name, top[0]);
	lex_env[2]= make_cons(top[0], lex_env[2]);
	vs_top = top;
}

object
lex_tag_sch(tag)
object tag;
{
	object alist = lex_env[2];

	while (!endp(alist)) {
		if (eql(MMcaar(alist), tag) && MMcadar(alist) == Stag)
			return(MMcar(alist));
		alist = MMcdr(alist);
	}
	return(Cnil);
}

object lex_block_sch(name)
object name;
{
	object alist = lex_env[2];

	while (!endp(alist)) {
		if (MMcaar(alist) == name && MMcadar(alist) == Sblock)
			return(MMcar(alist));
		alist = MMcdr(alist);
	}
	return(Cnil);
}

init_lex()
{
	Sfunction = make_ordinary("FUNCTION");
	enter_mark_origin(&Sfunction);
	Smacro = make_ordinary("MACRO");
	enter_mark_origin(&Smacro);
	Stag = make_ordinary("TAG");
	enter_mark_origin(&Stag);
	Sblock =  make_ordinary("BLOCK");
	enter_mark_origin(&Sblock);
}
