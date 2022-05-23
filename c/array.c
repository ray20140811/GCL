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
	array.c

	array routines
*/

#include "include.h"

#define	ADIMLIM		16*1024*1024
#define	ATOTLIM		16*1024*1024
#define WSIZE  CHAR_SIZE*sizeof(fixnum)

enum aelttype
get_aelttype(x)
object x;
{
	if (x == Sstring_char)
		return(aet_ch);
	else if (x == Sbit)
		return(aet_bit);
	else if (x == Sfixnum)
		return(aet_fix);
	else if (x == Sshort_float)
		return(aet_sf);
	else if (x == Slong_float || x == Ssingle_float || x==Sdouble_float)
		return(aet_lf);
	else if (x == Sunsigned_char)
	  return(aet_uchar);
	else if (x == Sunsigned_short)
	  return(aet_ushort);
	else if (x == Ssigned_char)
	  return(aet_char);
	else if (x == Ssigned_short)
	  return(aet_short);
	else
		return(aet_object);
}

enum aelttype
array_elttype(x)
object x;
{
	switch(type_of(x)) {
	case t_array:
	case t_vector:
		return((enum aelttype)x->a.a_elttype);

	case t_string:
		return(aet_ch);

	case t_bitvector:
		return(aet_bit);

	default:
		FEwrong_type_argument(Sarray, x);
	}
}

char *
array_address(x, inc)
object x;
int inc;
{
	switch(array_elttype(x)) {
	case aet_object:
	case aet_fix:
	case aet_sf:
		return((char *)(x->a.a_self + inc));

        case aet_char:
        case aet_uchar:
	case aet_ch:
		return(x->st.st_self + inc);

        case aet_short:
        case aet_ushort:
		return ((char *)&(USHORT(x,inc)));

	case aet_lf:
		return((char *)(x->lfa.lfa_self + inc));
	      default:
		FEerror("Bad array type",0);
	}
}

static object DFLT_aet_object = Cnil;	
static char DFLT_aet_ch = ' ';
static char DFLT_aet_char = 0; 
static int DFLT_aet_fix = 0  ;		
static short DFLT_aet_short = 0;
static shortfloat DFLT_aet_sf = 0.0;
static longfloat DFLT_aet_lf = 0.0;	

char * default_aet_types[] =
{   (char *)	&DFLT_aet_object,		/*  t  */
    (char *)	&DFLT_aet_ch,			/*  string-char  */
    (char *)	&DFLT_aet_fix,		/*  bit  */
    (char *)	&DFLT_aet_fix,		/*  fixnum  */
    (char *)	&DFLT_aet_sf,			/*  short-float  */
    (char *)	&DFLT_aet_lf,			/*  long-float  */
    (char *)	&DFLT_aet_char,               /* signed char */
    (char *)    &DFLT_aet_char,               /* unsigned char */
    (char *)	&DFLT_aet_short,              /* signed short */
    (char *)	&DFLT_aet_short,             /*  unsigned short   */
	};

   /* RAW_AET_PTR returns a pointer to something of raw type obtained from X
      suitable for using GSET for an array of elt type TYP.
      If x is the null pointer, return a default for that array element
      type.
      */

char *
raw_aet_ptr(x,typ)
     short typ;
     object x;
{  /* doubles are the largest raw type */
  static double u;
  if (x==Cnil) return default_aet_types[typ];
  switch (typ){
#define STORE_TYPED(pl,type,val) *((type *) pl) = (type) val; break;
  case aet_object: STORE_TYPED(&u,object,x);
  case aet_ch:     STORE_TYPED(&u,char, char_code(x));
  case aet_bit:    STORE_TYPED(&u,fixnum, -fix(x));
  case aet_fix:    STORE_TYPED(&u,fixnum, fix(x));
  case aet_sf:     STORE_TYPED(&u,shortfloat, sf(x));
  case aet_lf:     STORE_TYPED(&u,longfloat, lf(x));
  case aet_char:   STORE_TYPED(&u, char, fix(x));
  case aet_uchar:  STORE_TYPED(&u, unsigned char, fix(x));
  case aet_short:  STORE_TYPED(&u, short, fix(x));
  case aet_ushort: STORE_TYPED(&u,unsigned short,fix(x));
  default: FEerror("bad elttype",0);
  }
  return (char *)&u;
}


     /* GSET copies into array ptr P1, the value
	pointed to by the ptr VAL into the next N slots.  The
	array type is typ.  If VAL is the null ptr, use
	the default for that element type
	NOTE: for type aet_bit n is the number of Words
	ie (nbits +WSIZE-1)/WSIZE and the words are set.
	*/     

