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
	alloc.c
	IMPLEMENTATION-DEPENDENT
*/

#include "include.h"


object Vignore_maximum_pages;


#include "page.h"

#ifdef DEBUG_SBRK
int debug;
char *
sbrk1(n)
     int n;
{char *ans;
 if (debug){
   printf("\n{sbrk(%d)",n);
   fflush(stdout);}
 ans= (char *)sbrk(n);
 if (debug){
   printf("->[0x%x]", ans);
   fflush(stdout);
   printf("core_end=0x%x,sbrk(0)=0x%x}",core_end,sbrk(0));
   fflush(stdout);}
 return ans;
}
#define sbrk sbrk1
#endif /* DEBUG_SBRK */

int real_maxpage = MAXPAGE;
int new_holepage;

#define	available_pages	\
	(real_maxpage-page(heap_end)-new_holepage-2*nrbpage-real_maxpage/32)


#ifdef UNIX
extern char *sbrk();
#endif

#ifdef BSD
#include <sys/time.h>
#include <sys/resource.h>
struct rlimit data_rlimit;
extern char etext;
#endif


/* If  (n >= 0 ) return pointer to n pages starting at heap end,
   These must come from the hole, so if that is exhausted you have
   to gc and move the hole.
   if  (n < 0) return pointer to n pages starting at heap end,
   but don't worry about the hole.   Basically just make sure
   the space is available from the Operating system.
 */
char *
alloc_page(n)
int n;
{
	char *e;
	int m;
	e = heap_end;
	if (n >= 0) {
		if (n >= holepage) {
			holepage = new_holepage + n;

			{int in_sgc=sgc_enabled;
			 if (in_sgc) sgc_quit();
			GBC(t_relocatable);
			if (in_sgc)
			  {sgc_start();
			   /* starting sgc can use up some pages
			      and may move heap end, so start over
			    */
			   return alloc_page(n);}
		       }
		}
		holepage -= n;
		heap_end += PAGESIZE*n;
		return(e);
	}
     else
       /* n < 0 , then this says ensure there are -n pages
	  starting at heap_end, and return pointer to heap_end */
      {
	n = -n;
	m = (core_end - heap_end)/PAGESIZE;
	if (n <= m)
		return(e);

	IF_ALLOCATE_ERR error("Can't allocate.  Good-bye!");
#ifdef SGC
	if (sgc_enabled)
	  make_writable(page(core_end),page(core_end)+n-m);

#endif	
	core_end += PAGESIZE*(n - m);
	return(e);}
}

void
add_page_to_freelist(p,tm)
     char *p;
     struct typemanager *tm;
{short t,size;
 int i=tm->tm_nppage,fw;
 int nn;
 object x,f;
 t=tm->tm_type;
#ifdef SGC
 nn=page(p);
 if (sgc_enabled)
   { if (!WRITABLE_PAGE_P(nn)) make_writable(nn,nn+1);}
#endif
 type_map[page(p)]= t;
 size=tm->tm_size;
 f=tm->tm_free;
 x= (object)p;
 x->d.t=t;
 x->d.m=FREE;
#ifdef SGC
 if (sgc_enabled && tm->tm_sgc)
   {x->d.s=SGC_RECENT;
    sgc_type_map[page(x)] = (SGC_PAGE_FLAG | SGC_TEMP_WRITABLE);}
 else x->d.s = SGC_NORMAL;
 
 /* array headers must be always writable, since a write to the
    body does not touch the header.   It may be desirable if there
    are many arrays in a system to make the headers not writable,
    but just SGC_TOUCH the header each time you write to it.   this
    is what is done with t_structure */
  if (t== (tm_of(t_array)->tm_type))
   sgc_type_map[page(x)] |= SGC_PERM_WRITABLE;
   
#endif 
 fw= *(int *)x;
 while (--i >= 0)
   { *(int *)x=fw;
     F_LINK(x)=f;
     f=x;
     x= (object) ((char *)x + size);
   }
 tm->tm_free=f;
 tm->tm_nfree += tm->tm_nppage;
 tm->tm_npage++;
}



