
#include <cmpinclude.h>
#include "numlib.h"
init_numlib(){do_init(VV);}
/*	local entry for function ISQRT	*/

static object LI1(V2)

register object V2;
{	 VMB1 VMS1 VMV1
TTL:;
	if(!(type_of((V2))==t_fixnum||type_of((V2))==t_bignum)){
	goto T2;}
	if(number_compare((V2),small_fixnum(0))>=0){
	goto T1;}
T2:;
	base[0]= VV[0];
	base[1]= (V2);
	vs_top=(vs_base=base+0)+2;
	Lerror();
	vs_top=sup;
T1:;
	if(!(number_compare(small_fixnum(0),(V2))==0)){
	goto T9;}
	{object V3 = small_fixnum(0);
	VMR1(V3)}
T9:;
	{object V4;
	base[0]= (V2);
	vs_top=(vs_base=base+0)+1;
	Linteger_length();
	vs_top=sup;
	V4= vs_base[0];
	{register object V5;
	register object V6;
	base[0]= small_fixnum(1);
	base[2]= (V4);
	base[3]= small_fixnum(2);
	vs_top=(vs_base=base+2)+2;
	Lceiling();
	vs_top=sup;
	base[1]= vs_base[0];
	vs_top=(vs_base=base+0)+2;
	Lash();
	vs_top=sup;
	V5= vs_base[0];
	V6= Cnil;
T19:;
	base[0]= (V2);
	base[1]= (V5);
	vs_top=(vs_base=base+0)+2;
	Lfloor();
	vs_top=sup;
	V6= vs_base[0];
	if(!(number_compare((V5),(V6))<=0)){
	goto T26;}
	{object V7 = (V5);
	VMR1(V7)}
T26:;
	base[0]= number_plus((V5),(V6));
	base[1]= small_fixnum(2);
	vs_top=(vs_base=base+0)+2;
	Lfloor();
	vs_top=sup;
	V5= vs_base[0];
	goto T19;}}
}
/*	local entry for function ABS	*/

static object LI2(V9)

register object V9;
{	 VMB2 VMS2 VMV2
TTL:;
	base[0]= (V9);
	vs_top=(vs_base=base+0)+1;
	Lcomplexp();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T36;}
	base[1]= (V9);
	vs_top=(vs_base=base+1)+1;
	Lrealpart();
	vs_top=sup;
	V10= vs_base[0];
	base[1]= (V9);
	vs_top=(vs_base=base+1)+1;
	Lrealpart();
	vs_top=sup;
	V11= vs_base[0];
	V12= number_times(V10,V11);
	base[1]= (V9);
	vs_top=(vs_base=base+1)+1;
	Limagpart();
	vs_top=sup;
	V13= vs_base[0];
	base[1]= (V9);
	vs_top=(vs_base=base+1)+1;
	Limagpart();
	vs_top=sup;
	V14= vs_base[0];
	V15= number_times(V13,V14);
	base[0]= number_plus(/* INLINE-ARGS */V12,/* INLINE-ARGS */V15);
	vs_top=(vs_base=base+0)+1;
	Lsqrt();
	vs_top=sup;
	{object V16 = vs_base[0];
	VMR2(V16)}
T36:;
	if(!(number_compare(small_fixnum(0),(V9))>0)){
	goto T49;}
	{object V17 = number_negate((V9));
	VMR2(V17)}
T49:;
	{object V18 = (V9);
	VMR2(V18)}
}
/*	local entry for function PHASE	*/

static object LI3(V20)

object V20;
{	 VMB3 VMS3 VMV3
TTL:;
	base[1]= (V20);
	vs_top=(vs_base=base+1)+1;
	Limagpart();
	vs_top=sup;
	base[0]= vs_base[0];
	base[2]= (V20);
	vs_top=(vs_base=base+2)+1;
	Lrealpart();
	vs_top=sup;
	base[1]= vs_base[0];
	vs_top=(vs_base=base+0)+2;
	Latan();
	vs_top=sup;
	{object V21 = vs_base[0];
	VMR3(V21)}
}
/*	local entry for function SIGNUM	*/

static object LI4(V23)

