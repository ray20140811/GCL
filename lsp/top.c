
#include <cmpinclude.h>
#include "top.h"
init_top(){do_init(VV);}
/*	local entry for function TOP-LEVEL	*/

static object LI1()

{	 VMB1 VMS1 VMV1
	bds_check;
TTL:;
	bds_bind(VV[0],Cnil);
	bds_bind(VV[1],Cnil);
	bds_bind(VV[2],Cnil);
	bds_bind(VV[3],Cnil);
	bds_bind(VV[4],Cnil);
	bds_bind(VV[5],Cnil);
	bds_bind(VV[6],Cnil);
	bds_bind(VV[7],Cnil);
	bds_bind(VV[8],Cnil);
	bds_bind(VV[9],Cnil);
	setq(VV[10],Ct);
	frs_push(FRS_CATCH,symbol_value(VV[11]));
	if(nlj_active)
	{nlj_active=FALSE;frs_pop();
	vs_top=sup;
	goto T3;}
	else{
	{register object V1;
	base[10]= symbol_value(VV[12]);
	base[11]= VV[13];
	vs_top=(vs_base=base+10)+2;
	(void) (*Lnk121)();
	vs_top=sup;
	V1= vs_base[0];
	if(!((file_exists((V1))))){
	goto T9;}
	base[10]= (V1);
	base[11]= VV[14];
	base[12]= Cnil;
	vs_top=(vs_base=base+10)+3;
	(void) (*Lnk122)();
	vs_top=sup;
T9:;
	if((symbol_value(VV[15]))==Cnil){
	goto T17;}
	setq(VV[15],Cnil);
	goto T15;
T17:;
	if(!((file_exists(VV[16])))){
	goto T15;}
	base[10]= VV[17];
	vs_top=(vs_base=base+10)+1;
	(void) (*Lnk122)();
	vs_top=sup;
T15:;
T24:;
	V1= symbol_value(VV[18]);
	{register object x= VV[19],V2= (V1);
	while(!endp(V2))
	if(equal(x,V2->c.c_car)){
	V1= V2;
	goto T31;
	}else V2=V2->c.c_cdr;
	V1= Cnil;}
T31:;
	if(((V1))==Cnil){
	goto T28;}
	base[10]= cadr((V1));
	base[11]= VV[14];
	base[12]= Cnil;
	vs_top=(vs_base=base+10)+3;
	(void) (*Lnk122)();
	vs_top=sup;
	V1= cddr((V1));
T28:;
	if((V1)!=Cnil){
	goto T25;}
	goto T5;
T25:;
	goto T24;}
T5:;
	base[10]= symbol_value(VV[20]);
	vs_top=(vs_base=base+10)+1;
	Lfunctionp();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T38;}
	frs_pop();
	goto T3;
T38:;
	V3= (
	(type_of(symbol_value(VV[20])) == t_sfun ?(*(object (*)())((symbol_value(VV[20]))->sfn.sfn_self)):
	(fcall.fun=(symbol_value(VV[20])),fcall.argd=0,fcalln))());
	frs_pop();}
T3:;
T42:;
	(VV[2]->s.s_dbind)= (VV[1]->s.s_dbind);
	(VV[1]->s.s_dbind)= (VV[0]->s.s_dbind);
	(VV[0]->s.s_dbind)= (VV[3]->s.s_dbind);
	if((symbol_value(VV[21]))==Cnil){
	goto T52;}
	setq(VV[21],Cnil);
	goto T50;
T52:;
	base[10]= Ct;
	base[11]= VV[22];{VOL object V4;
	V4= symbol_value(VV[23]);
	base[13]= VV[24];
	vs_top=(vs_base=base+13)+1;
	Lfind_package();
	vs_top=sup;
	V5= vs_base[0];
	if(!((V4)==(V5))){
	goto T59;}}
	base[12]= VV[25];
	goto T57;
T59:;
	base[13]= symbol_value(VV[23]);
	vs_top=(vs_base=base+13)+1;
	Lpackage_name();
	vs_top=sup;
	base[12]= vs_base[0];
T57:;
	vs_top=(vs_base=base+10)+3;
	Lformat();
	vs_top=sup;
T50:;
	vs_base=vs_top;
	siLreset_stack_limits();
	vs_top=sup;
	if((symbol_value(VV[15]))==Cnil){
	goto T65;}
	{object V6 = Cnil;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	VMR1(V6)}
T65:;
	frs_push(FRS_CATCH,symbol_value(VV[11]));
	if(nlj_active)
	{nlj_active=FALSE;frs_pop();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T43;}
	goto T69;}
	else{
	base[10]= symbol_value(VV[26]);
	base[11]= Cnil;
	base[12]= symbol_value(VV[27]);
	(VV[3]->s.s_dbind)= simple_symlispcall(VV[123],base+10,3);
	if(!(((VV[3]->s.s_dbind))==(symbol_value(VV[27])))){
	goto T76;}
	vs_base=vs_top;
	Lby();
	vs_top=sup;
T76:;
	{object V7;
	base[10]= (VV[3]->s.s_dbind);
	symlispcall(VV[124],base+10,1);
	Llist();
	vs_top=sup;
	V7= vs_base[0];
	(VV[9]->s.s_dbind)= (VV[8]->s.s_dbind);
	(VV[8]->s.s_dbind)= (VV[7]->s.s_dbind);
	(VV[7]->s.s_dbind)= (V7);
	(VV[6]->s.s_dbind)= (VV[5]->s.s_dbind);
	(VV[5]->s.s_dbind)= (VV[4]->s.s_dbind);
	(VV[4]->s.s_dbind)= car((VV[7]->s.s_dbind));
	vs_base=vs_top;
	Lfresh_line();
	vs_top=sup;
	{register object V8;
	register object V9;
	V8= (VV[7]->s.s_dbind);
	V9= car((V8));
T99:;
	if(!(endp((V8)))){
	goto T100;}
	goto T95;
T100:;
	base[11]= (V9);
	(void)simple_symlispcall(VV[125],base+11,1);
	princ_char(10,Cnil);
	V8= cdr((V8));
	V9= car((V8));
	goto T99;}
T95:;
	frs_pop();
	goto T43;}}
T69:;
	setq(VV[28],Cnil);
	setq(VV[29],Cnil);
	princ_char(10,VV[30]);
	vs_base=vs_top;
	(void) (*Lnk126)();
	vs_top=sup;
T43:;
	goto T42;
}
/*	function definition for DBL-READ	*/

static L2()
{register object *base=vs_base;
	register object *sup=base+VM2; VC2
	vs_reserve(VM2);
	{register object V10;
	register object V11;
	register object V12;
	if(vs_top-vs_base>3) too_many_arguments();
	if(vs_base>=vs_top){vs_top=sup;goto T118;}
	V10=(base[0]);
	vs_base++;
	if(vs_base>=vs_top){vs_top=sup;goto T119;}
	V11=(base[1]);
	vs_base++;
	if(vs_base>=vs_top){vs_top=sup;goto T120;}
	V12=(base[2]);
	vs_top=sup;
	goto T121;
T118:;
	V10= symbol_value(VV[26]);
T119:;
	V11= Ct;
T120:;
	V12= Cnil;
T121:;
	{object V13;
	register object V14;
	V13= Cnil;
	V14= Cnil;
T129:;
	base[3]= (V10);
	base[4]= (V11);
	base[5]= (V12);
	vs_top=(vs_base=base+3)+3;
	Lread_char();
	vs_top=sup;
	V14= vs_base[0];
	if(!(eql((V14),VV[31]))){
	goto T137;}
	goto T129;
T137:;
	if(!(((V14))==((V12)))){
	goto T135;}
	base[3]= (V12);
	vs_top=(vs_base=base+3)+1;
	return;
T135:;
	base[3]= (V14);
	base[4]= (V10);
	vs_top=(vs_base=base+3)+2;
	Lunread_char();
	vs_top=sup;
	goto T127;
T127:;
	if(!(eql(VV[32],(V14)))){
	goto T145;}
	base[3]= VV[33];
	base[5]= (V10);
	base[6]= (V11);
	base[7]= (V12);
	vs_top=(vs_base=base+5)+3;
	Lread_line();
	vs_top=sup;
	base[4]= vs_base[0];
	base[5]= VV[34];
	vs_top=(vs_base=base+3)+3;
	(void) (*Lnk121)();
	vs_top=sup;
	V13= vs_base[0];
	base[4]= (V13);
	vs_top=(vs_base=base+4)+1;
	(void) (*Lnk127)();
	vs_top=sup;
	base[3]= vs_base[0];
	base[4]= (V11);
	base[5]= (V12);
	vs_top=(vs_base=base+3)+3;
	Lread();
	return;
T145:;
	base[3]= (V10);
	base[4]= (V11);
	base[5]= (V12);
	vs_top=(vs_base=base+3)+3;
	Lread();
	return;}
	}
}
/*	function definition for BREAK-LEVEL	*/

