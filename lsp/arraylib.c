
#include <cmpinclude.h>
#include "arraylib.h"
init_arraylib(){do_init(VV);}
/*	local entry for function BEST-ARRAY-ELEMENT-TYPE	*/

static object LI1(V2)

register object V2;
{	 VMB1 VMS1 VMV1
TTL:;
	if(eql(Ct,(V2))){
	goto T1;}
	if(((V2))!=Cnil){
	goto T2;}
T1:;
	{object V3 = Ct;
	VMR1(V3)}
T2:;
	{register object x= (V2),V4= VV[0];
	while(!endp(V4))
	if(x==(V4->c.c_car)){
	goto T8;
	}else V4=V4->c.c_cdr;
	goto T7;}
T8:;
	{object V5 = (V2);
	VMR1(V5)}
T7:;
	base[0]= (V2);
	base[1]= VV[1];
	vs_top=(vs_base=base+0)+2;
	(void) (*Lnk16)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T10;}
	{register object V6;
	register object V7;
	V6= VV[2];
	V7= car((V6));
T17:;
	if(!(endp((V6)))){
	goto T18;}
	{object V8 = VV[1];
	VMR1(V8)}
T18:;
	base[1]= (V2);
	base[2]= (V7);
	vs_top=(vs_base=base+1)+2;
	(void) (*Lnk16)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T22;}
	{object V9 = (V7);
	VMR1(V9)}
T22:;
	V6= cdr((V6));
	V7= car((V6));
	goto T17;}
T10:;
	if(!(eql((V2),VV[3]))){
	goto T33;}
	{object V10 = VV[4];
	VMR1(V10)}
T33:;{object V11;
	{register object V12;
	register object V13;
	V12= VV[5];
	V13= car((V12));
T40:;
	if(!(endp((V12)))){
	goto T41;}
	V11= Cnil;
	goto T36;
T41:;
	base[1]= (V2);
	base[2]= (V13);
	vs_top=(vs_base=base+1)+2;
	(void) (*Lnk16)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T45;}
	V11= (V13);
	goto T36;
T45:;
	V12= cdr((V12));
	V13= car((V12));
	goto T40;}
T36:;
	if(V11==Cnil)goto T35;
	{object V14 = V11;
	VMR1(V14)}
T35:;}
	{object V15 = Ct;
	VMR1(V15)}
}
/*	local entry for function MAKE-ARRAY	*/

static object LI2(V16,va_alist)
	object V16;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB2 VMS2 VMV2
	{register object V17;
	object V18;
	object V19;
	register object V20;
	object V21;
	object V22;
	object V23;
	object V24;
	object V25;
	object V26;
	if(narg <1) too_few_arguments();
	V17= V16;
	narg= narg - 1;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +1,&LI2key,ap);
	if(Vcs[1]==0){
	V18= Ct;
	}else{
	V18=(Vcs[1]);}
	V19=(Vcs[2]);
	if(Vcs[3]==0){
	V20= Cnil;
	V21= Cnil;
	}else{
	V20=(Vcs[3]);
	V21= Ct;}
	V22=(Vcs[4]);
	V23=(Vcs[5]);
	V24=(Vcs[6]);
	V25=(Vcs[7]);
	V26=(Vcs[8]);
	if(!(type_of((V17))==t_fixnum||type_of((V17))==t_bignum)){
	goto T57;}
	V17= make_cons((V17),Cnil);
T57:;
	V18= (*(LnkLI21))((V18));
	if(!((length((V17)))==(1))){
	goto T64;}
	{register object V27;
	base[0]= (V18);
	base[1]= car((V17));
	base[2]= (V22);
	base[3]= (V23);
	base[4]= (V24);
	base[5]= (V25);
	base[6]= (V26);
	base[7]= (V19);
	vs_top=(vs_base=base+0)+8;
	siLmake_vector();
	vs_top=sup;
	V27= vs_base[0];
	if(((V21))==Cnil){
	goto T75;}
	{int V28;
	register int V29;
	V28= fix(car((V17)));
	V29= 0;
T81:;
	if(!((V29)>=(V28))){
	goto T82;}
	goto T75;
T82:;
	V30= elt((V20),V29);
	(void)(aset1((V27),V29,/* INLINE-ARGS */V30));
	V29= (V29)+1;
	goto T81;}
T75:;
	{object V31 = (V27);
	VMR2(V31)}}