register object V23;
{	 VMB4 VMS4 VMV4
TTL:;
	if(!(number_compare(small_fixnum(0),(V23))==0)){
	goto T56;}
	{object V24 = (V23);
	VMR4(V24)}
T56:;
	base[0]= (V23);
	base[1]= (*(LnkLI9))((V23));
	vs_top=(vs_base=base+0)+2;
	Ldivide();
	vs_top=sup;
	{object V25 = vs_base[0];
	VMR4(V25)}
}
/*	local entry for function CIS	*/

static object LI5(V27)

object V27;
{	 VMB5 VMS5 VMV5
TTL:;
	base[0]= number_times(VV[1],(V27));
	vs_top=(vs_base=base+0)+1;
	Lexp();
	vs_top=sup;
	{object V28 = vs_base[0];
	VMR5(V28)}
}
/*	local entry for function ASIN	*/

static object LI6(V30)

register object V30;
{	 VMB6 VMS6 VMV6
TTL:;
	{object V31;
	V33= number_times(VV[1],(V30));
	V35= number_times((V30),(V30));
	base[1]= number_minus(VV[2],/* INLINE-ARGS */V35);
	vs_top=(vs_base=base+1)+1;
	Lsqrt();
	vs_top=sup;
	V34= vs_base[0];
	base[0]= number_plus(/* INLINE-ARGS */V33,V34);
	vs_top=(vs_base=base+0)+1;
	Llog();
	vs_top=sup;
	V32= vs_base[0];
	V36= number_times(VV[1],V32);
	V31= number_negate(/* INLINE-ARGS */V36);
	base[0]= (V30);
	vs_top=(vs_base=base+0)+1;
	Lcomplexp();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T68;}
	if(!(number_compare((V30),VV[2])<=0)){
	goto T68;}
	if(number_compare((V30),VV[3])>=0){
	goto T66;}
T68:;
	base[0]= (V31);
	vs_top=(vs_base=base+0)+1;
	Limagpart();
	vs_top=sup;
	V37= vs_base[0];
	if(!(number_compare(small_fixnum(0),V37)==0)){
	goto T67;}
T66:;
	base[0]= (V31);
	vs_top=(vs_base=base+0)+1;
	Lrealpart();
	vs_top=sup;
	{object V38 = vs_base[0];
	VMR6(V38)}
T67:;
	{object V39 = (V31);
	VMR6(V39)}}
}
/*	local entry for function ACOS	*/

static object LI7(V41)

register object V41;
{	 VMB7 VMS7 VMV7
TTL:;
	{object V42;
	V45= number_times((V41),(V41));
	base[1]= number_minus(VV[2],/* INLINE-ARGS */V45);
	vs_top=(vs_base=base+1)+1;
	Lsqrt();
	vs_top=sup;
	V44= vs_base[0];
	V46= number_times(VV[1],V44);
	base[0]= number_plus((V41),/* INLINE-ARGS */V46);
	vs_top=(vs_base=base+0)+1;
	Llog();
	vs_top=sup;
	V43= vs_base[0];
	V47= number_times(VV[1],V43);
	V42= number_negate(/* INLINE-ARGS */V47);
	base[0]= (V41);
	vs_top=(vs_base=base+0)+1;
	Lcomplexp();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T86;}
	if(!(number_compare((V41),VV[2])<=0)){
	goto T86;}
	if(number_compare((V41),VV[3])>=0){
	goto T84;}
T86:;
	base[0]= (V42);
	vs_top=(vs_base=base+0)+1;
	Limagpart();
	vs_top=sup;
	V48= vs_base[0];
	if(!(number_compare(small_fixnum(0),V48)==0)){
	goto T85;}
T84:;
	base[0]= (V42);
	vs_top=(vs_base=base+0)+1;
	Lrealpart();
	vs_top=sup;
	{object V49 = vs_base[0];
	VMR7(V49)}
T85:;
	{object V50 = (V42);
	VMR7(V50)}}
}
/*	local entry for function SINH	*/

static object LI8(V52)

