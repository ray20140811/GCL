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
#ifndef COM_LENG
#define COM_LENG
#endif

/*  alloc.c  */
char *alloc_page();
object alloc_object();
char *alloc_contblock();
char *alloc_relblock();

/*  array.c  */
enum aelttype array_elttype();
object aref();
object aset();
object aref1();
object aset1();

/*  assignment.s  */

/*  backq.c  */
int backq_level;

/*  bds.c  */

/*  big.c  */
object stretch_big();
object copy_big();
object copy_to_big();
object big_minus();
object big_plus();
object big_times();
object normalize_big_to_object();
double big_to_double();

/* bind.c */
object ANDoptional;
object ANDrest;
object ANDkey;
object ANDallow_other_keys;
object ANDaux;
object Kallow_other_keys;
object find_special();
object let_bind();
object letA_bind();

/* block.c */

/*  cfun.c  */
object make_cfun();
object MF();
object MM();
object make_function();
object make_si_function();
object make_special_form();
object make_macro();

/*  character.d  */
object STreturn;
object STspace;
object STrubout;
object STpage;
object STtab;
object STbackspace;
object STlinefeed;
object STnewline;
object coerce_to_character();

/*  catch.c  */

/*  cmpaux.c  */
char object_to_char();
float object_to_float();
double object_to_double();

/*  error.c  */
object Kerror;
object Kwrong_type_argument;
object Kcatch;
object Kprotect;
object Kcatchall;
object Ktoo_few_arguments;
object Ktoo_many_arguments;
object Kunexpected_keyword;
object Kinvalid_form;
object Kunbound_variable;
object Kinvalid_variable;
object Kundefined_function;
object Kinvalid_function;
object wrong_type_argument();

/*  eval.c  */
object Sapply;
object Sfuncall;
object simple_lispcall();
object simple_lispcall_no_event();
object simple_symlispcall();
object simple_symlispcall_no_event();
object Vevalhook;
object Vapplyhook;
object ieval();
object ifuncall1();
object ifuncall2();
object ifuncall3();

/*  unixfasl.c  fasload.c  */

/*  file.d  */
object Vstandard_input;
object Vstandard_output;
object Verror_output;
object Vquery_io;
object Vdebug_io;
object Vterminal_io;
object Vtrace_output;
object Kabort;
object Kdirection;
object Kinput;
object Koutput;
object Kio;
object Kprobe;
object Kelement_type;
object Kdefault;
object Kif_exists;
object Knew_version;
object Krename;
object Krename_and_delete;
object Koverwrite;
object Kappend;
object Ksupersede;
object Kif_does_not_exist;
object Kcreate;
object Kprint;
object Kverbose;
object Kset_default_pathname;
object Vload_verbose;
object FASL_string;
object stream_element_type();
object open_stream();
object make_two_way_stream();
object make_echo_stream();
object make_string_input_stream();
object make_string_output_stream();
object get_output_stream_string();
object read_fasl_data();

#ifdef UNIX
/*  unixfsys.c  */
FILE *backup_fopen();
#else
/*  filesystem.c  */
FILE *backup_fopen();
#endif

/*  frame.c  */
frame_ptr frs_sch();
frame_ptr frs_sch_catch();

/*  gbc.c  */
bool GBC_enable;

/*  let.c  */

/*  lex.c  */
object assoc_eq();
object lex_tag_sch();
object lex_block_sch();

/*  list.d  */
object Ktest;
object Ktest_not;
object Kkey;
object car();
object cdr();
object kar();
object kdr();
object caar();
object cadr();
object cdar();
object cddr();
object caaar();
object caadr();
object cadar();
object caddr();
object cdaar();
object cdadr();
object cddar();
object cdddr();
object caaaar();
object caaadr();
object caadar();
object caaddr();
object cadaar();
object cadadr();
object caddar();
object cadddr();
object cdaaar();
object cdaadr();
object cdadar();
object cdaddr();
object cddaar();
object cddadr();
object cdddar();
object cddddr();
object nth();
object nthcdr();
object make_cons();
object list();
object listA();
object append();
object copy_list();
object nconc();

/*  macros.c  */
object Vmacroexpand_hook;
object siSdefmacroA;
object macro_expand();

/*  main.c  */
int ARGC;
char **ARGV;
#ifdef UNIX
char **ENVP;
#endif


object siVsystem_directory;
#ifdef UNIX
char *kcl_self;
#endif
#if !defined(IN_MAIN) || !defined(ATT)
extern char lisp_implementation_version[COM_LENG];
extern char system_directory[COM_LENG];
bool initflag;
#endif
char *merge_system_directory();

/*  mapfun.c  */

/*  multival.c  */

/*  number.c  */
object shortfloat_zero;
object longfloat_zero;
object make_fixnum();
object make_ratio();
object make_shortfloat();
object make_longfloat();
object make_complex();
double number_to_double();

/*  num_pred.c  */

/*  num_comp.c  */

/*  num_arith  */
object bignum2();
object bignum3();
object number_to_complex();
object complex_plus();
object number_plus();
object number_negate();
object number_minus();
object number_times();
object number_divide();
object integer_divide1();
object get_gcd();
object get_lcm();
object one_plus();
object one_minus();

/*  num_co.c  */
object double_to_integer();
object remainder();

/*  num_log.c  */
object shift_integer();