static L3()
{register object *VOL base=vs_base;
	register object *VOL sup=base+VM3; VC3
	vs_reserve(VM3);
	bds_check;
	{VOL object V15;
	VOL object V16;
	if(vs_top-vs_base<1) too_few_arguments();
	if(vs_top-vs_base>2) too_many_arguments();
	V15=(base[0]);
	vs_base=vs_base+1;
	if(vs_base>=vs_top){vs_top=sup;goto T162;}
	V16=(base[1]);
	vs_top=sup;
	goto T163;
T162:;
	V16= Cnil;
T163:;
	{VOL object V17;
	if(!(type_of((V15))==t_string)){
	goto T167;}
	bds_bind(VV[35],(V15));
	goto T165;
T167:;
	bds_bind(VV[35],symbol_value(VV[35]));
T165:;
	V18= make_cons(symbol_value(VV[37]),symbol_value(VV[11]));
	bds_bind(VV[36],make_cons(/* INLINE-ARGS */V18,symbol_value(VV[36])));
	bds_bind(VV[11],make_cons(Cnil,Cnil));
	if(((V15))!=Cnil){
	goto T173;}
	bds_bind(VV[37],symbol_value(VV[37]));
	goto T171;
T173:;
	bds_bind(VV[37],make_cons(Ct,symbol_value(VV[37])));
T171:;
	bds_bind(VV[38],one_plus(symbol_value(VV[39])));
	vs_base=vs_top;
	(void) (*Lnk128)();
	vs_top=sup;
	V19= vs_base[0];
	bds_bind(VV[39],one_minus(V19));
	bds_bind(VV[40],(VV[39]->s.s_dbind));{VOL object V20;
	base[25]= symbol_value(VV[42]);
	base[26]= (VV[38]->s.s_dbind);
	vs_top=(vs_base=base+25)+2;
	(void) (*Lnk129)();
	vs_top=sup;
	V20= vs_base[0];
	if(V20==Cnil)goto T179;
	bds_bind(VV[41],V20);
	goto T178;
T179:;}
	vs_base=vs_top;
	(void) (*Lnk130)();
	vs_top=sup;
	V21= vs_base[0];
	bds_bind(VV[41],one_plus(V21));
T178:;
	vs_base=vs_top;
	(void) (*Lnk130)();
	vs_top=sup;
	bds_bind(VV[42],vs_base[0]);
	bds_bind(VV[43],Cnil);
	V17= symbol_value(VV[44]);
	if(!(type_of((V15))==t_string)){
	goto T188;}
	bds_bind(VV[44],Cnil);
	goto T186;
T188:;
	bds_bind(VV[44],(V17));
T186:;
	if(symbol_value(VV[46])!=Cnil){
	bds_bind(VV[45],symbol_value(VV[46]));
	goto T190;}
	bds_bind(VV[45],symbol_value(VV[45]));
T190:;
	bds_bind(VV[47],Cnil);
	bds_bind(VV[0],symbol_value(VV[0]));
	bds_bind(VV[1],symbol_value(VV[1]));
	bds_bind(VV[2],symbol_value(VV[2]));
	bds_bind(VV[3],symbol_value(VV[3]));
	bds_bind(VV[4],symbol_value(VV[4]));
	bds_bind(VV[5],symbol_value(VV[5]));
	bds_bind(VV[6],symbol_value(VV[6]));
	bds_bind(VV[7],symbol_value(VV[7]));
	bds_bind(VV[8],symbol_value(VV[8]));
	bds_bind(VV[9],symbol_value(VV[9]));
	if(((V17))!=Cnil){
	goto T191;}
	if(!(type_of((V15))==t_string)){
	goto T191;}
	vs_base=vs_top;
	(void) (*Lnk131)();
	vs_top=sup;
	base[25]= make_fixnum(length(cdr((VV[37]->s.s_dbind))));
	vs_top=(vs_base=base+25)+1;
	(void) (*Lnk132)();
	vs_top=sup;
T191:;
	base[25]= small_fixnum(1);
	vs_top=(vs_base=base+25)+1;
	(void) (*Lnk133)();
	vs_top=sup;
	setq(VV[48],Ct);
	if(!(type_of((V15))==t_string)){
	goto T204;}
	(void)((*(LnkLI134))());
	princ_char(10,VV[30]);
	setq(VV[21],Cnil);
	goto T202;
T204:;
	base[25]= (V15);
	base[26]= (V16);
	vs_top=(vs_base=base+25)+2;
	(void) (*Lnk135)();
	vs_top=sup;
T202:;
T212:;
	(VV[2]->s.s_dbind)= (VV[1]->s.s_dbind);
	(VV[1]->s.s_dbind)= (VV[0]->s.s_dbind);
	(VV[0]->s.s_dbind)= (VV[3]->s.s_dbind);
	if((symbol_value(VV[21]))==Cnil){
	goto T222;}
	setq(VV[21],Cnil);
	goto T220;
T222:;
	base[25]= symbol_value(VV[49]);
	base[26]= VV[50];
	if(!(type_of((V15))==t_string)){
	goto T229;}
	base[27]= VV[51];
	goto T227;
T229:;
	base[27]= VV[52];
T227:;{VOL object V22;
	V22= symbol_value(VV[23]);
	base[29]= VV[24];
	vs_top=(vs_base=base+29)+1;
	Lfind_package();
	vs_top=sup;
	V23= vs_base[0];
	if(!((V22)==(V23))){
	goto T233;}}
	base[28]= VV[53];
	goto T231;
T233:;
	base[29]= symbol_value(VV[23]);
	vs_top=(vs_base=base+29)+1;
	Lpackage_name();
	vs_top=sup;
	base[28]= vs_base[0];
T231:;
	base[29]= (VV[37]->s.s_dbind);
	vs_top=(vs_base=base+25)+5;
	Lformat();
	vs_top=sup;
T220:;
	frs_push(FRS_CATCH,VV[54]);
	if(nlj_active)
	{nlj_active=FALSE;frs_pop();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T213;}
	goto T240;}
	else{
	frs_push(FRS_CATCH,(VV[11]->s.s_dbind));
	if(nlj_active)
	{nlj_active=FALSE;frs_pop();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	frs_pop();
	goto T213;}
	frs_pop();
	goto T240;}
	else{
	base[25]= symbol_value(VV[49]);
	base[26]= Cnil;
	base[27]= symbol_value(VV[27]);
	vs_top=(vs_base=base+25)+3;
	(void) (*Lnk136)();
	vs_top=sup;
	(VV[3]->s.s_dbind)= vs_base[0];
	if(!(((VV[3]->s.s_dbind))==(symbol_value(VV[27])))){
	goto T248;}
	vs_base=vs_top;
	Lby();
	vs_top=sup;
T248:;
	{object V24;
	object V25;
	V24= Cnil;
	if(!((type_of((VV[3]->s.s_dbind))==t_symbol&&((VV[3]->s.s_dbind))->s.s_hpack==keyword_package))){
	goto T255;}
	(VV[3]->s.s_dbind)= make_cons((VV[3]->s.s_dbind),Cnil);
T255:;
	if(!(type_of((VV[3]->s.s_dbind))==t_cons)){
	goto T260;}
	{object V26= car((VV[3]->s.s_dbind));
	if(!((type_of(V26)==t_symbol&&(V26)->s.s_hpack==keyword_package))){
	goto T260;}}
	V24= Ct;
	base[26]= car((VV[3]->s.s_dbind));
	base[27]= cdr((VV[3]->s.s_dbind));
	symlispcall(VV[137],base+26,2);
	goto T254;
T260:;
	base[26]= (VV[3]->s.s_dbind);
	base[27]= Cnil;
	base[28]= Cnil;
	base[29]= (VV[43]->s.s_dbind);
	symlispcall(VV[138],base+26,4);
T254:;
	Llist();
	vs_top=sup;
	V25= vs_base[0];
	if((V24)==Cnil){
	goto T272;}
	if((car((V25)))==(VV[55])){
	goto T273;}
	goto T272;
T273:;
	frs_pop();
	frs_pop();
	base[26]= Cnil;
	vs_top=(vs_base=base+26)+1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	return;
T272:;
	(VV[9]->s.s_dbind)= (VV[8]->s.s_dbind);
	(VV[8]->s.s_dbind)= (VV[7]->s.s_dbind);
	(VV[7]->s.s_dbind)= (V25);
	(VV[6]->s.s_dbind)= (VV[5]->s.s_dbind);
	(VV[5]->s.s_dbind)= (VV[4]->s.s_dbind);
	(VV[4]->s.s_dbind)= car((VV[7]->s.s_dbind));
	base[26]= symbol_value(VV[49]);
	vs_top=(vs_base=base+26)+1;
	Lfresh_line();
	vs_top=sup;
	{register object V27;
	register object V28;
	V27= (VV[7]->s.s_dbind);
	V28= car((V27));
T292:;
	if(!(endp((V27)))){
	goto T293;}
	goto T251;
T293:;
	base[27]= (V28);
	base[28]= symbol_value(VV[49]);
	(void)simple_symlispcall(VV[125],base+27,2);
	princ_char(10,VV[49]);
	V27= cdr((V27));
	V28= car((V27));
	goto T292;}}
T251:;
	frs_pop();
	frs_pop();
	goto T213;}}
T240:;
	princ_char(10,VV[49]);
	vs_base=vs_top;
	(void) (*Lnk126)();
	vs_top=sup;
T213:;
	goto T212;}
	}
}
/*	local entry for function WARN	*/

