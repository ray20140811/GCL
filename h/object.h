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
	object.h
*/

/*
	Some system constants.
*/

#define	TRUE		1	/*  boolean true value  */
#define	FALSE		0	/*  boolean false value  */

#ifdef SGC
#define FIRSTWORD     short t;  char s,m
#else
#define FIRSTWORD     short t; short m
#endif

#define	NBPP		4	/*  number of bytes per pointer  */

#ifndef PAGEWIDTH
#define	PAGEWIDTH	11	/*  page width  */
#endif
				/*  log2(PAGESIZE)  */
#define	PAGESIZE	(1 << PAGEWIDTH)	/*  page size in bytes  */


#define	CHCODELIM	256	/*  character code limit  */
				/*  ASCII character set  */
#define	CHFONTLIM	1	/*  character font limit  */
#define	CHBITSLIM	1	/*  character bits limit  */
#define	CHCODEFLEN	8	/*  character code field length  */
#define	CHFONTFLEN	0	/*  character font field length  */
#define	CHBITSFLEN      0	/*  character bits field length  */

#define	PHTABSIZE	512	/*  number of entries  */
				/*  in the package hash table  */

#define	ARANKLIM	64	/*  array rank limit  */

#define	RTABSIZE	CHCODELIM
				/*  read table size  */

#define	CBMINSIZE	64	/*  contiguous block minimal size  */

#ifndef CHAR_SIZE
#define CHAR_SIZE        8     /* number of bits in a char */
#endif

typedef int bool;
typedef int fixnum;
typedef float shortfloat;
typedef double longfloat;
typedef unsigned short fatchar;


#define SIGNED_CHAR(x) (((char ) -1) < (char )0 ? (char) x \
		  : (x >= (1<<(CHAR_SIZE-1)) ? \
		     x - (((int)(1<<(CHAR_SIZE-1))) << 1) \
		     : (char ) x))


/*
	Definition of the type of LISP objects.
*/
typedef union lispunion *object;

typedef union int_object iobject;
union int_object {object o; int i;};

/*
	OBJect NULL value.
	It should not coincide with any legal object value.
*/
#define	OBJNULL		((object)NULL)

/*
	Definition of each implementation type.
*/

struct fixnum_struct {
		FIRSTWORD;
	fixnum	FIXVAL;		/*  fixnum value  */
};
#define	fix(obje)	(obje)->FIX.FIXVAL

#define	SMALL_FIXNUM_LIMIT	1024

struct fixnum_struct small_fixnum_table[2*SMALL_FIXNUM_LIMIT];

#define	small_fixnum(i)  \
	(object)(small_fixnum_table+SMALL_FIXNUM_LIMIT+(i))

struct shortfloat_struct {
			FIRSTWORD;
	shortfloat	SFVAL;	/*  shortfloat value  */
};
#define	sf(obje)	(obje)->SF.SFVAL

struct longfloat_struct {
			FIRSTWORD;
	longfloat	LFVAL;	/*  longfloat value  */
};
#define	lf(obje)	(obje)->LF.LFVAL

struct bignum {
			FIRSTWORD;
	long             *big_self;	/*  bignum body  */
	int		big_length;	/*  bignum length  */
};

struct ratio {
		FIRSTWORD;
	object	rat_den;	/*  denominator  */
				/*  must be an integer  */
	object	rat_num;	/*  numerator  */
				/*  must be an integer  */
};

struct complex {
		FIRSTWORD;
	object	cmp_real;	/*  real part  */
				/*  must be a number  */
	object	cmp_imag;	/*  imaginary part  */
				/*  must be a number  */
};

struct character {
			FIRSTWORD;
	unsigned short	ch_code;	/*  code  */
	unsigned char	ch_font;	/*  font  */
	unsigned char	ch_bits;	/*  bits  */
};

#ifdef MV

#endif

#ifdef AV
struct character character_table1[256+128];
#endif
#define character_table (character_table1+128)
#define	code_char(c)		(object)(character_table+(c))
#define	char_code(obje)		(obje)->ch.ch_code
#define	char_font(obje)		(obje)->ch.ch_font
#define	char_bits(obje)		(obje)->ch.ch_bits

