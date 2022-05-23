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
	file.d
	IMPLEMENTATION-DEPENDENT

	The specification of printf may be dependent on the C library,
	especially for read-write access, append access, etc.
	The file also contains the code to reclaim the I/O buffer
	by accessing the FILE structure of C.
	It also contains read_fasl_data.
*/

#define IN_FILE
#include "include.h"

#define	kclgetc(FP)		getc(FP)
#define	kclungetc(C, FP)	ungetc(C, FP)
#define	kclfeof(FP)		feof(FP)
#define	kclputc(C, FP)		putc(C, FP)

#ifdef HAVE_AOUT
#undef ATT
#undef BSD
#ifndef HAVE_ELF
#define BSD
#endif
#include HAVE_AOUT
#endif

#ifdef ATT
#include <filehdr.h>
#include <syms.h>
#endif

#ifdef E15
#include <a.out.h>
#define exec	bhdr
#define a_text	tsize
#define a_data	dsize
#define a_bss	bsize
#define a_syms	ssize
#define a_trsize	rtsize
#define a_drsize	rdsize
#endif

#ifdef HAVE_ELF
#include <elf.h>
#endif

static object terminal_io;

object Vverbose;
object LSP_string;


object siVignore_eof_on_terminal_io;

bool
feof1(fp)
FILE *fp;
{
	if (!feof(fp))
		return(FALSE);
	if (fp == terminal_io->sm.sm_object0->sm.sm_fp) {
		if (symbol_value(siVignore_eof_on_terminal_io) == Cnil)
			return(TRUE);
#ifdef UNIX
		fp = freopen("/dev/tty", "r", fp);
#endif
#ifdef AOSVS

#endif
		if (fp == NULL)
			error("can't reopen the console");
		return(FALSE);
	}
	return(TRUE);
}

#undef	feof
#define	feof	feof1


end_of_stream(strm)
object strm;
{
	FEerror("Unexpected end of ~S.", 1, strm);
}

/*
	Input_stream_p(strm) answers
	if stream strm is an input stream or not.
	It does not check if it really is possible to read
	from the stream,
	but only checks the mode of the stream (sm_mode).
*/
bool
input_stream_p(strm)
object strm;
{
BEGIN:
	switch (strm->sm.sm_mode) {
	case smm_input:
		return(TRUE);

	case smm_output:
		return(FALSE);

	case smm_io:
		return(TRUE);

	case smm_probe:
		return(FALSE);

	case smm_synonym:
		strm = symbol_value(strm->sm.sm_object0);
		if (type_of(strm) != t_stream)
			FEwrong_type_argument(Sstream, strm);
		goto BEGIN;

	case smm_broadcast:
		return(FALSE);

	case smm_concatenated:
		return(TRUE);

	case smm_two_way:
		return(TRUE);

	case smm_echo:
		return(TRUE);

	case smm_string_input:
		return(TRUE);

	case smm_string_output:
		return(FALSE);

	default:
		error("illegal stream mode");
	}
}

/*
	Output_stream_p(strm) answers
	if stream strm is an output stream.
	It does not check if it really is possible to write
	to the stream,
	but only checks the mode of the stream (sm_mode).
*/
bool
output_stream_p(strm)
object strm;
{
BEGIN:
	switch (strm->sm.sm_mode) {
	case smm_input:
		return(FALSE);

	case smm_output:
		return(TRUE);

	case smm_io:
		return(TRUE);

	case smm_probe:
		return(FALSE);

	case smm_synonym:
		strm = symbol_value(strm->sm.sm_object0);
		if (type_of(strm) != t_stream)
			FEwrong_type_argument(Sstream, strm);
		goto BEGIN;

	case smm_broadcast:
		return(TRUE);

	case smm_concatenated:
		return(FALSE);

	case smm_two_way:
		return(TRUE);

	case smm_echo:
		return(TRUE);

	case smm_string_input:
		return(FALSE);

	case smm_string_output:
		return(TRUE);

	default:
		error("illegal stream mode");
	}
}

object
stream_element_type(strm)
object strm;
{
	object x;

BEGIN:
	switch (strm->sm.sm_mode) {
	case smm_input:
	case smm_output:
	case smm_io:
	case smm_probe:
		return(strm->sm.sm_object0);

	case smm_synonym:
		strm = symbol_value(strm->sm.sm_object0);
		if (type_of(strm) != t_stream)
			FEwrong_type_argument(Sstream, strm);
		goto BEGIN;

	case smm_broadcast:
		x = strm->sm.sm_object0;
		if (endp(x))
			return(Ct);
		return(stream_element_type(x->c.c_car));

	case smm_concatenated:
		x = strm->sm.sm_object0;
		if (endp(x))
			return(Ct);
		return(stream_element_type(x->c.c_car));

	case smm_two_way:
		return(stream_element_type(strm->sm.sm_object0));

	case smm_echo:
		return(stream_element_type(strm->sm.sm_object0));

	case smm_string_input:
		return(Sstring_char);

	case smm_string_output:
		return(Sstring_char);

	default:
		error("illegal stream mode");
	}
}

/*
	Open_stream(fn, smm, if_exists, if_does_not_exist)
	opens file fn with mode smm.
	Fn is a namestring.
*/
object
open_stream(fn, smm, if_exists, if_does_not_exist)
object fn;
enum smmode smm;
object if_exists, if_does_not_exist;
{
	object x;
	FILE *fp;
	char fname[BUFSIZ];
	int i;
	vs_mark;

/*
	if (type_of(fn) != t_string)
		FEwrong_type_argument(Sstring, fn);
*/
	if (fn->st.st_fillp > BUFSIZ - 1)
		too_long_file_name(fn);
	for (i = 0;  i < fn->st.st_fillp;  i++)
		fname[i] = fn->st.st_self[i];
	fname[i] = '\0';
	if (smm == smm_input || smm == smm_probe) {
		fp = fopen(fname, "r");
		if (fp == NULL) {
			if (if_does_not_exist == Kerror)
				cannot_open(fn);
			else if (if_does_not_exist == Kcreate) {
				fp = fopen(fname, "w");
				if (fp == NULL)
					cannot_create(fn);
				fclose(fp);
				fp = fopen(fname, "r");
				if (fp == NULL)
					cannot_open(fn);
			} else if (if_does_not_exist == Cnil)
				return(Cnil);
			else
			 FEerror("~S is an illegal IF-DOES-NOT-EXIST option.",
				 1, if_does_not_exist);
		}
	} else if (smm == smm_output || smm == smm_io) {
		if (if_exists == Knew_version && if_does_not_exist == Kcreate)
			goto CREATE;
		fp = fopen(fname, "r");
		if (fp != NULL) {
			fclose(fp);
			if (if_exists == Kerror)
				FEerror("The file ~A already exists.", 1, fn);
			else if (if_exists == Krename) {
				if (smm == smm_output)
					fp = backup_fopen(fname, "w");
				else
					fp = backup_fopen(fname, "w+");
				if (fp == NULL)
					cannot_create(fn);
			} else if (if_exists == Krename_and_delete ||
				   if_exists == Knew_version ||
				   if_exists == Ksupersede) {
				if (smm == smm_output)
					fp = fopen(fname, "w");
				else
					fp = fopen(fname, "w+");
				if (fp == NULL)
					cannot_create(fn);
			} else if (if_exists == Koverwrite) {
				fp = fopen(fname, "r+");
				if (fp == NULL)
					cannot_open(fn);
			} else if (if_exists == Kappend) {
				if (smm == smm_output)
					fp = fopen(fname, "a");
				else
					fp = fopen(fname, "a+");
				if (fp == NULL)
				FEerror("Cannot append to the file ~A.",1,fn);
			} else if (if_exists == Cnil)
				return(Cnil);
			else
				FEerror("~S is an illegal IF-EXISTS option.",
					1, if_exists);
		} else {
			if (if_does_not_exist == Kerror)
				FEerror("The file ~A does not exist.", 1, fn);
			else if (if_does_not_exist == Kcreate) {
			CREATE:
				if (smm == smm_output)
					fp = fopen(fname, "w");
				else
					fp = fopen(fname, "w+");
				if (fp == NULL)
					cannot_create(fn);
			} else if (if_does_not_exist == Cnil)
				return(Cnil);
			else
			 FEerror("~S is an illegal IF-DOES-NOT-EXIST option.",
				 1, if_does_not_exist);
		}
	} else
		error("illegal stream mode");
	x = alloc_object(t_stream);
	x->sm.sm_mode = (short)smm;
	x->sm.sm_fp = fp;

