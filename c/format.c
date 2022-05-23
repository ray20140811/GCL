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
	format.c
*/

#include "include.h"
#include <varargs.h>
object siVindent_formatted_output;

object fmt_stream;
int ctl_origin;
int ctl_index;
int ctl_end;
object *fmt_base;
int fmt_index;
int fmt_end;
int *fmt_jmp_buf;
int fmt_indents;
object fmt_string;

#define	ctl_string	(fmt_string->st.st_self + ctl_origin)

#define	fmt_old		VOL object old_fmt_stream; \
			VOL int old_ctl_origin; \
			VOL int old_ctl_index; \
			VOL int old_ctl_end; \
			object * VOL old_fmt_base; \
			VOL int old_fmt_index; \
			VOL int old_fmt_end; \
			int  * VOL old_fmt_jmp_buf; \
			VOL int old_fmt_indents; \
			VOL object old_fmt_string
#define	fmt_save	old_fmt_stream = fmt_stream; \
			old_ctl_origin = ctl_origin; \
			old_ctl_index = ctl_index; \
			old_ctl_end = ctl_end; \
			old_fmt_base = fmt_base; \
			old_fmt_index = fmt_index; \
			old_fmt_end = fmt_end; \
			old_fmt_jmp_buf = fmt_jmp_buf; \
			old_fmt_indents = fmt_indents; \
			old_fmt_string = fmt_string
#define	fmt_restore	fmt_stream = old_fmt_stream; \
			ctl_origin = old_ctl_origin; \
			ctl_index = old_ctl_index; \
			ctl_end = old_ctl_end; \
			fmt_base = old_fmt_base; \
			fmt_index = old_fmt_index; \
			fmt_end = old_fmt_end; \
			fmt_jmp_buf = old_fmt_jmp_buf; \
			fmt_indents = old_fmt_indents; \
			fmt_string = old_fmt_string
#define	fmt_restore1	fmt_stream = old_fmt_stream; \
			ctl_origin = old_ctl_origin; \
			ctl_index = old_ctl_index; \
			ctl_end = old_ctl_end; \
			fmt_jmp_buf = old_fmt_jmp_buf; \
			fmt_indents = old_fmt_indents; \
			fmt_string = old_fmt_string

#ifndef WRITEC_NEWLINE
#define  WRITEC_NEWLINE(strm) (writec_stream('\n',strm))
#endif

object fmt_temporary_stream;
object fmt_temporary_string;

int fmt_nparam;
#define	INT	1
#define	CHAR	2
struct {
	int fmt_param_type;
	int fmt_param_value;
} fmt_param[100];


char *fmt_big_numeral[] = {
	"thousand",
	"million",
	"billion",
	"trillion",
	"quadrillion",
	"quintillion",
	"sextillion",
	"septillion",
	"octillion"
};

char *fmt_numeral[] = {
	"zero", "one", "two", "three", "four",
	"five", "six", "seven", "eight", "nine",
	"ten", "eleven", "twelve", "thirteen", "fourteen",
	"fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
	"zero", "ten", "twenty", "thirty", "forty",
	"fifty", "sixty", "seventy", "eighty", "ninety"
};

char *fmt_ordinal[] = {
	"zeroth", "first", "second", "third", "fourth",
	"fifth", "sixth", "seventh", "eighth", "ninth",
	"tenth", "eleventh", "twelfth", "thirteenth", "fourteenth",
	"fifteenth", "sixteenth", "seventeenth", "eighteenth", "nineteenth",
	"zeroth", "tenth", "twentieth", "thirtieth", "fortieth",
	"fiftieth", "sixtieth", "seventieth", "eightieth", "ninetieth"
};


int fmt_spare_spaces;
int fmt_line_length;


int
fmt_tempstr(s)
int s;
{
	return(fmt_temporary_string->st.st_self[s]);
}

ctl_advance()
{
	if (ctl_index >= ctl_end)
		fmt_error("unexpected end of control string");
	return(ctl_string[ctl_index++]);
}

object
fmt_advance()
{
	if (fmt_index >= fmt_end)
		fmt_error("arguments exhausted");
	return(fmt_base[fmt_index++]);
}


format(fmt_stream0, ctl_origin0, ctl_end0)
object fmt_stream0;
int ctl_origin0;
int ctl_end0;
{
	int c, i, n;
	bool colon, atsign;
	object x;

	fmt_stream = fmt_stream0;
	ctl_origin = ctl_origin0;
	ctl_index = 0;
	ctl_end = ctl_end0;

LOOP:
	if (ctl_index >= ctl_end)
		return;
	if ((c = ctl_advance()) != '~') {
		writec_stream(c, fmt_stream);
		goto LOOP;
	}
	n = 0;
	for (;;) {
		switch (c = ctl_advance()) {
		case ',':
			fmt_param[n].fmt_param_type = NULL;
			break;

		case '0':  case '1':  case '2':  case '3':  case '4':
		case '5':  case '6':  case '7':  case '8':  case '9':
		DIGIT:
			i = 0;
			do {
				i = i*10 + (c - '0');
				c = ctl_advance();
			} while (isDigit(c));
			fmt_param[n].fmt_param_type = INT;
			fmt_param[n].fmt_param_value = i;
			break;

		case '+':
			c = ctl_advance();
			if (!isDigit(c))
				fmt_error("digit expected");
			goto DIGIT;

		case '-':
			c = ctl_advance();
			if (!isDigit(c))
				fmt_error("digit expected");
			i = 0;
			do {
				i = i*10 + (c - '0');
				c = ctl_advance();
			} while (isDigit(c));
			fmt_param[n].fmt_param_type = INT;
			fmt_param[n].fmt_param_value = -i;
			break;

		case '\'':
			fmt_param[n].fmt_param_type = CHAR;
			fmt_param[n].fmt_param_value = ctl_advance();
			c = ctl_advance();
			break;

		case 'v':  case 'V':
			x = fmt_advance();
			if (type_of(x) == t_fixnum) {
				fmt_param[n].fmt_param_type = INT;
				fmt_param[n].fmt_param_value = fix(x);
			} else if (type_of(x) == t_character) {
				fmt_param[n].fmt_param_type = CHAR;
				fmt_param[n].fmt_param_value = x->ch.ch_code;
                        } else if (x == Cnil) {
                                 fmt_param[n].fmt_param_type = NULL;				
			} else
				fmt_error("illegal V parameter");
			c = ctl_advance();
			break;

		case '#':
			fmt_param[n].fmt_param_type = INT;
			fmt_param[n].fmt_param_value = fmt_end - fmt_index;
			c = ctl_advance();
			break;

		default:
			if (n > 0)
				fmt_error("illegal ,");
			else
				goto DIRECTIVE;
		}
		n++;
		if (c != ',')
			break;
	}

DIRECTIVE:
	colon = atsign = FALSE;
	if (c == ':') {
		colon = TRUE;
		c = ctl_advance();
	}
	if (c == '@') {
		atsign = TRUE;
		c = ctl_advance();
	}
	fmt_nparam = n;
	switch (c) {
	case 'a':  case 'A':
		fmt_ascii(colon, atsign);
		break;

	case 's':  case 'S':
		fmt_S_expression(colon, atsign);
		break;

	case 'd':  case 'D':
		fmt_decimal(colon, atsign);
		break;

	case 'b':  case 'B':
		fmt_binary(colon, atsign);
		break;

	case 'o':  case 'O':
		fmt_octal(colon, atsign);
		break;

	case 'x':  case 'X':
		fmt_hexadecimal(colon, atsign);
		break;

	case 'r':  case 'R':
		fmt_radix(colon, atsign);
		break;

	case 'p':  case 'P':
		fmt_plural(colon, atsign);
		break;

	case 'c':  case 'C':
		fmt_character(colon, atsign);
		break;

	case 'f':  case 'F':
		fmt_fix_float(colon, atsign);
		break;

	case 'e':  case 'E':
		fmt_exponential_float(colon, atsign);
		break;

	case 'g':  case 'G':
		fmt_general_float(colon, atsign);
		break;

	case '$':
		fmt_dollars_float(colon, atsign);
		break;

	case '%':
		fmt_percent(colon, atsign);
		break;

	case '&':
		fmt_ampersand(colon, atsign);
		break;

	case '|':
		fmt_bar(colon, atsign);
		break;

	case '~':
		fmt_tilde(colon, atsign);
		break;

	case '\n':
	case '\r':	
		fmt_newline(colon, atsign);
		break;

	case 't':  case 'T':
		fmt_tabulate(colon, atsign);
		break;

	case '*':
		fmt_asterisk(colon, atsign);
		break;

	case '?':
		fmt_indirection(colon, atsign);
		break;

	case '(':
		fmt_case(colon, atsign);
		break;

	case '[':
		fmt_conditional(colon, atsign);
		break;

	case '{':
		fmt_iteration(colon, atsign);
		break;

	case '<':
		fmt_justification(colon, atsign);
		break;

	case '^':
		fmt_up_and_out(colon, atsign);
		break;

	case ';':
		fmt_semicolon(colon, atsign);
		break;

	default:
   {object user_fmt=getf(siVindent_formatted_output->s.s_plist,make_fixnum(c),Cnil);
    
    if (user_fmt!=Cnil)
     {object *oldbase=vs_base;
      object *oldtop=vs_top;
      vs_base=vs_top;
      vs_push(fmt_advance());
      vs_push(fmt_stream);
      vs_push(make_fixnum(colon));
      vs_push(make_fixnum(atsign));
      if (type_of(user_fmt)==t_symbol) user_fmt=symbol_function(user_fmt);
      funcall(user_fmt);
      vs_base=oldbase; vs_top=oldtop; break;}}
		fmt_error("illegal directive");
	}
	goto LOOP;
}



