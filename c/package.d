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
	package.d
*/

#include "include.h"

#define	HASHCOEF	12345		/*  hashing coefficient  */

int check_type_or_symbol_string_package();

#define	INTERNAL	1
#define	EXTERNAL	2
#define	INHERITED	3

#define P_INTERNAL(x,j) ((x)->p.p_internal[(j) % (x)->p.p_internal_size])
#define P_EXTERNAL(x,j) ((x)->p.p_external[(j) % (x)->p.p_external_size])




bool
member_string_equal(x, l)
object x, l;
{
	for (;  type_of(l) == t_cons;  l = l->c.c_cdr)
		if (string_equal(x, l->c.c_car))
			return(TRUE);
	return(FALSE);
}

rehash_pack(ptab,n,m)
     object **ptab;
     int *n,m;
{ object *ntab;
  object *tab = *ptab;
  object l,ll;
  int k,i;
  i=0;
  k = *n;

  ntab= AR_ALLOC(alloc_contblock,m,object);
  *ptab = ntab;
  *n=m;
  while(i<m) ntab[i++]=Cnil;
   for(i=0 ; i< k; i++)
   	for (l = tab[i];  type_of(l) == t_cons;)
	  {int j =pack_hash(l->c.c_car)%m;
	   ll=l->c.c_cdr;
	   l->c.c_cdr = ntab[j];
	   ntab[j]=l;
	   l=ll;
	 }}

/* some prime numbers suitable for package sizes */

static int package_sizes[]={
  97,251, 509, 1021, 2039, 4093, 8191, 16381,
  32749, 65521, 131071, 262139,   524287, 1048573};

suitable_package_size(n)
{int *i=package_sizes;
 if (n>= 1000000) return 1048573;
 while(*i < n) { i++;}
 return *i;}
   
/*
	Make_package(n, ns, ul, isize , esize) makes a package with name n,
	which must be a string or a symbol,
	and nicknames ns, which must be a list of strings or symbols,
	and uses packages in list ul, which must be a list of packages
	or package names i.e. strings or symbols.
*/
object
make_package(n, ns, ul,isize,esize)
object n, ns, ul;
int isize,esize;
{
	object x, y;
	int i;
	vs_mark;

	if (type_of(n) == t_symbol) {
		vs_push(alloc_simple_string(n->s.s_fillp));
		vs_head->st.st_self = n->s.s_self;
		n = vs_head;
	}
	if (find_package(n) != Cnil)
		package_already(n);
	x = alloc_object(t_package);
	x->p.p_name = n;
	x->p.p_nicknames = Cnil;
	x->p.p_shadowings = Cnil;
	x->p.p_uselist = Cnil;
	x->p.p_usedbylist = Cnil;
	x->p.p_internal = NULL;
	x->p.p_external = NULL;
	x->p.p_internal_size = (isize ? isize : suitable_package_size(200));
	x->p.p_external_size = (esize ? esize : suitable_package_size(60));
	x->p.p_internal_fp =0;   
	x->p.p_external_fp =0;
	
	vs_push(x);
	for (;  !endp(ns);  ns = ns->c.c_cdr) {
		n = ns->c.c_car;
		if (type_of(n) == t_symbol) {
			vs_push(alloc_simple_string(n->s.s_fillp));
			vs_head->st.st_self = n->s.s_self;
			n = vs_head;
		}
		if (find_package(n) != Cnil) {
			vs_reset;
			package_already(n);
		}
		x->p.p_nicknames = make_cons(n, x->p.p_nicknames);
	}
	for (;  !endp(ul);  ul = ul->c.c_cdr) {
		if (type_of(ul->c.c_car) == t_package)
			y = ul->c.c_car;
		else {
			y = find_package(ul->c.c_car);
			if (y == Cnil)
				no_package(ul->c.c_car);
		}
		x->p.p_uselist = make_cons(y, x->p.p_uselist);
		y->p.p_usedbylist = make_cons(x, y->p.p_usedbylist);
	}
	x->p.p_internal
	= AR_ALLOC(alloc_contblock,x->p.p_internal_size,object);
	for (i = 0;  i < x->p.p_internal_size;  i++)
		x->p.p_internal[i] = Cnil;
	x->p.p_external
	= AR_ALLOC(alloc_contblock,x->p.p_external_size,object);
	for (i = 0;  i < x->p.p_external_size;  i++)
		x->p.p_external[i] = Cnil;
	x->p.p_link = pack_pointer;
	pack_pointer = &(x->p);
	vs_reset;
	return(x);
}

