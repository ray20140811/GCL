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
	pathname.d
	IMPLEMENTATION-DEPENTENT

	This file contains those functions that interpret namestrings.
*/

#include "include.h"


object
make_pathname(host, device, directory, name, type, version)
object host, device, directory, name, type, version;
{
	object x;

	x = alloc_object(t_pathname);
	x->pn.pn_host = host;
	x->pn.pn_device = device;
	x->pn.pn_directory = directory;
	x->pn.pn_name = name;
	x->pn.pn_type = type;
	x->pn.pn_version = version;
	return(x);
}

static
make_one(s, end)
char *s;
int end;
{
	int i;

#ifdef UNIX
	for (i = 0;  i < end;  i++)
		token->st.st_self[i] = s[i];
#endif
#ifdef AOSVS



#endif
	token->st.st_fillp = end;
	vs_push(copy_simple_string(token));
}

/* !!!!! Bug Fix. NLG */
object
parse_namestring(s, start, end, ep)
object s;
int start, end, *ep;
{
	int i, j, k;
	int d;
	object *vsp;
	object x;
	vs_mark;

	vsp = vs_top + 1;
	for (i = j = start;  i < end;  ) {
		if (isspace(s->st.st_self[i]))
			break;
#ifndef IS_DIR_SEPARATOR
#define IS_DIR_SEPARATOR(x) (x == '/')
#endif
#ifdef UNIX
		if (IS_DIR_SEPARATOR(s->st.st_self[i])) {
#endif

			if (j == 0 && i == 0) {
				i++;
				vs_push(Kroot);
				j = i;
				continue;
			}
#ifdef UNIX
			/* BUG FIX by Grant J. Munsey */
			if (i == j) {
				i++;
				j = i;
				continue;
			}
			/* END OF BUG FIX */
#endif
#ifdef AOSVS


#endif
#ifdef UNIX
			if (i-j == 1 && s->st.st_self[j] == '.') {
				vs_push(Kcurrent);
			} else if (i-j==2 && s->st.st_self[j]=='.' && s->st.st_self[j+1]=='.') {
				vs_push(Kparent);
			} else
				make_one(&s->st.st_self[j], i-j);
#endif
#ifdef AOSVS

#endif
			i++;
			j = i;
#ifdef AOSVS


























#endif
		} else
			i++;
	}
#ifdef UNIX
/*
	if (i-j == 1 && s->st.st_self[j] == '.') {
		vs_push(Kcurrent);
		j = i;
	} else if (i-j == 2 && s->st.st_self[j] == '.' && s->st.st_self[j+1] == '.') {
		vs_push(Kparent);
		j = i;
	}
*/
#endif
	*ep = i;
	vs_push(Cnil);
	while (vs_top > vsp)
		stack_cons();
	if (i == j) {
		/*  no file and no type  */
		vs_push(Cnil);
		vs_push(Cnil);
		goto L;
	}
	for (k = j, d = -1;  k < i;  k++)
		if (s->st.st_self[k] == '.')
			d = k;
	if (d == -1) {
		/*  no file type  */
#ifdef UNIX
		if (i-j == 1 && s->st.st_self[j] == '*')
#endif
#ifdef AOSVS

#endif
			vs_push(Kwild);
		else
			make_one(&s->st.st_self[j], i-j);
		vs_push(Cnil);
	} else if (d == j) {
		/*  no file name  */
		vs_push(Cnil);
#ifdef UNIX
		if (i-d-1 == 1 && s->st.st_self[d+1] == '*')
#endif
#ifdef AOSVS

#endif
			vs_push(Kwild);
		else
			make_one(&s->st.st_self[d+1], i-d-1);
	} else {
		/*  file name and file type  */
#ifdef UNIX
		if (d-j == 1 && s->st.st_self[j] == '*')
#endif
#ifdef AOSVS

#endif
			vs_push(Kwild);
		else
			make_one(&s->st.st_self[j], d-j);
#ifdef UNIX
		if (i-d-1 == 1 && s->st.st_self[d+1] == '*')
#endif
#ifdef AOSVS

#endif
			vs_push(Kwild);
		else
			make_one(&s->st.st_self[d+1], i-d-1);
	}
L:
	x
	= make_pathname(Cnil, Cnil,
			vs_top[-3], vs_top[-2], vs_top[-1], Cnil);
	vs_reset;
	return(x);

NO:
	*ep = i;
	vs_reset;
	return(OBJNULL);
}