enum stype {			/*  symbol type  */
	stp_ordinary,		/*  ordinary  */
	stp_constant,		/*  constant  */
        stp_special		/*  special  */
};

#define	Cnil			((object)&Cnil_body)
#define	Ct			((object)&Ct_body)

struct symbol {
		FIRSTWORD;
	object	s_dbind;	/*  dynamic binding  */
	int	(*s_sfdef)();	/*  special form definition  */
				/*  This field coincides with c_car  */

#define	NOT_SPECIAL		((int (*)())Cnil)

#define	s_fillp		st_fillp
#define	s_self		st_self

	int	s_fillp;	/*  print name length  */
	char	*s_self;	/*  print name  */
				/*  These fields coincide with  */
				/*  st_fillp and st_self.  */

	object	s_gfdef;        /*  global function definition  */
				/*  For a macro,  */
				/*  its expansion function  */
				/*  is to be stored.  */
	object	s_plist;	/*  property list  */
	object	s_hpack;	/*  home package  */
				/*  Cnil for uninterned symbols  */
	short	s_stype;	/*  symbol type  */
				/*  of enum stype  */
	short	s_mflag;	/*  macro flag  */
};

struct symbol Cnil_body, Ct_body;

struct package {
		FIRSTWORD;
	object	p_name;		/*  package name  */
				/*  a string  */
	object	p_nicknames;	/*  nicknames  */
				/*  list of strings  */
	object	p_shadowings;	/*  shadowing symbol list  */
	object	p_uselist;	/*  use-list of packages  */
	object	p_usedbylist;	/*  used-by-list of packages  */
	object	*p_internal;	/*  hashtable for internal symbols  */
	object	*p_external;	/*  hashtable for external symbols  */
	int p_internal_size;    /* size of internal hash table*/
	int p_external_size;     /* size of external hash table */
	int p_internal_fp;       /* [rough] number of symbols */
        int p_external_fp;    /* [rough]  number of symbols */
	struct package
		*p_link;	/*  package link  */
};

/*
	The values returned by intern and find_symbol.
	File_symbol may return 0.
*/
#define	INTERNAL	1
#define	EXTERNAL	2
#define	INHERITED	3

/*
	All the packages are linked through p_link.
*/
struct package *pack_pointer;	/*  package pointer  */

struct cons {
		FIRSTWORD;
	object	c_cdr;		/*  cdr  */
	object	c_car;		/*  car  */
};

enum httest {			/*  hash table key test function  */
	htt_eq,			/*  eq  */
	htt_eql,		/*  eql  */
	htt_equal		/*  equal  */
};

struct htent {			/*  hash table entry  */
	object	hte_key;	/*  key  */
	object	hte_value;	/*  value  */
};

struct hashtable {		/*  hash table header  */
		FIRSTWORD;
	struct htent
		*ht_self;	/*  pointer to the hash table  */
	object	ht_rhsize;	/*  rehash size  */
	object	ht_rhthresh;	/*  rehash threshold  */
	int	ht_nent;	/*  number of entries  */
	int	ht_size;	/*  hash table size  */
	short	ht_test;	/*  key test function  */
				/*  of enum httest  */
};

enum aelttype {			/*  array element type  */
	aet_object,		/*  t  */
	aet_ch,			/*  string-char  */
	aet_bit,		/*  bit  */
	aet_fix,		/*  fixnum  */
	aet_sf,			/*  short-float  */
	aet_lf,			/*  long-float  */
	aet_char,               /* signed char */
        aet_uchar,               /* unsigned char */
	aet_short,              /* signed short */
	aet_ushort,             /*  unsigned short   */
	  };