object
alloc_object(t)
enum type t;
{
	STATIC object obj;
	STATIC struct typemanager *tm;
	STATIC int i;
	STATIC char *p;
	STATIC object x, f;

ONCE_MORE:
	tm = tm_of(t);

	if (interrupt_flag) {
		interrupt_flag = FALSE;
#ifdef UNIX
		alarm(0);
#endif
		terminal_interrupt(TRUE);
		goto ONCE_MORE;
	}
	obj = tm->tm_free;
	if (obj == OBJNULL) {
		if (tm->tm_npage >= tm->tm_maxpage)
			goto CALL_GBC;
		if (available_pages < 1) {
			Vignore_maximum_pages->s.s_dbind = Cnil;
			goto CALL_GBC;
		}
		p = alloc_page(1);
		add_page_to_freelist(p,tm);
		obj = tm->tm_free;
		if (tm->tm_npage >= tm->tm_maxpage)
			goto CALL_GBC;
	}
	tm->tm_free = ((struct freelist *)obj)->f_link;
	--(tm->tm_nfree);
	(tm->tm_nused)++;
	obj->d.t = (short)t;
	obj->d.m = FALSE;
	return(obj);
#define TOTAL_THIS_TYPE(tm) \
	(tm->tm_nppage * (sgc_enabled ? sgc_count_type(tm->tm_type) : tm->tm_npage))
CALL_GBC:
	GBC(tm->tm_type);
	if (tm->tm_nfree == 0 ||
	    (float)tm->tm_nfree * 10.0 < (float) TOTAL_THIS_TYPE(tm))
		goto EXHAUSTED;
	goto ONCE_MORE;

EXHAUSTED:
	if (symbol_value(Vignore_maximum_pages) != Cnil) {
		if (tm->tm_maxpage/2 <= 0)
			tm->tm_maxpage += 1;
		else
			tm->tm_maxpage += tm->tm_maxpage/2;
		goto ONCE_MORE;
	}
	GBC_enable = FALSE;
	vs_push(make_simple_string(tm_table[(int)t].tm_name+1));
	vs_push(make_fixnum(tm->tm_npage));
	GBC_enable = TRUE;
	CEerror("The storage for ~A is exhausted.~%\
Currently, ~D pages are allocated.~%\
Use ALLOCATE to expand the space.",
		"Continues execution.",
		2, vs_top[-2], vs_top[-1]);
	vs_pop;
	vs_pop;
	goto ONCE_MORE;
}

grow_linear(old,fract,grow_min,grow_max)
     int old,grow_min,grow_max,fract;
{int delt;
 if(fract==0) fract=50;
 if(grow_min==0) grow_min=1;
 if(grow_max==0) grow_max=1000;
 delt=(old*fract)/100;
 delt= (delt < grow_min ? grow_min:
	delt > grow_max ? grow_max:
	delt);
 return old + delt;}

object
make_cons(a, d)
object a, d;
{
	STATIC object obj;
	STATIC int i;
	STATIC char *p;
	STATIC object x, f;
	struct typemanager *tm=(&tm_table[(int)t_cons]);
/* #define	tm	(&tm_table[(int)t_cons])*/

ONCE_MORE:
	if (interrupt_flag) {
		interrupt_flag = FALSE;
#ifdef UNIX
		alarm(0);
#endif
		terminal_interrupt(TRUE);
		goto ONCE_MORE;
	}
	obj = tm->tm_free;
	if (obj == OBJNULL) {
		if (tm->tm_npage >= tm->tm_maxpage)
			goto CALL_GBC;
		if (available_pages < 1) {
			Vignore_maximum_pages->s.s_dbind = Cnil;
			goto CALL_GBC;
		}
		p = alloc_page(1);
		add_page_to_freelist(p,tm);
		obj = tm->tm_free ;
		if (tm->tm_npage >= tm->tm_maxpage)
			goto CALL_GBC;
	}
	tm->tm_free = ((struct freelist *)obj)->f_link;
	--(tm->tm_nfree);
	(tm->tm_nused)++;
	obj->c.t = (short)t_cons;
	obj->c.m = FALSE;
	obj->c.c_car = a;
	obj->c.c_cdr = d;
	return(obj);

CALL_GBC:
	GBC(t_cons);
	if (tm->tm_nfree == 0 ||
	    (float)tm->tm_nfree * 10.0 < (float) TOTAL_THIS_TYPE(tm))
		goto EXHAUSTED;
	goto ONCE_MORE;

EXHAUSTED:
	if (symbol_value(Vignore_maximum_pages) != Cnil) {
	  tm->tm_maxpage =
	    grow_linear(tm->tm_maxpage,tm->tm_growth_percent,
			tm->tm_min_grow,tm->tm_max_grow);
		goto ONCE_MORE;
	}
	GBC_enable = FALSE;
	vs_push(make_fixnum(tm->tm_npage));
	GBC_enable = TRUE;
	CEerror("The storage for CONS is exhausted.~%\
Currently, ~D pages are allocated.~%\
Use ALLOCATE to expand the space.",
		"Continues execution.",
		1, vs_top[-1]);
	vs_pop;
	goto ONCE_MORE;
#undef	tm
}