gset(p1,val,n,typ)
     char *p1,*val;
     int n;
     int typ;
{ if (val==0)
    val = default_aet_types[typ];
    switch (typ){

#define GSET(p,n,typ,val) {typ x = *((typ *) val); GSET1(p,n,typ,x)}
#define GSET1(p,n,typ,val) while (n-- > 0) \
      { *((typ *) p) = val; \
	  p = p + sizeof(typ); \
	  } break;

    case aet_object: GSET(p1,n,object,val);
    case aet_ch:     GSET(p1,n,char,val);
      /* Note n is number of fixnum WORDS for bit */
    case aet_bit:    GSET(p1,n,fixnum,val);
    case aet_fix:    GSET(p1,n,fixnum,val);
    case aet_sf:     GSET(p1,n,shortfloat,val);
    case aet_lf:     GSET(p1,n,longfloat,val);
    case aet_char:   GSET(p1,n,char,val);
    case aet_uchar:  GSET(p1,n,unsigned char,val);
    case aet_short:  GSET(p1,n,short,val);
    case aet_ushort: GSET(p1,n,unsigned short,val);
    default:         FEerror("bad elttype",0);
    }
  }

#ifndef COM_LENG
#define COM_LENG
#endif
extern short aet_sizes[COM_LENG];
#define W_SIZE (CHAR_SIZE*sizeof(fixnum))    
/*  This copies from p1 to p2 n elements of typ 
gcopy(p1,p2,n,typ)
char *p1,*p2;
int n,typ;
{ if(typ== (int)aet_bit)

    bcopy(p1,p2,(n+CHAR_SIZE-1)/CHAR_SIZE);
  else
    bcopy(p1,p2,n*aet_sizes[(int) typ]);
}
*/
  /* Copy n1 elements from x to y starting at x[i1]  to x[i2]
     If the types of the arrays are not the same, this has
     implementation dependent results.
   */
   
     
copy_array_portion(x,y,i1,i2,n1)
     object x,y; int i1,i2,n1;
{ enum aelttype typ1=array_elttype(vs_base[0]);
  enum aelttype typ2=array_elttype(vs_base[1]);
  int nc;
  if (typ1==aet_bit)
    {if (i1 % CHAR_SIZE)
     badcopy:
       FEerror("Bit copies only if aligned");
     else
       {int rest=n1%CHAR_SIZE;
	if (rest!=0 )
	  {if (typ2!=aet_bit)
	     goto badcopy;
	   {while(rest> 0)
	     { aset1(y,i2+n1-rest,(aref1(x,i1+n1-rest)));
	       rest--;}
	  }}
	i1=i1/CHAR_SIZE ;
	n1=n1/CHAR_SIZE;
	typ1=aet_char;
     }};
  if (typ2==aet_bit)
    {if (i2 % CHAR_SIZE)
       goto badcopy;
       i2=i2/CHAR_SIZE ;}
  if ((typ1 ==aet_object ||
       typ2  ==aet_object) && typ1 != typ2)
    FEerror("Can't copy between different array types");
  nc=n1 * aet_sizes[(int)typ1];
  if (i1+n1 > x->a.a_dim
      || ((y->a.a_dim - i2) *aet_sizes[(int)typ2]) < nc)
    FEerror("Copy  out of bounds");
  bcopy(x->ust.ust_self + (i1*aet_sizes[(int)typ1]),
	y->ust.ust_self + (i2*aet_sizes[(int)typ2]),
	nc);
}

/* Copy from X to Y starting at indices i1 and i2 and
   going optional N places (or array-total-size(x) -i1)
   if not specified
 */