static object LI4(V29,va_alist)
	object V29;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB4 VMS4 VMV4
	bds_check;
	{object V30;
	object V31;
	if(narg <1) too_few_arguments();
	V30= V29;
	narg= narg - 1;
	va_start(ap);
	V32 = list_vector(narg,ap);
	V31= V32;
	bds_bind(VV[56],small_fixnum(4));
	bds_bind(VV[57],small_fixnum(4));
	bds_bind(VV[58],VV[59]);
	if((symbol_value(VV[60]))==Cnil){
	goto T309;}
	base[3]= (V30);
	{object V33;
	V33= (V31);
	 vs_top=base+4;
	 while(!endp(V33))
	 {vs_push(car(V33));V33=cdr(V33);}
	vs_base=base+3;}
	(void) (*Lnk139)();
	vs_top=sup;
	{object V34 = vs_base[0];
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	VMR4(V34)}
T309:;
	base[3]= symbol_value(VV[30]);
	base[4]= VV[61];
	vs_top=(vs_base=base+3)+2;
	Lformat();
	vs_top=sup;
	bds_bind(VV[62],Ct);
	base[4]= symbol_value(VV[30]);
	base[5]= (V30);
	{object V35;
	V35= (V31);
	 vs_top=base+6;
	 while(!endp(V35))
	 {vs_push(car(V35));V35=cdr(V35);}
	vs_base=base+4;}
	Lformat();
	vs_top=sup;
	bds_unwind1;
	{object V36 = Cnil;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	VMR4(V36)}}
	}
/*	local entry for function UNIVERSAL-ERROR-HANDLER	*/

static object LI5(V41,V40,V39,V38,V37,va_alist)
	object V41,V40,V39,V38,V37;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB5 VMS5 VMV5
	bds_check;
	{object V42;
	object V43;
	register object V44;
	object V45;
	register object V46;
	register object V47;
	if(narg <5) too_few_arguments();
	V42= V41;
	V43= V40;
	V44= V39;
	V45= V38;
	V46= V37;
	narg= narg - 5;
	va_start(ap);
	V48 = list_vector(narg,ap);
	V47= V48;
	{object V49;
	V49= Cnil;
	bds_bind(VV[63],Cnil);
	bds_bind(VV[56],symbol_value(VV[64]));
	bds_bind(VV[57],symbol_value(VV[64]));
	bds_bind(VV[58],VV[59]);
	princ_char(10,VV[30]);
	if(((V43))==Cnil){
	goto T324;}
	if((symbol_value(VV[44]))==Cnil){
	goto T324;}
	base[4]= symbol_value(VV[30]);
	base[5]= VV[65];
	vs_top=(vs_base=base+4)+2;
	Lformat();
	vs_top=sup;
	bds_bind(VV[62],Ct);
	base[5]= symbol_value(VV[30]);
	base[6]= (V46);
	{object V50;
	V50= (V47);
	 vs_top=base+7;
	 while(!endp(V50))
	 {vs_push(car(V50));V50=cdr(V50);}
	vs_base=base+5;}
	Lformat();
	vs_top=sup;
	bds_unwind1;
	princ_char(10,VV[30]);
	base[4]= Cnil;
	base[5]= (V46);
	{object V51;
	V51= (V47);
	 vs_top=base+6;
	 while(!endp(V51))
	 {vs_push(car(V51));V51=cdr(V51);}
	vs_base=base+4;}
	Lformat();
	vs_top=sup;
	V49= vs_base[0];
	if(((V44))==Cnil){
	goto T343;}
	base[4]= symbol_value(VV[30]);
	base[5]= VV[66];
	base[6]= (V44);
	vs_top=(vs_base=base+4)+3;
	Lformat();
	vs_top=sup;
	goto T341;
T343:;
	base[4]= symbol_value(VV[30]);
	base[5]= VV[67];
	vs_top=(vs_base=base+4)+2;
	Lformat();
	vs_top=sup;
T341:;
	base[4]= symbol_value(VV[30]);
	base[5]= VV[68];
	vs_top=(vs_base=base+4)+2;
	Lformat();
	vs_top=sup;
	bds_bind(VV[62],Ct);
	base[5]= symbol_value(VV[30]);
	base[6]= VV[69];
	base[7]= (V45);
	base[8]= (V47);
	vs_top=(vs_base=base+5)+4;
	Lformat();
	vs_top=sup;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	goto T321;
T324:;
	base[4]= symbol_value(VV[30]);
	base[5]= VV[70];
	vs_top=(vs_base=base+4)+2;
	Lformat();
	vs_top=sup;
	bds_bind(VV[62],Ct);
	base[5]= symbol_value(VV[30]);
	base[6]= (V46);
	{object V52;
	V52= (V47);
	 vs_top=base+7;
	 while(!endp(V52))
	 {vs_push(car(V52));V52=cdr(V52);}
	vs_base=base+5;}
	Lformat();
	vs_top=sup;
	bds_unwind1;
	princ_char(10,VV[30]);
	if(!((length(symbol_value(VV[71])))>(0))){
	goto T365;}
	base[4]= symbol_value(VV[30]);
	base[5]= VV[72];
	vs_top=(vs_base=base+4)+2;
	Lformat();
	vs_top=sup;
T365:;
	base[4]= Cnil;
	base[5]= (V46);
	{object V53;
	V53= (V47);
	 vs_top=base+6;
	 while(!endp(V53))
	 {vs_push(car(V53));V53=cdr(V53);}
	vs_base=base+4;}
	Lformat();
	vs_top=sup;
	V49= vs_base[0];
	if(((V44))==Cnil){
	goto T376;}
	base[4]= symbol_value(VV[30]);
	base[5]= VV[73];
	base[6]= (V44);
	vs_top=(vs_base=base+4)+3;
	Lformat();
	vs_top=sup;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	goto T321;
T376:;
	base[4]= symbol_value(VV[30]);
	base[5]= VV[74];
	vs_top=(vs_base=base+4)+2;
	Lformat();
	vs_top=sup;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
T321:;
	base[0]= (V49);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk140)();
	vs_top=sup;
	if(((V43))!=Cnil){
	goto T386;}
	{frame_ptr fr;
	fr=frs_sch_catch(symbol_value(VV[11]));
	if(fr==NULL) FEerror("The tag ~s is undefined.",1,symbol_value(VV[11]));
	base[0]= symbol_value(VV[11]);
	vs_top=(vs_base=base+0)+1;
	unwind(fr,symbol_value(VV[11]));}
T386:;
	{object V54 = Cnil;
	VMR5(V54)}}}
	}
/*	local entry for function BREAK	*/

static object LI6(va_alist)
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB6 VMS6 VMV6
	bds_check;
	{object V55;
	object V56;
	narg = narg - 0;
	if (narg <= 0) goto T389;
	else {
	va_start(ap);
	V55= va_arg(ap,object);}
	--narg; goto T390;
T389:;
	V55= Cnil;
T390:;
	V57 = list_vector(narg,ap);
	V56= V57;
	{object V58;
	V58= Cnil;
	bds_bind(VV[63],Cnil);
	bds_bind(VV[56],small_fixnum(4));
	bds_bind(VV[57],small_fixnum(4));
	bds_bind(VV[58],VV[59]);
	princ_char(10,VV[30]);
	if(((V55))==Cnil){
	goto T396;}
	base[4]= symbol_value(VV[30]);
	base[5]= VV[75];
	vs_top=(vs_base=base+4)+2;
	Lformat();
	vs_top=sup;
	bds_bind(VV[62],Ct);
	base[5]= symbol_value(VV[30]);
	base[6]= (V55);
	{object V59;
	V59= (V56);
	 vs_top=base+7;
	 while(!endp(V59))
	 {vs_push(car(V59));V59=cdr(V59);}
	vs_base=base+5;}
	Lformat();
	vs_top=sup;
	bds_unwind1;
	princ_char(10,VV[30]);
	base[4]= Cnil;
	base[5]= (V55);
	{object V60;
	V60= (V56);
	 vs_top=base+6;
	 while(!endp(V60))
	 {vs_push(car(V60));V60=cdr(V60);}
	vs_base=base+4;}
	Lformat();
	vs_top=sup;
	V58= vs_base[0];
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	goto T393;
T396:;
	base[4]= symbol_value(VV[30]);
	base[5]= VV[76];
	vs_top=(vs_base=base+4)+2;
	Lformat();
	vs_top=sup;
	V58= VV[77];
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
T393:;
	bds_bind(VV[44],Ct);
	base[1]= (V58);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk140)();
	vs_top=sup;
	bds_unwind1;
	{object V61 = Cnil;
	VMR6(V61)}}}
	}
/*	local entry for function TERMINAL-INTERRUPT	*/