object on_stack_cons(x,y)
     object x,y;
{object p = (object) alloca_val;
 p->c.t= (short)t_cons;
 p->c.m=FALSE;
 p->c.c_car=x;
 p->c.c_cdr=y;
 return p;
}


 

#define	round_up(n)	(((n) + 03) & ~03)

char *
alloc_contblock(n)
int n;
{
	STATIC char *p;
	STATIC struct contblock **cbpp;
	STATIC int i;
	STATIC int m;
	STATIC bool g;
	bool gg;

/*
	printf("allocating %d-byte contiguous block...\n", n);
*/

	g = FALSE;
	n = round_up(n);

ONCE_MORE:
	if (interrupt_flag) {
		interrupt_flag = FALSE;
		gg = g;
		terminal_interrupt(TRUE);
		g = gg;
		goto ONCE_MORE;
	}
	for(cbpp= &cb_pointer; (*cbpp)!=NULL; cbpp= &(*cbpp)->cb_link)
		if ((*cbpp)->cb_size >= n) {
			p = (char *)(*cbpp);
			i = (*cbpp)->cb_size - n;
			*cbpp = (*cbpp)->cb_link;
			--ncb;
			insert_contblock(p+n, i);
			return(p);
		}
	m = (n + PAGESIZE - 1)/PAGESIZE;
	if (ncbpage + m > maxcbpage || available_pages < m) {
		if (available_pages < m)
			Vignore_maximum_pages->s.s_dbind = Cnil;
		if (!g) {
			GBC(t_contiguous);
			g = TRUE;
			goto ONCE_MORE;
		}
		if (symbol_value(Vignore_maximum_pages) != Cnil)
		  {struct typemanager *tm = &tm_table[(int)t_contiguous];
		   maxcbpage=grow_linear(maxcbpage,tm->tm_growth_percent,
			      tm->tm_min_grow, tm->tm_max_grow);
			g = FALSE;
			goto ONCE_MORE;
		}
		vs_push(make_fixnum(ncbpage));
		CEerror("Contiguous blocks exhausted.~%\
Currently, ~D pages are allocated.~%\
Use ALLOCATE-CONTIGUOUS-PAGES to expand the space.",
			"Continues execution.", 1, vs_head);
		vs_pop;
		g = FALSE;
		goto ONCE_MORE;
	}

	p = alloc_page(m);

	for (i = 0;  i < m;  i++)
		type_map[page(p) + i] = (char)t_contiguous;
	ncbpage += m;
	insert_contblock(p+n, PAGESIZE*m - n);
	return(p);
}

insert_contblock(p, s)
char *p;
int s;
{
	struct contblock **cbpp, *cbp;

	if (s < CBMINSIZE)
		return;
	ncb++;
	cbp = (struct contblock *)p;
	cbp->cb_size = s;
	for (cbpp = &cb_pointer;  *cbpp;  cbpp = &((*cbpp)->cb_link))
		if ((*cbpp)->cb_size >= s) {
			cbp->cb_link = *cbpp;
			*cbpp = cbp;
			return;
		}
	cbp->cb_link = NULL;
	*cbpp = cbp;
}