fmt_skip()
{
	int c, level = 0;
	
LOOP:
	if (ctl_advance() != '~')
		goto LOOP;
	for (;;)
		switch (c = ctl_advance()) {
		case '\'':
			ctl_advance();

		case ',':
		case '0':  case '1':  case '2':  case '3':  case '4':
		case '5':  case '6':  case '7':  case '8':  case '9':
		case '+':
		case '-':
		case 'v':  case 'V':
		case '#':
		case ':':  case '@':
			continue;

		default:
			goto DIRECTIVE;
		}

DIRECTIVE:
	switch (c) {
	case '(':  case '[':  case '<':  case '{':
		level++;
		break;

	case ')':  case ']':  case '>':  case '}':
		if (level == 0)
			return(ctl_index);
		else
			--level;
		break;

	case ';':
		if (level == 0)
			return(ctl_index);
		break;
	}
	goto LOOP;
}


fmt_max_param(n)
{
	if (fmt_nparam > n)
		fmt_error("too many parameters");
}

fmt_not_colon(colon)
bool colon;
{
	if (colon)
		fmt_error("illegal :");
}

fmt_not_atsign(atsign)
bool atsign;
{
	if (atsign)
		fmt_error("illegal @");
}

fmt_not_colon_atsign(colon, atsign)
bool colon, atsign;
{
	if (colon && atsign)
		fmt_error("illegal :@");
}

fmt_set_param(i, p, t, v)
int i, *p, t, v;
{
	if (i >= fmt_nparam || fmt_param[i].fmt_param_type == NULL)
		*p = v;
	else if (fmt_param[i].fmt_param_type != t)
		fmt_error("illegal parameter type");
	else
		*p = fmt_param[i].fmt_param_value;
}	


fmt_ascii(colon, atsign)
{
	int mincol, colinc, minpad, padchar;
	object x;
	int c, l, i;

	fmt_max_param(4);
	fmt_set_param(0, &mincol, INT, 0);
	fmt_set_param(1, &colinc, INT, 1);
	fmt_set_param(2, &minpad, INT, 0);
	fmt_set_param(3, &padchar, CHAR, ' ');

	fmt_temporary_string->st.st_fillp = 0;
	fmt_temporary_stream->sm.sm_int0 = file_column(fmt_stream);
	fmt_temporary_stream->sm.sm_int1 = file_column(fmt_stream);
	x = fmt_advance();
	if (colon && x == Cnil)
		writestr_stream("()", fmt_temporary_stream);
	else if (mincol == 0 && minpad == 0) {
		princ(x, fmt_stream);
		return;
	} else
		princ(x, fmt_temporary_stream);
	l = fmt_temporary_string->st.st_fillp;
	for (i = minpad;  l + i < mincol;  i += colinc)
		;
	if (!atsign) {
		write_string(fmt_temporary_string, fmt_stream);
		while (i-- > 0)
			writec_stream(padchar, fmt_stream);
	} else {
		while (i-- > 0)
			writec_stream(padchar, fmt_stream);
		write_string(fmt_temporary_string, fmt_stream);
	}
}

fmt_S_expression(colon, atsign)
{
	int mincol, colinc, minpad, padchar;
	object x;
	int c, l, i;

	fmt_max_param(4);
	fmt_set_param(0, &mincol, INT, 0);
	fmt_set_param(1, &colinc, INT, 1);
	fmt_set_param(2, &minpad, INT, 0);
	fmt_set_param(3, &padchar, CHAR, ' ');

	fmt_temporary_string->st.st_fillp = 0;
	fmt_temporary_stream->sm.sm_int0 = file_column(fmt_stream);
	fmt_temporary_stream->sm.sm_int1 = file_column(fmt_stream);
	x = fmt_advance();
	if (colon && x == Cnil)
		writestr_stream("()", fmt_temporary_stream);
	else if (mincol == 0 && minpad == 0) {
		prin1(x, fmt_stream);
		return;
	} else
		prin1(x, fmt_temporary_stream);
	l = fmt_temporary_string->st.st_fillp;
	for (i = minpad;  l + i < mincol;  i += colinc)
		;
	if (!atsign) {
		write_string(fmt_temporary_string, fmt_stream);
		while (i-- > 0)
			writec_stream(padchar, fmt_stream);
	} else {
		while (i-- > 0)
			writec_stream(padchar, fmt_stream);
		write_string(fmt_temporary_string, fmt_stream);
	}
}

fmt_decimal(colon, atsign)
{
	int mincol, padchar, commachar;

	fmt_max_param(3);
	fmt_set_param(0, &mincol, INT, 0);
	fmt_set_param(1, &padchar, CHAR, ' ');
	fmt_set_param(2, &commachar, CHAR, ',');
	fmt_integer(fmt_advance(), colon, atsign,
		    10, mincol, padchar, commachar);
}

fmt_binary(colon, atsign)
{
	int mincol, padchar, commachar;

	fmt_max_param(3);
	fmt_set_param(0, &mincol, INT, 0);
	fmt_set_param(1, &padchar, CHAR, ' ');
	fmt_set_param(2, &commachar, CHAR, ',');
	fmt_integer(fmt_advance(), colon, atsign,
		    2, mincol, padchar, commachar);
}

fmt_octal(colon, atsign)
{
	int mincol, padchar, commachar;

	fmt_max_param(3);
	fmt_set_param(0, &mincol, INT, 0);
	fmt_set_param(1, &padchar, CHAR, ' ');
	fmt_set_param(2, &commachar, CHAR, ',');
	fmt_integer(fmt_advance(), colon, atsign,
		    8, mincol, padchar, commachar);
}