T64:;
	{register object V32;
	base[0]= (V18);
	base[1]= (V22);
	base[2]= (V24);
	base[3]= (V25);
	base[4]= (V26);
	base[5]= (V19);
	{object V33;
	V33= (V17);
	 vs_top=base+6;
	 while(!endp(V33))
	 {vs_push(car(V33));V33=cdr(V33);}
	vs_base=base+0;}
	siLmake_pure_array();
	vs_top=sup;
	V32= vs_base[0];
	if(((V23))==Cnil){
	goto T98;}
	base[0]= VV[6];
	vs_top=(vs_base=base+0)+1;
	Lerror();
	vs_top=sup;
T98:;
	{register object x= small_fixnum(0),V34= (V17);
	while(!endp(V34))
	if(eql(x,V34->c.c_car)){
	goto T102;
	}else V34=V34->c.c_cdr;}
	if(((V21))==Cnil){
	goto T102;}
	{register object V35;
	base[0]= make_fixnum(length((V17)));
	base[1]= VV[7];
	base[2]= small_fixnum(0);
	vs_top=(vs_base=base+0)+3;
	Lmake_list();
	vs_top=sup;
	V35= vs_base[0];
T112:;
	base[0]= (V32);
	base[1]= (*(LnkLI22))((V20),(V35));
	base[2]= (V35);
	vs_top=(vs_base=base+0)+3;
	(void) (*Lnk23)();
	vs_top=sup;
	if(((*(LnkLI24))((V35),(V17)))==Cnil){
	goto T119;}
	goto T102;
T119:;
	goto T112;}
T102:;
	{object V36 = (V32);
	VMR2(V36)}}}
	}}
/*	local entry for function INCREMENT-CURSOR	*/

static object LI3(V39,V40)

register object V39;object V40;
{	 VMB3 VMS3 VMV3
TTL:;
	if(((V39))!=Cnil){
	goto T125;}
	{object V41 = Ct;
	VMR3(V41)}
T125:;
	{object V42;
	V42= (*(LnkLI24))(cdr((V39)),cdr((V40)));
	if(((V42))==Cnil){
	goto T129;}
	if(!(((fix(car((V39))))+1)>=(fix(car((V40)))))){
	goto T132;}
	if(type_of((V39))!=t_cons)FEwrong_type_argument(Scons,(V39));
	((V39))->c.c_car = small_fixnum(0);
	{object V43 = Ct;
	VMR3(V43)}
T132:;
	V44 = make_fixnum((fix(car((V39))))+1);
	if(type_of((V39))!=t_cons)FEwrong_type_argument(Scons,(V39));
	((V39))->c.c_car = V44;
	{object V45 = Cnil;
	VMR3(V45)}
T129:;
	{object V46 = Cnil;
	VMR3(V46)}}
}
/*	local entry for function SEQUENCE-CURSOR	*/

static object LI4(V49,V50)

object V49;object V50;
{	 VMB4 VMS4 VMV4
TTL:;
	if(((V50))!=Cnil){
	goto T137;}
	{object V51 = (V49);
	VMR4(V51)}
T137:;
	V49= elt((V49),fix(car((V50))));
	V50= cdr((V50));
	goto TTL;
}
/*	local entry for function VECTOR	*/

static object LI5(va_alist)
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB5 VMS5 VMV5
	{object V52;
	narg= narg - 0;
	va_start(ap);
	V53 = (ALLOCA_CONS(narg),ON_STACK_LIST_VECTOR(narg,ap));
	V52= V53;
	{object V54;
	V55 = make_fixnum(length((V52)));
	V54= make_cons(V55,Cnil);
	{object V56 = (VFUN_NARGS=5,(*(LnkLI25))((V54),VV[8],Ct,VV[9],(V52)));
	VMR5(V56)}}}
	}
/*	local entry for function ARRAY-DIMENSIONS	*/

static object LI6(V58)

