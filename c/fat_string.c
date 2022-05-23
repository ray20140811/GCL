/*
(c) Copyright W. Schelter 1988, All rights reserved.
*/

/* 16 bit strings  with leader, and raw slots in the leader t_fat_string */


#include "include.h"
#include "page.h"
#define FAT_STRING

object  Sfat_string;
enum type what_to_collect;
#define	inheap(pp)	((char *)(pp) < heap_end)



/* start fasdump stuff */
#include "fasdump.c"

/* this will be used for lines, and for structures that require some
raw storage */

#define check_fs_args(ar,ind) \
    if (type_of(ar) != t_fat_string) FEerror("Not a vector with leader",0); \
   if ((ind >= (ar->fs.fs_dim)) \
       ||(ind < 0)) FEerror("subscript out of bounds",0)
   
check_type_fat_string(p)
object *p;
{
BEGIN:
	if (type_of(*p)==t_fat_string) return;
	*p = wrong_type_argument(Sfat_string, *p);
	goto BEGIN;
      }
      

void
siLfsref()
{ check_arg(2);
  {register int  ind = fix(vs_base[1]);
   register object ar =  vs_base[0];
   check_fs_args(ar,ind);
   vs_base[0]=make_fixnum((int) (ar->fs.fs_self[ind]));
   vs_top=vs_base+1;}}

void
siLfsset()
{register object *base,ar;
 register int ind;
 check_arg(3);
 base=vs_base;
 ar=base[0];
 check_type_integer(&base[1]);
 ind =fix(base[1]); 
 check_fs_args(ar,ind);
 base[0]=base[2];
 ar->fs.fs_self[ind]=fix(base[0]);
 vs_top=base+1;
}

#define check_fs_leader(ar,ind) \
      if (type_of(ar) != t_fat_string) FEerror("Not a vector with leader",0); \
      if ((ind >= ar->fs.fs_leader_length)||(ind < 0)) FEerror("subscript out of bounds",0)


fs_leader_ref(ar,ind)
     register object ar;
     register int ind;
{ check_arg(2);
  check_fs_leader(ar,ind);
  return (int) fs_leader(ar,ind);
}


void
check_raw(raw,i)
     unsigned int raw;
     int i;
{if (!(raw & (1 << i))) FEerror("Slot not raw",0);}


void
siLfs_leader_ref()
{ register object *base;
  base=vs_base;
  base[0]=(object) fs_leader_ref(base[0],fix(base[1]));
  vs_top=base+1;
}

void
siLfixnum_fs_leader_ref()
{ register object *base;
  base=vs_base;
  check_raw((base[0]->fs.fs_raw),fix(base[1]));
  base[0]=make_fixnum(fs_leader_ref(base[0],fix(base[1])));
  vs_top=base+1;
}


void
fs_leader_set(ar,ind,val)
 register object ar;
  register  int ind;
     object val;
{  check_arg(3);
  check_fs_leader(ar,ind);
  fs_leader(ar,ind)=  val;
}


void
siLfs_leader_set()
{ register object *base;
  base=vs_base;
  fs_leader_set(base[0],fix(base[1]), base[2]);
  base[0]=base[2];
  vs_top=base+1;}

void
siLfixnum_fs_leader_set()
{ register object *base;
  base=vs_base;
  check_type_integer(&base[2]);
  check_raw((base[0])->fs.fs_raw,fix(base[1]));
  fs_leader_set(base[0],fix(base[1]),(object) fix(base[2]));
  base[0]=base[2];
  vs_top=base+1;}

void
mark_fat_string(x)
     object x;
{register char *cp;
 { int i=0,raw=x->fs.fs_raw;
   cp = (char *) x->fs.fs_self;
   while (i < x->fs.fs_leader_length)
     {if (raw & 1) ;
      else mark_object(fs_leader(x,i));
      raw=( raw >> 1); i++;
    }}
 {int leader_size = (x->fs.fs_leader_length) * sizeof(object *);
  int body_size = leader_size + (x->fs.fs_dim)*sizeof(fatchar);
  cp=cp-leader_size;
  if ((int)what_to_collect >= (int)t_contiguous) {
    if (inheap(cp)) {
      if (what_to_collect == t_contiguous)
	mark_contblock(cp,body_size);
    }
    else x->fs.fs_self =
      (fatchar *) ((char *)copy_relblock(cp,body_size) + leader_size);
  }}}
   
void
siLfs_array_total_size()
{vs_top=vs_base+1;
  check_type_fat_string(&vs_base[0]);
 vs_base[0]=make_fixnum(vs_base[0]->fs.fs_dim);
}