static object LI7(V63)

object V63;
{	 VMB7 VMS7 VMV7
	bds_check;
TTL:;
	bds_bind(VV[44],Ct);
	if(((V63))==Cnil){
	goto T417;}
	base[1]= VV[78];
	base[2]= VV[79];
	vs_top=(vs_base=base+1)+2;
	Lcerror();
	vs_top=sup;
	{object V64 = vs_base[0];
	bds_unwind1;
	VMR7(V64)}
T417:;
	base[1]= VV[80];
	vs_top=(vs_base=base+1)+1;
	Lerror();
	vs_top=sup;
	{object V65 = vs_base[0];
	bds_unwind1;
	VMR7(V65)}
}
/*	local entry for function BREAK-CALL	*/

static object LI8(V68,V69)

object V68;object V69;
{	 VMB8 VMS8 VMV8
TTL:;
	{object V70;
	V70= get((V68),VV[81],Cnil);
	if(((V70))==Cnil){
	goto T424;}
	base[1]= make_cons((V70),(V69));
	base[2]= Cnil;
	base[3]= Cnil;
	base[4]= symbol_value(VV[43]);
	vs_top=(vs_base=base+1)+4;
	Levalhook();
	vs_top=sup;
	{object V71 = vs_base[0];
	VMR8(V71)}
T424:;
	base[1]= symbol_value(VV[49]);
	base[2]= VV[82];
	base[3]= (V68);
	vs_top=(vs_base=base+1)+3;
	Lformat();
	vs_top=sup;
	{object V72 = vs_base[0];
	VMR8(V72)}}
}
/*	function definition for BREAK-QUIT	*/

static L9()
{register object *base=vs_base;
	register object *sup=base+VM9; VC9
	vs_reserve(VM9);
	{object V73;
	if(vs_top-vs_base>1) too_many_arguments();
	if(vs_base>=vs_top){vs_top=sup;goto T433;}
	V73=(base[0]);
	vs_top=sup;
	goto T434;
T433:;
	V73= small_fixnum(0);
T434:;
	{object V74;
	V74= make_fixnum(length(symbol_value(VV[37])));
	if(!(number_compare((V73),small_fixnum(0))>=0)){
	goto T437;}
	if(!(number_compare((V73),(V74))<0)){
	goto T437;}
	{object V75;
	base[2]= (V74);
	base[3]= (V73);
	base[4]= small_fixnum(1);
	vs_top=(vs_base=base+2)+3;
	Lminus();
	vs_top=sup;
	V76= vs_base[0];
	V75= nth(fixint(V76),symbol_value(VV[36]));
	{frame_ptr fr;
	base[2]= cdr((V75));
	fr=frs_sch_catch(base[2]);
	if(fr==NULL) FEerror("The tag ~s is undefined.",1,base[2]);
	base[3]= cdr((V75));
	vs_top=(vs_base=base+3)+1;
	unwind(fr,base[2]);}}
T437:;
	vs_base=vs_top;
	(void) (*Lnk126)();
	return;}
	}
}
/*	function definition for BREAK-PREVIOUS	*/

static L10()
{register object *base=vs_base;
	register object *sup=base+VM10; VC10
	vs_reserve(VM10);
	{register object V77;
	if(vs_top-vs_base>1) too_many_arguments();
	if(vs_base>=vs_top){vs_top=sup;goto T449;}
	V77=(base[0]);
	vs_top=sup;
	goto T450;
T449:;
	V77= small_fixnum(1);
T450:;
	{register object V78;
	V78= one_minus(symbol_value(VV[40]));
T454:;
	if(number_compare((V78),symbol_value(VV[38]))<0){
	goto T456;}
	if(!(number_compare((V77),small_fixnum(0))<=0)){
	goto T455;}
T456:;
	(void)((*(LnkLI141))());
	vs_base=vs_top;
	(void) (*Lnk126)();
	return;
T455:;
	if(((*(LnkLI142))((V78)))==Cnil){
	goto T462;}
	setq(VV[40],(V78));
	V77= one_minus((V77));
T462:;
	V78= one_minus((V78));
	goto T454;}
	}
}
/*	local entry for function SET-CURRENT	*/

static object LI11()

{	 VMB11 VMS11 VMV11
TTL:;
	{register object V79;
	V79= symbol_value(VV[40]);
T472:;
	if(((*(LnkLI142))((V79)))!=Cnil){
	goto T474;}
	if(!(number_compare((V79),symbol_value(VV[38]))<=0)){
	goto T473;}
T474:;
	setq(VV[40],(V79));
	(void)((*(LnkLI141))());
	base[0]= symbol_value(VV[49]);
	base[1]= VV[83];
	base[3]= symbol_value(VV[40]);
	vs_top=(vs_base=base+3)+1;
	(void) (*Lnk143)();
	vs_top=sup;
	base[2]= vs_base[0];
	base[3]= cdr(symbol_value(VV[37]));
	vs_top=(vs_base=base+0)+4;
	Lformat();
	vs_top=sup;
	{object V80 = vs_base[0];
	VMR11(V80)}
T473:;
	V79= one_minus((V79));
	goto T472;}
}
/*	function definition for BREAK-NEXT	*/

static L12()
{register object *base=vs_base;
	register object *sup=base+VM12; VC12
	vs_reserve(VM12);
	{register object V81;
	if(vs_top-vs_base>1) too_many_arguments();
	if(vs_base>=vs_top){vs_top=sup;goto T490;}
	V81=(base[0]);
	vs_top=sup;
	goto T491;
T490:;
	V81= small_fixnum(1);
T491:;
	{register object V82;
	V82= symbol_value(VV[40]);
T494:;
	if(number_compare((V82),symbol_value(VV[39]))>0){
	goto T496;}
	if(!(number_compare((V81),small_fixnum(0))<0)){
	goto T495;}
T496:;
	(void)((*(LnkLI141))());
	vs_base=vs_top;
	(void) (*Lnk126)();
	return;
T495:;
	if(((*(LnkLI142))((V82)))==Cnil){
	goto T502;}
	setq(VV[40],(V82));
	V81= one_minus((V81));
T502:;
	V82= one_plus((V82));
	goto T494;}
	}
}
/*	function definition for BREAK-GO	*/

static L13()
{register object *base=vs_base;
	register object *sup=base+VM13; VC13
	vs_reserve(VM13);
	{object V83;
	check_arg(1);
	V83=(base[0]);
	vs_top=sup;
TTL:;
	{object V84= (number_compare((V83),symbol_value(VV[38]))>=0?((V83)):symbol_value(VV[38]));
	setq(VV[40],(number_compare(V84,symbol_value(VV[39]))<=0?(V84):symbol_value(VV[39])));}
	if(((*(LnkLI142))(symbol_value(VV[40])))==Cnil){
	goto T514;}
	(void)((*(LnkLI141))());
	vs_base=vs_top;
	(void) (*Lnk126)();
	return;
T514:;
	vs_base=vs_top;
	(void) (*Lnk144)();
	return;
	}
}
/*	function definition for BREAK-MESSAGE	*/

static L14()
{register object *base=vs_base;
	register object *sup=base+VM14; VC14
	vs_reserve(VM14);
	check_arg(0);
	vs_top=sup;
TTL:;
	(void)(princ(symbol_value(VV[35]),symbol_value(VV[49])));
	princ_char(10,VV[49]);
	vs_base=vs_top=base+0;
	vs_base[0]=Cnil;
	return;
}
/*	function definition for DESCRIBE-ENVIRONMENT	*/

