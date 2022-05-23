
#include <cmpinclude.h>
#include "cmptop.h"
init_cmptop(){do_init(VV);}
/*	function definition for T1EXPR	*/

static L1()
{register object *VOL base=vs_base;
	register object *VOL sup=base+VM1; VC1
	vs_reserve(VM1);
	bds_check;
	{VOL object V1;
	check_arg(1);
	V1=(base[0]);
	vs_top=sup;
TTL:;
	bds_bind(VV[0],(V1));
	bds_bind(VV[1],Ct);
	frs_push(FRS_CATCH,VV[2]);
	if(nlj_active)
	{nlj_active=FALSE;frs_pop();
	bds_unwind1;
	bds_unwind1;
	return;}
	else{
	if(!(type_of((V1))==t_cons)){
	goto T3;}
	{register object V2;
	object V3;
	register object V4;
	V2= car((V1));
	V3= cdr((V1));
	V4= Cnil;
	if(!(type_of((V2))==t_symbol)){
	goto T8;}
	if(!(((V2))==(VV[3]))){
	goto T11;}
	V5= (VFUN_NARGS=1,(*(LnkLI253))(VV[4]));
	frs_pop();
	base[3]= V5;
	vs_top=(vs_base=base+3)+1;
	bds_unwind1;
	bds_unwind1;
	return;
T11:;
	if((get((V2),VV[5],Cnil))==Cnil){
	goto T14;}
	if((symbol_value(VV[6]))==Cnil){
	goto T16;}
	(void)((VFUN_NARGS=2,(*(LnkLI254))(VV[7],(V1))));
T16:;
	(void)((*(LnkLI255))(Ct,(V1)));
	V6= (*(LnkLI256))((V1));
	frs_pop();
	base[3]= V6;
	vs_top=(vs_base=base+3)+1;
	bds_unwind1;
	bds_unwind1;
	return;
T14:;
	V4= get((V2),VV[8],Cnil);
	if(((V4))==Cnil){
	goto T21;}
	if((symbol_value(VV[9]))==Cnil){
	goto T24;}
	(void)((*(LnkLI257))());
T24:;
	base[3]= (V3);
	vs_top=(vs_base=base+3)+1;
	super_funcall_no_event((V4));
	frs_pop();
	bds_unwind1;
	bds_unwind1;
	return;
T21:;
	if((get((V2),VV[10],Cnil))==Cnil){
	goto T29;}
	if((symbol_value(VV[9]))==Cnil){
	goto T31;}
	(void)((*(LnkLI257))());
T31:;
	base[3]= (*(LnkLI258))((V1));
	vs_top=(vs_base=base+3)+1;
	(void) (*Lnk259)();
	frs_pop();
	bds_unwind1;
	bds_unwind1;
	return;
T29:;
	if((get((V2),VV[11],Cnil))==Cnil){
	goto T36;}
	V7= (*(LnkLI260))((V1));
	frs_pop();
	base[3]= V7;
	vs_top=(vs_base=base+3)+1;
	bds_unwind1;
	bds_unwind1;
	return;
T36:;
	base[3]= (V2);
	vs_top=(vs_base=base+3)+1;
	Lmacro_function();
	vs_top=sup;
	V4= vs_base[0];
	if(((V4))==Cnil){
	goto T39;}
	{object V8;
	base[3]= cdr((V1));
	vs_top=(vs_base=base+3)+1;
	Lcopy_list();
	vs_top=sup;
	V9= vs_base[0];
	V8= (*(LnkLI261))((V4),(V2),V9);
	base[3]= (V8);
	vs_top=(vs_base=base+3)+1;
	(void) (*Lnk259)();
	frs_pop();
	bds_unwind1;
	bds_unwind1;
	return;}
T39:;
	V10= (*(LnkLI260))((V1));
	frs_pop();
	base[3]= V10;
	vs_top=(vs_base=base+3)+1;
	bds_unwind1;
	bds_unwind1;
	return;
T8:;
	if(!(type_of((V2))==t_cons)){
	goto T48;}
	V11= (*(LnkLI260))((V1));
	frs_pop();
	base[3]= V11;
	vs_top=(vs_base=base+3)+1;
	bds_unwind1;
	bds_unwind1;
	return;
T48:;
	V12= (VFUN_NARGS=2,(*(LnkLI253))(VV[12],(V2)));
	frs_pop();
	base[3]= V12;
	vs_top=(vs_base=base+3)+1;
	bds_unwind1;
	bds_unwind1;
	return;}
T3:;
	frs_pop();
	base[3]= Cnil;
	vs_top=(vs_base=base+3)+1;
	bds_unwind1;
	bds_unwind1;
	return;}
	}
}
/*	local entry for function CTOP-WRITE	*/

static object LI2(V14)

object V14;
{	 VMB2 VMS2 VMV2
	bds_check;
TTL:;
	{object V15;
	V15= Cnil;
	bds_bind(VV[13],Cnil);
	bds_bind(VV[14],Cnil);
	bds_bind(VV[16],VV[15]);
	bds_bind(VV[17],Cnil);
	bds_bind(VV[18],small_fixnum(0));
	bds_bind(VV[19],Cnil);
	bds_bind(VV[0],Cnil);
	setq(VV[20],reverse(symbol_value(VV[20])));
	princ_str("\ninit_",VV[21]);
	(void)((*(LnkLI262))((V14)));
	princ_str("(){",VV[21]);
	princ_str("do_init(VV);",VV[21]);
	princ_char(125,VV[21]);
	{object V16;
	V16= symbol_value(VV[20]);
	bds_bind(VV[0],car((V16)));
T63:;
	if(!(endp((V16)))){
	goto T64;}
	bds_unwind1;
	goto T59;
T64:;
	setq(VV[1],Ct);
	V15= get(car((VV[0]->s.s_dbind)),VV[22],Cnil);
	if(((V15))==Cnil){
	goto T70;}
	base[8]= (V15);
	{object V17;
	V17= cdr((VV[0]->s.s_dbind));
	 vs_top=base+9;
	 while(!endp(V17))
	 {vs_push(car(V17));V17=cdr(V17);}
	vs_base=base+9;}
	super_funcall_no_event(base[8]);
	vs_top=sup;
T70:;
	V16= cdr((V16));
	(VV[0]->s.s_dbind)= car((V16));
	goto T63;}
T59:;
	{object V18;
	V18= symbol_value(VV[20]);
	bds_bind(VV[0],car((V18)));
T85:;
	if(!(endp((V18)))){
	goto T86;}
	bds_unwind1;
	goto T81;
T86:;
	setq(VV[1],Ct);
	V15= get(car((VV[0]->s.s_dbind)),VV[23],Cnil);
	if(((V15))==Cnil){
	goto T92;}
	base[8]= (V15);
	{object V19;
	V19= cdr((VV[0]->s.s_dbind));
	 vs_top=base+9;
	 while(!endp(V19))
	 {vs_push(car(V19));V19=cdr(V19);}
	vs_base=base+9;}
	super_funcall_no_event(base[8]);
	vs_top=sup;
T92:;
	V18= cdr((V18));
	(VV[0]->s.s_dbind)= car((V18));
	goto T85;}
T81:;
	{object V20;
	V20= Cnil;
T105:;
	if(!(endp(symbol_value(VV[24])))){
	goto T107;}
	goto T103;
T107:;
	V20= car(symbol_value(VV[24]));
	{object V21;
	V21= car(symbol_value(VV[24]));
	setq(VV[24],cdr(symbol_value(VV[24])));}
	{object V22;
	V22= (V20);
	 vs_top=base+7;
	 while(!endp(V22))
	 {vs_push(car(V22));V22=cdr(V22);}
	vs_base=base+7;}
	(void) (*Lnk245)();
	vs_top=sup;
	goto T105;}
T103:;
	{object V23;
	object V24;
	V23= symbol_value(VV[25]);
	V24= car((V23));
T122:;
	if(!(endp((V23)))){
	goto T123;}
	goto T118;
T123:;
	{object V25;
	V25= (V24);
	 vs_top=base+8;
	 while(!endp(V25))
	 {vs_push(car(V25));V25=cdr(V25);}
	vs_base=base+8;}
	(void) (*Lnk263)();
	vs_top=sup;
	V23= cdr((V23));
	V24= car((V23));
	goto T122;}
T118:;
	{object V26;
	object V27;
	V26= (VV[13]->s.s_dbind);
	V27= car((V26));
T138:;
	if(!(endp((V26)))){
	goto T139;}
	goto T134;
T139:;
	(void)((*(LnkLI264))((V27)));
	V26= cdr((V26));
	V27= car((V26));
	goto T138;}
T134:;
	{object V28;
	object V29;
	V28= symbol_value(VV[26]);
	V29= car((V28));
T153:;
	if(!(endp((V28)))){
	goto T154;}
	goto T149;
T154:;
	princ_str("\nstatic LC",VV[27]);
	V30= structure_ref((V29),VV[28],3);
	(void)((*(LnkLI265))(/* INLINE-ARGS */V30));
	princ_str("();",VV[27]);
	V28= cdr((V28));
	V29= car((V28));
	goto T153;}
T149:;
	{object V31;
	object V32;
	V31= symbol_value(VV[29]);
	V32= car((V31));
T171:;
	if(!(endp((V31)))){
	goto T172;}
	goto T167;
T172:;
	princ_str("\n#define VM",VV[27]);
	(void)((*(LnkLI265))(car((V32))));
	princ_char(32,VV[27]);
	(void)((*(LnkLI265))(cdr((V32))));
	V31= cdr((V31));
	V32= car((V31));
	goto T171;}
T167:;
	(void)((*(LnkLI266))(Cnil));
	{object V33;
	object V34;
	base[8]= (VV[18]->s.s_dbind);
	base[9]= symbol_value(VV[30]);
	base[10]= small_fixnum(1);
	vs_top=(vs_base=base+8)+3;
	Lminus();
	vs_top=sup;
	V33= vs_base[0];
	V34= small_fixnum(0);
T194:;
	if(!(number_compare((V34),(V33))>=0)){
	goto T195;}
	goto T187;
T195:;
	(void)((*(LnkLI266))(Cnil));
	V34= one_plus((V34));
	goto T194;}
T187:;
	princ_str("\nstatic char * VVi[",VV[27]);
	V35= number_plus(small_fixnum(1),symbol_value(VV[30]));
	(void)((*(LnkLI265))(/* INLINE-ARGS */V35));
	princ_str("]={",VV[27]);
	princ_str("\n#define Cdata VV[",VV[27]);
	(void)((*(LnkLI265))(symbol_value(VV[30])));
	princ_char(93,VV[27]);
	if((VV[17]->s.s_dbind)!=Cnil){
	goto T211;}
	princ_char(10,VV[27]);
	(void)((*(LnkLI265))(small_fixnum(0)));
T211:;
	{register object V36;
	V36= nreverse((VV[17]->s.s_dbind));
T217:;
	if(((V36))!=Cnil){
	goto T218;}
	princ_str("\n};",VV[27]);
	goto T214;
T218:;
	princ_str("\n(char *)(",VV[27]);
	(void)((*(LnkLI265))(caar((V36))));
	(void)((*(LnkLI265))(cadar((V36))));
	if((cdr((V36)))==Cnil){
	goto T230;}
	V37= VV[31];
	goto T228;
T230:;
	V37= VV[32];
T228:;
	(void)((*(LnkLI265))(V37));
	V36= cdr((V36));
	goto T217;}
T214:;
	princ_str("\n#define VV ((object *)VVi)",VV[27]);
	vs_base=vs_top;
	(void) (*Lnk267)();
	vs_top=sup;
	{object V38;
	object V39;
	V38= (VV[13]->s.s_dbind);
	V39= car((V38));
T241:;
	if(!(endp((V38)))){
	goto T242;}
	{object V40 = Cnil;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	VMR2(V40)}
T242:;
	{register object V41;
	register object V42;
	V41= cadr((V39));
	V42= caddr((V39));
	if(!(((V42))==(VV[33]))){
	goto T251;}
	princ_str("\nstatic object *Lclptr",VV[27]);
	(void)((*(LnkLI265))((V41)));
	princ_char(59,VV[27]);
	V42= VV[34];
	goto T249;
T251:;
	if(((V42))==Cnil){
	goto T260;}
	V42= (*(LnkLI268))((V42));
	goto T258;
T260:;
	V42= VV[35];
T258:;
T249:;
	princ_str("\nstatic ",VV[27]);
	(void)((*(LnkLI265))((V42)));
	princ_str(" LnkT",VV[27]);
	(void)((*(LnkLI265))((V41)));
	princ_str("() ;",VV[27]);
	princ_str("\nstatic ",VV[27]);
	(void)((*(LnkLI265))((V42)));
	princ_str(" (*Lnk",VV[27]);
	(void)((*(LnkLI265))((V41)));
	princ_str(")() = LnkT",VV[27]);
	(void)((*(LnkLI265))((V41)));
	princ_char(59,VV[27]);}
	V38= cdr((V38));
	V39= car((V38));
	goto T241;}}
}
/*	local entry for function MAYBE-EVAL	*/

static object LI3(V45,V46)

object V45;register object V46;
{	 VMB3 VMS3 VMV3
TTL:;
	if((V45)!=Cnil){
	goto T280;}
	if(type_of(car((V46)))==t_symbol){
	goto T281;}
	goto T280;
T281:;
	V45= get(car((V46)),VV[36],Cnil);
T280:;
	if(((V45))==Cnil){
	goto T286;}
	if((VV[37])==(symbol_value(VV[38]))){
	goto T284;}
T286:;
	if(!(type_of(symbol_value(VV[38]))==t_cons)){
	goto T285;}
	{register object x= VV[39],V47= symbol_value(VV[38]);
	while(!endp(V47))
	if(eql(x,V47->c.c_car)){
	goto T292;
	}else V47=V47->c.c_cdr;
	goto T285;}
T292:;
T284:;
	if(((V46))==Cnil){
	goto T293;}
	base[0]= (V46);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk269)();
	vs_top=sup;
T293:;
	{object V48 = Ct;
	VMR3(V48)}
T285:;
	{object V49 = Cnil;
	VMR3(V49)}
}
/*	function definition for T1EVAL-WHEN	*/

static L4()
{register object *base=vs_base;
	register object *sup=base+VM4; VC4
	vs_reserve(VM4);
	bds_check;
	{register object V50;
	check_arg(1);
	V50=(base[0]);
	vs_top=sup;
TTL:;
	{register object V51;
	register object V52;
	V51= Cnil;
	V52= Cnil;
	if(!(endp((V50)))){
	goto T299;}
	(void)((*(LnkLI270))(VV[40],small_fixnum(1),small_fixnum(0)));
T299:;
	{register object V53;
	register object V54;
	V53= car((V50));
	V54= car((V53));
T306:;
	if(!(endp((V53)))){
	goto T307;}
	goto T302;
T307:;
	{object V55= (V54);
	if((V55!= VV[271]))goto T312;
	V51= Ct;
	goto T311;
T312:;
	if((V55!= VV[39]))goto T314;
	V52= Ct;
	goto T311;
T314:;
	if((V55!= VV[272]))goto T316;
	goto T311;
T316:;
	(void)((VFUN_NARGS=2,(*(LnkLI253))(VV[41],(V54))));}
T311:;
	V53= cdr((V53));
	V54= car((V53));
	goto T306;}
T302:;
	base[1]= car((V50));
	bds_bind(VV[38],base[1]);
	if(((V51))==Cnil){
	goto T324;}
	base[2]= (*(LnkLI273))(cdr((V50)));
	vs_top=(vs_base=base+2)+1;
	bds_unwind1;
	return;
T324:;
	if(((V52))==Cnil){
	goto T327;}
	base[2]= make_cons(VV[42],cdr((V50)));
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk269)();
	bds_unwind1;
	return;
T327:;
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	bds_unwind1;
	return;}
	}
}
/*	local entry for function T1PROGN	*/

static object LI5(V57)

object V57;
{	 VMB5 VMS5 VMV5
	bds_check;
TTL:;
	if(!(equal(car((V57)),VV[43]))){
	goto T331;}
	bds_bind(VV[44],Ct);
	{object V58 = (*(LnkLI273))(cdr((V57)));
	bds_unwind1;
	VMR5(V58)}
T331:;
	{register object V59;
	register object V60;
	V59= (V57);
	V60= car((V59));
T336:;
	if(!(endp((V59)))){
	goto T337;}
	{object V61 = Cnil;
	VMR5(V61)}
T337:;
	base[1]= (V60);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk259)();
	vs_top=sup;
	V59= cdr((V59));
	V60= car((V59));
	goto T336;}
}
/*	local entry for function CMPFIX-ARGS	*/

static object LI6(V64,V65)

object V64;object V65;
{	 VMB6 VMS6 VMV6
TTL:;
	{register object V66;
	register object V67;
	V66= Cnil;
	base[1]= cadr((V64));
	vs_top=(vs_base=base+1)+1;
	Lcopy_list();
	vs_top=sup;
	V67= vs_base[0];
	{register object V68;
	register object V69;
	V68= (V65);
	V69= car((V68));
T355:;
	if(!(endp((V68)))){
	goto T356;}
	goto T351;
T356:;
	{register object x= car((V69)),V70= (V67);
	while(!endp(V70))
	if(eql(x,V70->c.c_car)){
	V66= V70;
	goto T361;
	}else V70=V70->c.c_cdr;
	V66= Cnil;}
T361:;
	if((V66)==Cnil){
	goto T362;}
	{register object V71;
	register object V72;
	V71= (V66);
	V72= cadr((V69));
	if(type_of((V71))!=t_cons)FEwrong_type_argument(Scons,(V71));
	((V71))->c.c_car = (V72);}
T362:;
	V68= cdr((V68));
	V69= car((V68));
	goto T355;}
T351:;
	{register object x= VV[45],V73= (V67);
	while(!endp(V73))
	if(eql(x,V73->c.c_car)){
	V66= V73;
	goto T375;
	}else V73=V73->c.c_cdr;
	V66= Cnil;}
T375:;
	if(((V66))==Cnil){
	goto T373;}
	{object V75;
	V75= append((V65),cdr((V66)));
	if(type_of(V66)!=t_cons)FEwrong_type_argument(Scons,V66);
	(V66)->c.c_cdr = (V75);
	goto T371;}
T373:;
	V76= make_cons(VV[45],(V65));
	V67= append((V67),/* INLINE-ARGS */V76);
T371:;
	{object V77 = listA(3,car((V64)),(V67),cddr((V64)));
	VMR6(V77)}}
}
/*	local entry for function T1DEFUN	*/

static object LI7(V79)