	x->sm.sm_buffer = 0;
	x->sm.sm_object0 = Sstring_char;
	x->sm.sm_object1 = fn;
	x->sm.sm_int0 = x->sm.sm_int1 = 0;
	vs_push(x);
	{char *buf=alloc_contblock(BUFSIZ);
  	x->sm.sm_buffer = buf;
#ifdef SGC
	perm_writable(buf,BUFSIZ);
#endif
	setbuf(fp, buf);
	}	
	vs_reset;
	return(x);
}

/*
	Close_stream(strm, abort_flag) closes stream strm.
	The abort_flag is not used now.
*/
close_stream(strm, abort_flag)
object strm;
bool abort_flag;	/*  Not used now!  */
{
	object x;

BEGIN:
	switch (strm->sm.sm_mode) {
	case smm_output:
		if (strm->sm.sm_fp == stdout)
			FEerror("Cannot close the standard output.", 0);
		if (strm->sm.sm_fp == NULL) break;
		fflush(strm->sm.sm_fp);
		if (strm->sm.sm_buffer)
  		  {insert_contblock(strm->sm.sm_buffer, BUFSIZ);
     		   strm->sm.sm_buffer = 0;}
                  else
                   printf("no buffer? %x  \n",strm->sm.sm_fp);
#ifndef FCLOSE_SETBUF_OK
		strm->sm.sm_fp->_base = NULL;
#endif

		fclose(strm->sm.sm_fp);
		strm->sm.sm_fp = NULL;
		break;

	case smm_input:
		if (strm->sm.sm_fp == stdin)
			FEerror("Cannot close the standard input.", 0);

	case smm_io:
	case smm_probe:
		if (strm->sm.sm_fp == NULL) break;
		if (strm->sm.sm_buffer)
  		  {insert_contblock(strm->sm.sm_buffer, BUFSIZ);
     		   strm->sm.sm_buffer = 0;}
                  else
                   printf("no buffer? %x  \n",strm->sm.sm_fp);

#ifndef FCLOSE_SETBUF_OK
		strm->sm.sm_fp->_base = NULL;
#endif
		fclose(strm->sm.sm_fp);
		strm->sm.sm_fp = NULL;
		break;

	case smm_synonym:
		strm = symbol_value(strm->sm.sm_object0);
		if (type_of(strm) != t_stream)
			FEwrong_type_argument(Sstream, strm);
		goto BEGIN;

	case smm_broadcast:
		for (x = strm->sm.sm_object0; !endp(x); x = x->c.c_cdr)
			close_stream(x->c.c_car, abort_flag);
		break;

	case smm_concatenated:
		for (x = strm->sm.sm_object0; !endp(x); x = x->c.c_cdr)
			close_stream(x->c.c_car, abort_flag);
		break;

	case smm_two_way:
		close_stream(strm->sm.sm_object0);
		close_stream(strm->sm.sm_object1);
		break;

	case smm_echo:
		close_stream(strm->sm.sm_object0);
		close_stream(strm->sm.sm_object1);
		break;

	case smm_string_input:
		break;		/*  There is nothing to do.  */

	case smm_string_output:
		break;		/*  There is nothing to do.  */

	default:
		error("illegal stream mode");
	}
}

object
make_two_way_stream(istrm, ostrm)
object istrm, ostrm;
{
	object strm;

	strm = alloc_object(t_stream);
	strm->sm.sm_mode = (short)smm_two_way;
	strm->sm.sm_fp = NULL;
	strm->sm.sm_object0 = istrm;
	strm->sm.sm_object1 = ostrm;
	strm->sm.sm_int0 = strm->sm.sm_int1 = 0;
	return(strm);
}

object
make_echo_stream(istrm, ostrm)
object istrm, ostrm;
{
	object strm;

	strm = make_two_way_stream(istrm, ostrm);
	strm->sm.sm_mode = (short)smm_echo;
	return(strm);
}

object
make_string_input_stream(strng, istart, iend)
object strng;
int istart, iend;
{
	object strm;

	strm = alloc_object(t_stream);
	strm->sm.sm_mode = (short)smm_string_input;
	strm->sm.sm_fp = NULL;
	strm->sm.sm_object0 = strng;
	strm->sm.sm_object1 = OBJNULL;
	strm->sm.sm_int0 = istart;
	strm->sm.sm_int1 = iend;
	return(strm);
}

object
make_string_output_stream(line_length)
int line_length;
{
	object strng, strm;
	vs_mark;

	strng = alloc_object(t_string);
	strng->st.st_hasfillp = TRUE;
	strng->st.st_adjustable = TRUE;
	strng->st.st_displaced = Cnil;
	strng->st.st_dim = line_length;
	strng->st.st_fillp = 0;
	strng->st.st_self = NULL;
		/*  For GBC not to go mad.  */
	vs_push(strng);
		/*  Saving for GBC.  */
	strng->st.st_self = alloc_relblock(line_length);
	strm = alloc_object(t_stream);
	strm->sm.sm_mode = (short)smm_string_output;
	strm->sm.sm_fp = NULL;
	strm->sm.sm_object0 = strng;
	strm->sm.sm_object1 = OBJNULL;
	strm->sm.sm_int0 = strm->sm.sm_int1 = 0;
	vs_reset;
	return(strm);
}

object
get_output_stream_string(strm)
object strm;
{
	object strng;

	strng = copy_simple_string(strm->sm.sm_object0);
	strm->sm.sm_object0->st.st_fillp = 0;
	return(strng);
}