register object V58;
{	 VMB6 VMS6 VMV6
TTL:;
	{register object V59;
	register object V60;
	base[0]= (V58);
	vs_top=(vs_base=base+0)+1;
	Larray_rank();
	vs_top=sup;
	V59= vs_base[0];
	V60= Cnil;
T146:;
	if(!(number_compare((V59),small_fixnum(0))==0)){
	goto T147;}
	{object V61 = (V60);
	VMR6(V61)}
T147:;
	V59= one_minus((V59));
	base[0]= (V58);
	base[1]= (V59);
	vs_top=(vs_base=base+0)+2;
	Larray_dimension();
	vs_top=sup;
	V62= vs_base[0];
	V60= make_cons(V62,(V60));
	goto T146;}
}
/*	local entry for function ARRAY-IN-BOUNDS-P	*/

static object LI7(V63,va_alist)
	object V63;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB7 VMS7 VMV7
	{register object V64;
	object V65;
	if(narg <1) too_few_arguments();
	V64= V63;
	narg= narg - 1;
	va_start(ap);
	V66 = (ALLOCA_CONS(narg),ON_STACK_LIST_VECTOR(narg,ap));
	V65= V66;
	{register object V67;
	base[1]= (V64);
	vs_top=(vs_base=base+1)+1;
	Larray_rank();
	vs_top=sup;
	V67= vs_base[0];
	V68 = make_fixnum(length((V65)));
	if(!(number_compare((V67),V68)!=0)){
	goto T162;}
	base[1]= VV[10];
	base[2]= (V67);
	base[3]= make_fixnum(length((V65)));
	vs_top=(vs_base=base+1)+3;
	Lerror();
	vs_top=sup;
T162:;
	{register object V69;
	register object V70;
	V69= small_fixnum(0);
	V70= (V65);
T169:;
	if(!(number_compare((V69),(V67))>=0)){
	goto T170;}
	{object V71 = Ct;
	VMR7(V71)}
T170:;
	if(number_compare(car((V70)),small_fixnum(0))<0){
	goto T175;}
	V72= car((V70));
	base[1]= (V64);
	base[2]= (V69);
	vs_top=(vs_base=base+1)+2;
	Larray_dimension();
	vs_top=sup;
	V73= vs_base[0];
	if(!(number_compare(/* INLINE-ARGS */V72,V73)>=0)){
	goto T174;}
T175:;
	{object V74 = Cnil;
	VMR7(V74)}
T174:;
	V69= one_plus((V69));
	V70= cdr((V70));
	goto T169;}}}
	}
/*	local entry for function ARRAY-ROW-MAJOR-INDEX	*/

static object LI8(V75,va_alist)
	object V75;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB8 VMS8 VMV8
	{register object V76;
	object V77;
	if(narg <1) too_few_arguments();
	V76= V75;
	narg= narg - 1;
	va_start(ap);
	V78 = (ALLOCA_CONS(narg),ON_STACK_LIST_VECTOR(narg,ap));
	V77= V78;
	{register object V79;
	register object V80;
	register object V81;
	V79= small_fixnum(0);
	V80= small_fixnum(0);
	V81= (V77);
T187:;
	if(((V81))!=Cnil){
	goto T188;}
	{object V82 = (V80);
	VMR8(V82)}
T188:;
	{object V83;
	V83= one_plus((V79));
	base[0]= (V76);
	base[1]= (V79);
	vs_top=(vs_base=base+0)+2;
	Larray_dimension();
	vs_top=sup;
	V84= vs_base[0];
	V85= number_times((V80),V84);
	V80= number_plus(/* INLINE-ARGS */V85,car((V81)));
	V81= cdr((V81));
	V79= (V83);}
	goto T187;}}
	}
/*	local entry for function BIT	*/

static object LI9(V86,va_alist)
	object V86;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB9 VMS9 VMV9
	{object V87;
	object V88;
	if(narg <1) too_few_arguments();
	V87= V86;
	narg= narg - 1;
	va_start(ap);
	V89 = (ALLOCA_CONS(narg),ON_STACK_LIST_VECTOR(narg,ap));
	V88= V89;
	base[0]= (V87);
	{object V90;
	V90= (V88);
	 vs_top=base+1;
	 while(!endp(V90))
	 {vs_push(car(V90));V90=cdr(V90);}
	vs_base=base+0;}
	Laref();
	vs_top=sup;
	{object V91 = vs_base[0];
	VMR9(V91)}}
	}