siLcopy_array_portion()
{int n;
 if (vs_top-vs_base == 5)
   {n=fix(vs_base[4]);}
 else
   {check_arg(4);
    if(type_of(vs_base[3]) !=t_fixnum ||
     type_of(vs_base[2]) !=t_fixnum )
      FEerror("Need fixnum index");
    n= vs_base[0]->a.a_dim - fix(vs_base[2]);
  }
 copy_array_portion(vs_base[0],vs_base[1],fix(vs_base[2]),
		    fix(vs_base[3]),n);
  vs_top=vs_base+1;
}



/* X is the header of an array.  This supplies the body which
   will not be relocatable if STATICP.  If DFLT is 0, do not
   initialize (the caller promises to reset these before the
   next gc!).   If DFLT == Cnil then initialize to default type
   for this array type.   Otherwise DFLT is an object and its
   value is used to init the array */
   
array_allocself(x, staticp,dflt)
object x,dflt;
bool staticp;
{
	int i, d;
	char *(*f)(),*tmp_alloc;
	enum aelttype typ;

	d = x->a.a_dim;
	if (staticp)
		f = alloc_contblock;
	else
		f = alloc_relblock;
	typ=array_elttype(x);
	switch (typ) {
	case aet_object:
		x->a.a_self = AR_ALLOC(*f,d,object);
		break;
	case aet_ch:
	case aet_char:
        case aet_uchar:
		x->st.st_self = AR_ALLOC(*f,d,char);
		break;
        case aet_short:
        case aet_ushort:
		x->ust.ust_self = (unsigned char *) AR_ALLOC(*f,d,short);
		break;
	case aet_bit:
		d = (d+W_SIZE-1)/W_SIZE;
		x->bv.bv_offset = 0;
	case aet_fix:
		x->fixa.fixa_self = AR_ALLOC(*f,d,fixnum);
		break;
	case aet_sf:
		x->sfa.sfa_self = AR_ALLOC(*f,d,shortfloat);
		break;
	case aet_lf:
		x->lfa.lfa_self = AR_ALLOC(*f,d,longfloat);
		break;
	}
	if(dflt!=0) gset(x->st.st_self,raw_aet_ptr(dflt,typ),d,typ);
}

object
aref(x, index)
object x;
int index;
{
	if (index >= x->a.a_dim) {
		vs_push(make_fixnum(index));
		FEerror("The index, ~D, is too large.", 1, vs_head);
	}
	switch (array_elttype(x)) {
	case aet_object:
		return(x->a.a_self[index]);

	case aet_ch:
		return(code_char(x->ust.ust_self[index]));

	case aet_bit:
		index += x->bv.bv_offset;
		if (x->bv.bv_self[index/8] & (0200>>index%8))
			return(small_fixnum(1));
		else
			return(small_fixnum(0));

	case aet_fix:
		return(make_fixnum(x->fixa.fixa_self[index]));


#define UCHAR(x,index) ((x)->ust.ust_self[index])

	case aet_uchar:
		return(make_fixnum((fixnum)(UCHAR(x,index))));
  
	case aet_char:
		return(make_fixnum((fixnum)(SIGNED_CHAR(UCHAR(x,index)))));
        
        case aet_short:
	  return(make_fixnum((fixnum)(short)USHORT(x,index)));

        case aet_ushort:
	  return(make_fixnum((fixnum)USHORT(x,index)));

	case aet_sf:
		return(make_shortfloat(x->sfa.sfa_self[index]));

	case aet_lf:
		return(make_longfloat(x->lfa.lfa_self[index]));
	}
}

object
aset(x, index, value)
object x;
int index;
object value;
{
	int i;

	if (index >= x->a.a_dim) {
		vs_push(make_fixnum(index));
		FEerror("The index, ~D, too large.", 1, vs_head);
	}
	switch (array_elttype(x)) {
	case aet_object:
		x->a.a_self[index] = value;
		break;

	case aet_ch:
		if (type_of(value) != t_character)
			FEerror("~S is not a character.", 1, value);
		x->st.st_self[index] = value->ch.ch_code;
		break;

	case aet_bit:
		i = fixint(value);
		if (i != 0 && i != 1)
			FEerror("~S is not a bit.", 1, value);
		index += x->bv.bv_offset;
		if (i == 0)
			x->bv.bv_self[index/8] &= ~(0200>>index%8);
		else
			x->bv.bv_self[index/8] |= 0200>>index%8;
		break;

	case aet_fix:
		x->fixa.fixa_self[index] = fixint(value);
		break;
		
	case aet_char:
        case aet_uchar:
		x->ust.ust_self[index]=(unsigned char)fixint(value);
		break;

	case aet_short:
        case aet_ushort:
		USHORT(x,index) = (unsigned short)fixint(value);
		break;

	case aet_sf:
		x->sfa.sfa_self[index] = object_to_double(value);
		break;

	case aet_lf:
		x->lfa.lfa_self[index] = object_to_double(value);
		break;
	}
	return(value);
}