char *
alloc_relblock(n)
int n;
{
	STATIC char *p;
	STATIC bool g;
	bool gg;
	int i;

/*
	printf("allocating %d-byte relocatable block...\n", n);
*/

	g = FALSE;
	n = round_up(n);

ONCE_MORE:
	if (interrupt_flag) {
		interrupt_flag = FALSE;
		gg = g;
		terminal_interrupt(TRUE);
		g = gg;
		goto ONCE_MORE;
	}
	if (rb_limit - rb_pointer < n) {
		if (!g) {
			GBC(t_relocatable);
			g = TRUE;
			{ float f1 = (float)(rb_limit - rb_pointer),
				f2 = (float)(rb_limit - rb_start);

				if (f1 * 10.0 < f2) 
				;
			else
				goto ONCE_MORE;
			}
		}
		if (symbol_value(Vignore_maximum_pages) != Cnil)
		  {struct typemanager *tm = &tm_table[(int)t_relocatable];
		   nrbpage=grow_linear(i=nrbpage,tm->tm_growth_percent,
			      tm->tm_min_grow, tm->tm_max_grow);
		   if (available_pages < 0)
		     nrbpage = i;
		   else {
			  rb_end +=  (PAGESIZE* (nrbpage -i));
			  rb_limit = rb_end - 2*RB_GETA;
			  if (page(rb_end) - page(heap_end) !=
			      holepage + nrbpage)
			    FEerror("bad rb_end");
			  alloc_page(-( nrbpage + holepage));
			  g = FALSE;
			  goto ONCE_MORE;
			}
		}
		if (rb_limit > rb_end - 2*RB_GETA)
			error("relocatable blocks exhausted");
		rb_limit += RB_GETA;
		vs_push(make_fixnum(nrbpage));
		CEerror("Relocatable blocks exhausted.~%\
Currently, ~D pages are allocated.~%\
Use ALLOCATE-RELOCATABLE-PAGES to expand the space.",
			"Continues execution.", 1, vs_head);
		vs_pop;
		g = FALSE;
		goto ONCE_MORE;
	}
	p = rb_pointer;
	rb_pointer += n;
	return(p);
}

init_tm(t, name, elsize, nelts,sgc)
enum type t;
char name[];
int elsize, nelts;
{
	int i, j;
	int maxpage;
	/* round up to next number of pages */
	maxpage = (((nelts * elsize) + PAGESIZE -1)/PAGESIZE);
	tm_table[(int)t].tm_name = name;
	for (j = -1, i = 0;  i < (int)t_end;  i++)
		if (tm_table[i].tm_size != 0 &&
		    tm_table[i].tm_size >= elsize &&
		    (j < 0 || tm_table[j].tm_size > tm_table[i].tm_size))
			j = i;
	if (j >= 0) {
		tm_table[(int)t].tm_type = (enum type)j;
		tm_table[j].tm_maxpage += maxpage;
#ifdef SGC		
		tm_table[j].tm_sgc += sgc;
#endif
		return;
	}
	tm_table[(int)t].tm_type = t;
	tm_table[(int)t].tm_size = round_up(elsize);
	tm_table[(int)t].tm_nppage = PAGESIZE/round_up(elsize);
	tm_table[(int)t].tm_free = OBJNULL;
	tm_table[(int)t].tm_nfree = 0;
	tm_table[(int)t].tm_nused = 0;
	tm_table[(int)t].tm_npage = 0;
	tm_table[(int)t].tm_maxpage = maxpage;
	tm_table[(int)t].tm_gbccount = 0;
#ifdef SGC	
	tm_table[(int)t].tm_sgc = sgc;
	tm_table[(int)t].tm_sgc_max = 3000;
	tm_table[(int)t].tm_sgc_minfree = (int)
	  (0.4 * tm_table[(int)t].tm_nppage);
#endif

}