fmt_hexadecimal(colon, atsign)
{
	int mincol, padchar, commachar;

	fmt_max_param(3);
	fmt_set_param(0, &mincol, INT, 0);
	fmt_set_param(1, &padchar, CHAR, ' ');
	fmt_set_param(2, &commachar, CHAR, ',');
	fmt_integer(fmt_advance(), colon, atsign,
		    16, mincol, padchar, commachar);
}

fmt_radix(colon, atsign)
{
	int radix, mincol, padchar, commachar;
	object x;
	int i, j, k;
	int s, t;
	bool b;
	extern (*write_ch_fun)(), writec_PRINTstream();

	if (fmt_nparam == 0) {
		x = fmt_advance();
		check_type_integer(&x);
		if (atsign) {
			if (type_of(x) == t_fixnum)
				i = fix(x);
			else
				i = -1;
			if (!colon && (i <= 0 || i >= 4000) ||
			    colon && (i <= 0 || i >= 5000)) {
				fmt_integer(x, FALSE, FALSE, 10, 0, ' ', ',');
				return;
			}
			fmt_roman(i/1000, 'M', '*', '*', colon);
			fmt_roman(i%1000/100, 'C', 'D', 'M', colon);
			fmt_roman(i%100/10, 'X', 'L', 'C', colon);
			fmt_roman(i%10, 'I', 'V', 'X', colon);
			return;
		}
		fmt_temporary_string->st.st_fillp = 0;
		fmt_temporary_stream->sm.sm_int0 = file_column(fmt_stream);
		fmt_temporary_stream->sm.sm_int1 = file_column(fmt_stream);
		PRINTstream = fmt_temporary_stream;
		PRINTradix = FALSE;
		PRINTbase = 10;
		write_ch_fun = writec_PRINTstream;
		write_object(x, 0);
		s = 0;
		i = fmt_temporary_string->st.st_fillp;
		if (i == 1 && fmt_tempstr(s) == '0') {
			writestr_stream("zero", fmt_stream);
			if (colon)
				writestr_stream("th", fmt_stream);
			return;
		} else if (fmt_tempstr(s) == '-') {
			writestr_stream("minus ", fmt_stream);
			--i;
			s++;
		}
		t = fmt_temporary_string->st.st_fillp;
		for (;;)
			if (fmt_tempstr(--t) != '0')
				break;
		for (b = FALSE;  i > 0;  i -= j) {
			b = fmt_nonillion(s, j = (i+29)%30+1, b,
					  i<=30&&colon, t);
			s += j;
			if (b && i > 30) {
				for (k = (i - 1)/30;  k > 0;  --k)
					writestr_stream(" nonillion",
							fmt_stream);
				if (colon && s > t)
					writestr_stream("th", fmt_stream);
			}
		}
		return;
	}
	fmt_max_param(4);
	fmt_set_param(0, &radix, INT, 10);
	fmt_set_param(1, &mincol, INT, 0);
	fmt_set_param(2, &padchar, CHAR, ' ');
	fmt_set_param(3, &commachar, CHAR, ',');
	x = fmt_advance();
	check_type_integer(&x);
	if (radix < 0 || radix > 36) {
		vs_push(make_fixnum(radix));
		FEerror("~D is illegal as a radix.", 1, vs_head);
	}
	fmt_integer(x, colon, atsign, radix, mincol, padchar, commachar);
}	

fmt_integer(x, colon, atsign, radix, mincol, padchar, commachar)
object x;
{
	int l, l1;
	int s;
	extern (*write_ch_fun)(), writec_PRINTstream();

	if (type_of(x) != t_fixnum && type_of(x) != t_bignum) {
		fmt_temporary_string->st.st_fillp = 0;
		fmt_temporary_stream->sm.sm_int0 = file_column(fmt_stream);
		fmt_temporary_stream->sm.sm_int1 = file_column(fmt_stream);
		setupPRINTdefault(x);
		PRINTstream = fmt_temporary_stream;
		PRINTescape = FALSE;
		PRINTbase = radix;
		write_ch_fun = writec_PRINTstream;
		write_object(x, 0);
		cleanupPRINT();
		l = fmt_temporary_string->st.st_fillp;
		mincol -= l;
		while (mincol-- > 0)
			writec_stream(padchar, fmt_stream);
		for (s = 0;  l > 0;  --l, s++)
			writec_stream(fmt_tempstr(s), fmt_stream);
		return;
	}
	fmt_temporary_string->st.st_fillp = 0;
	fmt_temporary_stream->sm.sm_int0 = file_column(fmt_stream);
	fmt_temporary_stream->sm.sm_int1 = file_column(fmt_stream);
	PRINTstream = fmt_temporary_stream;
	PRINTradix = FALSE;
	PRINTbase = radix;
	write_ch_fun = writec_PRINTstream;
	write_object(x, 0);
	l = l1 = fmt_temporary_string->st.st_fillp;
	s = 0;
	if (fmt_tempstr(s) == '-')
		--l1;
	mincol -= l;
	if (colon)
		mincol -= (l1 - 1)/3;
	if (atsign && fmt_tempstr(s) != '-')
		--mincol;
	while (mincol-- > 0)
		writec_stream(padchar, fmt_stream);
	if (fmt_tempstr(s) == '-') {
		s++;
		writec_stream('-', fmt_stream);
	} else if (atsign)
		writec_stream('+', fmt_stream);
	while (l1-- > 0) {
		writec_stream(fmt_tempstr(s++), fmt_stream);
		if (colon && l1 > 0 && l1%3 == 0)
			writec_stream(commachar, fmt_stream);
	}
}

fmt_nonillion(s, i, b, o, t)
int s, t;
int i;
bool b, o;
{
	int j;

	for (;  i > 3;  i -= j) {
		b = fmt_thousand(s, j = (i+2)%3+1, b, FALSE, t);
		if (j != 3 || fmt_tempstr(s) != '0' ||
		    fmt_tempstr(s+1) != '0' || fmt_tempstr(s+2) != '0') {
			writec_stream(' ', fmt_stream);
			writestr_stream(fmt_big_numeral[(i - 1)/3 - 1],
					fmt_stream);
			s += j;
			if (o && s > t)
				writestr_stream("th", fmt_stream);
		} else
			s += j;
	}
	return(fmt_thousand(s, i, b, o, t));
}		

fmt_thousand(s, i, b, o, t)
int s, t;
int i;
bool b, o;
{
	if (i == 3 && fmt_tempstr(s) > '0') {
		if (b)
			writec_stream(' ', fmt_stream);
		fmt_write_numeral(s, 0);
		writestr_stream(" hundred", fmt_stream);
		--i;
		s++;
		b = TRUE;
		if (o & s > t)
			writestr_stream("th", fmt_stream);
	}
	if (i == 3) {
		--i;
		s++;
	}
	if (i == 2 && fmt_tempstr(s) > '0') {
		if (b)
			writec_stream(' ', fmt_stream);
		if (fmt_tempstr(s) == '1') {
			if (o && s + 2 > t)
				fmt_write_ordinal(++s, 10);
			else
				fmt_write_numeral(++s, 10);
			return(TRUE);
		} else {
			if (o && s + 1 > t)
				fmt_write_ordinal(s, 20);
			else
				fmt_write_numeral(s, 20);
			s++;
			if (fmt_tempstr(s) > '0') {
				writec_stream('-', fmt_stream);
				if (o && s + 1 > t)
					fmt_write_ordinal(s, 0);
				else
					fmt_write_numeral(s, 0);
			}
			return(TRUE);
		}
	}
	if (i == 2)
		s++;
	if (fmt_tempstr(s) > '0') {
		if (b)
			writec_stream(' ', fmt_stream);
		if (o && s + 1 > t)
			fmt_write_ordinal(s, 0);
		else
			fmt_write_numeral(s, 0);
		return(TRUE);
	}
	return(b);
}
	