object
aref1(v, index)
object v;
int index;
{
	int i;
	object l;

	if (index < 0) {
		vs_push(make_fixnum(index));
		FEerror("Negative index: ~D.", 1, vs_head);
	}
	switch (type_of(v)) {
	case t_vector:
	case t_bitvector:
		return(aref(v, index));

	case t_string:
		if (index >= v->st.st_dim)
			goto E;
		return(code_char(v->ust.ust_self[index]));

	default:
		FEerror("~S is not a vector.", 1, v);
	}

E:
	vs_push(make_fixnum(index));
	FEerror("The index, ~D, is too large.", 1, vs_head);
}

object
aset1(v, index, val)
object v;
int index;
object val;
{
	int i;
	object l;

	if (index < 0) {
		vs_push(make_fixnum(index));
		FEerror("Negative index: ~D.", 1, vs_head);
	}
	switch (type_of(v)) {
	case t_vector:
	case t_bitvector:
		return(aset(v, index, val));

	case t_string:
		if (index >= v->st.st_dim)
			goto E;
		if (type_of(val) != t_character)
			FEerror("~S is not a character.", 1, val);
		v->st.st_self[index] = val->ch.ch_code;
		return(val);

	default:
		FEerror("~S is not a vector.", 1, v);
	}

E:
	vs_push(make_fixnum(index));
	FEerror("The index, ~D, is too large", 1, vs_head);
}

/*
	Displace(from, to, offset) displaces the from-array
	to the to-array (the original array) by the specified offset.
	It changes the a_displaced field of both arrays.
	The field is a cons; the car of the from-array points to
	the to-array and the cdr of the to-array is a list of arrays
	displaced to the to-array, so the from-array is pushed to the
	cdr of the to-array's a_displaced.
*/
displace(from, to, offset)
object from, to, offset;
{
	int j;
	enum aelttype totype, fromtype;

	j = fixnnint(offset);
	totype = array_elttype(to);
	fromtype = array_elttype(from);
	if (totype != fromtype)
		FEerror("Cannot displace the array,~%\
because the element types don't match.", 0);
	if (j + from->a.a_dim > to->a.a_dim)
		FEerror("Cannot displace the array,~%\
because the total size of the to-array is too small.", 0);
	from->a.a_displaced = make_cons(to, Cnil);
	if (to->a.a_displaced == Cnil)
		to->a.a_displaced = make_cons(Cnil, Cnil);
	to->a.a_displaced->c.c_cdr =
	make_cons(from, to->a.a_displaced->c.c_cdr);
	if (fromtype == aet_bit) {
		j += to->bv.bv_offset;
		from->bv.bv_self = to->bv.bv_self + j/8;
		from->bv.bv_offset = j%8;
	}
#ifdef MV


#endif
	else
		from->st.st_self = array_address(to, j);
}

/*  (setq a (make-array 2 :displaced-to (setq b (make-array 4 )))) {  A->displ = (B), B->displ=(nil A)}
	Undisplace(from) destroys the displacement from the from-array.
*/
undisplace(from)
object from;
{
	object *p;
	object to;
	
	  /* if the cons is free, neither the FROM nor the TO array will
	     survive the gc (or we would have marked this), and we can
	     skip undisplacing */
	
	if (from->a.a_displaced->d.m == FREE) return;
	to= from->a.a_displaced->c.c_car;
	
	if (to == Cnil)
		return;
	from->a.a_displaced->c.c_car = Cnil;
	for (p = &(to->a.a_displaced->c.c_cdr);;  p = &((*p)->c.c_cdr)){

	  if ((*p)->d.m == FREE) return;
	  /* During the sweep phase we sometimes null out the rest of this list
	     if the array is being displaced.
	     */
	  if (*p == Cnil) return; 
	  if ((*p)->c.c_car == from) {
	    *p = (*p)->c.c_cdr;
	    return;
		}}
}