object V52;
{	 VMB8 VMS8 VMV8
TTL:;
	base[1]= (V52);
	vs_top=(vs_base=base+1)+1;
	Lexp();
	vs_top=sup;
	V53= vs_base[0];
	base[1]= number_negate((V52));
	vs_top=(vs_base=base+1)+1;
	Lexp();
	vs_top=sup;
	V54= vs_base[0];
	base[0]= number_minus(V53,V54);
	base[1]= VV[4];
	vs_top=(vs_base=base+0)+2;
	Ldivide();
	vs_top=sup;
	{object V55 = vs_base[0];
	VMR8(V55)}
}
/*	local entry for function COSH	*/

static object LI9(V57)

object V57;
{	 VMB9 VMS9 VMV9
TTL:;
	base[1]= (V57);
	vs_top=(vs_base=base+1)+1;
	Lexp();
	vs_top=sup;
	V58= vs_base[0];
	base[1]= number_negate((V57));
	vs_top=(vs_base=base+1)+1;
	Lexp();
	vs_top=sup;
	V59= vs_base[0];
	base[0]= number_plus(V58,V59);
	base[1]= VV[4];
	vs_top=(vs_base=base+0)+2;
	Ldivide();
	vs_top=sup;
	{object V60 = vs_base[0];
	VMR9(V60)}
}
/*	local entry for function TANH	*/

static object LI10(V62)

object V62;
{	 VMB10 VMS10 VMV10
TTL:;
	base[0]= (*(LnkLI10))((V62));
	base[1]= (*(LnkLI11))((V62));
	vs_top=(vs_base=base+0)+2;
	Ldivide();
	vs_top=sup;
	{object V63 = vs_base[0];
	VMR10(V63)}
}
/*	local entry for function ASINH	*/

static object LI11(V65)

object V65;
{	 VMB11 VMS11 VMV11
TTL:;
	V67= number_times((V65),(V65));
	base[1]= number_plus(VV[2],/* INLINE-ARGS */V67);
	vs_top=(vs_base=base+1)+1;
	Lsqrt();
	vs_top=sup;
	V66= vs_base[0];
	base[0]= number_plus((V65),V66);
	vs_top=(vs_base=base+0)+1;
	Llog();
	vs_top=sup;
	{object V68 = vs_base[0];
	VMR11(V68)}
}
/*	local entry for function ACOSH	*/

static object LI12(V70)

register object V70;
{	 VMB12 VMS12 VMV12
TTL:;
	V71= one_plus((V70));
	base[2]= one_minus((V70));
	base[3]= one_plus((V70));
	vs_top=(vs_base=base+2)+2;
	Ldivide();
	vs_top=sup;
	base[1]= vs_base[0];
	vs_top=(vs_base=base+1)+1;
	Lsqrt();
	vs_top=sup;
	V72= vs_base[0];
	V73= number_times(/* INLINE-ARGS */V71,V72);
	base[0]= number_plus((V70),/* INLINE-ARGS */V73);
	vs_top=(vs_base=base+0)+1;
	Llog();
	vs_top=sup;
	{object V74 = vs_base[0];
	VMR12(V74)}
}
/*	local entry for function ATANH	*/

static object LI13(V76)

register object V76;
{	 VMB13 VMS13 VMV13
TTL:;
	if(number_compare((V76),VV[2])==0){
	goto T120;}
	if(!(number_compare((V76),VV[3])==0)){
	goto T119;}
T120:;
	base[0]= VV[5];
	base[1]= (V76);
	vs_top=(vs_base=base+0)+2;
	Lerror();
	vs_top=sup;
T119:;
	base[1]= one_plus((V76));
	V77= number_times((V76),(V76));
	base[3]= number_minus(VV[2],/* INLINE-ARGS */V77);
	vs_top=(vs_base=base+3)+1;
	Lsqrt();
	vs_top=sup;
	base[2]= vs_base[0];
	vs_top=(vs_base=base+1)+2;
	Ldivide();
	vs_top=sup;
	base[0]= vs_base[0];
	vs_top=(vs_base=base+0)+1;
	Llog();
	vs_top=sup;
	{object V78 = vs_base[0];
	VMR13(V78)}
}
/*	local entry for function RATIONAL	*/

static object LI14(V80)