/*  package.d  */
object lisp_package;
object user_package;
object keyword_package;
object system_package;
object Vpackage;
object Kinternal;
object Kexternal;
object Kinherited;
object Knicknames;
object Kuse;
int intern_flag;
object uninterned_list;
object make_package();
object in_package();
object rename_package();
object find_package();
object coerce_to_package();
object current_package();
object intern();
object find_symbol();

/*  pathname.d  */
object Vdefault_pathname_defaults;
object Kwild;
object Knewest;
object Kstart;
object Kend;
object Kjunk_allowed;
object Khost;
object Kdevice;
object Kdirectory;
object Kname;
object Ktype;
object Kversion;
object Kdefaults;
object Kroot;
object Kcurrent;
object Kparent;
object Kper;
object parse_namestring();
object coerce_to_pathname();
object default_device();
object merge_pathnames();
object namestring();
object coerce_to_namestring();

/*  prediate.c  */

/*  print.d  */
object Kupcase;
object Kdowncase;
object Kcapitalize;
object Kstream;
object Kescape;
object Kpretty;
object Kcircle;
object Kbase;
object Kradix;
object Kcase;
object Kgensym;
object Klevel;
object Klength;
object Karray;
object Vprint_escape;
object Vprint_pretty;
object Vprint_circle;
object Vprint_base;
object Vprint_radix;
object Vprint_case;
object Vprint_gensym;
object Vprint_level;
object Vprint_length;
object Vprint_array;
object *PRINTvs_top;
object *PRINTvs_limit;
object PRINTstream;
bool PRINTescape;
bool PRINTpretty;
bool PRINTcircle;
int PRINTbase;
bool PRINTradix;
object PRINTcase;
bool PRINTgensym;
int PRINTlevel;
int PRINTlength;
bool PRINTarray;
int (*write_ch_fun)();
object princ();
object prin1();
object print();
object terpri();
object siSpretty_print_format;

/*  read.d  */
object standard_readtable;
object Vreadtable;
object Vread_default_float_format;
object Vread_base;
object Vread_suppress;
object READtable;
int READdefault_float_format;
int READbase;
bool READsuppress;
object siSsharp_comma;
bool escape_flag;
object delimiting_char;
bool detect_eos_flag;
bool in_list_flag;
bool dot_flag;
bool preserving_whitespace_flag;
object default_dispatch_macro;
object big_register_0;
int sharp_eq_context_max;
object read_char();
object peek_char();
object read_object_recursive();
object read_object_non_recursive();
object standard_read_object_non_recursive();
object read_object();
object parse_number();
object parse_integer();
object copy_readtable();
object current_readtable();
object patch_sharp();
object read_fasl_vector();

/*  reference.c  */
object symbol_function();


/*  sequence.d  */
object alloc_simple_vector();
object alloc_simple_bitvector();
object elt();
object elt_set();
object reverse();
object nreverse();

/*  structure.c  */
object siLs_data;
object structure_ref();
object structure_set();
object structure_to_list();

/*  string.d  */
object alloc_simple_string();
object make_simple_string();
object copy_simple_string();
object coerce_to_string();

/*  symbol.d  */
object string_register;
object gensym_prefix;
int gensym_counter;
object gentemp_prefix;
int gentemp_counter;
object token;
object make_symbol();
object make_ordinary();
object make_special();
object make_constant();
object make_si_ordinary();
object make_si_special();
object make_si_constant();
object make_keyword();
object symbol_value();
object getf();
object get();
object putf();
object putprop();
object remprop();
object gensym();		/*  to be deleted  */

#ifdef UNIX
/*  unixsys.c  */
#else
/*  sys.c  */
#endif

#ifdef UNIX
/*  unixtime.c  */
object unix_time_to_universal_time();
#else
/*  time.c  */
#endif

/*  toplevel.c  */
object Sspecial,Sdeclare;
object siSvariable_documentation;
object siSfunction_documentation;

/*  typespec.c  */
object
St,		Snil,		Scommon,
Snull,		Scons,		Slist,		Ssymbol,
Sarray,		Svector,	Sbit_vector,	Sstring,
Ssequence,
Ssimple_array,	Ssimple_vector,	Ssimple_bit_vector,
						Ssimple_string,
Scompiled_function,
				Spathname,	Scharacter,
Snumber,	Srational,	Sfloat,		Sstring_char,
Sinteger,	Sratio,		Sshort_float,	Sstandard_char,
Sfixnum,	Scomplex,	Ssingle_float,	Spackage,
Sbignum,	Srandom_state,	Sdouble_float,	Sstream,
Sbit,		Sreadtable,	Slong_float,	Shash_table;
object Sstructure;
object Ssatisfies;
object Smember;
object Snot;
object Sor;
object Sand;
object Svalues;
object Smod;
object Ssigned_byte;
object Sunsigned_byte;
object Ssigned_char;
object Sunsigned_char;
object Ssigned_short;
object Sunsigned_short;
object SA;
object Splusp;
object TSor_symbol_string;
object TSor_string_symbol;
object TSor_symbol_string_package;
object TSnon_negative_integer;
object TSpositive_number;
object TSor_integer_float;
object TSor_rational_float;
#ifdef UNIX
object TSor_pathname_string_symbol;
#endif
object TSor_pathname_string_symbol_stream;

int interrupt_flag;		/* console interupt flag */
int interrupt_enable;		/* console interupt enable */

/*  CMPtemp  */
object CMPtemp;
object CMPtemp1;
object CMPtemp2;
object CMPtemp3;

