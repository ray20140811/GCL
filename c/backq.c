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

#include "include.h"

#define	attach(x)	(vs_head = make_cons(x, vs_head))
#define	make_list	(vs_push(Cnil), stack_cons(), stack_cons())


#define	QUOTE	1
#define	EVAL	2
#define	LIST	3
#define	LISTA	4
#define	APPEND	5
#define	NCONC	6

object siScomma;
object siScomma_at;
object siScomma_dot;


object SlistA;
object Sappend;
object Snconc;



kwote_cdr()
{
	object x;

	x = vs_head;
	if (type_of(x) == t_symbol) {
		if ((enum stype)x->s.s_stype == stp_constant &&
		    x->s.s_dbind == x)
			return;
		goto KWOTE;
	} else if (type_of(x) == t_cons || type_of(x) == t_vector)
		goto KWOTE;
	return;

KWOTE:
	vs_head = make_cons(vs_head, Cnil);
	vs_head = make_cons(Squote, vs_head);
}

kwote_car()
{
	object x;

	x = vs_top[-2];
	if (type_of(x) == t_symbol) {
		if ((enum stype)x->s.s_stype == stp_constant &&
		    x->s.s_dbind == x)
			return;
		goto KWOTE;
	} else if (type_of(x) == t_cons || type_of(x) == t_vector)
		goto KWOTE;
	return;

KWOTE:
	vs_top[-2] = make_cons(vs_top[-2], Cnil);
	vs_top[-2] = make_cons(Squote, vs_top[-2]);
}

/*
	Backq_cdr(x) pushes a form on vs and returns one of

		QUOTE		the form should be quoted
		EVAL		the form should be evaluated
		LIST		the form should be applied to LIST
		LISTA		the form should be applied to LIST*
		APPEND		the form should be applied to APPEND
		NCONC		the form should be applied to NCONC
*/
int
backq_cdr(x)
object x;
{
	int a, d;

	cs_check(x);

	if (type_of(x) != t_cons) {
		vs_push(x);
		return(QUOTE);
	}
	if (x->c.c_car == siScomma) {
		vs_push(x->c.c_cdr);
		return(EVAL);
	}
	if (x->c.c_car == siScomma_at || x->c.c_car == siScomma_dot)
		FEerror(",@ or ,. has appeared in an illegal position.", 0);
	a = backq_car(x->c.c_car);
	d = backq_cdr(x->c.c_cdr);
	if (d == QUOTE)
		switch (a) {
		case QUOTE:
			vs_pop;
			vs_head = x;
			return(QUOTE);

		case EVAL:
			if (vs_head == Cnil) {
				stack_cons();
				return(LIST);
			}
			if (type_of(vs_head) == t_cons &&
			    vs_head->c.c_cdr == Cnil) {
				vs_head = vs_head->c.c_car;
				kwote_cdr();
				make_list;
				return(LIST);
			}
			kwote_cdr();
			make_list;
			return(LISTA);

		case APPEND:
			if (vs_head == Cnil) {
				vs_pop;
				return(EVAL);
			}
			kwote_cdr();
			make_list;
			return(APPEND);

		case NCONC:
			if (vs_head == Cnil) {
				vs_pop;
				return(EVAL);
			}
			kwote_cdr();
			make_list;
			return(NCONC);

		default:
			error("backquote botch");
		}
	if (d == EVAL)
		switch (a) {
		case QUOTE:
			kwote_car();
			make_list;
			return(LISTA);

		case EVAL:
			make_list;
			return(LISTA);

		case APPEND:
			make_list;
			return(APPEND);

		case NCONC:
			make_list;
			return(NCONC);

		default:
			error("backquote botch");
		}
	if (a == d) {
		stack_cons();
		return(d);
	}
	switch (d) {
	case LIST:
		if (a == QUOTE) {
			kwote_car();
			stack_cons();
			return(d);
		}
		if (a == EVAL) {
			stack_cons();
			return(d);
		}
		attach(Slist);
		break;

	case LISTA:
		if (a == QUOTE) {
			kwote_car();
			stack_cons();
			return(d);
		}
		if (a == EVAL) {
			stack_cons();
			return(d);
		}
		attach(SlistA);
		break;

	case APPEND:
		attach(Sappend);
		break;

	case NCONC:
		attach(Snconc);
		break;

	default:
		error("backquote botch");
	}
	switch (a) {
	case QUOTE:
		kwote_car();
		make_list;
		return(LISTA);

	case EVAL:
		make_list;
		return(LISTA);

	case APPEND:
		make_list;
		return(APPEND);

	case NCONC:
		make_list;
		return(NCONC);

	default:
		error("backquote botch");
	}
}