void
siLfs_fill_pointer()
{vs_top=vs_base+1;
  check_type_fat_string(&vs_base[0]);
 vs_base[0]=make_fixnum(vs_base[0]->fs.fs_fillp);
}


void
siLset_fs_fill_pointer()
{check_arg(2);
 check_type_fat_string(&vs_base[0]);
 vs_top=vs_base+1;
 vs_base[0]->fs.fs_fillp = fix(vs_base[1]);
}


object
make_fat_string(dim,raw,lleng,staticp)
int dim,raw,lleng;
{object x;
 x=alloc_object(t_fat_string);
 vs_push(x);
 x->fs.fs_dim=dim;
 x->fs.fs_raw=raw;
 x->fs.fs_leader_length=lleng;
 x->fs.fs_fillp=0;
 alloc_fs(x,staticp);
 return x;
}

void
siLmake_fat_string()
{ register object *base;
 check_arg(4);
 base=vs_base;
 base[0]=make_fat_string (fix(base[0]),fix(base[1]),fix(base[2]),
			  (base[3]!=Cnil));
 vs_top=base+1;
}


alloc_fs(x,staticp)
object x; int staticp;
{char *cp, *actual_cp ;
 register object *obp;
 char *(*f)();
 int leader_size=sizeof(object *)*(x->fs.fs_leader_length);
 if (staticp)
   f = alloc_contblock;
 else
   f = alloc_relblock;
 obp=(object *)(cp= (*f)(sizeof(fatchar) * (x->fs.fs_dim)
			+leader_size));
 actual_cp=cp+leader_size;
 while(obp <  (object *) actual_cp)
   {*obp=Cnil;
    obp++;}
 x->fs.fs_self=(fatchar *)actual_cp;
}


object siLprofile_array;
#ifdef NO_PROFILE
profil()
{;}
#endif

void
siLprofile() /*(start-address scale) where scale is 0 <= n <= 256 */
{
object ar=siLprofile_array->s.s_dbind;
if (type_of(ar)!=t_string)
      FEerror("si:*Profile-array* not a string",0);
if((vs_top-vs_base != 2) ||
   type_of(vs_base[0])!=t_fixnum ||   type_of(vs_base[1])!=t_fixnum)
     FEerror("Needs start address and scale as args",0);
  profil((char *) (ar->ust.ust_self), (ar->ust.ust_dim),
       fix(vs_base[0]),fix(vs_base[1]) << 8);
}

void
siLfunction_start()
{check_arg(1);
 if(type_of(vs_base[0])!=t_cfun) FEerror("not compiled function",0);
 vs_base[0]=make_fixnum((int) (vs_base[0]->cf.cf_self));
}

/* begin fasl stuff*/

#include "ext_sym.h"
#ifdef AIX3
#include <sys/ldr.h>
char *data_load_addr =0;
#endif

read_special_symbols(symfile)
char *symfile;
{FILE *symin;
 char *symbols;
 int i,jj;
 struct lsymbol_table tab;
#ifdef AIX3
 {char buf[500];
  struct ld_info * ld;
 loadquery(L_GETINFO,buf,sizeof(buf));
  ld = (struct ld_info *)buf;
  data_load_addr = ld->ldinfo_dataorg ;}
#endif  
 if (!(symin=fopen(symfile,"r")))
   {perror(symfile);exit(1);};
 if(!fread((char *)&tab,sizeof(tab),1,symin))
   FEerror("No header",0);
 symbols=malloc(tab.tot_leng);
 c_table.alloc_length=( (PTABLE_EXTRA+ tab.n_symbols));
 (c_table.ptable) = (TABL *) malloc(sizeof(struct node) * c_table.alloc_length);
 if (!(c_table.ptable)) {perror("could not allocate"); exit(1);};
 i=0; c_table.length=tab.n_symbols;
 while(i < tab.n_symbols)
   { fread((char *)&jj,sizeof(int),1,symin);
#ifdef FIX_ADDRESS
     FIX_ADDRESS(jj);
#endif       
     (SYM_ADDRESS(c_table,i))=jj;
     SYM_STRING(c_table,i)=symbols;
 
     while( *(symbols++) =   getc(symin)) 
       {;}
/*     dprintf( name %s ,  SYM_STRING(c_table,i));
     dprintf( addr %d , jj);
*/
     i++;
   }

 /*
   for(i=0;i< 5;i++)
   {printf("Symbol: %d %s %d \n",i,SYM_STRINGN(c_table,i),
   SYM_ADDRESS(*ptable,i));}
   */
 if (symin) fclose(symin);
}

node_compare(node1,node2)
char *node1, *node2;
{ return(strcmp( ((struct node *)node1)->string,
	         ((struct node *)node2)->string));}