set_maxpage()
{
  /* This is run in init.  Various initializations including getting
     maxpage are here */ 
#ifdef SGC
  page_multiple=getpagesize()/PAGESIZE;
  if (page_multiple==0) error("PAGESIZE must be factor of getpagesize()");
  if (sgc_enabled)
    {memory_protect(1);}
  if (~(-MAXPAGE) != MAXPAGE-1) error("MAXPAGE must be power of 2");
  if (core_end)
     bzero(&sgc_type_map[ page(core_end)],MAXPAGE- page(core_end));
#else
  page_multiple=1;
#endif
  
SET_REAL_MAXPAGE;

      }





init_alloc()
{
	int i, j;
	struct typemanager *tm;
	char *p, *q;
	enum type t;
	int c;
	static initialized;
	if (initialized) return;
	initialized=1;
	

#ifndef DONT_NEED_MALLOC	

	{
		extern object malloc_list;
		malloc_list = Cnil;
		enter_mark_origin(&malloc_list);
	}
#endif	

	holepage = INIT_HOLEPAGE;
	new_holepage = HOLEPAGE;
	nrbpage = INIT_NRBPAGE;

	set_maxpage();


	INIT_ALLOC;
	

	alloc_page(-(holepage + nrbpage));
	rb_start = rb_pointer = heap_end + PAGESIZE*holepage;
	rb_end = rb_start + PAGESIZE*nrbpage;
	rb_limit = rb_end - 2*RB_GETA;
#ifdef SGC	
	tm_table[(int)t_relocatable].tm_sgc = 50;
#endif
	
	for (i = 0;  i < MAXPAGE;  i++)
		type_map[i] = (char)t_other;

	init_tm(t_fixnum, "NFIXNUM",
		sizeof(struct fixnum_struct), 8192,20);
	init_tm(t_cons, ".CONS", sizeof(struct cons), 65536 ,50 );
	init_tm(t_structure, "SSTRUCTURE", sizeof(struct structure), 5461,0 );
	init_tm(t_cfun, "fCFUN", sizeof(struct cfun), 4096,0  );
	init_tm(t_sfun, "gSFUN", sizeof(struct sfun),409,0 );
	init_tm(t_string, "\"STRING", sizeof(struct string), 5461,1  );
	init_tm(t_array, "aARRAY", sizeof(struct array), 4681,1 );
	init_tm(t_symbol, "|SYMBOL", sizeof(struct symbol), 3640,1 );
	init_tm(t_bignum, "BBIGNUM", sizeof(struct bignum), 2730,0 );
	init_tm(t_ratio, "RRATIONAL", sizeof(struct ratio), 170,0 );
	init_tm(t_shortfloat, "FSHORT-FLOAT",
		sizeof(struct shortfloat_struct), 256 ,0);
	init_tm(t_longfloat, "LLONG-FLOAT",
		sizeof(struct longfloat_struct), 170 ,0);
	init_tm(t_complex, "CCOMPLEX", sizeof(struct complex), 170 ,0);
	init_tm(t_character,"#CHARACTER",sizeof(struct character), 256 ,0);
	init_tm(t_package, ":PACKAGE", sizeof(struct package), 2*PAGESIZE / sizeof(struct package),0);
	init_tm(t_hashtable, "hHASH-TABLE", sizeof(struct hashtable), 78,0 );
	init_tm(t_vector, "vVECTOR", sizeof(struct vector), 146 ,0);
	init_tm(t_bitvector, "bBIT-VECTOR", sizeof(struct bitvector), 73 ,0);
	init_tm(t_stream, "sSTREAM", sizeof(struct stream), 78 ,0);
	init_tm(t_random, "$RANDOM-STATE", sizeof(struct random), 256 ,0);
	init_tm(t_readtable, "rREADTABLE", sizeof(struct readtable), 256 ,0);
	init_tm(t_pathname, "pPATHNAME", sizeof(struct pathname), 73 ,0);
	init_tm(t_cclosure, "cCCLOSURE", sizeof(struct cclosure), 85 ,0);
	init_tm(t_vfun, "VVFUN", sizeof(struct vfun), 102 ,0);
	init_tm(t_gfun, "gGFUN", sizeof(struct sfun), 0 ,0);
	init_tm(t_cfdata, "cCFDATA", sizeof(struct cfdata), 102 ,0);
	init_tm(t_spice, "!SPICE", sizeof(struct spice), 4096 ,0);
	init_tm(t_fat_string, "FFAT-STRING", sizeof(struct fat_string), 102
		,0);
	init_tm(t_relocatable, "%RELOCATABLE-BLOCKS", 1000,0,20);
	init_tm(t_contiguous, "_CONTIGUOUS-BLOCKS", 1001,0,20);


	ncb = 0;
	ncbpage = 0;
	maxcbpage = 512;
	
}