/*	local entry for function SBIT	*/

static object LI10(V92,va_alist)
	object V92;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB10 VMS10 VMV10
	{object V93;
	object V94;
	if(narg <1) too_few_arguments();
	V93= V92;
	narg= narg - 1;
	va_start(ap);
	V95 = (ALLOCA_CONS(narg),ON_STACK_LIST_VECTOR(narg,ap));
	V94= V95;
	base[0]= (V93);
	{object V96;
	V96= (V94);
	 vs_top=base+1;
	 while(!endp(V96))
	 {vs_push(car(V96));V96=cdr(V96);}
	vs_base=base+0;}
	Laref();
	vs_top=sup;
	{object V97 = vs_base[0];
	VMR10(V97)}}
	}
/*	local entry for function BIT-AND	*/

static object LI11(V99,V98,va_alist)
	object V99,V98;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB11 VMS11 VMV11
	{object V100;
	object V101;
	object V102;
	if(narg <2) too_few_arguments();
	V100= V99;
	V101= V98;
	narg = narg - 2;
	if (narg <= 0) goto T204;
	else {
	va_start(ap);
	V102= va_arg(ap,object);}
	--narg; goto T205;
T204:;
	V102= Cnil;
T205:;
	base[0]= small_fixnum(1);
	base[1]= (V100);
	base[2]= (V101);
	base[3]= (V102);
	vs_top=(vs_base=base+0)+4;
	siLbit_array_op();
	vs_top=sup;
	{object V103 = vs_base[0];
	VMR11(V103)}}
	}
/*	local entry for function BIT-IOR	*/

static object LI12(V105,V104,va_alist)
	object V105,V104;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB12 VMS12 VMV12
	{object V106;
	object V107;
	object V108;
	if(narg <2) too_few_arguments();
	V106= V105;
	V107= V104;
	narg = narg - 2;
	if (narg <= 0) goto T211;
	else {
	va_start(ap);
	V108= va_arg(ap,object);}
	--narg; goto T212;
T211:;
	V108= Cnil;
T212:;
	base[0]= small_fixnum(7);
	base[1]= (V106);
	base[2]= (V107);
	base[3]= (V108);
	vs_top=(vs_base=base+0)+4;
	siLbit_array_op();
	vs_top=sup;
	{object V109 = vs_base[0];
	VMR12(V109)}}
	}
/*	local entry for function BIT-XOR	*/

static object LI13(V111,V110,va_alist)
	object V111,V110;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB13 VMS13 VMV13
	{object V112;
	object V113;
	object V114;
	if(narg <2) too_few_arguments();
	V112= V111;
	V113= V110;
	narg = narg - 2;
	if (narg <= 0) goto T218;
	else {
	va_start(ap);
	V114= va_arg(ap,object);}
	--narg; goto T219;
T218:;
	V114= Cnil;
T219:;
	base[0]= small_fixnum(6);
	base[1]= (V112);
	base[2]= (V113);
	base[3]= (V114);
	vs_top=(vs_base=base+0)+4;
	siLbit_array_op();
	vs_top=sup;
	{object V115 = vs_base[0];
	VMR13(V115)}}
	}
/*	local entry for function BIT-EQV	*/

static object LI14(V117,V116,va_alist)
	object V117,V116;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB14 VMS14 VMV14
	{object V118;
	object V119;
	object V120;
	if(narg <2) too_few_arguments();
	V118= V117;
	V119= V116;
	narg = narg - 2;
	if (narg <= 0) goto T225;
	else {
	va_start(ap);
	V120= va_arg(ap,object);}
	--narg; goto T226;
T225:;
	V120= Cnil;
T226:;
	base[0]= small_fixnum(9);
	base[1]= (V118);
	base[2]= (V119);
	base[3]= (V120);
	vs_top=(vs_base=base+0)+4;
	siLbit_array_op();
	vs_top=sup;
	{object V121 = vs_base[0];
	VMR14(V121)}}
	}
/*	local entry for function BIT-NAND	*/

