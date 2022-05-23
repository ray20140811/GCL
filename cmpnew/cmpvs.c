
#include <cmpinclude.h>
#include "cmpvs.h"
init_cmpvs(){do_init(VV);}
/*	local entry for function VS-PUSH	*/

static object LI1()

{	 VMB1 VMS1 VMV1
TTL:;
	{object V1;
	V1= make_cons(symbol_value(VV[0]),symbol_value(VV[1]));
	setq(VV[1],number_plus(symbol_value(VV[1]),small_fixnum(1)));
	setq(VV[2],(number_compare(symbol_value(VV[1]),symbol_value(VV[2]))>=0?(symbol_value(VV[1])):symbol_value(VV[2])));
	{object V2 = (V1);
	VMR1(V2)}}
}
/*	local entry for function SET-VS	*/

static object LI2(V5,V6)

register object V5;object V6;
{	 VMB2 VMS2 VMV2
TTL:;
	if(!(type_of((V5))==t_cons)){
	goto T6;}
	if(!((car((V5)))==(VV[3]))){
	goto T6;}
	if(equal(cadr((V5)),(V6))){
	goto T7;}
T6:;
	princ_str("\n	",VV[4]);
	(void)((*(LnkLI11))((V6)));
	princ_str("= ",VV[4]);
	(void)((*(LnkLI12))((V5)));
	princ_char(59,VV[4]);
	{object V7 = Cnil;
	VMR2(V7)}
T7:;
	{object V8 = Cnil;
	VMR2(V8)}
}
/*	local entry for function WT-VS	*/

static object LI3(V10)

register object V10;
{	 VMB3 VMS3 VMV3
TTL:;
	if(!((car((V10)))==(VV[5]))){
	goto T19;}
	princ_char(86,VV[4]);
	(void)((*(LnkLI12))(cadr((V10))));
	{object V11 = Cnil;
	VMR3(V11)}
T19:;
	if(!((car((V10)))==(VV[6]))){
	goto T24;}
	princ_str("Vcs[",VV[4]);
	(void)((*(LnkLI12))(cdr((V10))));
	princ_char(93,VV[4]);
	{object V12 = Cnil;
	VMR3(V12)}
T24:;
	if(!(number_compare(car((V10)),symbol_value(VV[0]))==0)){
	goto T30;}
	princ_str("base[",VV[4]);
	(void)((*(LnkLI12))(cdr((V10))));
	princ_char(93,VV[4]);
	{object V13 = Cnil;
	VMR3(V13)}
T30:;
	princ_str("base",VV[4]);
	(void)((*(LnkLI12))(car((V10))));
	princ_char(91,VV[4]);
	(void)((*(LnkLI12))(cdr((V10))));
	princ_char(93,VV[4]);
	{object V14 = Cnil;
	VMR3(V14)}
}
/*	local entry for function WT-VS*	*/

static object LI4(V16)

object V16;
{	 VMB4 VMS4 VMV4
TTL:;
	princ_char(40,VV[4]);
	(void)((*(LnkLI11))((V16)));
	princ_str("->c.c_car)",VV[4]);
	{object V17 = Cnil;
	VMR4(V17)}
}
/*	local entry for function WT-CCB-VS	*/

static object LI5(V19)

object V19;
{	 VMB5 VMS5 VMV5
TTL:;
	princ_str("(base0[",VV[4]);
	V20= number_minus(symbol_value(VV[7]),(V19));
	(void)((*(LnkLI12))(/* INLINE-ARGS */V20));
	princ_str("]->c.c_car)",VV[4]);
	{object V21 = Cnil;
	VMR5(V21)}
}
/*	local entry for function CLINK	*/

static object LI6(V23)

object V23;
{	 VMB6 VMS6 VMV6
TTL:;
	setq(VV[8],(V23));
	{object V24 = symbol_value(VV[8]);
	VMR6(V24)}
}
/*	local entry for function WT-CLINK	*/

static object LI7(va_alist)
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB7 VMS7 VMV7
	{object V25;
	narg = narg - 0;
	if (narg <= 0) goto T48;
	else {
	va_start(ap);
	V25= va_arg(ap,object);}
	--narg; goto T49;
T48:;
	V25= symbol_value(VV[8]);
T49:;
	if(((V25))!=Cnil){
	goto T52;}
	princ_str("Cnil",VV[4]);
	{object V26 = Cnil;
	VMR7(V26)}
T52:;
	{object V27 = (*(LnkLI11))((V25));
	VMR7(V27)}}
	}
/*	local entry for function CCB-VS-PUSH	*/

static object LI8()

{	 VMB8 VMS8 VMV8
TTL:;
	setq(VV[9],number_plus(symbol_value(VV[9]),small_fixnum(1)));
	{object V28 = symbol_value(VV[9]);
	VMR8(V28)}
}
/*	local entry for function CVS-PUSH	*/

static object LI9()

{	 VMB9 VMS9 VMV9
TTL:;
	{object V29;
	V29= make_cons(VV[6],symbol_value(VV[10]));
	setq(VV[10],number_plus(symbol_value(VV[10]),small_fixnum(1)));
	{object V30 = (V29);
	VMR9(V30)}}
}
/*	local entry for function WT-LIST	*/

static object LI10(V32)

object V32;
{	 VMB10 VMS10 VMV10
TTL:;
	{register object V33;
	V33= (V32);
T60:;
	if(((V33))!=Cnil){
	goto T61;}
	{object V34 = Cnil;
	VMR10(V34)}
T61:;
	(void)((*(LnkLI12))(car((V33))));
	if(!((cdr((V33)))==Cnil)){
	goto T68;}
	goto T67;
T68:;
	princ_char(44,VV[4]);
T67:;
	V33= cdr((V33));
	goto T60;}
}
static object  LnkTLI12(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[12],&LnkLI12,1,ap);} /* WT1 */
static object  LnkTLI11(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[11],&LnkLI11,1,ap);} /* WT-VS */