/*
	Check_displaced(dlist, orig, newdim) checks if the displaced
	arrays can keep the displacement when the original array is
	adjusted.
	Dlist is the list of displaced arrays, orig is the original array
	and newdim is the new dimension of the original array.
*/
check_displaced(dlist, orig, newdim)
object dlist, orig;
int newdim;
{
	object x;

	for (;  dlist != Cnil;  dlist = dlist->c.c_cdr) {
		x = dlist->c.c_car;
		if (x->a.a_self == NULL)
			continue;
		if (array_elttype(x) != aet_bit) {
			if (array_address(x, x->a.a_dim) >
			    array_address(orig, newdim))
				FEerror("Can't keep displacement.", 0);
		} else {
			if ((x->bv.bv_self - orig->bv.bv_self)*8 +
			    x->bv.bv_dim - newdim +
			    x->bv.bv_offset - orig->bv.bv_offset > 0)
				FEerror("Can't keep displacement.", 0);
		}
		check_displaced(x->a.a_displaced->c.c_cdr, orig, newdim);
	}
}

/*
	Adjust_displaced(x, diff) adds the int value diff
	to the a_self field of the array x and all the arrays displaced to x.
	This function is used in siLreplace_array (ADJUST-ARRAY) and
	the garbage collector.
*/
adjust_displaced(x, diff)
object x;
int diff;
{
	if (x->a.a_self != NULL)
		x->a.a_self = (object *)((int)(x->a.a_self) + diff);
	for (x = x->a.a_displaced->c.c_cdr;  x != Cnil;  x = x->c.c_cdr)
		adjust_displaced(x->c.c_car, diff);
}

setup_fillp(x, fillp)
object x, fillp;
{
	int j;

	if (fillp == Cnil) {
		x->v.v_hasfillp = FALSE;
		x->v.v_fillp = x->v.v_dim;
	} else if (fillp == Ct) {
		x->v.v_hasfillp = TRUE;
		x->v.v_fillp = x->v.v_dim;
	} else if ((j = fixnnint(fillp)) > x->v.v_dim)
		FEerror("The fill-pointer ~S is too large.", 1, fillp);
	else {
		x->v.v_hasfillp = TRUE;
		x->v.v_fillp = j;
	}
}

/*
	Internal function for making arrays:

		(si:make-pure-array element-type adjustable
			            displaced-to displaced-index-offset
				    static initial-element
			            dim0 dim1 ... )
*/
siLmake_pure_array()
{
	int r, s, i, j;
	object x;

	r = vs_top - vs_base - 6;
	if (r < 0)
		too_few_arguments();
	x = alloc_object(t_array);
	x->a.a_self = NULL;
	x->a.a_displaced = Cnil;
	x->a.a_rank = r;
	x->a.a_dims = NULL;
	x->a.a_elttype = (short)get_aelttype(vs_base[0]);
	vs_base[0] = x;
	x->a.a_dims = AR_ALLOC(alloc_relblock,r,int);
	if (r >= ARANKLIM) {
		vs_push(make_fixnum(r));
		FEerror("The array rank, ~R, is too large.", 1, vs_head);
	}
	for (i = 0, s = 1;  i < r;  i++) {
		if ((j = fixnnint(vs_base[i+6])) > ADIMLIM) {
			vs_push(make_fixnum(i+1));
			FEerror("The ~:R array dimension, ~D, is too large.",
				2, vs_head, vs_base[i+6]);
		}
		s *= (x->a.a_dims[i] = j);
	}
	if (s > ATOTLIM) {
		vs_push(make_fixnum(s));
		FEerror("The array total size, ~D, is too large.",
			1, vs_head);
	}
	x->a.a_dim = s;
	x->a.a_adjustable = vs_base[1] != Cnil;
	if (vs_base[2] == Cnil)
		array_allocself(x, vs_base[4] != Cnil,vs_base[5]);
	else
		displace(x, vs_base[2], vs_base[3]);
	vs_top = vs_base + 1;
}