int
readc_stream(strm)
object strm;
{
	int c;

BEGIN:
	switch (strm->sm.sm_mode) {
	case smm_input:
	case smm_io:
		if (strm->sm.sm_fp == NULL)
			closed_stream(strm);
		c = kclgetc(strm->sm.sm_fp);
		c &= 0377;
		if (kclfeof(strm->sm.sm_fp))
			end_of_stream(strm);
		strm->sm.sm_int0++;
		return(c);

	case smm_synonym:
		strm = symbol_value(strm->sm.sm_object0);
		if (type_of(strm) != t_stream)
			FEwrong_type_argument(Sstream, strm);
		goto BEGIN;

	case smm_concatenated:
	CONCATENATED:
		if (endp(strm->sm.sm_object0)) {
			end_of_stream(strm);
		}
		if (stream_at_end(strm->sm.sm_object0->c.c_car)) {
			strm->sm.sm_object0
			= strm->sm.sm_object0->c.c_cdr;
			goto CONCATENATED;
		}
		c = readc_stream(strm->sm.sm_object0->c.c_car);
		return(c);

	case smm_two_way:
#ifdef UNIX
		if (strm == terminal_io)				/**/
			flush_stream(terminal_io->sm.sm_object1);	/**/
#endif
		strm->sm.sm_int1 = 0;
		strm = strm->sm.sm_object0;
		goto BEGIN;

	case smm_echo:
		c = readc_stream(strm->sm.sm_object0);
		if (strm->sm.sm_int0 == 0)
			writec_stream(c, strm->sm.sm_object1);
		else
			--(strm->sm.sm_int0);
		return(c);

	case smm_string_input:
		if (strm->sm.sm_int0 >= strm->sm.sm_int1)
			end_of_stream(strm);
		return(strm->sm.sm_object0->st.st_self
		       [strm->sm.sm_int0++]);

	case smm_output:
	case smm_probe:
	case smm_broadcast:
	case smm_string_output:
		cannot_read(strm);
#ifdef USER_DEFINED_STREAMS
	case smm_user_defined:
#define STM_DATA_STRUCT 0
#define STM_READ_CHAR 1
#define STM_WRITE_CHAR 2
#define STM_UNREAD_CHAR 7
#define STM_FORCE_OUTPUT 4
#define STM_PEEK_CHAR 3
#define STM_CLOSE 5
#define STM_TYPE 6
#define STM_NAME 8
{object val;
		object *old_vs_base = vs_base;
		object *old_vs_top = vs_top;
		vs_base = vs_top;
		vs_push(strm);
		super_funcall(strm->sm.sm_object1->str.str_self[STM_READ_CHAR]);
		val = vs_base[0];
		vs_base = old_vs_base;
		vs_top = old_vs_top;
		if (type_of(val) == t_fixnum)
		  return (fix(val));
		if (type_of(val) == t_character)
		  return (char_code(val));
	      }

#endif

	default:	
		error("illegal stream mode");
	}
}

unreadc_stream(c, strm)
int c;
object strm;
{
BEGIN:
	switch (strm->sm.sm_mode) {
	case smm_input:
	case smm_io:
		if (strm->sm.sm_fp == NULL)
			closed_stream(strm);
		kclungetc(c, strm->sm.sm_fp);
		--strm->sm.sm_int0;
		break;

	case smm_synonym:
		strm = symbol_value(strm->sm.sm_object0);
		if (type_of(strm) != t_stream)
			FEwrong_type_argument(Sstream, strm);
		goto BEGIN;

	case smm_concatenated:
		if (endp(strm->sm.sm_object0))
			goto UNREAD_ERROR;
		strm = strm->sm.sm_object0->c.c_car;
		goto BEGIN;

	case smm_two_way:
		strm = strm->sm.sm_object0;
		goto BEGIN;

	case smm_echo:
		unreadc_stream(c, strm->sm.sm_object0);
		(strm->sm.sm_int0)++;
		break;

	case smm_string_input:
		if (strm->sm.sm_int0 <= 0)
			goto UNREAD_ERROR;
		--strm->sm.sm_int0;
		break;

	case smm_output:
	case smm_probe:
	case smm_broadcast:
	case smm_string_output:
		goto UNREAD_ERROR;

#ifdef USER_DEFINED_STREAMS
        case smm_user_defined:
		{object *old_vs_base = vs_base;
		 object *old_vs_top = vs_top;
		 vs_base = vs_top;
		 vs_push(strm);
		 /* if there is a file pointer and no define unget function,
                  * then call ungetc */
		 if ((strm->sm.sm_fp != NULL ) &&
		     strm->sm.sm_object1->str.str_self[STM_UNREAD_CHAR] == Cnil)
		   kclungetc(c, strm->sm.sm_fp);
		 else
		   super_funcall(strm->sm.sm_object1->str.str_self[STM_UNREAD_CHAR]);
		 vs_top = old_vs_top;
		 vs_base = old_vs_base;
	       }
		break;
#endif
	default:
		error("illegal stream mode");
	}
	return;

UNREAD_ERROR:
	FEerror("Cannot unread the stream ~S.", 1, strm);
}

writec_stream(c, strm)
int c;
object strm;
{
	object x;
	char *p;
	int i;

BEGIN:
	switch (strm->sm.sm_mode) {
	case smm_output:
	case smm_io:
		strm->sm.sm_int0++;
		if (c == '\n')
			strm->sm.sm_int1 = 0;
		else if (c == '\t')
			strm->sm.sm_int1 = (strm->sm.sm_int1&~07) + 8;
		else
			strm->sm.sm_int1++;
		if (strm->sm.sm_fp == NULL)
			closed_stream(strm);
		kclputc(c, strm->sm.sm_fp);
		break;

	case smm_synonym:
		strm = symbol_value(strm->sm.sm_object0);
		if (type_of(strm) != t_stream)
			FEwrong_type_argument(Sstream, strm);
		goto BEGIN;

	case smm_broadcast:
		for (x = strm->sm.sm_object0; !endp(x); x = x->c.c_cdr)
			writec_stream(c, x->c.c_car);
		break;

	case smm_two_way:
		strm->sm.sm_int0++;
		if (c == '\n')
			strm->sm.sm_int1 = 0;
		else if (c == '\t')
			strm->sm.sm_int1 = (strm->sm.sm_int1&~07) + 8;
		else
			strm->sm.sm_int1++;
		strm = strm->sm.sm_object1;
		goto BEGIN;

	case smm_echo:
		strm = strm->sm.sm_object1;
		goto BEGIN;

	case smm_string_output:
		strm->sm.sm_int0++;
		if (c == '\n')
			strm->sm.sm_int1 = 0;
		else if (c == '\t')
			strm->sm.sm_int1 = (strm->sm.sm_int1&~07) + 8;
		else
			strm->sm.sm_int1++;
		x = strm->sm.sm_object0;
		if (x->st.st_fillp >= x->st.st_dim) {
			if (!x->st.st_adjustable)
				FEerror("The string ~S is not adjustable.",
					1, x);
			p = alloc_relblock(x->st.st_dim * 2 + 16);
			for (i = 0;  i < x->st.st_dim;  i++)
				p[i] = x->st.st_self[i];
			i = x->st.st_dim * 2 + 16;
#define	ADIMLIM		16*1024*1024
			if (i >= ADIMLIM)
				FEerror("Can't extend the string.", 0);
			x->st.st_dim = i;
			adjust_displaced(x, p - x->st.st_self);
		}
		x->st.st_self[x->st.st_fillp++] = c;
		break;

	case smm_input:
	case smm_probe:
	case smm_concatenated:
	case smm_string_input:
		cannot_write(strm);

#ifdef USER_DEFINED_STREAMS
	case smm_user_defined:
		{object *old_vs_base = vs_base;
		 object *old_vs_top = vs_top;
		 vs_base = vs_top;
		 vs_push(strm);
		 vs_push(code_char(c));
		 super_funcall(strm->sm.sm_object1->str.str_self[2]);
		 vs_base = old_vs_base;
		 vs_top = old_vs_top;
		 break;
	       }

#endif
	default:
		error("illegal stream mode");
	}
	return(c);
}

