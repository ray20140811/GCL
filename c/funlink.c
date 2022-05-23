/*  Copyright William Schelter. All rights reserved.
Fast linking method for kcl by W. Schelter University of Texas
   Note there are also changes to 
 cmpcall.lsp and cmptop.lsp */


#include "include.h"
#include "sfun_argd.h"


object siLcdefn;
typedef object (*object_func)();

object Vlink_array;
int Rset = 0;

void
call_or_link(sym,link)
int *link;
object sym;
{object fun;
 fun = sym->s.s_gfdef;
 if (fun == OBJNULL) {FEinvalid_function(sym); return;}
 if (type_of(fun) == t_cclosure
     && (fun->cc.cc_turbo))
   {if (Rset==0) {MMccall(fun, fun->cc.cc_turbo);}
    else (*(fun)->cf.cf_self)(fun->cc.cc_turbo);
    return;}
 if (Rset==0) funcall(fun);
   else
   if (type_of(fun) == t_cfun)
       { (void) vpush_extend((int) link,Vlink_array->s.s_dbind);
	  (void) vpush_extend((int) *link,Vlink_array->s.s_dbind);	 
         *link = (int) (fun->cf.cf_self);
	 (*(void (*)())(fun->cf.cf_self))();
       }
   else funcall(fun);}

void
call_or_link_closure(sym,link,ptr)
int *link;
object sym;
object *ptr;
{object fun;
 fun = sym->s.s_gfdef;
 if (fun == OBJNULL) {FEinvalid_function(sym); return;}
 if (type_of(fun) == t_cclosure
     && (fun->cc.cc_turbo))
   {if (Rset) {
     (void) vpush_extend((int) link,Vlink_array->s.s_dbind);
     (void) vpush_extend((int) *link,Vlink_array->s.s_dbind);
     *ptr = (void *)(fun->cc.cc_turbo);
     *link = (int) (fun->cf.cf_self);
     MMccall(fun, fun->cc.cc_turbo);}
    else
      {MMccall(fun, fun->cc.cc_turbo);}
    return;}
 if (Rset==0) funcall(fun);
   else
     /* can't do this if invoking foo(a) is illegal when foo is not defined
	to take any arguments.   In the majority of C's this is legal */
     
   if (type_of(fun) == t_cfun)
       { (void) vpush_extend((int) link,Vlink_array->s.s_dbind);
	  (void) vpush_extend((int) *link,Vlink_array->s.s_dbind);	 
         *link = (int) (fun->cf.cf_self);
	 (*(void (*)())(fun->cf.cf_self))();
       }
   else funcall(fun);}

/* for pushing item into an array, where item is an address if array-type = t
or a fixnum if array-type = fixnum */

vpush_extend(item,ar)
int item; object ar;
{ register int ind = ar->v.v_fillp;
  if (ind < ar->fixa.fixa_dim)
   {ar->fixa.fixa_self[ind] = item;
    return(ar->v.v_fillp = ++ind);}
       else
    { register int *oldp ;
      int newdim=(2 + (int) (1.3 * ind));
      char *newself;
      newself=alloc_relblock(sizeof(int)*newdim);
      oldp= ar->fixa.fixa_self;
      ar->fixa.fixa_dim=newdim;
      ar->fixa.fixa_self=(fixnum *)newself;
      
     /* this should be ok since the gc may be called at allocself, but when the
actual allocation takes place, the array is still pointing to its old body,
and the gc will not be called while we run through copying */
     {register int *p = ar->fixa.fixa_self;
      register int *last ;
      last =  (p + ind);
      while ( p < last)
	*p++ = *oldp++;
      *p=item;}
      return(++(ar->v.v_fillp));
    }
  
   }

/* if we unlink a bunch of functions, this will mean there are some
   holes in the link array, and we should probably go through it and
   push them back  */
static int number_unlinked=0;

Luse_fast_links()
{use_fast_links(vs_top-vs_base,vs_base[0],vs_top[-1]);}