struct array {			/*  array header  */
		FIRSTWORD;
	short	a_rank;		/*  array rank  */
/*	short	v_hasfillp;	    has-fill-pointer flag  */
	short	a_adjustable;	/*  adjustable flag  */
	int	a_dim;		/*  dimension  */
	int	*a_dims;	/*  table of dimensions  */
/*	int	v_fillp;	    fill pointer  */
	object	*a_self;	/*  pointer to the array  */
	object	a_displaced;	/*  displaced  */
	short	a_elttype;	/*  element type  */
	short	a_offset;	/*  bitvector offset  */
};



struct vector {			/*  vector header  */
		FIRSTWORD;
	short	v_hasfillp;	/*  has-fill-pointer flag  */
	short	v_adjustable;	/*  adjustable flag  */
	int	v_dim;		/*  dimension  */
	int	v_fillp;	/*  fill pointer  */
				/*  For simple vectors,  */
				/*  v_fillp is equal to v_dim.  */
	object	*v_self;	/*  pointer to the vector  */
	object	v_displaced;	/*  displaced  */
	short	v_elttype;	/*  element type  */
	short	v_offset;	/*  not used  */
};

struct string {			/*  string header  */
		FIRSTWORD;
	short	st_hasfillp;	/*  has-fill-pointer flag  */
	short	st_adjustable;	/*  adjustable flag  */
	int	st_dim;		/*  dimension  */
				/*  string length  */
	int	st_fillp;	/*  fill pointer  */
				/*  For simple strings,  */
				/*  st_fillp is equal to st_dim.  */
	char	*st_self;	/*  pointer to the string  */
	object	st_displaced;	/*  displaced  */
};

struct ustring {
		FIRSTWORD;
	short	ust_hasfillp;
	short	ust_adjustable;
	int	ust_dim;
	int	ust_fillp;
	unsigned char
		*ust_self;
	object	ust_displaced;
};

#define USHORT(x,i) (((unsigned short *)(x)->ust.ust_self)[i])

struct bitvector {		/*  bitvector header  */
		FIRSTWORD;
	short	bv_hasfillp;	/*  has-fill-pointer flag  */
	short	bv_adjustable;	/*  adjustable flag  */
	int	bv_dim;		/*  dimension  */
				/*  number of bits  */
	int	bv_fillp;	/*  fill pointer  */
				/*  For simple bitvectors,  */
				/*  st_fillp is equal to st_dim.  */
	char	*bv_self;	/*  pointer to the bitvector  */
	object	bv_displaced;	/*  displaced  */
	short	bv_elttype;	/*  not used  */
	short	bv_offset;	/*  bitvector offset  */
				/*  the position of the first bit  */
				/*  in the first byte  */
};

struct fixarray {		/*  fixnum array header  */
		FIRSTWORD;
	short	fixa_rank;	/*  array rank  */
	short	fixa_adjustable;/*  adjustable flag  */
	int	fixa_dim;	/*  dimension  */
	int	*fixa_dims;	/*  table of dimensions  */
	fixnum	*fixa_self;	/*  pointer to the array  */
	object	fixa_displaced;	/*  displaced  */
	short	fixa_elttype;	/*  element type  */
	short	fixa_offset;	/*  not used  */
};

struct sfarray {		/*  short-float array header  */
		FIRSTWORD;
	short	sfa_rank;	/*  array rank  */
	short	sfa_adjustable;	/*  adjustable flag  */
	int	sfa_dim;	/*  dimension  */
	int	*sfa_dims;	/*  table of dimensions  */
	shortfloat
		*sfa_self;	/*  pointer to the array  */
	object	sfa_displaced;	/*  displaced  */
	short	sfa_elttype;	/*  element type  */
	short	sfa_offset;	/*  not used  */
};

struct lfarray {		/*  long-float array header  */
		FIRSTWORD;
	short	lfa_rank;	/*  array rank  */
	short	lfa_adjustable;	/*  adjustable flag  */
	int	lfa_dim;		/*  dimension  */
	int	*lfa_dims;	/*  table of dimensions  */
	longfloat
		*lfa_self;	/*  pointer to the array  */
	object	lfa_displaced;	/*  displaced  */
	short	lfa_elttype;	/*  element type  */
	short	lfa_offset;	/*  not used  */
};

