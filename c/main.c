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
	main.c
	IMPLEMENTATION-DEPENDENT
*/

#define IN_MAIN

#ifdef KCLOVM
#include <ovm/ovm.h>
void change_contexts();
int ovm_process_created; 
void initialize_process();
#endif

#include "include.h"
#ifdef UNIX
#include <signal.h>

int segmentation_catcher();
#endif
#include "page.h"

bool saving_system = FALSE;

#ifdef BSD
#include <sys/time.h>
#ifndef SGI
#include <sys/resource.h>
#endif
#endif

#ifdef AOSVS

#endif

#define	MAXPATHLEN	1024

char lisp_implementation_version[] = "April 1994";

char system_directory[MAXPATHLEN];

int page_multiple=1;

char stdin_buf[BUFSIZ];
char stdout_buf[BUFSIZ];

int debug;			/* debug switch */
int initflag = FALSE;		/* initialized flag */

int real_maxpage;
object siVlisp_maxpages;

object siClisp_pagesize;

object siStop_level;


static object defmacro_data;
static object evalmacros_data;
static object top_data;
static object module_data;
static object siLmultiply_stacks;
int stack_multiple=1;
static object stack_space;

char *merge_system_directory();

int cssize;

int sgc_enabled;
void install_segmentation_catcher();

#define SIG_STACK_SIZE 1000
#ifndef SETUP_SIG_STACK
#if defined(HAVE_SIGACTION) || defined(HAVE_SIGVEC)
        struct sigstack estack;
#endif
#endif
 