/*
	Internal function for making vectors:

		(si:make-vector element-type dimension adjustable fill-pointer
				displaced-to displaced-index-offset
			        static &optional initial-element)
*/
siLmake_vector()
{
	int d, i, j;
	object x;
	object dflt=Cnil;
	enum aelttype aet;
        if (vs_top-vs_base == 8)
	  {dflt=vs_base[7];}
	else {check_arg(7);}
	aet = get_aelttype(vs_base[0]);
	if ((d = fixnnint(vs_base[1])) > ADIMLIM)
		FEerror("The vector dimension, ~D, is too large.",
			1, vs_base[1]);
	if (aet == aet_ch)
		x = alloc_object(t_string);
	else if (aet == aet_bit)
		x = alloc_object(t_bitvector);
	else
		x = alloc_object(t_vector);
	x->v.v_self = NULL;
	x->v.v_displaced = Cnil;
	x->v.v_dim = d;
	x->v.v_adjustable = vs_base[2] != Cnil;
	if (aet != aet_ch && aet != aet_bit)
		x->v.v_elttype = (short)aet;
	vs_base[0] = x;
	setup_fillp(x, vs_base[3]);
	if (vs_base[4] == Cnil)
		array_allocself(x, vs_base[6] != Cnil,dflt);
	else
		displace(x, vs_base[4], vs_base[5]);
	vs_top = vs_base + 1;
}

Laref()
{
	int r, s, i, j;
	object x;

	r = vs_top - vs_base - 1;
	if (r < 0)
		too_few_arguments();
	x = vs_base[0];
	switch (type_of(x)) {
	case t_array:
		if (r != x->a.a_rank)
			FEerror("Wrong number of indices.", 0);
		for (i = j = 0;  i < r;  i++) {
			if ((s = fixnnint(vs_base[i+1])) >= x->a.a_dims[i]) {
				vs_push(make_fixnum(i+1));
				FEerror("The ~:R index, ~S, to the array~%\
~S is too large.", 3, vs_head, vs_base[i+1], x);
			}
			j = j*(x->a.a_dims[i]) + s;
		}
		break;

	case t_vector:
	case t_string:
	case t_bitvector:
		if (r != 1)
			FEerror("Wrong number of indices.", 0);
		j = fixnnint(vs_base[1]);
		if (j >= x->v.v_dim) {
			FEerror("The first index, ~S, to the array~%\
~S is too large.", 2, vs_base[1], x);
		}
		break;

	default:
		FEwrong_type_argument(Sarray, x);
	}
	vs_base[0] = aref(x, j);
	vs_top = vs_base + 1;
}

/*
	Internal function for setting array elements:

		(si:aset array dim0 dim1 ... newvalue)
*/
siLaset()
{
	int r, s, i, j;
	object x;

	r = vs_top - vs_base - 2;
	if (r < 0)
		too_few_arguments();
	x = vs_base[0];
	switch (type_of(x)) {
	case t_array:
		if (r != x->a.a_rank)
			FEerror("Wrong number of indices.", 0);
		for (i = j = 0;  i < r;  i++) {
			if ((s = fixnnint(vs_base[i+1])) >= x->a.a_dims[i]) {
				vs_push(make_fixnum(i+1));
				FEerror("The ~:R index, ~S, to the array~%\
~S is too large.", 3, vs_head, vs_base[i+1], x);
			}
			j = j*(x->a.a_dims[i]) + s;
		}
		break;

	case t_vector:
	case t_string:
	case t_bitvector:
		if (r != 1)
			FEerror("Wrong number of indices.", 0);
		j = fixnnint(vs_base[1]);
		if (j >= x->v.v_dim) {
			FEerror("The first index, ~S, to the array~%\
~S is too large.", 2, vs_base[1], x);
		}
		break;

	default:
		FEwrong_type_argument(Sarray, x);
	}
	aset(x, j, vs_base[r+1]);
	vs_base[0] = vs_base[r+1];
	vs_top = vs_base + 1;
}