static L15()
{register object *base=vs_base;
	register object *sup=base+VM15; VC15
	vs_reserve(VM15);
	{object V85;
	register object V86;
	if(vs_top-vs_base>2) too_many_arguments();
	if(vs_base>=vs_top){vs_top=sup;goto T519;}
	V85=(base[0]);
	vs_base++;
	if(vs_base>=vs_top){vs_top=sup;goto T520;}
	V86=(base[1]);
	vs_top=sup;
	goto T521;
T519:;
	V85= symbol_value(VV[43]);
T520:;
	V86= symbol_value(VV[49]);
T521:;
	if(!((length((V85)))==(3))){
	goto T525;}
	goto T524;
T525:;
	base[2]= VV[84];
	vs_top=(vs_base=base+2)+1;
	Lerror();
	vs_top=sup;
T524:;
	{register object V87;
	V87= VV[85];
	base[2]= (V86);
	base[3]= (V87);
	base[4]= VV[86];
	{object V88;
	{object V89;
	object V90= car(symbol_value(VV[43]));
	if(endp(V90)){
	V88= Cnil;
	goto T532;}
	base[5]=V89=MMcons(Cnil,Cnil);
T533:;
	(V89->c.c_car)= car((V90->c.c_car));
	if(endp(V90=MMcdr(V90))){
	V88= base[5];
	goto T532;}
	V89=MMcdr(V89)=MMcons(Cnil,Cnil);
	goto T533;}
T532:;
	 vs_top=base+5;
	 while(!endp(V88))
	 {vs_push(car(V88));V88=cdr(V88);}
	vs_base=base+2;}
	Lformat();
	vs_top=sup;
	base[2]= (V86);
	base[3]= (V87);
	base[4]= VV[87];
	{object V91;
	{object V92;
	object V93= cadr(symbol_value(VV[43]));
	if(endp(V93)){
	V91= Cnil;
	goto T539;}
	base[5]=V92=MMcons(Cnil,Cnil);
T540:;
	(V92->c.c_car)= car((V93->c.c_car));
	if(endp(V93=MMcdr(V93))){
	V91= base[5];
	goto T539;}
	V92=MMcdr(V92)=MMcons(Cnil,Cnil);
	goto T540;}
T539:;
	 vs_top=base+5;
	 while(!endp(V91))
	 {vs_push(car(V91));V91=cdr(V91);}
	vs_base=base+2;}
	Lformat();
	vs_top=sup;
	base[2]= (V86);
	base[3]= (V87);
	base[4]= VV[88];
	{object V94;
	{object V95;
	object V96= caddr(symbol_value(VV[43]));
	if(endp(V96)){
	V94= Cnil;
	goto T546;}
	base[5]=V95=MMcons(Cnil,Cnil);
T547:;
	if(!((cadr((V96->c.c_car)))==(VV[89]))){
	goto T550;}
	(V95->c.c_cdr)= make_cons(car((V96->c.c_car)),Cnil);
	goto T548;
T550:;
	(V95->c.c_cdr)= Cnil;
T548:;
	while(!endp(MMcdr(V95)))V95=MMcdr(V95);
	if(endp(V96=MMcdr(V96))){
	base[5]=base[5]->c.c_cdr;
	V94= base[5];
	goto T546;}
	goto T547;}
T546:;
	 vs_top=base+5;
	 while(!endp(V94))
	 {vs_push(car(V94));V94=cdr(V94);}
	vs_base=base+2;}
	Lformat();
	vs_top=sup;
	base[2]= (V86);
	base[3]= (V87);
	base[4]= VV[90];
	{object V98;
	{object V99;
	object V100= caddr(symbol_value(VV[43]));
	if(endp(V100)){
	V98= Cnil;
	goto T555;}
	base[5]=V99=MMcons(Cnil,Cnil);
T556:;
	if(!((cadr((V100->c.c_car)))==(VV[91]))){
	goto T559;}
	(V99->c.c_cdr)= make_cons(car((V100->c.c_car)),Cnil);
	goto T557;
T559:;
	(V99->c.c_cdr)= Cnil;
T557:;
	while(!endp(MMcdr(V99)))V99=MMcdr(V99);
	if(endp(V100=MMcdr(V100))){
	base[5]=base[5]->c.c_cdr;
	V98= base[5];
	goto T555;}
	goto T556;}
T555:;
	 vs_top=base+5;
	 while(!endp(V98))
	 {vs_push(car(V98));V98=cdr(V98);}
	vs_base=base+2;}
	Lformat();
	return;}
	}
}
/*	function definition for BREAK-VS	*/

static L16()
{register object *base=vs_base;
	register object *sup=base+VM16; VC16
	vs_reserve(VM16);
	{register object V102;
	object V103;
	if(vs_top-vs_base>2) too_many_arguments();
	if(vs_base>=vs_top){vs_top=sup;goto T561;}
	V102=(base[0]);
	vs_base++;
	if(vs_base>=vs_top){vs_top=sup;goto T562;}
	V103=(base[1]);
	vs_top=sup;
	goto T563;
T561:;
	base[2]= symbol_value(VV[38]);
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk145)();
	vs_top=sup;
	V102= vs_base[0];
T562:;
	base[2]= symbol_value(VV[39]);
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk145)();
	vs_top=sup;
	V103= vs_base[0];
T563:;
	base[2]= symbol_value(VV[38]);
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk145)();
	vs_top=sup;
	V104= vs_base[0];
	V102= (number_compare((V102),V104)>=0?((V102)):V104);
	base[2]= one_plus(symbol_value(VV[39]));
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk145)();
	vs_top=sup;
	V105= vs_base[0];
	V106= one_minus(V105);
	V103= (number_compare((V103),/* INLINE-ARGS */V106)<=0?((V103)):/* INLINE-ARGS */V106);
	{register object V107;
	V107= symbol_value(VV[38]);
T577:;
	if(number_compare((V107),symbol_value(VV[39]))>=0){
	goto T579;}
	base[2]= (V107);
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk145)();
	vs_top=sup;
	V108= vs_base[0];
	if(!(number_compare(V108,(V102))>=0)){
	goto T578;}
T579:;
	{register object V109;
	V109= (V102);
T586:;
	if(!(number_compare((V109),(V103))>0)){
	goto T587;}
	vs_base=vs_top=base+2;
	vs_base[0]=Cnil;
	return;
T587:;
T593:;
	base[2]= (V107);
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk145)();
	vs_top=sup;
	V110= vs_base[0];
	if(!(number_compare(V110,(V109))>0)){
	goto T594;}
	goto T591;
T594:;
	if(((*(LnkLI142))((V107)))==Cnil){
	goto T600;}
	(void)((*(LnkLI146))((V107)));
T600:;
	V107= number_plus((V107),small_fixnum(1));
	goto T593;
T591:;
	base[2]= symbol_value(VV[49]);
	base[3]= VV[92];
	base[4]= (V109);
	base[6]= (V109);
	vs_top=(vs_base=base+6)+1;
	(void) (*Lnk147)();
	vs_top=sup;
	base[5]= vs_base[0];
	vs_top=(vs_base=base+2)+4;
	Lformat();
	vs_top=sup;
	V109= one_plus((V109));
	goto T586;}
T578:;
	V107= one_plus((V107));
	goto T577;}
	}
}
/*	function definition for BREAK-LOCAL	*/

static L17()
{register object *base=vs_base;
	register object *sup=base+VM17; VC17
	vs_reserve(VM17);
	{object V111;
	if(vs_top-vs_base>1) too_many_arguments();
	if(vs_base>=vs_top){vs_top=sup;goto T620;}
	V111=(base[0]);
	vs_top=sup;
	goto T621;
T620:;
	V111= small_fixnum(0);
T621:;
	{object V112;
	base[2]= symbol_value(VV[40]);
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk145)();
	vs_top=sup;
	V113= vs_base[0];
	V112= number_plus(V113,(V111));
	base[2]= (V112);
	base[3]= (V112);
	vs_top=(vs_base=base+2)+2;
	(void) (*Lnk148)();
	return;}
	}
}
/*	function definition for BREAK-BDS	*/

static L18()
{register object *base=vs_base;
	register object *sup=base+VM18; VC18
	vs_reserve(VM18);
	{register object V114;
	vs_top[0]=Cnil;
	{object *p=vs_top;
	 for(;p>vs_base;p--)p[-1]=MMcons(p[-1],p[0]);}
	V114=(base[0]);
	vs_top=sup;
	{register object V115;
	V115= symbol_value(VV[41]);
	{register object V116;
	register object V117;
	base[1]= one_minus(symbol_value(VV[41]));
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk149)();
	vs_top=sup;
	V118= vs_base[0];
	V116= one_plus(V118);
	base[1]= one_plus(symbol_value(VV[42]));
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk149)();
	vs_top=sup;
	V117= vs_base[0];
T635:;
	if(!(number_compare((V116),(V117))>0)){
	goto T636;}
	vs_base=vs_top=base+1;
	vs_base[0]=Cnil;
	return;
T636:;
	if(((V114))==Cnil){
	goto T641;}
	base[1]= (V116);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk150)();
	vs_top=sup;
	V120= vs_base[0];
	{register object x= V120,V119= (V114);
	while(!endp(V119))
	if(eql(x,V119->c.c_car)){
	goto T644;
	}else V119=V119->c.c_cdr;
	goto T640;}
T644:;
T641:;
T649:;
	if(number_compare((V115),symbol_value(VV[42]))>0){
	goto T651;}
	base[1]= (V115);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk149)();
	vs_top=sup;
	V121= vs_base[0];
	if(!(number_compare(V121,(V116))>0)){
	goto T650;}
T651:;
	goto T647;
T650:;
	(void)((*(LnkLI151))((V115)));
	V115= number_plus((V115),small_fixnum(1));
	goto T649;
T647:;
	base[1]= symbol_value(VV[49]);
	base[2]= VV[93];
	base[3]= (V116);
	base[5]= (V116);
	vs_top=(vs_base=base+5)+1;
	(void) (*Lnk150)();
	vs_top=sup;
	base[4]= vs_base[0];
	base[6]= (V116);
	vs_top=(vs_base=base+6)+1;
	(void) (*Lnk152)();
	vs_top=sup;
	base[5]= vs_base[0];
	vs_top=(vs_base=base+1)+5;
	Lformat();
	vs_top=sup;
T640:;
	V116= one_plus((V116));
	goto T635;}}
	}
}
/*	function definition for SIMPLE-BACKTRACE	*/

