

#define T_INT int
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

/*  alloc.c  */
char *alloc_page();
object alloc_object();
char *alloc_contblock();
char *alloc_relblock();
T_INT init_alloc();
T_INT init_alloc_function();

/*  array.c  */
enum aelttype array_elttype();
T_INT array_allocself();
object aref();
object aset();
object aref1();
object aset1();
T_INT adjust_displaced();
T_INT init_array_function();

/*  assignment.s  */
T_INT setq();
T_INT init_assignment();

/*  backq.c  */
int backq_level;

/*  bds.c  */
T_INT bds_unwind();

/*  big.c  */

object copy_big();
object copy_to_big();
bool big_zerop();
int big_sign();
int big_compare();
int complement_big();
object big_minus();
T_INT add_int_big();
T_INT sub_int_big();
T_INT mul_int_big();
int div_int_big();
object big_plus();
object big_times();
int big_length();
int big_quotient_remainder();
T_INT normalize_big();
object normalize_big_to_object();
double big_to_double();

/* bind.c */
object ANDoptional;
object ANDrest;
object ANDkey;
object ANDallow_other_keys;
object ANDaux;
object Kallow_other_keys;
T_INT lambda_bind();
object find_special();
object let_bind();
object letA_bind();
T_INT init_bind();

/* block.c */
object Sblock;
T_INT init_block();

/*  cfun.c  */
object make_cfun();
object MF();
object MM();
object make_function();
object make_si_function();
object make_special_form();
object make_macro();
T_INT init_cfun();

/*  character.d  */
object STreturn;
object STspace;
object STrubout;
object STpage;
object STtab;
object STbackspace;
object STlinefeed;
object STnewline;
int digitp();
int digit_weight();
bool char_eq();
bool char_equal();
object coerce_to_character();
T_INT init_character();
T_INT init_character_function();

/*  catch.c  */
T_INT init_catch();

/*  cmpaux.c  */
char object_to_char();
T_INT set_VV();
int object_to_int();
float object_to_float();
double object_to_double();

/*  error.c  */
T_INT FEerror();
T_INT FEwrong_type_argument();
T_INT FEtoo_few_arguments();
T_INT FEtoo_few_argumentsF();
T_INT FEtoo_many_arguments();
T_INT FEtoo_many_argumentsF();
T_INT FEunexpected_keyword();
T_INT FEinvalid_form();
T_INT FEunbound_variable();
T_INT FEinvalid_variable();
T_INT FEundefined_function();
T_INT FEinvalid_function();
object Kerror;
object Kwrong_type_argument;
object Ktoo_few_arguments;
object Ktoo_many_arguments;
object Kunexpected_keyword;
object Kinvalid_form;
object Kunbound_variable;
object Kinvalid_variable;
object Kundefined_function;
object Kinvalid_function;
object wrong_type_argument();
object Kcatch;
object Kcatchall;
object Kprotect;
int init_error();

/*  eval.c  */
object Sapply;
object Sfuncall;
T_INT funcall();
T_INT funcall_no_event();
T_INT lispcall();
T_INT lispcall_no_event();
T_INT symlispcall();
T_INT symlispcall_no_event();
object simple_lispcall();
object simple_lispcall_no_event();
object simple_symlispcall();
object simple_symlispcall_no_event();
T_INT super_funcall();
T_INT super_funcall_no_event();
T_INT eval();
object Vevalhook;
object Vapplyhook;
object ieval();
object ifuncall1();
object ifuncall2();
object ifuncall3();
T_INT init_eval();

/*  unixfasl.c  fasload.c  */
T_INT fasload();

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
object Kerror;
object Knew_version;
object Krename;
object Krename_and_delete;
object Koverwrite;
object Kappend;
object Ksupersede;
object Kif_does_not_exist;
object Kerror;
object Kcreate;
object Kprint;
object Kverbose;
object Kif_does_not_exist;
object Kset_default_pathname;
object Vload_verbose;
object FASL_string;
T_INT end_of_stream();
bool input_stream_p();
bool output_stream_p();
object stream_element_type();
object open_stream();
T_INT close_stream();
object make_two_way_stream();
object make_echo_stream();
object make_string_input_stream();
object make_string_output_stream();
object get_output_stream_string();
int readc_stream();
T_INT unreadc_stream();
T_INT writec_stream();
T_INT writestr_stream();
T_INT unwritec_stream();
T_INT flush_stream();
bool stream_at_end();
bool listen_stream();
int file_position();
int file_position_set();
int file_length();
int file_column();
T_INT load();
T_INT init_file();
T_INT init_file_function();
object read_fasl_data();

#ifdef UNIX
/*  unixfsys.c  */
T_INT coerce_to_filename();
FILE *backup_fopen();
int file_exists();
int file_len();
#else
/*  filesystem.c  */
FILE *backup_fopen();
int file_exists();
int file_len();
#endif

/*  frame.c  */
T_INT unwind();
frame_ptr frs_sch();
frame_ptr frs_sch_catch();