register object V80;
{	 VMB14 VMS14 VMV14
TTL:;
	{register object V81;
	V81= (V80);
	if(!(type_of((V81))==t_shortfloat||type_of((V81))==t_longfloat)){
	goto T131;}
	{object V82;
	object V83;
	object V84;
	base[0]= (V80);
	vs_top=(vs_base=base+0)+1;
	Linteger_decode_float();
	if(vs_base>=vs_top){vs_top=sup;goto T135;}
	V82= vs_base[0];
	vs_base++;
	if(vs_base>=vs_top){vs_top=sup;goto T136;}
	V83= vs_base[0];
	vs_base++;
	if(vs_base>=vs_top){vs_top=sup;goto T137;}
	V84= vs_base[0];
	vs_top=sup;
	goto T138;
T135:;
	V82= Cnil;
T136:;
	V83= Cnil;
T137:;
	V84= Cnil;
T138:;
	if(!(number_compare((V84),small_fixnum(0))>=0)){
	goto T140;}
	base[0]= (V80);
	vs_top=(vs_base=base+0)+1;
	Lfloat_radix();
	vs_top=sup;
	V85= vs_base[0];
	V86= number_expt(V85,(V83));
	{object V87 = number_times((V82),/* INLINE-ARGS */V86);
	VMR14(V87)}
T140:;
	base[0]= (V80);
	vs_top=(vs_base=base+0)+1;
	Lfloat_radix();
	vs_top=sup;
	V88= vs_base[0];
	V89= number_expt(V88,(V83));
	V90= number_times((V82),/* INLINE-ARGS */V89);
	{object V91 = number_negate(/* INLINE-ARGS */V90);
	VMR14(V91)}}
T131:;
	base[0]= (V81);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk12)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T147;}
	{object V92 = (V80);
	VMR14(V92)}
T147:;
	base[0]= (*(LnkLI13))(VV[6],(V81),VV[7]);
	vs_top=(vs_base=base+0)+1;
	Lerror();
	vs_top=sup;
	{object V93 = vs_base[0];
	VMR14(V93)}}
}
/*	function definition for FFLOOR	*/

static L15()
{register object *base=vs_base;
	register object *sup=base+VM15; VC15
	vs_reserve(VM15);
	{object V94;
	object V95;
	if(vs_top-vs_base<1) too_few_arguments();
	if(vs_top-vs_base>2) too_many_arguments();
	V94=(base[0]);
	vs_base=vs_base+1;
	if(vs_base>=vs_top){vs_top=sup;goto T151;}
	V95=(base[1]);
	vs_top=sup;
	goto T152;
T151:;
	V95= VV[8];
T152:;
	{object V96;
	object V97;
	base[3]= (V94);
	vs_top=(vs_base=base+3)+1;
	Lfloat();
	vs_top=sup;
	base[2]= vs_base[0];
	base[4]= (V95);
	vs_top=(vs_base=base+4)+1;
	Lfloat();
	vs_top=sup;
	base[3]= vs_base[0];
	vs_top=(vs_base=base+2)+2;
	Lfloor();
	if(vs_base>=vs_top){vs_top=sup;goto T159;}
	V96= vs_base[0];
	vs_base++;
	if(vs_base>=vs_top){vs_top=sup;goto T160;}
	V97= vs_base[0];
	vs_top=sup;
	goto T161;
T159:;
	V96= Cnil;
T160:;
	V97= Cnil;
T161:;
	base[3]= (V96);
	base[4]= (V97);
	vs_top=(vs_base=base+3)+2;
	Lfloat();
	vs_top=sup;
	base[2]= vs_base[0];
	base[3]= (V97);
	vs_top=(vs_base=base+2)+2;
	return;}
	}
}
/*	function definition for FCEILING	*/