fmt_write_numeral(s, i)
int s, i;
{
	writestr_stream(fmt_numeral[fmt_tempstr(s) - '0' + i], fmt_stream);
}

fmt_write_ordinal(s, i)
int s, i;
{
	writestr_stream(fmt_ordinal[fmt_tempstr(s) - '0' + i], fmt_stream);
}

fmt_roman(i, one, five, ten, colon)
{
	int j;

	if (i == 0)
		return;
	if (!colon && i < 4 || colon && i < 5)
		for (j = 0;  j < i;  j++)
			writec_stream(one, fmt_stream);
	else if (!colon && i == 4) {
		writec_stream(one, fmt_stream);
		writec_stream(five, fmt_stream);
	} else if (!colon && i < 9 || colon) {
		writec_stream(five, fmt_stream);
		for (j = 5;  j < i;  j++)
			writec_stream(one, fmt_stream);
	} else if (!colon && i == 9) {
		writec_stream(one, fmt_stream);
		writec_stream(ten, fmt_stream);
	}
}

fmt_plural(colon, atsign)
{
	fmt_max_param(0);
	if (colon) {
		if (fmt_index == 0)
			fmt_error("can't back up");
		--fmt_index;
	}
	if (eql(fmt_advance(), make_fixnum(1)))
		if (atsign)
			writec_stream('y', fmt_stream);
		else
			;
	else
		if (atsign)
			writestr_stream("ies", fmt_stream);
		else
			writec_stream('s', fmt_stream);
}

fmt_character(colon, atsign)
{
	object x;
	int i;

	fmt_max_param(0);
	fmt_temporary_string->st.st_fillp = 0;
	fmt_temporary_stream->sm.sm_int0 = 0;
	fmt_temporary_stream->sm.sm_int1 = 0;
	x = fmt_advance();
	check_type_character(&x);
	prin1(x, fmt_temporary_stream);
	if (!colon && atsign)
		i = 0;
	else
		i = 2;
	for (;  i < fmt_temporary_string->st.st_fillp;  i++)
		writec_stream(fmt_tempstr(i), fmt_stream);
}

fmt_fix_float(colon, atsign)
{
	int w, d, k, overflowchar, padchar;
	double f;
	int sign;
	char buff[256], *b, buff1[256];
	int exp;
	int i, j;
	object x;
	int n, m;
	vs_mark;

	b = buff1 + 1;

	fmt_not_colon(colon);
	fmt_max_param(5);
	fmt_set_param(0, &w, INT, 0);
	if (w < 0)
		fmt_error("illegal width");
	fmt_set_param(0, &w, INT, -1);
	fmt_set_param(1, &d, INT, 0);
	if (d < 0)
		fmt_error("illegal number of digits");
	fmt_set_param(1, &d, INT, -1);
	fmt_set_param(2, &k, INT, 0);
	fmt_set_param(3, &overflowchar, CHAR, -1);
	fmt_set_param(4, &padchar, CHAR, ' ');

	x = fmt_advance();
	if (type_of(x) == t_fixnum ||
	    type_of(x) == t_bignum ||
	    type_of(x) == t_ratio) {
		x = make_shortfloat((shortfloat)number_to_double(x));
		vs_push(x);
	}
	if (type_of(x) == t_complex) {
		if (w < 0)
			prin1(x, fmt_stream);
		else {
			fmt_nparam = 1;
			--fmt_index;
			fmt_decimal(colon, atsign);
		}
		vs_reset;
		return;
	}
	if (type_of(x) == t_longfloat)
		n = 16;
	else
		n = 7;
	f = number_to_double(x);
	edit_double(n, f, &sign, buff, &exp);
	if (exp + k > 100 || exp + k < -100 || d > 100) {
		prin1(x, fmt_stream);
		vs_reset;
		return;
	}
	if (d >= 0)
		m = d + exp + k + 1;
	else if (w >= 0) {
		if (exp + k >= 0)
			m = w - 1;
		else
			m = w + exp + k - 2;
		if (sign < 0 || atsign)
			--m;
		if (m == 0)
			m = 1;
	} else
		m = n;
	if (m <= 0) {
		if (m == 0 && buff[0] >= '5') {
			exp++;
			n = m = 1;
			buff[0] = '1';
		} else
			n = m = 0;
	} else if (m < n) {
		n = m;
		edit_double(n, f, &sign, buff, &exp);
	}
	while (n >= 0)
		if (buff[n - 1] == '0')
			--n;
		else
			break;
	exp += k;
	j = 0;
	if (exp >= 0) {
		for (i = 0;  i <= exp;  i++)
			b[j++] = i < n ? buff[i] : '0';
		b[j++] = '.';
		if (d >= 0)
			for (m = i + d;  i < m;  i++)
				b[j++] = i < n ? buff[i] : '0';
		else
			for (;  i < n;  i++)
				b[j++] = buff[i];
	} else {
		b[j++] = '.';
		if (d >= 0) {
			for (i = 0;  i < (-exp) - 1 && i < d;  i++)
				b[j++] = '0';
			for (m = d - i, i = 0;  i < m;  i++)
				b[j++] = i < n ? buff[i] : '0';
		} else if (n > 0) {
			for (i = 0;  i < (-exp) - 1;  i++)
				b[j++] = '0';
			for (i = 0;  i < n;  i++)
				b[j++] = buff[i];
		}
	}
	b[j] = '\0';
	if (w >= 0) {
		if (sign < 0 || atsign)
			--w;
		if (j > w && overflowchar >= 0)
			goto OVER;
		if (j < w && b[j-1] == '.' && d) {
			b[j++] = '0';
			b[j] = '\0';
		}
		if (j < w && b[0] == '.') {
			*--b = '0';
			j++;
		}
		for (i = j;  i < w;  i++)
			writec_stream(padchar, fmt_stream);
	} else {
		if (b[0] == '.') {
			*--b = '0';
			j++;
		}
		if (d < 0 && b[j-1] == '.') {
			b[j++] = '0';
			b[j] = '\0';
		}
	}
	if (sign < 0)
		writec_stream('-', fmt_stream);
	else if (atsign)
		writec_stream('+', fmt_stream);
	writestr_stream(b, fmt_stream);
	vs_reset;
	return;

OVER:
	fmt_set_param(0, &w, INT, 0);
	for (i = 0;  i < w;  i++)
		writec_stream(overflowchar, fmt_stream);
	vs_reset;
	return;
}

int
fmt_exponent_length(e)
{
	int i;

	if (e == 0)
		return(1);
	if (e < 0)
		e = -e;
	for (i = 0;  e > 0;  i++, e /= 10)
		;
	return(i);
}

fmt_exponent(e)
{
	if (e == 0) {
		writec_stream('0', fmt_stream);
		return;
	}
	if (e < 0)
		e = -e;
	fmt_exponent1(e);
}
	
fmt_exponent1(e)
{
	if (e == 0)
		return;
	fmt_exponent1(e/10);
	writec_stream('0' + e%10, fmt_stream);
}