main(argc, argv, envp) 
int argc;
char **argv, **envp;
{
	FILE *i;
#ifdef BSD
#ifndef SGI
	struct rlimit rl;
#endif
#endif
#if defined(HAVE_SIGACTION) || defined(HAVE_SIGVEC)

#ifdef SETJMP_ONE_DIRECTION
	static
#endif
	  /* make sure the stack is 8 byte aligned */
	double estack_buf[SIG_STACK_SIZE];
#endif
	setbuf(stdin, stdin_buf);
	setbuf(stdout, stdout_buf);

	ARGC = argc;
	ARGV = argv;
#ifdef UNIX
	ENVP = envp;
#endif

#ifdef UNIX
/*
	if (argv[0][0] != '/')
		error("can't get the program name");
*/
	kcl_self = argv[0];
	if (!initflag) {
		strcpy(system_directory, argv[0]);
		if (system_directory[0] != '/')
			strcpy(system_directory, "./");
		else {
			int j;

			for (j = strlen(system_directory);
                             system_directory[j-1] != '/';  --j)
				;
			system_directory[j] = '\0';
		}
	}
#endif
#ifdef AOSVS












#endif

	if (!initflag && argc > 1) {
#ifdef UNIX
		if (argv[1][strlen(argv[1])-1] != '/')
#endif
#ifdef AOSVS

#endif
			error("can't get the system directory");
		strcpy(system_directory, argv[1]);
	}

	GBC_enable = FALSE;

	/* if stack_space not zero we have grown the stack space */
	if (stack_space == 0)
	  {
	    vs_org = value_stack;
	    vs_limit = &vs_org[VSSIZE];
	    frs_org = frame_stack;
	    frs_limit = &frs_org[FRSSIZE];
	    bds_org = bind_stack;
	    bds_limit = &bds_org[BDSSIZE];
#ifdef KCLOVM
	    bds_save_org = save_bind_stack;
	    bds_save_top = bds_save_org - 1;
	    bds_save_limit = &bds_save_org[BDSSIZE];
#endif
	    ihs_org = ihs_stack;
	    ihs_limit = &ihs_org[IHSSIZE];}

	vs_top = vs_base = vs_org;
	clear_stack(vs_top,vs_limit);
	ihs_top = ihs_org-1;
	bds_top = bds_org-1;
	frs_top = frs_org-1;
	cs_org = &argc;

	cssize = CSSIZE;
	install_segmentation_catcher();

#ifdef BSD
#ifdef RLIMIT_STACK
	getrlimit(RLIMIT_STACK, &rl);
	cssize = rl.rlim_cur/4 - 4*CSGETA;
#endif	
#endif

#ifdef AV
	cs_limit = cs_org - cssize;
#endif
#ifdef MV

#endif
        
	set_maxpage();
#ifdef SETUP_SIG_STACK
	SETUP_SIG_STACK
#else
#if defined(HAVE_SIGACTION) || defined(HAVE_SIGVEC)
	bzero(estack_buf,sizeof(estack_buf));
	estack.ss_sp = (char *) &estack_buf[SIG_STACK_SIZE-1];
	estack.ss_onstack=0;
	sigstack(&estack,0);
#endif	
#endif	
	

	if (initflag) {
		if (saving_system) {
			saving_system = FALSE;
			alloc_page(-(holepage + nrbpage));
		}

		initflag = FALSE;
		GBC_enable = TRUE;
		vs_base = vs_top;
		ihs_push(Cnil);
		lex_new();
		vs_base = vs_top;
#ifdef AOSVS


#endif
		interrupt_enable = TRUE;
#ifdef UNIX
		init_interrupt();
#endif
		siVlisp_maxpages->s.s_dbind = make_fixnum(real_maxpage);
		initflag = TRUE;
#ifdef KCLOVM
		ovm_user_context_change = change_contexts;
		ovm_user_context_initialize = initialize_process;

		v_init_processes();
		ovm_process_created = 1;
#endif
	      again:
		super_funcall(siStop_level);
		if (type_of(siLmultiply_stacks->s.s_dbind)==t_fixnum)
		  {multiply_stacks(fix(siLmultiply_stacks->s.s_dbind));
		   goto  again;}

		exit(0);
	}

	printf("GCL (GNU Common Lisp)  %s  %d pages\n",
	       lisp_implementation_version,
	       MAXPAGE);
	fflush(stdout);

	initlisp();

	vs_base = vs_top;
	ihs_push(Cnil);
	lex_new();

	GBC_enable = TRUE;

	CMPtemp = CMPtemp1 = CMPtemp2 = CMPtemp3 = OBJNULL;

	init_init();

	Vpackage->s.s_dbind = user_package;

	lex_new();
	vs_base = vs_top;
	initflag = TRUE;

	interrupt_enable = TRUE;
#ifdef UNIX
	init_interrupt();
#endif

/*  Primitive read-eval-print loop for debugging.  */
/*
	for (;;) {
		vs_base = vs_top;
		vs_push(code_char('>'));
		Lwrite_char();
		vs_base = vs_top;
		Lfinish_output();
		vs_base = vs_top;
		Lread();
		Leval();
		vs_top = vs_base+1;
		Lprin1();
		vs_base = vs_top;
		Lterpri();
	}
*/

/*  Now, init.lsp is loaded by si:top-level.  */
/*
#ifdef UNIX
	if ((i = fopen("./init.lsp", "r")) != NULL) {
		fclose(i);
		load("./init.lsp");
	}
#endif
#ifdef AOSVS




#endif
*/

	super_funcall(siStop_level);

}


void
gcl_signal(signo,handler)
     int signo;
     void (*handler)();
{
#ifdef HAVE_SIGACTION
  struct sigaction action;
  action.sa_handler = handler;
  action.sa_flags = SA_RESTART | (signo == SIGSEGV || signo == SIGBUS ? SV_ONSTACK : 0)
#ifdef SA_SIGINFO
    | SA_SIGINFO
#endif      
    ;
  sigemptyset(&action.sa_mask);
  sigaddset(&action.sa_mask,signo);
  sigaction(signo,&action,0);
#else
#ifdef HAVE_SIGVEC
  struct sigvec vec;
  vec.sv_handler =  handler;
  vec.sv_flags =  (signo == SIGSEGV || signo == SIGBUS ? SV_ONSTACK : 0);
  vec.sv_mask = sigmask(signo);
  sigvec(signo,&vec,0);
#else
  signal(signo,handler);
#endif
#endif  
}


/* catch certain signals */
void install_segmentation_catcher()
{
#ifdef INSTALL_SEGMENTATION_CATCHER
  INSTALL_SEGMENTATION_CATCHER;
#else
#ifdef SIGSEGV
       (void) gcl_signal(SIGSEGV,segmentation_catcher);
#endif
#endif
       }