static L16()
{register object *base=vs_base;
	register object *sup=base+VM16; VC16
	vs_reserve(VM16);
	{object V98;
	object V99;
	if(vs_top-vs_base<1) too_few_arguments();
	if(vs_top-vs_base>2) too_many_arguments();
	V98=(base[0]);
	vs_base=vs_base+1;
	if(vs_base>=vs_top){vs_top=sup;goto T166;}
	V99=(base[1]);
	vs_top=sup;
	goto T167;
T166:;
	V99= VV[8];
T167:;
	{object V100;
	object V101;
	base[3]= (V98);
	vs_top=(vs_base=base+3)+1;
	Lfloat();
	vs_top=sup;
	base[2]= vs_base[0];
	base[4]= (V99);
	vs_top=(vs_base=base+4)+1;
	Lfloat();
	vs_top=sup;
	base[3]= vs_base[0];
	vs_top=(vs_base=base+2)+2;
	Lceiling();
	if(vs_base>=vs_top){vs_top=sup;goto T174;}
	V100= vs_base[0];
	vs_base++;
	if(vs_base>=vs_top){vs_top=sup;goto T175;}
	V101= vs_base[0];
	vs_top=sup;
	goto T176;
T174:;
	V100= Cnil;
T175:;
	V101= Cnil;
T176:;
	base[3]= (V100);
	base[4]= (V101);
	vs_top=(vs_base=base+3)+2;
	Lfloat();
	vs_top=sup;
	base[2]= vs_base[0];
	base[3]= (V101);
	vs_top=(vs_base=base+2)+2;
	return;}
	}
}
/*	function definition for FTRUNCATE	*/

static L17()
{register object *base=vs_base;
	register object *sup=base+VM17; VC17
	vs_reserve(VM17);
	{object V102;
	object V103;
	if(vs_top-vs_base<1) too_few_arguments();
	if(vs_top-vs_base>2) too_many_arguments();
	V102=(base[0]);
	vs_base=vs_base+1;
	if(vs_base>=vs_top){vs_top=sup;goto T181;}
	V103=(base[1]);
	vs_top=sup;
	goto T182;
T181:;
	V103= VV[8];
T182:;
	{object V104;
	object V105;
	base[3]= (V102);
	vs_top=(vs_base=base+3)+1;
	Lfloat();
	vs_top=sup;
	base[2]= vs_base[0];
	base[4]= (V103);
	vs_top=(vs_base=base+4)+1;
	Lfloat();
	vs_top=sup;
	base[3]= vs_base[0];
	vs_top=(vs_base=base+2)+2;
	Ltruncate();
	if(vs_base>=vs_top){vs_top=sup;goto T189;}
	V104= vs_base[0];
	vs_base++;
	if(vs_base>=vs_top){vs_top=sup;goto T190;}
	V105= vs_base[0];
	vs_top=sup;
	goto T191;
T189:;
	V104= Cnil;
T190:;
	V105= Cnil;
T191:;
	base[3]= (V104);
	base[4]= (V105);
	vs_top=(vs_base=base+3)+2;
	Lfloat();
	vs_top=sup;
	base[2]= vs_base[0];
	base[3]= (V105);
	vs_top=(vs_base=base+2)+2;
	return;}
	}
}
/*	function definition for FROUND	*/

static L18()
{register object *base=vs_base;
	register object *sup=base+VM18; VC18
	vs_reserve(VM18);
	{object V106;
	object V107;
	if(vs_top-vs_base<1) too_few_arguments();
	if(vs_top-vs_base>2) too_many_arguments();
	V106=(base[0]);
	vs_base=vs_base+1;
	if(vs_base>=vs_top){vs_top=sup;goto T196;}
	V107=(base[1]);
	vs_top=sup;
	goto T197;
T196:;
	V107= VV[8];
T197:;
	{object V108;
	object V109;
	base[3]= (V106);
	vs_top=(vs_base=base+3)+1;
	Lfloat();
	vs_top=sup;
	base[2]= vs_base[0];
	base[4]= (V107);
	vs_top=(vs_base=base+4)+1;
	Lfloat();
	vs_top=sup;
	base[3]= vs_base[0];
	vs_top=(vs_base=base+2)+2;
	Lround();
	if(vs_base>=vs_top){vs_top=sup;goto T204;}
	V108= vs_base[0];
	vs_base++;
	if(vs_base>=vs_top){vs_top=sup;goto T205;}
	V109= vs_base[0];
	vs_top=sup;
	goto T206;
T204:;
	V108= Cnil;
T205:;
	V109= Cnil;
T206:;
	base[3]= (V108);
	base[4]= (V109);
	vs_top=(vs_base=base+3)+2;
	Lfloat();
	vs_top=sup;
	base[2]= vs_base[0];
	base[3]= (V109);
	vs_top=(vs_base=base+2)+2;
	return;}
	}
}
/*	local entry for function LOGNAND	*/