object V79;
{	 VMB7 VMS7 VMV7
	bds_check;
TTL:;
	{object V80;
	V80= symbol_value(VV[46]);
	bds_bind(VV[48],Cnil);
	if(endp((V79))){
	goto T381;}
	if(!(endp(cdr((V79))))){
	goto T380;}
T381:;
	V82 = make_fixnum(length((V79)));
	(void)((*(LnkLI270))(VV[47],small_fixnum(2),V82));
T380:;
	if(type_of(car((V79)))==t_symbol){
	goto T385;}
	(void)((VFUN_NARGS=2,(*(LnkLI253))(VV[49],car((V79)))));
T385:;
	V83= make_cons(VV[47],(V79));
	(void)((*(LnkLI255))(Cnil,/* INLINE-ARGS */V83));
T390:;
	setq(VV[6],Ct);
	setq(VV[50],Cnil);
	{register object V84;
	object V85;
	object V86;
	register object V87;{object V88;
	V88= get(car((V79)),VV[56],Cnil);
	if(V88==Cnil)goto T397;
	V85= V88;
	goto T396;
T397:;}
	setq(VV[57],number_plus(symbol_value(VV[57]),small_fixnum(1)));
	V85= symbol_value(VV[57]);
T396:;
	V87= car((V79));
	bds_bind(VV[51],Cnil);
	bds_bind(VV[52],Cnil);
	bds_bind(VV[53],Cnil);
	bds_bind(VV[54],Cnil);
	V84= Cnil;
	bds_bind(VV[55],Cnil);
	V86= Cnil;
	V84= (VFUN_NARGS=2,(*(LnkLI274))(cdr((V79)),(V87)));
	if(!(eql((V80),symbol_value(VV[46])))){
	goto T404;}
	goto T403;
T404:;
	(void)(structure_set(cadr((V84)),VV[58],4,Ct));
T403:;
	V89= structure_ref(cadr((V84)),VV[58],1);
	(void)((*(LnkLI275))(/* INLINE-ARGS */V89));
	if((get((V87),VV[59],Cnil))==Cnil){
	goto T407;}
	{object V90;
	V90= make_fixnum(length(car(caddr((V84)))));
	(void)(sputprop((V87),VV[59],(V90)));
	base[6]= (V90);
	base[7]= VV[61];
	base[8]= Ct;
	vs_top=(vs_base=base+6)+3;
	Lmake_list();
	vs_top=sup;
	V91= vs_base[0];
	V92= list(4,VV[60],(V87),V91,Ct);
	(void)((*(LnkLI276))(/* INLINE-ARGS */V92));}
T407:;
	if((get((V87),VV[62],Cnil))==Cnil){
	goto T418;}
	{object V93;
	register object V94;
	V93= caddr((V84));
	V94= Cnil;
	if((cadr((V93)))==Cnil){
	goto T423;}
	goto T418;
T423:;
	if((caddr((V93)))==Cnil){
	goto T425;}
	goto T418;
T425:;
	if((cadddr((V93)))==Cnil){
	goto T427;}
	goto T418;
T427:;
	if((length(car((V93))))<(64)){
	goto T429;}
	goto T418;
T429:;
	{register object V95;
	register object V96;
	object V97;
	V95= car((V93));
	V96= get((V87),VV[63],Cnil);
	V97= Cnil;
T436:;
	if(!(endp((V95)))){
	goto T437;}
	if(endp((V96))){
	goto T440;}
	goto T432;
T440:;
	if(((V94))==Cnil){
	goto T443;}
	V79= (*(LnkLI277))((V79),(V94));
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	goto T390;
T443:;
	if(((V97))==Cnil){
	goto T431;}
	goto T432;
T437:;
	{register object V98;
	V98= car((V95));
	if(!(equal(car((V96)),VV[64]))){
	goto T450;}
	goto T432;
T450:;
	V99= structure_ref((V98),VV[65],1);
	if((/* INLINE-ARGS */V99)==(VV[66])){
	goto T456;}
	V100= structure_ref((V98),VV[65],1);
	if(!((/* INLINE-ARGS */V100)==(VV[67]))){
	goto T455;}
	if(!((car((V96)))==(Ct))){
	goto T455;}
T456:;
	if((structure_ref((V98),VV[65],3))!=Cnil){
	goto T455;}
	V101= structure_ref((V98),VV[65],4);
	if(!((/* INLINE-ARGS */V101)==(VV[68]))){
	goto T454;}
T455:;
	V102= structure_ref((V98),VV[65],0);
	vs_base=vs_top;
	Lgensym();
	vs_top=sup;
	V103= vs_base[0];
	V104= list(2,/* INLINE-ARGS */V102,V103);
	V94= make_cons(/* INLINE-ARGS */V104,(V94));
T454:;
	V105= car((V96));
	V106= structure_ref((V98),VV[65],5);
	if(((*(LnkLI278))(/* INLINE-ARGS */V105,/* INLINE-ARGS */V106))==Cnil){
	goto T453;}
	{register object x= car((V96)),V107= VV[69];
	while(!endp(V107))
	if(eql(x,V107->c.c_car)){
	goto T448;
	}else V107=V107->c.c_cdr;}
	V108= structure_ref((V98),VV[65],4);
	if((/* INLINE-ARGS */V108)==(VV[70])){
	goto T448;}
	if((symbol_value(VV[71]))!=Cnil){
	goto T448;}
	V110= structure_ref(cadr((V84)),VV[58],0);
	{register object x= (V98),V109= /* INLINE-ARGS */V110;
	while(!endp(V109))
	if(eql(x,V109->c.c_car)){
	goto T477;
	}else V109=V109->c.c_cdr;
	goto T448;}
T477:;
T453:;
	if(((V94))!=Cnil){
	goto T478;}
	V111= structure_ref((V98),VV[65],0);
	(void)((VFUN_NARGS=3,(*(LnkLI254))(VV[72],(V87),/* INLINE-ARGS */V111)));
T478:;
	V97= Ct;}
T448:;
	V95= cdr((V95));
	V96= cdr((V96));
	goto T436;}
T432:;
	goto T418;
T431:;
	if(!(type_of((V85))==t_fixnum||
type_of((V85))==t_bignum||
type_of((V85))==t_ratio||
type_of((V85))==t_shortfloat||
type_of((V85))==t_longfloat||
type_of((V85))==t_complex)){
	goto T418;}}
	V112= get((V87),VV[63],Cnil);
	V113= get((V87),VV[74],Cnil);
	V114= get((V87),VV[63],Cnil);
	V115= list(5,(V87),V112,V113,small_fixnum(3),(*(LnkLI279))((V85),V114));
	setq(VV[73],make_cons(/* INLINE-ARGS */V115,symbol_value(VV[73])));
	goto T416;
T418:;
	{object V116;
	V117= get((V87),VV[74],Cnil);
	V116= ((V117)==(Ct)?Ct:Cnil);
	if(((V116))==Cnil){
	goto T416;}}
T416:;
	if((cadddr((V84)))==Cnil){
	goto T494;}
	V86= cadddr((V84));
T494:;
	(void)((*(LnkLI280))());
	V118= list(6,VV[47],(V87),(V85),(V84),(V86),(VV[55]->s.s_dbind));
	setq(VV[20],make_cons(/* INLINE-ARGS */V118,symbol_value(VV[20])));
	V119= make_cons((V87),(V85));
	setq(VV[75],make_cons(/* INLINE-ARGS */V119,symbol_value(VV[75])));
	V120= symbol_value(VV[75]);
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;}
	{object V121 = Cnil;
	bds_unwind1;
	VMR7(V121)}}
}
/*	local entry for function MAKE-INLINE-STRING	*/

static object LI8(V124,V125)

object V124;object V125;
{	 VMB8 VMS8 VMV8
TTL:;
	if(((V125))!=Cnil){
	goto T503;}
	base[0]= Cnil;
	base[1]= VV[76];
	base[2]= (V124);
	vs_top=(vs_base=base+0)+3;
	Lformat();
	vs_top=sup;
	{object V126 = vs_base[0];
	VMR8(V126)}
T503:;
	{register object V127;
	V127= (VFUN_NARGS=7,(*(LnkLI281))(small_fixnum(100),VV[77],VV[78],VV[79],small_fixnum(0),VV[80],Ct));
	base[0]= (V127);
	base[1]= VV[81];
	base[2]= (V124);
	vs_top=(vs_base=base+0)+3;
	Lformat();
	vs_top=sup;
	{register object V128;
	register int V129;
	V129= 0;
	V128= (V125);
T516:;
	if(!(endp(cdr((V128))))){
	goto T517;}
	base[0]= (V127);
	base[1]= VV[82];
	base[2]= make_fixnum(V129);
	vs_top=(vs_base=base+0)+3;
	Lformat();
	vs_top=sup;
	goto T513;
T517:;
	base[0]= (V127);
	base[1]= VV[83];
	base[2]= make_fixnum(V129);
	vs_top=(vs_base=base+0)+3;
	Lformat();
	vs_top=sup;
	V128= cdr((V128));
	V129= (V129)+1;
	goto T516;}
T513:;
	{object V130 = (V127);
	VMR8(V130)}}
}
/*	local entry for function CS-PUSH	*/

static object LI9(va_alist)
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB9 VMS9 VMV9
	{object V131;
	narg = narg - 0;
	if (narg <= 0) goto T532;
	else {
	va_start(ap);
	V131= va_arg(ap,object);}
	--narg; goto T533;
T532:;
	V131= Cnil;
T533:;
	{object V132;
	setq(VV[84],number_plus(symbol_value(VV[84]),small_fixnum(1)));
	V132= symbol_value(VV[84]);
	if(((V131))==Cnil){
	goto T541;}
	V133= make_cons((V131),(V132));
	goto T539;
T541:;
	V133= (V132);
T539:;
	setq(VV[14],make_cons(V133,symbol_value(VV[14])));
	{object V134 = (V132);
	VMR9(V134)}}}
	}
/*	local entry for function F-TYPE	*/

static int LI10(V136)

register object V136;
{	 VMB10 VMS10 VMV10
TTL:;
	base[0]= (V136);
	base[1]= VV[65];
	vs_top=(vs_base=base+0)+2;
	(void) (*Lnk282)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T543;}
	V136= structure_ref((V136),VV[65],5);
T543:;
	if(((V136))==Cnil){
	goto T550;}
	base[0]= (V136);
	base[1]= VV[85];
	vs_top=(vs_base=base+0)+2;
	(void) (*Lnk283)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T550;}
	{int V137 = 1;
	VMR10(V137)}
T550:;
	{int V138 = 0;
	VMR10(V138)}
}
/*	local entry for function PROCLAIMED-ARGD	*/

static int LI11(V141,V142)

register object V141;object V142;
{	 VMB11 VMS11 VMV11
TTL:;
	{register int V143;
	register int V144;
	register object V145;
	register object V146;
	V143= length((V141));
	V144= 8;
	V145= make_fixnum((*(LnkLI284))((V142)));
	V146= Ct;
T560:;
	if(eql(small_fixnum(0),(V145))){
	goto T562;}
	V143= (V143)+(((fix((V145))) << (V144)));
T562:;
	if(((V146))==Cnil){
	goto T566;}
	V144= 10;
	V146= Cnil;
T566:;
	if(((V141))!=Cnil){
	goto T572;}
	{int V147 = V143;
	VMR11(V147)}
T572:;
	V144= (V144)+(2);
	{register object V149;
	V149= car((V141));
	V141= cdr((V141));
	V148= (V149);}
	V145= make_fixnum((*(LnkLI284))(V148));
	goto T560;}
}
/*	local entry for function WT-IF-PROCLAIMED	*/

static object LI12(V153,V154,V155)

register object V153;object V154;object V155;
{	 VMB12 VMS12 VMV12
TTL:;
	if(((VFUN_NARGS=1,(*(LnkLI286))((V153))))==Cnil){
	goto T584;}
	{register object x= (V153),V156= symbol_value(VV[73]);
	while(!endp(V156))
	if(type_of(V156->c.c_car)==t_cons &&eql(x,V156->c.c_car->c.c_car)){
	goto T588;
	}else V156=V156->c.c_cdr;
	goto T587;}
T588:;
	V157= list(2,VV[87],(V153));
	V158= (*(LnkLI288))(VV[88],(V154));
	V159= get((V153),VV[63],Cnil);
	V160= get((V153),VV[74],Cnil);
	V161 = make_fixnum((*(LnkLI289))(V159,V160));
	V162= list(4,VV[86],/* INLINE-ARGS */V157,/* INLINE-ARGS */V158,V161);
	(void)((VFUN_NARGS=1,(*(LnkLI287))(/* INLINE-ARGS */V162)));
	{object V163 = Ct;
	VMR12(V163)}
T587:;
	{register object V164;
	register object V165;
	object V166;
	V164= make_fixnum(length(car(caddr((V155)))));
	V167= get((V153),VV[63],Cnil);
	V165= make_fixnum(length(V167));
	V169= get((V153),VV[63],Cnil);
	{register object x= VV[64],V168= V169;
	while(!endp(V168))
	if(eql(x,V168->c.c_car)){
	V166= V168;
	goto T596;
	}else V168=V168->c.c_cdr;
	V166= Cnil;}
T596:;
	if(((V166))==Cnil){
	goto T599;}
	base[0]= (V164);
	vs_top=(vs_base=base+0)+1;
	Lmonotonically_nonincreasing();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T601;}
	goto T592;
T601:;{object V170;
	V171 = make_fixnum(length((V166)));
	V170= number_minus((V165),V171);
	if(V170==Cnil)goto T604;
	goto T592;
T604:;}
	V172 = make_fixnum(length((V166)));
	V173= number_minus((V165),V172);
	(void)((VFUN_NARGS=4,(*(LnkLI254))(VV[89],(V153),/* INLINE-ARGS */V173,(V164))));
	goto T592;
T599:;
	if(eql((V164),(V165))){
	goto T607;}
	(void)((VFUN_NARGS=4,(*(LnkLI254))(VV[90],(V153),(V165),(V164))));
	goto T592;
T607:;
	(void)((VFUN_NARGS=2,(*(LnkLI254))(VV[91],(V153))));}
T592:;
	{object V174 = Cnil;
	VMR12(V174)}
T584:;
	{object V175 = Cnil;
	VMR12(V175)}
}
/*	local entry for function VOLATILE	*/

static object LI13(V177)

object V177;
{	 VMB13 VMS13 VMV13
TTL:;
	if((structure_ref((V177),VV[58],4))==Cnil){
	goto T610;}
	{object V178 = VV[92];
	VMR13(V178)}
T610:;
	{object V179 = VV[93];
	VMR13(V179)}
}
/*	local entry for function REGISTER	*/

static object LI14(V181)

object V181;
{	 VMB14 VMS14 VMV14
TTL:;
	if(!(equal(symbol_value(VV[16]),VV[94]))){
	goto T613;}
	{int V182= fix(structure_ref((V181),VV[65],6));
	if(!((/* INLINE-ARGS */V182)>=(fix(symbol_value(VV[95]))))){
	goto T613;}}
	{object V183 = VV[96];
	VMR14(V183)}
T613:;
	{object V184 = VV[97];
	VMR14(V184)}
}
/*	local entry for function VARARG-P	*/

static object LI15(V186)

object V186;
{	 VMB15 VMS15 VMV15
TTL:;
	V187= get((V186),VV[74],Cnil);
	if(equal(V187,Ct)){
	goto T617;}
	{object V188 = Cnil;
	VMR15(V188)}
T617:;
	{register object V189;
	V189= get((V186),VV[63],Cnil);
T622:;
	if(((V189))!=Cnil){
	goto T623;}
	{object V190 = Ct;
	VMR15(V190)}
T623:;
	if(!(type_of((V189))==t_cons)){
	goto T628;}
	goto T627;
T628:;
	{object V191 = Cnil;
	VMR15(V191)}
T627:;
	if(!((car((V189)))==(Ct))){
	goto T631;}
	goto T630;
T631:;
	if(!((car((V189)))==(VV[64]))){
	goto T633;}
	goto T630;
T633:;
	{object V192 = Cnil;
	VMR15(V192)}
T630:;
	V189= cdr((V189));
	goto T622;}
}
/*	local entry for function MAXARGS	*/

static object LI16(V194)

register object V194;
{	 VMB16 VMS16 VMV16
TTL:;
	if((cadr(cddddr((V194))))!=Cnil){
	goto T638;}
	if((caddr((V194)))==Cnil){
	goto T639;}
T638:;
	{object V195 = small_fixnum(64);
	VMR16(V195)}
T639:;
	{ save_avma;
	V196 = stoi(length(car((V194))));
	V197 = stoi(length(cadr((V194))));
	V198 = stoi(length(car(cddddr((V194)))));
	{GEN V199= mulsi(2,V198);
	{object V200 = make_integer(addii(V196,addii(V197,/* INLINE-ARGS */V199)));
	restore_avma; 
	VMR16(V200)}restore_avma;}}
}
/*	local entry for function ADD-ADDRESS	*/

static object LI17(V203,V204)

object V203;object V204;
{	 VMB17 VMS17 VMV17
TTL:;
	V205= list(2,(V203),(V204));
	setq(VV[17],make_cons(/* INLINE-ARGS */V205,symbol_value(VV[17])));
	{object V206;
	V206= symbol_value(VV[18]);
	setq(VV[18],number_plus(symbol_value(VV[18]),small_fixnum(1)));
	{object V207 = (V206);
	VMR17(V207)}}
}
/*	local entry for function T2DEFUN	*/

static object LI18(V213,V214,V215,V216,V217)

register object V213;register object V214;register object V215;object V216;object V217;
{	 VMB18 VMS18 VMV18
TTL:;
	if((get((V213),VV[98],Cnil))==Cnil){
	goto T647;}
	{object V218 = Cnil;
	VMR18(V218)}
T647:;
	if(((V216))==Cnil){
	goto T650;}
	V219= list(4,VV[99],list(2,VV[87],(V213)),(V216),VV[100]);
	(void)((VFUN_NARGS=1,(*(LnkLI287))(/* INLINE-ARGS */V219)));
T650:;
	{object V220;
	V220= (*(LnkLI290))((V213),(V214),(V215));
	if(((V220))==Cnil){
	goto T656;}
	goto T653;
T656:;
	if(((*(LnkLI291))((V213)))==Cnil){
	goto T659;}
	{object V221;
	V221= cadddr(caddr((V215)));
	princ_str("\nstatic object LI",VV[27]);
	(void)((*(LnkLI265))((V214)));
	princ_str("();",VV[27]);
	if(((V221))==Cnil){
	goto T667;}
	V222= list(2,VV[87],(V213));
	V223= (*(LnkLI288))(VV[102],(V214));
	V224 = make_fixnum(length(car(caddr((V215)))));
	V225= (*(LnkLI292))(caddr((V215)));
	V226= (*(LnkLI285))(/* INLINE-ARGS */V225,small_fixnum(8));
	V227= number_plus(V224,/* INLINE-ARGS */V226);
	base[0]= Cnil;
	base[1]= VV[103];
	base[2]= (V214);
	vs_top=(vs_base=base+0)+3;
	Lformat();
	vs_top=sup;
	V228= vs_base[0];
	V229= list(5,VV[101],/* INLINE-ARGS */V222,/* INLINE-ARGS */V223,/* INLINE-ARGS */V227,(*(LnkLI288))(V228,VV[104]));
	(void)((VFUN_NARGS=1,(*(LnkLI287))(/* INLINE-ARGS */V229)));
	goto T653;
T667:;
	V230= list(2,VV[87],(V213));
	V231= (*(LnkLI288))(VV[106],(V214));
	V232 = make_fixnum(length(car(caddr((V215)))));
	V233= (*(LnkLI292))(caddr((V215)));
	V234= (*(LnkLI285))(/* INLINE-ARGS */V233,small_fixnum(8));
	V235= list(4,VV[105],/* INLINE-ARGS */V230,/* INLINE-ARGS */V231,number_plus(V232,/* INLINE-ARGS */V234));
	(void)((VFUN_NARGS=1,(*(LnkLI287))(/* INLINE-ARGS */V235)));
	goto T653;}
T659:;
	if(!(type_of((V214))==t_fixnum||
type_of((V214))==t_bignum||
type_of((V214))==t_ratio||
type_of((V214))==t_shortfloat||
type_of((V214))==t_longfloat||
type_of((V214))==t_complex)){
	goto T674;}
	princ_str("\nstatic L",VV[27]);
	(void)((*(LnkLI265))((V214)));
	princ_str("();",VV[27]);
	V236= list(2,VV[87],(V213));
	V237= list(3,VV[107],/* INLINE-ARGS */V236,(*(LnkLI288))(VV[108],(V214)));
	(void)((VFUN_NARGS=1,(*(LnkLI287))(/* INLINE-ARGS */V237)));
	goto T653;
T674:;
	princ_char(10,VV[27]);
	(void)((*(LnkLI265))((V214)));
	princ_str("();",VV[27]);
	V238= list(2,VV[87],(V213));
	V239= list(3,VV[107],/* INLINE-ARGS */V238,(*(LnkLI288))(VV[109],(V214)));
	(void)((VFUN_NARGS=1,(*(LnkLI287))(/* INLINE-ARGS */V239)));}
T653:;
	if(!(number_compare(symbol_value(VV[110]),small_fixnum(2))<0)){
	goto T685;}
	{object V240 = sputprop((V213),VV[111],Ct);
	VMR18(V240)}
T685:;
	{object V241 = Cnil;
	VMR18(V241)}
}
/*	local entry for function ADD-DEBUG	*/