initlisp()
{
	int j;

	init_alloc();

	Cnil_body.t = (short)t_symbol;
	Cnil_body.s_dbind = Cnil;
	Cnil_body.s_sfdef = NOT_SPECIAL;
	Cnil_body.s_fillp = 3;
	Cnil_body.s_self = "NIL";
	Cnil_body.s_gfdef = OBJNULL;
	Cnil_body.s_plist = Cnil;
	Cnil_body.s_hpack = Cnil;
	Cnil_body.s_stype = (short)stp_constant;
	Cnil_body.s_mflag = FALSE;
	
	Ct_body.t = (short)t_symbol;
	Ct_body.s_dbind = Ct;
	Ct_body.s_sfdef = NOT_SPECIAL;
	Ct_body.s_fillp = 1;
	Ct_body.s_self = "T";
	Ct_body.s_gfdef = OBJNULL;
	Ct_body.s_plist = Cnil;
	Ct_body.s_hpack = Cnil;
	Ct_body.s_stype = (short)stp_constant;
	Ct_body.s_mflag = FALSE;
	
	init_symbol();

	init_package();

	Cnil->s.s_hpack = lisp_package;
	import(Cnil, lisp_package);
	export(Cnil, lisp_package);

	Ct->s.s_hpack = lisp_package;
	import(Ct, lisp_package);
	export(Ct, lisp_package);

	Squote = make_ordinary("QUOTE");
	enter_mark_origin(&Squote);
	Sfunction = make_ordinary("FUNCTION");
	enter_mark_origin(&Sfunction);
	Slambda = make_ordinary("LAMBDA");
	enter_mark_origin(&Slambda);
	Slambda_block = make_ordinary("LAMBDA-BLOCK");
	enter_mark_origin(&Slambda_block);
	Slambda_closure = make_ordinary("LAMBDA-CLOSURE");
	enter_mark_origin(&Slambda_closure);
	Slambda_block_closure = make_ordinary("LAMBDA-BLOCK-CLOSURE");
	enter_mark_origin(&Slambda_block_closure);
	Sspecial = make_ordinary("SPECIAL");
	enter_mark_origin(&Sspecial);

	init_typespec();
	init_pari();
	init_number();
	init_character();
	init_file();
	init_read();
	init_bind();
	init_pathname();
	init_print();
	init_GBC();

#ifdef UNIX
#ifndef DGUX
	init_unixfasl();
	init_unixsys();
	init_unixsave();
#else



#endif
#endif

	init_alloc_function();
	init_array_function();
	init_character_function();
	init_file_function();
	init_list_function();
	init_package_function();
	init_pathname_function();
	init_predicate_function();
	init_print_function();
	init_read_function();
	init_sequence_function();
#if  defined(KCLOVM) || defined(RUN_PROCESS)
	init_socket_function();
#endif	
	init_structure_function();
	init_string_function();
	init_symbol_function();
	init_typespec_function();
	init_hash();
	init_cfun();

#ifdef UNIX
	init_unixfsys();
	init_unixtime();
#endif
	init_eval();
	init_lex();
	init_prog();
	init_catch();
	init_block();
        init_macros();
	init_conditional();
	init_reference();
	init_assignment();
	init_multival();
	init_error();
	init_let();
	init_mapfun();
	init_iteration();
	init_toplevel();

	init_cmpaux();

	init_main();

	init_format();
	init_links();

	init_fat_string();
#ifdef CMAC
	init_cmac();
#endif	
	init_interrupt1();
}

/*  init_init is now defined in init_system.c  */
/*
init_init()
{
	load(merge_system_directory("export.lsp"));

#ifdef UNIX
	defmacro_data = read_fasl_data(merge_system_directory("defmacro.o"));
	enter_mark_origin(&defmacro_data);
	init_defmacro(NULL, 0, defmacro_data);
	evalmacros_data
	= read_fasl_data(merge_system_directory("evalmacros.o"));
	enter_mark_origin(&evalmacros_data);
	init_evalmacros(NULL, 0, evalmacros_data);
	top_data = read_fasl_data(merge_system_directory("top.o"));
	enter_mark_origin(&top_data);
	init_top(NULL, 0, top_data);
	module_data = read_fasl_data(merge_system_directory("module.o"));
	enter_mark_origin(&module_data);
	init_module(NULL, 0, module_data);
#endif
#ifdef AOSVS














#endif

	load(merge_system_directory("autoload.lsp"));
}
*/