static object LI15(V123,V122,va_alist)
	object V123,V122;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB15 VMS15 VMV15
	{object V124;
	object V125;
	object V126;
	if(narg <2) too_few_arguments();
	V124= V123;
	V125= V122;
	narg = narg - 2;
	if (narg <= 0) goto T232;
	else {
	va_start(ap);
	V126= va_arg(ap,object);}
	--narg; goto T233;
T232:;
	V126= Cnil;
T233:;
	base[0]= small_fixnum(14);
	base[1]= (V124);
	base[2]= (V125);
	base[3]= (V126);
	vs_top=(vs_base=base+0)+4;
	siLbit_array_op();
	vs_top=sup;
	{object V127 = vs_base[0];
	VMR15(V127)}}
	}
/*	local entry for function BIT-NOR	*/

static object LI16(V129,V128,va_alist)
	object V129,V128;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB16 VMS16 VMV16
	{object V130;
	object V131;
	object V132;
	if(narg <2) too_few_arguments();
	V130= V129;
	V131= V128;
	narg = narg - 2;
	if (narg <= 0) goto T239;
	else {
	va_start(ap);
	V132= va_arg(ap,object);}
	--narg; goto T240;
T239:;
	V132= Cnil;
T240:;
	base[0]= small_fixnum(8);
	base[1]= (V130);
	base[2]= (V131);
	base[3]= (V132);
	vs_top=(vs_base=base+0)+4;
	siLbit_array_op();
	vs_top=sup;
	{object V133 = vs_base[0];
	VMR16(V133)}}
	}
/*	local entry for function BIT-ANDC1	*/

static object LI17(V135,V134,va_alist)
	object V135,V134;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB17 VMS17 VMV17
	{object V136;
	object V137;
	object V138;
	if(narg <2) too_few_arguments();
	V136= V135;
	V137= V134;
	narg = narg - 2;
	if (narg <= 0) goto T246;
	else {
	va_start(ap);
	V138= va_arg(ap,object);}
	--narg; goto T247;
T246:;
	V138= Cnil;
T247:;
	base[0]= small_fixnum(4);
	base[1]= (V136);
	base[2]= (V137);
	base[3]= (V138);
	vs_top=(vs_base=base+0)+4;
	siLbit_array_op();
	vs_top=sup;
	{object V139 = vs_base[0];
	VMR17(V139)}}
	}
/*	local entry for function BIT-ANDC2	*/

static object LI18(V141,V140,va_alist)
	object V141,V140;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB18 VMS18 VMV18
	{object V142;
	object V143;
	object V144;
	if(narg <2) too_few_arguments();
	V142= V141;
	V143= V140;
	narg = narg - 2;
	if (narg <= 0) goto T253;
	else {
	va_start(ap);
	V144= va_arg(ap,object);}
	--narg; goto T254;
T253:;
	V144= Cnil;
T254:;
	base[0]= small_fixnum(2);
	base[1]= (V142);
	base[2]= (V143);
	base[3]= (V144);
	vs_top=(vs_base=base+0)+4;
	siLbit_array_op();
	vs_top=sup;
	{object V145 = vs_base[0];
	VMR18(V145)}}
	}
/*	local entry for function BIT-ORC1	*/

static object LI19(V147,V146,va_alist)
	object V147,V146;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB19 VMS19 VMV19
	{object V148;
	object V149;
	object V150;
	if(narg <2) too_few_arguments();
	V148= V147;
	V149= V146;
	narg = narg - 2;
	if (narg <= 0) goto T260;
	else {
	va_start(ap);
	V150= va_arg(ap,object);}
	--narg; goto T261;
T260:;
	V150= Cnil;
T261:;
	base[0]= small_fixnum(13);
	base[1]= (V148);
	base[2]= (V149);
	base[3]= (V150);
	vs_top=(vs_base=base+0)+4;
	siLbit_array_op();
	vs_top=sup;
	{object V151 = vs_base[0];
	VMR19(V151)}}
	}
/*	local entry for function BIT-ORC2	*/

static object LI20(V153,V152,va_alist)
	object V153,V152;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB20 VMS20 VMV20
	{object V154;
	object V155;
	object V156;
	if(narg <2) too_few_arguments();
	V154= V153;
	V155= V152;
	narg = narg - 2;
	if (narg <= 0) goto T267;
	else {
	va_start(ap);
	V156= va_arg(ap,object);}
	--narg; goto T268;
T267:;
	V156= Cnil;
T268:;
	base[0]= small_fixnum(11);
	base[1]= (V154);
	base[2]= (V155);
	base[3]= (V156);
	vs_top=(vs_base=base+0)+4;
	siLbit_array_op();
	vs_top=sup;
	{object V157 = vs_base[0];
	VMR20(V157)}}
	}