Larray_element_type()
{
	check_arg(1);

	switch (array_elttype(vs_base[0])) {
	case aet_object:
		vs_base[0] = Ct;
		break;

	case aet_ch:
		vs_base[0] = Sstring_char;
		break;

	case aet_bit:
		vs_base[0] = Sbit;
		break;

	case aet_fix:
		vs_base[0] = Sfixnum;
		break;

        case aet_char:
		vs_base[0]= Ssigned_char;
		break;

        case aet_uchar:
		vs_base[0]= Sunsigned_char;
		break;
        case aet_short:
		vs_base[0]= Ssigned_short;
		break;
        case aet_ushort:
		vs_base[0]= Sunsigned_short;
		break;
	case aet_sf:
		vs_base[0] = Sshort_float;
		break;

	case aet_lf:
		vs_base[0] = Slong_float;
		break;
	}
}

Larray_rank()
{
	check_arg(1);
	check_type_array(&vs_base[0]);
	if (type_of(vs_base[0]) == t_array)
		vs_base[0] = make_fixnum(vs_base[0]->a.a_rank);
	else
		vs_base[0] = make_fixnum(1);
}

Larray_dimension()
{
	int i;

	check_arg(2);
	check_type_array(&vs_base[0]);
	i = fixnnint(vs_base[1]);
	if (type_of(vs_base[0]) == t_array) {
		if (i >= vs_base[0]->a.a_rank)
			goto ILLEGAL;
		vs_base[0] = make_fixnum(vs_base[0]->a.a_dims[i]);
	} else {
		if (i != 0)
			goto ILLEGAL;
		vs_base[0] = make_fixnum(vs_base[0]->v.v_dim);
	}
	vs_top = vs_base + 1;
	return;

ILLEGAL:
	FEerror("~S is an illegal axis-number to the array~%\
~S.", 2, vs_base[1], vs_base[0]);

}

Larray_total_size()
{
	check_arg(1);
	check_type_array(&vs_base[0]);
	vs_base[0] = make_fixnum(vs_base[0]->a.a_dim);
}