cant_get_a_type()
{
	FEerror("Can't get a type.", 0);
}

siLallocate()
{
	struct typemanager *tm;
	int c, i;
	char *p, *pp;
	object f, x;
	int t;

	if (vs_top - vs_base < 2)
		too_few_arguments();
	if (vs_top - vs_base > 3)
	  too_many_arguments();
	t= t_from_type(vs_base[0]);
	if (type_of(vs_base[1]) != t_fixnum ||
	    (i = fix(vs_base[1])) < 0)
		FEerror("~A is not a non-negative fixnum.", 1, vs_base[1]);
	tm = tm_of(t);
	if (tm->tm_npage > i) {i=tm->tm_npage;}
	tm->tm_maxpage = i;
	if (vs_top - vs_base == 3 && vs_base[2] != Cnil &&
	    tm->tm_maxpage > tm->tm_npage)
	  goto ALLOCATE;
	vs_top = vs_base;
	vs_push(Ct);
	return;

ALLOCATE:
	if (available_pages < tm->tm_maxpage - tm->tm_npage ||
	    (pp = alloc_page(tm->tm_maxpage - tm->tm_npage)) == NULL) {
	vs_push(make_simple_string(tm->tm_name+1));
	FEerror("Can't allocate ~D pages for ~A.", 2, vs_base[1], vs_top[-1]);
	}
	for (;  tm->tm_npage < tm->tm_maxpage;  pp += PAGESIZE)
	  add_page_to_freelist(pp,tm);
	vs_top = vs_base;
	vs_push(Ct);
}

t_from_type(type)
     object type;
{object typ= coerce_to_string(type);
 object c = aref1(typ,0);
 int i;
 for (i= (int)t_start ; i < (int)t_contiguous ; i++)
   {struct typemanager *tm = &tm_table[i];
   if(tm->tm_name &&
      0==strncmp((tm->tm_name)+1,typ->st.st_self,typ->st.st_fillp)
      )
     return i;}
 FEerror("Unrecognized type");
}
/* When sgc is enabled the TYPE should have at least MIN pages of sgc type,
   and at most MAX of them.   Each page should be FREE_PERCENT free
   when the sgc is turned on.  FREE_PERCENT is an integer between 0 and 100. 
   */
   
object
siSallocate_sgc(type,min,max,free_percent)
     object type;
     int min,max,free_percent;
{int m,t=t_from_type(type);
 struct typemanager *tm;
 object res;
 tm=tm_of(t);
  res= list(3,make_fixnum(tm->tm_sgc),
	   make_fixnum(tm->tm_sgc_max),
	   make_fixnum((100*tm->tm_sgc_minfree)/tm->tm_nppage));
 
 if(min<0 || max< min || min > 3000 || free_percent < 0 || free_percent > 100)
    goto END;
 tm->tm_sgc_max=max;
 tm->tm_sgc=min;
 tm->tm_sgc_minfree= (tm->tm_nppage *free_percent) /100;
 END:
 return res;
}

/* Growth of TYPE will be by at least MIN pages and at most MAX pages.
   It will try to grow PERCENT of the current pages.
   */
object
siSallocate_growth(type,min,max,percent)
int min,max,percent;
object type;
{int  t=t_from_type(type);
 struct typemanager *tm=tm_of(t);
 object res;
 res= list(3,make_fixnum(tm->tm_min_grow),
	   make_fixnum(tm->tm_max_grow),
	   make_fixnum(tm->tm_growth_percent));
 
 if(min<0 || max< min || min > 3000 || percent < 0 || percent > 500)
    goto END;
 tm->tm_max_grow=max;
 tm->tm_min_grow=min;
 tm->tm_growth_percent= percent;
 END:
 return res;
}
 
  