/*	local entry for function BIT-NOT	*/

static object LI21(V158,va_alist)
	object V158;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB21 VMS21 VMV21
	{object V159;
	object V160;
	if(narg <1) too_few_arguments();
	V159= V158;
	narg = narg - 1;
	if (narg <= 0) goto T274;
	else {
	va_start(ap);
	V160= va_arg(ap,object);}
	--narg; goto T275;
T274:;
	V160= Cnil;
T275:;
	base[0]= small_fixnum(12);
	base[1]= (V159);
	base[2]= (V159);
	base[3]= (V160);
	vs_top=(vs_base=base+0)+4;
	siLbit_array_op();
	vs_top=sup;
	{object V161 = vs_base[0];
	VMR21(V161)}}
	}
/*	local entry for function VECTOR-PUSH	*/

static object LI22(V164,V165)

object V164;register object V165;
{	 VMB22 VMS22 VMV22
TTL:;
	{register int V166;
	base[0]= (V165);
	vs_top=(vs_base=base+0)+1;
	Lfill_pointer();
	vs_top=sup;
	V166= fix(vs_base[0]);
	base[0]= (V165);
	base[1]= small_fixnum(0);
	vs_top=(vs_base=base+0)+2;
	Larray_dimension();
	vs_top=sup;
	V167= vs_base[0];
	if(!((V166)<(fix(V167)))){
	goto T284;}
	(void)(aset1((V165),V166,(V164)));
	base[0]= (V165);
	base[1]= make_fixnum((V166)+1);
	vs_top=(vs_base=base+0)+2;
	siLfill_pointer_set();
	vs_top=sup;
	{object V168 = make_fixnum(V166);
	VMR22(V168)}
T284:;
	{object V169 = Cnil;
	VMR22(V169)}}
}
/*	local entry for function VECTOR-PUSH-EXTEND	*/

static object LI23(V171,V170,va_alist)
	object V171,V170;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB23 VMS23 VMV23
	{object V172;
	register object V173;
	object V174;
	if(narg <2) too_few_arguments();
	V172= V171;
	V173= V170;
	narg = narg - 2;
	if (narg <= 0) goto T293;
	else {
	va_start(ap);
	V174= va_arg(ap,object);}
	--narg; goto T294;
T293:;
	V174= Cnil;
T294:;
	{register int V175;
	base[0]= (V173);
	vs_top=(vs_base=base+0)+1;
	Lfill_pointer();
	vs_top=sup;
	V175= fix(vs_base[0]);
	base[0]= (V173);
	base[1]= small_fixnum(0);
	vs_top=(vs_base=base+0)+2;
	Larray_dimension();
	vs_top=sup;
	V176= vs_base[0];
	if(!((V175)<(fix(V176)))){
	goto T299;}
	(void)(aset1((V173),V175,(V172)));
	base[0]= (V173);
	base[1]= make_fixnum((V175)+1);
	vs_top=(vs_base=base+0)+2;
	siLfill_pointer_set();
	vs_top=sup;
	{object V177 = make_fixnum(V175);
	VMR23(V177)}
T299:;
	base[0]= (V173);
	base[1]= small_fixnum(0);
	vs_top=(vs_base=base+0)+2;
	Larray_dimension();
	vs_top=sup;
	V178= vs_base[0];
	if((V174)!=Cnil){
	V179= (V174);
	goto T312;}
	base[0]= (V173);
	base[1]= small_fixnum(0);
	vs_top=(vs_base=base+0)+2;
	Larray_dimension();
	vs_top=sup;
	V180= vs_base[0];
	if(!((fix(V180))>(0))){
	goto T314;}
	base[0]= (V173);
	base[1]= small_fixnum(0);
	vs_top=(vs_base=base+0)+2;
	Larray_dimension();
	vs_top=sup;
	V179= vs_base[0];
	goto T312;
T314:;
	V179= small_fixnum(5);
T312:;
	V181= number_plus(V178,V179);
	V182= make_cons(/* INLINE-ARGS */V181,Cnil);
	base[0]= (V173);
	vs_top=(vs_base=base+0)+1;
	Larray_element_type();
	vs_top=sup;
	V183= vs_base[0];
	V184 = make_fixnum(V175);
	(void)((VFUN_NARGS=6,(*(LnkLI26))((V173),/* INLINE-ARGS */V182,VV[8],V183,VV[11],V184)));
	(void)(aset1((V173),V175,(V172)));
	base[0]= (V173);
	base[1]= make_fixnum((V175)+1);
	vs_top=(vs_base=base+0)+2;
	siLfill_pointer_set();
	vs_top=sup;
	{object V185 = make_fixnum(V175);
	VMR23(V185)}}}
	}