delete_link(address,link_ar) 
     int address;
     object link_ar;
{int *ar,*ar_end,*p;
 p=0;
 ar = link_ar->fixa.fixa_self;
 ar_end = ar +   link_ar->v.v_fillp;
 while (ar < ar_end)
   { if (*ar && *((int *)*ar)==address)
       { p = (int *) *ar;
	 *ar=0;
	 *p = *(ar+1);
	 number_unlinked++;}
     ar=ar+2;}
 if (number_unlinked > 40)
   link_ar->v.v_fillp=
     clean_link_array(link_ar->fixa.fixa_self,ar_end); }


use_fast_links(n,flag,sym)
     int n;
     object sym,flag;
     
{ register int  *ar,*ar_end;
  int *p;
  object link_ar;
  object fun;

  link_ar = Vlink_array->s.s_dbind;
  if (link_ar==Cnil && flag==Cnil) return 0;
  check_type_array(&link_ar);
  ar = link_ar->fixa.fixa_self;
  ar_end = ar +   link_ar->v.v_fillp;
    switch (n)
      {
  case 1:
   if (flag==Cnil)
    { Rset=0;
     while ( ar < ar_end)
      /* set the link variables back to initial state */
	 { 
	    p = (int *) *ar;
	    if (p) *p = (ar++, *ar); else ar++;
	   ar++;
	 }
    link_ar->v.v_fillp = 0;
    }
  else
    { Rset=1;}
    break;
  case 2:
   if (!(type_of(sym)==t_symbol)) not_a_symbol(sym);
   fun = sym->s.s_gfdef;
   goto BEGIN;
 case 3:
   fun = sym;
 BEGIN:
   if(Rset)
     {
      if(!fun) return 0;
      switch(type_of(fun)){
      case t_cfun:
      case t_sfun:
      case t_vfun:	
      case t_gfun:
      case t_cclosure:
	delete_link((int)fun->cf.cf_self,link_ar);
	/* becoming obsolete 
	 y=getf(sym->s.s_plist,siLcdefn,Cnil);
	 if (y!=Cnil)
	   delete_link(fix(y),link_ar);
	   */

      break;
    
    }
  }
    break;
  default:
    FEerror("Usage: (use-fast-links {nil,t} &optional fun)",0);
   return(0);
}
}


clean_link_array(ar,ar_end)
int *ar,*ar_end;
{int i=0;
 int *orig;
 orig=ar;
 number_unlinked=0;
  while( ar<ar_end)
   {if(*ar)
      {orig[i++]= *ar++ ;
	 orig[i++]= *ar++;
       }
   else ar=ar+2;       
    }
 return(i);
 }

#include <varargs.h>