siLallocated_pages()
{
	struct typemanager *tm;
	int c;

	check_arg(1);
	{int t=t_from_type(vs_base[0]);
	 vs_base[0]=make_fixnum(tm_of(t)->tm_npage);}
      }


siLmaxpage()
{
	struct typemanager *tm;
	int c;

	check_arg(1);
	{int t=t_from_type(vs_base[0]);
	 vs_base[0]=make_fixnum(tm_of(t)->tm_npage);}
      }


siLalloc_contpage()
{
	int i, m;
	char *p;

	if (vs_top - vs_base < 1)
		too_few_arguments();
	if (vs_top - vs_base > 2)
		too_many_arguments();
	if (type_of(vs_base[0]) != t_fixnum ||
	    (i = fix(vs_base[0])) < 0)
		FEerror("~A is not a non-negative fixnum.", 1, vs_base[0]);
	if (ncbpage > i)
	  { printf("Allocate contiguous %d: %d already there pages",i,ncbpage);
	    i=ncbpage;}
	maxcbpage = i;
	if (vs_top - vs_base < 2 || vs_base[1] == Cnil) {
		vs_top = vs_base;
		vs_push(Ct);
		return;
	}
	m = maxcbpage - ncbpage;
	if (available_pages < m || (p = alloc_page(m)) == NULL)
		FEerror("Can't allocate ~D pages for contiguous blocks.",
			1, vs_base[0]);
	for (i = 0;  i < m;  i++)
		type_map[page(p + PAGESIZE*i)] = (char)t_contiguous;
	ncbpage += m;
	insert_contblock(p, PAGESIZE*m);
	vs_top = vs_base;
	vs_push(Ct);
}

siLncbpage()
{
	check_arg(0);
	vs_push(make_fixnum(ncbpage));
}

siLmaxcbpage()
{
	check_arg(0);
	vs_push(make_fixnum(maxcbpage));
}

siLalloc_relpage()
{
	int i;
	char *p;

	if (vs_top - vs_base < 1)
		too_few_arguments();
	if (vs_top - vs_base > 2)
		too_many_arguments();
	if (type_of(vs_base[0]) != t_fixnum ||
	    (i = fix(vs_base[0])) < 0)
		FEerror("~A is not a non-negative fixnum.", 1, vs_base[0]);
	if (nrbpage > i && rb_pointer >= rb_start + PAGESIZE*i - 2*RB_GETA
	 || 2*i > real_maxpage-page(heap_end)-new_holepage-real_maxpage/32)
		FEerror("Can't set the limit for relocatable blocks to ~D.",
			1, vs_base[0]);
	rb_end += (i-nrbpage)*PAGESIZE;
	nrbpage = i;
	rb_limit = rb_end - 2*RB_GETA;
	alloc_page(-(holepage + nrbpage));
	vs_top = vs_base;
	vs_push(Ct);
}

siLnrbpage()
{
	check_arg(0);
	vs_push(make_fixnum(nrbpage));
}

siLget_hole_size()
{
	check_arg(0);
	vs_push(make_fixnum(new_holepage));
}

siLset_hole_size()
{
	int i;

	check_arg(1);
	i = fixint(vs_base[0]);
	if (i < 1 ||
	    i > real_maxpage - page(heap_end) - 2*nrbpage - real_maxpage/32)
		FEerror("Illegal value for the hole size.", 0);
	new_holepage = i;
}