/*	local entry for function VECTOR-POP	*/

static object LI24(V187)

register object V187;
{	 VMB24 VMS24 VMV24
TTL:;
	{int V188;
	base[0]= (V187);
	vs_top=(vs_base=base+0)+1;
	Lfill_pointer();
	vs_top=sup;
	V188= fix(vs_base[0]);
	if(!((V188)==(0))){
	goto T329;}
	base[0]= VV[12];
	base[1]= (V187);
	vs_top=(vs_base=base+0)+2;
	Lerror();
	vs_top=sup;
T329:;
	base[0]= (V187);
	base[1]= make_fixnum((V188)-1);
	vs_top=(vs_base=base+0)+2;
	siLfill_pointer_set();
	vs_top=sup;
	{object V189 = aref1((V187),(V188)-1);
	VMR24(V189)}}
}
/*	local entry for function ADJUST-ARRAY	*/

static object LI25(V191,V190,va_alist)
	object V191,V190;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB25 VMS25 VMV25
	{register object V192;
	register object V193;
	register object V194;
	register object V195;
	object V196;
	object V197;
	object V198;
	object V199;
	object V200;
	object V201;
	if(narg <2) too_few_arguments();
	V192= V191;
	V193= V190;
	narg= narg - 2;
	va_start(ap);
	V202 = (ALLOCA_CONS(narg),ON_STACK_MAKE_LIST(narg));
	V194= V202;
	{
	parse_key_rest(V202,narg,Vcs +3,&LI25key,ap);
	V195=(Vcs[3]);
	V196=(Vcs[4]);
	V197=(Vcs[5]);
	V198=(Vcs[6]);
	V199=(Vcs[7]);
	V200=(Vcs[8]);
	V201=(Vcs[9]);
	if(!(type_of((V193))==t_fixnum||type_of((V193))==t_bignum)){
	goto T337;}
	V193= make_cons((V193),Cnil);
T337:;
	{register object x= VV[11],V203= (V194);
	while(!endp(V203))
	if(eql(x,V203->c.c_car)){
	goto T344;
	}else V203=V203->c.c_cdr;
	goto T343;}
T344:;
	base[0]= (V192);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk27)();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T341;}
	base[0]= VV[13];
	vs_top=(vs_base=base+0)+1;
	Lerror();
	vs_top=sup;
	goto T341;
T343:;
	base[0]= (V192);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk27)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T341;}
	base[0]= (V192);
	vs_top=(vs_base=base+0)+1;
	Lfill_pointer();
	vs_top=sup;
	V204= vs_base[0];
	V194= ON_STACK_CONS(V204,(V194));
	V194= ON_STACK_CONS(VV[11],(V194));
T341:;
	base[0]= (V192);
	vs_top=(vs_base=base+0)+1;
	Larray_element_type();
	vs_top=sup;
	V195= vs_base[0];
	if(((V195))==(Ct)){
	goto T360;}
	V194= ON_STACK_CONS((V195),(V194));
	V194= ON_STACK_CONS(VV[8],(V194));