char *
merge_system_directory(s)
{
	static char buff[MAXPATHLEN];
	extern char *strcat();

	strcpy(buff, system_directory);
	return(strcat(buff, s));
}

vs_overflow()
{
	if (vs_limit > vs_org + stack_multiple *  VSSIZE)
		error("value stack overflow");
	vs_limit += VSGETA;
	FEerror("Value stack overflow.", 0);
}


bds_overflow()
{
	--bds_top;
	if (bds_limit > bds_org + stack_multiple *  BDSSIZE)
		error("bind stack overflow");
	bds_limit += BDSGETA;
	FEerror("Bind stack overflow.", 0);
}

frs_overflow()
{
	--frs_top;
	if (frs_limit > frs_org + stack_multiple *  FRSSIZE)
		error("frame stack overflow");
	frs_limit += FRSGETA;
	FEerror("Frame stack overflow.", 0);
}

ihs_overflow()
{
	--ihs_top;
	if (ihs_limit > ihs_org + stack_multiple *  IHSSIZE)
		error("invocation history stack overflow");
	ihs_limit += IHSGETA;
	FEerror("Invocation history stack overflow.", 0);
}

segmentation_catcher()
{int x;
#ifndef SIG_STACK_SIZE 
 if (&x < cs_limit)
	cs_overflow();
 else 
  {printf("Segmentation violation: c stack ok:signalling error");
	}
#endif
  error("Segmentation violation.");
}

cs_overflow()
{
#ifdef AV
	if (cs_limit < cs_org - cssize)
		error("control stack overflow");
	cs_limit -= CSGETA;
#endif
#ifdef MV



#endif
	FEerror("Control stack overflow.", 0);
}

end_of_file()
{
	error("end of file");
}


int catch_fatal=1;
error(s)
{
        if (catch_fatal>0 && interrupt_enable )
	  {catch_fatal = -1;
	   if (sgc_enabled)
	     { sgc_quit();}
	   if (sgc_enabled==0)
	     { install_segmentation_catcher() ;}
	   FEerror("Caught fatal error [memory may be damaged]"); }
	printf("\nUnrecoverable error: %s.\n", s);
	fflush(stdout);
#ifdef UNIX
	abort();
#endif
#ifdef AOSVS

#endif
}

Lby()
{
#ifdef UNIX
	int i;

	if (vs_top - vs_base == 0)
		i = 0;
	else if (vs_top - vs_base == 1) {
		if (type_of(vs_base[0]) == t_fixnum)
			i = fix(vs_base[0]);
		else
			FEerror("Illegal exit code: ~S.", 1, vs_base[0]);
	} else
		too_many_arguments();
	printf("Bye.\n");
	exit(i);
#endif
#ifdef AOSVS






















#endif
}

c_trace()
{
#ifdef AOSVS

#endif
}

siLargc()
{
	check_arg(0);
	vs_push(make_fixnum(ARGC));
}

siLargv()
{
	int i;

	check_arg(1);
	if (type_of(vs_base[0]) != t_fixnum ||
	    (i = fix(vs_base[0])) < 0 ||
	    i >= ARGC)
		FEerror("Illegal argument index: ~S.", 1, vs_base[0]);
	vs_base[0] = make_simple_string(ARGV[i]);
}

#ifdef UNIX
siLgetenv()
{
	char name[256];
	int i;
	char *value;
	extern char *getenv();

	check_arg(1);
	check_type_string(&vs_base[0]);
	if (vs_base[0]->st.st_fillp >= 256)
		FEerror("Too long name: ~S.", 1, vs_base[0]);
	for (i = 0;  i < vs_base[0]->st.st_fillp;  i++)
		name[i] = vs_base[0]->st.st_self[i];
	name[i] = '\0';
	if ((value = getenv(name)) != NULL)
		vs_base[0] = make_simple_string(value);
	else
		vs_base[0] = Cnil;
}
#endif

object *vs_marker;