static object LI19(V112,V113)

object V112;object V113;
{	 VMB19 VMS19 VMV19
TTL:;
	base[0]= small_fixnum(14);
	base[1]= (V112);
	base[2]= (V113);
	vs_top=(vs_base=base+0)+3;
	Lboole();
	vs_top=sup;
	{object V114 = vs_base[0];
	VMR19(V114)}
}
/*	local entry for function LOGNOR	*/

static object LI20(V117,V118)

object V117;object V118;
{	 VMB20 VMS20 VMV20
TTL:;
	base[0]= small_fixnum(8);
	base[1]= (V117);
	base[2]= (V118);
	vs_top=(vs_base=base+0)+3;
	Lboole();
	vs_top=sup;
	{object V119 = vs_base[0];
	VMR20(V119)}
}
/*	local entry for function LOGANDC1	*/

static object LI21(V122,V123)

object V122;object V123;
{	 VMB21 VMS21 VMV21
TTL:;
	base[0]= small_fixnum(4);
	base[1]= (V122);
	base[2]= (V123);
	vs_top=(vs_base=base+0)+3;
	Lboole();
	vs_top=sup;
	{object V124 = vs_base[0];
	VMR21(V124)}
}
/*	local entry for function LOGANDC2	*/

static object LI22(V127,V128)

object V127;object V128;
{	 VMB22 VMS22 VMV22
TTL:;
	base[0]= small_fixnum(2);
	base[1]= (V127);
	base[2]= (V128);
	vs_top=(vs_base=base+0)+3;
	Lboole();
	vs_top=sup;
	{object V129 = vs_base[0];
	VMR22(V129)}
}
/*	local entry for function LOGORC1	*/

static object LI23(V132,V133)

object V132;object V133;
{	 VMB23 VMS23 VMV23
TTL:;
	base[0]= small_fixnum(13);
	base[1]= (V132);
	base[2]= (V133);
	vs_top=(vs_base=base+0)+3;
	Lboole();
	vs_top=sup;
	{object V134 = vs_base[0];
	VMR23(V134)}
}
/*	local entry for function LOGORC2	*/

static object LI24(V137,V138)

object V137;object V138;
{	 VMB24 VMS24 VMV24
TTL:;
	base[0]= small_fixnum(11);
	base[1]= (V137);
	base[2]= (V138);
	vs_top=(vs_base=base+0)+3;
	Lboole();
	vs_top=sup;
	{object V139 = vs_base[0];
	VMR24(V139)}
}
/*	local entry for function LOGNOT	*/

static object LI25(V141)

object V141;
{	 VMB25 VMS25 VMV25
TTL:;
	base[0]= small_fixnum(-1);
	base[1]= (V141);
	vs_top=(vs_base=base+0)+2;
	Llogxor();
	vs_top=sup;
	{object V142 = vs_base[0];
	VMR25(V142)}
}
/*	local entry for function LOGTEST	*/

static object LI26(V145,V146)

object V145;object V146;
{	 VMB26 VMS26 VMV26
TTL:;
	base[0]= (V145);
	base[1]= (V146);
	vs_top=(vs_base=base+0)+2;
	Llogand();
	vs_top=sup;
	V147= vs_base[0];
	{object V148 = (((number_compare(small_fixnum(0),V147)==0?Ct:Cnil))==Cnil?Ct:Cnil);
	VMR26(V148)}
}
/*	local entry for function BYTE	*/

static object LI27(V151,V152)

object V151;object V152;
{	 VMB27 VMS27 VMV27
TTL:;
	{object V153 = make_cons((V151),(V152));
	VMR27(V153)}
}
/*	local entry for function BYTE-SIZE	*/

static object LI28(V155)

object V155;
{	 VMB28 VMS28 VMV28
TTL:;
	{object V156 = car((V155));
	VMR28(V156)}
}
/*	local entry for function BYTE-POSITION	*/

static object LI29(V158)

object V158;
{	 VMB29 VMS29 VMV29
TTL:;
	{object V159 = cdr((V158));
	VMR29(V159)}
}
/*	local entry for function LDB	*/

static object LI30(V162,V163)