object
in_package(n, ns, ul,isize,esize)
object n, ns, ul;
int isize,esize;
{
	object x, y;
	int i;
	vs_mark;

	x = find_package(n);
	if (x == Cnil) {
		x = make_package(n, ns, ul,isize,esize);
		goto L;
	}
	if (isize) rehash_pack(&(x->p.p_internal),
		&x->p.p_internal_size,isize);
	for (;  !endp(ns);  ns = ns->c.c_cdr) {
		n = ns->c.c_car;
		if (type_of(n) == t_symbol) {
			vs_push(alloc_simple_string(n->s.s_fillp));
			vs_head->st.st_self = n->s.s_self;
			n = vs_head;
		}
		y = find_package(n);
		if (x == y)
			continue;
		if (y != Cnil)
			package_already(n);
		x->p.p_nicknames = make_cons(n, x->p.p_nicknames);
	}
	for (;  !endp(ul);  ul = ul->c.c_cdr)
		use_package(ul->c.c_car, x);
L:
	Vpackage->s.s_dbind = x;
	vs_reset;
	return(x);
}

object
rename_package(x, n, ns)
object x, n, ns;
{
	object y;
	vs_mark;

	if (type_of(n) == t_symbol) {
		vs_push(alloc_simple_string(n->s.s_fillp));
		vs_head->st.st_self = n->s.s_self;
		n = vs_head;
	}
   	if (!(equal(x->p.p_name,n)) &&
	    find_package(n) != Cnil)
		package_already(n);
	x->p.p_name = n;
	x->p.p_nicknames = Cnil;
	for (;  !endp(ns);  ns = ns->c.c_cdr) {
		n = ns->c.c_car;
		if (type_of(n) == t_symbol) {
			vs_push(alloc_simple_string(n->s.s_fillp));
			vs_head->st.st_self = n->s.s_self;
			n = vs_head;
		}
		y = find_package(n);
		if (x == y)
			continue;
		if (y != Cnil)
			package_already(n);
		x->p.p_nicknames = make_cons(n, x->p.p_nicknames);
	}
	vs_reset;
	return(x);
}

/*
	Find_package(n) seaches for a package with name n,
	which is a string or a symbol.
	If not so, an error is signaled.
*/
object
find_package(n)
object n;
{
	struct package *p;

	if (type_of(n) == t_symbol)
		;
	else if (type_of(n) != t_string)
		FEwrong_type_argument(TSor_string_symbol, n);
	for (p = pack_pointer;  p != NULL;  p = p->p_link) {
		if (string_equal(p->p_name, n))
			return((object)p);
		if (member_string_equal(n, p->p_nicknames))
			return((object)p);
	}
	return(Cnil);
}

object
coerce_to_package(p)
object p;
{
	object pp;

	if (type_of(p) == t_package)
		return(p);
	pp = find_package(p);
	if (pp == Cnil)
		no_package(p);
	return(pp);
}

object
current_package()
{
	object x;

	x = symbol_value(Vpackage);
	if (type_of(x) != t_package) {
		Vpackage->s.s_dbind = user_package;
		FEerror("The value of *PACKAGE*, ~S, was not a package.",
			1, x);
	}
	return(x);
}

/*
	Pack_hash(st) hashes string st
	and returns the index for a hash table of a package.
*/

