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

	cmpaux.c
*/

#include "include.h"
#include "mp.h"
#define dcheck_type(a,b) check_type(a,b)

siLspecialp()
{
	object sym;

	check_arg(1);
	sym = vs_base[0];
	if (type_of(sym) == t_symbol &&
	    (enum stype)sym->s.s_stype == stp_special)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}



object siSPinit;
object siSPmemory;
object siSdebug;
void
siLdefvar1()
{int n=vs_top-vs_base;
 if(vs_base[0]->s.s_dbind==0 && n > 1)
   vs_base[0]->s.s_dbind= vs_base[1];
 vs_base[0]->s.s_stype=(short)stp_special;
 if(n > 2)
 putprop(vs_base[0],vs_base[2],siSvariable_documentation);
 vs_top=vs_base+1;
}

void
siLdebug()
{putprop(vs_base[0],vs_base[1],siSdebug);}

void
siLsetvv()
{ if(type_of(siSPmemory->s.s_dbind)==t_cfdata)
  siSPmemory->s.s_dbind->cfd.cfd_self[fix(vs_base[0])]=vs_base[1];
  else FEerror("setvv called outside %init");
}


void Lidentity();
init_cmpaux()
{
        siSPmemory=make_si_special("%MEMORY",Cnil);
        siSPinit=make_si_special("%INIT",Cnil);
	make_si_function("SPECIALP",siLspecialp);
	make_si_function("DEFVAR1",siLdefvar1);
	/* real one defined in predlib.lsp, need this for bootstrap */
	make_si_function("WARN-VERSION",Lidentity);
	siSdebug=make_si_function("DEBUG",siLdebug);
	make_si_function("SETVV",siLsetvv);
	
}

  
int
ifloor(x, y)
int x, y;
{
	if (y == 0)
		FEerror("Zero divizor", 0);
	else if (y > 0)
		if (x >= 0)
			return(x/y);
		else
			return(-((-x+y-1))/y);
	else
		if (x >= 0)
			return(-((x-y-1)/(-y)));
		else
			return((-x)/(-y));
}

int
imod(x, y)
int x, y;
{
	return(x - ifloor(x, y)*y);
}

set_VV_data(VV,n,data,start,size)
object VV[],data;
int size,n;
char *start;
{set_VV(VV,n,data);
 data->cfd.cfd_start=start;
 data->cfd.cfd_size = size;
}

set_VV(VV, n, data)
object VV[];
int n;
object data;
{
	object *p, *q;

	p = VV;
	q = data->v.v_self;
	while (n-- > 0)
		*p++ = *q++;
	data->cfd.cfd_self = VV;
}

/*
	Conversions to C
*/

char
object_to_char(x)
object x;
{
	int c;

	switch (type_of(x)) {
	case t_fixnum:
		c = fix(x);  break;
	case t_bignum:
		c = (char)MP_LOW(MP(x),lgef(MP(x)));  break;
	case t_character:
		c = char_code(x);  break;
	default:
		FEerror("~S cannot be coerce to a C char.", 1, x);
	}
	return(c);
}

int
object_to_int(x)
object x;
{
	int i;

	switch (type_of(x)) {
	case t_character:
		i = char_code(x);  break;
	case t_fixnum:
		i = fix(x);  break;
	case t_bignum:
		i = MP_LOW(MP(x),lgef(MP(x))) * big_sign(x);  break;
	case t_ratio:
		i = number_to_double(x);  break;
	case t_shortfloat:
		i = sf(x);  break;
	case t_longfloat:
		i = lf(x);  break;
	default:
		FEerror("~S cannot be coerce to a C int.", 1, x);
	}
	return(i);
}

float
object_to_float(x)
object x;
{
	float f;

	switch (type_of(x)) {
	case t_character:
		f = char_code(x);  break;
	case t_fixnum:
		f = fix(x);  break;
	case t_bignum:
	case t_ratio:
		f = number_to_double(x);  break;
	case t_shortfloat:
		f = sf(x);  break;
	case t_longfloat:
		f = lf(x);  break;
	default:
		FEerror("~S cannot be coerce to a C float.", 1, x);
	}
	return(f);
}

double
object_to_double(x)
object x;
{
	double d;

	switch (type_of(x)) {
	case t_character:
		d = char_code(x);  break;
	case t_fixnum:
		d = fix(x);  break;
	case t_bignum:
	case t_ratio:
		d = number_to_double(x);  break;
	case t_shortfloat:
		d = sf(x);  break;
	case t_longfloat:
		d = lf(x);  break;
	default:
		FEerror("~S cannot be coerce to a C double.", 1, x);
	}
	return(d);
}

/* this may allocate storage.  The user can prevent this
   by providing a string will fillpointer < length and
   have a null character in the fillpointer position. */

char *malloc();