writestr_stream(s, strm)
char *s;
object strm;
{
	while (*s != '\0')
		writec_stream(*s++, strm);
}

flush_stream(strm)
object strm;
{
	object x;

BEGIN:
	switch (strm->sm.sm_mode) {
	case smm_output:
	case smm_io:
		if (strm->sm.sm_fp == NULL)
			closed_stream(strm);
		fflush(strm->sm.sm_fp);
		break;

	case smm_synonym:
		strm = symbol_value(strm->sm.sm_object0);
		if (type_of(strm) != t_stream)
			FEwrong_type_argument(Sstream, strm);
		goto BEGIN;

	case smm_broadcast:
		for (x = strm->sm.sm_object0; !endp(x); x = x->c.c_cdr)
			flush_stream(x->c.c_car);
		break;

	case smm_two_way:
		strm = strm->sm.sm_object1;
		goto BEGIN;

	case smm_echo:
		strm = strm->sm.sm_object1;
		goto BEGIN;

	case smm_string_output:
		break;

	case smm_input:
	case smm_probe:
	case smm_concatenated:
	case smm_string_input:
		FEerror("Cannot flush the stream ~S.", 1, strm);
#ifdef USER_DEFINED_STREAMS
        case smm_user_defined:
		{object *old_vs_base = vs_base;
		 object *old_vs_top = vs_top;
		 vs_base = vs_top;
		 vs_push(strm);
		 super_funcall(strm->sm.sm_object1->str.str_self[4]);
		 vs_base = old_vs_base;
		 vs_top = old_vs_top;
		break;
	       }

#endif

	default:
		error("illegal stream mode");
	}
}

bool
stream_at_end(strm)
object strm;
{
	object x;
	int c;

BEGIN:
	switch (strm->sm.sm_mode) {
	case smm_io:	
	case smm_input:
		if (strm->sm.sm_fp == NULL)
			closed_stream(strm);
		c = kclgetc(strm->sm.sm_fp);
		if (kclfeof(strm->sm.sm_fp))
			return(TRUE);
		else {
			kclungetc(c, strm->sm.sm_fp);
			return(FALSE);
		}

	case smm_output:
		return(FALSE);

/*	case smm_io:
		return(FALSE);
*/

	case smm_probe:
		return(FALSE);

	case smm_synonym:
		strm = symbol_value(strm->sm.sm_object0);
		if (type_of(strm) != t_stream)
			FEwrong_type_argument(Sstream, strm);
		goto BEGIN;

	case smm_broadcast:
		return(FALSE);

	case smm_concatenated:
	CONCATENATED:
		if (endp(strm->sm.sm_object0))
			return(TRUE);
		if (stream_at_end(strm->sm.sm_object0->c.c_car)) {
			strm->sm.sm_object0
			= strm->sm.sm_object0->c.c_cdr;
			goto CONCATENATED;
		} else
			return(FALSE);

	case smm_two_way:
#ifdef UNIX
		if (strm == terminal_io)				/**/
			flush_stream(terminal_io->sm.sm_object1);	/**/
#endif
		strm = strm->sm.sm_object0;
		goto BEGIN;

	case smm_echo:
		strm = strm->sm.sm_object0;
		goto BEGIN;

	case smm_string_input:
		if (strm->sm.sm_int0 >= strm->sm.sm_int1)
			return(TRUE);
		else
			return(FALSE);

	case smm_string_output:
		return(FALSE);

#ifdef USER_DEFINED_STREAMS
        case smm_user_defined:
		  return(FALSE);
#endif
	default:
		error("illegal stream mode");
	}
}

#ifdef HAVE_IOCTL
#include <sys/ioctl.h>
#endif

bool
listen_stream(strm)
object strm;
{
	object x;
	int c;

BEGIN:
	switch (strm->sm.sm_mode) {
	case smm_input:
	case smm_io:

		if (strm->sm.sm_fp == NULL)
			closed_stream(strm);
		if (feof(strm->sm.sm_fp))
				return(FALSE);
#ifdef LISTEN_FOR_INPUT
		LISTEN_FOR_INPUT(strm->sm.sm_fp);
#endif
		return TRUE;

	case smm_synonym:
		strm = symbol_value(strm->sm.sm_object0);
		if (type_of(strm) != t_stream)
			FEwrong_type_argument(Sstream, strm);
		goto BEGIN;

	case smm_concatenated:
	CONCATENATED:
		if (endp(strm->sm.sm_object0))
			return(FALSE);
		strm = strm->sm.sm_object0->c.c_car;	/* Incomplete! */
		goto BEGIN;

	case smm_two_way:
	case smm_echo:
		strm = strm->sm.sm_object0;
		goto BEGIN;

	case smm_string_input:
		if (strm->sm.sm_int0 < strm->sm.sm_int1)
			return(TRUE);
		else
			return(FALSE);

	case smm_output:
	case smm_probe:
	case smm_broadcast:
	case smm_string_output:
		FEerror("Can't listen to ~S.", 1, strm);

	default:
		error("illegal stream mode");
	}
}

int
file_position(strm)
object strm;
{
BEGIN:
	switch (strm->sm.sm_mode) {
	case smm_input:
	case smm_output:
	case smm_io:
		/*  return(strm->sm.sm_int0);  */
		if (strm->sm.sm_fp == NULL)
			closed_stream(strm);
		return(ftell(strm->sm.sm_fp));

	case smm_string_output:
		return(strm->sm.sm_object0->st.st_fillp);

	case smm_synonym:
		strm = symbol_value(strm->sm.sm_object0);
		if (type_of(strm) != t_stream)
			FEwrong_type_argument(Sstream, strm);
		goto BEGIN;

	case smm_probe:
	case smm_broadcast:
	case smm_concatenated:
	case smm_two_way:
	case smm_echo:
	case smm_string_input:
		return(-1);

	default:
		error("illegal stream mode");
	}
}

int
file_position_set(strm, disp)
object strm;
int disp;
{
BEGIN:
	switch (strm->sm.sm_mode) {
	case smm_input:
	case smm_output:
	case smm_io:
		if (strm->sm.sm_fp == NULL)
			closed_stream(strm);
		if (fseek(strm->sm.sm_fp, disp, 0) < 0)
			return(-1);
		strm->sm.sm_int0 = disp;
		return(0);

	case smm_string_output:
		if (disp < strm->sm.sm_object0->st.st_fillp) {
			strm->sm.sm_object0->st.st_fillp = disp;
			strm->sm.sm_int0 = disp;
		} else {
			disp -= strm->sm.sm_object0->st.st_fillp;
			while (disp-- > 0)
				writec_stream(' ', strm);
		}
		return(0);

	case smm_synonym:
		strm = symbol_value(strm->sm.sm_object0);
		if (type_of(strm) != t_stream)
			FEwrong_type_argument(Sstream, strm);
		goto BEGIN;

	case smm_probe:
	case smm_broadcast:
	case smm_concatenated:
	case smm_two_way:
	case smm_echo:
	case smm_string_input:
		return(-1);

	default:
		error("illegal stream mode");
	}
}