static object LI19(V244,V245)

object V244;object V245;
{	 VMB19 VMS19 VMV19
TTL:;
	{object V246 = putprop((V244),(V245),VV[112]);
	VMR19(V246)}
}
/*	local entry for function T3DEFUN	*/

static object LI20(V252,V253,V254,V255,V256)

register object V252;register object V253;register object V254;object V255;object V256;
{	 VMB20 VMS20 VMV20
	bds_check;
TTL:;
	{register object V257;
	V257= Cnil;
	bds_bind(VV[0],list(2,VV[47],(V252)));
	bds_bind(VV[16],(*(LnkLI293))(cadr((V254))));
	bds_bind(VV[113],Cnil);
	{register object V258;
	register object V259;
	V258= symbol_value(VV[73]);
	V259= car((V258));
T697:;
	if(!(endp((V258)))){
	goto T698;}
	goto T692;
T698:;{object V260;
	base[4]= cadddr((V259));
	vs_top=(vs_base=base+4)+1;
	(void) (*Lnk294)();
	vs_top=sup;
	V260= vs_base[0];
	if(V260==Cnil)goto T703;
	goto T702;
T703:;}
	base[4]= VV[114];
	vs_top=(vs_base=base+4)+1;
	Lerror();
	vs_top=sup;
T702:;
	if((car((V259)))==((V252))){
	goto T708;}
	goto T707;
T708:;
	if((cadr(cddddr((V259))))==Cnil){
	goto T710;}
	goto T707;
T710:;
	V257= (V259);
	if(((V257))==Cnil){
	goto T692;}
	goto T693;
T707:;
	V258= cdr((V258));
	V259= car((V258));
	goto T697;}
T693:;
	if(((VFUN_NARGS=1,(*(LnkLI286))((V252))))!=Cnil){
	goto T718;}
	V261= list(4,(V252),(V253),cadr((V257)),caddr((V257)));
	setq(VV[25],make_cons(/* INLINE-ARGS */V261,symbol_value(VV[25])));
T718:;
	V262= structure_ref(cadr((V254)),VV[58],1);
	(void)((*(LnkLI295))(/* INLINE-ARGS */V262,small_fixnum(0)));
	base[3]= VV[115];
	{object V263= caddr((V257));
	if((V263!= VV[85]))goto T725;
	base[4]= VV[116];
	goto T724;
T725:;
	if((V263!= VV[138]))goto T726;
	base[4]= VV[117];
	goto T724;
T726:;
	if((V263!= VV[139]))goto T727;
	base[4]= VV[118];
	goto T724;
T727:;
	if((V263!= VV[140]))goto T728;
	base[4]= VV[119];
	goto T724;
T728:;
	base[4]= VV[120];}
T724:;
	base[5]= (V252);
	base[6]= (V253);
	base[7]= (V254);
	base[8]= (V256);
	base[9]= (V257);
	vs_top=(vs_base=base+3)+7;
	(void) (*Lnk296)();
	vs_top=sup;
	goto T690;
T692:;
	if(((*(LnkLI291))((V252)))==Cnil){
	goto T735;}
	V264= structure_ref(cadr((V254)),VV[58],1);
	(void)((*(LnkLI295))(/* INLINE-ARGS */V264,small_fixnum(0)));
	base[3]= VV[121];
	base[4]= VV[120];
	base[5]= (V252);
	base[6]= (V253);
	base[7]= (V254);
	base[8]= (V256);
	vs_top=(vs_base=base+3)+6;
	(void) (*Lnk296)();
	vs_top=sup;
	goto T690;
T735:;
	V265= structure_ref(cadr((V254)),VV[58],1);
	(void)((*(LnkLI295))(/* INLINE-ARGS */V265,small_fixnum(2)));
	base[3]= VV[122];
	base[4]= VV[123];
	base[5]= (V252);
	base[6]= (V253);
	base[7]= (V254);
	base[8]= (V256);
	vs_top=(vs_base=base+3)+6;
	(void) (*Lnk296)();
	vs_top=sup;
T690:;
	(void)((*(LnkLI297))((V253)));
	{object V266 = (*(LnkLI298))((V252),(V254));
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	VMR20(V266)}}
}
/*	function definition for T3DEFUN-AUX	*/

static L21()
{register object *base=vs_base;
	register object *sup=base+VM21; VC21
	vs_reserve(VM21);
	bds_check;
	{object V267;
	object V268;
	if(vs_top-vs_base<2) too_few_arguments();
	V267=(base[0]);
	bds_bind(VV[124],base[1]);
	vs_base=vs_base+2;
	vs_top[0]=Cnil;
	{object *p=vs_top;
	 for(;p>vs_base;p--)p[-1]=MMcons(p[-1],p[0]);}
	V268=(base[2]);
	vs_top=sup;
	bds_bind(VV[14],Cnil);
	bds_bind(VV[125],small_fixnum(0));
	bds_bind(VV[126],small_fixnum(0));
	bds_bind(VV[127],small_fixnum(0));
	bds_bind(VV[128],small_fixnum(0));
	bds_bind(VV[129],Cnil);
	bds_bind(VV[130],make_cons((VV[124]->s.s_dbind),Cnil));
	bds_bind(VV[131],(VV[124]->s.s_dbind));
	setq(VV[133],number_plus(symbol_value(VV[133]),small_fixnum(1)));
	bds_bind(VV[132],symbol_value(VV[133]));
	bds_bind(VV[134],Cnil);
	bds_bind(VV[135],Cnil);
	bds_bind(VV[136],Cnil);
	bds_bind(VV[137],small_fixnum(0));
	base[16]= (V267);
	{object V269;
	V269= (V268);
	 vs_top=base+17;
	 while(!endp(V269))
	 {vs_push(car(V269));V269=cdr(V269);}
	vs_base=base+17;}
	super_funcall_no_event(base[16]);
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
	}
}
/*	local entry for function T3DEFUN-LOCAL-ENTRY	*/

static object LI22(V275,V276,V277,V278,V279)

object V275;object V276;object V277;object V278;object V279;
{	 VMB22 VMS22 VMV22
	bds_check;
TTL:;
	{object V280;
	object V281;
	V280= Cnil;
	V281= caaddr((V277));
	{register object V282;
	object V283;
	V283= cadr((V279));
	V282= (V281);
T762:;
	if(!(endp((V282)))){
	goto T763;}
	goto T759;
T763:;
	V284= structure_ref(car((V282)),VV[65],1);
	if(!((/* INLINE-ARGS */V284)==(VV[67]))){
	goto T769;}
	V285= car((V282));
	V286= structure_ref(car((V282)),VV[65],4);
	V287= make_cons(/* INLINE-ARGS */V285,/* INLINE-ARGS */V286);
	V280= make_cons(/* INLINE-ARGS */V287,(V280));
	goto T767;
T769:;
	V288= car((V282));
	{object V290= car((V283));
	if((V290!= VV[85]))goto T773;
	V289= VV[85];
	goto T772;
T773:;
	if((V290!= VV[138]))goto T774;
	V289= VV[138];
	goto T772;
T774:;
	if((V290!= VV[139]))goto T775;
	V289= VV[139];
	goto T772;
T775:;
	if((V290!= VV[140]))goto T776;
	V289= VV[140];
	goto T772;
T776:;
	V289= VV[70];}
T772:;
	(void)(structure_set(/* INLINE-ARGS */V288,VV[65],1,V289));
T767:;
	V291= car((V282));
	setq(VV[84],number_plus(symbol_value(VV[84]),small_fixnum(1)));
	(void)(structure_set(/* INLINE-ARGS */V291,VV[65],4,symbol_value(VV[84])));
	V282= cdr((V282));
	V283= cdr((V283));
	goto T762;}
T759:;
	(void)((VFUN_NARGS=2,(*(LnkLI299))(VV[141],(V275))));
	princ_str("\nstatic ",VV[27]);
	V292= (*(LnkLI268))(caddr((V279)));
	(void)((*(LnkLI265))(/* INLINE-ARGS */V292));
	princ_str("LI",VV[27]);
	(void)((*(LnkLI265))((V276)));
	princ_str("();",VV[27]);
	princ_str("\nstatic ",VV[21]);
	V293= (*(LnkLI268))(caddr((V279)));
	(void)((*(LnkLI262))(/* INLINE-ARGS */V293));
	princ_str("LI",VV[21]);
	(void)((*(LnkLI262))((V276)));
	princ_char(40,VV[21]);
	(void)((*(LnkLI300))((V281),cadr((V279))));
	{object V294;
	V294= symbol_value(VV[132]);
	if((symbol_value(VV[143]))==Cnil){
	goto T800;}
	base[1]= make_cons((V275),(V281));
	goto T798;
T800:;
	base[1]= Cnil;
T798:;
	bds_bind(VV[142],base[1]);
	bds_bind(VV[130],symbol_value(VV[130]));
	princ_str("\n{	",VV[21]);
	V295= structure_ref(cadr((V277)),VV[58],1);
	(void)((*(LnkLI301))(/* INLINE-ARGS */V295,(V276),VV[144]));
	princ_str(" VMB",VV[21]);
	(void)((*(LnkLI262))((V294)));
	princ_str(" VMS",VV[21]);
	(void)((*(LnkLI262))((V294)));
	princ_str(" VMV",VV[21]);
	(void)((*(LnkLI262))((V294)));
	if(((V278))==Cnil){
	goto T812;}
	princ_str("\n	bds_check;",VV[21]);
T812:;
	if((symbol_value(VV[145]))==Cnil){
	goto T816;}
	princ_str("\n	ihs_check;",VV[21]);
T816:;
	if(((VV[142]->s.s_dbind))==Cnil){
	goto T820;}
	(VV[130]->s.s_dbind)= make_cons(VV[146],(VV[130]->s.s_dbind));
	princ_str("\nTTL:;",VV[21]);
T820:;
	{register object V296;
	register object V297;
	V296= (V280);
	V297= car((V296));
T830:;
	if(!(endp((V296)))){
	goto T831;}
	goto T826;
T831:;
	princ_str("\n	bds_bind(VV[",VV[21]);
	(void)((*(LnkLI262))(cdr((V297))));
	princ_str("],V",VV[21]);
	V298= structure_ref(car((V297)),VV[65],4);
	(void)((*(LnkLI262))(/* INLINE-ARGS */V298));
	princ_str(");",VV[21]);
	(VV[130]->s.s_dbind)= make_cons(VV[147],(VV[130]->s.s_dbind));
	(void)(structure_set(car((V297)),VV[65],1,VV[67]));
	(void)(structure_set(car((V297)),VV[65],4,cdr((V297))));
	V296= cdr((V296));
	V297= car((V296));
	goto T830;}
T826:;
	base[3]= caddr(cddr((V277)));
	vs_top=(vs_base=base+3)+1;
	(void) (*Lnk302)();
	vs_top=sup;
	princ_str("\n}",VV[21]);
	{object V299 = (*(LnkLI303))((V294),caddr((V279)));
	bds_unwind1;
	bds_unwind1;
	VMR22(V299)}}}
}
/*	local entry for function SET-UP-VAR-CVS	*/

static object LI23(V301)

object V301;
{	 VMB23 VMS23 VMV23
TTL:;
	if((symbol_value(VV[148]))==Cnil){
	goto T855;}
	V302= (*(LnkLI304))();
	{object V303 = structure_set((V301),VV[65],2,/* INLINE-ARGS */V302);
	VMR23(V303)}
T855:;
	V304= (*(LnkLI305))();
	{object V305 = structure_set((V301),VV[65],2,/* INLINE-ARGS */V304);
	VMR23(V305)}
}
/*	local entry for function T3DEFUN-VARARG	*/

static object LI24(V310,V311,V312,V313)