int
pack_hash(x)
object x;
{unsigned int h=0;
 {int len=x->st.st_fillp;
  char *s;
#define HADD(i,j,k,l) (h+=s[i],h+=s[j]<<8,h+=s[k]<<13,h+=s[l]<<23)
#define HADD2(i,j) (h+=s[i]<<5,h+=s[j]<<15)
  s=x->st.st_self;
  switch(len) {
  case 0: break;
  case 10: 
  case 9: HADD(1,4,6,8); HADD2(5,7); goto END;
  case 8: HADD(1,3,5,7); HADD2(2,4); goto END;
  case 7: HADD(1,3,4,5); HADD2(6,2); goto END;
  case 6: HADD(1,3,4,5); HADD2(0,2); goto END;
  case 5: h+= s[4] << 13;
  case 4: h+= s[3] << 24;
  case 3: h+= s[2]<< 16;
  case 2: h+= s[1] << 8;
  case 1: h+= s[0] ;
    break;
  default:
    HADD(3,6,len-2,len-4); HADD2(1,len-1);
    if (len > 15) {HADD2(7,10);		   
		 }
  }
 END:
  h &= 0x7fffffff; 
  return(h);
}}



/*
	Intern(st, p) interns string st in package p.
*/
object
intern(st, p)
object st, p;
{
	int j;
	object x, *ip, *ep, l, ul;
	vs_mark;

	j = pack_hash(st);
	ip = &P_INTERNAL(p ,j);
#define string_eq(a,b) \
   ((a)->st.st_fillp==(b)->st.st_fillp && \
	 bcmp((a)->st.st_self,(b)->st.st_self,(a)->st.st_fillp)==0)

	for (l = *ip;  type_of(l) == t_cons;  l = l->c.c_cdr)
		if (string_eq(l->c.c_car, st)) {
			intern_flag = INTERNAL;
			return(l->c.c_car);
		}
	ep = &P_EXTERNAL(p,j);
	for (l = *ep;  type_of(l) == t_cons;  l = l->c.c_cdr)
		if (string_eq(l->c.c_car, st)) {
			intern_flag = EXTERNAL;
			return(l->c.c_car);
		}
	for (ul=p->p.p_uselist; type_of(ul)==t_cons; ul=ul->c.c_cdr)
		for (l = P_EXTERNAL(ul->c.c_car,j);
		     type_of(l) == t_cons;
		     l = l->c.c_cdr)
			if (string_eq(l->c.c_car, st)) {
				intern_flag = INHERITED;
				return(l->c.c_car);
			}
	x = make_symbol(st);
	vs_push(x);
	if (p == keyword_package) {
		x->s.s_stype = (short)stp_constant;
		x->s.s_dbind = x;
		*ep = make_cons(x, *ep);
		keyword_package->p.p_external_fp ++;
		intern_flag = 0;
	} else {
		*ip = make_cons(x, *ip);
		if (p->p.p_internal_fp++>(p->p.p_internal_size << 1))
			rehash_pack(&(p->p.p_internal),&p->p.p_internal_size,
				    suitable_package_size(p->p.p_internal_fp));
		intern_flag = 0;
	}
	if (x->s.s_hpack == Cnil)
		x->s.s_hpack = p;
	vs_reset;
	return(x);
}

/*
	Find_symbol(st, p) searches for string st in package p.
*/
object
find_symbol(st, p)
object st, p;
{
	int j;
	object *ip, *ep, l, ul;

	j = pack_hash(st);
	ip = &P_INTERNAL(p ,j);
	for (l = *ip;  type_of(l) == t_cons;  l = l->c.c_cdr)
		if (string_eq(l->c.c_car, st)) {
			intern_flag = INTERNAL;
			return(l->c.c_car);
		}
	ep = &P_EXTERNAL(p,j);
	for (l = *ep;  type_of(l) == t_cons;  l = l->c.c_cdr)
		if (string_eq(l->c.c_car, st)) {
			intern_flag = EXTERNAL;
			return(l->c.c_car);
		}
	for (ul=p->p.p_uselist; type_of(ul)==t_cons; ul=ul->c.c_cdr)
		for (l = P_EXTERNAL(ul->c.c_car,j);
		     type_of(l) == t_cons;
		     l = l->c.c_cdr)
			if (string_eq(l->c.c_car, st)) {
				intern_flag = INHERITED;
				return(l->c.c_car);
			}
	intern_flag = 0;
	return(Cnil);
}