struct structure {		/*  structure header  */
		FIRSTWORD;
	object	str_def;	/*  structure definition (a structure)  */
	object	*str_self;	/*  structure self  */
};

struct s_data {object name;
	       int length;
	       object raw;
	       object included;
	       object includes;
	       object staticp;
	       object print_function;
	       object slot_descriptions;
	       object slot_position;
	       int    size;
	       object has_holes;
	     };

#define S_DATA(x) ((struct s_data *)((x)->str.str_self))
#define SLOT_TYPE(def,i) (((S_DATA(def))->raw->ust.ust_self[i]))
#define SLOT_POS(def,i) USHORT(S_DATA(def)->slot_position,i)
#define STREF(type,x,i) (*((type *)(((char *)((x)->str.str_self))+(i))))



enum smmode {			/*  stream mode  */
	smm_input,		/*  input  */
	smm_output,		/*  output  */
	smm_io,			/*  input-output  */
	smm_probe,		/*  probe  */
	smm_synonym,		/*  synonym  */
	smm_broadcast,		/*  broadcast  */
	smm_concatenated,	/*  concatenated  */
	smm_two_way,		/*  two way  */
	smm_echo,		/*  echo  */
	smm_string_input,	/*  string input  */
	smm_string_output,	/*  string output  */
	smm_user_defined        /*  for user defined */ 
};

struct stream {
		FIRSTWORD;
	FILE	*sm_fp;		/*  file pointer  */
	object	sm_object0;	/*  some object  */
	object	sm_object1;	/*  some object */
	int	sm_int0;	/*  some int  */
	int	sm_int1;	/*  some int  */
	char  	*sm_buffer;     /*  ptr to BUFSIZE block of storage */
	short	sm_mode;	/*  stream mode  */
				/*  of enum smmode  */
};


#ifdef BSD
#ifdef SUN3
#define	BASEFF		(unsigned char *)0xffffffff
#else
#define	BASEFF		(char *)0xffffffff
#endif
#endif

#ifdef ATT
#define	BASEFF		(unsigned char *)0xffffffff
#endif

#ifdef E15
#define	BASEFF		(unsigned char *)0xffffffff
#endif

#ifdef MV


#endif

struct random {
			FIRSTWORD;
	unsigned	rnd_value;	/*  random state value  */
};

enum chattrib {			/*  character attribute  */
	cat_whitespace,		/*  whitespace  */
	cat_terminating,	/*  terminating macro  */
	cat_non_terminating,	/*  non-terminating macro  */
	cat_single_escape,	/*  single-escape  */
	cat_multiple_escape,	/*  multiple-escape  */
	cat_constituent		/*  constituent  */
};

struct rtent {				/*  read table entry  */
	enum chattrib	rte_chattrib;	/*  character attribute  */
	object		rte_macro;	/*  macro function  */
	object		*rte_dtab;	/*  pointer to the  */
					/*  dispatch table  */
					/*  NULL for  */
					/*  non-dispatching  */
					/*  macro character, or  */
					/*  non-macro character  */
};

struct readtable {			/*  read table  */
			FIRSTWORD;
	struct rtent	*rt_self;	/*  read table itself  */
};

struct pathname {
		FIRSTWORD;
	object	pn_host;	/*  host  */
	object	pn_device;	/*  device  */
	object	pn_directory;	/*  directory  */
	object	pn_name;	/*  name  */
	object	pn_type;	/*  type  */
	object	pn_version;	/*  version  */
};

struct cfun {			/*  compiled function header  */
		FIRSTWORD;
	object	cf_name;	/*  compiled function name  */
	int	(*cf_self)();	/*  entry address  */
	object	cf_data;	/*  data the function uses  */
				/*  for GBC  */
};