object
coerce_to_pathname(x)
object x;
{
	object y;
	int e;

L:
	switch (type_of(x)) {
	case t_symbol:
	case t_string:
                /* !!!!! Bug Fix. NLG */
		y = parse_namestring(x, 0, x->st.st_fillp, &e);
		if (y == OBJNULL || e != x->st.st_fillp)
			goto CANNOT_COERCE;
		return(y);

	case t_pathname:
		return(x);

	case t_stream:
		switch (x->sm.sm_mode) {
		case smm_input:
		case smm_output:
		case smm_probe:
		case smm_io:
			x = x->sm.sm_object1;
			/*
				The file was stored in sm.sm_object1.
				See open.
			*/
			goto L;

		case smm_synonym:
			x = symbol_value(x->sm.sm_object0);
			goto L;

		default:
			goto CANNOT_COERCE;
		}

	default:
	CANNOT_COERCE:
		FEerror("~S cannot be coerced to a pathname.", 1, x);
	}
}

object
default_device(host)
object host;
{
	return(Cnil);
	/*  not implemented yet  */
}

object
merge_pathnames(path, defaults, default_version)
object path, defaults, default_version;
{
	object host, device, directory, name, type, version;

	if (path->pn.pn_host == Cnil)
		host = defaults->pn.pn_host;
	else
		host = path->pn.pn_host;
	if (path->pn.pn_device == Cnil)
		if (path->pn.pn_host == Cnil)
			device = defaults->pn.pn_device;
		else if (path->pn.pn_host == defaults->pn.pn_host)
			device = defaults->pn.pn_device;
		else
			device = default_device(path->pn.pn_host);
	else
		device = path->pn.pn_device;
	if (path->pn.pn_directory == Cnil)
		directory = defaults->pn.pn_directory;
	else
		directory = path->pn.pn_directory;
	if (path->pn.pn_name == Cnil)
		name = defaults->pn.pn_name;
	else
		name = path->pn.pn_name;
	if (path->pn.pn_type == Cnil)
		type = defaults->pn.pn_type;
	else
		type = path->pn.pn_type;
	version = Cnil;
	/*
		In this implimentation, version is not counted
	*/
	return(make_pathname(host,device,directory,name,type,version));
}

/*
	Namestring(x) converts a pathname to a namestring.
*/
object
namestring(x)
object x;
{
	int i, j;
	object l, y;

	i = 0;
	l = x->pn.pn_directory;
	if (endp(l))
		goto L;
	y = l->c.c_car;
	if (y == Kroot) {
#ifdef UNIX
		token->st.st_self[i++] = '/';
#endif
#ifdef AOSVS

#endif
		l = l->c.c_cdr;
	}
#ifdef AOSVS













#endif
	for (;  !endp(l);  l = l->c.c_cdr) {
		y = l->c.c_car;
#ifdef UNIX
		if (y == Kcurrent) {
			token->st.st_self[i++] = '.';
			token->st.st_self[i++] = '/';
			continue;
		} else if (y == Kparent) {
			token->st.st_self[i++] = '.';
			token->st.st_self[i++] = '.';
			token->st.st_self[i++] = '/';
			continue;
		}
#endif
		y = coerce_to_string(y);
		for (j = 0;  j < y->st.st_fillp;  j++)
			token->st.st_self[i++]
			= y->st.st_self[j];
#ifdef UNIX
		token->st.st_self[i++] = '/';
#endif
#ifdef AOSVS

#endif
	}
L:
	y = x->pn.pn_name;
	if (y == Cnil)
		goto M;
	if (y == Kwild) {
#ifdef UNIX
		token->st.st_self[i++] = '*';
#endif
#ifdef AOSVS

#endif
		goto M;
	}
	if (type_of(y) != t_string)
		FEerror("~S is an illegal pathname name.", 1, y);
	for (j = 0;  j < y->st.st_fillp;  j++)
		token->st.st_self[i++] = y->st.st_self[j];
M:
	y = x->pn.pn_type;
	if (y == Cnil)
		goto N;
	if (y == Kwild) {
		token->st.st_self[i++] = '.';
#ifdef UNIX
		token->st.st_self[i++] = '*';
#endif
#ifdef AOSVS

#endif
		goto N;
	}
	if (type_of(y) != t_string)
		FEerror("~S is an illegal pathname name.", 1, y);
	token->st.st_self[i++] = '.';
	for (j = 0;  j < y->st.st_fillp;  j++)
		token->st.st_self[i++] = y->st.st_self[j];
N:
	token->st.st_fillp = i;
	return(copy_simple_string(token));
}