bool
unintern(s, p)
object s, p;
{
	object x, y, l, *lp;
	int j;

	j = pack_hash(s);
	x = find_symbol(s, p);
	if (intern_flag == INTERNAL && s == x) {
		lp = &P_INTERNAL(p ,j);
		if (member_eq(s, p->p.p_shadowings))
			goto L;
		goto UNINTERN;
	}
	if (intern_flag == EXTERNAL && s == x) {
		lp = &P_EXTERNAL(p,j);
		if (member_eq(s, p->p.p_shadowings))
			goto L;
		goto UNINTERN;
	}
	return(FALSE);

L:
	x = OBJNULL;
	for (l = p->p.p_uselist; type_of(l) == t_cons; l = l->c.c_cdr) {
		y = find_symbol(s, l->c.c_car);
		if (intern_flag == EXTERNAL) {
			if (x == OBJNULL)
				x = y;
			else if (x != y)
FEerror("Cannot unintern the shadowing symbol ~S~%\
from ~S,~%\
because ~S and ~S will cause~%\
a name conflict.", 4, s, p, x, y);
		}
	}
	delete_eq(s, &p->p.p_shadowings);

UNINTERN:
	delete_eq(s, lp);
	if (s->s.s_hpack == p)
		s->s.s_hpack = Cnil;
	if ((enum stype)s->s.s_stype != stp_ordinary)
		uninterned_list = make_cons(s, uninterned_list);
	return(TRUE);
}

export(s, p)
object s, p;
{
	object x;
	int j;
	object *ep, *ip, l;

BEGIN:
	ip = NULL;
	j = pack_hash(s);
	x = find_symbol(s, p);
	if (intern_flag) {
		if (x != s) {
			import(s, p);	/*  signals an error  */
			goto BEGIN;
		}
		if (intern_flag == INTERNAL)
			ip = &P_INTERNAL(p ,j);
		else if (intern_flag == EXTERNAL)
			return;
	} else
		FEerror("The symbol ~S is not accessible from ~S.", 2,
			s, p);
	for (l = p->p.p_usedbylist;
	     type_of(l) == t_cons;
	     l = l->c.c_cdr) {
		x = find_symbol(s, l->c.c_car);
		if (intern_flag && s != x &&
		    !member_eq(x, l->c.c_car->p.p_shadowings))
FEerror("Cannot export the symbol ~S~%\
from ~S,~%\
because it will cause a name conflict~%\
in ~S.", 3, s, p, l->c.c_car);
	}
	if (ip != NULL)
		{delete_eq(s, ip);
		 p->p.p_internal_fp--;}
	ep = &P_EXTERNAL(p,j);
	p->p.p_external_fp++;
	*ep = make_cons(s, *ep);
}

unexport(s, p)
object s, p;
{
	object x, *ep, *ip;
	int j;

	if (p == keyword_package)
		FEerror("Cannot unexport a symbol from the keyword.", 0);
	x = find_symbol(s, p);
	if (intern_flag != EXTERNAL || x != s)
FEerror("Cannot unexport the symbol ~S~%\
from ~S,~%\
because the symbol is not an external symbol~%\
of the package.", 2, s, p);
	j = pack_hash(s);
	ep = &P_EXTERNAL(p,j);
	delete_eq(s, ep);
	ip = &P_INTERNAL(p ,j);
	p->p.p_internal_fp++;
	*ip = make_cons(s, *ip);
}

import(s, p)
object s, p;
{
	object x;
	int j;
	object *ip, l;