siLmark_vs()
{
	check_arg(0);
	vs_marker = vs_base;
	vs_base[0] = Cnil;
}

siLcheck_vs()
{
	check_arg(0);
	if (vs_base != vs_marker)
		FEerror("Value stack is flawed.", 0);
	vs_base[0] = Cnil;
}

object
siLcatch_fatal(i)
{catch_fatal=i;
 return Cnil;}


siLreset_stack_limits(arg)
{
	check_arg(0);
	if(catch_fatal <0) catch_fatal=1;
#ifdef SGC	
	{extern int fault_count ; fault_count = 0;}
#endif 
	if (vs_top < vs_org + stack_multiple *  VSSIZE)
		vs_limit = vs_org + stack_multiple *  VSSIZE;
	else
		error("can't reset vs_limit");
	if (bds_top < bds_org + stack_multiple *  BDSSIZE)
		bds_limit = bds_org + stack_multiple *  BDSSIZE;
	else
		error("can't reset bds_limit");
	if (frs_top < frs_org + stack_multiple *  FRSSIZE)
		frs_limit = frs_org + stack_multiple *  FRSSIZE;
	else
		error("can't reset frs_limit");
	if (ihs_top < ihs_org + stack_multiple *  IHSSIZE)
		ihs_limit = ihs_org + stack_multiple *  IHSSIZE;
	else
		error("can't reset ihs_limit");
#ifdef AV
	if (&arg > cs_org - cssize + 16)
		cs_limit = cs_org - cssize;
#endif
	else
		error("can't reset cs_limit");
	vs_base[0] = Cnil;
}

#define COPYSTACK(org,p,typ,lim,top,geta,size) \
 do{int leng,topl;      \
  bcopy(org,p,leng=(stack_multiple*size*sizeof(typ))); \
  topl= top - org; \
  org=(typ *)p; top = org +topl;\
  p=p+leng+2*geta*sizeof(typ); \
  lim = ((typ *)p) - 2*geta;   \
  }while (0)

multiply_stacks(m)
     int m;
{  int n;
   object x;
   object gc_pro=stack_space;
   char *p;
   int vs,bd,frs,ihs;
   stack_multiple=stack_multiple*m;
#define ELTSIZE(x) (((char *)((x)+1)) - ((char *) x))
   vs  = (stack_multiple*VSSIZE  + 2*VSGETA)* ELTSIZE(vs_org);
   bd  = (stack_multiple*BDSSIZE + 2*BDSGETA)*ELTSIZE(bds_org);
   frs = (stack_multiple*FRSSIZE + 2*FRSGETA)*ELTSIZE(frs_org);
   ihs = (stack_multiple*IHSSIZE + 2*IHSGETA)*ELTSIZE(ihs_org);
   if (stack_space==0) {enter_mark_origin(&stack_space);}
   stack_space = alloc_simple_string(vs+bd+frs+ihs);
   array_allocself(stack_space,1,code_char(0));
   p=stack_space->st.st_self;
   COPYSTACK(vs_org,p,object,vs_limit,vs_top,VSGETA,VSSIZE);
   COPYSTACK(bds_org,p,struct bds_bd,bds_limit,bds_top,BDSGETA,BDSSIZE);
   COPYSTACK(frs_org,p,struct frame,frs_limit,frs_top,FRSGETA,FRSSIZE);
   COPYSTACK(ihs_org,p,struct invocation_history,ihs_limit,ihs_top,
	     IHSGETA,IHSSIZE);
   vs_base=vs_top;
   return stack_multiple;
 }






 
  

siLinit_system()
{
	check_arg(0);
	init_system();
	vs_base[0] = Cnil;
}

siLaddress()
{
	check_arg(1);
	vs_base[0] = make_fixnum((int)vs_base[0]);
}

siLnani()
{
	check_arg(1);
	vs_base[0] = (object)fixint(vs_base[0]);
}

siLinitialization_failure()
{
	check_arg(0);
	printf("lisp initialization failed\n");
	exit(0);
}

Lidentity()
{
	check_arg(1);
}

Llisp_implementation_version()
{
	check_arg(0);
	vs_push(make_simple_string(lisp_implementation_version));
	vs_base[0] = Cnil;
}