struct cclosure {		/*  compiled closure header  */
		FIRSTWORD;
	object	cc_name;	/*  compiled closure name  */
	int	(*cc_self)();	/*  entry address  */
	object	cc_env;		/*  environment  */
	object	cc_data;	/*  data the closure uses  */
				/*  for GBC  */
	object	*cc_turbo;	/*  turbo charger */
};
struct sfun {
		FIRSTWORD; 
	object	sfn_name;       /* name */
	int	(*sfn_self)();  /* C start address of code */
	object	sfn_data;       /* To object holding VV vector */
	int sfn_argd;           /* description of args + number */

	      };
struct vfun {
		FIRSTWORD; 
	object	vfn_name;       /* name */
	int	(*vfn_self)();  /* C start address of code */
	object	vfn_data;       /* To object holding VV data */
	unsigned short vfn_minargs; /* Min args and where varargs start */
	unsigned short vfn_maxargs;    /* Max number of args */
	      };
struct cfdata {
     FIRSTWORD;
     char *cfd_start;             /* beginning of contblock for fun */
     int cfd_size;              /* size of contblock */
     int cfd_fillp;             /* size of self */
     object *cfd_self;          /* body */
   };
struct fat_string {			/*  vector header  */
		FIRSTWORD;
        unsigned fs_raw : 24;     /* tells if the things in leader are raw */
	unsigned char fs_leader_length;	 /* leader_Length  */
	int	fs_dim;		/*  dimension  */
	int	fs_fillp;	/*  fill pointer  */
				/*  For simple vectors,  */
				/*  fs_fillp is equal to fs_dim.  */
#define fs_leader(ar,i) (((object *)((ar)->fs.fs_self))[-(i+1)])
	fatchar 	*fs_self;	/*  pointer to the vector
Note the leader starts at (int *) *fs_self - fs_leader_length */
};


struct dclosure {		/*  compiled closure header  */
		FIRSTWORD;
	int	(*dc_self)();	/*  entry address  */
	object	*dc_env;	/*  environment  */
};


struct spice {
		FIRSTWORD;
	int	spc_dummy;
};

/*
	dummy type
*/
struct dummy {
	FIRSTWORD;
};

/*
	Definition of lispunion.
*/
union lispunion {
	struct fixnum_struct
			FIX;	/*  fixnum  */
	struct bignum	big;	/*  bignum  */
	struct ratio	rat;	/*  ratio  */
	struct shortfloat_struct
			SF;	/*  short floating-point number  */
	struct longfloat_struct
			LF;	/*  long floating-point number  */
	struct complex	cmp;	/*  complex number  */
	struct character
			ch;	/*  character  */
	struct symbol	s;	/*  symbol  */
	struct package	p;	/*  package  */
	struct cons	c;	/*  cons  */
	struct hashtable
			ht;	/*  hash table  */
	struct array	a;	/*  array  */
	struct fat_string fs; /* fat string fatchar 's */
        struct dclosure dc;
	struct vector	v;	/*  vector  */
	struct string	st;	/*  string  */
	struct ustring	ust;
	struct bitvector
			bv;	/*  bit-vector  */
	struct structure
			str;	/*  structure  */
	struct stream	sm;	/*  stream  */
	struct random	rnd;	/*  random-states  */
	struct readtable
			rt;	/*  read table  */
	struct pathname	pn;	/*  path name  */
	struct cfun	cf;	/*  compiled function  uses value stack] */
	struct cclosure	cc;	/*  compiled closure  uses value stack */
	struct sfun     sfn;    /*  simple function */
	struct vfun     vfn;    /*  function with variable number of args */
	struct cfdata   cfd;    /* compiled fun data */
	struct spice	spc;	/*  spice  */

	struct dummy	d;	/*  dummy  */

	struct fixarray	fixa;	/*  fixnum array  */
	struct sfarray	sfa;	/*  short-float array  */
	struct lfarray	lfa;	/*  long-float array  */
};

/*
	The struct of free lists.
*/
struct freelist {
	FIRSTWORD;
	object	f_link;
};

#define	FREE	(-1)		/*  free object  */

