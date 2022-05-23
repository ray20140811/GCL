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
	cfun.c
*/

#include "include.h"


#define dcheck_vs do{if (vs_base < vs_org || vs_top < vs_org) error("bad vs");} while (0)
#define dcheck_type(a,b) check_type(a,b) ; dcheck_vs 

#define PADDR(i) ((char *)(siSPinit->s.s_dbind->fixa.fixa_self[fix(i)]))
object siSPinit,siSPmemory;

object
make_cfun(self, name, data, start, size)
int (*self)();
object name, data;
char *start;
int size;
{
	object cf;

	cf = alloc_object(t_cfun);
	cf->cf.cf_self = self;
	cf->cf.cf_name = name;
	cf->cf.cf_data = data;
	if(data && type_of(data)==t_cfdata)
	  { data->cfd.cfd_start=start; 
	    data->cfd.cfd_size=size;}
	  else if(size) FEerror(0,"Bad call to make_cfun");
	return(cf);
}
object
make_sfun(name,self,argd, data)
int argd,(*self)();
object name, data;
{object sfn;
       
	sfn = alloc_object(t_sfun);
        if(argd >15) sfn->d.t = (int)t_gfun;
	sfn->sfn.sfn_self = self;
	sfn->sfn.sfn_name = name;
	sfn->sfn.sfn_data = data;
        sfn->sfn.sfn_argd = argd;
	return(sfn);
}

#define VFUN_MIN_ARGS(argd) (argd & 0xff)
#define VFUN_MAX_ARGS(argd) ((argd) >> 8)

object
make_vfun(name,self,argd, data)
int (*self)(),argd;
object name, data;
{object vfn;
       
	vfn = alloc_object(t_vfun);
	vfn->vfn.vfn_self = self;
	vfn->vfn.vfn_name = name;
	vfn->vfn.vfn_minargs = VFUN_MIN_ARGS(argd);
        vfn->vfn.vfn_maxargs = VFUN_MAX_ARGS(argd);
        vfn->vfn.vfn_data = data;
	return(vfn);
}

object
make_cclosure_new(self, name, env, data)
int (*self)();
object name, env, data;
{
	object cc;

	cc = alloc_object(t_cclosure);
	cc->cc.cc_self = self;
	cc->cc.cc_name = name;
	cc->cc.cc_env = env;
	cc->cc.cc_data = data;
	cc->cc.cc_turbo = NULL;
	return(cc);
}


object
make_cclosure(self, name, env, data, start, size)
int (*self)();
object name, env, data;
char *start;
int size;
{
	if(data && type_of(data)==t_cfdata)
	  { data->cfd.cfd_start=start; 
	    data->cfd.cfd_size=size;}
	  else if(size) FEerror("Bad call to make_cclosure",0);
	return make_cclosure_new(self,name,env,data);

}


siLmc() /* args: (name,address) */
{ dcheck_type(vs_base[0],t_symbol);
  dcheck_type(vs_base[1],t_fixnum);
  dcheck_type(siSPmemory->s.s_dbind,t_cfdata);
  vs_base[0]=make_cclosure_new(PADDR(vs_base[1]),vs_base[0],Cnil,
		     siSPmemory->s.s_dbind);}

object MFsfun(sym,self,argd,data)
     object sym,data;
     int argd,(*self)();
{object sfn;
 if (type_of(sym)!=t_symbol) not_a_symbol(sym);
 if (sym->s.s_sfdef != NOT_SPECIAL && sym->s.s_mflag)
   sym->s.s_sfdef = NOT_SPECIAL;
 sfn = make_sfun(sym,self,argd,data);
 sym = clear_compiler_properties(sym,sfn);
 sym->s.s_gfdef = sfn;
 sym->s.s_mflag = FALSE;
}

siLmfsfun() /* args: (name,address,argd) */
{  dcheck_type(vs_base[1],t_fixnum);
  MFsfun(vs_base[0],PADDR(vs_base[1]),fix(vs_base[2]),siSPmemory->s.s_dbind);}


object MFvfun(sym,self,argd,data)
     object sym,data;
     int argd,(*self)();
{object vfn;
 if (type_of(sym)!=t_symbol) not_a_symbol(sym);
 if (sym->s.s_sfdef != NOT_SPECIAL && sym->s.s_mflag)
   sym->s.s_sfdef = NOT_SPECIAL;
 dcheck_type(data,t_cfdata);
 vfn = make_vfun(sym,self,argd,data);
 sym = clear_compiler_properties(sym,vfn);
 sym->s.s_gfdef = vfn;
 sym->s.s_mflag = FALSE;
}

siLmfvfun()
{MFvfun(vs_base[0],PADDR(vs_base[1]),fix(vs_base[2]),siSPmemory->s.s_dbind);}



object MFvfun_key(sym,self,argd,data,keys)
     object sym,data;
     int argd,(*self)();
     char *keys;
{if (data) set_key_struct(keys,data);
 return MFvfun(sym,self,argd,data);
}

siLmfvfun_key() 
{MFvfun_key(vs_base[0],PADDR(vs_base[1]),fix(vs_base[2]),siSPmemory->s.s_dbind,PADDR(vs_base[3]));}