/*
	Backq_car(x) pushes a form on vs and returns one of

		QUOTE		the form should be quoted
		EVAL		the form should be evaluated
		APPEND		the form should be appended
				into the outer form
		NCONC		the form should be nconc'ed
				into the outer form
*/
int
backq_car(x)
object x;
{
	int d;

	cs_check(x);

	if (type_of(x) != t_cons) {
		vs_push(x);
		return(QUOTE);
	}
	if (x->c.c_car == siScomma) {
		vs_push(x->c.c_cdr);
		return(EVAL);
	}
	if (x->c.c_car == siScomma_at) {
		vs_push(x->c.c_cdr);
		return(APPEND);
	}
	if (x->c.c_car == siScomma_dot) {
		vs_push(x->c.c_cdr);
		return(NCONC);
	}
	d = backq_cdr(x);
	switch (d) {
	case QUOTE:
		return(QUOTE);

	case EVAL:
		return(EVAL);

	case LIST:
		attach(Slist);
		break;

	case LISTA:
		attach(SlistA);
		break;

	case APPEND:
		attach(Sappend);
		break;

	case NCONC:
		attach(Snconc);
		break;

	default:
		error("backquote botch");
        }
	return(EVAL);
}

object
backq(x)
object x;
{
	int a;

	a = backq_car(x);
	if (a == APPEND || a == NCONC)
		FEerror(",@ or ,. has appeared in an illegal position.", 0);
	if (a == QUOTE)
		kwote_cdr();
	return(vs_pop);
}

Lcomma_reader()
{
	object in, c;

	check_arg(2);
	vs_pop;
	in = vs_base[0];
	if (backq_level <= 0)
		FEerror("A comma has appeared out of a backquote.", 0);
	c = peek_char(FALSE, in);
	if (c == code_char('@')) {
		vs_push(siScomma_at);
		read_char(in);
	} else if (c == code_char('.')) {
		vs_push(siScomma_dot);
		read_char(in);
	} else
		vs_push(siScomma);
	--backq_level;
	vs_push(read_object(in));
	backq_level++;
	stack_cons();
	vs_base[0] = vs_base[1];
	vs_pop;
}

Lbackquote_reader()
{
	object in;

	check_arg(2);
	vs_pop;
	in = vs_base[0];
	backq_level++;
	vs_base[0] = read_object(in);
	--backq_level;
	vs_base[0] = backq(vs_base[0]);
}

#define	make_cf(f)	make_cfun((f), Cnil, Cnil, NULL, 0);

init_backq()
{
	object r;

	siScomma = make_si_ordinary(",");
	enter_mark_origin(&siScomma);
	siScomma_at = make_si_ordinary(",@");
	enter_mark_origin(&siScomma_at);
	siScomma_dot = make_si_ordinary(",.");
	enter_mark_origin(&siScomma_dot);

	Slist = make_ordinary("LIST");
	enter_mark_origin(&Slist);
	SlistA = make_ordinary("LIST*");
	enter_mark_origin(&SlistA);
	Sappend = make_ordinary("APPEND");
	enter_mark_origin(&Sappend);
	Snconc = make_ordinary("NCONC");
	enter_mark_origin(&Snconc);

	Sapply = make_ordinary("APPLY");
	enter_mark_origin(&Sapply);
	Svector = make_ordinary("VECTOR");
	enter_mark_origin(&Svector);

	r = standard_readtable;
	r->rt.rt_self['`'].rte_chattrib = cat_terminating;
	r->rt.rt_self['`'].rte_macro = make_cf(Lbackquote_reader);
	r->rt.rt_self[','].rte_chattrib = cat_terminating;
	r->rt.rt_self[','].rte_macro = make_cf(Lcomma_reader);

	backq_level = 0;
}