fmt_exponential_float(colon, atsign)
{
	int w, d, e, k, overflowchar, padchar, exponentchar;
	double f;
	int sign;
	char buff[256], *b, buff1[256];
	int exp;
	int i, j;
	object x, y;
	int n, m;
	enum type t;
	vs_mark;

	b = buff1 + 1;

	fmt_not_colon(colon);
	fmt_max_param(7);
	fmt_set_param(0, &w, INT, 0);
	if (w < 0)
		fmt_error("illegal width");
	fmt_set_param(0, &w, INT, -1);
	fmt_set_param(1, &d, INT, 0);
	if (d < 0)
		fmt_error("illegal number of digits");
	fmt_set_param(1, &d, INT, -1);
	fmt_set_param(2, &e, INT, 0);
	if (e < 0)
		fmt_error("illegal number of digits in exponent");
	fmt_set_param(2, &e, INT, -1);
	fmt_set_param(3, &k, INT, 1);
	fmt_set_param(4, &overflowchar, CHAR, -1);
	fmt_set_param(5, &padchar, CHAR, ' ');
	fmt_set_param(6, &exponentchar, CHAR, -1);

	x = fmt_advance();
	if (type_of(x) == t_fixnum ||
	    type_of(x) == t_bignum ||
	    type_of(x) == t_ratio) {
		x = make_shortfloat((shortfloat)number_to_double(x));
		vs_push(x);
	}
	if (type_of(x) == t_complex) {
		if (w < 0)
			prin1(x, fmt_stream);
		else {
			fmt_nparam = 1;
			--fmt_index;
			fmt_decimal(colon, atsign);
		}
		vs_reset;
		return;
	}
	if (type_of(x) == t_longfloat)
		n = 16;
	else
		n = 7;
	f = number_to_double(x);
	edit_double(n, f, &sign, buff, &exp);
	if (d >= 0) {
		if (k > 0) {
			if (!(k < d + 2))
				fmt_error("illegal scale factor");
			m = d + 1;
		} else {
			if (!(k > -d))
				fmt_error("illegal scale factor");
			m = d + k;
		}
	} else if (w >= 0) {
		if (k > 0)
			m = w - 1;
		else
			m = w + k - 1;
		if (sign < 0 || atsign)
			--m;
		if (e >= 0)
			m -= e + 2;
		else
			m -= fmt_exponent_length(e - k + 1) + 2;
	} else
		m = n;
	if (m <= 0) {
		if (m == 0 && buff[0] >= '5') {
			exp++;
			n = m = 1;
			buff[0] = '1';
		} else
			n = m = 0;
	} else if (m < n) {
		n = m;
		edit_double(n, f, &sign, buff, &exp);
	}
	while (n >= 0)
		if (buff[n - 1] == '0')
			--n;
		else
			break;
	exp = exp - k + 1;
	j = 0;
	if (k > 0) {
		for (i = 0;  i < k;  i++)
			b[j++] = i < n ? buff[i] : '0';
		b[j++] = '.';
		if (d >= 0)
			for (m = i + (d - k + 1);  i < m;  i++)
				b[j++] = i < n ? buff[i] : '0';
		else
			for (;  i < n;  i++)
				b[j++] = buff[i];
	} else {
		b[j++] = '.';
		if (d >= 0) {
			for (i = 0;  i < -k && i < d;  i++)
				b[j++] = '0';
			for (m = d - i, i = 0;  i < m;  i++)
				b[j++] = i < n ? buff[i] : '0';
		} else if (n > 0) {
			for (i = 0;  i < -k;  i++)
				b[j++] = '0';
			for (i = 0;  i < n;  i++)
				b[j++] = buff[i];
		}
	}
	b[j] = '\0';
	if (w >= 0) {
		if (sign < 0 || atsign)
			--w;
		i = fmt_exponent_length(exp);
		if (e >= 0) {
			if (i > e) {
				if (overflowchar >= 0)
					goto OVER;
				else
					e = i;
			}
			w -= e + 2;
		} else
			w -= i + 2;
		if (j > w && overflowchar >= 0)
			goto OVER;
		if (j < w && b[j-1] == '.') {
			b[j++] = '0';
			b[j] = '\0';
		}
		if (j < w && b[0] == '.') {
			*--b = '0';
			j++;
		}
		for (i = j;  i < w;  i++)
			writec_stream(padchar, fmt_stream);
	} else {
		if (b[j-1] == '.') {
			b[j++] = '0';
			b[j] = '\0';
		}
		if (d < 0 && b[0] == '.') {
			*--b = '0';
			j++;
		}
	}
	if (sign < 0)
		writec_stream('-', fmt_stream);
	else if (atsign)
		writec_stream('+', fmt_stream);
	writestr_stream(b, fmt_stream);
	y = symbol_value(Vread_default_float_format);
	if (exponentchar < 0) {
		if (y == Slong_float || y == Sdouble_float)
			t = t_longfloat;
		else
			t = t_shortfloat;
		if (type_of(x) == t)
			exponentchar = 'E';
		else if (type_of(x) == t_shortfloat)
			exponentchar = 'S';
		else
			exponentchar = 'L';
	}
	writec_stream(exponentchar, fmt_stream);
	if (exp < 0)
		writec_stream('-', fmt_stream);
	else
		writec_stream('+', fmt_stream);
	if (e >= 0)
		for (i = e - fmt_exponent_length(exp);  i > 0;  --i)
			writec_stream('0', fmt_stream);
	fmt_exponent(exp);
	vs_reset;
	return;

OVER:
	fmt_set_param(0, &w, INT, -1);
	for (i = 0;  i < w;  i++)
		writec_stream(overflowchar, fmt_stream);
	vs_reset;
	return;
}

fmt_general_float(colon, atsign)
{
	int w, d, e, k, overflowchar, padchar, exponentchar;
	int sign, exp;
	char buff[256];
	object x;
	int n, ee, ww, q, dd;
	vs_mark;

	fmt_not_colon(colon);
	fmt_max_param(7);
	fmt_set_param(0, &w, INT, 0);
	if (w < 0)
		fmt_error("illegal width");
	fmt_set_param(0, &w, INT, -1);
	fmt_set_param(1, &d, INT, 0);
	if (d < 0)
		fmt_error("illegal number of digits");
	fmt_set_param(1, &d, INT, -1);
	fmt_set_param(2, &e, INT, 0);
	if (e < 0)
		fmt_error("illegal number of digits in exponent");
	fmt_set_param(2, &e, INT, -1);
	fmt_set_param(3, &k, INT, 1);
	fmt_set_param(4, &overflowchar, CHAR, -1);
	fmt_set_param(5, &padchar, CHAR, ' ');
	fmt_set_param(6, &exponentchar, CHAR, -1);

	x = fmt_advance();
	if (type_of(x) == t_complex) {
		if (w < 0)
			prin1(x, fmt_stream);
		else {
			fmt_nparam = 1;
			--fmt_index;
			fmt_decimal(colon, atsign);
		}
		vs_reset;
		return;
	}
	if (type_of(x) == t_longfloat)
		q = 16;
	else
		q = 7;
	edit_double(q, number_to_double(x), &sign, buff, &exp);
	n = exp + 1;
	while (q >= 0)
		if (buff[q - 1] == '0')
			--q;
		else
			break;
	if (e >= 0)
		ee = e + 2;
	else
		ee = 4;
	ww = w - ee;
	if (d < 0) {
		d = n < 7 ? n : 7;
		d = q > d ? q : d;
	}
	dd = d - n;
	if (0 <= dd && dd <= d) {
		fmt_nparam = 5;
		fmt_param[0].fmt_param_value = ww;
		fmt_param[1].fmt_param_value = dd;
		fmt_param[1].fmt_param_type = INT;
		fmt_param[2].fmt_param_type = NULL;
		fmt_param[3] = fmt_param[4];
		fmt_param[4] = fmt_param[5];
		--fmt_index;
		fmt_fix_float(colon, atsign);
		if (w >= 0)
			while (ww++ < w)
				writec_stream(padchar, fmt_stream);
		vs_reset;
		return;
	}
	fmt_param[1].fmt_param_value = d;
	fmt_param[1].fmt_param_type = INT;
	--fmt_index;
	fmt_exponential_float(colon, atsign);
	vs_reset;
}