int
file_length(strm)
object strm;
{
BEGIN:
	switch (strm->sm.sm_mode) {
	case smm_input:
	case smm_output:
	case smm_io:
		if (strm->sm.sm_fp == NULL)
			closed_stream(strm);
		return(file_len(strm->sm.sm_fp));

	case smm_synonym:
		strm = symbol_value(strm->sm.sm_object0);
		if (type_of(strm) != t_stream)
			FEwrong_type_argument(Sstream, strm);
		goto BEGIN;

	case smm_probe:
	case smm_broadcast:
	case smm_concatenated:
	case smm_two_way:
	case smm_echo:
	case smm_string_input:
	case smm_string_output:
		return(-1);

	default:
		error("illegal stream mode");
	}
}

int
file_column(strm)
object strm;
{
	int i;
	object x;

BEGIN:
	switch (strm->sm.sm_mode) {
	case smm_output:
	case smm_io:
	case smm_two_way:
	case smm_string_output:
		return(strm->sm.sm_int1);

	case smm_synonym:
		strm = symbol_value(strm->sm.sm_object0);
		if (type_of(strm) != t_stream)
			FEwrong_type_argument(Sstream, strm);
		goto BEGIN;

	case smm_echo:
		strm = strm->sm.sm_object1;
		goto BEGIN;

	case smm_input:
	case smm_probe:
	case smm_string_input:
		return(-1);

	case smm_concatenated:
		if (endp(strm->sm.sm_object0))
			return(-1);
		strm = strm->sm.sm_object0->c.c_car;
		goto BEGIN;

	case smm_broadcast:
		for (x = strm->sm.sm_object0; !endp(x); x = x->c.c_cdr) {
			i = file_column(x->c.c_car);
			if (i >= 0)
				return(i);
		}
		return(-1);

#ifdef USER_DEFINED_STREAMS
	case smm_user_defined: /* not right but what is? */
		return(-1);
	
#endif
	default:
		error("illegal stream mode");
	}
}

load(s)
char *s;
{
	object filename, strm, x;
	vs_mark;

	filename = make_simple_string(s);
	vs_push(filename);
	strm = open_stream(filename, smm_input, Cnil, Kerror);
	vs_push(strm);
	for (;;) {
		preserving_whitespace_flag = FALSE;
		detect_eos_flag = TRUE;
		x = read_object_non_recursive(strm);
		if (x == OBJNULL)
			break;
		vs_push(x);
		ieval(x);
		vs_pop;
	}
	close_stream(strm);
	vs_reset;
}

Lmake_synonym_stream()
{
	object x;

	check_arg(1);
	check_type_symbol(&vs_base[0]);
	x = alloc_object(t_stream);
	x->sm.sm_mode = (short)smm_synonym;
	x->sm.sm_fp = NULL;
	x->sm.sm_object0 = vs_base[0];
	x->sm.sm_object1 = OBJNULL;
	x->sm.sm_int0 = x->sm.sm_int1 = 0;
	vs_base[0] = x;
}

Lmake_broadcast_stream()
{
	object x;
	int narg, i;

	narg = vs_top - vs_base;
	for (i = 0;  i < narg;  i++)
		if (type_of(vs_base[i]) != t_stream ||
		    !output_stream_p(vs_base[i]))
			cannot_write(vs_base[i]);
	vs_push(Cnil);
	for (i = narg;  i > 0;  --i)
		stack_cons();
	x = alloc_object(t_stream);
	x->sm.sm_mode = (short)smm_broadcast;
	x->sm.sm_fp = NULL;
	x->sm.sm_object0 = vs_base[0];
	x->sm.sm_object1 = OBJNULL;
	x->sm.sm_int0 = x->sm.sm_int1 = 0;
	vs_base[0] = x;
}

Lmake_concatenated_stream()
{
	object x;
	int narg, i;

	narg = vs_top - vs_base;
	for (i = 0;  i < narg;  i++)
		if (type_of(vs_base[i]) != t_stream ||
		    !input_stream_p(vs_base[i]))
			cannot_read(vs_base[i]);
	vs_push(Cnil);
	for (i = narg;  i > 0;  --i)
		stack_cons();
	x = alloc_object(t_stream);
	x->sm.sm_mode = (short)smm_concatenated;
	x->sm.sm_fp = NULL;
	x->sm.sm_object0 = vs_base[0];
	x->sm.sm_object1 = OBJNULL;
	x->sm.sm_int0 = x->sm.sm_int1 = 0;
	vs_base[0] = x;
}

Lmake_two_way_stream()
{
	check_arg(2);

	if (type_of(vs_base[0]) != t_stream ||
	    !input_stream_p(vs_base[0]))
		cannot_read(vs_base[0]);
	if (type_of(vs_base[1]) != t_stream ||
	    !output_stream_p(vs_base[1]))
		cannot_write(vs_base[1]);
	vs_base[0] = make_two_way_stream(vs_base[0], vs_base[1]);
	vs_pop;
}

Lmake_echo_stream()
{
	check_arg(2);

	if (type_of(vs_base[0]) != t_stream ||
	    !input_stream_p(vs_base[0]))
		cannot_read(vs_base[0]);
	if (type_of(vs_base[1]) != t_stream ||
	    !output_stream_p(vs_base[1]))
		cannot_write(vs_base[1]);
	vs_base[0] = make_echo_stream(vs_base[0], vs_base[1]);
	vs_pop;
}

@(defun make_string_input_stream (strng &o istart iend)
	int s, e;
@
	check_type_string(&strng);
	if (istart == Cnil)
		s = 0;
	else if (type_of(istart) != t_fixnum)
		goto E;
	else
		s = fix(istart);
	if (iend == Cnil)
		e = strng->st.st_fillp;
	else if (type_of(iend) != t_fixnum)
		goto E;
	else
		e = fix(iend);
	if (s < 0 || e > strng->st.st_fillp || s > e)
		goto E;
	@(return `make_string_input_stream(strng, s, e)`)

E:
	FEerror("~S and ~S are illegal as :START and :END~%\
for the string ~S.",
		3, istart, iend, strng);
@)

Lmake_string_output_stream()
{
	check_arg(0);
	vs_push(make_string_output_stream(64));
}

Lget_output_stream_string()
{
	check_arg(1);

	if (type_of(vs_base[0]) != t_stream ||
	    (enum smmode)vs_base[0]->sm.sm_mode != smm_string_output)
		FEerror("~S is not a string-output stream.", 1, vs_base[0]);
	vs_base[0] = get_output_stream_string(vs_base[0]);
}