object
coerce_to_namestring(x)
object x;
{
	object y;
	int e;

L:
	switch (type_of(x)) {
	case t_symbol:
		vs_push(alloc_simple_string(x->s.s_fillp));
		/* By Nick Gall */
		vs_head->st.st_self = alloc_relblock(x->s.s_fillp);
		{
			int i;
			for (i = 0;  i < x->s.s_fillp;  i++)
				vs_head->st.st_self[i] = x->s.s_self[i];
		}
		return(vs_pop);

	case t_string:
		return(x);

	case t_pathname:
		return(namestring(x));

	case t_stream:
		switch (x->sm.sm_mode) {
		case smm_input:
		case smm_output:
		case smm_probe:
		case smm_io:
			x = x->sm.sm_object1;
			/*
				The file was stored in sm.sm_object1.
				See open.
			*/
			goto L;

		case smm_synonym:
			x = symbol_value(x->sm.sm_object0);
			goto L;

		default:
			goto CANNOT_COERCE;
		}

	default:
	CANNOT_COERCE:
		FEerror("~S cannot be coerced to a namestring.", 1, x);
	}
}

Lpathname()
{
	check_arg(1);
	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	vs_base[0] = coerce_to_pathname(vs_base[0]);
}

@(defun parse_namestring (thing
	&o host
	   (defaults `symbol_value(Vdefault_pathname_defaults)`)
	&k start end junk_allowed
	&a x y)
	int s, e, ee;
@
	check_type_or_pathname_string_symbol_stream(&thing);
	check_type_or_pathname_string_symbol_stream(&defaults);
	defaults = coerce_to_pathname(defaults);
	x = thing;
L:
	switch (type_of(x)) {
	case t_symbol:
	case t_string:
		get_string_start_end(x, start, end, &s, &e);
		for (;  s < e && isspace(x->st.st_self[s]);  s++)
			;
		y
                  /* !!!!! Bug Fix. NLG */
		= parse_namestring(x,
                                   s,
				   e - s,
				   &ee);
		if (junk_allowed == Cnil) {
			for (;  ee < e - s;  ee++)
				if (!isspace(x->st.st_self[s + ee]))
					break;
			if (y == OBJNULL || ee != e - s)
				FEerror("Cannot parse the namestring ~S~%\
from ~S to ~S.",
					3, x, start, end);
		} else
			if (y == OBJNULL)
				@(return Cnil `make_fixnum(s + ee)`)
		start = make_fixnum(s + ee);
		break;

	case t_pathname:
		y = x;
		break;

	case t_stream:
		switch (x->sm.sm_mode) {
		case smm_input:
		case smm_output:
		case smm_probe:
		case smm_io:
			x = x->sm.sm_object1;
			/*
				The file was stored in sm.sm_object1.
				See open.
			*/
			goto L;

		case smm_synonym:
			x = symbol_value(x->sm.sm_object0);
			goto L;

		default:
			goto CANNOT_PARSE;
		}

	default:
	CANNOT_PARSE:
		FEerror("Cannot parse the namestring ~S.", 1, x);
	}
	if (host != Cnil && y->pn.pn_host != Cnil &&
	    host != y->pn.pn_host)
		FEerror("The hosts ~S and ~S do not match.",
			2, host, y->pn.pn_host);
	@(return y start)
@)

@(defun merge_pathnames (path
	&o (defaults `symbol_value(Vdefault_pathname_defaults)`)
 	   (default_version Knewest))
@
	check_type_or_pathname_string_symbol_stream(&path);
	check_type_or_pathname_string_symbol_stream(&defaults);
	path = coerce_to_pathname(path);
	defaults = coerce_to_pathname(defaults);
	@(return `merge_pathnames(path, defaults, default_version)`)
@)

@(defun make_pathname (&key host device directory name
			    type version defaults
		       &aux x)
@
	if (defaults == Cnil) {
		defaults
		= symbol_value(Vdefault_pathname_defaults);
		defaults = coerce_to_pathname(defaults);
		defaults
		= make_pathname(defaults->pn.pn_host,
			        Cnil, Cnil, Cnil, Cnil, Cnil);
	} else
		defaults = coerce_to_pathname(defaults);
	x = make_pathname(host, device, directory, name, type, version);
	x = merge_pathnames(x, defaults, Cnil);
	@(return x)
@)