void
siLread_externals()
{check_arg(1);
 {object x=vs_base[0];
  unsigned int n;
  char *str;
  n=x->st.st_fillp;
 check_type_string(&x);
 str=malloc(n+1);
  str[n]=NULL;
 (void) strncpy(str,x->st.st_self,n);
 read_special_symbols(str);
  /* we sort them since these are used by the sfasl loader too */
qsort((char*)(c_table.ptable),(int)(c_table.length),sizeof(struct node),node_compare);
 free(str);}}

#define CFUN_LIM 10000

int maxpage;
object siLcdefn;

#define CF_FLAG (1 << 31) 


cfuns_to_combined_table(n) /* non zero n will ensure new table length */
unsigned int n;
{int ii=0;  
 STATIC int i, j;
 STATIC object x;
 STATIC char *p,*cf_addr;
 STATIC struct typemanager *tm;
 if (! (n || combined_table.ptable)) n=CFUN_LIM;
 if (n && combined_table.alloc_length < n)
   { 
     (combined_table.ptable)=NULL;
     (combined_table.ptable)= (TABL *)malloc(n* sizeof(struct node));
     if(!combined_table.ptable)
       FEerror("unable to allocate",0);
     combined_table.alloc_length=n;}

 for (i = 0;  i < maxpage;  i++) {
   if ((enum type)type_map[i]!=tm_table[(short)t_cfun].tm_type &&
       (enum type)type_map[i]!=tm_table[(short)t_gfun].tm_type &&
       (enum type)type_map[i]!=tm_table[(short)t_sfun].tm_type &&
       (enum type)type_map[i]!=tm_table[(short)t_vfun].tm_type
       )
     continue;
   tm = tm_of((enum type)type_map[i]);
   p = pagetochar(i);
   for (j = tm->tm_nppage; j > 0; --j, p += tm->tm_size) {
     x = (object)p;
     if (type_of(x)!=t_cfun &&
	 type_of(x)!=t_sfun &&
	 type_of(x)!=t_vfun &&
	 type_of(x)!=t_gfun
	 ) continue;
     if ((x->d.m == FREE) || x->cf.cf_self == NULL)
       continue;
	/* the cdefn things are the proclaimed call types. */
     cf_addr=(char * ) ((unsigned int)(x->cf.cf_self));
	
     SYM_ADDRESS(combined_table,ii)=(unsigned int)cf_addr;
     SYM_STRING(combined_table,ii)= (char *)(CF_FLAG | (unsigned int)x) ;
/*       (x->cf.cf_name ? x->cf.cf_name->s.st_self : NULL) ; */
     combined_table.length = ++ii;
     if (ii >= combined_table.alloc_length)
       FEerror("Need a larger combined_table",0);
   }
		
 }
}

address_node_compare(node1,node2)
char *node1, *node2;
{unsigned int a1,a2;
 a1=((struct node *)node1)->address;
 a2=((struct node *)node2)->address;
 if (a1> a2) return 1;
 if (a1< a2) return -1;
 return 0;
}
 

void
siLset_up_combined()
{unsigned int n=0;
 if (((vs_top - vs_base) == 1)&&type_of(vs_base[0])==t_fixnum)
   n = (unsigned int) fix(vs_base[0]);
 cfuns_to_combined_table(n);
 if (c_table.ptable)
   {int j,k;
    if((k=combined_table.length)+c_table.length >=
       combined_table.alloc_length)
      cfuns_to_combined_table(combined_table.length+c_table.length +20);
    for(j = 0; j < c_table.length;)
    { SYM_ADDRESS(combined_table,k) =SYM_ADDRESS(c_table,j);
      SYM_STRING(combined_table,k) =SYM_STRING(c_table,j);
      k++;j++;
    };
    combined_table.length += c_table.length ;}
 qsort((char*)combined_table.ptable,(int)combined_table.length,
       sizeof(struct node),address_node_compare);
}

static int  prof_start;
prof_ind(address,scale)
     unsigned int address;
{address = address - prof_start ;
 if (address > 0) return ((address * scale) >> 8) ;
 return 0;
}

/* sum entries AAR up to DIM entries */
string_sum(aar,dim)
register unsigned char *aar;
unsigned int dim;
{register unsigned char *endar;
 register unsigned int count = 0;
endar=aar+dim;
 for ( ; aar< endar; aar++)
   count += *aar;
 return count;
}