	x = find_symbol(s, p);
	if (intern_flag) {
		if (x != s)
FEerror("Cannot import the symbol ~S~%\
from ~S,~%\
because there is already a symbol with the same name~%\
in the package.", 2, s, p);
		if (intern_flag == INTERNAL || intern_flag == EXTERNAL)
			return;
	}
	j = pack_hash(s);
	ip = &P_INTERNAL(p ,j);
	p->p.p_internal_fp++;
	*ip = make_cons(s, *ip);
}

shadowing_import(s, p)
object s, p;
{
	object x, *ip;

	x = find_symbol(s, p);
	if (intern_flag && intern_flag != INHERITED) {
		if (x == s) {
			if (!member_eq(x, p->p.p_shadowings))
				p->p.p_shadowings
				= make_cons(x, p->p.p_shadowings);
			return;
		}
		if(member_eq(x, p->p.p_shadowings))
			delete_eq(x, &p->p.p_shadowings);
		if (intern_flag == INTERNAL)
			delete_eq(x, &P_INTERNAL(p,pack_hash(x)));
		else
			delete_eq(x, &P_EXTERNAL(p ,pack_hash(x)));
		if (x->s.s_hpack == p)
			x->s.s_hpack = Cnil;
		if ((enum stype)x->s.s_stype != stp_ordinary)
			uninterned_list = make_cons(x, uninterned_list);
	}
	ip = &P_INTERNAL(p ,pack_hash(s));
	*ip = make_cons(s, *ip);
	p->p.p_internal_fp++;	
	p->p.p_shadowings = make_cons(s, p->p.p_shadowings);
}

shadow(s, p)
object s, p;
{
	int j;
	object *ip;

	find_symbol(s, p);
	if (intern_flag == INTERNAL || intern_flag == EXTERNAL)
		return;
	j = pack_hash(s);
	ip = &P_INTERNAL(p ,j);
	vs_push(make_symbol(s));
	vs_head->s.s_hpack = p;
	*ip = make_cons(vs_head, *ip);
	p->p.p_internal_fp++;
	p->p.p_shadowings = make_cons(vs_head, p->p.p_shadowings);
	vs_pop;
}

use_package(x0, p)
object x0, p;
{
	object x = x0;
	int i;
	object y, l;

	if (type_of(x) != t_package) {
		x = find_package(x);
		if (x == Cnil)
			no_package(x0);
	}
	if (x == keyword_package)
		FEerror("Cannot use keyword package.", 0);
	if (p == x)
		return;
	if (member_eq(x, p->p.p_uselist))
		return;
	for (i = 0;  i < x->p.p_external_size;  i++)
		for (l = P_EXTERNAL(x ,i);
		     type_of(l) == t_cons;
		     l = l->c.c_cdr) {
			y = find_symbol(l->c.c_car, p);
			if (intern_flag && l->c.c_car != y
			    && ! member_eq(y,p->p.p_shadowings)
			    )
FEerror("Cannot use ~S~%\
from ~S,~%\
because ~S and ~S will cause~%\
a name conflict.", 4, x, p, l->c.c_car, y);
		}
	p->p.p_uselist = make_cons(x, p->p.p_uselist);
	x->p.p_usedbylist = make_cons(p, x->p.p_usedbylist);
}

unuse_package(x0, p)
object x0, p;
{
	object x = x0;

	if (type_of(x) != t_package) {
		x = find_package(x);
		if (x == Cnil)
			no_package(x0);
	}
	delete_eq(x, &p->p.p_uselist);
	delete_eq(p, &x->p.p_usedbylist);
}

@(defun make_package (pack_name
		      &key nicknames
			   (use `make_cons(lisp_package, Cnil)`)
		      (internal `small_fixnum(0)`)
		      (external `small_fixnum(0)`)
		      )
@
	check_type_or_string_symbol(&pack_name);
	@(return `make_package(pack_name, nicknames, use,
			       fix(internal),fix(external))`)
@)