/*
	Implementation types.
*/
enum type {
	t_cons,
	t_start = 0 , /* t_cons, */
	t_fixnum,
	t_bignum,
	t_ratio,
	t_shortfloat,
	t_longfloat,
	t_complex,
	t_character,
	t_symbol,
	t_package,
/*	t_cons,  */
	t_hashtable,
	t_array,
	t_vector,
	t_string,
	t_bitvector,
	t_structure,
	t_stream,
	t_random,
	t_readtable,
	t_pathname,
	t_cfun,
	t_cclosure,
	t_sfun,
        t_gfun,
	t_vfun,
	t_cfdata,
	t_spice,
	t_fat_string,
        t_dclosure,
   
	t_end,
	t_contiguous,		/*  contiguous block  */
	t_relocatable,		/*  relocatable block  */
	t_other			/*  other  */
};
/*
	Type_of.
*/
#define	type_of(obje)	((enum type)(((object)(obje))->d.t))

/*
	Storage manager for each type.
*/
struct typemanager {
	enum type
		tm_type;	/*  type  */
	short	tm_size;	/*  element size in bytes  */
	short   tm_nppage;	/*  number per page  */
	object	tm_free;	/*  free list  */
				/*  Note that it is of type object.  */
	int	tm_nfree;	/*  number of free elements  */
	int	tm_nused;	/*  number of elements used  */
	int	tm_npage;	/*  number of pages  */
	int	tm_maxpage;	/*  maximum number of pages  */
	char	*tm_name;	/*  type name  */
	int	tm_gbccount;	/*  GBC count  */
	object  tm_alt_free;    /*  Alternate free list (swap with tm_free) */
	int     tm_alt_nfree;   /*  Alternate nfree (length of nfree) */
	short   tm_sgc;         /*  this type has at least this many
				    sgc pages */
	short   tm_sgc_minfree;   /* number free on a page to qualify for
				    being an sgc page */
	short   tm_sgc_max;     /* max on sgc pages */
	short   tm_min_grow;    /* min amount to grow when growing */
	short   tm_max_grow;    /* max amount to grow when growing */
	short   tm_growth_percent;  /* percent to increase maxpages */

};

/*
	The table of type managers.
*/
struct typemanager tm_table[ 32  /* (int) t_relocatable */];

#define	tm_of(t)	(&(tm_table[(int)tm_table[(int)(t)].tm_type]))

/*
	Contiguous block header.
*/
struct contblock {		/*  contiguous block header  */
	int	cb_size;	/*  size in bytes  */
	struct contblock
		*cb_link;	/*  contiguous block link  */
};

/*
	The pointer to the contiguous blocks.
*/
struct contblock *cb_pointer;	/*  contblock pointer  */

/*
	Variables for memory management.
*/
int ncb;			/*  number of contblocks  */
int ncbpage;			/*  number of contblock pages  */
int maxcbpage;			/*  maximum number of contblock pages  */
int cbgbccount;			/*  contblock gbc count  */

int holepage;			/*  hole pages  */
int nrbpage;			/*  number of relblock pages  */
int rbgbccount;			/*  relblock gbc count  */

char *rb_start;			/*  relblock start  */
char *rb_end;			/*  relblock end  */
char *rb_limit;			/*  relblock limit  */
char *rb_pointer;		/*  relblock pointer  */
char *rb_start1;		/*  relblock start in copy space  */
char *rb_pointer1;		/*  relblock pointer in copy space  */

char *heap_end;			/*  heap end  */
char *core_end;			/*  core end  */

char *tmp_alloc;

/* make f allocate enough extra, so that we can round
   up, the address given to an even multiple.   Special
   case of size == 0 , in which case we just want an aligned
   number in the address range
   */

#define ALLOC_ALIGNED(f, size,align) \
  (align <= sizeof(long) ? (char *)((f)(size)) : \
   (tmp_alloc = (char *)((f)(size+(size ?(align)-1 : 0)))+(align)-1 , \
   (char *)(align * (((unsigned int)tmp_alloc)/align))))
#define AR_ALLOC(f,n,type) (type *) \
  (ALLOC_ALIGNED(f,(n)*sizeof(type),sizeof(type)))