object
c_apply_n(fn,n,x)
     object *x;
     int n;
     object (*fn)();
{object res;
 switch(n){
    case 0:  res=(*fn)();break;
    case 1:  res=(*fn)(x[0]);break;
    case 2:  res=(*fn)(x[0],x[1]);break;
    case 3:  res=(*fn)(x[0],x[1],x[2]);break;
    case 4:  res=(*fn)(x[0],x[1],x[2],x[3]);break;
    case 5:  res=(*fn)(x[0],x[1],x[2],x[3],x[4]);break;
    case 6:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5]);break;
    case 7:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6]);break;
    case 8:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7]);break;
    case 9:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8]);break;
    case 10:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9]);break;
    case 11:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10]);break;
    case 12:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11]);break;
    case 13:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12]);break;
    case 14:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13]);break;
    case 15:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14]);break;
    case 16:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15]);break;
    case 17:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16]);break;
    case 18:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17]);break;
    case 19:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18]);break;
    case 20:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19]);break;
    case 21:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20]);break;
    case 22:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21]);break;
    case 23:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22]);break;
    case 24:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23]);break;
    case 25:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24]);break;
    case 26:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25]);break;
    case 27:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26]);break;
    case 28:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27]);break;
    case 29:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28]);break;
    case 30:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29]);break;
    case 31:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30]);break;
    case 32:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31]);break;
    case 33:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32]);break;
    case 34:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33]);break;
    case 35:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34]);break;
    case 36:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35]);break;
    case 37:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36]);break;
    case 38:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37]);break;
    case 39:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38]);break;
    case 40:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39]);break;
    case 41:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40]);break;
    case 42:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41]);break;
    case 43:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42]);break;
    case 44:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42],
         x[43]);break;
    case 45:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42],
         x[43],x[44]);break;
    case 46:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42],
         x[43],x[44],x[45]);break;
    case 47:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42],
         x[43],x[44],x[45],x[46]);break;
    case 48:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42],
         x[43],x[44],x[45],x[46],x[47]);break;
    case 49:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42],
         x[43],x[44],x[45],x[46],x[47],x[48]);break;
    case 50:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42],
         x[43],x[44],x[45],x[46],x[47],x[48],x[49]);break;
    case 51:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42],
         x[43],x[44],x[45],x[46],x[47],x[48],x[49],
         x[50]);break;
    case 52:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42],
         x[43],x[44],x[45],x[46],x[47],x[48],x[49],
         x[50],x[51]);break;
    case 53:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42],
         x[43],x[44],x[45],x[46],x[47],x[48],x[49],
         x[50],x[51],x[52]);break;
    case 54:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42],
         x[43],x[44],x[45],x[46],x[47],x[48],x[49],
         x[50],x[51],x[52],x[53]);break;
    case 55:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42],
         x[43],x[44],x[45],x[46],x[47],x[48],x[49],
         x[50],x[51],x[52],x[53],x[54]);break;
    case 56:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42],
         x[43],x[44],x[45],x[46],x[47],x[48],x[49],
         x[50],x[51],x[52],x[53],x[54],x[55]);break;
    case 57:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42],
         x[43],x[44],x[45],x[46],x[47],x[48],x[49],
         x[50],x[51],x[52],x[53],x[54],x[55],x[56]);break;
    case 58:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42],
         x[43],x[44],x[45],x[46],x[47],x[48],x[49],
         x[50],x[51],x[52],x[53],x[54],x[55],x[56],
         x[57]);break;
    case 59:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42],
         x[43],x[44],x[45],x[46],x[47],x[48],x[49],
         x[50],x[51],x[52],x[53],x[54],x[55],x[56],
         x[57],x[58]);break;
    case 60:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42],
         x[43],x[44],x[45],x[46],x[47],x[48],x[49],
         x[50],x[51],x[52],x[53],x[54],x[55],x[56],
         x[57],x[58],x[59]);break;
    case 61:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42],
         x[43],x[44],x[45],x[46],x[47],x[48],x[49],
         x[50],x[51],x[52],x[53],x[54],x[55],x[56],
         x[57],x[58],x[59],x[60]);break;
    case 62:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42],
         x[43],x[44],x[45],x[46],x[47],x[48],x[49],
         x[50],x[51],x[52],x[53],x[54],x[55],x[56],
         x[57],x[58],x[59],x[60],x[61]);break;
    case 63:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42],
         x[43],x[44],x[45],x[46],x[47],x[48],x[49],
         x[50],x[51],x[52],x[53],x[54],x[55],x[56],
         x[57],x[58],x[59],x[60],x[61],x[62]);break;
    case 64:  res=(*fn)(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],
         x[8],x[9],x[10],x[11],x[12],x[13],x[14],
         x[15],x[16],x[17],x[18],x[19],x[20],x[21],
         x[22],x[23],x[24],x[25],x[26],x[27],x[28],
         x[29],x[30],x[31],x[32],x[33],x[34],x[35],
         x[36],x[37],x[38],x[39],x[40],x[41],x[42],
         x[43],x[44],x[45],x[46],x[47],x[48],x[49],
         x[50],x[51],x[52],x[53],x[54],x[55],x[56],
         x[57],x[58],x[59],x[60],x[61],x[62],x[63]);break;
  default: FEerror("Exceeded call-arguments-limit ");
  } 

 return res;
}
  
/* Used for calling cfunctions which take object args, and return object 
value.  This function is called by the static lnk function in the reference
file */