@(defun in_package (pack_name &key nicknames (use Cnil use_sp)
		      (internal `small_fixnum(0)`)
		      (external `small_fixnum(0)`)
		    )
@
	check_type_or_string_symbol(&pack_name);
	if (find_package(pack_name) == Cnil && !(use_sp))
		use = make_cons(lisp_package, Cnil);
	@(return `in_package(pack_name, nicknames, use,fix(internal),fix(external))`)
@)

Lfind_package()
{
	check_arg(1);

	vs_base[0] = find_package(vs_base[0]);
}

Lpackage_name()
{
	check_arg(1);

	check_type_package(&vs_base[0]);
	vs_base[0] = vs_base[0]->p.p_name;
}

Lpackage_nicknames()
{
	check_arg(1);

	check_type_or_symbol_string_package(&vs_base[0]);
	vs_base[0] = coerce_to_package(vs_base[0]);
	vs_base[0] = vs_base[0]->p.p_nicknames;
}

@(defun rename_package (pack new_name &o new_nicknames)
@
	check_type_or_symbol_string_package(&pack);
	pack = coerce_to_package(pack);
	check_type_or_string_symbol(&new_name);
	@(return `rename_package(pack, new_name, new_nicknames)`)
@)

Lpackage_use_list()
{
	check_arg(1);

	check_type_or_symbol_string_package(&vs_base[0]);
	vs_base[0] = coerce_to_package(vs_base[0]);
	vs_base[0] = vs_base[0]->p.p_uselist;
}

Lpackage_used_by_list()
{
	check_arg(1);

	check_type_or_symbol_string_package(&vs_base[0]);
	vs_base[0] = coerce_to_package(vs_base[0]);
	vs_base[0] = vs_base[0]->p.p_usedbylist;
}

Lpackage_shadowing_symbols()
{
	check_arg(1);

	check_type_or_symbol_string_package(&vs_base[0]);
	vs_base[0] = coerce_to_package(vs_base[0]);
	vs_base[0] = vs_base[0]->p.p_shadowings;
}

Llist_all_packages()
{
	struct package *p;
	int i;

	check_arg(0);
	for (p = pack_pointer, i = 0;  p != NULL;  p = p->p_link, i++)
		vs_push((object)p);
	vs_push(Cnil);
	while (i-- > 0)
		stack_cons();
}

@(defun intern (strng &optional (p `current_package()`) &aux sym)
@
	check_type_string(&strng);
	check_type_or_symbol_string_package(&p);
	p = coerce_to_package(p);
	sym = intern(strng, p);
	if (intern_flag == INTERNAL)
		@(return sym Kinternal)
	if (intern_flag == EXTERNAL)
		@(return sym Kexternal)
	if (intern_flag == INHERITED)
		@(return sym Kinherited)
	@(return sym Cnil)
@)

@(defun find_symbol (strng &optional (p `current_package()`))
	object x;
@
	check_type_string(&strng);
	check_type_or_symbol_string_package(&p);
	p = coerce_to_package(p);
	x = find_symbol(strng, p);
	if (intern_flag == INTERNAL)
		@(return x Kinternal)
	if (intern_flag == EXTERNAL)
		@(return x Kexternal)
	if (intern_flag == INHERITED)
		@(return x Kinherited)
	@(return Cnil Cnil)
@)

@(defun unintern (symbl &optional (p `current_package()`))
	object x;
@
	check_type_symbol(&symbl);
	check_type_or_symbol_string_package(&p);
	p = coerce_to_package(p);
	if (unintern(symbl, p))
		@(return Ct)
	else
		@(return Cnil)
@)

@(defun export (symbols &o (pack `current_package()`))
	object l;
@
	check_type_or_symbol_string_package(&pack);
	pack = coerce_to_package(pack);
BEGIN:
	switch (type_of(symbols)) {
	case t_symbol:
		if (symbols == Cnil)
			break;
		export(symbols, pack);
		break;

	case t_cons:
		for (l = symbols;  !endp(l);  l = l->c.c_cdr)
			export(l->c.c_car, pack);
		break;

	default:
		check_type_symbol(&symbols);
		goto BEGIN;
	}
	@(return Ct)
@)