#ifndef HOLEPAGE
#define	HOLEPAGE	128
#endif


#define	INIT_HOLEPAGE	150
#define	INIT_NRBPAGE	50
#define	RB_GETA		512

/*
	Endp macro.
*/
/*
#define	endp(obje)	((enum type)((endp_temp = (obje))->d.t) == t_cons ? \
			 FALSE : endp_temp == Cnil ? TRUE : \
			 (bool)FEwrong_type_argument(Slist, endp_temp))

object endp_temp;
*/

#define	endp(obje)	endp1(obje)

#ifdef AV
#define	STATIC	register
#endif
#ifdef MV

#endif

#define	TIME_ZONE	(-9)

int FIXtemp;

/*  For IEEEFLOAT, the double may have exponent in the second word
(little endian) or first word.*/

#if defined(I386) || defined(LITTLE_ENDIAN)
#define HIND 1  /* (int) of double where the exponent and most signif is */
#define LIND 0  /* low part of a double */
#else /* big endian */
#define HIND 0
#define LIND 1
#endif
#ifndef VOL
#define VOL
#endif


#define	isUpper(xxx)	(((xxx)&0200) == 0 && isupper(xxx))
#define	isLower(xxx)	(((xxx)&0200) == 0 && islower(xxx))
#define	isDigit(xxx)	(((xxx)&0200) == 0 && isdigit(xxx))
enum ftype {f_object,f_fixnum};

char *alloca_val;
/*          ...xx|xx|xxxx|xxxx|   
		     ret  Narg     */

/*    a9a8a7a6a5a4a3a4a3a2a1a0rrrrnnnnnnnn
         ai=argtype(i)         ret   nargs
 */
#define SFUN_NARGS(x) (x & 0xff) /* 8 bits */
#define RESTYPE(x) (x<<8)   /* 3 bits */
   /* set if the VFUN_NARGS = m ; has been set correctly */
#define VFUN_NARG_BIT (1 <<11) 
#define ARGTYPE(i,x) ((x) <<(12+(i*2)))
#define ARGTYPE1(x)  (1 | ARGTYPE(0,x))
#define ARGTYPE2(x,y) (2 | ARGTYPE(0,x)  | ARGTYPE(1,y))
#define ARGTYPE3(x,y,z) (3 | ARGTYPE(0,x) | ARGTYPE(1,y) | ARGTYPE(2,z))

object make_si_sfun();
object MVloc[10];

/* Set new to be an (object *) whose [i]'th elmt is the
   ith elmnt in a va_list
   MUST_COPY_VA_LIST should be true, if
   ((vl[0] != va_arg(ap,object)) ||
    (vl[1] != va_arg(ap,object)) || .. vl[n-1] != va_arg(ap,object))
   Normal machines have va_list an ordinary array and a copy is unnecessary.
 */
#ifndef MUST_COPY_VA_LIST
#define COERCE_VA_LIST(new,vl,n) new = (object *) (vl)
#else
#define COERCE_VA_LIST(new,vl,n) \
 object Xxvl[65]; \
 {int i; \
  new=Xxvl; \
  if (n >= 65) FEerror("Too long vl"); \
  for (i=0 ; i < (n); i++) new[i]=va_arg(vl,object);}
#endif
#define make_si_vfun(s,f,min,max) \
  make_si_vfun1(s,f,min | (max << 8))

/* Number of args supplied to a variable arg t_vfun
 Used by the C function to set optionals */

struct call_data { object fun;
		   int argd;};
struct call_data fcall;
#define  VFUN_NARGS fcall.argd

/* we sometimes have to touch the header of arrays or structures
   to make sure the page is writable */
#ifdef SGC
#define SGC_TOUCH(x) if ((x)->d.m) system_error(); (x)->d.m=0
#else
#define SGC_TOUCH(x)
#endif

object funcall_cfun();
object clear_compiler_properties();
object siSlambda_block_expanded;

#ifndef FIX_PATH_STRING
#define FIX_PATH_STRING(file) file
#endif
	