/*  gbc.c  */
bool GBC_enable;
T_INT GBC();
T_INT init_GBC();

/*  let.c  */
T_INT let_var_list();
T_INT init_let();

/*  lex.c  */
object assoc_eq();
T_INT lex_fun_bind();
T_INT lex_macro_bind();
T_INT lex_tag_bind();
T_INT lex_block_bind();
object lex_tag_sch();
object lex_block_sch();

/*  list.d  */
object Ktest;
object Ktest_not;
object Kkey;
bool endp1();
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
T_INT stack_cons();
object list();
object listA();
object append();
object copy_list();
bool member_eq();
T_INT delete_eq();
object nconc();
T_INT init_list_function();

/*  macros.c  */
object Vmacroexpand_hook;
object siSdefmacroA;
object macro_expand();
T_INT init_macros();

/*  main.c  */
int ARGC;
char **ARGV;
#ifdef UNIX
char **ENVP;
#endif
char lisp_implementation_version[];
char system_directory[];
object siVsystem_directory;
#ifdef UNIX
char *kcl_self;
#endif
bool initflag;
char *merge_system_directory();

/*  mapfun.c  */
T_INT init_mapfun();

/*  multival.c  */
T_INT init_multival();

/*  number.c  */
int fixint();
int fixnnint();
object shortfloat_zero;
object longfloat_zero;
object make_fixnum();
object make_ratio();
object make_shortfloat();
object make_longfloat();
object make_complex();
T_INT init_number();
T_INT init_number_function();
double number_to_double();
int b_clr_op();
int b_set_op();
int b_1_op();
int b_2_op();
int b_c1_op();
int b_c2_op();
int and_op();
int ior_op();
int xor_op();
int eqv_op();
int nand_op();
int nor_op();
int andc1_op();
int andc2_op();
int orc1_op();
int orc2_op();

/*  num_pred.c  */
int complex_zerop();
int number_zerop();
int number_plusp();
int number_mimusp();

/*  num_comp.c  */
int number_compare();

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
int double_shift();
object shift_integer();

/*  package.d  */
bool member_string_equal();
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
int pack_hash();
object intern();
object find_symbol();
bool unintern();
T_INT export();
T_INT unexport();
T_INT import();
T_INT shadowing_import();
T_INT shadow();
T_INT use_package();
T_INT unuse_package();
T_INT init_package();
T_INT init_package_function();

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
bool eql();
bool equal();
bool equalp();
T_INT init_predicate_function();

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
T_INT edit_double();
T_INT write_object();
T_INT setupPRINTdefault();
T_INT cleanupPRINT();
T_INT write_object_by_default();
T_INT terpri_by_default();
bool potential_number_p();
object princ();
object prin1();
object print();
object terpri();
T_INT init_print_function();
object siSpretty_print_format;

/*  read.d  */
object standard_readtable;
object Vreadtable;
object Vread_default_float_format;
object Vread_base;
object Vread_suppress;
object Kstart;
object Kend;
object Kradix;
object Kjunk_allowed;
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
T_INT setup_READtable();
T_INT setup_READ();
T_INT setup_standard_READ();
object read_char();
T_INT unread_char();
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
T_INT init_read();
T_INT init_read_function();
object read_fasl_vector();

/*  reference.c  */
object symbol_function();
T_INT init_reference();
object Sfunction;

/*  sequence.d  */
object alloc_simple_vector();
object alloc_simple_bitvector();
object elt();
object elt_set();
int length();
object reverse();
object nreverse();
T_INT init_sequence_function();

/*  structure.c  */
object siLs_data;
object structure_ref();
object structure_set();
object structure_to_list();
T_INT init_structure_function();

/*  string.d  */
object alloc_simple_string();
object make_simple_string();
bool string_eq();
bool string_equal();
object copy_simple_string();
object coerce_to_string();
bool member_char();
T_INT init_string_function();

/*  symbol.d  */
object string_register;
object gensym_prefix;
int gensym_counter;
object gentemp_prefix;
int gentemp_counter;
object token;
T_INT set_up_string_register();
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
bool remf();
object remprop();
bool keywordp();
T_INT init_symbol();
T_INT init_symbol_function();
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
T_INT toplevel_eval();
T_INT init_toplevel();

/*  typespec.c  */
object
St,		Snil,		Scommon,
Snull,		Scons,		Slist,		Ssymbol,
Sarray,		Svector,	Sbit_vector,	Sstring,
Ssequence,
Ssimple_array,	Ssimple_vector,	Ssimple_bit_vector,
						Ssimple_string,
Sfunction,	Scompiled_function,
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
T_INT init_typespec();
T_INT   int_typespec_function();

int interrupt_flag;		/* console interupt flag */
int interrupt_enable;		/* console interupt enable */

/*  CMPtemp  */
object CMPtemp;
object CMPtemp1;
object CMPtemp2;
object CMPtemp3;

/* funlink.c */
void call_or_link();