object V310;object V311;object V312;object V313;
{	 VMB24 VMS24 VMV24
	bds_check;
TTL:;
	{object V314;
	register object V315;
	object V316;
	object V317;
	object V318;
	object V319;
	object V320;
	object V321;
	V314= Cnil;
	bds_bind(VV[148],Cnil);
	base[1]= Cnil;
	V315= Cnil;
	V316= Ct;
	V317= Cnil;
	bds_bind(VV[149],small_fixnum(0));
	V318= Cnil;
	V319= caddr((V312));
	V320= Cnil;{object V322;
	V322= caddr((V319));
	if(V322==Cnil)goto T865;
	V321= V322;
	goto T864;
T865:;}{object V323;
	V323= cadr((V319));
	if(V323==Cnil)goto T867;
	V321= V323;
	goto T864;
T867:;}
	V321= cadddr((V319));
T864:;
	{object V324;
	register object V325;
	V324= car((V319));
	V325= car((V324));
T873:;
	if(!(endp((V324)))){
	goto T874;}
	goto T869;
T874:;
	setq(VV[84],number_plus(symbol_value(VV[84]),small_fixnum(1)));
	V326= list(2,VV[150],symbol_value(VV[84]));
	V314= make_cons(/* INLINE-ARGS */V326,(V314));
	V324= cdr((V324));
	V325= car((V324));
	goto T873;}
T869:;
	(void)((VFUN_NARGS=2,(*(LnkLI299))(VV[151],(V310))));
	princ_str("\nstatic object LI",VV[27]);
	(void)((*(LnkLI265))((V311)));
	princ_str("();",VV[27]);
	princ_str("\nstatic object LI",VV[21]);
	(void)((*(LnkLI262))((V311)));
	princ_char(40,VV[21]);
	(void)((*(LnkLI306))((V314)));
	if(((V321))==Cnil){
	goto T896;}
	if(((V314))==Cnil){
	goto T899;}
	princ_char(44,VV[21]);
T899:;
	princ_str("va_alist",VV[21]);
T896:;
	princ_char(41,VV[21]);
	if(((V314))==Cnil){
	goto T906;}
	princ_str("\n	object ",VV[21]);
	(void)((*(LnkLI306))((V314)));
	princ_char(59,VV[21]);
T906:;
	if(((V321))==Cnil){
	goto T913;}
	princ_str("\n	va_dcl ",VV[21]);
T913:;
	{object V327;
	V327= symbol_value(VV[132]);
	if(symbol_value(VV[143])==Cnil){
	base[5]= Cnil;
	goto T918;}
	if((caddr((V319)))==Cnil){
	goto T919;}
	base[5]= Cnil;
	goto T918;
T919:;
	{object V328;
	object V329;
	V328= car((V319));
	V329= car((V328));
T926:;
	if(!(endp((V328)))){
	goto T927;}
	goto T921;
T927:;
	if((structure_ref((V329),VV[65],3))==Cnil){
	goto T931;}
	goto T922;
T931:;
	V328= cdr((V328));
	V329= car((V328));
	goto T926;}
T922:;
	base[5]= Cnil;
	goto T918;
T921:;
	if((cadr((V319)))==Cnil){
	goto T939;}
	base[5]= Cnil;
	goto T918;
T939:;
	if((car(cddddr((V319))))==Cnil){
	goto T941;}
	base[5]= Cnil;
	goto T918;
T941:;
	base[5]= make_cons((V310),car((V319)));
T918:;
	bds_bind(VV[142],base[5]);
	bds_bind(VV[130],symbol_value(VV[130]));
	princ_str("\n{	",VV[21]);
	if(((V321))==Cnil){
	goto T945;}
	princ_str("\n	va_list ap;",VV[21]);
T945:;
	princ_str("\n	int narg = VFUN_NARGS;",VV[21]);
	V330= structure_ref(cadr((V312)),VV[58],1);
	(void)((*(LnkLI301))(/* INLINE-ARGS */V330,(V311),VV[144]));
	princ_str(" VMB",VV[21]);
	(void)((*(LnkLI262))((V327)));
	princ_str(" VMS",VV[21]);
	(void)((*(LnkLI262))((V327)));
	princ_str(" VMV",VV[21]);
	(void)((*(LnkLI262))((V327)));
	if(((V313))==Cnil){
	goto T959;}
	princ_str("\n	bds_check;",VV[21]);
T959:;
	if((symbol_value(VV[145]))==Cnil){
	goto T963;}
	princ_str("\n	ihs_check;",VV[21]);
T963:;
	if((V321)!=Cnil){
	goto T967;}
	princ_str("\n	if ( narg!= ",VV[21]);
	V331 = make_fixnum(length((V314)));
	(void)((*(LnkLI262))(V331));
	princ_str(") vfun_wrong_number_of_args(small_fixnum(",VV[21]);
	V332 = make_fixnum(length((V314)));
	(void)((*(LnkLI262))(V332));
	princ_str("));",VV[21]);
T967:;
	{object V333;
	object V334;
	V333= car((V319));
	V334= car((V333));
T978:;
	if(!(endp((V333)))){
	goto T979;}
	goto T974;
T979:;
	base[9]= (V334);
	vs_top=(vs_base=base+9)+1;
	L25(base);
	vs_top=sup;
	V333= cdr((V333));
	V334= car((V333));
	goto T978;}
T974:;
	{object V335;
	object V336;
	V335= cadr((V319));
	V336= car((V335));
T994:;
	if(!(endp((V335)))){
	goto T995;}
	goto T990;
T995:;
	base[9]= car((V336));
	vs_top=(vs_base=base+9)+1;
	L25(base);
	vs_top=sup;
	if((caddr((V336)))==Cnil){
	goto T1001;}
	base[9]= caddr((V336));
	vs_top=(vs_base=base+9)+1;
	L25(base);
	vs_top=sup;
T1001:;
	V335= cdr((V335));
	V336= car((V335));
	goto T994;}
T990:;
	if((caddr((V319)))==Cnil){
	goto T1010;}
	base[7]= caddr((V319));
	vs_top=(vs_base=base+7)+1;
	L25(base);
	vs_top=sup;
T1010:;
	{object V337;
	object V338;
	V337= car(cddddr((V319)));
	V338= car((V337));
T1017:;
	if(!(endp((V337)))){
	goto T1018;}
	goto T973;
T1018:;
	base[9]= cadr((V338));
	vs_top=(vs_base=base+9)+1;
	L25(base);
	vs_top=sup;
	if((cadddr((V338)))==Cnil){
	goto T1024;}
	base[9]= cadddr((V338));
	vs_top=(vs_base=base+9)+1;
	L25(base);
	vs_top=sup;
T1024:;
	V337= cdr((V337));
	V338= car((V337));
	goto T1017;}
T973:;
	if((symbol_value(VV[152]))!=Cnil){
	goto T1035;}
	if((symbol_value(VV[153]))==Cnil){
	goto T1033;}
T1035:;
	if((car((V319)))==Cnil){
	goto T1033;}
	princ_str("\n	if(narg <",VV[21]);
	V339 = make_fixnum(length(car((V319))));
	(void)((*(LnkLI262))(V339));
	princ_str(") too_few_arguments();",VV[21]);
T1033:;
	{object V340;
	object V341;
	V340= car((V319));
	V341= car((V340));
T1047:;
	if(!(endp((V340)))){
	goto T1048;}
	goto T1043;
T1048:;
	(void)((*(LnkLI307))((V341)));
	V340= cdr((V340));
	V341= car((V340));
	goto T1047;}
T1043:;
	{object V342;
	object V343;
	V342= cadr((V319));
	V343= car((V342));
T1062:;
	if(!(endp((V342)))){
	goto T1063;}
	goto T1058;
T1063:;
	(void)((*(LnkLI307))(car((V343))));
	V342= cdr((V342));
	V343= car((V342));
	goto T1062;}
T1058:;
	if((caddr((V319)))==Cnil){
	goto T1073;}
	(void)((*(LnkLI307))(caddr((V319))));
T1073:;
	if(((VV[148]->s.s_dbind))==Cnil){
	goto T1079;}
	V317= symbol_value(VV[125]);
	goto T1077;
T1079:;
	V317= symbol_value(VV[137]);
T1077:;
	{object V344;
	object V345;
	V344= car(cddddr((V319)));
	V345= car((V344));
T1085:;
	if(!(endp((V344)))){
	goto T1086;}
	goto T1081;
T1086:;
	(void)((*(LnkLI307))(cadr((V345))));
	V344= cdr((V344));
	V345= car((V344));
	goto T1085;}
T1081:;
	{object V346;
	object V347;
	V346= car(cddddr((V319)));
	V347= car((V346));
T1100:;
	if(!(endp((V346)))){
	goto T1101;}
	goto T1096;
T1101:;
	(void)((*(LnkLI307))(cadddr((V347))));
	V346= cdr((V346));
	V347= car((V346));
	goto T1100;}
T1096:;
	{object V348;
	object V349;
	V349= car((V319));
	V348= (V314);
T1114:;
	if(((V348))!=Cnil){
	goto T1115;}
	goto T1111;
T1115:;
	(void)((*(LnkLI308))(car((V349)),car((V348))));
	V348= cdr((V348));
	V349= cdr((V349));
	goto T1114;}
T1111:;
	if((cadr((V319)))==Cnil){
	goto T1124;}
	bds_bind(VV[129],symbol_value(VV[129]));
	bds_bind(VV[130],(VV[130]->s.s_dbind));
	bds_bind(VV[128],symbol_value(VV[128]));
	princ_str("\n	narg = narg - ",VV[21]);
	V350 = make_fixnum(length((V314)));
	(void)((*(LnkLI262))(V350));
	princ_char(59,VV[21]);
	{object V351;
	object V352;
	V351= cadr((V319));
	V352= car((V351));
T1135:;
	if(!(endp((V351)))){
	goto T1136;}
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	goto T1127;
T1136:;
	setq(VV[154],number_plus(symbol_value(VV[154]),small_fixnum(1)));
	V353= make_cons(symbol_value(VV[154]),Cnil);
	V315= make_cons(/* INLINE-ARGS */V353,(V315));
	princ_str("\n	if (",VV[21]);
	if((cdr((V315)))==Cnil){
	goto T1148;}
	V354= VV[155];
	goto T1146;
T1148:;
	V354= VV[156];
T1146:;
	(void)((*(LnkLI262))(V354));
	princ_str("narg <= 0) ",VV[21]);
	if(type_of(car((V315)))!=t_cons)FEwrong_type_argument(Scons,car((V315)));
	(car((V315)))->c.c_cdr = Ct;
	(void)(car((V315)));
	princ_str("goto T",VV[21]);
	(void)((*(LnkLI262))(car(car((V315)))));
	princ_char(59,VV[21]);
	princ_str("\n	else {",VV[21]);
	if(((V320))!=Cnil){
	goto T1158;}
	V320= Ct;
	princ_str("\n	va_start(ap);",VV[21]);
T1158:;
	V355= car((V352));
	V356= make_cons(VV[157],Cnil);
	(void)((*(LnkLI308))(/* INLINE-ARGS */V355,/* INLINE-ARGS */V356));
	princ_char(125,VV[21]);
	if((caddr((V352)))==Cnil){
	goto T1167;}
	(void)((*(LnkLI308))(caddr((V352)),Ct));
T1167:;
	V351= cdr((V351));
	V352= car((V351));
	goto T1135;}
T1127:;
	V315= nreverse((V315));
	{object V357;
	setq(VV[154],number_plus(symbol_value(VV[154]),small_fixnum(1)));
	V357= make_cons(symbol_value(VV[154]),Cnil);
	princ_str("\n	--narg; ",VV[21]);
	if(type_of((V357))!=t_cons)FEwrong_type_argument(Scons,(V357));
	((V357))->c.c_cdr = Ct;
	princ_str("goto T",VV[21]);
	(void)((*(LnkLI262))(car((V357))));
	princ_char(59,VV[21]);
	{object V358;
	object V359;
	V358= cadr((V319));
	V359= car((V358));
T1190:;
	if(!(endp((V358)))){
	goto T1191;}
	goto T1186;
T1191:;
	if((cdr(car((V315))))==Cnil){
	goto T1195;}
	princ_str("\nT",VV[21]);
	(void)((*(LnkLI262))(car(car((V315)))));
	princ_str(":;",VV[21]);
T1195:;
	{object V360;
	V360= car((V315));
	V315= cdr((V315));}
	(void)((*(LnkLI309))(car((V359)),cadr((V359))));
	if((caddr((V359)))==Cnil){
	goto T1206;}
	(void)((*(LnkLI308))(caddr((V359)),Cnil));
T1206:;
	V358= cdr((V358));
	V359= car((V358));
	goto T1190;}
T1186:;
	if((cdr((V357)))==Cnil){
	goto T1124;}
	princ_str("\nT",VV[21]);
	(void)((*(LnkLI262))(car((V357))));
	princ_str(":;",VV[21]);}
T1124:;
	if((caddr((V319)))==Cnil){
	goto T1219;}
	V318= (VFUN_NARGS=0,(*(LnkLI310))());
	{object V361;
	V361= cadr((V319));
	if(((V361))==Cnil){
	goto T1227;}
	goto T1224;
T1227:;
	princ_str("\n	narg= narg - ",VV[21]);
	V362 = make_fixnum(length(car((V319))));
	(void)((*(LnkLI262))(V362));
	princ_char(59,VV[21]);}
T1224:;
	if(((V320))!=Cnil){
	goto T1232;}
	V320= Ct;
	princ_str("\n	va_start(ap);",VV[21]);
T1232:;
	princ_str("\n	V",VV[21]);
	(void)((*(LnkLI262))((V318)));
	princ_str(" = ",VV[21]);
	V363= structure_ref(caddr((V319)),VV[65],5);
	if(!((/* INLINE-ARGS */V363)==(VV[159]))){
	goto T1243;}
	base[7]= Ct;
	goto T1242;
T1243:;
	base[7]= symbol_value(VV[158]);
T1242:;
	bds_bind(VV[158],base[7]);
	if((cadddr((V319)))==Cnil){
	goto T1247;}
	if(((VV[158]->s.s_dbind))==Cnil){
	goto T1250;}
	princ_str("(ALLOCA_CONS(narg),ON_STACK_MAKE_LIST(narg));",VV[21]);
	goto T1245;
T1250:;
	princ_str("make_list(narg);",VV[21]);
	goto T1245;
T1247:;
	if(((VV[158]->s.s_dbind))==Cnil){
	goto T1255;}
	princ_str("(ALLOCA_CONS(narg),ON_STACK_LIST_VECTOR(narg,ap));",VV[21]);
	goto T1245;
T1255:;
	princ_str("list_vector(narg,ap);",VV[21]);
T1245:;
	V364= caddr((V319));
	V365= list(2,VV[150],(V318));
	V366= (*(LnkLI308))(/* INLINE-ARGS */V364,/* INLINE-ARGS */V365);
	bds_unwind1;
T1219:;
	if((cadddr((V319)))==Cnil){
	goto T1259;}
	{object V367;
	V367= caddr((V319));
	if(((V367))==Cnil){
	goto T1265;}
	goto T1262;
T1265:;
	{object V368;
	V368= cadr((V319));
	if(((V368))==Cnil){
	goto T1269;}
	goto T1262;
T1269:;
	princ_str("\n	narg= narg - ",VV[21]);
	V369 = make_fixnum(length(car((V319))));
	(void)((*(LnkLI262))(V369));
	princ_char(59,VV[21]);}}
T1262:;
	if(((V320))!=Cnil){
	goto T1274;}
	V320= Ct;
	princ_str("\n	va_start(ap);",VV[21]);
T1274:;
	{object V370;
	object V371= car(cddddr((V319)));
	if(endp(V371)){
	V316= Cnil;
	goto T1281;}
	base[7]=V370=MMcons(Cnil,Cnil);
T1282:;
	(V370->c.c_car)= caddr((V371->c.c_car));
	if(endp(V371=MMcdr(V371))){
	V316= base[7];
	goto T1281;}
	V370=MMcdr(V370)=MMcons(Cnil,Cnil);
	goto T1282;}
T1281:;
	{object V372;
	object V373;
	V373= make_fixnum(length(car(cddddr((V319)))));
	V372= Cnil;
	{register object V374;
	object V375;
	object V376;
	V374= (V316);
	V375= car(cddddr((V319)));
	V376= car((V375));
T1290:;
	if(((V374))!=Cnil){
	goto T1291;}
	goto T1285;
T1291:;
	if(!((caar((V374)))==(VV[160]))){
	goto T1296;}
	if((caddr(car((V374))))==(Cnil)){
	goto T1295;}
T1296:;
	V372= Ct;
T1295:;
	if(!((caar((V374)))==(VV[160]))){
	goto T1302;}
	{object V377;
	V377= caddr(car((V374)));
	if(!(((V377))==(Cnil))){
	goto T1308;}
	goto T1306;
T1308:;
	if(type_of((V377))==t_cons){
	goto T1310;}
	goto T1302;
T1310:;
	{register object x= car((V377)),V378= VV[161];
	while(!endp(V378))
	if(eql(x,V378->c.c_car)){
	goto T1306;
	}else V378=V378->c.c_cdr;
	goto T1302;}}
T1306:;
	V379= structure_ref(cadddr((V376)),VV[65],1);
	if((/* INLINE-ARGS */V379)==(VV[162])){
	goto T1301;}
T1302:;
	V372= Ct;
	if(type_of(V374)!=t_cons)FEwrong_type_argument(Scons,V374);
	(V374)->c.c_car = small_fixnum(0);
T1301:;
	V374= cdr((V374));
	V375= cdr((V375));
	V376= car((V375));
	goto T1290;}
T1285:;
	if(!((length((V316)))>(15))){
	goto T1323;}
	V372= Ct;
T1323:;
	princ_str("\n	{",VV[21]);
	vs_base=vs_top;
	(void) (*Lnk311)();
	vs_top=sup;
	bds_bind(VV[21],symbol_value(VV[27]));
	if(((V372))==Cnil){
	goto T1331;}
	princ_char(10,VV[27]);
	princ_str("static int VK",VV[21]);
	(void)((*(LnkLI262))((V311)));
	princ_str("defaults[",VV[21]);
	V382 = make_fixnum(length((V316)));
	(void)((*(LnkLI262))(V382));
	princ_str("]={",VV[21]);
	{object V383;
	register object V384;
	V383= (V316);
	V384= Cnil;
T1343:;
	if(((V383))!=Cnil){
	goto T1344;}
	goto T1341;
T1344:;
	if(!(eql(car((V383)),small_fixnum(0)))){
	goto T1350;}
	princ_str("-1",VV[21]);
	goto T1348;
T1350:;
	V384= caddr(car((V383)));
	if(!(((V384))==(Cnil))){
	goto T1354;}
	princ_str("-2",VV[21]);
	goto T1348;
T1354:;
	if(!(type_of((V384))==t_cons)){
	goto T1359;}
	if(!((car((V384)))==(VV[163]))){
	goto T1359;}
	(void)((*(LnkLI262))(cadr((V384))));
	goto T1348;
T1359:;
	if(!(type_of((V384))==t_cons)){
	goto T1365;}
	if(!((car((V384)))==(VV[164]))){
	goto T1365;}
	V385= (*(LnkLI312))(caddr((V384)));
	(void)((*(LnkLI262))(/* INLINE-ARGS */V385));
	goto T1348;
T1365:;
	(void)((*(LnkLI313))());
T1348:;
	if((cdr((V383)))==Cnil){
	goto T1370;}
	princ_char(44,VV[21]);
T1370:;
	V383= cdr((V383));
	goto T1343;}
T1341:;
	princ_str("};",VV[21]);
T1331:;
	princ_char(10,VV[27]);
	princ_str("static struct { short n,allow_other_keys;",VV[21]);
	princ_str("int *defaults;",VV[21]);
	princ_str("\n	 int keys[",VV[21]);
	(void)((*(LnkLI262))((V373)));
	princ_str("];",VV[21]);
	princ_str("} LI",VV[21]);
	(void)((*(LnkLI262))((V311)));
	princ_str("key=",VV[21]);
	princ_char(123,VV[21]);
	V386 = make_fixnum(length(car(cddddr((V319)))));
	(void)((*(LnkLI262))(V386));
	princ_char(44,VV[21]);
	if((cadr(cddddr((V319))))==Cnil){
	goto T1397;}
	V387= small_fixnum(1);
	goto T1395;
T1397:;
	V387= small_fixnum(0);
T1395:;
	(void)((*(LnkLI262))(V387));
	princ_char(44,VV[21]);
	if(((V372))==Cnil){
	goto T1402;}
	princ_str("VK",VV[21]);
	(void)((*(LnkLI262))((V311)));
	princ_str("defaults",VV[21]);
	goto T1400;
T1402:;
	princ_str("(int *)Cstd_key_defaults",VV[21]);
T1400:;
	if((car(cddddr((V319))))==Cnil){
	goto T1408;}
	princ_str(",{",VV[21]);
	{object V388;
	V388= reverse(car(cddddr((V319))));
T1416:;
	if(((V388))!=Cnil){
	goto T1417;}
	goto T1413;
T1417:;
	V389= (*(LnkLI314))(caar((V388)));
	(void)((*(LnkLI262))(/* INLINE-ARGS */V389));
	if((cdr((V388)))==Cnil){
	goto T1423;}
	princ_char(44,VV[21]);
T1423:;
	V388= cdr((V388));
	goto T1416;}
T1413:;
	princ_char(125,VV[21]);
T1408:;
	princ_str("};",VV[21]);
	bds_unwind1;
	if((caddr((V319)))==Cnil){
	goto T1434;}
	princ_str("\n	parse_key_rest(",VV[21]);
	V390= list(2,VV[150],(V318));
	(void)((*(LnkLI262))(/* INLINE-ARGS */V390));
	princ_char(44,VV[21]);
	goto T1432;
T1434:;
	princ_str("\n	parse_key_new(",VV[21]);
T1432:;
	if(!(eql(small_fixnum(0),symbol_value(VV[137])))){
	goto T1440;}
	setq(VV[137],small_fixnum(1));
T1440:;
	princ_str("narg,",VV[21]);
	if(((VV[148]->s.s_dbind))==Cnil){
	goto T1448;}
	V391= VV[165];
	goto T1446;
T1448:;
	V391= VV[166];
T1446:;
	(void)((*(LnkLI262))(V391));
	princ_char(43,VV[21]);
	(void)((*(LnkLI262))((V317)));
	princ_str(",&LI",VV[21]);
	(void)((*(LnkLI262))((V311)));
	princ_str("key,ap);",VV[21]);}
T1259:;
	{object V392;
	register object V393;
	V392= car(cddddr((V319)));
	V393= car((V392));
T1459:;
	if(!(endp((V392)))){
	goto T1460;}
	goto T1455;
T1460:;
	{object V395;
	V395= car((V316));
	V316= cdr((V316));
	V394= (V395);}
	if(eql(small_fixnum(0),V394)){
	goto T1466;}
	(void)((*(LnkLI315))(cadr((V393))));
	goto T1464;
T1466:;
	princ_str("\n	if(",VV[21]);
	V396= structure_ref(cadr((V393)),VV[65],2);
	(void)((*(LnkLI316))(/* INLINE-ARGS */V396));
	princ_str("==0){",VV[21]);
	bds_bind(VV[129],symbol_value(VV[129]));
	bds_bind(VV[130],(VV[130]->s.s_dbind));
	bds_bind(VV[128],symbol_value(VV[128]));
	V397= (*(LnkLI309))(cadr((V393)),caddr((V393)));
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	V398= structure_ref(cadddr((V393)),VV[65],1);
	if((/* INLINE-ARGS */V398)==(VV[162])){
	goto T1478;}
	(void)((*(LnkLI308))(cadddr((V393)),Cnil));
T1478:;
	princ_str("\n	}else{",VV[21]);
	(void)((*(LnkLI315))(cadr((V393))));
	V399= structure_ref(cadddr((V393)),VV[65],1);
	if((/* INLINE-ARGS */V399)==(VV[162])){
	goto T1484;}
	(void)((*(LnkLI308))(cadddr((V393)),Ct));
T1484:;
	princ_char(125,VV[21]);
T1464:;
	V392= cdr((V392));
	V393= car((V392));
	goto T1459;}
T1455:;
	if(((VV[142]->s.s_dbind))==Cnil){
	goto T1493;}
	(VV[130]->s.s_dbind)= make_cons(VV[146],(VV[130]->s.s_dbind));
	princ_str("\nTTL:;",VV[21]);
T1493:;
	base[7]= caddr(cddr((V312)));
	vs_top=(vs_base=base+7)+1;
	(void) (*Lnk302)();
	vs_top=sup;
	princ_char(125,VV[21]);
	if((base[1])==Cnil){
	goto T1503;}
	princ_str("\n	}",VV[21]);
T1503:;
	(void)((*(LnkLI317))());
	V400= get((V310),VV[74],Cnil);
	{object V401 = (*(LnkLI303))((V327),V400);
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	VMR24(V401)}}}
}
/*	local entry for function T3DEFUN-NORMAL	*/

static object LI26(V406,V407,V408,V409)

object V406;register object V407;object V408;object V409;
{	 VMB25 VMS25 VMV25
TTL:;
	(void)((VFUN_NARGS=2,(*(LnkLI299))(VV[167],(V406))));
	if(!(type_of((V407))==t_fixnum||
type_of((V407))==t_bignum||
type_of((V407))==t_ratio||
type_of((V407))==t_shortfloat||
type_of((V407))==t_longfloat||
type_of((V407))==t_complex)){
	goto T1512;}
	princ_str("\nstatic L",VV[21]);
	(void)((*(LnkLI262))((V407)));
	princ_str("()",VV[21]);
	goto T1510;
T1512:;
	princ_char(10,VV[21]);
	(void)((*(LnkLI262))((V407)));
	princ_str("()",VV[21]);
T1510:;
	princ_str("\n{",VV[21]);
	princ_str("register object *",VV[21]);
	(void)((*(LnkLI262))(symbol_value(VV[16])));
	princ_str("base=vs_base;",VV[21]);
	V410= structure_ref(cadr((V408)),VV[58],1);
	(void)((*(LnkLI301))(/* INLINE-ARGS */V410,(V407),VV[144]));
	princ_str("\n	register object *",VV[21]);
	(void)((*(LnkLI262))(symbol_value(VV[16])));
	princ_str("sup=base+VM",VV[21]);
	(void)((*(LnkLI262))(symbol_value(VV[132])));
	princ_char(59,VV[21]);
	princ_str(" VC",VV[21]);
	(void)((*(LnkLI262))(symbol_value(VV[132])));
	if((symbol_value(VV[152]))==Cnil){
	goto T1537;}
	princ_str("\n	vs_reserve(VM",VV[21]);
	(void)((*(LnkLI262))(symbol_value(VV[132])));
	princ_str(");",VV[21]);
	goto T1535;
T1537:;
	princ_str("\n	vs_check;",VV[21]);
T1535:;
	if(((V409))==Cnil){
	goto T1543;}
	princ_str("\n	bds_check;",VV[21]);
T1543:;
	if((symbol_value(VV[145]))==Cnil){
	goto T1547;}
	princ_str("\n	ihs_check;",VV[21]);
T1547:;
	(void)((VFUN_NARGS=3,(*(LnkLI318))(caddr((V408)),caddr(cddr((V408))),(V406))));
	princ_str("\n}",VV[21]);
	V411= make_cons(symbol_value(VV[132]),symbol_value(VV[126]));
	setq(VV[29],make_cons(/* INLINE-ARGS */V411,symbol_value(VV[29])));
	princ_str("\n#define VC",VV[27]);
	(void)((*(LnkLI265))(symbol_value(VV[132])));
	{object V412 = (*(LnkLI319))();
	VMR25(V412)}
}
/*	local entry for function WT-V*-MACROS	*/

static object LI27(V415,V416)