T360:;
	{register object V205;
	base[0]= (V193);
	base[1]= VV[14];
	base[2]= Ct;
	{object V206;
	V206= (V194);
	 vs_top=base+3;
	 while(!endp(V206))
	 {vs_push(car(V206));V206=cdr(V206);}
	vs_base=base+0;}
	(void) (*Lnk25)();
	vs_top=sup;
	V205= vs_base[0];
	if((cdr((V193)))==Cnil){
	goto T372;}
	V207= cdr((V193));
	V208= (*(LnkLI28))((V192));
	if(!(equal(/* INLINE-ARGS */V207,cdr(/* INLINE-ARGS */V208)))){
	goto T373;}
	if(!(((V195))==(VV[15]))){
	goto T372;}
	base[0]= (V193);
	vs_top=(vs_base=base+0)+1;
	Llast();
	vs_top=sup;
	V209= vs_base[0];
	{int V210= fix(car(V209));
	if(!((0)==((V210>=0&&(8)>0?(V210)%(8):imod(V210,8))))){
	goto T373;}}
T372:;
	base[0]= (V192);
	base[1]= (V205);
	base[2]= small_fixnum(0);
	base[3]= small_fixnum(0);
	base[5]= (V205);
	vs_top=(vs_base=base+5)+1;
	(void) (*Lnk29)();
	vs_top=sup;
	V211= vs_base[0];
	base[5]= (V192);
	vs_top=(vs_base=base+5)+1;
	(void) (*Lnk29)();
	vs_top=sup;
	V212= vs_base[0];
	base[4]= (number_compare(V211,V212)<=0?(V211):V212);
	vs_top=(vs_base=base+0)+5;
	(void) (*Lnk30)();
	vs_top=sup;
	goto T371;
T373:;
	{register object V213;
	base[0]= make_fixnum(length((V193)));
	base[1]= VV[7];
	base[2]= small_fixnum(0);
	vs_top=(vs_base=base+0)+3;
	Lmake_list();
	vs_top=sup;
	V213= vs_base[0];
T397:;
	base[0]= (V192);
	{object V214;
	V214= (V213);
	 vs_top=base+1;
	 while(!endp(V214))
	 {vs_push(car(V214));V214=cdr(V214);}
	vs_base=base+0;}
	(void) (*Lnk31)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T400;}
	base[0]= (V205);
	base[2]= (V192);
	{object V215;
	V215= (V213);
	 vs_top=base+3;
	 while(!endp(V215))
	 {vs_push(car(V215));V215=cdr(V215);}
	vs_base=base+2;}
	Laref();
	vs_top=sup;
	base[1]= vs_base[0];
	base[2]= (V213);
	vs_top=(vs_base=base+0)+3;
	(void) (*Lnk23)();
	vs_top=sup;
T400:;
	if(((*(LnkLI24))((V213),(V193)))==Cnil){
	goto T410;}
	goto T371;
T410:;
	goto T397;}
T371:;
	base[0]= (V192);
	base[1]= (V205);
	vs_top=(vs_base=base+0)+2;
	siLreplace_array();
	vs_top=sup;
	{object V216 = vs_base[0];
	VMR25(V216)}}}
	}}
static LnkT31(){ call_or_link(VV[31],&Lnk31);} /* ARRAY-IN-BOUNDS-P */
static LnkT30(){ call_or_link(VV[30],&Lnk30);} /* COPY-ARRAY-PORTION */
static LnkT29(){ call_or_link(VV[29],&Lnk29);} /* ARRAY-TOTAL-SIZE */
static object  LnkTLI28(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[28],&LnkLI28,1,ap);} /* ARRAY-DIMENSIONS */
static LnkT25(){ call_or_link(VV[25],&Lnk25);} /* MAKE-ARRAY */
static LnkT27(){ call_or_link(VV[27],&Lnk27);} /* ARRAY-HAS-FILL-POINTER-P */
static object  LnkTLI26(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[26],&LnkLI26,ap);} /* ADJUST-ARRAY */
static object  LnkTLI25(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[25],&LnkLI25,ap);} /* MAKE-ARRAY */
static object  LnkTLI24(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[24],&LnkLI24,2,ap);} /* INCREMENT-CURSOR */
static LnkT23(){ call_or_link(VV[23],&Lnk23);} /* ASET-BY-CURSOR */
static object  LnkTLI22(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[22],&LnkLI22,2,ap);} /* SEQUENCE-CURSOR */
static object  LnkTLI21(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[21],&LnkLI21,1,ap);} /* BEST-ARRAY-ELEMENT-TYPE */
static LnkT16(){ call_or_link(VV[16],&Lnk16);} /* SUBTYPEP */