siLsave_system()
{
	int i;

#ifdef HAVE_YP_UNBIND
	extern object truename(),namestring();
	check_arg(1);
	/* prevent subsequent consultation of yp by getting
	   truename now*/
	vs_base[0]=namestring(truename(vs_base[0]));
	{char name[200];
	 char *dom = name;
	 if (0== getdomainname(dom,sizeof(name)))
	   yp_unbind(dom);}
#endif
	
	saving_system = TRUE;
	GBC(t_contiguous);



#if defined(BSD) || defined(ATT)  
	brk(core_end);
  /* printf( "(breaking at core_end = %x in main ,)",core_end); */
#endif

#ifdef DGUX

#endif

#ifdef AOSVS




#endif
	cbgbccount = 0;
	rbgbccount = 0;
	for (i = 0;  i < (int)t_end;  i++)
		tm_table[i].tm_gbccount = 0;
	Lsave();
	saving_system = FALSE;
	alloc_page(-(holepage+nrbpage));
}

init_main()
{
	make_function("BY", Lby);
	make_function("BYE", Lby);

	make_function("IDENTITY", Lidentity);

	siStop_level=make_si_ordinary("TOP-LEVEL");
	enter_mark_origin(&siStop_level);

	make_si_function("ARGC", siLargc);
	make_si_function("ARGV", siLargv);

#ifdef UNIX
	make_si_function("GETENV", siLgetenv);
#endif

	make_si_function("MARK-VS", siLmark_vs);
	make_si_function("CHECK-VS", siLcheck_vs);

	make_si_function("RESET-STACK-LIMITS", siLreset_stack_limits);

	make_si_function("INIT-SYSTEM", siLinit_system);

	make_si_function("ADDRESS", siLaddress);
	make_si_function("NANI", siLnani);

	make_si_function("INITIALIZATION-FAILURE",
			 siLinitialization_failure);

	make_function("LISP-IMPLEMENTATION-VERSION",
		      Llisp_implementation_version);

	siVlisp_maxpages =
	make_si_special("*LISP-MAXPAGES*", make_fixnum(real_maxpage));

	siClisp_pagesize =
	make_si_constant("LISP-PAGESIZE", make_fixnum(PAGESIZE));

	siVsystem_directory =
	make_si_special("*SYSTEM-DIRECTORY*",
			make_simple_string(system_directory));
	{object features;

#define ADD_FEATURE(name) \
	 features=  make_cons(make_ordinary(name),features)

	   features=    make_cons(make_ordinary("COMMON"),
		     make_cons(make_ordinary("KCL"), Cnil));
	 ADD_FEATURE("AKCL");
	 ADD_FEATURE("GCL");	 

#ifdef UNIX
	ADD_FEATURE("UNIX");
#endif
#ifdef IEEEFLOAT
       ADD_FEATURE("IEEE-FLOATING-POINT");
#endif
#ifdef SGC
       ADD_FEATURE("SGC");
#endif	 
#ifdef  ADDITIONAL_FEATURES
     	             ADDITIONAL_FEATURES;
#endif
#ifdef  BSD
	ADD_FEATURE("BSD");
#endif


#ifndef PECULIAR_MACHINE
#define BIGM    (int)((((unsigned int)(-1))/2))	 
	{ 
	  int ONEM = -1;
	  int Bigm  = BIGM;
	  int Smallm = -BIGM-1;
	  int Seven = 7;
	  int Three = 3;
	  if ( (Smallm / Seven)  < 0
	      && (Smallm / (-Seven))  > 0
	      && (Bigm / (-Seven)) < 0 
	      && ((-Seven) / Three) == -2
	      && (Seven / (-Three)) == -2
	      && ((-Seven)/ (-Three)) == 2)
	    { ADD_FEATURE("TRUNCATE_USE_C");
	    }  }
#endif	 


	 
	make_special("*FEATURES*",features);}

	make_si_function("SAVE-SYSTEM", siLsave_system);
	make_si_sfun("CATCH-FATAL",siLcatch_fatal,ARGTYPE1(f_fixnum));
	siLmultiply_stacks=make_si_special("*MULTIPLY-STACKS*",Cnil);
	
}