fmt_dollars_float(colon, atsign)
{
	int d, n, w, padchar;
	double f;
	int sign;
	char buff[256];
	int exp;
	int q, i;
	object x;
	vs_mark;

	fmt_max_param(4);
	fmt_set_param(0, &d, INT, 2);
	if (d < 0)
		fmt_error("illegal number of digits");
	fmt_set_param(1, &n, INT, 1);
	if (n < 0)
		fmt_error("illegal number of digits");
	fmt_set_param(2, &w, INT, 0);
	if (w < 0)
		fmt_error("illegal width");
	fmt_set_param(3, &padchar, CHAR, ' ');
	x = fmt_advance();
	if (type_of(x) == t_complex) {
		if (w < 0)
			prin1(x, fmt_stream);
		else {
			fmt_nparam = 1;
			fmt_param[0] = fmt_param[2];
			--fmt_index;
			fmt_decimal(colon, atsign);
		}
		vs_reset;
		return;
	}
	q = 7;
	if (type_of(x) == t_longfloat)
		q = 16;
	f = number_to_double(x);
	edit_double(q, f, &sign, buff, &exp);
	if ((q = exp + d + 1) > 0)
		edit_double(q, f, &sign, buff, &exp);
	exp++;
	if (w > 100 || exp > 100 || exp < -100) {
		fmt_nparam = 6;
		fmt_param[0] = fmt_param[2];
		fmt_param[1].fmt_param_value = d + n - 1;
		fmt_param[1].fmt_param_type = INT;
		fmt_param[2].fmt_param_type =
		fmt_param[3].fmt_param_type =
		fmt_param[4].fmt_param_type = NULL;
		fmt_param[5] = fmt_param[3];
		--fmt_index;
		fmt_exponential_float(colon, atsign);
	}
	if (exp > n)
		n = exp;
	if (sign < 0 || atsign)
		--w;
	if (colon) {
		if (sign < 0)
			writec_stream('-', fmt_stream);
		else if (atsign)
			writec_stream('+', fmt_stream);
		while (--w > n + d)
			writec_stream(padchar, fmt_stream);
	} else {
		while (--w > n + d)
			writec_stream(padchar, fmt_stream);
		if (sign < 0)
			writec_stream('-', fmt_stream);
		else if (atsign)
			writec_stream('+', fmt_stream);
	}
	for (i = n - exp;  i > 0;  --i)
		writec_stream('0', fmt_stream);
	for (i = 0;  i < exp;  i++)
		writec_stream((i < q ? buff[i] : '0'), fmt_stream);
	writec_stream('.', fmt_stream);
	for (d += i;  i < d;  i++)
		writec_stream((i < q ? buff[i] : '0'), fmt_stream);
	vs_reset;
}

fmt_percent(colon, atsign)
{
	int n, i;

	fmt_max_param(1);
	fmt_set_param(0, &n, INT, 1);
	fmt_not_colon(colon);
	fmt_not_atsign(atsign);
	while (n-- > 0) {
                WRITEC_NEWLINE(fmt_stream);
		if (n == 0)
			for (i = fmt_indents;  i > 0;  --i)
				writec_stream(' ', fmt_stream);
	}
}

fmt_ampersand(colon, atsign)
{
	int n;

	fmt_max_param(1);
	fmt_set_param(0, &n, INT, 1);
	fmt_not_colon(colon);
	fmt_not_atsign(atsign);
	if (n == 0)
		return;
	if (file_column(fmt_stream) != 0)
	  WRITEC_NEWLINE(fmt_stream);
	while (--n > 0)
	  	  WRITEC_NEWLINE(fmt_stream);
	fmt_indents = 0;
}

fmt_bar(colon, atsign)
{
	int n;

	fmt_max_param(1);
	fmt_set_param(0, &n, INT, 1);
	fmt_not_colon(colon);
	fmt_not_atsign(atsign);
	while (n-- > 0)
		writec_stream('\f', fmt_stream);
}

fmt_tilde(colon, atsign)
{
	int n;

	fmt_max_param(1);
	fmt_set_param(0, &n, INT, 1);
	fmt_not_colon(colon);
	fmt_not_atsign(atsign);
	while (n-- > 0)
		writec_stream('~', fmt_stream);
}

fmt_newline(colon, atsign)
{
	int c;

	fmt_max_param(0);
	fmt_not_colon_atsign(colon, atsign);
	if (atsign)
	  WRITEC_NEWLINE(fmt_stream);
	while (ctl_index < ctl_end && isspace(ctl_string[ctl_index])) {
		if (colon)
			writec_stream(ctl_string[ctl_index], fmt_stream);
		ctl_index++;
	}
}

fmt_tabulate(colon, atsign)
{
	int colnum, colinc;
	int c, i;
	
	fmt_max_param(2);
	fmt_not_colon(colon);
	fmt_set_param(0, &colnum, INT, 1);
	fmt_set_param(1, &colinc, INT, 1);
	if (!atsign) {
		c = file_column(fmt_stream);
		if (c < 0) {
			writestr_stream("  ", fmt_stream);
			return;
		}
		if (c > colnum && colinc <= 0)
			return;
		while (c > colnum)
			colnum += colinc;
		for (i = colnum - c;  i > 0;  --i)
			writec_stream(' ', fmt_stream);
	} else {
		for (i = colnum;  i > 0;  --i)
			writec_stream(' ', fmt_stream);
		c = file_column(fmt_stream);
		if (c < 0 || colinc <= 0)
			return;
		colnum = 0;
		while (c > colnum)
			colnum += colinc;
		for (i = colnum - c;  i > 0;  --i)
			writec_stream(' ', fmt_stream);
	}
}

fmt_asterisk(colon, atsign)
{
	int n;

	fmt_max_param(1);
	fmt_not_colon_atsign(colon, atsign);
	if (atsign) {
		fmt_set_param(0, &n, INT, 0);
		if (n < 0 || n >= fmt_end)
			fmt_error("can't goto");
		fmt_index = n;
	} else if (colon) {
		fmt_set_param(0, &n, INT, 1);
		if (n > fmt_index)
			fmt_error("can't back up");
		fmt_index -= n;
	} else {
		fmt_set_param(0, &n, INT, 1);
		while (n-- > 0)
			fmt_advance();
	}
}	

fmt_indirection(colon, atsign)
{
	object s, l;
	fmt_old;
	jmp_buf fmt_jmp_buf0;
	int up_colon;

	fmt_max_param(0);
	fmt_not_colon(colon);
	s = fmt_advance();
	if (type_of(s) != t_string)
		fmt_error("control string expected");
	if (atsign) {
		fmt_save;
		fmt_jmp_buf = fmt_jmp_buf0;
		fmt_string = s;
		if (up_colon = setjmp(fmt_jmp_buf)) {
			if (--up_colon)
				fmt_error("illegal ~:^");
		} else
			format(fmt_stream, 0, s->st.st_fillp);
		fmt_restore1;
	} else {
		l = fmt_advance();
		fmt_save;
		fmt_base = vs_top;
		fmt_index = 0;
		for (fmt_end = 0;  !endp(l);  fmt_end++, l = l->c.c_cdr)
			vs_check_push(l->c.c_car);
		fmt_jmp_buf = fmt_jmp_buf0;
		fmt_string = s;
		if (up_colon = setjmp(fmt_jmp_buf)) {
			if (--up_colon)
				fmt_error("illegal ~:^");
		} else
			format(fmt_stream, 0, s->st.st_fillp);
		vs_top = fmt_base;
		fmt_restore;
	}
}