init_alloc_function()
{
	make_si_function("ALLOCATE", siLallocate);
	make_si_function("ALLOCATED-PAGES", siLallocated_pages);
	make_si_function("MAXIMUM-ALLOCATABLE-PAGES", siLmaxpage);
	make_si_function("ALLOCATE-CONTIGUOUS-PAGES", siLalloc_contpage);
	make_si_function("ALLOCATED-CONTIGUOUS-PAGES", siLncbpage);
	make_si_function("MAXIMUM-CONTIGUOUS-PAGES", siLmaxcbpage);
	make_si_function("ALLOCATE-RELOCATABLE-PAGES", siLalloc_relpage);
	make_si_function("ALLOCATED-RELOCATABLE-PAGES", siLnrbpage);
	make_si_function("GET-HOLE-SIZE", siLget_hole_size);
	make_si_function("SET-HOLE-SIZE", siLset_hole_size);
	make_si_sfun("ALLOCATE-SGC",siSallocate_sgc,
		     4 | ARGTYPE(0,f_object) | ARGTYPE(1,f_fixnum) |
		     ARGTYPE(2,f_fixnum) | ARGTYPE(3,f_fixnum)
		     | RESTYPE(f_object));


	make_si_sfun("ALLOCATE-GROWTH",siSallocate_growth,
		     4 | ARGTYPE(0,f_object) | ARGTYPE(1,f_fixnum) |
		     ARGTYPE(2,f_fixnum) | ARGTYPE(3,f_fixnum)
		     | RESTYPE(f_object));
	Vignore_maximum_pages
	= make_special("*IGNORE-MAXIMUM-PAGES*", Ct);

}

object malloc_list;

#ifndef DONT_NEED_MALLOC

/*
	UNIX malloc simulator.

	Used by
		getwd, popen, etc.
*/



/*  If this is defined, substitute the fast gnu malloc for the slower
    version below.   If you have many calls to malloc this is worth
    your while.   I have only tested it slightly under 4.3Bsd.   There
    the difference in a test run with 120K mallocs and frees,
    was 29 seconds to 1.9 seconds */
    
#ifdef GNU_MALLOC
#include "malloc.c"
#else

char *
malloc(size)
int size;
{
	object x;

	if (GBC_enable==0 && initflag ==0)
	  { init_alloc();}
      

	x = alloc_simple_string(size);

	x->st.st_self = alloc_contblock(size);
#ifdef SGC
	perm_writable(x->st.st_self,size);
#endif
	malloc_list = make_cons(x, malloc_list);

	return(x->st.st_self);
}


void
free(ptr)
#ifndef NO_VOID_STAR
void *
#else
char *
#endif  
  ptr;
{
	object *p;

	if (ptr == 0)
	  return;
	for (p = &malloc_list; *p && !endp(*p);  p = &((*p)->c.c_cdr))
		if ((*p)->c.c_car->st.st_self == ptr) {
			insert_contblock((*p)->c.c_car->st.st_self,
					 (*p)->c.c_car->st.st_dim);
			(*p)->c.c_car->st.st_self = NULL;
			*p = (*p)->c.c_cdr;
			return ;
		}
#ifdef NOFREE_ERR
	return ;
#else	
	FEerror("free(3) error.",0);
	return;
#endif	
}

char *
realloc(ptr, size)
char *ptr;
int size;
{
	object x;
	int i, j;

	if(ptr == NULL) return malloc(size);
	for (x = malloc_list;  !endp(x);  x = x->c.c_cdr)
		if (x->c.c_car->st.st_self == ptr) {
			x = x->c.c_car;
			if (x->st.st_dim >= size) {
				x->st.st_fillp = size;
				return(ptr);
			} else {
				j = x->st.st_dim;
				x->st.st_self = alloc_contblock(size);
				x->st.st_fillp = x->st.st_dim = size;
				for (i = 0;  i < size;  i++)
					x->st.st_self[i] = ptr[i];
				insert_contblock(ptr, j);
				return(x->st.st_self);
			}
		}
	FEerror("realloc(3) error.", 0);
}

#endif /* gnumalloc */
char *
calloc(nelem, elsize)
int nelem, elsize;
{
	char *ptr;
	int i;

	ptr = malloc(i = nelem*elsize);
	while (--i >= 0)
		ptr[i] = 0;
	return(ptr);
}

cfree(ptr)
char *ptr;
{
	free(ptr);

}

#endif


#ifndef GNUMALLOC
char *
memalign(align,size)
     int align,size;
{ object x = alloc_simple_string(size);
  x->st.st_self = ALLOC_ALIGNED(alloc_contblock,size,align);
  malloc_list = make_cons(x, malloc_list);
  return x->st.st_self;
}
#ifdef WANT_VALLOC
char *
valloc(size)
int size;     
{ return memalign(getpagesize(),size);}
#endif

#endif