/*
	(SI:OUTPUT-STREAM-STRING string-output-stream)

		extracts the string associated with the given
		string-output-stream.
*/
siLoutput_stream_string()
{
	check_arg(1);
	if (type_of(vs_base[0]) != t_stream ||
	    (enum smmode)vs_base[0]->sm.sm_mode != smm_string_output)
		FEerror("~S is not a string-output stream.", 1, vs_base[0]);
	vs_base[0] = vs_base[0]->sm.sm_object0;
}

Lstreamp()
{
	check_arg(1);

	if (type_of(vs_base[0]) == t_stream)
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Linput_stream_p()
{
	check_arg(1);

	check_type_stream(&vs_base[0]);
	if (input_stream_p(vs_base[0]))
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Loutput_stream_p()
{
	check_arg(1);

	check_type_stream(&vs_base[0]);
	if (output_stream_p(vs_base[0]))
		vs_base[0] = Ct;
	else
		vs_base[0] = Cnil;
}

Lstream_element_type()
{
	check_arg(1);

	check_type_stream(&vs_base[0]);
	vs_base[0] = stream_element_type(vs_base[0]);
}

@(defun close (strm &key abort)
@
	check_type_stream(&strm);
	close_stream(strm, abort != Cnil);
	@(return Ct)
@)

@(defun open (filename
	      &key (direction Kinput)
		   (element_type Sstring_char)
		   (if_exists Cnil iesp)
		   (if_does_not_exist Cnil idnesp)
	      &aux strm)
	enum smmode smm;
@
	check_type_or_pathname_string_symbol_stream(&filename);
	filename = coerce_to_namestring(filename);
	if (direction == Kinput) {
		smm = smm_input;
		if (!idnesp)
			if_does_not_exist = Kerror;
	} else if (direction == Koutput) {
		smm = smm_output;
		if (!iesp)
			if_exists = Knew_version;
		if (!idnesp) {
			if (if_exists == Koverwrite ||
			    if_exists == Kappend)
				if_does_not_exist = Kerror;
			else
				if_does_not_exist = Kcreate;
		}
	} else if (direction == Kio) {
		smm = smm_io;
		if (!iesp)
			if_exists = Knew_version;
		if (!idnesp) {
			if (if_exists == Koverwrite ||
			    if_exists == Kappend)
				if_does_not_exist = Kerror;
			else
				if_does_not_exist = Kcreate;
		}
	} else if (direction == Kprobe) {
		smm = smm_probe;
		if (!idnesp)
			if_does_not_exist = Cnil;
	} else
		FEerror("~S is an illegal DIRECTION for OPEN.",
			1, direction);
	strm = open_stream(filename, smm, if_exists, if_does_not_exist);
	@(return strm)
@)

@(defun file_position (file_stream &o position)
	int i;
@
	check_type_stream(&file_stream);
	if (position == Cnil) {
		i = file_position(file_stream);
		if (i < 0)
			@(return Cnil)
		@(return `make_fixnum(i)`)
	} else {
		if (position == Kstart)
			i = 0;
		else if (position == Kend)
			i = file_length(file_stream);
		else if (type_of(position) != t_fixnum ||
		    (i = fix((position))) < 0)
			FEerror("~S is an illegal file position~%\
for the file-stream ~S.",
				2, position, file_stream);
		if (file_position_set(file_stream, i) < 0)
			@(return Cnil)
		@(return Ct)
	}	
@)

Lfile_length()
{
	int i;

	check_arg(1);
	check_type_stream(&vs_base[0]);
	i = file_length(vs_base[0]);
	if (i < 0)
		vs_base[0] = Cnil;
	else
		vs_base[0] = make_fixnum(i);
}

object siVload_pathname;

@(defun load (pathname
	      &key (verbose `symbol_value(Vload_verbose)`)
		    print
		    (if_does_not_exist Kerror)
	      &aux pntype fasl_filename lsp_filename filename
		   defaults strm stdoutput x
		   package)
	bds_ptr old_bds_top;
	int i;
	object strm1;
@
	check_type_or_pathname_string_symbol_stream(&pathname);
	pathname = coerce_to_pathname(pathname);
	defaults = symbol_value(Vdefault_pathname_defaults);
	defaults = coerce_to_pathname(defaults);
	pathname = merge_pathnames(pathname, defaults, Knewest);
	pntype = pathname->pn.pn_type;
	filename = coerce_to_namestring(pathname);
        old_bds_top=bds_top;
  	if (pntype == Cnil || pntype == Kwild ||
	    type_of(pntype) == t_string &&
#ifdef UNIX
	    string_eq(pntype, FASL_string)) {
#endif
#ifdef AOSVS

#endif
		pathname->pn.pn_type = FASL_string;
		fasl_filename = coerce_to_namestring(pathname);
	}
	if (pntype == Cnil || pntype == Kwild ||
	    type_of(pntype) == t_string &&
#ifdef UNIX
	    string_eq(pntype, LSP_string)) {
#endif
#ifdef AOSVS

#endif
		pathname->pn.pn_type = LSP_string;
		lsp_filename = coerce_to_namestring(pathname);
	}
	if (fasl_filename != Cnil && file_exists(fasl_filename)) {
		if (verbose != Cnil) {
			setupPRINTdefault(fasl_filename);
			if (file_column(PRINTstream) != 0)
				write_str("\n");
			write_str("Loading ");
			PRINTescape = FALSE;
			write_object(fasl_filename, 0);
			write_str("\n");
			cleanupPRINT();
			flush_stream(PRINTstream);
		}
		package = symbol_value(Vpackage);
		bds_bind(Vpackage, package);
		bds_bind(siVload_pathname,fasl_filename);
		i = fasload(fasl_filename);
		if (print != Cnil) {
			setupPRINTdefault(Cnil);
			vs_top = PRINTvs_top;
			if (file_column(PRINTstream) != 0)
				write_str("\n");
			write_str("Fasload successfully ended.");
			write_str("\n");
			cleanupPRINT();
			flush_stream(PRINTstream);
		}
		bds_unwind(old_bds_top);
		if (verbose != Cnil) {
			setupPRINTdefault(fasl_filename);
			if (file_column(PRINTstream) != 0)
				write_str("\n");
			write_str("Finished loading ");
			PRINTescape = FALSE;
			write_object(fasl_filename, 0);
			write_str("\n");
			cleanupPRINT();
			flush_stream(PRINTstream);
		}
		@(return `make_fixnum(i)`)
	}
	if (lsp_filename != Cnil && file_exists(lsp_filename)) {
		filename = lsp_filename;
	}
	if (if_does_not_exist != Cnil)
		if_does_not_exist = Kerror;
	strm1 = strm
	= open_stream(filename, smm_input, Cnil, if_does_not_exist);
	if (strm == Cnil)
		@(return Cnil)
	if (verbose != Cnil) {
		setupPRINTdefault(filename);
		if (file_column(PRINTstream) != 0)
			write_str("\n");
		write_str("Loading ");
		PRINTescape = FALSE;
		write_object(filename, 0);
		write_str("\n");
		cleanupPRINT();
		flush_stream(PRINTstream);
	}
	package = symbol_value(Vpackage);
	bds_bind(siVload_pathname,pathname);
	bds_bind(Vpackage, package);
	bds_bind(Vstandard_input, strm);
	frs_push(FRS_PROTECT, Cnil);
	if (nlj_active) {
		close_stream(strm1, TRUE);
		nlj_active = FALSE;
		frs_pop();
		bds_unwind(old_bds_top);
		unwind(nlj_fr, nlj_tag);
	}
	for (;;) {
		preserving_whitespace_flag = FALSE;
		detect_eos_flag = TRUE;
		x = read_object_non_recursive(strm);
		if (x == OBJNULL)
			break;
		{
			object *base = vs_base, *top = vs_top, *lex = lex_env;
			object xx;

			lex_new();
			eval(x);
			xx = vs_base[0];
			lex_env = lex;
			vs_top = top;
			vs_base = base;
			x = xx;
		}
		if (print != Cnil) {
			setupPRINTdefault(x);
			write_object(x, 0);
			write_str("\n");
			cleanupPRINT();
			flush_stream(PRINTstream);
		}
	}
	close_stream(strm, TRUE);
	frs_pop();
	bds_unwind(old_bds_top);
	if (verbose != Cnil) {
		setupPRINTdefault(filename);
		if (file_column(PRINTstream) != 0)
			write_str("\n");
		write_str("Finished loading ");
		PRINTescape = FALSE;
		write_object(filename, 0);
		write_str("\n");
		cleanupPRINT();
		flush_stream(PRINTstream);
	}
	@(return Ct)
@)

siLget_string_input_stream_index()
{
	check_arg(1);
	check_type_stream(&vs_base[0]);
	if ((enum smmode)vs_base[0]->sm.sm_mode != smm_string_input)
		FEerror("~S is not a string-input stream.", 1, vs_base[0]);
	vs_base[0] = make_fixnum(vs_base[0]->sm.sm_int0);
}

siLmake_string_output_stream_from_string()
{
	object strng, strm;

	check_arg(1);
	strng = vs_base[0];
	if (type_of(strng) != t_string || !strng->st.st_hasfillp)
		FEerror("~S is not a string with a fill-pointer.", 1, strng);
	strm = alloc_object(t_stream);
	strm->sm.sm_mode = (short)smm_string_output;
	strm->sm.sm_fp = NULL;
	strm->sm.sm_object0 = strng;
	strm->sm.sm_object1 = OBJNULL;
	strm->sm.sm_int0 = strng->st.st_fillp;
	strm->sm.sm_int1 = 0;
	vs_base[0] = strm;
}

siLcopy_stream()
{
	object in, out;

	check_arg(2);
	check_type_stream(&vs_base[0]);
	check_type_stream(&vs_base[1]);
	in = vs_base[0];
	out = vs_base[1];
	while (!stream_at_end(in))
		writec_stream(readc_stream(in), out);
	flush_stream(out);
	vs_base[0] = Ct;
	vs_pop;
#ifdef AOSVS

#endif
}


too_long_file_name(fn)
object fn;
{
	FEerror("~S is a too long file name.", 1, fn);
}

cannot_open(fn)
object fn;
{
	FEerror("Cannot open the file ~A.", 1, fn);
}

cannot_create(fn)
object fn;
{
	FEerror("Cannot create the file ~A.", 1, fn);
}

cannot_read(strm)
object strm;
{
	FEerror("Cannot read the stream ~S.", 1, strm);
}

cannot_write(strm)
object strm;
{
	FEerror("Cannot write to the stream ~S.", 1, strm);
}

#ifdef USER_DEFINED_STREAMS
/* more support for user defined streams */
siLuser_stream_state()
{     
  check_arg(1);

  if(vs_base[0]->sm.sm_object1)
      vs_base[0] = vs_base[0]->sm.sm_object1->str.str_self[0]; 
  else
	FEerror("Stream data NULL ~S", 1, vs_base[0]);
}
#endif

closed_stream(strm)
object strm;
{
	FEerror("The stream ~S is already closed.", 1, strm);
}



/* returns a stream with which one can safely do fwrite to the x->sm.sm_fp
   or nil.
   */


/* coerce stream to one so that x->sm.sm_fp is suitable for fread and fwrite,
   Return nil if this is not possible.
   */

object
coerce_stream(strm,out)
object strm;
int out;
{
 BEGIN:
 if (type_of(strm) != t_stream)
   FEwrong_type_argument(Sstream, strm);
 switch (strm->sm.sm_mode){
 case smm_synonym:
  strm = symbol_value(strm->sm.sm_object0);
  if (type_of(strm) != t_stream)
			FEwrong_type_argument(Sstream, strm);
		goto BEGIN;

 case smm_two_way:
 case smm_echo:
  if (out)strm = strm->sm.sm_object1;
    else strm = strm->sm.sm_object0;
  goto BEGIN;
 case smm_output:
  if (!out) cannot_read(strm);
  break;
 case smm_input:
    if (out) cannot_write(strm);
  break;
 default:
  strm=Cnil;
  }
 if (strm!=Cnil
     && (strm->sm.sm_fp == NULL))
   closed_stream(strm);
 return(strm);
}

siLfp_output_stream()
{check_arg(1);
 vs_base[0]=coerce_stream(vs_base[0],1);
}

siLfp_input_stream()
{check_arg(1);
 vs_base[0]=coerce_stream(vs_base[0],0);
}
 

@(defun fwrite (vector start count stream)
  unsigned char *p;
  int n,beg;
@  
  stream=coerce_stream(stream,1);
  if (stream==Cnil) @(return Cnil);
  p = vector->ust.ust_self;
  beg = ((type_of(start)==t_fixnum) ? fix(start) : 0);
  n = ((type_of(count)==t_fixnum) ? fix(count) : (vector->st.st_fillp - beg));
  if (fwrite(p+beg,1,n,stream->sm.sm_fp)) @(return Ct);
  @(return Cnil);
@)

@(defun fread (vector start count stream)
  unsigned char *p;
  int n,beg;
@  
  stream=coerce_stream(stream,0);
  if (stream==Cnil) @(return Cnil);
  p = vector->ust.ust_self;
  beg = ((type_of(start)==t_fixnum) ? fix(start) : 0);
  n = ((type_of(count)==t_fixnum) ? fix(count) : (vector->st.st_fillp - beg));
  if (n=fread(p+beg,1,n,stream->sm.sm_fp))
      @(return `make_fixnum(n)`);
  @(return Cnil);
@)



init_file()
{
	object standard_input;
	object standard_output;
	object standard;
	object x;
#ifdef AOSVS1



#endif

	standard_input = alloc_object(t_stream);
	standard_input->sm.sm_mode = (short)smm_input;
	standard_input->sm.sm_fp = stdin;
	standard_input->sm.sm_object0 = Sstring_char;
	standard_input->sm.sm_object1
#ifdef UNIX
	= make_simple_string("stdin");
#endif
#ifdef AOSVS

#endif
	standard_input->sm.sm_int0 = 0;
	standard_input->sm.sm_int1 = 0;

	standard_output = alloc_object(t_stream);
	standard_output->sm.sm_mode = (short)smm_output;
	standard_output->sm.sm_fp = stdout;
	standard_output->sm.sm_object0 = Sstring_char;
	standard_output->sm.sm_object1
#ifdef UNIX
	= make_simple_string("stdout");
#endif
#ifdef AOSVS

#endif
	standard_output->sm.sm_int0 = 0;
	standard_output->sm.sm_int1 = 0;

	terminal_io = standard
	= make_two_way_stream(standard_input, standard_output);
	enter_mark_origin(&terminal_io);

	Vterminal_io
	= make_special("*TERMINAL-IO*", standard);

	x = alloc_object(t_stream);
	x->sm.sm_mode = (short)smm_synonym;
	x->sm.sm_fp = NULL;
	x->sm.sm_object0 = Vterminal_io;
	x->sm.sm_object1 = OBJNULL;
	x->sm.sm_int0 = x->sm.sm_int1 = 0;
	standard = x;

	Vstandard_input
	= make_special("*STANDARD-INPUT*", standard);
	Vstandard_output
	= make_special("*STANDARD-OUTPUT*", standard);
	Verror_output
	= make_special("*ERROR-OUTPUT*", standard);

#ifdef AOSVS1














#endif

	Vquery_io
	= make_special("*QUERY-IO*", standard);
	Vdebug_io
	= make_special("*DEBUG-IO*", standard);
	Vtrace_output
	= make_special("*TRACE-OUTPUT*", standard);

#ifdef AOSVS1



















#endif
}

init_file_function()
{
	Kabort = make_keyword("ABORT");

	Kdirection = make_keyword("DIRECTION");
	Kinput = make_keyword("INPUT");
	Koutput = make_keyword("OUTPUT");
	Kio = make_keyword("IO");
	Kprobe = make_keyword("PROBE");
	Kelement_type = make_keyword("ELEMENT-TYPE");
	Kdefault = make_keyword("DEFAULT");
	Kif_exists = make_keyword("IF-EXISTS");
	Kerror = make_keyword("ERROR");
	Knew_version = make_keyword("NEW-VERSION");
	Krename = make_keyword("RENAME");
	Krename_and_delete = make_keyword("RENAME-AND-DELETE");
	Koverwrite = make_keyword("OVERWRITE");
	Kappend = make_keyword("APPEND");
	Ksupersede = make_keyword("SUPERSEDE");
	Kif_does_not_exist = make_keyword("IF-DOES-NOT-EXIST");
	/*  Kerror = make_keyword("ERROR");  */
	Kcreate = make_keyword("CREATE");

	Kprint = make_keyword("PRINT");
	Kverbose = make_keyword("VERBOSE");
	Kif_does_not_exist = make_keyword("IF-DOES-NOT-EXIST");
	Kset_default_pathname = make_keyword("SET-DEFAULT-PATHNAME");

	Vload_verbose = make_special("*LOAD-VERBOSE*", Ct);
	siVload_pathname = make_si_special("*LOAD-PATHNAME*",Cnil);

#ifdef UNIX
	FASL_string = make_simple_string("o");
	make_si_constant("*EOF*",make_fixnum(EOF));
#endif
#ifdef AOSVS

#endif
	enter_mark_origin(&FASL_string);
#ifdef UNIX
	LSP_string = make_simple_string("lsp");
#endif
#ifdef AOSVS

#endif
	enter_mark_origin(&LSP_string);
	make_si_function("FP-INPUT-STREAM",	siLfp_input_stream);
	make_si_function("FP-OUTPUT-STREAM",	siLfp_output_stream);

	make_function("MAKE-SYNONYM-STREAM", Lmake_synonym_stream);
	make_function("MAKE-BROADCAST-STREAM", Lmake_broadcast_stream);
	make_function("MAKE-CONCATENATED-STREAM",
		      Lmake_concatenated_stream);
	make_function("MAKE-TWO-WAY-STREAM", Lmake_two_way_stream);
	make_function("MAKE-ECHO-STREAM", Lmake_echo_stream);
	make_function("MAKE-STRING-INPUT-STREAM",
		      Lmake_string_input_stream);
	make_function("MAKE-STRING-OUTPUT-STREAM",
		      Lmake_string_output_stream);
	make_function("GET-OUTPUT-STREAM-STRING",
		      Lget_output_stream_string);

	make_si_function("OUTPUT-STREAM-STRING", siLoutput_stream_string);
	make_si_function("FWRITE",Lfwrite);
	make_si_function("FREAD",Lfread);
	make_function("STREAMP", Lstreamp);
	make_function("INPUT-STREAM-P", Linput_stream_p);
	make_function("OUTPUT-STREAM-P", Loutput_stream_p);
	make_function("STREAM-ELEMENT-TYPE", Lstream_element_type);
	make_function("CLOSE", Lclose);

	make_function("OPEN", Lopen);

	make_function("FILE-POSITION", Lfile_position);
	make_function("FILE-LENGTH", Lfile_length);

	make_function("LOAD", Lload);

	make_si_function("GET-STRING-INPUT-STREAM-INDEX",
			 siLget_string_input_stream_index);
	make_si_function("MAKE-STRING-OUTPUT-STREAM-FROM-STRING",
			 siLmake_string_output_stream_from_string);
	make_si_function("COPY-STREAM", siLcopy_stream);

#ifdef USER_DEFINED_STREAMS
	make_si_function("USER-STREAM-STATE", siLuser_stream_state);
#endif
	siVignore_eof_on_terminal_io
	= make_si_special("*IGNORE-EOF-ON-TERMINAL-IO*", Cnil);
}


object
read_fasl_data(str)
char *str;
{
	object faslfile, data;
#ifdef UNIX
	FILE *fp;


#ifdef BSD
#ifdef HAVE_AOUT
 	struct exec header;
#endif
#endif
#ifdef ATT
	struct filehdr fileheader;
#endif
#ifdef E15
	struct exec header;
#endif
	int i;
#endif
        vs_mark;

	faslfile = make_simple_string(str);
	vs_push(faslfile);
	faslfile = open_stream(faslfile, smm_input, Cnil, Kerror);
	vs_push(faslfile);

#ifdef SEEK_TO_END_OFILE
 	SEEK_TO_END_OFILE(faslfile->sm.sm_fp);
#else

#ifdef BSD
	fp = faslfile->sm.sm_fp;
	fread(&header, sizeof(header), 1, fp);
	fseek(fp,
	      header.a_text+header.a_data+
	      header.a_syms+header.a_trsize+header.a_drsize,
	      1);
	fread(&i, sizeof(i), 1, fp);
	fseek(fp, i - sizeof(i), 1);
#endif

#ifdef ATT
	fp = faslfile->sm.sm_fp;
	fread(&fileheader, sizeof(fileheader), 1, fp);
	fseek(fp,
	      fileheader.f_symptr+fileheader.f_nsyms*SYMESZ,
	      0);
	fread(&i, sizeof(i), 1, fp);
	fseek(fp, i - sizeof(i), 1);
	while ((i = getc(fp)) == 0)
		;
	ungetc(i, fp);
#endif

#ifdef E15
	fp = faslfile->sm.sm_fp;
	fread(&header, sizeof(header), 1, fp);
	fseek(fp,
	      header.a_text+header.a_data+
	      header.a_syms+header.a_trsize+header.a_drsize,
	      1);
#endif

#ifdef DGUX




#endif

#ifdef AOSVS




#endif
#endif
	data = read_fasl_vector(faslfile);

	vs_push(data);
	close_stream(faslfile, TRUE);
	vs_reset;
	return(data);
}