fmt_case(colon, atsign)
{
	VOL object x;
	VOL int i, j;
	fmt_old;
	jmp_buf fmt_jmp_buf0;
	int up_colon;
	bool b;

	x = make_string_output_stream(64);
	vs_push(x);
	i = ctl_index;
	j = fmt_skip();
	if (ctl_string[--j] != ')' || ctl_string[--j] != '~')
		fmt_error("~) expected");
	fmt_save;
	fmt_jmp_buf = fmt_jmp_buf0;
	if (up_colon = setjmp(fmt_jmp_buf))
		;
	else
		format(x, ctl_origin + i, j - i);
	fmt_restore1;
	x = x->sm.sm_object0;
	if (!colon && !atsign)
		for (i = 0;  i < x->st.st_fillp;  i++) {
			if (isUpper(j = x->st.st_self[i]))
				j += 'a' - 'A';
			writec_stream(j, fmt_stream);
		}
	else if (colon && !atsign)
		for (b = TRUE, i = 0;  i < x->st.st_fillp;  i++) {
			if (isLower(j = x->st.st_self[i])) {
				if (b)
					j -= 'a' - 'A';
				b = FALSE;
			} else if (isUpper(j)) {
				if (!b)
					j += 'a' - 'A';
				b = FALSE;
			} else if (!isDigit(j))
				b = TRUE;
			writec_stream(j, fmt_stream);
		}
	else if (!colon && atsign)
		for (b = TRUE, i = 0;  i < x->st.st_fillp;  i++) {
			if (isLower(j = x->st.st_self[i])) {
				if (b)
					j -= 'a' - 'A';
				b = FALSE;
			} else if (isUpper(j)) {
				if (!b)
					j += 'a' - 'A';
				b = FALSE;
			}
			writec_stream(j, fmt_stream);
		}
	else
		for (i = 0;  i < x->st.st_fillp;  i++) {
			if (isLower(j = x->st.st_self[i]))
				j -= 'a' - 'A';
			writec_stream(j, fmt_stream);
		}
	vs_pop;
	if (up_colon)
		longjmp(fmt_jmp_buf, up_colon);
}

fmt_conditional(colon, atsign)
{
	int i, j, k;
	object x;
	int n;
	bool done;
	fmt_old;

	fmt_not_colon_atsign(colon, atsign);
	if (colon) {
		fmt_max_param(0);
		i = ctl_index;
		j = fmt_skip();
		if (ctl_string[--j] != ';' || ctl_string[--j] != '~')
			fmt_error("~; expected");
		k = fmt_skip();
		if (ctl_string[--k] != ']' || ctl_string[--k] != '~')
			fmt_error("~] expected");
		if (fmt_advance() == Cnil) {
			fmt_save;
			format(fmt_stream, ctl_origin + i, j - i);
			fmt_restore1;
		} else {
			fmt_save;
			format(fmt_stream, ctl_origin + j + 2, k - (j + 2));
			fmt_restore1;
		}
	} else if (atsign) {
		i = ctl_index;
		j = fmt_skip();
		if (ctl_string[--j] != ']' || ctl_string[--j] != '~')
			fmt_error("~] expected");
		if (fmt_advance() == Cnil)
			;
		else {
			--fmt_index;
			fmt_save;
			format(fmt_stream, ctl_origin + i, j - i);
			fmt_restore1;
		}
	} else {
		fmt_max_param(1);
		if (fmt_nparam == 0) {
			x = fmt_advance();
			if (type_of(x) != t_fixnum)
				fmt_error("illegal argument for conditional");
			n = fix(x);
		} else
			fmt_set_param(0, &n, INT, 0);
		i = ctl_index;
		for (done = FALSE;;  --n) {
			j = fmt_skip();
			for (k = j;  ctl_string[--k] != '~';)
				;
			if (n == 0) {
				fmt_save;
				format(fmt_stream, ctl_origin + i, k - i);
				fmt_restore1;
				done = TRUE;
			}
			i = j;
			if (ctl_string[--j] == ']') {
				if (ctl_string[--j] != '~')
					fmt_error("~] expected");
				return;
			}
			if (ctl_string[j] == ';') {
				if (ctl_string[--j] == '~')
					continue;
				if (ctl_string[j] == ':')
					goto ELSE;
			}
			fmt_error("~; or ~] expected");
		}
	ELSE:
		if (ctl_string[--j] != '~')
			fmt_error("~:; expected");
		j = fmt_skip();
		if (ctl_string[--j] != ']' || ctl_string[--j] != '~')
			fmt_error("~] expected");
		if (!done) {
			fmt_save;
			format(fmt_stream, ctl_origin + i, j - i);
			fmt_restore1;
		}
	}
}	

fmt_iteration(colon, atsign)
{
	int i,n;
	VOL int j;
	int o;
	bool colon_close = FALSE;
	object l;
	VOL object l0;
	fmt_old;
	jmp_buf fmt_jmp_buf0;
	int up_colon;

	fmt_max_param(1);
	fmt_set_param(0, &n, INT, 1000000);
	i = ctl_index;
	j = fmt_skip();
	if (ctl_string[--j] != '}')
		fmt_error("~} expected");
	if (ctl_string[--j] == ':') {
		colon_close = TRUE;
		--j;
	}
	if (ctl_string[j] != '~')
		fmt_error("syntax error");
	o = ctl_origin;
	if (!colon && !atsign) {
		l = fmt_advance();
		fmt_save;
		fmt_base = vs_top;
		fmt_index = 0;
		for (fmt_end = 0;  !endp(l);  fmt_end++, l = l->c.c_cdr)
			vs_check_push(l->c.c_car);
		fmt_jmp_buf = fmt_jmp_buf0;
		if (colon_close)
			goto L1;
		while (fmt_index < fmt_end) {
		L1:
			if (n-- <= 0)
				break;
			if (up_colon = setjmp(fmt_jmp_buf)) {
				if (--up_colon)
					fmt_error("illegal ~:^");
				break;
			}
			format(fmt_stream, o + i, j - i);
		}
		vs_top = fmt_base;
		fmt_restore;
	} else if (colon && !atsign) {
		l0 = fmt_advance();
		fmt_save;
		fmt_base = vs_top;
		fmt_jmp_buf = fmt_jmp_buf0;
		if (colon_close)
			goto L2;
		while (!endp(l0)) {
		L2:
			if (n-- <= 0)
				break;
			l = l0->c.c_car;
			l0 = l0->c.c_cdr;
			fmt_index = 0;
			for (fmt_end = 0; !endp(l); fmt_end++, l = l->c.c_cdr)
				vs_check_push(l->c.c_car);
			if (up_colon = setjmp(fmt_jmp_buf)) {
				vs_top = fmt_base;
				if (--up_colon)
					break;
				else
					continue;
			}
			format(fmt_stream, o + i, j - i);
			vs_top = fmt_base;
		}
		fmt_restore;
	} else if (!colon && atsign) {
		fmt_save;
		fmt_jmp_buf = fmt_jmp_buf0;
		if (colon_close)
			goto L3;
		while (fmt_index < fmt_end) {
		L3:
			if (n-- <= 0)
				break;
			if (up_colon = setjmp(fmt_jmp_buf)) {
				if (--up_colon)
					fmt_error("illegal ~:^");
				break;
			}
			format(fmt_stream, o + i, j - i);
		}
		fmt_restore1;
	} else if (colon && atsign) {
		if (colon_close)
			goto L4;
		while (fmt_index < fmt_end) {
		L4:
			if (n-- <= 0)
				break;
			l = fmt_advance();
			fmt_save;
			fmt_base = vs_top;
			fmt_index = 0;
			for (fmt_end = 0; !endp(l); fmt_end++, l = l->c.c_cdr)
				vs_check_push(l->c.c_car);
			fmt_jmp_buf = fmt_jmp_buf0;
			if (up_colon = setjmp(fmt_jmp_buf)) {
				vs_top = fmt_base;
				fmt_restore;
				if (--up_colon)
					break;
				else
					continue;
			}
			format(fmt_stream, o + i, j - i);
			vs_top = fmt_base;
			fmt_restore;
		}
	}
}