static L19()
{register object *base=vs_base;
	register object *sup=base+VM19; VC19
	vs_reserve(VM19);
	check_arg(0);
	vs_top=sup;
TTL:;
	princ_str("Backtrace: ",VV[49]);
	{register object V122;
	register object V123;
	V122= symbol_value(VV[38]);
	V123= Cnil;
T677:;
	if(!(number_compare((V122),symbol_value(VV[39]))>0)){
	goto T678;}
	princ_char(10,VV[49]);
	vs_base=vs_top=base+0;
	vs_base[0]=Cnil;
	return;
T678:;
	if(((*(LnkLI142))((V122)))==Cnil){
	goto T683;}
	if(((V123))==Cnil){
	goto T686;}
	princ_str(" > ",VV[49]);
T686:;
	base[1]= (V122);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk143)();
	vs_top=sup;
	base[0]= vs_base[0];
	base[1]= VV[94];
	base[2]= symbol_value(VV[49]);
	base[3]= VV[95];
	base[4]= Ct;
	base[5]= VV[96];
	if(!(number_compare((V122),symbol_value(VV[40]))==0)){
	goto T698;}
	base[6]= VV[59];
	goto T696;
T698:;
	base[6]= VV[97];
T696:;
	vs_top=(vs_base=base+0)+7;
	Lwrite();
	vs_top=sup;
T683:;
	V122= one_plus((V122));
	V123= Ct;
	goto T677;}
}
/*	function definition for IHS-BACKTRACE	*/

static L20()
{register object *base=vs_base;
	register object *sup=base+VM20; VC20
	vs_reserve(VM20);
	{object V124;
	register object V125;
	if(vs_top-vs_base>2) too_many_arguments();
	if(vs_base>=vs_top){vs_top=sup;goto T705;}
	V124=(base[0]);
	vs_base++;
	if(vs_base>=vs_top){vs_top=sup;goto T706;}
	V125=(base[1]);
	vs_top=sup;
	goto T707;
T705:;
	V124= symbol_value(VV[38]);
T706:;
	V125= symbol_value(VV[39]);
T707:;
	V124= (number_compare((V124),symbol_value(VV[38]))>=0?((V124)):symbol_value(VV[38]));
	V125= (number_compare((V125),symbol_value(VV[39]))<=0?((V125)):symbol_value(VV[39]));
	{register object V126;
	register object V127;
	V126= (V124);{object V128;
	base[3]= symbol_value(VV[41]);
	base[4]= (V124);
	vs_top=(vs_base=base+3)+2;
	(void) (*Lnk129)();
	vs_top=sup;
	V128= vs_base[0];
	if(V128==Cnil)goto T716;
	V127= V128;
	goto T715;
T716:;}
	V127= one_plus(symbol_value(VV[42]));
T715:;
T721:;
	if(!(number_compare((V126),(V125))>0)){
	goto T722;}
	vs_base=vs_top=base+3;
	vs_base[0]=Cnil;
	return;
T722:;
	if(((*(LnkLI142))((V126)))==Cnil){
	goto T726;}
	(void)((*(LnkLI146))((V126)));
T726:;
T731:;
	if(number_compare((V127),symbol_value(VV[42]))>0){
	goto T733;}
	base[3]= (V127);
	vs_top=(vs_base=base+3)+1;
	(void) (*Lnk153)();
	vs_top=sup;
	V129= vs_base[0];
	if(!(number_compare(V129,(V126))>0)){
	goto T732;}
T733:;
	goto T729;
T732:;
	(void)((*(LnkLI151))((V127)));
	V127= number_plus((V127),small_fixnum(1));
	goto T731;
T729:;
	V126= one_plus((V126));
	goto T721;}
	}
}
/*	local entry for function PRINT-IHS	*/

static object LI21(V131)

register object V131;
{	 VMB21 VMS21 VMV21
	bds_check;
TTL:;
	bds_bind(VV[56],small_fixnum(2));
	bds_bind(VV[57],small_fixnum(4));
	base[2]= Ct;
	base[3]= VV[98];
	base[4]= (number_compare((V131),symbol_value(VV[40]))==0?Ct:Cnil);
	base[5]= (V131);
	{register object V132;
	base[7]= (V131);
	vs_top=(vs_base=base+7)+1;
	(void) (*Lnk154)();
	vs_top=sup;
	V132= vs_base[0];
	if(type_of((V132))==t_symbol){
	goto T755;}
	base[7]= (V132);
	vs_top=(vs_base=base+7)+1;
	Lcompiled_function_p();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T756;}
T755:;
	base[6]= (V132);
	goto T752;
T756:;
	if(!(type_of((V132))==t_cons)){
	goto T762;}
	{object V133= car((V132));
	if((V133!= VV[99]))goto T764;
	base[6]= (V132);
	goto T752;
T764:;
	if((V133!= VV[155])
	&& (V133!= VV[156]))goto T765;
	base[6]= cdr((V132));
	goto T752;
T765:;
	if((V133!= VV[116]))goto T766;
	base[6]= make_cons(VV[99],cddddr((V132)));
	goto T752;
T766:;
	if((V133!= VV[157]))goto T767;
	base[6]= cddddr((V132));
	goto T752;
T767:;
	if(!(type_of(car((V132)))==t_symbol)){
	goto T769;}
	base[7]= car((V132));
	vs_top=(vs_base=base+7)+1;
	Lspecial_form_p();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T768;}
	base[7]= car((V132));
	vs_top=(vs_base=base+7)+1;
	Lfboundp();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T769;}
T768:;
	base[6]= car((V132));
	goto T752;
T769:;
	base[6]= VV[100];
	goto T752;}
T762:;
	(void)(print((V132),Cnil));
	base[6]= VV[101];}
T752:;
	base[8]= (V131);
	vs_top=(vs_base=base+8)+1;
	(void) (*Lnk145)();
	vs_top=sup;
	base[7]= vs_base[0];
	vs_top=(vs_base=base+2)+6;
	Lformat();
	vs_top=sup;
	{object V134 = vs_base[0];
	bds_unwind1;
	bds_unwind1;
	VMR21(V134)}
}
/*	local entry for function PRINT-FRS	*/

static object LI22(V136)

register object V136;
{	 VMB22 VMS22 VMV22
TTL:;
	base[0]= symbol_value(VV[49]);
	base[1]= VV[102];
	base[2]= (V136);
	base[3]= (*(LnkLI158))((V136));
	base[5]= (V136);
	vs_top=(vs_base=base+5)+1;
	(void) (*Lnk153)();
	vs_top=sup;
	base[4]= vs_base[0];
	base[6]= (V136);
	vs_top=(vs_base=base+6)+1;
	(void) (*Lnk159)();
	vs_top=sup;
	base[5]= vs_base[0];
	base[7]= (V136);
	vs_top=(vs_base=base+7)+1;
	(void) (*Lnk149)();
	vs_top=sup;
	base[6]= vs_base[0];
	vs_top=(vs_base=base+0)+7;
	Lformat();
	vs_top=sup;
	{object V137 = vs_base[0];
	VMR22(V137)}
}
/*	local entry for function FRS-KIND	*/

static object LI23(V139)

register object V139;
{	 VMB23 VMS23 VMV23
TTL:;
	{register object V140;
	V140= Cnil;
	base[0]= (V139);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk160)();
	vs_top=sup;
	V142= vs_base[0];
	{object V141= V142;
	if((V141!= VV[161]))goto T793;
	base[1]= (V139);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk162)();
	vs_top=sup;
	base[0]= vs_base[0];
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk163)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T795;}{object V143;
	base[1]= (V139);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk162)();
	vs_top=sup;
	base[0]= vs_base[0];
	base[3]= (V139);
	vs_top=(vs_base=base+3)+1;
	(void) (*Lnk159)();
	vs_top=sup;
	V144= vs_base[0];
	base[2]= number_plus(V144,small_fixnum(2));
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk147)();
	vs_top=sup;
	base[1]= vs_base[0];
	base[2]= VV[103];
	base[3]= symbol_function(VV[164]);
	base[4]= VV[104];
	base[5]= symbol_function(VV[165]);
	vs_top=(vs_base=base+0)+6;
	Lmember();
	vs_top=sup;
	V140= vs_base[0];
	if(((V140))!=Cnil){
	goto T801;}
	V143= Cnil;
	goto T800;
T801:;
	if(!((cadar((V140)))==(VV[89]))){
	goto T815;}
	V143= list(3,VV[89],caar((V140)),VV[6]);
	goto T800;
T815:;
	base[1]= (V139);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk162)();
	vs_top=sup;
	V148= vs_base[0];
	V149= symbol_function(VV[165]);
	V150= symbol_function(VV[164]);
	V151= (VFUN_NARGS=6,(*(LnkLI166))(V148,(V140),VV[106],V149,VV[103],V150));
	{object V146;
	object V147= /* INLINE-ARGS */V151;
	if(endp(V147)){
	V145= Cnil;
	goto T817;}
	base[0]=V146=MMcons(Cnil,Cnil);
T818:;
	(V146->c.c_car)= car((V147->c.c_car));
	if(endp(V147=MMcdr(V147))){
	V145= base[0];
	goto T817;}
	V146=MMcdr(V146)=MMcons(Cnil,Cnil);
	goto T818;}