Ladjustable_array_p()
{
	check_arg(1);
	check_type_array(&vs_base[0]);
	if (vs_base[0]->a.a_adjustable)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

/*
	Internal function for checking if an array is displaced.
*/
siLdisplaced_array_p()
{
	check_arg(1);
	check_type_array(&vs_base[0]);
	if (vs_base[0]->a.a_displaced->c.c_car != Cnil)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Lsvref()
{
	int i;
	object x;

	check_arg(2);
	x = vs_base[0];
	if (type_of(x) != t_vector ||
	    x->v.v_adjustable ||
	    x->v.v_hasfillp ||
	    x->v.v_displaced->c.c_car != Cnil ||
	    (enum aelttype)x->v.v_elttype != aet_object)
		FEerror("~S is not a simple general vector.", 1, x);
	if ((i = fix(vs_base[1])) >= x->v.v_dim)
		illegal_index(x, vs_base[1]);
	vs_base[0] = x->v.v_self[i];
	vs_pop;
}

siLsvset()
{
	int i;
	object x;

	check_arg(3);
	x = vs_base[0];
	if (type_of(x) != t_vector ||
	    x->v.v_adjustable ||
	    x->v.v_hasfillp ||
	    x->v.v_displaced->c.c_car != Cnil ||
	    (enum aelttype)x->v.v_elttype != aet_object)
		FEerror("~S is not a simple general vector.", 1, x);
	if ((i = fixnnint(vs_base[1])) >= x->v.v_dim)
		illegal_index(x, vs_base[1]);
	vs_base[0] = x->v.v_self[i] = vs_base[2];
	vs_pop;
	vs_pop;
}

Larray_has_fill_pointer_p()
{
	check_arg(1);
	check_type_array(&vs_base[0]);
	if (type_of(vs_base[0]) == t_array)
		vs_base[0] = Cnil;
	else if (vs_base[0]->v.v_hasfillp)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Lfill_pointer()
{
	check_arg(1);
	check_type_vector(&vs_base[0]);
	if (vs_base[0]->v.v_hasfillp)
		vs_base[0] = make_fixnum(vs_base[0]->v.v_fillp);
	else
		FEerror("The vector ~S has no fill pointer.", 1, vs_base[0]);
}

/*
	Internal function for setting fill pointer.
*/
siLfill_pointer_set()
{
	int i;

	check_arg(2);
	check_type_vector(&vs_base[0]);
	i = fixnnint(vs_base[1]);
	if (vs_base[0]->v.v_hasfillp)
		if (i > vs_base[0]->v.v_dim)
			FEerror("The fill-pointer ~S is too large",
				1, vs_base[0]);
		else
			vs_base[0]->v.v_fillp = i;
	else
		FEerror("The vector ~S has no fill pointer.",
			1, vs_base[0]);
	vs_base[0] = vs_base[1];
	vs_top = vs_base + 1;
}

/*
	Internal function for replacing the contents of arrays:

		(si:replace-array old-array new-array).

	Used in ADJUST-ARRAY.
*/
siLreplace_array()
{
	object old, new, displaced, dlist;
	int diff;
	struct dummy fw;

	check_arg(2);
	old = vs_base[0];
	new = vs_base[1];
	fw = old->d;

	if (type_of(old) != type_of(new))
		goto CANNOT;
	if (type_of(old) == t_array && old->a.a_rank != new->a.a_rank)
		goto CANNOT;
/*   Common lisp now allows adjustment of non adjustable arrays CLTLII 17.6
     if (!old->a.a_adjustable)
		FEerror("~S is not adjustable.", 1, old);
*/		
	diff = (int)(new->a.a_self) - (int)(old->a.a_self);
	dlist = old->a.a_displaced->c.c_cdr;
	displaced = make_cons(new->a.a_displaced->c.c_car, dlist);
	vs_push(displaced);
	check_displaced(dlist, old, new->a.a_dim);
	adjust_displaced(old, diff);
	undisplace(old);
	switch (type_of(old)) {
	case t_array:
	case t_vector:
	case t_bitvector:
		old->a = new->a;
		break;

	case t_string:
		old->st = new->st;
		break;

	default:
		goto CANNOT;
	}
	
	/* restore the s and m fields overwritten by above assignments  */
	old->d = fw;
	old->a.a_displaced = displaced;
	/* prevent having two arrays with the same body--which are not related
        that would cause the gc to try to copy both arrays and there might
       not be enough space. */
	new->a.a_dim=0;
	new->a.a_self=0;
	vs_pop;
	vs_pop;
	return;

CANNOT:
	FEerror("Cannot replace the array ~S~%\
by the array ~S.", 2, old, new);
}

siLaset_by_cursor()
{
	object *base = vs_base;
	object x;

	check_arg(3);
	vs_base = vs_top;
	vs_push(base[0]);
	for (x = base[2];  !endp(x);  x = MMcdr(x))
		vs_push(MMcar(x));
	vs_push(base[1]);
	siLaset();
}

init_array_function()
{
	make_constant("ARRAY-RANK-LIMIT", make_fixnum(ARANKLIM));
	make_constant("ARRAY-DIMENSION-LIMIT", make_fixnum(ADIMLIM));
	make_constant("ARRAY-TOTAL-SIZE-LIMIT", make_fixnum(ATOTLIM));

	make_si_function("MAKE-PURE-ARRAY", siLmake_pure_array);
	make_si_function("MAKE-VECTOR", siLmake_vector);
	make_function("AREF", Laref);
	make_si_function("ASET", siLaset);
	make_function("ARRAY-ELEMENT-TYPE", Larray_element_type);
	make_function("ARRAY-RANK", Larray_rank);
	make_function("ARRAY-DIMENSION", Larray_dimension);
	make_function("ARRAY-TOTAL-SIZE", Larray_total_size);
	make_function("ADJUSTABLE-ARRAY-P", Ladjustable_array_p);
	make_si_function("DISPLACED-ARRAY-P", siLdisplaced_array_p);
	make_si_constant("CHAR-SIZE",make_fixnum(CHAR_SIZE));
	make_si_constant("SHORT-SIZE",make_fixnum(CHAR_SIZE*sizeof(short)));
	make_function("SVREF", Lsvref);
	make_si_function("SVSET", siLsvset);
	make_si_function("COPY-ARRAY-PORTION",siLcopy_array_portion);
	make_function("ARRAY-HAS-FILL-POINTER-P",
		      Larray_has_fill_pointer_p);
	make_function("FILL-POINTER", Lfill_pointer);
	make_si_function("FILL-POINTER-SET", siLfill_pointer_set);

	make_si_function("REPLACE-ARRAY", siLreplace_array);

	make_si_function("ASET-BY-CURSOR", siLaset_by_cursor);
}