object
call_proc(sym,link,argd,ll)
object sym;
int argd, *link;
va_list ll;
{object fun;
 int nargs;
 check_type_symbol(&sym);
 fun=sym->s.s_gfdef;
 if (fun && (type_of(fun)==t_sfun
	     || type_of(fun)==t_gfun
	     || type_of(fun)== t_vfun)
	     && Rset) /* the && Rset is to allow tracing */
   {object_func fn;
    fn =  (object_func) fun->sfn.sfn_self;
    if (type_of(fun)==t_vfun)
      { /* argd=VFUN_NARGS; */ /*remove this! */
	nargs=SFUN_NARGS(argd);
	if (nargs < fun->vfn.vfn_minargs || nargs > fun->vfn.vfn_maxargs
	    || (argd & (SFUN_ARG_TYPE_MASK | SFUN_RETURN_MASK)))
	 goto WRONG_ARGS;
	if ((VFUN_NARG_BIT & argd) == 0)
	 /* don't link */
	 { 
	   VFUN_NARGS = nargs;
	   goto   AFTER_LINK;
	 }
      }
    else /* t_gfun,t_sfun */
      { nargs= SFUN_NARGS(argd);
	if ((argd & (~VFUN_NARG_BIT)) != fun->sfn.sfn_argd) 
	WRONG_ARGS:    
	  FEerror("Arg or result mismatch in call to  ~s",1,sym);
      }
   
    (void) vpush_extend((int) link,Vlink_array->s.s_dbind);
    (void) vpush_extend((int) *link,Vlink_array->s.s_dbind);	 
    *link = (int)fn;
  AFTER_LINK:	
 
    if (nargs < 10) 
    /* code below presumes sizeof(int) == sizeof(object)
       Should probably not bother special casing the < 10 args
     */
      {object x0,x1,x2,x3,x4,x5,x6,x7,x8,x9;    
       if (nargs-- > 0)
	 x0=va_arg(ll,object);
       else
	 {return((*fn)());}
       if (nargs-- > 0)
	 x1=va_arg(ll,object);
       else
	 { return((*fn)(x0));}
       if (nargs-- > 0)
	 x2=va_arg(ll,object);
       else
	 {return((*fn)(x0,x1));}
       if (nargs-- > 0)  x3=va_arg(ll,object);
       else
	 return((*fn)(x0,x1,x2));
       if (nargs-- > 0)  x4=va_arg(ll,object);
       else
	 return((*fn)(x0,x1,x2,x3));
       if (nargs-- > 0)  x5=va_arg(ll,object);
       else
	 return((*fn)(x0,x1,x2,x3,x4));
       if (nargs-- > 0)  x6=va_arg(ll,object);
       else
	 return((*fn)(x0,x1,x2,x3,x4,x5));
       if (nargs-- > 0)  x7=va_arg(ll,object);
       else
	 return((*fn)(x0,x1,x2,x3,x4,x5,x6));
       if (nargs-- > 0)  x8=va_arg(ll,object);
       else
	 return((*fn)(x0,x1,x2,x3,x4,x5,x6,x7));
       if (nargs-- > 0)  x9=va_arg(ll,object);
       else
	 return((*fn)(x0,x1,x2,x3,x4,x5,x6,x7,x8));
       return((*fn)(x0,x1,x2,x3,x4,x5,x6,x7,x8,x9));
 
     }
  else {object *new;
	COERCE_VA_LIST(new,ll,nargs);
	return(c_apply_n(fn,nargs,new));}
  }
 else				/* there is no cdefn property */
regular_call:
   { 
     object fun;
     register object *base;
     enum ftype result_type;
     /* we check they are valid functions before calling this */
     if(type_of(sym)==t_symbol) fun = symbol_function(sym);
     else fun = sym;
     vs_base= (base =   vs_top);
     if (fun == OBJNULL) FEinvalid_function(sym);
     /* push the args */
/*     if (type_of(fun)==t_vfun) argd=fcall.argd; */ /*remove this! */
     nargs=SFUN_NARGS(argd);
     result_type=SFUN_RETURN_TYPE(argd);
     argd=SFUN_START_ARG_TYPES(argd);
     {int i=0;
      if (argd==0)
	{while(i < nargs)
	    {vs_push(va_arg(ll,object));
	     i++;}}
      else
	{while(i < nargs)
	    {enum ftype typ=SFUN_NEXT_TYPE(argd);
	      vs_push((typ==f_object? va_arg(ll,object):
		       make_fixnum(va_arg(ll,int))));
	     i++;}}
    }

     vs_check;
     
     funcall(fun);
      vs_top=base;
	/* vs_base=oldbase;
      The caller won't expect us to restore these.  */
     return((result_type==f_object? vs_base[0] : (object)fix(vs_base[0])));
   }
}