@(defun unexport (symbols &o (pack `current_package()`))
	object l;
@
	check_type_or_symbol_string_package(&pack);
	pack = coerce_to_package(pack);
BEGIN:
	switch (type_of(symbols)) {
	case t_symbol:
		if (symbols == Cnil)
			break;
		unexport(symbols, pack);
		break;

	case t_cons:
		for (l = symbols;  !endp(l);  l = l->c.c_cdr)
			unexport(l->c.c_car, pack);
		break;

	default:
		check_type_symbol(&symbols);
		goto BEGIN;
	}
	@(return Ct)
@)

@(defun import (symbols &o (pack `current_package()`))
	object l;
@
	check_type_or_symbol_string_package(&pack);
	pack = coerce_to_package(pack);
BEGIN:
	switch (type_of(symbols)) {
	case t_symbol:
		if (symbols == Cnil)
			break;
		import(symbols, pack);
		break;

	case t_cons:
		for (l = symbols;  !endp(l);  l = l->c.c_cdr)
			import(l->c.c_car, pack);
		break;

	default:
		check_type_symbol(&symbols);
		goto BEGIN;
	}
	@(return Ct)
@)

@(defun shadowing_import (symbols &o (pack `current_package()`))
	object l;
@
	check_type_or_symbol_string_package(&pack);
	pack = coerce_to_package(pack);
BEGIN:
	switch (type_of(symbols)) {
	case t_symbol:
		if (symbols == Cnil)
			break;
		shadowing_import(symbols, pack);
		break;

	case t_cons:
		for (l = symbols;  !endp(l);  l = l->c.c_cdr)
			shadowing_import(l->c.c_car, pack);
		break;

	default:
		check_type_symbol(&symbols);
		goto BEGIN;
	}
	@(return Ct)
@)

@(defun shadow (symbols &o (pack `current_package()`))
	object l;
@
	check_type_or_symbol_string_package(&pack);
	pack = coerce_to_package(pack);
BEGIN:
	switch (type_of(symbols)) {
	case t_symbol:
		if (symbols == Cnil)
			break;
		shadow(symbols, pack);
		break;

	case t_cons:
		for (l = symbols;  !endp(l);  l = l->c.c_cdr)
			shadow(l->c.c_car, pack);
		break;

	default:
		check_type_symbol(&symbols);
		goto BEGIN;
	}
	@(return Ct)
@)

@(defun use_package (pack &o (pa `current_package()`))
	object l;
@
	check_type_or_symbol_string_package(&pa);
	pa = coerce_to_package(pa);
BEGIN:
	switch (type_of(pack)) {
	case t_symbol:
		if (pack == Cnil)
			break;

	case t_string:
	case t_package:
		use_package(pack, pa);
		break;

	case t_cons:
		for (l = pack;  !endp(l);  l = l->c.c_cdr)
			use_package(l->c.c_car, pa);
		break;

	default:
		check_type_package(&pack);
		goto BEGIN;
	}
	@(return Ct)
@)

@(defun unuse_package (pack &o (pa `current_package()`))
	object l;
@
	check_type_or_symbol_string_package(&pa);
	pa = coerce_to_package(pa);
BEGIN:
	switch (type_of(pack)) {
	case t_symbol:
		if (pack == Cnil)
			break;

	case t_string:
	case t_package:
		unuse_package(pack, pa);
		break;

	case t_cons:
		for (l = pack;  !endp(l);  l = l->c.c_cdr)
			unuse_package(l->c.c_car, pa);
		break;

	default:
		check_type_package(&pack);
		goto BEGIN;
	}
	@(return Ct)
@)