T817:;
	V152= reverse(V145);
	V153= append(/* INLINE-ARGS */V152,VV[107]);
	V143= make_cons(VV[105],/* INLINE-ARGS */V153);
T800:;
	if(V143==Cnil)goto T799;
	{object V154 = V143;
	VMR23(V154)}
T799:;}
	base[0]= (V139);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk162)();
	vs_top=sup;
	V155= vs_base[0];
	{object V156 = list(2,VV[108],V155);
	VMR23(V156)}
T795:;
	base[0]= (V139);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk162)();
	vs_top=sup;
	V157= vs_base[0];
	{object V158 = list(3,VV[109],list(2,VV[110],V157),VV[6]);
	VMR23(V158)}
T793:;
	if((V141!= VV[167]))goto T828;
	{object V159 = VV[111];
	VMR23(V159)}
T828:;
	base[0]= (V139);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk162)();
	vs_top=sup;
	V160= vs_base[0];
	{object V161 = list(2,VV[112],V160);
	VMR23(V161)}}}
}
/*	function definition for BREAK-CURRENT	*/

static L24()
{register object *base=vs_base;
	register object *sup=base+VM24; VC24
	vs_reserve(VM24);
	check_arg(0);
	vs_top=sup;
TTL:;
	if((symbol_value(VV[37]))==Cnil){
	goto T833;}
	base[0]= symbol_value(VV[49]);
	base[1]= VV[113];
	base[3]= symbol_value(VV[40]);
	vs_top=(vs_base=base+3)+1;
	(void) (*Lnk143)();
	vs_top=sup;
	base[2]= vs_base[0];
	vs_top=(vs_base=base+0)+3;
	Lformat();
	vs_top=sup;
	goto T831;
T833:;
	base[0]= symbol_value(VV[49]);
	base[1]= VV[114];
	vs_top=(vs_base=base+0)+2;
	Lformat();
	vs_top=sup;
T831:;
	vs_base=vs_top=base+0;
	vs_base[0]=Cnil;
	return;
}
/*	local entry for function IHS-VISIBLE	*/

static object LI25(V163)

object V163;
{	 VMB25 VMS25 VMV25
TTL:;
	{object V164;
	base[1]= (V163);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk143)();
	vs_top=sup;
	V164= vs_base[0];
	if((V164)==Cnil){
	{object V165 = Cnil;
	VMR25(V165)}}
	{register object x= (V164),V167= symbol_value(VV[115]);
	while(!endp(V167))
	if(eql(x,V167->c.c_car)){
	V166= V167;
	goto T843;
	}else V167=V167->c.c_cdr;
	V166= Cnil;}
T843:;
	{object V168 = ((V166)==Cnil?Ct:Cnil);
	VMR25(V168)}}
}
/*	function definition for IHS-FNAME	*/

static L26()
{register object *base=vs_base;
	register object *sup=base+VM26; VC26
	vs_reserve(VM26);
	{object V169;
	check_arg(1);
	V169=(base[0]);
	vs_top=sup;
TTL:;
	{register object V170;
	base[1]= (V169);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk154)();
	vs_top=sup;
	V170= vs_base[0];
	if(!(type_of((V170))==t_symbol)){
	goto T847;}
	base[1]= (V170);
	vs_top=(vs_base=base+1)+1;
	return;
T847:;
	if(!(type_of((V170))==t_cons)){
	goto T850;}
	{object V171= car((V170));
	if((V171!= VV[99]))goto T852;
	base[1]= VV[99];
	vs_top=(vs_base=base+1)+1;
	return;
T852:;
	if((V171!= VV[155])
	&& (V171!= VV[156]))goto T853;
	base[1]= cadr((V170));
	vs_top=(vs_base=base+1)+1;
	return;
T853:;
	if((V171!= VV[157]))goto T854;
	base[1]= car(cddddr((V170)));
	vs_top=(vs_base=base+1)+1;
	return;
T854:;
	if((V171!= VV[116]))goto T855;
	base[1]= VV[116];
	vs_top=(vs_base=base+1)+1;
	return;
T855:;
	if(!(type_of(car((V170)))==t_symbol)){
	goto T857;}
	base[1]= car((V170));
	vs_top=(vs_base=base+1)+1;
	Lspecial_form_p();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T856;}
	base[1]= car((V170));
	vs_top=(vs_base=base+1)+1;
	Lfboundp();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T857;}
T856:;
	base[1]= car((V170));
	vs_top=(vs_base=base+1)+1;
	return;
T857:;
	base[1]= VV[101];
	vs_top=(vs_base=base+1)+1;
	return;}
T850:;
	base[1]= (V170);
	vs_top=(vs_base=base+1)+1;
	Lcompiled_function_p();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T866;}
	base[1]= (V170);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk168)();
	return;
T866:;
	base[1]= VV[101];
	vs_top=(vs_base=base+1)+1;
	return;}
	}
}
/*	function definition for IHS-NOT-INTERPRETED-ENV	*/

static L27()
{register object *base=vs_base;
	register object *sup=base+VM27; VC27
	vs_reserve(VM27);
	{object V172;
	check_arg(1);
	V172=(base[0]);
	vs_top=sup;
TTL:;
	{object V173;
	base[1]= (V172);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk154)();
	vs_top=sup;
	V173= vs_base[0];
	if(!(type_of((V173))==t_cons)){
	goto T873;}
	if(!(number_compare((V172),small_fixnum(3))>0)){
	goto T873;}
	base[1]= Cnil;
	vs_top=(vs_base=base+1)+1;
	return;
T873:;
	base[1]= Ct;
	vs_top=(vs_base=base+1)+1;
	return;}
	}
}
/*	local entry for function SET-ENV	*/

static object LI28()

{	 VMB28 VMS28 VMV28
TTL:;
	base[0]= symbol_value(VV[40]);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk169)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T879;}
	setq(VV[43],Cnil);
	goto T877;
T879:;
	{object V174;
	base[0]= symbol_value(VV[40]);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk145)();
	vs_top=sup;
	V174= vs_base[0];
	base[0]= (V174);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk147)();
	vs_top=sup;
	V175= vs_base[0];
	base[0]= one_plus((V174));
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk147)();
	vs_top=sup;
	V176= vs_base[0];
	base[0]= number_plus((V174),small_fixnum(2));
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk147)();
	vs_top=sup;
	V177= vs_base[0];
	setq(VV[43],list(3,V175,V176,V177));}
T877:;
	{object V178 = symbol_value(VV[43]);
	VMR28(V178)}
}
/*	local entry for function LIST-DELQ	*/

static object LI29(V181,V182)

object V181;register object V182;
{	 VMB29 VMS29 VMV29
TTL:;
	if(((V182))!=Cnil){
	goto T891;}
	{object V183 = Cnil;
	VMR29(V183)}
T891:;
	if(!(((V181))==(car((V182))))){
	goto T894;}
	{object V184 = cdr((V182));
	VMR29(V184)}
T894:;
	V185= (*(LnkLI170))((V181),cdr((V182)));
	if(type_of((V182))!=t_cons)FEwrong_type_argument(Scons,(V182));
	((V182))->c.c_cdr = /* INLINE-ARGS */V185;
	{object V186 = (V182);
	VMR29(V186)}
}
/*	local entry for function SUPER-GO	*/

static object LI30(V189,V190)

register object V189;register object V190;
{	 VMB30 VMS30 VMV30
TTL:;
	{object V191;
	V191= Cnil;
	if(!(number_compare((V189),symbol_value(VV[41]))>=0)){
	goto T897;}
	if(!(number_compare((V189),symbol_value(VV[42]))<=0)){
	goto T897;}
	base[1]= (V189);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk162)();
	vs_top=sup;
	base[0]= vs_base[0];
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk163)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T897;}
	base[1]= (V189);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk162)();
	vs_top=sup;
	base[0]= vs_base[0];
	base[3]= (V189);
	vs_top=(vs_base=base+3)+1;
	(void) (*Lnk159)();
	vs_top=sup;
	V192= vs_base[0];
	base[2]= number_plus(V192,small_fixnum(2));
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk147)();
	vs_top=sup;
	base[1]= vs_base[0];
	base[2]= VV[103];
	base[3]= symbol_function(VV[164]);
	base[4]= VV[104];
	base[5]= symbol_function(VV[165]);
	vs_top=(vs_base=base+0)+6;
	Lmember();
	vs_top=sup;
	V191= vs_base[0];
	if(((V191))==Cnil){
	goto T907;}
	if(!((cadar((V191)))==(VV[91]))){
	goto T897;}
	base[1]= (V189);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk162)();
	vs_top=sup;
	V197= vs_base[0];
	V198= symbol_function(VV[165]);
	V199= symbol_function(VV[164]);
	V200= (VFUN_NARGS=6,(*(LnkLI166))(V197,(V191),VV[106],V198,VV[103],V199));
	{object V195;
	object V196= /* INLINE-ARGS */V200;
	if(endp(V196)){
	V194= Cnil;
	goto T924;}
	base[0]=V195=MMcons(Cnil,Cnil);
T925:;
	(V195->c.c_car)= car((V196->c.c_car));
	if(endp(V196=MMcdr(V196))){
	V194= base[0];
	goto T924;}
	V195=MMcdr(V195)=MMcons(Cnil,Cnil);
	goto T925;}