void
siLdisplay_profile()
{if (!combined_table.ptable)
   FEerror("must symbols first",0);
   check_arg(2);
   {unsigned int prev,next,upto,dim,total;
    int j,scale,count;
    unsigned char *ar;
    object obj_ar;
    obj_ar=siLprofile_array->s.s_dbind;
    if (type_of(obj_ar)!=t_string)
      FEerror("si:*Profile-array* not a string",0);
    ar=obj_ar->ust.ust_self;
    scale=fix(vs_base[1]);
    prof_start=fix(vs_base[0]);
    vs_top=vs_base;
    dim= (obj_ar->ust.ust_dim);

    total=string_sum(ar,dim);
  
    j=0;
    {int i, finish = combined_table.length-1;
     for(i =0,prev=SYM_ADDRESS(combined_table,i); i< finish;
	 prev=next)
       { ++i;
	 next=SYM_ADDRESS(combined_table,i);
	 if ( prev < prof_start) continue;
	 upto=prof_ind(next,scale);
	 if (upto >= dim) upto=dim;
	 {char *name; unsigned int uname;
	  count=0;
	  for( ; j<upto;j++)
	    count += ar[j];
	  if (count > 0) {
	    name=SYM_STRING(combined_table,i-1);
	    uname = (unsigned int) name;
	    printf("\n%6.2f%% (%5d): ",(100.0*count)/total, count);
	    fflush(stdout);
	    if (CF_FLAG & uname)
	      {if (~CF_FLAG & uname) prin1( ((object) (~CF_FLAG & uname))->cf.cf_name,Cnil);}
	     else if (name ) printf("%s",name);};
	  if (upto==dim) goto TOTALS ;
	  
	}}}
 TOTALS:
  printf("\nTotal ticks %d",total);fflush(stdout);
}}

#ifdef SFASL
int build_symbol_table();
#endif


/* end fasl stuff*/


/* These are some low level hacks to allow determining the address
   of an array body, and to allow jumping to inside the body
   of the array */

siLarray_adress()
{check_arg(1);
 vs_base[0]=make_fixnum((int) (&(vs_base[0]->st.st_self[0])));
}

/* This is some very low level code for hacking invokation of
   m68k instructions in a lisp array.  The index used should be
   a byte index.  So invoke(ar,3) jmps to byte ar+3.
   */

#ifdef CLI

invoke(ar)
char *ar;
{asm("movel a6@(8),a0");
 asm("jmp a0@");
}
/* save regs (2 3 4 5 6 7  10 11 12 13 14) and invoke restoring them */
save_regs_invoke(ar)
char *ar;
{asm("moveml #0x3f3e,sp@-");
 invoke(ar);
 asm("moveml a6@(-44),#0x7cfc");
}
siLsave_regs_invoke()
{int x;
 check_arg(2);
  check_type_integer(&vs_base[1]);
  x=save_regs_invoke((vs_base[0]->st.st_self)+fix(vs_base[1]));
 vs_top=vs_base+1;
 vs_base[0]=make_fixnum(x);
}


#endif

init_fat_string()
{make_si_function("ARRAY-ADDRESS",siLarray_adress);
#ifdef CLI
 make_si_function("SAVE-REGS-INVOKE",siLsave_regs_invoke);
#endif 
 make_si_function("FSREF",siLfsref);
 make_si_function("FSSET",siLfsset);
 make_si_function("FS-LEADER-REF",siLfs_leader_ref);
 make_si_function("FS-LEADER-SET",siLfs_leader_set);
 make_si_function("FIXNUM-FS-LEADER-SET",siLfixnum_fs_leader_set);
 make_si_function("FIXNUM-FS-LEADER-REF",siLfixnum_fs_leader_ref);
 make_si_function("SET-FS-FILL-POINTER",siLset_fs_fill_pointer);
 make_si_function("FS-ARRAY-TOTAL-SIZE",siLfs_array_total_size);
 make_si_function("FS-FILL-POINTER",siLfs_fill_pointer);
 make_si_function("MAKE-FAT-STRING",siLmake_fat_string);
 make_si_function("FUNCTION-START",siLfunction_start);
 make_si_function("PROFILE",siLprofile);
 make_si_function("READ-EXTERNALS",siLread_externals);
 make_si_function("SET-UP-COMBINED",siLset_up_combined);
 make_si_function("DISPLAY-PROFILE",siLdisplay_profile);
 make_si_constant("*ASH->>*",(-1==(((int)-1) >> 50))? Ct :Cnil);
#ifdef SFASL
 make_si_function("BUILD-SYMBOL-TABLE",build_symbol_table);
#endif
 siLprofile_array=make_si_special("*PROFILE-ARRAY*",Cnil);
 Sfat_string = make_ordinary("FAT-STRING");
 enter_mark_origin(&Sfat_string);
 init_fasdump();
 
}