siLpackage_internal()
{
	int j;

	check_arg(2);
	check_type_package(&vs_base[0]);
	if (type_of(vs_base[1]) != t_fixnum ||
	    (j = fix(vs_base[1])) < 0 || j >= vs_base[0]->p.p_internal_size)
		FEerror("~S is an illgal index to a package hashtable.",
			1, vs_base[1]);
	vs_base[0] = P_INTERNAL(vs_base[0],j);
	vs_pop;
}

siLpackage_external()
{
	int j;

	check_arg(2);
	check_type_package(&vs_base[0]);
	if (type_of(vs_base[1]) != t_fixnum ||
	    (j = fix(vs_base[1])) < 0 || j >= vs_base[0]->p.p_external_size)
		FEerror("~S is an illegal index to a package hashtable.",
			1, vs_base[1]);
	vs_base[0] = P_EXTERNAL(vs_base[0],j);
	vs_pop;
}

no_package(n)
object n;
{
	FEerror("There is no package with the name ~A.", 1, n);
}

package_already(n)
object n;
{
	FEerror("A package with the name ~A already exists.", 1, n);
}

void
siLpackage_size()
{object p;
 p=vs_base[0];
 check_type_package(&p);
 check_arg(1);
 vs_base[0]=make_fixnum(p->p.p_external_size);
 vs_base[1]=make_fixnum(p->p.p_internal_size);
 vs_top=vs_base+2;
 return;
}
 

init_package()
{

	lisp_package
	= make_package(make_simple_string("LISP"),
		       Cnil, Cnil,47,509);
	user_package
	= make_package(make_simple_string("USER"),
		       Cnil,
		       make_cons(lisp_package, Cnil),509,97);
	keyword_package
	= make_package(make_simple_string("KEYWORD"),
		       Cnil, Cnil,11,509);
	system_package
	= make_package(make_simple_string("SYSTEM"),
		       make_cons(make_simple_string("SI"),
			         make_cons(make_simple_string("SYS"),
					   Cnil)),
		       make_cons(lisp_package, Cnil),251,157);

	/*  There is no need to enter a package as a mark origin.  */

	Vpackage = make_special("*PACKAGE*", lisp_package);

	Kinternal = make_keyword("INTERNAL");
	Kexternal = make_keyword("EXTERNAL");
	Kinherited = make_keyword("INHERITED");
	Knicknames = make_keyword("NICKNAMES");
	Kuse = make_keyword("USE");

	uninterned_list = Cnil;
	enter_mark_origin(&uninterned_list);
}

init_package_function()
{
	make_function("MAKE-PACKAGE", Lmake_package);
	make_function("IN-PACKAGE", Lin_package);
	make_function("FIND-PACKAGE", Lfind_package);
	make_function("PACKAGE-NAME", Lpackage_name);
	make_function("PACKAGE-NICKNAMES", Lpackage_nicknames);
	make_function("RENAME-PACKAGE", Lrename_package);
	make_function("PACKAGE-USE-LIST", Lpackage_use_list);
	make_function("PACKAGE-USED-BY-LIST", Lpackage_used_by_list);
	make_function("PACKAGE-SHADOWING-SYMBOLS",
		      Lpackage_shadowing_symbols);
	make_function("LIST-ALL-PACKAGES", Llist_all_packages);
	make_function("INTERN", Lintern);
	make_function("FIND-SYMBOL", Lfind_symbol);
	make_function("UNINTERN", Lunintern);
	make_function("EXPORT", Lexport);
	make_function("UNEXPORT", Lunexport);
	make_function("IMPORT", Limport);
	make_function("SHADOWING-IMPORT", Lshadowing_import);
	make_function("SHADOW", Lshadow);
	make_function("USE-PACKAGE", Luse_package);
	make_function("UNUSE-PACKAGE", Lunuse_package);

	make_si_function("PACKAGE-SIZE",siLpackage_size);
	make_si_function("PACKAGE-INTERNAL", siLpackage_internal);
	make_si_function("PACKAGE-EXTERNAL", siLpackage_external);
}