register object V415;object V416;
{	 VMB26 VMS26 VMV26
TTL:;
	V417= make_cons((V415),symbol_value(VV[126]));
	setq(VV[29],make_cons(/* INLINE-ARGS */V417,symbol_value(VV[29])));
	if(!(number_compare(small_fixnum(0),symbol_value(VV[126]))==0)){
	goto T1563;}
	if((symbol_value(VV[134]))!=Cnil){
	goto T1563;}
	if((symbol_value(VV[136]))!=Cnil){
	goto T1563;}
	princ_str("\n#define VMB",VV[27]);
	(void)((*(LnkLI265))((V415)));
	goto T1561;
T1563:;
	princ_str("\n#define VMB",VV[27]);
	(void)((*(LnkLI265))((V415)));
	princ_char(32,VV[27]);
	princ_str("register object *",VV[27]);
	(void)((*(LnkLI265))(symbol_value(VV[16])));
	princ_str("base=vs_top;",VV[27]);
T1561:;
	(void)((*(LnkLI319))());
	if((symbol_value(VV[134]))==Cnil){
	goto T1580;}
	princ_str("\n#define VMS",VV[27]);
	(void)((*(LnkLI265))((V415)));
	princ_char(32,VV[27]);
	princ_str(" register object *",VV[27]);
	(void)((*(LnkLI265))(symbol_value(VV[16])));
	princ_str("sup=vs_top+",VV[27]);
	(void)((*(LnkLI265))(symbol_value(VV[126])));
	princ_str(";vs_top=sup;",VV[27]);
	goto T1578;
T1580:;
	if(!(number_compare(small_fixnum(0),symbol_value(VV[126]))==0)){
	goto T1591;}
	princ_str("\n#define VMS",VV[27]);
	(void)((*(LnkLI265))((V415)));
	goto T1578;
T1591:;
	princ_str("\n#define VMS",VV[27]);
	(void)((*(LnkLI265))((V415)));
	princ_str(" vs_top += ",VV[27]);
	(void)((*(LnkLI265))(symbol_value(VV[126])));
	princ_char(59,VV[27]);
T1578:;
	if(!(number_compare(small_fixnum(0),symbol_value(VV[126]))==0)){
	goto T1602;}
	princ_str("\n#define VMV",VV[27]);
	(void)((*(LnkLI265))((V415)));
	goto T1600;
T1602:;
	if((symbol_value(VV[152]))==Cnil){
	goto T1607;}
	princ_str("\n#define VMV",VV[27]);
	(void)((*(LnkLI265))((V415)));
	princ_str(" vs_reserve(",VV[27]);
	(void)((*(LnkLI265))(symbol_value(VV[126])));
	princ_str(");",VV[27]);
	goto T1600;
T1607:;
	princ_str("\n#define VMV",VV[27]);
	(void)((*(LnkLI265))((V415)));
	princ_str(" vs_check;",VV[27]);
T1600:;
	if(!(number_compare(small_fixnum(0),symbol_value(VV[126]))==0)){
	goto T1618;}
	princ_str("\n#define VMR",VV[27]);
	(void)((*(LnkLI265))((V415)));
	princ_str("(VMT",VV[27]);
	(void)((*(LnkLI265))((V415)));
	princ_str(") return(VMT",VV[27]);
	(void)((*(LnkLI265))((V415)));
	princ_str(");",VV[27]);
	{object V418 = Cnil;
	VMR26(V418)}
T1618:;
	princ_str("\n#define VMR",VV[27]);
	(void)((*(LnkLI265))((V415)));
	princ_str("(VMT",VV[27]);
	(void)((*(LnkLI265))((V415)));
	princ_str(") vs_top=base ; return(VMT",VV[27]);
	(void)((*(LnkLI265))((V415)));
	princ_str(");",VV[27]);
	{object V419 = Cnil;
	VMR26(V419)}
}
/*	local entry for function WT-REQUIREDS	*/

static object LI28(V422,V423)

object V422;object V423;
{	 VMB27 VMS27 VMV27
TTL:;
	{register object V424;
	V424= (V422);
T1636:;
	if(!(endp((V424)))){
	goto T1637;}
	goto T1634;
T1637:;
	{register object V425;
	setq(VV[84],number_plus(symbol_value(VV[84]),small_fixnum(1)));
	V425= symbol_value(VV[84]);
	(void)(structure_set(car((V424)),VV[65],4,(V425)));
	princ_char(86,VV[21]);
	(void)((*(LnkLI262))((V425)));}
	if(endp(cdr((V424)))){
	goto T1647;}
	princ_char(44,VV[21]);
T1647:;
	V424= cdr((V424));
	goto T1636;}
T1634:;
	princ_str(")\n",VV[21]);
	if(((V422))==Cnil){
	goto T1657;}
	princ_char(10,VV[21]);
	{register object V426;
	register object V427;
	register object V428;
	V426= (V422);
	V427= (V423);
	V428= Cnil;
T1661:;
	if(!(endp((V426)))){
	goto T1662;}
	princ_char(59,VV[21]);
	{object V429 = Cnil;
	VMR27(V429)}
T1662:;
	if(((V428))==Cnil){
	goto T1667;}
	princ_char(59,VV[21]);
T1667:;
	(void)((*(LnkLI262))(symbol_value(VV[16])));
	V430= (*(LnkLI320))(car((V426)));
	(void)((*(LnkLI262))(/* INLINE-ARGS */V430));
	V431= (*(LnkLI268))(car((V427)));
	(void)((*(LnkLI262))(/* INLINE-ARGS */V431));
	V428= car((V427));
	princ_char(86,VV[21]);
	V432= structure_ref(car((V426)),VV[65],4);
	(void)((*(LnkLI262))(/* INLINE-ARGS */V432));
	V426= cdr((V426));
	V427= cdr((V427));
	goto T1661;}
T1657:;
	{object V433 = Cnil;
	VMR27(V433)}
}
/*	local entry for function ADD-DEBUG-INFO	*/

static object LI29(V436,V437)

object V436;object V437;
{	 VMB28 VMS28 VMV28
TTL:;
	{object V438;
	V438= Cnil;
	{object V439;
	V439= (number_compare(symbol_value(VV[110]),small_fixnum(2))>=0?Ct:Cnil);
	if(((V439))==Cnil){
	goto T1687;}
	{object V440 = (V439);
	VMR28(V440)}
T1687:;
	if((get((V436),VV[111],Cnil))!=Cnil){
	goto T1690;}
	{object V441 = (VFUN_NARGS=2,(*(LnkLI321))(VV[168],(V436)));
	VMR28(V441)}
T1690:;
	(void)(remprop((V436),VV[111]));
	{register object V442;
	V442= small_fixnum(0);
	{register object V443;
	register object V444;
	V443= structure_ref(cadr((V437)),VV[58],1);
	V444= car((V443));
T1697:;
	if(!(endp((V443)))){
	goto T1698;}
	goto T1693;
T1698:;
	V445= structure_ref((V444),VV[65],2);
	if(!(type_of(/* INLINE-ARGS */V445)==t_cons)){
	goto T1702;}
	V446= structure_ref((V444),VV[65],2);
	if(!(type_of(cdr(/* INLINE-ARGS */V446))==t_fixnum)){
	goto T1702;}
	V447= structure_ref((V444),VV[65],2);
	{object V448= cdr(/* INLINE-ARGS */V447);
	V442= (number_compare((V442),V448)>=0?((V442)):V448);}
T1702:;
	V443= cdr((V443));
	V444= car((V443));
	goto T1697;}
T1693:;
	base[0]= one_plus((V442));
	vs_top=(vs_base=base+0)+1;
	Lmake_list();
	vs_top=sup;
	V438= vs_base[0];
	{register object V449;
	register object V450;
	V449= structure_ref(cadr((V437)),VV[58],1);
	V450= car((V449));
T1720:;
	if(!(endp((V449)))){
	goto T1721;}
	goto T1716;
T1721:;
	V451= structure_ref((V450),VV[65],2);
	if(!(type_of(/* INLINE-ARGS */V451)==t_cons)){
	goto T1725;}
	V452= structure_ref((V450),VV[65],2);
	if(!(type_of(cdr(/* INLINE-ARGS */V452))==t_fixnum)){
	goto T1725;}
	{object V453;
	register object V455;
	V456= structure_ref((V450),VV[65],2);
	V453= cdr(/* INLINE-ARGS */V456);
	V455= structure_ref((V450),VV[65],0);
	if(type_of(nthcdr(fixint((V453)),V438))!=t_cons)FEwrong_type_argument(Scons,nthcdr(fixint((V453)),V438));
	(nthcdr(fixint((V453)),V438))->c.c_car = (V455);
	(void)(nthcdr(fixint((V453)),V438));}
T1725:;
	V449= cdr((V449));
	V450= car((V449));
	goto T1720;}
T1716:;
	(void)(sputprop((V436),VV[112],(V438)));
	{object V457;
	V457= get((V436),VV[112],Cnil);
	if(((V457))==Cnil){
	goto T1741;}
	if((cdr((V457)))!=Cnil){
	goto T1740;}
	if((car((V457)))==Cnil){
	goto T1741;}
T1740:;
	V458= list(2,VV[87],(V436));
	V459= list(3,VV[112],/* INLINE-ARGS */V458,list(2,VV[87],(V457)));
	{object V460 = (VFUN_NARGS=1,(*(LnkLI287))(/* INLINE-ARGS */V459));
	VMR28(V460)}
T1741:;
	{object V461 = Cnil;
	VMR28(V461)}}}}}
}
/*	local entry for function ANALYZE-REGS	*/

static int LI30(V464,V465)

object V464;object V465;
{	 VMB29 VMS29 VMV29
TTL:;
	{object V466;
	V466= number_minus(symbol_value(VV[169]),(V465));
	if(!(number_compare(small_fixnum(0),symbol_value(VV[170]))==0)){
	goto T1749;}
	V467= (VFUN_NARGS=1,(*(LnkLI323))((V464)));
	{int V468 = (*(LnkLI322))(/* INLINE-ARGS */V467,(V466));
	VMR29(V468)}
T1749:;
	{register object V469;
	register object V470;
	V469= Cnil;
	V470= Cnil;
	{register object V471;
	register object V472;
	V471= (V464);
	V472= car((V471));
T1755:;
	if(!(endp((V471)))){
	goto T1756;}
	goto T1751;
T1756:;
	V474= structure_ref((V472),VV[65],5);
	{register object x= /* INLINE-ARGS */V474,V473= VV[171];
	while(!endp(V473))
	if(x==(V473->c.c_car)){
	goto T1763;
	}else V473=V473->c.c_cdr;
	goto T1762;}
T1763:;{object V475;
	{register object x= (V472),V476= (V470);
	while(!endp(V476))
	if(eql(x,V476->c.c_car)){
	V475= V476;
	goto T1765;
	}else V476=V476->c.c_cdr;
	V475= Cnil;}
T1765:;
	if(V475==Cnil)goto T1764;
	goto T1760;
T1764:;}
	V470= make_cons((V472),(V470));
	goto T1760;
T1762:;{object V477;
	{register object x= (V472),V478= (V469);
	while(!endp(V478))
	if(x==(V478->c.c_car)){
	V477= V478;
	goto T1768;
	}else V478=V478->c.c_cdr;
	V477= Cnil;}
T1768:;
	if(V477==Cnil)goto T1767;
	goto T1760;
T1767:;}
	V470= make_cons((V472),(V470));
T1760:;
	V471= cdr((V471));
	V472= car((V471));
	goto T1755;}
T1751:;
	(void)((*(LnkLI322))((V469),(V466)));
	{int V479 = (*(LnkLI322))((V470),symbol_value(VV[170]));
	VMR29(V479)}}}
}
/*	local entry for function ANALYZE-REGS1	*/

static int LI31(V482,V483)

object V482;object V483;
{	 VMB30 VMS30 VMV30
TTL:;
	{register int V484;
	register int V485;
	int V486;
	int V487;
	register int V488;
	V484= 0;
	V485= 3;
	V486= 100000;
	V487= fix((V483));
	V488= 0;
	V482= (VFUN_NARGS=1,(*(LnkLI323))((V482)));
T1784:;
	{register object V489;
	object V490;
	V489= (V482);
	V490= car((V489));
T1790:;
	if(!(endp((V489)))){
	goto T1791;}
	goto T1786;
T1791:;
	V484= fix(structure_ref((V490),VV[65],6));
	if(!((V484)>=(V485))){
	goto T1797;}
	V488= (V488)+(1);
	if(!((V484)<(V486))){
	goto T1802;}
	V486= V484;
T1802:;
	if(!((V488)>(V487))){
	goto T1797;}
	goto T1785;
T1797:;
	V489= cdr((V489));
	V490= car((V489));
	goto T1790;}
T1786:;
	if(!((V488)<(V487))){
	goto T1813;}
	V485= (V485)-(1);
T1813:;
	{register object V491;
	register object V492;
	V491= (V482);
	V492= car((V491));
T1821:;
	if(!(endp((V491)))){
	goto T1822;}
	goto T1817;
T1822:;
	{int V493= fix(structure_ref((V492),VV[65],6));
	if(!((/* INLINE-ARGS */V493)<(V485))){
	goto T1826;}}
	(void)(structure_set((V492),VV[65],6,small_fixnum(0)));
T1826:;
	V491= cdr((V491));
	V492= car((V491));
	goto T1821;}
T1817:;
	{int V494 = V485;
	VMR30(V494)}
T1785:;
	V488= 0;
	V485= (V486)+(1);
	V486= 1000000;
	goto T1784;}
}
/*	local entry for function WT-GLOBAL-ENTRY	*/

static object LI32(V499,V500,V501,V502)

object V499;object V500;object V501;object V502;
{	 VMB31 VMS31 VMV31
TTL:;
	if((get((V499),VV[98],Cnil))==Cnil){
	goto T1841;}
	{object V503 = Cnil;
	VMR31(V503)}
T1841:;
	(void)((VFUN_NARGS=2,(*(LnkLI299))(VV[174],(V499))));
	princ_str("\nstatic L",VV[21]);
	(void)((*(LnkLI262))((V500)));
	princ_str("()",VV[21]);
	princ_str("\n{	register object *base=vs_base;",VV[21]);
	if((symbol_value(VV[152]))!=Cnil){
	goto T1852;}
	if((symbol_value(VV[153]))==Cnil){
	goto T1851;}
T1852:;
	princ_str("\n	check_arg(",VV[21]);
	V504 = make_fixnum(length((V501)));
	(void)((*(LnkLI262))(V504));
	princ_str(");",VV[21]);
T1851:;
	princ_str("\n	base[0]=",VV[21]);
	{object V506= (V502);
	if((V506!= VV[85]))goto T1863;
	if(!(number_compare(small_fixnum(0),symbol_value(VV[110]))==0)){
	goto T1865;}
	V505= VV[175];
	goto T1862;
T1865:;
	V505= VV[176];
	goto T1862;
T1863:;
	if((V506!= VV[138]))goto T1867;
	V505= VV[177];
	goto T1862;
T1867:;
	if((V506!= VV[139]))goto T1868;
	V505= VV[178];
	goto T1862;
T1868:;
	if((V506!= VV[140]))goto T1869;
	V505= VV[179];
	goto T1862;
T1869:;
	V505= VV[180];}
T1862:;
	(void)((*(LnkLI262))(V505));
	princ_str("(LI",VV[21]);
	(void)((*(LnkLI262))((V500)));
	princ_char(40,VV[21]);
	{register object V507;
	register int V508;
	V508= 0;
	V507= (V501);
T1876:;
	if(!(endp((V507)))){
	goto T1877;}
	goto T1873;
T1877:;
	{object V510= car((V507));
	if((V510!= VV[85]))goto T1884;
	V509= VV[181];
	goto T1883;
T1884:;
	if((V510!= VV[138]))goto T1885;
	V509= VV[182];
	goto T1883;
T1885:;
	if((V510!= VV[139]))goto T1886;
	V509= VV[183];
	goto T1883;
T1886:;
	if((V510!= VV[140]))goto T1887;
	V509= VV[184];
	goto T1883;
T1887:;
	V509= VV[185];}
T1883:;
	(void)((*(LnkLI262))(V509));
	princ_str("(base[",VV[21]);
	V511 = make_fixnum(V508);
	(void)((*(LnkLI262))(V511));
	princ_str("])",VV[21]);
	if(endp(cdr((V507)))){
	goto T1891;}
	princ_char(44,VV[21]);
T1891:;
	V507= cdr((V507));
	V508= (V508)+1;
	goto T1876;}
T1873:;
	princ_str("));",VV[21]);
	princ_str("\n	vs_top=(vs_base=base)+1;",VV[21]);
	princ_str("\n}",VV[21]);
	{object V512 = Cnil;
	VMR31(V512)}
}
/*	local entry for function REP-TYPE	*/

static object LI33(V514)

object V514;
{	 VMB32 VMS32 VMV32
TTL:;
	{object V515= (V514);
	if((V515!= VV[85]))goto T1904;
	{object V516 = VV[186];
	VMR32(V516)}
T1904:;
	if((V515!= VV[249]))goto T1905;
	{object V517 = VV[187];
	VMR32(V517)}
T1905:;
	if((V515!= VV[138]))goto T1906;
	{object V518 = VV[188];
	VMR32(V518)}
T1906:;
	if((V515!= VV[140]))goto T1907;
	{object V519 = VV[189];
	VMR32(V519)}
T1907:;
	if((V515!= VV[139]))goto T1908;
	{object V520 = VV[190];
	VMR32(V520)}
T1908:;
	{object V521 = VV[191];
	VMR32(V521)}}
}
/*	local entry for function T1DEFMACRO	*/

static object LI34(V523)

register object V523;
{	 VMB33 VMS33 VMV33
	bds_check;
TTL:;
	if(endp((V523))){
	goto T1910;}
	if(!(endp(cdr((V523))))){
	goto T1909;}
T1910:;
	V524 = make_fixnum(length((V523)));
	(void)((*(LnkLI270))(VV[192],small_fixnum(2),V524));
T1909:;
	if(type_of(car((V523)))==t_symbol){
	goto T1914;}
	(void)((VFUN_NARGS=2,(*(LnkLI253))(VV[193],car((V523)))));
T1914:;
	V525= make_cons(VV[192],(V523));
	(void)((*(LnkLI255))(Ct,/* INLINE-ARGS */V525));
	setq(VV[6],Ct);
	{register object V526;
	object V527;
	setq(VV[57],number_plus(symbol_value(VV[57]),small_fixnum(1)));
	V527= symbol_value(VV[57]);
	bds_bind(VV[51],Cnil);
	bds_bind(VV[52],Cnil);
	bds_bind(VV[53],Cnil);
	bds_bind(VV[54],Cnil);
	bds_bind(VV[48],Cnil);
	bds_bind(VV[55],Cnil);
	V526= Cnil;
	V526= (*(LnkLI324))(car((V523)),cadr((V523)),cddr((V523)));
	(void)((*(LnkLI280))());
	V528= list(7,VV[192],car((V523)),(V527),cddr((V526)),car((V526)),cadr((V526)),(VV[55]->s.s_dbind));
	setq(VV[20],make_cons(/* INLINE-ARGS */V528,symbol_value(VV[20])));
	{object V529 = symbol_value(VV[20]);
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	VMR33(V529)}}
}
/*	local entry for function T2DEFMACRO	*/

static object LI35(V536,V537,V538,V539,V540,V541)