T924:;
	{register object x= (V190),V193= V194;
	while(!endp(V193))
	if(eql(x,V193->c.c_car)){
	goto T923;
	}else V193=V193->c.c_cdr;
	goto T897;}
T923:;
	base[1]= (V189);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk162)();
	vs_top=sup;
	base[0]= vs_base[0];
	base[1]= (V190);
	base[2]= Ct;
	vs_top=(vs_base=base+0)+3;
	(void) (*Lnk171)();
	vs_top=sup;
	goto T897;
T907:;
	base[1]= (V189);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk162)();
	vs_top=sup;
	base[0]= vs_base[0];
	base[1]= (V190);
	base[2]= Cnil;
	vs_top=(vs_base=base+0)+3;
	(void) (*Lnk171)();
	vs_top=sup;
T897:;
	base[0]= symbol_value(VV[49]);
	base[1]= VV[117];
	base[2]= (V189);
	base[3]= (V190);
	vs_top=(vs_base=base+0)+4;
	Lformat();
	vs_top=sup;
	{object V201 = vs_base[0];
	VMR30(V201)}}
}
/*	local entry for function BREAK-BACKWARD-SEARCH-STACK	*/

static object LI31(V203)

object V203;
{	 VMB31 VMS31 VMV31
TTL:;
	{register object V204;
	V204= Cnil;
	V204= coerce_to_string((V203));
	{register object V205;
	register object V206;
	V205= one_minus(symbol_value(VV[40]));
	base[2]= (V205);
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk143)();
	vs_top=sup;
	V206= vs_base[0];
T950:;
	if(!(number_compare((V205),symbol_value(VV[38]))<0)){
	goto T951;}
	base[2]= symbol_value(VV[49]);
	base[3]= VV[118];
	base[4]= (V204);
	vs_top=(vs_base=base+2)+3;
	Lformat();
	vs_top=sup;
	{object V207 = vs_base[0];
	VMR31(V207)}
T951:;
	if(((*(LnkLI142))((V205)))==Cnil){
	goto T958;}
	V208= symbol_name((V206));
	V209= symbol_function(VV[173]);
	if(((VFUN_NARGS=4,(*(LnkLI172))((V204),/* INLINE-ARGS */V208,VV[104],V209)))==Cnil){
	goto T958;}
	base[2]= (V205);
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk174)();
	vs_top=sup;
	{object V210 = Cnil;
	VMR31(V210)}
T958:;
	V205= one_minus((V205));
	base[2]= (V205);
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk143)();
	vs_top=sup;
	V206= vs_base[0];
	goto T950;}}
}
/*	local entry for function BREAK-FORWARD-SEARCH-STACK	*/

static object LI32(V212)

object V212;
{	 VMB32 VMS32 VMV32
TTL:;
	{register object V213;
	V213= Cnil;
	V213= coerce_to_string((V212));
	{register object V214;
	register object V215;
	V214= one_plus(symbol_value(VV[40]));
	base[2]= (V214);
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk143)();
	vs_top=sup;
	V215= vs_base[0];
T979:;
	if(!(number_compare((V214),symbol_value(VV[39]))>0)){
	goto T980;}
	base[2]= symbol_value(VV[49]);
	base[3]= VV[119];
	base[4]= (V213);
	vs_top=(vs_base=base+2)+3;
	Lformat();
	vs_top=sup;
	{object V216 = vs_base[0];
	VMR32(V216)}
T980:;
	if(((*(LnkLI142))((V214)))==Cnil){
	goto T987;}
	V217= symbol_name((V215));
	V218= symbol_function(VV[173]);
	if(((VFUN_NARGS=4,(*(LnkLI172))((V213),/* INLINE-ARGS */V217,VV[104],V218)))==Cnil){
	goto T987;}
	base[2]= (V214);
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk174)();
	vs_top=sup;
	{object V219 = Cnil;
	VMR32(V219)}
T987:;
	V214= one_plus((V214));
	base[2]= (V214);
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk143)();
	vs_top=sup;
	V215= vs_base[0];
	goto T979;}}
}
/*	local entry for function BREAK-HELP	*/

static object LI33()

{	 VMB33 VMS33 VMV33
TTL:;
	base[0]= symbol_value(VV[49]);
	base[1]= VV[120];
	vs_top=(vs_base=base+0)+2;
	Lformat();
	vs_top=sup;
	vs_base=vs_top=base+0;
	vs_base[0]=Cnil;
	vs_top=sup;
	{object V220 = vs_base[0];
	VMR33(V220)}
}
static LnkT174(){ call_or_link(VV[174],&Lnk174);} /* BREAK-GO */
static object  LnkTLI172(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[172],&LnkLI172,ap);} /* SEARCH */
static LnkT171(){ call_or_link(VV[171],&Lnk171);} /* INTERNAL-SUPER-GO */
static object  LnkTLI170(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[170],&LnkLI170,2,ap);} /* LIST-DELQ */
static LnkT169(){ call_or_link(VV[169],&Lnk169);} /* IHS-NOT-INTERPRETED-ENV */
static LnkT168(){ call_or_link(VV[168],&Lnk168);} /* COMPILED-FUNCTION-NAME */
static object  LnkTLI166(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[166],&LnkLI166,ap);} /* REMOVE */
static LnkT163(){ call_or_link(VV[163],&Lnk163);} /* SPICEP */
static LnkT162(){ call_or_link(VV[162],&Lnk162);} /* FRS-TAG */
static LnkT160(){ call_or_link(VV[160],&Lnk160);} /* FRS-CLASS */
static LnkT159(){ call_or_link(VV[159],&Lnk159);} /* FRS-VS */
static object  LnkTLI158(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[158],&LnkLI158,1,ap);} /* FRS-KIND */
static LnkT154(){ call_or_link(VV[154],&Lnk154);} /* IHS-FUN */
static LnkT153(){ call_or_link(VV[153],&Lnk153);} /* FRS-IHS */
static LnkT152(){ call_or_link(VV[152],&Lnk152);} /* BDS-VAL */
static object  LnkTLI151(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[151],&LnkLI151,1,ap);} /* PRINT-FRS */
static LnkT150(){ call_or_link(VV[150],&Lnk150);} /* BDS-VAR */
static LnkT149(){ call_or_link(VV[149],&Lnk149);} /* FRS-BDS */
static LnkT148(){ call_or_link(VV[148],&Lnk148);} /* BREAK-VS */
static LnkT147(){ call_or_link(VV[147],&Lnk147);} /* VS */
static object  LnkTLI146(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[146],&LnkLI146,1,ap);} /* PRINT-IHS */
static LnkT145(){ call_or_link(VV[145],&Lnk145);} /* IHS-VS */
static LnkT144(){ call_or_link(VV[144],&Lnk144);} /* BREAK-PREVIOUS */
static LnkT143(){ call_or_link(VV[143],&Lnk143);} /* IHS-FNAME */
static object  LnkTLI142(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[142],&LnkLI142,1,ap);} /* IHS-VISIBLE */
static object  LnkTLI141(){return call_proc0(VV[141],&LnkLI141);} /* SET-ENV */
static LnkT140(){ call_or_link(VV[140],&Lnk140);} /* BREAK-LEVEL */
static LnkT139(){ call_or_link(VV[139],&Lnk139);} /* BREAK */
static LnkT136(){ call_or_link(VV[136],&Lnk136);} /* DBL-READ */
static LnkT135(){ call_or_link(VV[135],&Lnk135);} /* SET-BACK */
static object  LnkTLI134(){return call_proc0(VV[134],&LnkLI134);} /* SET-CURRENT */
static LnkT133(){ call_or_link(VV[133],&Lnk133);} /* CATCH-FATAL */
static LnkT132(){ call_or_link(VV[132],&Lnk132);} /* BREAK-QUIT */
static LnkT131(){ call_or_link(VV[131],&Lnk131);} /* SIMPLE-BACKTRACE */
static LnkT130(){ call_or_link(VV[130],&Lnk130);} /* FRS-TOP */
static LnkT129(){ call_or_link(VV[129],&Lnk129);} /* SCH-FRS-BASE */
static LnkT128(){ call_or_link(VV[128],&Lnk128);} /* IHS-TOP */
static LnkT127(){ call_or_link(VV[127],&Lnk127);} /* MAKE-STRING-INPUT-STREAM */
static LnkT126(){ call_or_link(VV[126],&Lnk126);} /* BREAK-CURRENT */
static LnkT122(){ call_or_link(VV[122],&Lnk122);} /* LOAD */
static LnkT121(){ call_or_link(VV[121],&Lnk121);} /* STRING-CONCATENATE */