object call_vproc(sym,link,ll)
object sym;
int *link;
va_list ll;     
{return call_proc(sym,link,VFUN_NARGS | VFUN_NARG_BIT,ll);}

object
call_proc0(sym,link)
object sym;
int *link;
{return call_proc(sym,link,0,0);}

object
call_proc1(sym,link,x0)
     object sym,x0;int *link;
     
{return (call_proc(sym,link,1,x0));}

object
call_proc2(sym,link,x0,x1)
     object sym,x0,x1;int *link;
{return (call_proc(sym,link,2,x0,x1));}


   

object
ifuncall(sym,n,va_alist)
object sym; int n;
va_dcl
{ va_list ap;
  int i;
  object *old_vs_base;
  object *old_vs_top;
  object x;
  old_vs_base = vs_base;
  old_vs_top = vs_top;
  vs_base = old_vs_top;
  vs_top=old_vs_top+n;
  vs_check;
  va_start(ap);
  for(i=0;i<n;i++)
    old_vs_top[i]= va_arg(ap,object);
  va_end(ap);
  if (type_of(sym->s.s_gfdef)==t_cfun)
    (*(sym->s.s_gfdef)->cf.cf_self)();
  else  super_funcall(sym);
/*   funcall(sym->s.s_gfdef);*/
  x = vs_base[0];
  vs_top = old_vs_top;
  vs_base = old_vs_base;
  return(x);
}


object
imfuncall(sym,n,va_alist)
object sym; int n;
va_dcl
{ va_list ap;
  int i;
  object *old_vs_top;
  old_vs_top = vs_top;
  vs_base = old_vs_top;
  vs_top=old_vs_top+n;
  vs_check;
  va_start(ap);
  for(i=0;i<n;i++)
    old_vs_top[i]= va_arg(ap,object);
  va_end(ap);
  if (type_of(sym->s.s_gfdef)==t_cfun)
    (*(sym->s.s_gfdef)->cf.cf_self)();
  else  super_funcall(sym);
/*   funcall(sym->s.s_gfdef);*/
  return(vs_base[0]);
}

/* go from beg+1 below limit setting entries equal to 0 until you
   come to FRESH 0's . */

#define FRESH 40

clear_stack(beg,limit)
object *beg,*limit;
{int i=0;
 while (++beg < limit)
  {if (*beg==0) i++;
   if (i > FRESH) return 0;
   ;*beg=0;} return 0;}

object
set_mv(i,val)
     int i;
     object val;
{ if (i >= (sizeof(MVloc)/sizeof(object)))
     FEerror("Bad mv index");
  return(MVloc[i]=val);
}

object
mv_ref(i)
     unsigned int i;
{ if (i >= (sizeof(MVloc)/sizeof(object)))
     FEerror("Bad mv index");
  return (MVloc[i]);
}

#include "xdrfuns.c"

init_links()
{	Vlink_array = (object) make_special("*LINK-ARRAY*",Cnil);
	make_function("USE-FAST-LINKS", Luse_fast_links);
	siLcdefn=make_si_ordinary("CDEFN");
	make_si_sfun("SET-MV",set_mv, ARGTYPE2(f_fixnum,f_object) |
		     RESTYPE(f_object));
	make_si_sfun("MV-REF",mv_ref, ARGTYPE1(f_fixnum) | RESTYPE(f_object));
	init_xdrfuns();
	      }