object V536;object V537;object V538;object V539;object V540;object V541;
{	 VMB34 VMS34 VMV34
TTL:;
	if(((V539))==Cnil){
	goto T1926;}
	V542= list(4,VV[99],list(2,VV[87],(V536)),(V539),VV[194]);
	(void)((VFUN_NARGS=1,(*(LnkLI287))(/* INLINE-ARGS */V542)));
T1926:;
	if(((V540))==Cnil){
	goto T1929;}
	V543= list(2,VV[87],(V536));
	V544= list(4,VV[99],/* INLINE-ARGS */V543,list(2,VV[87],(V540)),VV[195]);
	(void)((VFUN_NARGS=1,(*(LnkLI287))(/* INLINE-ARGS */V544)));
T1929:;
	princ_str("\nstatic L",VV[27]);
	(void)((*(LnkLI265))((V537)));
	princ_str("();",VV[27]);
	V545= list(2,VV[87],(V536));
	V546= list(3,VV[196],/* INLINE-ARGS */V545,(*(LnkLI288))(VV[197],(V537)));
	{object V547 = (VFUN_NARGS=1,(*(LnkLI287))(/* INLINE-ARGS */V546));
	VMR34(V547)}
}
/*	local entry for function T3DEFMACRO	*/

static object LI36(V554,V555,V556,V557,V558,V559)

object V554;object V555;register object V556;object V557;object V558;object V559;
{	 VMB35 VMS35 VMV35
	bds_check;
TTL:;
	if((get((V554),VV[198],Cnil))==Cnil){
	goto T1938;}
	bds_bind(VV[16],VV[199]);
	goto T1936;
T1938:;
	bds_bind(VV[16],VV[200]);
T1936:;
	bds_bind(VV[124],VV[123]);
	bds_bind(VV[14],Cnil);
	bds_bind(VV[125],small_fixnum(0));
	bds_bind(VV[126],small_fixnum(0));
	bds_bind(VV[127],small_fixnum(0));
	bds_bind(VV[128],small_fixnum(0));
	bds_bind(VV[129],Cnil);
	bds_bind(VV[130],make_cons((VV[124]->s.s_dbind),Cnil));
	bds_bind(VV[131],(VV[124]->s.s_dbind));
	setq(VV[133],number_plus(symbol_value(VV[133]),small_fixnum(1)));
	bds_bind(VV[132],symbol_value(VV[133]));
	bds_bind(VV[134],Cnil);
	bds_bind(VV[135],Cnil);
	bds_bind(VV[136],Cnil);
	bds_bind(VV[137],small_fixnum(0));
	(void)((VFUN_NARGS=2,(*(LnkLI299))(VV[201],(V554))));
	princ_str("\nstatic L",VV[21]);
	(void)((*(LnkLI262))((V555)));
	princ_str("()",VV[21]);
	princ_str("\n{register object *",VV[21]);
	(void)((*(LnkLI262))((VV[16]->s.s_dbind)));
	princ_str("base=vs_base;",VV[21]);
	V560= structure_ref(car(cddddr((V556))),VV[58],1);
	(void)((*(LnkLI301))(/* INLINE-ARGS */V560,(V555),VV[144]));
	princ_str("\n	register object *",VV[21]);
	(void)((*(LnkLI262))((VV[16]->s.s_dbind)));
	princ_str("sup=base+VM",VV[21]);
	(void)((*(LnkLI262))((VV[132]->s.s_dbind)));
	princ_char(59,VV[21]);
	princ_str(" VC",VV[21]);
	(void)((*(LnkLI262))((VV[132]->s.s_dbind)));
	if((symbol_value(VV[152]))==Cnil){
	goto T1964;}
	princ_str("\n	vs_reserve(VM",VV[21]);
	(void)((*(LnkLI262))((VV[132]->s.s_dbind)));
	princ_str(");",VV[21]);
	goto T1962;
T1964:;
	princ_str("\n	vs_check;",VV[21]);
T1962:;
	if(((V559))==Cnil){
	goto T1970;}
	princ_str("\n	bds_check;",VV[21]);
T1970:;
	if((symbol_value(VV[145]))==Cnil){
	goto T1974;}
	princ_str("\n	ihs_check;",VV[21]);
T1974:;
	base[15]= car((V556));
	base[16]= cadr((V556));
	base[17]= caddr((V556));
	base[18]= cadddr((V556));
	vs_top=(vs_base=base+15)+4;
	(void) (*Lnk325)();
	vs_top=sup;
	princ_str("\n}",VV[21]);
	V561= make_cons((VV[132]->s.s_dbind),(VV[126]->s.s_dbind));
	setq(VV[29],make_cons(/* INLINE-ARGS */V561,symbol_value(VV[29])));
	princ_str("\n#define VC",VV[27]);
	(void)((*(LnkLI265))((VV[132]->s.s_dbind)));
	{object V562 = (*(LnkLI319))();
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
	VMR35(V562)}
}
/*	local entry for function T1ORDINARY	*/

static object LI37(V564)

register object V564;
{	 VMB36 VMS36 VMV36
	bds_check;
TTL:;
	{register object V565;
	V565= Cnil;
	setq(VV[6],Ct);
	if((symbol_value(VV[44]))==Cnil){
	goto T1994;}
	(void)((*(LnkLI255))(Cnil,(V564)));
	{object V566;
	base[0]= VV[202];
	vs_top=(vs_base=base+0)+1;
	Lgensym();
	vs_top=sup;
	V566= vs_base[0];
	V567= listA(3,VV[60],(V566),VV[203]);
	(void)((*(LnkLI276))(/* INLINE-ARGS */V567));
	base[0]= list(5,VV[47],(V566),Cnil,(V564),Cnil);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk259)();
	vs_top=sup;
	V568= list(2,VV[204],make_cons((V566),Cnil));
	setq(VV[20],make_cons(/* INLINE-ARGS */V568,symbol_value(VV[20])));
	{object V569 = symbol_value(VV[20]);
	VMR36(V569)}}
T1994:;
	{object V570;
	if(type_of((V564))==t_cons){
	goto T2004;}
	V570= Cnil;
	goto T2003;
T2004:;
	if(type_of(car((V564)))==t_symbol){
	goto T2006;}
	V570= Cnil;
	goto T2003;
T2006:;
	if(!((car((V564)))==(VV[205]))){
	goto T2010;}
	goto T2008;
T2010:;
	base[0]= car((V564));
	vs_top=(vs_base=base+0)+1;
	Lspecial_form_p();
	vs_top=sup;
	V571= vs_base[0];
	if((V571)==Cnil){
	goto T2008;}
	V570= Cnil;
	goto T2003;
T2008:;
	{register object V572;
	register int V573;
	V572= cdr((V564));
	V573= 1;
T2017:;
	if((V573)>=(1000)){
	goto T2019;}
	if(type_of((V572))==t_cons){
	goto T2018;}
T2019:;
	V570= Cnil;
	goto T2003;
T2018:;
	if(!(type_of(car((V572)))==t_cons)){
	goto T2024;}
	if(!((caar((V572)))==(VV[60]))){
	goto T2024;}
	V565= cadr(car((V572)));
	if(!(type_of((V565))==t_cons)){
	goto T2024;}
	if(!((car((V565)))==(VV[206]))){
	goto T2024;}
	{register object V574;
	vs_base=vs_top;
	Lgensym();
	vs_top=sup;
	V574= vs_base[0];
	base[0]= listA(3,VV[47],(V574),cdr((V565)));
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk259)();
	vs_top=sup;
	base[1]= (V564);
	base[2]= small_fixnum(0);
	base[3]= make_fixnum(V573);
	vs_top=(vs_base=base+1)+3;
	Lsubseq();
	vs_top=sup;
	base[0]= vs_base[0];
	V575= list(2,VV[207],list(2,VV[87],(V574)));
	base[1]= make_cons(/* INLINE-ARGS */V575,Cnil);
	{ save_avma;
	V576 = stoi(V573);
	V577= make_integer(addii(stoi(1),V576));
	base[2]= nthcdr(fixint(/* INLINE-ARGS */V577),(V564));restore_avma;}
	vs_top=(vs_base=base+0)+3;
	Lappend();
	vs_top=sup;
	V564= vs_base[0];
	goto TTL;}
T2024:;
	if(type_of((V572))==t_cons){
	goto T2047;}
	V572= Cnil;
	goto T2046;
T2047:;
	V572= cdr((V572));
T2046:;
	V573= (1)+(V573);
	goto T2017;}
T2003:;
	if(((V570))==Cnil){
	goto T2052;}
	{object V578 = (V570);
	VMR36(V578)}
T2052:;
	(void)((*(LnkLI255))(Cnil,(V564)));
	bds_bind(VV[51],Cnil);
	bds_bind(VV[52],Cnil);
	bds_bind(VV[53],Cnil);
	bds_bind(VV[54],Cnil);
	bds_bind(VV[48],Cnil);
	V579= list(2,VV[204],(V564));
	setq(VV[20],make_cons(/* INLINE-ARGS */V579,symbol_value(VV[20])));
	{object V580 = Cnil;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	VMR36(V580)}}}
}
/*	local entry for function T2ORDINARY	*/

static object LI38(V582)

object V582;
{	 VMB37 VMS37 VMV37
TTL:;
	{object V583;
	V583= (type_of((V582))!=t_cons?Ct:Cnil);
	if(((V583))==Cnil){
	goto T2059;}
	{object V584 = (V583);
	VMR37(V584)}
T2059:;
	{object V585;
	base[0]= (V582);
	vs_top=(vs_base=base+0)+1;
	Lconstantp();
	vs_top=sup;
	V585= vs_base[0];
	if(((V585))==Cnil){
	goto T2064;}
	{object V586 = (V585);
	VMR37(V586)}
T2064:;
	{object V587 = (VFUN_NARGS=1,(*(LnkLI287))((V582)));
	VMR37(V587)}}}
}
/*	local entry for function ADD-LOAD-TIME-SHARP-COMMA	*/

static object LI39()

{	 VMB38 VMS38 VMV38
TTL:;
	{register object V588;
	register object V589;
	V588= reverse(symbol_value(VV[48]));
	V589= car((V588));
T2069:;
	if(!(endp((V588)))){
	goto T2070;}
	{object V590 = Cnil;
	VMR38(V590)}
T2070:;
	if(!(type_of((V589))!=t_cons)){
	goto T2074;}
	(void)((*(LnkLI326))());
T2074:;
	V591= make_cons(VV[208],(V589));
	setq(VV[20],make_cons(/* INLINE-ARGS */V591,symbol_value(VV[20])));
	V588= cdr((V588));
	V589= car((V588));
	goto T2069;}
}
/*	local entry for function T2SHARP-COMMA	*/

static object LI40(V594,V595)

object V594;object V595;
{	 VMB39 VMS39 VMV39
TTL:;
	V596= list(3,VV[209],(V594),(V595));
	{object V597 = (VFUN_NARGS=1,(*(LnkLI287))(/* INLINE-ARGS */V596));
	VMR39(V597)}
}
/*	local entry for function T2DECLARE	*/

static object LI41(V599)

object V599;
{	 VMB40 VMS40 VMV40
TTL:;
	{object V600 = (*(LnkLI326))();
	VMR40(V600)}
}
/*	local entry for function T1DEFINE-STRUCTURE	*/

static object LI42(V602)

object V602;
{	 VMB41 VMS41 VMV41
TTL:;
	V603= (*(LnkLI255))(Cnil,Cnil);
	V604= make_cons(((/* INLINE-ARGS */V603)==Cnil?Ct:Cnil),Cnil);
	V605= append((V602),/* INLINE-ARGS */V604);
	V606= make_cons(VV[210],/* INLINE-ARGS */V605);
	(void)((*(LnkLI255))(Ct,/* INLINE-ARGS */V606));
	V607= make_cons(VV[210],(V602));
	{object V608 = (*(LnkLI260))(/* INLINE-ARGS */V607);
	VMR41(V608)}
}
/*	local entry for function SET-DBIND	*/

static object LI43(V611,V612)

object V611;object V612;
{	 VMB42 VMS42 VMV42
TTL:;
	princ_str("\n	VV[",VV[21]);
	(void)((*(LnkLI262))((V612)));
	princ_str("]->s.s_dbind = ",VV[21]);
	(void)((*(LnkLI262))((V611)));
	princ_char(59,VV[21]);
	{object V613 = Cnil;
	VMR42(V613)}
}
/*	local entry for function T1CLINES	*/

static object LI44(V615)

object V615;
{	 VMB43 VMS43 VMV43
TTL:;
	{register object V616;
	register object V617;
	V616= (V615);
	V617= car((V616));
T2095:;
	if(!(endp((V616)))){
	goto T2096;}
	goto T2091;
T2096:;
	if(type_of((V617))==t_string){
	goto T2100;}
	(void)((VFUN_NARGS=2,(*(LnkLI253))(VV[211],(V617))));
T2100:;
	V616= cdr((V616));
	V617= car((V616));
	goto T2095;}
T2091:;
	V618= list(2,VV[212],(V615));
	setq(VV[20],make_cons(/* INLINE-ARGS */V618,symbol_value(VV[20])));
	{object V619 = symbol_value(VV[20]);
	VMR43(V619)}
}
/*	local entry for function T3CLINES	*/

static object LI45(V621)

object V621;
{	 VMB44 VMS44 VMV44
TTL:;
	{register object V622;
	register object V623;
	V622= (V621);
	V623= car((V622));
T2112:;
	if(!(endp((V622)))){
	goto T2113;}
	{object V624 = Cnil;
	VMR44(V624)}
T2113:;
	princ_char(10,VV[21]);
	(void)((*(LnkLI262))((V623)));
	V622= cdr((V622));
	V623= car((V622));
	goto T2112;}
}
/*	local entry for function T1DEFCFUN	*/

static object LI46(V626)

register object V626;
{	 VMB45 VMS45 VMV45
TTL:;
	{register object V627;
	V627= Cnil;
	if(endp((V626))){
	goto T2127;}
	if(!(endp(cdr((V626))))){
	goto T2126;}
T2127:;
	V628 = make_fixnum(length((V626)));
	(void)((*(LnkLI270))(VV[213],small_fixnum(2),V628));
T2126:;
	if(type_of(car((V626)))==t_string){
	goto T2131;}
	(void)((VFUN_NARGS=2,(*(LnkLI253))(VV[214],car((V626)))));
T2131:;
	{object V629= cadr((V626));
	if(type_of(V629)==t_fixnum||
type_of(V629)==t_bignum||
type_of(V629)==t_ratio||
type_of(V629)==t_shortfloat||
type_of(V629)==t_longfloat||
type_of(V629)==t_complex){
	goto T2134;}}
	(void)((VFUN_NARGS=2,(*(LnkLI253))(VV[215],cadr((V626)))));
T2134:;
	{register object V630;
	register object V631;
	V630= cddr((V626));
	V631= car((V630));
T2141:;
	if(!(endp((V630)))){
	goto T2142;}
	goto T2137;
T2142:;
	if(!(type_of((V631))==t_string)){
	goto T2148;}
	V627= make_cons((V631),(V627));
	goto T2146;
T2148:;
	if(!(type_of((V631))==t_cons)){
	goto T2152;}
	if(!(type_of(car((V631)))==t_symbol)){
	goto T2155;}
	base[2]= car((V631));
	vs_top=(vs_base=base+2)+1;
	Lspecial_form_p();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T2157;}
	(void)((VFUN_NARGS=2,(*(LnkLI253))(VV[216],car((V631)))));
T2157:;
	V632= car((V631));
	V633= (*(LnkLI327))(cdr((V631)));
	V634= make_cons(/* INLINE-ARGS */V632,/* INLINE-ARGS */V633);
	V635= make_cons(/* INLINE-ARGS */V634,Cnil);
	V627= make_cons(/* INLINE-ARGS */V635,(V627));
	goto T2146;
T2155:;
	if(!(type_of(car((V631)))==t_cons)){
	goto T2163;}
	if(!(type_of(caar((V631)))==t_symbol)){
	goto T2163;}
	if(!((caar((V631)))==(VV[87]))){
	goto T2170;}
	if(!(endp(cdar((V631))))){
	goto T2172;}
	goto T2163;
T2172:;
	if(!(((endp(cddar((V631)))?Ct:Cnil))==Cnil)){
	goto T2174;}
	goto T2163;
T2174:;
	if(!(endp(cdr((V631))))){
	goto T2176;}
	goto T2163;
T2176:;
	if(((endp(cddr((V631)))?Ct:Cnil))==Cnil){
	goto T2163;}
	goto T2168;
T2170:;
	base[2]= caar((V631));
	vs_top=(vs_base=base+2)+1;
	Lspecial_form_p();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T2163;}
T2168:;
	V636= caar((V631));
	if(!((caar((V631)))==(VV[87]))){
	goto T2182;}
	V638= (*(LnkLI312))(cadar((V631)));
	V637= make_cons(/* INLINE-ARGS */V638,Cnil);
	goto T2180;
T2182:;
	V637= (*(LnkLI327))(cdar((V631)));
T2180:;
	V639= make_cons(/* INLINE-ARGS */V636,V637);
	V640= (*(LnkLI327))(cdr((V631)));
	V641= make_cons(/* INLINE-ARGS */V639,/* INLINE-ARGS */V640);
	V627= make_cons(/* INLINE-ARGS */V641,(V627));
	goto T2146;
T2163:;
	(void)((VFUN_NARGS=2,(*(LnkLI253))(VV[217],(V631))));
	goto T2146;
T2152:;
	(void)((VFUN_NARGS=2,(*(LnkLI253))(VV[218],(V631))));
T2146:;
	V630= cdr((V630));
	V631= car((V630));
	goto T2141;}
T2137:;
	V642= car((V626));
	V643= cadr((V626));
	V644= list(4,VV[213],/* INLINE-ARGS */V642,/* INLINE-ARGS */V643,reverse((V627)));
	setq(VV[20],make_cons(/* INLINE-ARGS */V644,symbol_value(VV[20])));
	{object V645 = symbol_value(VV[20]);
	VMR45(V645)}}
}
/*	local entry for function T3DEFCFUN	*/

static object LI47(V649,V650,V651)