object V162;object V163;
{	 VMB30 VMS30 VMV30
TTL:;
	base[0]= (V163);
	V165= (*(LnkLI15))((V162));
	base[1]= number_negate(/* INLINE-ARGS */V165);
	vs_top=(vs_base=base+0)+2;
	Lash();
	vs_top=sup;
	V164= vs_base[0];
	base[0]= small_fixnum(1);
	base[1]= (*(LnkLI16))((V162));
	vs_top=(vs_base=base+0)+2;
	Lash();
	vs_top=sup;
	V166= vs_base[0];
	V167= number_negate(V166);
	{object V168 = (*(LnkLI14))(V164,/* INLINE-ARGS */V167);
	VMR30(V168)}
}
/*	local entry for function LDB-TEST	*/

static object LI31(V171,V172)

object V171;object V172;
{	 VMB31 VMS31 VMV31
TTL:;
	V173= (*(LnkLI17))((V171),(V172));
	{object V174 = (((number_compare(small_fixnum(0),/* INLINE-ARGS */V173)==0?Ct:Cnil))==Cnil?Ct:Cnil);
	VMR31(V174)}
}
/*	local entry for function MASK-FIELD	*/

static object LI32(V177,V178)

object V177;object V178;
{	 VMB32 VMS32 VMV32
TTL:;
	base[0]= (*(LnkLI17))((V177),(V178));
	base[1]= (*(LnkLI15))((V177));
	vs_top=(vs_base=base+0)+2;
	Lash();
	vs_top=sup;
	{object V179 = vs_base[0];
	VMR32(V179)}
}
/*	local entry for function DPB	*/

static object LI33(V183,V184,V185)

object V183;object V184;object V185;
{	 VMB33 VMS33 VMV33
TTL:;
	base[0]= (V185);
	base[1]= (*(LnkLI18))((V184),(V185));
	base[4]= small_fixnum(1);
	base[5]= (*(LnkLI16))((V184));
	vs_top=(vs_base=base+4)+2;
	Lash();
	vs_top=sup;
	V186= vs_base[0];
	V187= number_negate(V186);
	base[3]= (*(LnkLI14))((V183),/* INLINE-ARGS */V187);
	base[4]= (*(LnkLI15))((V184));
	vs_top=(vs_base=base+3)+2;
	Lash();
	vs_top=sup;
	base[2]= vs_base[0];
	vs_top=(vs_base=base+0)+3;
	Llogxor();
	vs_top=sup;
	{object V188 = vs_base[0];
	VMR33(V188)}
}
/*	local entry for function DEPOSIT-FIELD	*/

static object LI34(V192,V193,V194)

object V192;object V193;object V194;
{	 VMB34 VMS34 VMV34
TTL:;
	base[0]= (V192);
	V196= (*(LnkLI15))((V193));
	base[1]= number_negate(/* INLINE-ARGS */V196);
	vs_top=(vs_base=base+0)+2;
	Lash();
	vs_top=sup;
	V195= vs_base[0];
	{object V197 = (*(LnkLI19))(V195,(V193),(V194));
	VMR34(V197)}
}
static object  LnkTLI19(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[19],&LnkLI19,3,ap);} /* DPB */
static object  LnkTLI18(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[18],&LnkLI18,2,ap);} /* MASK-FIELD */
static object  LnkTLI17(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[17],&LnkLI17,2,ap);} /* LDB */
static object  LnkTLI16(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[16],&LnkLI16,1,ap);} /* BYTE-SIZE */
static object  LnkTLI15(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[15],&LnkLI15,1,ap);} /* BYTE-POSITION */
static object  LnkTLI14(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[14],&LnkLI14,2,ap);} /* LOGANDC2 */
static object  LnkTLI13(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[13],&LnkLI13,3,ap);} /* TYPECASE-ERROR-STRING */
static LnkT12(){ call_or_link(VV[12],&Lnk12);} /* RATIONALP */
static object  LnkTLI11(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[11],&LnkLI11,1,ap);} /* COSH */
static object  LnkTLI10(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[10],&LnkLI10,1,ap);} /* SINH */
static object  LnkTLI9(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[9],&LnkLI9,1,ap);} /* ABS */