#define FORMAT_DIRECTIVE_LIMIT 100

fmt_justification(colon, atsign)
{
	int mincol, colinc, minpad, padchar;
	object fields[FORMAT_DIRECTIVE_LIMIT];
	fmt_old;
	jmp_buf fmt_jmp_buf0;
	VOL int i,j,n,j0;
	int k,l,m,l0;
	int up_colon;
	VOL int special = 0;
	int spare_spaces, line_length;
	vs_mark;

	fmt_max_param(4);
	fmt_set_param(0, &mincol, INT, 0);
	fmt_set_param(1, &colinc, INT, 1);
	fmt_set_param(2, &minpad, INT, 0);
	fmt_set_param(3, &padchar, CHAR, ' ');

	n = 0;
	for (;;) {
		if (n >= FORMAT_DIRECTIVE_LIMIT)
			fmt_error("too many fields");
		i = ctl_index;
		j0 = j = fmt_skip();
		while (ctl_string[--j] != '~')
			;
		fields[n] = make_string_output_stream(64);
		vs_push(fields[n]);
		fmt_save;
		fmt_jmp_buf = fmt_jmp_buf0;
		if (up_colon = setjmp(fmt_jmp_buf)) {
			--n;
			if (--up_colon)
				fmt_error("illegal ~:^");
			fmt_restore1;
			while (ctl_string[--j0] != '>')
				j0 = fmt_skip();
			if (ctl_string[--j0] != '~')
				fmt_error("~> expected");
			break;
		}
		format(fields[n++], ctl_origin + i, j - i);
		fmt_restore1;
		if (ctl_string[--j0] == '>') {
			if (ctl_string[--j0] != '~')
				fmt_error("~> expected");
			break;
		} else if (ctl_string[j0] != ';')
			fmt_error("~; expected");
		else if (ctl_string[--j0] == ':') {
			if (n != 1)
				fmt_error("illegal ~:;");
			special = 1;
			for (j = j0;  ctl_string[j] != '~';  --j)
				;
			fmt_save;
			format(fmt_stream, ctl_origin + j, j0 - j + 2);
			fmt_restore1;
			spare_spaces = fmt_spare_spaces;
			line_length = fmt_line_length;
		} else if (ctl_string[j0] != '~')
			fmt_error("~; expected");
	}
	for (i = special, l = 0;  i < n;  i++)
		l += fields[i]->sm.sm_object0->st.st_fillp;
	m = n - 1 - special;
	if (m <= 0 && !colon && !atsign) {
		m = 0;
		colon = TRUE;
	}
	if (colon)
		m++;
	if (atsign)
		m++;
	l0 = l;
	l += minpad * m;
	for (k = 0;  mincol + k * colinc < l;  k++)
		;
	l = mincol + k * colinc;
	if (special != 0 &&
	    file_column(fmt_stream) + l + spare_spaces >= line_length)
		princ(fields[0]->sm.sm_object0, fmt_stream);
	l -= l0;
	for (i = special;  i < n;  i++) {
		if (m > 0 && (i > 0 || colon))
			for (j = l / m, l -= j, --m;  j > 0;  --j)
				writec_stream(padchar, fmt_stream);
		princ(fields[i]->sm.sm_object0, fmt_stream);
	}
	if (atsign)
		for (j = l;  j > 0;  --j)
			writec_stream(padchar, fmt_stream);
	vs_reset;
}


fmt_up_and_out(colon, atsign)
{
	int i, j, k;

	fmt_max_param(3);
	fmt_not_atsign(atsign);
	if (fmt_nparam == 0) {
		if (fmt_index >= fmt_end)
			longjmp(fmt_jmp_buf, ++colon);
	} else if (fmt_nparam == 1) {
		fmt_set_param(0, &i, INT, 0);
		if (i == 0)
			longjmp(fmt_jmp_buf, ++colon);
	} else if (fmt_nparam == 2) {
		fmt_set_param(0, &i, INT, 0);
		fmt_set_param(1, &j, INT, 0);
		if (i == j)
			longjmp(fmt_jmp_buf, ++colon);
	} else {
		fmt_set_param(0, &i, INT, 0);
		fmt_set_param(1, &j, INT, 0);
		fmt_set_param(2, &k, INT, 0);
		if (i <= j && j <= k)
			longjmp(fmt_jmp_buf, ++colon);
	}
}


fmt_semicolon(colon, atsign)
{
	fmt_not_atsign(atsign);
	if (!colon)
		fmt_error("~:; expected");
	fmt_max_param(2);
	fmt_set_param(0, &fmt_spare_spaces, INT, 0);
	fmt_set_param(1, &fmt_line_length, INT, 72);
}


object 
LVformat(strm, control, va_alist)
     object strm;
     object control;
     va_dcl
{       va_list ap; 
        VOL int nargs= VFUN_NARGS;
	VOL object x = OBJNULL;
	jmp_buf fmt_jmp_buf0;
	bool colon, e;
	fmt_old;
	nargs=nargs-2;
	if (nargs < 0)
		too_few_arguments();
	if (strm == Cnil) {
		strm = make_string_output_stream(64);
		x = strm->sm.sm_object0;
	} else if (strm == Ct)
		strm = symbol_value(Vstandard_output);
	else if (type_of(strm) == t_string) {
		x = strm;
		if (!x->st.st_hasfillp)
		  FEerror("The string ~S doesn't have a fill-pointer.", 1, x);
		strm = make_string_output_stream(0);
		strm->sm.sm_object0 = x;
	} else
		check_type_stream(&strm);
	check_type_string(&control);
	fmt_save;
	frs_push(FRS_PROTECT, Cnil);
	if (nlj_active) {
		e = TRUE;
		goto L;
	}
	
	va_start(ap);
	{object *l;
	 COERCE_VA_LIST(l,ap,nargs);
	fmt_base = l;
	fmt_index = 0;
	fmt_end = nargs;
	fmt_jmp_buf = fmt_jmp_buf0;
	if (symbol_value(siVindent_formatted_output) != Cnil)
		fmt_indents = file_column(strm);
	else
		fmt_indents = 0;
	fmt_string = control;
	if (colon = setjmp(fmt_jmp_buf)) {
		if (--colon)
			fmt_error("illegal ~:^");
		vs_base = vs_top;
		if (x != OBJNULL)
			vs_push(x);
		else
			vs_push(Cnil);
		e = FALSE;
		goto L;
	}
	format(strm, 0, control->st.st_fillp);
	flush_stream(strm);
       }
	va_end(ap);
	e = FALSE;
L:
	frs_pop();
	fmt_restore;
	if (e) {
		nlj_active = FALSE;
		unwind(nlj_fr, nlj_tag);
	}
	return (x ==0 ? Cnil : x);  
}

object c_apply_n();

void
Lformat()
{object *b=vs_base;
 VFUN_NARGS = vs_top-vs_base;
 b[0]= c_apply_n(LVformat,vs_top-vs_base,vs_base);
 vs_top=((vs_base=b)+1);
}

fmt_error(s)
{
	vs_push(make_simple_string(s));
	vs_push(make_fixnum(&ctl_string[ctl_index] - fmt_string->st.st_self));
	FEerror("Format error: ~A.~%~V@TV~%\"~A\"~%",
		3, vs_top[-2], vs_top[-1], fmt_string);
}

init_format()
{
	fmt_temporary_stream = make_string_output_stream(64);
	enter_mark_origin(&fmt_temporary_stream);
	fmt_temporary_string = fmt_temporary_stream->sm.sm_object0;

	make_function("FORMAT", Lformat);

	siVindent_formatted_output
	= make_si_special("*INDENT-FORMATTED-OUTPUT*", Cnil);
}