object V649;object V650;object V651;
{	 VMB46 VMS46 VMV46
TTL:;
	{object V652;
	V652= Cnil;
	(void)((VFUN_NARGS=2,(*(LnkLI299))(VV[219],VV[213])));
	princ_char(10,VV[21]);
	(void)((*(LnkLI262))((V649)));
	princ_str("\n{",VV[21]);
	princ_str("\nobject *vs=vs_top;",VV[21]);
	princ_str("\nobject *old_top=vs_top+",VV[21]);
	(void)((*(LnkLI262))((V650)));
	princ_char(59,VV[21]);
	if(!(number_compare((V650),small_fixnum(0))>0)){
	goto T2203;}
	princ_str("\n	vs_top=old_top;",VV[21]);
T2203:;
	princ_str("\n{",VV[21]);
	{object V653;
	register object V654;
	V653= (V651);
	V654= car((V653));
T2213:;
	if(!(endp((V653)))){
	goto T2214;}
	goto T2209;
T2214:;
	if(!(type_of((V654))==t_string)){
	goto T2220;}
	princ_char(10,VV[21]);
	(void)((*(LnkLI262))((V654)));
	goto T2218;
T2220:;
	if(!((caar((V654)))==(VV[87]))){
	goto T2225;}
	princ_char(10,VV[21]);
	(void)((*(LnkLI262))(cadadr((V654))));
	{object V655= caadr((V654));
	if((V655!= VV[70]))goto T2230;
	princ_str("=VV[",VV[21]);
	(void)((*(LnkLI262))(cadar((V654))));
	princ_str("];",VV[21]);
	goto T2218;
T2230:;
	princ_str("=object_to_",VV[21]);
	base[1]= symbol_name(caadr((V654)));
	vs_top=(vs_base=base+1)+1;
	Lstring_downcase();
	vs_top=sup;
	V656= vs_base[0];
	(void)((*(LnkLI262))(V656));
	princ_str("(VV[",VV[21]);
	(void)((*(LnkLI262))(cadar((V654))));
	princ_str("]);",VV[21]);
	goto T2218;}
T2225:;
	princ_str("\n{vs_base=vs_top=old_top;",VV[21]);
	{register object V657;
	register object V658;
	V657= cdar((V654));
	V658= car((V657));
T2247:;
	if(!(endp((V657)))){
	goto T2248;}
	goto T2243;
T2248:;
	princ_str("\nvs_push(",VV[21]);
	{object V659= car((V658));
	if((V659!= VV[70]))goto T2255;
	(void)((*(LnkLI262))(cadr((V658))));
	goto T2254;
T2255:;
	if((V659!= VV[328]))goto T2257;
	princ_str("code_char((int)",VV[21]);
	(void)((*(LnkLI262))(cadr((V658))));
	princ_char(41,VV[21]);
	goto T2254;
T2257:;
	if((V659!= VV[329]))goto T2261;
	if(!(number_compare(small_fixnum(0),symbol_value(VV[110]))==0)){
	goto T2262;}
	princ_str("CMP",VV[21]);
T2262:;
	princ_str("make_fixnum((int)",VV[21]);
	(void)((*(LnkLI262))(cadr((V658))));
	princ_char(41,VV[21]);
	goto T2254;
T2261:;
	if((V659!= VV[330]))goto T2269;
	princ_str("make_shortfloat((double)",VV[21]);
	(void)((*(LnkLI262))(cadr((V658))));
	princ_char(41,VV[21]);
	goto T2254;
T2269:;
	if((V659!= VV[331]))goto T2273;
	princ_str("make_longfloat((double)",VV[21]);
	(void)((*(LnkLI262))(cadr((V658))));
	princ_char(41,VV[21]);
	goto T2254;
T2273:;}
T2254:;
	princ_str(");",VV[21]);
	V657= cdr((V657));
	V658= car((V657));
	goto T2247;}
T2243:;
	{register object x= caar((V654)),V660= symbol_value(VV[75]);
	while(!endp(V660))
	if(type_of(V660->c.c_car)==t_cons &&eql(x,V660->c.c_car->c.c_car)){
	V652= (V660->c.c_car);
	goto T2288;
	}else V660=V660->c.c_cdr;
	V652= Cnil;}
T2288:;
	if(((V652))==Cnil){
	goto T2286;}
	if((symbol_value(VV[145]))==Cnil){
	goto T2290;}
	princ_str("\nihs_push(VV[",VV[21]);
	V661= (*(LnkLI314))(caar((V654)));
	(void)((*(LnkLI262))(/* INLINE-ARGS */V661));
	princ_str("]);",VV[21]);
	princ_str("\nL",VV[21]);
	(void)((*(LnkLI262))(cdr((V652))));
	princ_str("();",VV[21]);
	princ_str("\nihs_pop();",VV[21]);
	goto T2284;
T2290:;
	princ_str("\nL",VV[21]);
	(void)((*(LnkLI262))(cdr((V652))));
	princ_str("();",VV[21]);
	goto T2284;
T2286:;
	if((symbol_value(VV[145]))==Cnil){
	goto T2305;}
	princ_str("\nsuper_funcall(VV[",VV[21]);
	V662= (*(LnkLI314))(caar((V654)));
	(void)((*(LnkLI262))(/* INLINE-ARGS */V662));
	princ_str("]);",VV[21]);
	goto T2284;
T2305:;
	if((symbol_value(VV[152]))==Cnil){
	goto T2311;}
	princ_str("\nsuper_funcall_no_event(VV[",VV[21]);
	V663= (*(LnkLI314))(caar((V654)));
	(void)((*(LnkLI262))(/* INLINE-ARGS */V663));
	princ_str("]);",VV[21]);
	goto T2284;
T2311:;
	princ_str("\nCMPfuncall(VV[",VV[21]);
	V664= (*(LnkLI314))(caar((V654)));
	(void)((*(LnkLI262))(/* INLINE-ARGS */V664));
	princ_str("]->s.s_gfdef);",VV[21]);
T2284:;
	if(endp(cdr((V654)))){
	goto T2319;}
	princ_char(10,VV[21]);
	(void)((*(LnkLI262))(cadadr((V654))));
	{object V665= caadr((V654));
	if((V665!= VV[70]))goto T2326;
	princ_str("=vs_base[0];",VV[21]);
	goto T2325;
T2326:;
	princ_str("=object_to_",VV[21]);
	base[1]= symbol_name(caadr((V654)));
	vs_top=(vs_base=base+1)+1;
	Lstring_downcase();
	vs_top=sup;
	V666= vs_base[0];
	(void)((*(LnkLI262))(V666));
	princ_str("(vs_base[0]);",VV[21]);}
T2325:;
	{register object V667;
	register object V668;
	V667= cddr((V654));
	V668= car((V667));
T2336:;
	if(!(endp((V667)))){
	goto T2337;}
	goto T2319;
T2337:;
	princ_str("\nvs_base++;",VV[21]);
	princ_char(10,VV[21]);
	(void)((*(LnkLI262))(cadr((V668))));
	{object V669= car((V668));
	if((V669!= VV[70]))goto T2347;
	princ_str("=(vs_base<vs_top?vs_base[0]:Cnil);",VV[21]);
	goto T2346;
T2347:;
	princ_str("=object_to_",VV[21]);
	base[3]= symbol_name(car((V668)));
	vs_top=(vs_base=base+3)+1;
	Lstring_downcase();
	vs_top=sup;
	V670= vs_base[0];
	(void)((*(LnkLI262))(V670));
	princ_str("((vs_base<vs_top?vs_base[0]:Cnil));",VV[21]);}
T2346:;
	V667= cdr((V667));
	V668= car((V667));
	goto T2336;}
T2319:;
	princ_str("\n}",VV[21]);
T2218:;
	V653= cdr((V653));
	V654= car((V653));
	goto T2213;}
T2209:;
	princ_str("\n}",VV[21]);
	princ_str("\nvs_top=vs;",VV[21]);
	princ_str("\n}",VV[21]);
	{object V671 = Cnil;
	VMR46(V671)}}
}
/*	local entry for function T1DEFENTRY	*/

static object LI48(V673)

register object V673;
{	 VMB47 VMS47 VMV47
TTL:;
	{register object V674;
	register object V675;
	object V676;
	register object V677;
	V674= Cnil;
	V675= Cnil;
	setq(VV[57],number_plus(symbol_value(VV[57]),small_fixnum(1)));
	V676= symbol_value(VV[57]);
	V677= Cnil;
	if(endp((V673))){
	goto T2376;}
	if(endp(cdr((V673)))){
	goto T2376;}
	if(!(endp(cddr((V673))))){
	goto T2375;}
T2376:;
	V678 = make_fixnum(length((V673)));
	(void)((*(LnkLI270))(VV[220],small_fixnum(3),V678));
T2375:;
	if(type_of(car((V673)))==t_symbol){
	goto T2382;}
	(void)((VFUN_NARGS=2,(*(LnkLI253))(VV[221],car((V673)))));
T2382:;
	{register object V679;
	register object V680;
	V679= cadr((V673));
	V680= car((V679));
T2389:;
	if(!(endp((V679)))){
	goto T2390;}
	goto T2385;
T2390:;
	{register object x= (V680),V681= VV[222];
	while(!endp(V681))
	if(eql(x,V681->c.c_car)){
	goto T2394;
	}else V681=V681->c.c_cdr;}
	(void)((VFUN_NARGS=2,(*(LnkLI253))(VV[223],(V680))));
T2394:;
	V679= cdr((V679));
	V680= car((V679));
	goto T2389;}
T2385:;
	V677= caddr((V673));
	if(!(type_of((V677))==t_symbol)){
	goto T2406;}
	V674= VV[70];
	base[1]= symbol_name((V677));
	vs_top=(vs_base=base+1)+1;
	Lstring_downcase();
	vs_top=sup;
	V675= vs_base[0];
	goto T2404;
T2406:;
	if(!(type_of((V677))==t_string)){
	goto T2413;}
	V674= VV[70];
	V675= (V677);
	goto T2404;
T2413:;
	if(!(type_of((V677))==t_cons)){
	goto T2419;}
	{register object x= car((V677)),V682= VV[224];
	while(!endp(V682))
	if(eql(x,V682->c.c_car)){
	goto T2423;
	}else V682=V682->c.c_cdr;
	goto T2419;}
T2423:;
	if(!(type_of(cdr((V677)))==t_cons)){
	goto T2419;}
	if(type_of(cadr((V677)))==t_symbol){
	goto T2426;}
	if(!(type_of(cadr((V677)))==t_string)){
	goto T2419;}
T2426:;
	if(!(endp(cddr((V677))))){
	goto T2419;}
	if(!(type_of(cadr((V677)))==t_symbol)){
	goto T2434;}
	base[1]= symbol_name(cadr((V677)));
	vs_top=(vs_base=base+1)+1;
	Lstring_downcase();
	vs_top=sup;
	V675= vs_base[0];
	goto T2432;
T2434:;
	V675= cadr((V677));
T2432:;
	V674= car((V677));
	goto T2404;
T2419:;
	(void)((VFUN_NARGS=2,(*(LnkLI253))(VV[225],(V677))));
T2404:;
	V683= list(6,VV[220],car((V673)),(V676),cadr((V673)),(V674),(V675));
	setq(VV[20],make_cons(/* INLINE-ARGS */V683,symbol_value(VV[20])));
	V684= make_cons(car((V673)),(V676));
	setq(VV[75],make_cons(/* INLINE-ARGS */V684,symbol_value(VV[75])));
	{object V685 = symbol_value(VV[75]);
	VMR47(V685)}}
}
/*	local entry for function T2DEFENTRY	*/

static object LI49(V691,V692,V693,V694,V695)

object V691;object V692;object V693;object V694;object V695;
{	 VMB48 VMS48 VMV48
TTL:;
	princ_str("\nstatic L",VV[27]);
	(void)((*(LnkLI265))((V692)));
	princ_str("();",VV[27]);
	V696= list(2,VV[87],(V691));
	V697= list(3,VV[107],/* INLINE-ARGS */V696,(*(LnkLI288))(VV[226],(V692)));
	{object V698 = (VFUN_NARGS=1,(*(LnkLI287))(/* INLINE-ARGS */V697));
	VMR48(V698)}
}
/*	local entry for function T3DEFENTRY	*/

static object LI50(V704,V705,V706,V707,V708)

object V704;object V705;object V706;register object V707;object V708;
{	 VMB49 VMS49 VMV49
TTL:;
	(void)((VFUN_NARGS=2,(*(LnkLI299))(VV[227],(V704))));
	princ_str("\nstatic L",VV[21]);
	(void)((*(LnkLI262))((V705)));
	princ_str("()",VV[21]);
	princ_str("\n{	object *old_base=vs_base;",VV[21]);
	{object V709= (V707);
	if((V709!= VV[228]))goto T2453;
	goto T2452;
T2453:;
	if((V709!= VV[332]))goto T2454;
	princ_str("\n	char *x;",VV[21]);
	goto T2452;
T2454:;
	princ_str("\n	",VV[21]);
	base[0]= symbol_name((V707));
	vs_top=(vs_base=base+0)+1;
	Lstring_downcase();
	vs_top=sup;
	V710= vs_base[0];
	(void)((*(LnkLI262))(V710));
	princ_str(" x;",VV[21]);}
T2452:;
	if((symbol_value(VV[152]))==Cnil){
	goto T2461;}
	princ_str("\n	check_arg(",VV[21]);
	V711 = make_fixnum(length((V706)));
	(void)((*(LnkLI262))(V711));
	princ_str(");",VV[21]);
T2461:;
	if(((V707))==(VV[228])){
	goto T2467;}
	princ_str("\n	x=",VV[21]);
T2467:;
	princ_str("\n	",VV[21]);
	(void)((*(LnkLI262))((V708)));
	princ_char(40,VV[21]);
	if(endp((V706))){
	goto T2475;}
	{register object V712;
	register int V713;
	V713= 0;
	V712= (V706);
T2480:;
	{object V714= car((V712));
	if((V714!= VV[70]))goto T2484;
	princ_str("\n	vs_base[",VV[21]);
	V715 = make_fixnum(V713);
	(void)((*(LnkLI262))(V715));
	princ_char(93,VV[21]);
	goto T2483;
T2484:;
	princ_str("\n	object_to_",VV[21]);
	base[0]= symbol_name(car((V712)));
	vs_top=(vs_base=base+0)+1;
	Lstring_downcase();
	vs_top=sup;
	V716= vs_base[0];
	(void)((*(LnkLI262))(V716));
	princ_str("(vs_base[",VV[21]);
	V717 = make_fixnum(V713);
	(void)((*(LnkLI262))(V717));
	princ_str("])",VV[21]);}
T2483:;
	if(!(endp(cdr((V712))))){
	goto T2495;}
	goto T2475;
T2495:;
	princ_char(44,VV[21]);
	V712= cdr((V712));
	V713= (V713)+1;
	goto T2480;}
T2475:;
	princ_str(");",VV[21]);
	princ_str("\n	vs_top=(vs_base=old_base)+1;",VV[21]);
	princ_str("\n	vs_base[0]=",VV[21]);
	{object V718= (V707);
	if((V718!= VV[228]))goto T2511;
	princ_str("Cnil",VV[21]);
	goto T2510;
T2511:;
	if((V718!= VV[70]))goto T2513;
	princ_char(120,VV[21]);
	goto T2510;
T2513:;
	if((V718!= VV[328]))goto T2515;
	princ_str("code_char(x)",VV[21]);
	goto T2510;
T2515:;
	if((V718!= VV[329]))goto T2517;
	if(!(number_compare(small_fixnum(0),symbol_value(VV[110]))==0)){
	goto T2518;}
	princ_str("CMP",VV[21]);
T2518:;
	princ_str("make_fixnum(x)",VV[21]);
	goto T2510;
T2517:;
	if((V718!= VV[332]))goto T2523;
	princ_str("make_simple_string(x)",VV[21]);
	goto T2510;
T2523:;
	if((V718!= VV[330]))goto T2525;
	princ_str("make_shortfloat(x)",VV[21]);
	goto T2510;
T2525:;
	if((V718!= VV[331]))goto T2527;
	princ_str("make_longfloat(x)",VV[21]);
	goto T2510;
T2527:;}
T2510:;
	princ_char(59,VV[21]);
	princ_str("\n}",VV[21]);
	{object V719 = Cnil;
	VMR49(V719)}
}
/*	local entry for function T1DEFLA	*/

static object LI51(V721)

object V721;
{	 VMB50 VMS50 VMV50
TTL:;
	{object V722 = Cnil;
	VMR50(V722)}
}
/*	local entry for function PARSE-CVSPECS	*/

static object LI52(V724)

object V724;
{	 VMB51 VMS51 VMV51
TTL:;
	{register object V725;
	V725= Cnil;
	{register object V726;
	register object V727;
	V726= (V724);
	V727= car((V726));
T2536:;
	if(!(endp((V726)))){
	goto T2537;}
	{object V728 = reverse((V725));
	VMR51(V728)}
T2537:;
	if(!(type_of((V727))==t_symbol)){
	goto T2543;}
	base[1]= symbol_name((V727));
	vs_top=(vs_base=base+1)+1;
	Lstring_downcase();
	vs_top=sup;
	V729= vs_base[0];
	V730= list(2,VV[70],V729);
	V725= make_cons(/* INLINE-ARGS */V730,(V725));
	goto T2541;
T2543:;
	if(!(type_of((V727))==t_string)){
	goto T2549;}
	V731= list(2,VV[70],(V727));
	V725= make_cons(/* INLINE-ARGS */V731,(V725));
	goto T2541;
T2549:;
	if(!(type_of((V727))==t_cons)){
	goto T2553;}
	{register object x= car((V727)),V732= VV[229];
	while(!endp(V732))
	if(eql(x,V732->c.c_car)){
	goto T2556;
	}else V732=V732->c.c_cdr;
	goto T2553;}
T2556:;
	{register object V733;
	register object V734;
	V733= cdr((V727));
	V734= car((V733));
T2560:;
	if(!(endp((V733)))){
	goto T2561;}
	goto T2541;
T2561:;
	V735= car((V727));
	if(!(type_of((V734))==t_symbol)){
	goto T2569;}
	base[3]= symbol_name((V734));
	vs_top=(vs_base=base+3)+1;
	Lstring_downcase();
	vs_top=sup;
	V736= vs_base[0];
	goto T2567;
T2569:;
	if(!(type_of((V734))==t_string)){
	goto T2573;}
	V736= (V734);
	goto T2567;
T2573:;
	V736= (VFUN_NARGS=2,(*(LnkLI253))(VV[230],(V734)));
T2567:;
	V737= list(2,/* INLINE-ARGS */V735,V736);
	V725= make_cons(/* INLINE-ARGS */V737,(V725));
	V733= cdr((V733));
	V734= car((V733));
	goto T2560;}
T2553:;
	(void)((VFUN_NARGS=2,(*(LnkLI253))(VV[231],(V727))));
T2541:;
	V726= cdr((V726));
	V727= car((V726));
	goto T2536;}}
}
/*	local entry for function T3LOCAL-DCFUN	*/

static object LI53(V743,V744,V745,V746,V747)

object V743;object V744;object V745;register object V746;register object V747;
{	 VMB52 VMS52 VMV52
	bds_check;
TTL:;
	{object V748;
	register object V749;
	object V750;
	if(((V743))==Cnil){
	goto T2587;}
	V748= small_fixnum(0);
	goto T2585;
T2587:;
	V748= structure_ref((V746),VV[28],4);
T2585:;
	V749= Cnil;
	bds_bind(VV[16],(*(LnkLI293))(cadr((V747))));
	bds_bind(VV[113],Cnil);
	V750= caaddr((V747));
	if((structure_ref((V746),VV[28],0))==Cnil){
	goto T2595;}
	V751= structure_ref((V746),VV[28],0);
	goto T2593;
T2595:;
	V751= Cnil;
T2593:;
	(void)((VFUN_NARGS=2,(*(LnkLI299))(VV[232],V751)));
	princ_str("\nstatic ",VV[21]);
	if(((V743))==Cnil){
	goto T2602;}
	V752= VV[233];
	goto T2600;
T2602:;
	V752= VV[234];
T2600:;
	(void)((*(LnkLI262))(V752));
	V753= structure_ref((V746),VV[28],3);
	(void)((*(LnkLI262))(/* INLINE-ARGS */V753));
	princ_char(40,VV[21]);
	princ_str("base0",VV[21]);
	if(((V750))==Cnil){
	goto T2611;}
	V754= VV[235];
	goto T2609;
T2611:;
	V754= VV[236];
T2609:;
	(void)((*(LnkLI262))(V754));
	V755= structure_ref(cadr((V747)),VV[58],1);
	(void)((*(LnkLI295))(/* INLINE-ARGS */V755,small_fixnum(2)));
	(void)((*(LnkLI300))(caaddr((V747)),Cnil));
	princ_str("register object *",VV[21]);
	(void)((*(LnkLI262))((VV[16]->s.s_dbind)));
	princ_str("base0;",VV[21]);
	bds_bind(VV[237],(V745));
	bds_bind(VV[124],VV[120]);
	bds_bind(VV[14],Cnil);
	bds_bind(VV[125],small_fixnum(0));
	bds_bind(VV[126],small_fixnum(0));
	bds_bind(VV[127],one_plus((V748)));
	bds_bind(VV[128],(V745));
	bds_bind(VV[129],(V744));
	bds_bind(VV[130],make_cons((VV[124]->s.s_dbind),Cnil));
	bds_bind(VV[131],(VV[124]->s.s_dbind));
	setq(VV[133],number_plus(symbol_value(VV[133]),small_fixnum(1)));
	bds_bind(VV[132],symbol_value(VV[133]));
	bds_bind(VV[134],Cnil);
	bds_bind(VV[135],Cnil);
	bds_bind(VV[136],Cnil);
	bds_bind(VV[137],small_fixnum(0));
	V749= (VV[132]->s.s_dbind);
	princ_str("\n{",VV[21]);
	V756= structure_ref(cadr((V747)),VV[58],1);
	V757= structure_ref((V746),VV[28],3);
	(void)((*(LnkLI301))(/* INLINE-ARGS */V756,/* INLINE-ARGS */V757,VV[238]));
	princ_str("\n	VMB",VV[21]);
	(void)((*(LnkLI262))((V749)));
	princ_str(" VMS",VV[21]);
	(void)((*(LnkLI262))((V749)));
	princ_str(" VMV",VV[21]);
	(void)((*(LnkLI262))((V749)));
	if((symbol_value(VV[145]))==Cnil){
	goto T2635;}
	princ_str("\n	ihs_check;",VV[21]);
T2635:;
	base[19]= caddr(cddr((V747)));
	vs_top=(vs_base=base+19)+1;
	(void) (*Lnk302)();
	vs_top=sup;
	princ_str("\n}",VV[21]);
	(void)((*(LnkLI303))((V749),Ct));
	V758= structure_ref((V746),VV[28],3);
	{object V759 = (*(LnkLI297))(/* INLINE-ARGS */V758);
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
	VMR52(V759)}}
}
/*	local entry for function T3LOCAL-FUN	*/