Lpathnamep()
{
	check_arg(1);

	if (type_of(vs_base[0]) == t_pathname)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Lpathname_host()
{
	check_arg(1);

	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	vs_base[0] = coerce_to_pathname(vs_base[0]);
	vs_base[0] = vs_base[0]->pn.pn_host;
}

Lpathname_device()
{
	check_arg(1);

	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	vs_base[0] = coerce_to_pathname(vs_base[0]);
	vs_base[0] = vs_base[0]->pn.pn_device;
}

Lpathname_directory()
{
	check_arg(1);

	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	vs_base[0] = coerce_to_pathname(vs_base[0]);
	vs_base[0] = vs_base[0]->pn.pn_directory;
}

Lpathname_name()
{
	check_arg(1);

	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	vs_base[0] = coerce_to_pathname(vs_base[0]);
	vs_base[0] = vs_base[0]->pn.pn_name;
}

Lpathname_type()
{
	check_arg(1);

	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	vs_base[0] = coerce_to_pathname(vs_base[0]);
	vs_base[0] = vs_base[0]->pn.pn_type;
}

Lpathname_version()
{
	check_arg(1);

	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	vs_base[0] = coerce_to_pathname(vs_base[0]);
	vs_base[0] = vs_base[0]->pn.pn_version;
}

Lnamestring()
{
	check_arg(1);

	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	vs_base[0] = coerce_to_namestring(vs_base[0]);
}

Lfile_namestring()
{
	check_arg(1);

	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	vs_base[0] = coerce_to_pathname(vs_base[0]);
	vs_base[0]
	= make_pathname(Cnil, Cnil, Cnil,
		        vs_base[0]->pn.pn_name,
		        vs_base[0]->pn.pn_type,
		        vs_base[0]->pn.pn_version);
	vs_base[0] = namestring(vs_base[0]);
}

Ldirectory_namestring()
{
	check_arg(1);

	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	vs_base[0] = coerce_to_pathname(vs_base[0]);
	vs_base[0]
	= make_pathname(Cnil, Cnil,
		        vs_base[0]->pn.pn_directory,
		        Cnil, Cnil, Cnil);
	vs_base[0] = namestring(vs_base[0]);
}

Lhost_namestring()
{
	check_arg(1);

	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	vs_base[0] = coerce_to_pathname(vs_base[0]);
	vs_base[0] = vs_base[0]->pn.pn_host;
	if (vs_base[0] == Cnil || vs_base[0] == Kwild)
		vs_base[0] = make_simple_string("");
}

@(defun enough_namestring (path
	&o (defaults `symbol_value(Vdefault_pathname_defaults)`))
@
	check_type_or_pathname_string_symbol_stream(&path);
	check_type_or_pathname_string_symbol_stream(&defaults);
	defaults = coerce_to_pathname(defaults);
	path = coerce_to_pathname(path);
	path
	= make_pathname(equalp(path->pn.pn_host, defaults->pn.pn_host) ?
			Cnil : path->pn.pn_host,
	                equalp(path->pn.pn_device,
			       defaults->pn.pn_device) ?
			Cnil : path->pn.pn_device,
	                equalp(path->pn.pn_directory,
			       defaults->pn.pn_directory) ?
			Cnil : path->pn.pn_directory,
	                equalp(path->pn.pn_name, defaults->pn.pn_name) ?
			Cnil : path->pn.pn_name,
	                equalp(path->pn.pn_type, defaults->pn.pn_type) ?
			Cnil : path->pn.pn_type,
	                equalp(path->pn.pn_version,
			       defaults->pn.pn_version) ?
			Cnil : path->pn.pn_version);
	@(return `namestring(path)`)
@)

init_pathname()
{
	Vdefault_pathname_defaults =
	make_special("*DEFAULT-PATHNAME-DEFAULTS*",
		     make_pathname(Cnil, Cnil, Cnil, Cnil, Cnil, Cnil));

	Kwild = make_keyword("WILD");
	Knewest = make_keyword("NEWEST");

	Kstart = make_keyword("START");
	Kend = make_keyword("END");
	Kjunk_allowed = make_keyword("JUNK-ALLOWED");

	Khost = make_keyword("HOST");
	Kdevice = make_keyword("DEVICE");
	Kdirectory = make_keyword("DIRECTORY");
	Kname = make_keyword("NAME");
	Ktype = make_keyword("TYPE");
	Kversion = make_keyword("VERSION");
	Kdefaults = make_keyword("DEFAULTS");

	Kroot = make_keyword("ROOT");
	Kcurrent = make_keyword("CURRENT");
	Kparent = make_keyword("PARENT");
	Kper = make_keyword("PER");
}

init_pathname_function()
{
	make_function("PATHNAME", Lpathname);
	make_function("PARSE-NAMESTRING", Lparse_namestring);
	make_function("MERGE-PATHNAMES", Lmerge_pathnames);
	make_function("MAKE-PATHNAME", Lmake_pathname);
	make_function("PATHNAMEP", Lpathnamep);
	make_function("PATHNAME-HOST", Lpathname_host);
	make_function("PATHNAME-DEVICE", Lpathname_device);
	make_function("PATHNAME-DIRECTORY", Lpathname_directory);
	make_function("PATHNAME-NAME", Lpathname_name);
	make_function("PATHNAME-TYPE", Lpathname_type);
	make_function("PATHNAME-VERSION", Lpathname_version);
	make_function("NAMESTRING", Lnamestring);
	make_function("FILE-NAMESTRING", Lfile_namestring);
	make_function("DIRECTORY-NAMESTRING", Ldirectory_namestring);
	make_function("HOST-NAMESTRING", Lhost_namestring);
	make_function("ENOUGH-NAMESTRING", Lenough_namestring);
}