object MFnew(sym,self,data)
     object sym,data;
 int (*self)();
{
	object cf;

	if (type_of(sym) != t_symbol)
		not_a_symbol(sym);
	if (sym->s.s_sfdef != NOT_SPECIAL && sym->s.s_mflag)
		sym->s.s_sfdef = NOT_SPECIAL;
	cf = alloc_object(t_cfun);
	cf->cf.cf_self = self;
	cf->cf.cf_name = sym;
	cf->cf.cf_data = data;
	sym = clear_compiler_properties(sym,cf);
 	sym->s.s_gfdef = cf;
	sym->s.s_mflag = FALSE;
}

siLmf()
{MFnew(vs_base[0],PADDR(vs_base[1]),siSPmemory->s.s_dbind);}


object
MF(sym, self, start, size, data)
object sym;
int (*self)();
char *start;
int size;
object data;
{ if(data && type_of(data)==t_cfdata)
	  { data->cfd.cfd_start=start; 
	    data->cfd.cfd_size=size;}
	  else if(size) FEerror(0,"Bad call to make_cfun");
  return(MFnew(sym,self,data));
}

object
MM(sym, self, start, size, data)
object sym;
int (*self)();
char *start;
int size;
object data;
{
	object cf;

	if (type_of(sym) != t_symbol)
		not_a_symbol(sym);
	if (sym->s.s_sfdef != NOT_SPECIAL && sym->s.s_mflag)
		sym->s.s_sfdef = NOT_SPECIAL;
	cf = alloc_object(t_cfun);
	cf->cf.cf_self = self;
	cf->cf.cf_name = sym;
	cf->cf.cf_data = data;
	data->cfd.cfd_start=start; 
	data->cfd.cfd_size=size;
	sym = 	clear_compiler_properties(sym,cf);
	sym->s.s_gfdef = cf;
	sym->s.s_mflag = TRUE;
}

siLmm()
{MM(vs_base[0],PADDR(vs_base[1]),
    /* bit wasteful to pass these in just to be reset to themselves..*/
    siSPmemory->s.s_dbind->cfd.cfd_start,
    siSPmemory->s.s_dbind->cfd.cfd_size,
    siSPmemory->s.s_dbind
    );}

  

object
make_function(s, f)
char *s;
int (*f)();
{
	object x;
	vs_mark;

	x = make_ordinary(s);
	vs_push(x);
	x->s.s_gfdef = make_cfun(f, x, Cnil, NULL, 0);
	x->s.s_mflag = FALSE;
	vs_reset;
	return(x);
}

object
make_si_sfun(s, f,argd)
char *s;
int (*f)();
int argd;
{  object x= make_si_ordinary(s);
   x->s.s_gfdef = make_sfun( x,f,argd, Cnil);
   x->s.s_mflag = FALSE;
   return(x);
}

object
make_si_vfun1(s, f,argd)
char *s;
int (*f)();
int argd;
{  object x= make_si_ordinary(s);
   x->s.s_gfdef = make_vfun( x,f,argd, Cnil);
   x->s.s_mflag = FALSE;
   return(x);
}


object
make_si_function(s, f)
char *s;
int (*f)();
{
	object x;
	vs_mark;

	x = make_si_ordinary(s);
	vs_push(x);
	x->s.s_gfdef = make_cfun(f, x, Cnil, NULL, 0);
	x->s.s_mflag = FALSE;
	vs_reset;
	return(x);
}




object
make_special_form(s, f)
char *s;
int (*f)();
{
	object x;
	x = make_ordinary(s);
	x->s.s_sfdef = f;
	return(x);
}

siLcompiled_function_name()
{
	check_arg(1);
	switch(type_of(vs_base[0])) {
	case t_cfun:
	case t_sfun:
	case t_vfun:
	case t_cclosure:
	case t_gfun:
	  vs_base[0] = vs_base[0]->cf.cf_name;
	  break;
	default:
	  FEerror("~S is not a compiled-function.", 1, vs_base[0]);
}}

turbo_closure(fun)
object fun;
{
  object l,*block;
  int n;

  if(fun->cc.cc_turbo==NULL)
    {for (n = 0, l = fun->cc.cc_env;  !endp(l);  n++, l = l->c.c_cdr);
     block= AR_ALLOC(alloc_contblock,(1+n),object);
     *block=make_fixnum(n);
     fun->cc.cc_turbo = block+1; /* equivalent to &block[1] */
     for (n = 0, l = fun->cc.cc_env;  !endp(l);  n++, l = l->c.c_cdr)
       fun->cc.cc_turbo[n] = l;}
}

siLturbo_closure()
{
	check_arg(1);
	if (type_of(vs_base[0]) == t_cclosure)
		turbo_closure(vs_base[0]);
}



init_cfun()
{
	make_si_function("COMPILED-FUNCTION-NAME",
			 siLcompiled_function_name);
	make_si_function("TURBO-CLOSURE", siLturbo_closure);
	make_si_function("MFSFUN",siLmfsfun);
	make_si_function("MFVFUN",siLmfvfun);
	make_si_function("MF",siLmf);
	make_si_function("MFVFUN-KEY",siLmfvfun_key);
	make_si_function("MM",siLmm);
	make_si_function("MC",siLmc);
	
}