static object LI54(V765,V766,V767,V768,V769)

object V765;object V766;object V767;object V768;object V769;
{	 VMB53 VMS53 VMV53
	bds_check;
TTL:;
	{int V770;
	if(((V765))==Cnil){
	goto T2646;}
	V770= 0;
	goto T2644;
T2646:;
	V770= fix(structure_ref((V768),VV[28],4));
T2644:;
	bds_bind(VV[16],(*(LnkLI293))(cadr((V769))));
	bds_bind(VV[113],Cnil);
	if(!(((V765))==(VV[239]))){
	goto T2649;}
	{object V771 = (*(LnkLI238))((V765),(V766),(V767),(V768),(V769));
	bds_unwind1;
	bds_unwind1;
	VMR53(V771)}
T2649:;
	if((structure_ref((V768),VV[28],0))==Cnil){
	goto T2655;}
	V772= structure_ref((V768),VV[28],0);
	goto T2653;
T2655:;
	V772= Cnil;
T2653:;
	(void)((VFUN_NARGS=2,(*(LnkLI299))(VV[240],V772)));
	princ_str("\nstatic ",VV[27]);
	if(((V765))==Cnil){
	goto T2662;}
	V773= VV[241];
	goto T2660;
T2662:;
	V773= VV[242];
T2660:;
	(void)((*(LnkLI265))(V773));
	V774= structure_ref((V768),VV[28],3);
	(void)((*(LnkLI265))(/* INLINE-ARGS */V774));
	princ_str("();",VV[27]);
	princ_str("\nstatic ",VV[21]);
	if(((V765))==Cnil){
	goto T2671;}
	V775= VV[243];
	goto T2669;
T2671:;
	V775= VV[244];
T2669:;
	(void)((*(LnkLI262))(V775));
	V776= structure_ref((V768),VV[28],3);
	(void)((*(LnkLI262))(/* INLINE-ARGS */V776));
	princ_char(40,VV[21]);
	{register object V777;
	register int V778;
	V777= make_fixnum(V770);
	V778= 0;
T2679:;
	V779 = make_fixnum(V778);
	if(!(number_compare(V779,(V777))>=0)){
	goto T2680;}
	princ_str("base",VV[21]);
	V780 = make_fixnum(V778);
	(void)((*(LnkLI262))(V780));
	princ_char(41,VV[21]);
	goto T2675;
T2680:;
	princ_str("base",VV[21]);
	V781 = make_fixnum(V778);
	(void)((*(LnkLI262))(V781));
	princ_char(44,VV[21]);
	V778= (V778)+1;
	goto T2679;}
T2675:;
	princ_str("\nregister object ",VV[21]);
	{register object V782;
	register int V783;
	V782= make_fixnum(V770);
	V783= 0;
T2700:;
	V784 = make_fixnum(V783);
	if(!(number_compare(V784,(V782))>=0)){
	goto T2701;}
	princ_char(42,VV[21]);
	(void)((*(LnkLI262))((VV[16]->s.s_dbind)));
	princ_str("base",VV[21]);
	V785 = make_fixnum(V783);
	(void)((*(LnkLI262))(V785));
	princ_char(59,VV[21]);
	goto T2696;
T2701:;
	princ_char(42,VV[21]);
	(void)((*(LnkLI262))((VV[16]->s.s_dbind)));
	princ_str("base",VV[21]);
	V786 = make_fixnum(V783);
	(void)((*(LnkLI262))(V786));
	princ_char(44,VV[21]);
	V783= (V783)+1;
	goto T2700;}
T2696:;
	V787= structure_ref(cadr((V769)),VV[58],1);
	(void)((*(LnkLI295))(/* INLINE-ARGS */V787,small_fixnum(2)));
	bds_bind(VV[124],VV[123]);
	bds_bind(VV[237],(V767));
	bds_bind(VV[14],Cnil);
	bds_bind(VV[125],small_fixnum(0));
	bds_bind(VV[126],small_fixnum(0));
	V788 = make_fixnum(V770);
	bds_bind(VV[127],one_plus(V788));
	bds_bind(VV[128],(V767));
	bds_bind(VV[129],(V766));
	bds_bind(VV[130],make_cons((VV[124]->s.s_dbind),Cnil));
	bds_bind(VV[131],(VV[124]->s.s_dbind));
	setq(VV[133],number_plus(symbol_value(VV[133]),small_fixnum(1)));
	bds_bind(VV[132],symbol_value(VV[133]));
	bds_bind(VV[134],Cnil);
	bds_bind(VV[135],Cnil);
	bds_bind(VV[136],Cnil);
	bds_bind(VV[137],small_fixnum(0));
	princ_str("\n{	register object *",VV[21]);
	(void)((*(LnkLI262))((VV[16]->s.s_dbind)));
	princ_str("base=vs_base;",VV[21]);
	princ_str("\n	register object *",VV[21]);
	(void)((*(LnkLI262))((VV[16]->s.s_dbind)));
	princ_str("sup=base+VM",VV[21]);
	(void)((*(LnkLI262))((VV[132]->s.s_dbind)));
	princ_char(59,VV[21]);
	V789= structure_ref(cadr((V769)),VV[58],1);
	V790= structure_ref((V768),VV[28],3);
	(void)((*(LnkLI301))(/* INLINE-ARGS */V789,/* INLINE-ARGS */V790,VV[245]));
	princ_str(" VC",VV[21]);
	(void)((*(LnkLI262))((VV[132]->s.s_dbind)));
	if((symbol_value(VV[152]))==Cnil){
	goto T2741;}
	princ_str("\n	vs_reserve(VM",VV[21]);
	(void)((*(LnkLI262))((VV[132]->s.s_dbind)));
	princ_str(");",VV[21]);
	goto T2739;
T2741:;
	princ_str("\n	vs_check;",VV[21]);
T2739:;
	if((symbol_value(VV[145]))==Cnil){
	goto T2747;}
	princ_str("\n	ihs_check;",VV[21]);
T2747:;
	if(((V765))==Cnil){
	goto T2753;}
	(void)((VFUN_NARGS=2,(*(LnkLI318))(caddr((V769)),caddr(cddr((V769))))));
	goto T2751;
T2753:;
	(void)((VFUN_NARGS=3,(*(LnkLI318))(caddr((V769)),caddr(cddr((V769))),(V768))));
T2751:;
	princ_str("\n}",VV[21]);
	V791= make_cons((VV[132]->s.s_dbind),(VV[126]->s.s_dbind));
	setq(VV[29],make_cons(/* INLINE-ARGS */V791,symbol_value(VV[29])));
	princ_str("\n#define VC",VV[27]);
	(void)((*(LnkLI265))((VV[132]->s.s_dbind)));
	V792= (*(LnkLI319))();
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
	V793= structure_ref((V768),VV[28],3);
	{object V794 = (*(LnkLI297))(/* INLINE-ARGS */V793);
	bds_unwind1;
	bds_unwind1;
	VMR53(V794)}}
}
/*	local entry for function WT-CVARS	*/

static object LI55()

{	 VMB54 VMS54 VMV54
TTL:;
	{register object V795;
	V795= Cnil;
	{register object V796;
	register object V797;
	V796= symbol_value(VV[14]);
	V797= car((V796));
T2767:;
	if(!(endp((V796)))){
	goto T2768;}
	goto T2763;
T2768:;
	{register object V798;
	if(!(type_of((V797))==t_cons)){
	goto T2775;}
	{register object V799;
	V799= car((V797));
	V797= cdr((V797));
	V798= (V799);
	goto T2773;}
T2775:;
	V798= Ct;
T2773:;
	if(!(((V795))==((V798)))){
	goto T2782;}
	base[1]= symbol_value(VV[27]);
	base[2]= VV[246];
	base[3]= (V797);
	vs_top=(vs_base=base+1)+3;
	Lformat();
	vs_top=sup;
	goto T2780;
T2782:;
	if(!(((V795))==Cnil)){
	goto T2788;}
	goto T2787;
T2788:;
	base[1]= symbol_value(VV[27]);
	base[2]= VV[247];
	vs_top=(vs_base=base+1)+2;
	Lformat();
	vs_top=sup;
T2787:;
	V795= (V798);
	base[1]= symbol_value(VV[27]);
	base[2]= VV[248];
	base[3]= (*(LnkLI268))((V795));
	base[4]= (V797);
	vs_top=(vs_base=base+1)+4;
	Lformat();
	vs_top=sup;
T2780:;
	if(!(((V795))==(VV[249]))){
	goto T2772;}
	base[1]= symbol_value(VV[27]);
	base[2]= VV[250];
	base[3]= (V797);
	vs_top=(vs_base=base+1)+3;
	Lformat();
	vs_top=sup;}
T2772:;
	V796= cdr((V796));
	V797= car((V796));
	goto T2767;}
T2763:;
	if(symbol_value(VV[14])==Cnil){
	goto T2808;}
	base[0]= symbol_value(VV[27]);
	base[1]= VV[251];
	vs_top=(vs_base=base+0)+2;
	Lformat();
	vs_top=sup;
T2808:;
	if(eql(symbol_value(VV[137]),small_fixnum(0))){
	goto T2812;}
	base[0]= symbol_value(VV[27]);
	base[1]= VV[252];
	base[2]= symbol_value(VV[137]);
	vs_top=(vs_base=base+0)+3;
	Lformat();
	vs_top=sup;
	{object V800 = vs_base[0];
	VMR54(V800)}
T2812:;
	{object V801 = Cnil;
	VMR54(V801)}}
}
/*	local function DO-DECL	*/

static L25(base0)
register object *base0;
{	register object *base=vs_base;
	register object *sup=base+VM55; VC55
	vs_reserve(VM55);
	{object V802;
	check_arg(1);
	V802=(base[0]);
	vs_top=sup;
TTL:;
	V803= structure_ref((V802),VV[65],4);
	if(eql(/* INLINE-ARGS */V803,VV[68])){
	goto T2818;}
	goto T2817;
T2818:;
	(VV[148]->s.s_dbind)= Ct;
T2817:;
	{object V804;
	V804= (*(LnkLI333))((V802));
	if(((V804))==Cnil){
	goto T2823;}
	{object V805;
	setq(VV[84],number_plus(symbol_value(VV[84]),small_fixnum(1)));
	V805= symbol_value(VV[84]);
	(void)(structure_set((V802),VV[65],1,(V804)));
	(void)(structure_set((V802),VV[65],4,(V805)));
	princ_str("\n	",VV[21]);
	if((base0[1])!=Cnil){
	goto T2830;}
	princ_char(123,VV[21]);
	base0[1]= Ct;
T2830:;
	base[1]= (V802);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk334)();
	return;}
T2823:;
	base[1]= Cnil;
	vs_top=(vs_base=base+1)+1;
	return;}
	}
}
static LnkT334(){ call_or_link(VV[334],&Lnk334);} /* WT-VAR-DECL */
static object  LnkTLI333(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[333],&LnkLI333,1,ap);} /* C2VAR-KIND */
static object  LnkTLI238(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[238],&LnkLI238,5,ap);} /* T3LOCAL-DCFUN */
static object  LnkTLI327(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[327],&LnkLI327,1,ap);} /* PARSE-CVSPECS */
static object  LnkTLI326(){return call_proc0(VV[326],&LnkLI326);} /* WFS-ERROR */
static LnkT325(){ call_or_link(VV[325],&Lnk325);} /* C2DM */
static object  LnkTLI324(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[324],&LnkLI324,3,ap);} /* C1DM */
static object  LnkTLI323(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[323],&LnkLI323,ap);} /* REMOVE-DUPLICATES */
static int  LnkTLI322(va_alist)va_dcl{va_list ap;va_start(ap);return(int )call_proc(VV[322],&LnkLI322,258,ap);} /* ANALYZE-REGS1 */
static object  LnkTLI321(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[321],&LnkLI321,ap);} /* WARN */
static object  LnkTLI320(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[320],&LnkLI320,1,ap);} /* REGISTER */
static object  LnkTLI319(){return call_proc0(VV[319],&LnkLI319);} /* WT-CVARS */
static object  LnkTLI318(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[318],&LnkLI318,ap);} /* C2LAMBDA-EXPR */
static object  LnkTLI317(){return call_proc0(VV[317],&LnkLI317);} /* CLOSE-INLINE-BLOCKS */
static object  LnkTLI316(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[316],&LnkLI316,1,ap);} /* WT-VS */
static object  LnkTLI315(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[315],&LnkLI315,1,ap);} /* C2BIND */
static object  LnkTLI314(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[314],&LnkLI314,1,ap);} /* ADD-SYMBOL */
static object  LnkTLI313(){return call_proc0(VV[313],&LnkLI313);} /* BABOON */
static object  LnkTLI312(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[312],&LnkLI312,1,ap);} /* ADD-OBJECT */
static LnkT311(){ call_or_link(VV[311],&Lnk311);} /* INC-INLINE-BLOCKS */
static object  LnkTLI310(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[310],&LnkLI310,ap);} /* CS-PUSH */
static object  LnkTLI309(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[309],&LnkLI309,2,ap);} /* C2BIND-INIT */
static object  LnkTLI308(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[308],&LnkLI308,2,ap);} /* C2BIND-LOC */
static object  LnkTLI307(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[307],&LnkLI307,1,ap);} /* SET-UP-VAR-CVS */
static object  LnkTLI306(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[306],&LnkLI306,1,ap);} /* WT-LIST */
static object  LnkTLI305(){return call_proc0(VV[305],&LnkLI305);} /* CVS-PUSH */
static object  LnkTLI304(){return call_proc0(VV[304],&LnkLI304);} /* VS-PUSH */
static object  LnkTLI303(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[303],&LnkLI303,2,ap);} /* WT-V*-MACROS */
static LnkT302(){ call_or_link(VV[302],&Lnk302);} /* C2EXPR */
static object  LnkTLI301(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[301],&LnkLI301,3,ap);} /* ASSIGN-DOWN-VARS */
static object  LnkTLI300(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[300],&LnkLI300,2,ap);} /* WT-REQUIREDS */
static object  LnkTLI299(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[299],&LnkLI299,ap);} /* WT-COMMENT */
static object  LnkTLI298(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[298],&LnkLI298,2,ap);} /* ADD-DEBUG-INFO */
static object  LnkTLI297(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[297],&LnkLI297,1,ap);} /* WT-DOWNWARD-CLOSURE-MACRO */
static LnkT296(){ call_or_link(VV[296],&Lnk296);} /* T3DEFUN-AUX */
static int  LnkTLI295(va_alist)va_dcl{va_list ap;va_start(ap);return(int )call_proc(VV[295],&LnkLI295,258,ap);} /* ANALYZE-REGS */
static LnkT294(){ call_or_link(VV[294],&Lnk294);} /* FIXNUMP */
static object  LnkTLI293(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[293],&LnkLI293,1,ap);} /* VOLATILE */
static object  LnkTLI292(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[292],&LnkLI292,1,ap);} /* MAXARGS */
static object  LnkTLI291(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[291],&LnkLI291,1,ap);} /* VARARG-P */
static object  LnkTLI290(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[290],&LnkLI290,3,ap);} /* WT-IF-PROCLAIMED */
static int  LnkTLI289(va_alist)va_dcl{va_list ap;va_start(ap);return(int )call_proc(VV[289],&LnkLI289,258,ap);} /* PROCLAIMED-ARGD */
static object  LnkTLI288(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[288],&LnkLI288,2,ap);} /* ADD-ADDRESS */
static object  LnkTLI287(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[287],&LnkLI287,ap);} /* ADD-INIT */
static object  LnkTLI286(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[286],&LnkLI286,ap);} /* FAST-LINK-PROCLAIMED-TYPE-P */
static object  LnkTLI285(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[285],&LnkLI285,2,ap);} /* SHIFT<< */
static int  LnkTLI284(va_alist)va_dcl{va_list ap;va_start(ap);return(int )call_proc(VV[284],&LnkLI284,257,ap);} /* F-TYPE */
static LnkT283(){ call_or_link(VV[283],&Lnk283);} /* SUBTYPEP */
static LnkT282(){ call_or_link(VV[282],&Lnk282);} /* STRUCTURE-SUBTYPE-P */
static object  LnkTLI281(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[281],&LnkLI281,ap);} /* MAKE-ARRAY */
static object  LnkTLI280(){return call_proc0(VV[280],&LnkLI280);} /* ADD-LOAD-TIME-SHARP-COMMA */
static object  LnkTLI279(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[279],&LnkLI279,2,ap);} /* MAKE-INLINE-STRING */
static object  LnkTLI278(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[278],&LnkLI278,2,ap);} /* TYPE-AND */
static object  LnkTLI277(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[277],&LnkLI277,2,ap);} /* CMPFIX-ARGS */
static object  LnkTLI276(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[276],&LnkLI276,1,ap);} /* PROCLAIM */
static object  LnkTLI275(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[275],&LnkLI275,1,ap);} /* CHECK-DOWNWARD */
static object  LnkTLI274(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[274],&LnkLI274,ap);} /* C1LAMBDA-EXPR */
static object  LnkTLI273(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[273],&LnkLI273,1,ap);} /* T1PROGN */
static object  LnkTLI270(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[270],&LnkLI270,3,ap);} /* TOO-FEW-ARGS */
static LnkT269(){ call_or_link(VV[269],&Lnk269);} /* CMP-EVAL */
static object  LnkTLI268(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[268],&LnkLI268,1,ap);} /* REP-TYPE */
static LnkT267(){ call_or_link(VV[267],&Lnk267);} /* WT-DATA-FILE */
static object  LnkTLI266(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[266],&LnkLI266,1,ap);} /* PUSH-DATA-INCF */
static object  LnkTLI265(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[265],&LnkLI265,1,ap);} /* WT-H1 */
static object  LnkTLI264(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[264],&LnkLI264,1,ap);} /* WT-FUNCTION-LINK */
static LnkT263(){ call_or_link(VV[263],&Lnk263);} /* WT-GLOBAL-ENTRY */
static LnkT245(){ call_or_link(VV[245],&Lnk245);} /* T3LOCAL-FUN */
static object  LnkTLI262(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[262],&LnkLI262,1,ap);} /* WT1 */
static object  LnkTLI261(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[261],&LnkLI261,3,ap);} /* CMP-EXPAND-MACRO */
static object  LnkTLI260(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[260],&LnkLI260,1,ap);} /* T1ORDINARY */
static LnkT259(){ call_or_link(VV[259],&Lnk259);} /* T1EXPR */
static object  LnkTLI258(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[258],&LnkLI258,1,ap);} /* CMP-MACROEXPAND-1 */
static object  LnkTLI257(){return call_proc0(VV[257],&LnkLI257);} /* PRINT-CURRENT-FORM */
static object  LnkTLI256(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[256],&LnkLI256,1,ap);} /* WT-DATA-PACKAGE-OPERATION */
static object  LnkTLI255(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[255],&LnkLI255,2,ap);} /* MAYBE-EVAL */
static object  LnkTLI254(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[254],&LnkLI254,ap);} /* CMPWARN */
static object  LnkTLI253(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[253],&LnkLI253,ap);} /* CMPERR */