char *
object_to_string(x)
     object x;
{ unsigned int leng;
  if (type_of(x)!=t_string) FEwrong_type_argument(Sstring,x);
  leng= x->st.st_fillp;
  /* user has thoughtfully provided a null terminated string ! */
    if (leng > 0 && leng < x->st.st_dim && x->st.st_self[leng]==0)
    return x->st.st_self;
  if (x->st.st_dim == leng
      && ( leng % sizeof(object))
     )
    { x->st.st_self[leng] = 0;
      return x->st.st_self;
    }
  else
    {char *res=malloc(leng+1);
     bcopy(x->st.st_self,res,leng);
     res[leng]=0;
     return res;
   }}


typedef int (*FUNC)();

/* perform the actual invocation of the init function durint a fasload
   init_address is the offset from the place in memory where the code is loaded
   in.  In most systems this will be 0.
   The new style fasl vector MUST end with an entry (si::%init f1 f2 .....)
   where f1 f2 are forms to be evaled.
*/

call_init(init_address,memory,fasl_vec)
     int init_address;
     object memory,fasl_vec;
       
{object form;
 FUNC at;

  check_type(fasl_vec,t_vector);
  form=(fasl_vec->v.v_self[fasl_vec->v.v_fillp -1]);
 at=(FUNC)(memory->cfd.cfd_start+ init_address );
 
#ifdef VERIFY_INIT
 VERIFY_INIT
#endif
   
 if (type_of(form)==t_cons &&
     form->c.c_car == siSPinit)
   {bds_bind(siSPinit,fasl_vec);
    bds_bind(siSPmemory,memory);
    (*at)();
    bds_unwind1;
    bds_unwind1;
  }
 else
   /* old style three arg init, with all init being done by C code. */
   {memory->cfd.cfd_self = fasl_vec->v.v_self;
    memory->cfd.cfd_fillp = fasl_vec->v.v_fillp;
    (*at)(memory->cfd.cfd_start, memory->cfd.cfd_size, memory);
}}

/* statVV is the address of some static storage, which is used by the
   cfunctions to refer to global variables,..
   Initially it holds a number of addresses.   We also have siSPmemory->s.s_dbind
   which points to a vector  of lisp constants.   We switch the
   fn addresses and lisp constants.   We follow this convoluted path,
   since we don't wish to have a separate block of data space allocated
   in the object module simply to temporarily have access to the
   actual function addresses during load. 

   */

do_init(statVV)
     object *statVV;
     
{object fasl_vec=siSPinit->s.s_dbind;
 object data = siSPmemory->s.s_dbind;
 {object *p,*q,x,y;
  int n=fasl_vec->v.v_fillp -1;
  int i;
  object form;
  check_type(fasl_vec,t_vector);
  form = fasl_vec->v.v_self[n];
  dcheck_type(form,t_cons);  


  /* switch SPinit to point to a vector of function addresses */
     
  fasl_vec->v.v_elttype = aet_fix;
  
  /* swap the entries */
  p = fasl_vec->v.v_self;
  q = statVV;
  for (i=0; i<=n ; i++)
    {  y = *p;
     *p++ = *q;
     *q++ = y;
     }
  
  data->cfd.cfd_self = statVV;
  data->cfd.cfd_fillp= n+1;
  statVV[n] = data;
  

  /* So now the fasl_vec is a fixnum array, containing random addresses of c
     functions and other stuff from the compiled code.
     data is what it wants to be for the init
  */
  /* Now we can run the forms f1 f2 in form= (%init f1 f2 ...) */

  form=form->c.c_cdr;
  {object *top=vs_top;
   
   for(i=0 ; i< form->v.v_fillp; i++)
     { 
       eval(form->v.v_self[i]);
       vs_top=top;
     }
 }
}}

#ifdef DOS
#define PATH_LIM 8
#define TYPE_LIM 3
char *
fix_path_string_dos(s)
char *s;
{char buf[200];
 char *p=s,*q=buf;
 int i=PATH_LIM;	
 while(*p)
  {
   if (IS_DIR_SEPARATOR(*p)) i=PATH_LIM;
    else if (*p == '.') i = TYPE_LIM;
    else i--;
   if (i>=0) *q++ = *p;
   p++;}
 *q = 0;
 strcpy(s,buf);
 return s;
}
	
#endif

void
init_or_load1(fn,file)
     int (*fn)();
     char *file;
{int n=strlen(file);
 if (file[n-1]=='o')
   { object memory;
     object fasl_data;
     file=FIX_PATH_STRING(file);

     memory=alloc_object(t_cfdata);
     memory->cfd.cfd_self=0;
     memory->cfd.cfd_fillp=0;
     memory->cfd.cfd_size = 0;
     printf("Initializing %s\n",file); fflush(stdout);
     fasl_data = read_fasl_data(file);
     memory->cfd.cfd_start= (char *)fn;
     call_init(0,memory,fasl_data);
  }
 else
  {printf("loading %s\n",file); fflush(stdout);  load(file);}
}

  

  
  
     
  
  
 

    
    
   
