
#include <cmpinclude.h>
#include "cmpinline.h"
init_cmpinline(){do_init(VV);}
/*	local entry for function MAKE-INFO	*/

static object LI1(va_alist)
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB1 VMS1 VMV1
	{object V1;
	object V2;
	object V3;
	object V4;
	object V5;
	narg= narg - 0;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +0,&LI1key,ap);
	V1=(Vcs[0]);
	V2=(Vcs[1]);
	if(Vcs[2]==0){
	V3= Ct;
	}else{
	V3=(Vcs[2]);}
	V4=(Vcs[3]);
	V5=(Vcs[4]);
	base[0]= VV[0];
	base[1]= (V1);
	base[2]= (V2);
	base[3]= (V3);
	base[4]= (V4);
	base[5]= (V5);
	vs_top=(vs_base=base+0)+6;
	siLmake_structure();
	vs_top=sup;
	{object V6 = vs_base[0];
	VMR1(V6)}}
	}}
/*	local entry for function ADD-INFO	*/

static object LI2(V9,V10)

register object V9;object V10;
{	 VMB2 VMS2 VMV2
TTL:;
	V11= structure_ref((V10),VV[0],0);
	V12= structure_ref((V9),VV[0],0);
	V13= append(/* INLINE-ARGS */V11,/* INLINE-ARGS */V12);
	(void)(structure_set((V9),VV[0],0,/* INLINE-ARGS */V13));
	V14= structure_ref((V10),VV[0],1);
	V15= structure_ref((V9),VV[0],1);
	V16= append(/* INLINE-ARGS */V14,/* INLINE-ARGS */V15);
	(void)(structure_set((V9),VV[0],1,/* INLINE-ARGS */V16));
	if((structure_ref((V10),VV[0],3))==Cnil){
	goto T11;}
	{object V17 = structure_set((V9),VV[0],3,Ct);
	VMR2(V17)}
T11:;
	{object V18 = Cnil;
	VMR2(V18)}
}
/*	local entry for function ARGS-INFO-CHANGED-VARS	*/

static object LI3(V21,V22)

register object V21;object V22;
{	 VMB3 VMS3 VMV3
TTL:;
	V24= structure_ref((V21),VV[1],1);
	{object V23= /* INLINE-ARGS */V24;
	if((V23== VV[70])
	|| (V23== VV[44])
	|| (V23== VV[71])
	|| (V23== VV[45])
	|| (V23== VV[46]))goto T14;
	if((V23!= VV[18]))goto T13;
T14:;
	{register object V25;
	register object V26;
	V25= (V22);
	V26= car((V25));
T18:;
	if(!(endp((V25)))){
	goto T19;}
	{object V27 = Cnil;
	VMR3(V27)}
T19:;
	V29= structure_ref(cadr((V26)),VV[0],0);
	{register object x= (V21),V28= /* INLINE-ARGS */V29;
	while(!endp(V28))
	if(eql(x,V28->c.c_car)){
	goto T25;
	}else V28=V28->c.c_cdr;
	goto T23;}
T25:;
	{object V30 = Ct;
	VMR3(V30)}
T23:;
	V25= cdr((V25));
	V26= car((V25));
	goto T18;}
T13:;
	if((V23!= VV[72]))goto T31;
	{object V31 = Cnil;
	VMR3(V31)}
T31:;
	{register object V32;
	register object V33;
	V32= (V22);
	V33= car((V32));
T35:;
	if(!(endp((V32)))){
	goto T36;}
	{object V34 = Cnil;
	VMR3(V34)}
T36:;
	V36= structure_ref(cadr((V33)),VV[0],0);
	{register object x= (V21),V35= /* INLINE-ARGS */V36;
	while(!endp(V35))
	if(eql(x,V35->c.c_car)){
	goto T41;
	}else V35=V35->c.c_cdr;}
	if((structure_ref(cadr((V33)),VV[0],3))==Cnil){
	goto T40;}
T41:;
	{object V37 = Ct;
	VMR3(V37)}
T40:;
	V32= cdr((V32));
	V33= car((V32));
	goto T35;}}
}
/*	local entry for function ARGS-INFO-REFERRED-VARS	*/

static object LI4(V40,V41)

register object V40;object V41;
{	 VMB4 VMS4 VMV4
TTL:;
	V43= structure_ref((V40),VV[1],1);
	{object V42= /* INLINE-ARGS */V43;
	if((V42== VV[70])
	|| (V42== VV[72])
	|| (V42== VV[44])
	|| (V42== VV[71])
	|| (V42== VV[45]))goto T51;
	if((V42!= VV[46])
	&& (V42!= VV[18]))goto T50;
T51:;
	{register object V44;
	register object V45;
	V44= (V41);
	V45= car((V44));
T55:;
	if(!(endp((V44)))){
	goto T56;}
	{object V46 = Cnil;
	VMR4(V46)}
T56:;
	V48= structure_ref(cadr((V45)),VV[0],1);
	{register object x= (V40),V47= /* INLINE-ARGS */V48;
	while(!endp(V47))
	if(eql(x,V47->c.c_car)){
	goto T62;
	}else V47=V47->c.c_cdr;
	goto T60;}
T62:;
	{object V49 = Ct;
	VMR4(V49)}
T60:;
	V44= cdr((V44));
	V45= car((V44));
	goto T55;}
T50:;
	{register object V50;
	register object V51;
	V50= (V41);
	V51= car((V50));
T71:;
	if(!(endp((V50)))){
	goto T72;}
	{object V52 = Cnil;
	VMR4(V52)}
T72:;
	V54= structure_ref(cadr((V51)),VV[0],1);
	{register object x= (V40),V53= /* INLINE-ARGS */V54;
	while(!endp(V53))
	if(eql(x,V53->c.c_car)){
	goto T77;
	}else V53=V53->c.c_cdr;}
	if((structure_ref(cadr((V51)),VV[0],3))==Cnil){
	goto T76;}
T77:;
	{object V55 = Ct;
	VMR4(V55)}
T76:;
	V50= cdr((V50));
	V51= car((V50));
	goto T71;}}
}
/*	function definition for INC-INLINE-BLOCKS	*/

static L5()
{register object *base=vs_base;
	register object *sup=base+VM5; VC5
	vs_reserve(VM5);
	check_arg(0);
	vs_top=sup;
TTL:;
	if(!(type_of(symbol_value(VV[2]))==t_cons)){
	goto T87;}
	{object V56;
	object V57;
	V56= symbol_value(VV[2]);
	V57= number_plus(car((V56)),small_fixnum(1));
	if(type_of((V56))!=t_cons)FEwrong_type_argument(Scons,(V56));
	((V56))->c.c_car = (V57);
	base[1]= (V57);
	vs_top=(vs_base=base+1)+1;
	return;}
T87:;
	setq(VV[2],number_plus(symbol_value(VV[2]),small_fixnum(1)));
	base[0]= symbol_value(VV[2]);
	vs_top=(vs_base=base+0)+1;
	return;
}
/*	local entry for function INLINE-ARGS	*/

static object LI6(V59,V58,va_alist)
	object V59,V58;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB6 VMS6 VMV6
	bds_check;
	{object V60;
	object V61;
	object V62;
	if(narg <2) too_few_arguments();
	V60= V59;
	V61= V58;
	narg = narg - 2;
	if (narg <= 0) goto T93;
	else {
	va_start(ap);
	V62= va_arg(ap,object);}
	--narg; goto T94;
T93:;
	V62= Cnil;
T94:;
	{register object V63;
	register object V64;
	V63= Cnil;
	V64= Cnil;
	{register object V65;
	object V66;
	V65= (V60);
	V66= (V61);
T99:;
	if(!(endp((V65)))){
	goto T100;}
	{object V67 = reverse((V63));
	VMR6(V67)}
T100:;
	{register object V68;
	register object V69;
	V68= car((V65));
	V69= car((V66));
	{object V70= car((V68));
	if((V70!= VV[14]))goto T107;
	V71= (*(LnkLI73))(caddr((V68)),(V69));
	V63= make_cons(/* INLINE-ARGS */V71,(V63));
	goto T104;
T107:;
	if((V70!= VV[1]))goto T109;
	if(((*(LnkLI74))(caaddr((V68)),cdr((V65))))==Cnil){
	goto T111;}
	V73= structure_ref(caaddr((V68)),VV[1],1);
	{register object x= /* INLINE-ARGS */V73,V72= symbol_value(VV[3]);
	while(!endp(V72))
	if(eql(x,V72->c.c_car)){
	goto T116;
	}else V72=V72->c.c_cdr;
	goto T114;}
T116:;
	V74= structure_ref(caaddr((V68)),VV[1],1);
	if(!(((V69))==(/* INLINE-ARGS */V74))){
	goto T114;}
	{object V75;
	setq(VV[4],number_plus(symbol_value(VV[4]),small_fixnum(1)));
	V75= symbol_value(VV[4]);
	princ_str("\n	{",VV[5]);
	V76= (*(LnkLI76))((V69));
	(void)((*(LnkLI75))(/* INLINE-ARGS */V76));
	princ_char(86,VV[5]);
	(void)((*(LnkLI75))((V75)));
	princ_str("= V",VV[5]);
	V77= structure_ref(caaddr((V68)),VV[1],4);
	(void)((*(LnkLI75))(/* INLINE-ARGS */V77));
	princ_char(59,VV[5]);
	V78= list(3,VV[6],(V75),VV[7]);
	V63= make_cons(/* INLINE-ARGS */V78,(V63));
	vs_base=vs_top;
	(void) (*Lnk77)();
	vs_top=sup;
	goto T104;}
T114:;
	{object V79;
	V79= (*(LnkLI78))();
	princ_str("\n	",VV[5]);
	(void)((*(LnkLI75))((V79)));
	princ_str("= ",VV[5]);
	(void)((*(LnkLI79))(caaddr((V68)),cadr(caddr((V68)))));
	princ_char(59,VV[5]);
	V80= (*(LnkLI73))((V79),(V69));
	V63= make_cons(/* INLINE-ARGS */V80,(V63));
	goto T104;}
T111:;
	V82= structure_ref(caaddr((V68)),VV[1],1);
	{register object x= /* INLINE-ARGS */V82,V81= VV[8];
	while(!endp(V81))
	if(eql(x,V81->c.c_car)){
	goto T142;
	}else V81=V81->c.c_cdr;
	goto T140;}
T142:;
	V83= structure_ref(caaddr((V68)),VV[1],1);
	if(((V69))==(/* INLINE-ARGS */V83)){
	goto T140;}
	{object V84;
	V84= (VFUN_NARGS=1,(*(LnkLI80))((V69)));
	princ_str("\n	V",VV[5]);
	(void)((*(LnkLI75))((V84)));
	princ_str(" = ",VV[5]);
	V85= make_cons(VV[1],caddr((V68)));
	V86= (*(LnkLI73))(/* INLINE-ARGS */V85,(V69));
	(void)((*(LnkLI75))(/* INLINE-ARGS */V86));
	princ_char(59,VV[5]);
	V87= list(2,VV[6],(V84));
	V63= make_cons(/* INLINE-ARGS */V87,(V63));
	goto T104;}
T140:;
	V88= make_cons(VV[1],caddr((V68)));
	V89= (*(LnkLI73))(/* INLINE-ARGS */V88,(V69));
	V63= make_cons(/* INLINE-ARGS */V89,(V63));
	goto T104;
T109:;
	if((V70!= VV[81]))goto T153;
	{object V90;
	V90= caddr((V68));
	if(((*(LnkLI82))((V90)))!=Cnil){
	goto T158;}
	goto T155;
T158:;
	V91= cadddr((V68));
	V92= structure_ref(cadr((V68)),VV[0],2);
	V64= (*(LnkLI83))((V90),/* INLINE-ARGS */V91,/* INLINE-ARGS */V92);
	if(((V64))!=Cnil){
	goto T160;}
	goto T155;
T160:;
	base[0]= (V64);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk84)();
	vs_top=sup;}
	{register object V93;
	V93= (*(LnkLI85))((V64),cadddr((V68)));
	base[0]= small_fixnum(0);
	base[1]= caddr((V64));
	vs_top=(vs_base=base+0)+2;
	Llogbitp();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T168;}
	if((symbol_value(VV[9]))==Cnil){
	goto T166;}
T168:;
	{register object x= cadr((V64)),V94= VV[10];
	while(!endp(V94))
	if(eql(x,V94->c.c_car)){
	goto T175;
	}else V94=V94->c.c_cdr;
	goto T167;}
T175:;
	if(((V69))==(cadr((V64)))){
	goto T167;}
T166:;
	{object V95;
	V95= (VFUN_NARGS=1,(*(LnkLI80))((V69)));
	princ_str("\n	V",VV[5]);
	(void)((*(LnkLI75))((V95)));
	princ_str(" = ",VV[5]);
	V96= (*(LnkLI73))((V93),(V69));
	(void)((*(LnkLI75))(/* INLINE-ARGS */V96));
	princ_char(59,VV[5]);
	V97= list(2,VV[6],(V95));
	V63= make_cons(/* INLINE-ARGS */V97,(V63));
	goto T104;}
T167:;
	if(((*(LnkLI86))(cdr((V65)),cdr((V66))))!=Cnil){
	goto T185;}
	base[0]= small_fixnum(0);
	base[1]= caddr((V64));
	vs_top=(vs_base=base+0)+2;
	Llogbitp();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T189;}
	if(((V62))==Cnil){
	goto T185;}
	{register object x= (V62),V98= VV[11];
	while(!endp(V98))
	if(x==(V98->c.c_car)){
	goto T196;
	}else V98=V98->c.c_cdr;
	goto T185;}
T196:;
T189:;
	base[0]= small_fixnum(4);
	base[1]= caddr((V64));
	vs_top=(vs_base=base+0)+2;
	Llogbitp();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T185;}
	base[0]= small_fixnum(1);
	base[1]= caddr((V64));
	vs_top=(vs_base=base+0)+2;
	Llogbitp();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T186;}
	if((cdr((V65)))==Cnil){
	goto T186;}
T185:;
	{object V99;
	V99= Cnil;
	if(!(((V69))==(Ct))){
	goto T208;}
	V99= (VFUN_NARGS=0,(*(LnkLI80))());
	princ_str("\n	V",VV[5]);
	(void)((*(LnkLI75))((V99)));
	princ_str("= ",VV[5]);
	base[0]= (V93);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk87)();
	vs_top=sup;
	goto T206;
T208:;
	setq(VV[4],number_plus(symbol_value(VV[4]),small_fixnum(1)));
	V99= symbol_value(VV[4]);
	princ_str("\n	{",VV[5]);
	V100= (*(LnkLI76))((V69));
	(void)((*(LnkLI75))(/* INLINE-ARGS */V100));
	princ_char(86,VV[5]);
	(void)((*(LnkLI75))((V99)));
	princ_str("= ",VV[5]);
	{object V101= (V69);
	if((V101!= VV[44]))goto T227;
	base[0]= (V93);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk88)();
	vs_top=sup;
	goto T226;
T227:;
	if((V101!= VV[89]))goto T229;
	base[0]= (V93);
	base[1]= VV[7];
	vs_top=(vs_base=base+0)+2;
	(void) (*Lnk90)();
	vs_top=sup;
	goto T226;
T229:;
	if((V101!= VV[71]))goto T232;
	base[0]= (V93);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk91)();
	vs_top=sup;
	goto T226;
T232:;
	if((V101!= VV[45]))goto T234;
	base[0]= (V93);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk92)();
	vs_top=sup;
	goto T226;
T234:;
	if((V101!= VV[46]))goto T236;
	base[0]= (V93);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk93)();
	vs_top=sup;
	goto T226;
T236:;
	base[0]= (V93);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk87)();
	vs_top=sup;}
T226:;
	vs_base=vs_top;
	(void) (*Lnk77)();
	vs_top=sup;
T206:;
	princ_char(59,VV[5]);
	V102= list(3,VV[6],(V99),VV[7]);
	V63= make_cons(/* INLINE-ARGS */V102,(V63));
	goto T104;}
T186:;
	V103= (*(LnkLI73))((V93),(V69));
	V63= make_cons(/* INLINE-ARGS */V103,(V63));
	goto T104;}
T155:;
	{object V104;
	if((symbol_value(VV[9]))==Cnil){
	goto T245;}
	V104= list(2,VV[6],(VFUN_NARGS=0,(*(LnkLI80))()));
	goto T243;
T245:;
	V104= list(2,VV[12],(*(LnkLI94))());
T243:;
	bds_bind(VV[13],(V104));
	V105= (*(LnkLI95))((V68));
	bds_unwind1;
	V106= (*(LnkLI73))((V104),(V69));
	V63= make_cons(/* INLINE-ARGS */V106,(V63));
	goto T104;}
T153:;
	if((V70!= VV[96]))goto T249;
	V107= (*(LnkLI97))(cdr((V68)),(V69));
	V63= make_cons(/* INLINE-ARGS */V107,(V63));
	goto T104;
T249:;
	if((V70!= VV[98]))goto T251;
	{object V108;
	object V109;
	V108= caddr((V68));
	V109= cadddr((V68));
	base[0]= make_cons(VV[1],(V108));
	bds_bind(VV[13],base[0]);
	V110= (*(LnkLI95))((V109));
	bds_unwind1;
	if(!((car((V109)))==(VV[14]))){
	goto T257;}
	V111= (*(LnkLI73))(caddr((V109)),(V69));
	V63= make_cons(/* INLINE-ARGS */V111,(V63));
	goto T104;
T257:;
	V65= listA(3,(V68),list(3,VV[1],cadr((V68)),(V108)),cdr((V65)));
	V66= make_cons((V69),(V66));
	goto T104;}
T251:;
	{object V112;
	if((symbol_value(VV[9]))==Cnil){
	goto T265;}
	if(!(((V69))==(Ct))){
	goto T268;}
	V112= list(2,VV[6],(VFUN_NARGS=0,(*(LnkLI80))()));
	goto T263;
T268:;
	setq(VV[4],number_plus(symbol_value(VV[4]),small_fixnum(1)));
	V113= make_cons((V69),symbol_value(VV[4]));
	setq(VV[15],make_cons(/* INLINE-ARGS */V113,symbol_value(VV[15])));
	{register object x= (V69),V115= symbol_value(VV[3]);
	while(!endp(V115))
	if(eql(x,V115->c.c_car)){
	goto T276;
	}else V115=V115->c.c_cdr;
	goto T275;}
T276:;
	V114= (V69);
	goto T273;
T275:;
	V114= VV[18];
T273:;
	V116= (VFUN_NARGS=6,(*(LnkLI99))(VV[16],(V69),VV[17],V114,VV[19],cdar(symbol_value(VV[15]))));
	V112= list(3,VV[1],/* INLINE-ARGS */V116,Cnil);
	goto T263;
T265:;
	V112= list(2,VV[12],(*(LnkLI94))());
T263:;
	bds_bind(VV[13],(V112));
	(void)((*(LnkLI95))((V68)));
	V117= (*(LnkLI73))((V112),(V69));
	V63= make_cons(/* INLINE-ARGS */V117,(V63));
	bds_unwind1;}}}
T104:;
	V65= cdr((V65));
	V66= cdr((V66));
	goto T99;}}}
	}
/*	local entry for function COERCE-LOC	*/

static object LI7(V120,V121)

register object V120;object V121;
{	 VMB7 VMS7 VMV7
TTL:;
	{object V122= (V121);
	if((V122!= VV[44]))goto T283;
	{object V123 = list(2,VV[20],(V120));
	VMR7(V123)}
T283:;
	if((V122!= VV[89]))goto T284;
	{object V124 = list(2,VV[21],(V120));
	VMR7(V124)}
T284:;
	if((V122!= VV[71]))goto T285;
	{object V125 = list(2,VV[22],(V120));
	VMR7(V125)}
T285:;
	if((V122!= VV[45]))goto T286;
	{object V126 = list(2,VV[23],(V120));
	VMR7(V126)}
T286:;
	if((V122!= VV[46]))goto T287;
	{object V127 = list(2,VV[24],(V120));
	VMR7(V127)}
T287:;
	{object V128 = (V120);
	VMR7(V128)}}
}
/*	local entry for function GET-INLINE-LOC	*/

static object LI8(V131,V132)

object V131;object V132;
{	 VMB8 VMS8 VMV8
TTL:;
	{object V133;
	object V134;
	V133= car(cdddr((V131)));
	V134= Cnil;
	V134= (VFUN_NARGS=3,(*(LnkLI7))((V132),car((V131)),(V133)));
	if(!(type_of((V133))==t_string)){
	goto T292;}
	base[1]= elt((V133),0);
	base[2]= VV[25];
	vs_top=(vs_base=base+1)+2;
	Lchar_eq();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T292;}
	{register int V135;
	object V136;
	V135= 1;
	V136= Cnil;
	{unsigned char V137;
	V137= char_code(elt((V133),V135));
T303:;
	base[1]= code_char(V137);
	base[2]= VV[26];
	vs_top=(vs_base=base+1)+2;
	Lchar_eq();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T304;}
	V135= (V135)+(1);
	goto T300;
T304:;
	V138 = make_fixnum(((V137))-(48));
	V136= make_cons(V138,(V136));
	V135= (V135)+(1);
	V137= char_code(elt((V133),V135));
	goto T303;}
T300:;
	{object V139;
	int V140;
	register object V141;
	V140= 0;
	V139= (V134);
	V141= Cnil;
T320:;
	if(!(endp((V139)))){
	goto T321;}
	V134= reverse((V141));
	goto T292;
T321:;
	V143 = make_fixnum(V140);
	{register object x= V143,V142= (V136);
	while(!endp(V142))
	if(eql(x,V142->c.c_car)){
	goto T329;
	}else V142=V142->c.c_cdr;
	goto T328;}
T329:;
	{register object V144;
	register object V145;
	object V146;
	V144= car((V139));
	V145= (V144);
	V146= Cnil;
	if(!(type_of((V144))==t_cons)){
	goto T333;}
	{register object x= car((V144)),V147= VV[27];
	while(!endp(V147))
	if(eql(x,V147->c.c_car)){
	goto T337;
	}else V147=V147->c.c_cdr;
	goto T333;}
T337:;
	V146= car((V144));
	V145= cadr((V144));
T333:;
	if(!(type_of((V145))==t_cons)){
	goto T342;}
	{register object x= car((V145)),V148= VV[28];
	while(!endp(V148))
	if(eql(x,V148->c.c_car)){
	goto T341;
	}else V148=V148->c.c_cdr;}
	{register object x= car((V145)),V149= VV[29];
	while(!endp(V149))
	if(eql(x,V149->c.c_car)){
	goto T348;
	}else V149=V149->c.c_cdr;
	goto T342;}
T348:;
	base[2]= small_fixnum(0);
	base[3]= cadr((V145));
	vs_top=(vs_base=base+2)+2;
	Llogbitp();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T341;}
	base[2]= small_fixnum(1);
	base[3]= cadr((V145));
	vs_top=(vs_base=base+2)+2;
	Llogbitp();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T342;}
T341:;
	princ_str("\n	{",VV[5]);
	vs_base=vs_top;
	(void) (*Lnk77)();
	vs_top=sup;
	{register object V150;
	setq(VV[4],number_plus(symbol_value(VV[4]),small_fixnum(1)));
	V150= symbol_value(VV[4]);
	V151= list(2,VV[6],(V150));
	V141= make_cons(/* INLINE-ARGS */V151,(V141));
	{object V152= (V146);
	if((V152!= Cnil))goto T364;
	princ_str("object V",VV[5]);
	(void)((*(LnkLI75))((V150)));
	princ_str("= ",VV[5]);
	base[2]= (V144);
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk87)();
	vs_top=sup;
	goto T359;
T364:;
	if((V152!= VV[20]))goto T370;
	princ_str("int V",VV[5]);
	(void)((*(LnkLI75))((V150)));
	princ_str("= ",VV[5]);
	base[2]= (V145);
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk88)();
	vs_top=sup;
	goto T359;
T370:;
	if((V152!= VV[21]))goto T376;
	princ_str("GEN V",VV[5]);
	(void)((*(LnkLI75))((V150)));
	princ_str("= ",VV[5]);
	base[2]= (V145);
	base[3]= VV[30];
	vs_top=(vs_base=base+2)+2;
	(void) (*Lnk90)();
	vs_top=sup;
	goto T359;
T376:;
	if((V152!= VV[22]))goto T383;
	princ_str("unsigned char V",VV[5]);
	(void)((*(LnkLI75))((V150)));
	princ_str("= ",VV[5]);
	base[2]= (V145);
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk91)();
	vs_top=sup;
	goto T359;
T383:;
	if((V152!= VV[23]))goto T389;
	princ_str("double V",VV[5]);
	(void)((*(LnkLI75))((V150)));
	princ_str("= ",VV[5]);
	base[2]= (V145);
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk92)();
	vs_top=sup;
	goto T359;
T389:;
	if((V152!= VV[24]))goto T395;
	princ_str("float V",VV[5]);
	(void)((*(LnkLI75))((V150)));
	princ_str("= ",VV[5]);
	base[2]= (V145);
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk93)();
	vs_top=sup;
	goto T359;
T395:;
	(void)((*(LnkLI100))());}}
T359:;
	princ_char(59,VV[5]);
	goto T326;
T342:;
	V141= make_cons((V144),(V141));
	goto T326;}
T328:;
	V141= make_cons(car((V139)),(V141));
T326:;
	V139= cdr((V139));
	V140= (V140)+1;
	goto T320;}}
T292:;
	V153= (*(LnkLI101))(cadr((V131)));
	{object V154 = list(4,/* INLINE-ARGS */V153,caddr((V131)),(V133),(V134));
	VMR8(V154)}}
}
/*	local entry for function INLINE-TYPE	*/

static object LI9(V156)

object V156;
{	 VMB9 VMS9 VMV9
TTL:;{object V157;
	{register object x= (V156),V159= symbol_value(VV[31]);
	while(!endp(V159))
	if(type_of(V159->c.c_car)==t_cons &&eql(x,V159->c.c_car->c.c_car)){
	V158= (V159->c.c_car);
	goto T410;
	}else V159=V159->c.c_cdr;
	V158= Cnil;}
T410:;
	V157= cdr(V158);
	if(V157==Cnil)goto T408;
	{object V160 = V157;
	VMR9(V160)}
T408:;}
	{object V161 = VV[32];
	VMR9(V161)}
}
/*	local entry for function GET-INLINE-INFO	*/

static object LI10(V165,V166,V167)

object V165;register object V166;object V167;
{	 VMB10 VMS10 VMV10
TTL:;
	{register object V168;
	base[0]=MMcons(Cnil,Cnil);
	V168= Cnil;
	if(((VFUN_NARGS=2,(*(LnkLI102))((V165),(V166))))!=Cnil){
	goto T413;}
	goto T412;
T413:;
	(void)((*(LnkLI103))((V165),(V167),(V166)));
T412:;
	{object V169;
	object V170= (V166);
	if(endp(V170)){
	V166= Cnil;
	goto T416;}
	base[1]=V169=MMcons(Cnil,Cnil);
T417:;
	(V169->c.c_car)= structure_ref(cadr((V170->c.c_car)),VV[0],2);
	if(endp(V170=MMcdr(V170))){
	V166= base[1];
	goto T416;}
	V169=MMcdr(V169)=MMcons(Cnil,Cnil);
	goto T417;}
T416:;
	if((symbol_value(VV[33]))==Cnil){
	goto T423;}
	(base[0]->c.c_car)= get((V165),VV[34],Cnil);
	if(((base[0]->c.c_car))==Cnil){
	goto T419;}
	goto T421;
T423:;
	(base[0]->c.c_car)= get((V165),VV[35],Cnil);
	if(((base[0]->c.c_car))==Cnil){
	goto T419;}
T421:;
	{register object V172;
	object V173;
	V172= (base[0]->c.c_car);
	V173= car((V172));
T430:;
	if(!(endp((V172)))){
	goto T431;}
	goto T419;
T431:;
	V168= (*(LnkLI104))((V173),(V166),(V167));
	if(((V168))==Cnil){
	goto T435;}
	{object V174 = (V168);
	VMR10(V174)}
T435:;
	V172= cdr((V172));
	V173= car((V172));
	goto T430;}
T419:;
	(base[0]->c.c_car)= get((V165),VV[36],Cnil);
	if(((base[0]->c.c_car))==Cnil){
	goto T444;}
	{register object V175;
	object V176;
	V175= (base[0]->c.c_car);
	V176= car((V175));
T451:;
	if(!(endp((V175)))){
	goto T452;}
	goto T444;
T452:;
	V168= (*(LnkLI104))((V176),(V166),(V167));
	if(((V168))==Cnil){
	goto T456;}
	{object V177 = (V168);
	VMR10(V177)}
T456:;
	V175= cdr((V175));
	V176= car((V175));
	goto T451;}
T444:;
	{register object V178;
	object V179;
	V178= symbol_value(VV[37]);
	V179= car((V178));
T469:;
	if(!(endp((V178)))){
	goto T470;}
	goto T465;
T470:;
	if(!((car((V179)))==((V165)))){
	goto T474;}
	V168= (*(LnkLI104))(cdr((V179)),(V166),(V167));
	if(((V168))==Cnil){
	goto T474;}
	{object V180 = (V168);
	VMR10(V180)}
T474:;
	V178= cdr((V178));
	V179= car((V178));
	goto T469;}
T465:;
	(base[0]->c.c_car)= get((V165),VV[38],Cnil);
	if(((base[0]->c.c_car))==Cnil){
	goto T485;}
	if(!(type_of((base[0]->c.c_car))==t_cons)){
	goto T492;}
	if(!(type_of(car((base[0]->c.c_car)))==t_fixnum)){
	goto T492;}
	{object V181;
	V182 = make_fixnum(length((V166)));
	V181= (number_compare(V182,car((base[0]->c.c_car)))>=0?Ct:Cnil);
	(base[0]->c.c_car)= cdr((base[0]->c.c_car));
	if(((V181))==Cnil){
	goto T485;}
	goto T490;}
T492:;
T490:;
	base[1]= make_fixnum(length((V166)));
	base[2]= VV[39];
	base[3]= Ct;
	vs_top=(vs_base=base+1)+3;
	Lmake_list();
	vs_top=sup;
	V183= vs_base[0];
	V184= 
	make_cclosure_new(LC27,Cnil,base[0],Cdata);
	{object V185 = list(4,V183,Ct,small_fixnum(3),V184);
	VMR10(V185)}
T485:;
	{object V186 = Cnil;
	VMR10(V186)}}
}
/*	local entry for function INLINE-TYPE-MATCHES	*/

static object LI11(V190,V191,V192)

register object V190;object V191;object V192;
{	 VMB11 VMS11 VMV11
TTL:;
	{register object V193;
	V193= Cnil;
	if(type_of(caddr((V190)))==t_fixnum){
	goto T505;}
	base[0]= (V190);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk105)();
	vs_top=sup;
T505:;
	{register object V194;
	V194= car((V190));
	{register object V195;
	register object V196;
	V195= (V191);
	V196= car((V195));
T517:;
	if(!(endp((V195)))){
	goto T518;}
	if(!(equal((V194),VV[40]))){
	goto T521;}
	goto T512;
T521:;
	if(!(endp((V194)))){
	goto T510;}
	goto T512;
T518:;
	if(!(endp((V194)))){
	goto T524;}
	goto T510;
T524:;
	if(!(equal((V194),VV[41]))){
	goto T527;}
	V194= VV[42];
T527:;
	if(!((car((V194)))==(VV[43]))){
	goto T533;}
	if(((*(LnkLI106))(VV[44],(V196)))==Cnil){
	goto T536;}
	V193= make_cons(VV[44],(V193));
	goto T531;
T536:;
	if(((*(LnkLI106))(VV[45],(V196)))==Cnil){
	goto T540;}
	V193= make_cons(VV[45],(V193));
	goto T531;
T540:;
	if(((*(LnkLI106))(VV[46],(V196)))==Cnil){
	goto T544;}
	V193= make_cons(VV[46],(V193));
	goto T531;
T544:;
	goto T510;
T533:;
	if(((*(LnkLI106))(car((V194)),(V196)))==Cnil){
	goto T548;}
	V193= make_cons(car((V194)),(V193));
	goto T531;
T548:;
	goto T510;
T531:;
	{register object V197;
	V197= car((V194));
	V194= cdr((V194));}
	V195= cdr((V195));
	V196= car((V195));
	goto T517;}}
T512:;
	if(((*(LnkLI106))(cadr((V190)),(V192)))==Cnil){
	goto T510;}
	V198= reverse((V193));
	{object V199 = make_cons(/* INLINE-ARGS */V198,cdr((V190)));
	VMR11(V199)}
T510:;
	{object V200 = Cnil;
	VMR11(V200)}}
}
/*	local entry for function NEED-TO-PROTECT	*/

static object LI12(V203,V204)

object V203;object V204;
{	 VMB12 VMS12 VMV12
TTL:;
	{register object V205;
	V205= Cnil;
	{register object V206;
	register object V207;
	V206= (V203);
	V207= (V204);
T563:;
	if(!(endp((V206)))){
	goto T564;}
	{object V208 = Cnil;
	VMR12(V208)}
T564:;
	{register object V209;
	V209= car((V206));
	{object V210= car((V209));
	if((V210!= VV[14]))goto T570;
	goto T568;
T570:;
	if((V210!= VV[1]))goto T571;
	if(((*(LnkLI74))(caaddr((V209)),cdr((V206))))!=Cnil){
	goto T572;}
	V212= structure_ref(caaddr((V209)),VV[1],1);
	{register object x= /* INLINE-ARGS */V212,V211= VV[47];
	while(!endp(V211))
	if(eql(x,V211->c.c_car)){
	goto T576;
	}else V211=V211->c.c_cdr;
	goto T568;}
T576:;
	V213= car((V207));
	V214= structure_ref(caaddr((V209)),VV[1],1);
	if((/* INLINE-ARGS */V213)==(/* INLINE-ARGS */V214)){
	goto T568;}
T572:;
	{object V215 = Ct;
	VMR12(V215)}
T571:;
	if((V210!= VV[81]))goto T578;
	{register object V216;
	V216= caddr((V209));
	if(((*(LnkLI82))((V216)))==Cnil){
	goto T580;}
	V217= cadddr((V209));
	V218= structure_ref(cadr((V209)),VV[0],2);
	V205= (*(LnkLI83))((V216),/* INLINE-ARGS */V217,/* INLINE-ARGS */V218);
	if(((V205))==Cnil){
	goto T580;}
	base[0]= small_fixnum(0);
	base[1]= caddr((V205));
	vs_top=(vs_base=base+0)+2;
	Llogbitp();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T580;}
	base[0]= small_fixnum(1);
	base[1]= caddr((V205));
	vs_top=(vs_base=base+0)+2;
	Llogbitp();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T580;}
	base[0]= small_fixnum(4);
	base[1]= caddr((V205));
	vs_top=(vs_base=base+0)+2;
	Llogbitp();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T580;}
	{register object x= cadr((V205)),V219= VV[48];
	while(!endp(V219))
	if(eql(x,V219->c.c_car)){
	goto T600;
	}else V219=V219->c.c_cdr;
	goto T598;}
T600:;
	if(!((car((V207)))==(cadr((V205))))){
	goto T580;}
T598:;
	if(((*(LnkLI86))(cadddr((V209)),car((V205))))==Cnil){
	goto T568;}
T580:;
	{object V220 = Ct;
	VMR12(V220)}}
T578:;
	if((V210!= VV[96]))goto T603;
	V221= make_cons(caddr((V209)),Cnil);
	if(((*(LnkLI86))(/* INLINE-ARGS */V221,VV[49]))==Cnil){
	goto T568;}
	{object V222 = Ct;
	VMR12(V222)}
T603:;
	{object V223 = Ct;
	VMR12(V223)}}}
T568:;
	V206= cdr((V206));
	V207= cdr((V207));
	goto T563;}}
}
/*	local entry for function WT-C-PUSH	*/

static object LI13()

{	 VMB13 VMS13 VMV13
TTL:;
	if((symbol_value(VV[9]))==Cnil){
	goto T611;}
	vs_base=vs_top;
	(void) (*Lnk77)();
	vs_top=sup;
	{object V224;
	setq(VV[4],number_plus(symbol_value(VV[4]),small_fixnum(1)));
	V224= symbol_value(VV[4]);
	princ_char(123,VV[5]);
	(void)((*(LnkLI75))(symbol_value(VV[50])));
	princ_str("object V",VV[5]);
	(void)((*(LnkLI75))((V224)));
	princ_char(59,VV[5]);
	{object V225 = list(2,VV[6],(V224));
	VMR13(V225)}}
T611:;
	{object V226 = list(2,VV[12],(*(LnkLI94))());
	VMR13(V226)}
}
/*	local entry for function CLOSE-INLINE-BLOCKS	*/

static object LI14()

{	 VMB14 VMS14 VMV14
TTL:;
	{register object V227;
	V227= symbol_value(VV[2]);
	if(!(type_of((V227))==t_cons)){
	goto T623;}
	if(!(eql(cdr((V227)),VV[51]))){
	goto T626;}
	princ_str("restore_avma;",VV[5]);
T626:;
	V227= car((V227));
T623:;
	{register int V228;
	register int V229;
	V228= fix((V227));
	V229= 0;
T634:;
	if(!((V229)>=(V228))){
	goto T635;}
	{object V230 = Cnil;
	VMR14(V230)}
T635:;
	princ_char(125,VV[5]);
	V229= (V229)+1;
	goto T634;}}
}
/*	function definition for WT-INLINE-LOC	*/

static L15()
{register object *base=vs_base;
	register object *sup=base+VM15; VC15
	vs_reserve(VM15);
	{register object V231;
	object V232;
	check_arg(2);
	V231=(base[0]);
	V232=(base[1]);
	vs_top=sup;
TTL:;
	{register int V233;
	int V234;
	V233= 0;
	V234= -1;
	if(!(type_of((V231))==t_string)){
	goto T647;}
	base[2]= elt((V231),0);
	base[3]= VV[25];
	vs_top=(vs_base=base+2)+2;
	Lchar_eq();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T649;}
	V233= 1;
T657:;
	base[2]= elt((V231),V233);
	base[3]= VV[26];
	vs_top=(vs_base=base+2)+2;
	Lchar_eq();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T658;}
	V233= (V233)+(1);
	goto T649;
T658:;
	V233= (V233)+(1);
	goto T657;
T649:;
	{int V235;
	V235= length((V231));
T671:;
	if(!((V233)>=(V235))){
	goto T672;}
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T672:;
	{unsigned char V236;
	V236= char_code(elt((V231),V233));
	base[2]= code_char(V236);
	base[3]= VV[52];
	vs_top=(vs_base=base+2)+2;
	Lchar_eq();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T679;}
	{register object V237;
	register object V238;
	V237= elt((V231),(V233)+1);
	V238= small_fixnum(0);
	if(!(eql((V237),VV[53]))){
	goto T686;}
	if(!((V234)>=(0))){
	goto T688;}
	V239 = make_fixnum(V234);
	V240= one_plus(V239);
	V241 = make_fixnum(length((V232)));
	if(!(number_compare(/* INLINE-ARGS */V240,V241)<0)){
	goto T688;}
	princ_char(44,VV[5]);
T688:;
	{register object V242;
	V243 = make_fixnum(V234);
	V244= one_plus(V243);
	V242= nthcdr(fixint(/* INLINE-ARGS */V244),(V232));
T696:;
	if(((V242))!=Cnil){
	goto T697;}
	goto T683;
T697:;
	base[2]= car((V242));
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk87)();
	vs_top=sup;
	if((cdr((V242)))==Cnil){
	goto T703;}
	princ_char(44,VV[5]);
T703:;
	V242= cdr((V242));
	goto T696;}
T686:;
	base[2]= (V237);
	base[3]= small_fixnum(10);
	vs_top=(vs_base=base+2)+2;
	Ldigit_char_p();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T683;}
	{ save_avma;
	base[2]= (V237);
	vs_top=(vs_base=base+2)+1;
	Lchar_code();
	vs_top=sup;
	V245= vs_base[0];
	V246 = stoi((48));
	V238= make_integer(subii(otoi(V245),V246));restore_avma;}
	{ save_avma;
	V247 = stoi(length((V231)));
	V248 = stoi(V233);
	{GEN V249= addii(V248,stoi(2));
	if(!(cmpii(V247,/* INLINE-ARGS */V249)>0)){
	restore_avma; 
	goto T718;}
	restore_avma; restore_avma;}}
	{ save_avma;
	V250 = stoi(V233);
	V251= make_integer(addii(V250,stoi(2)));
	V237= elt((V231),fixint(/* INLINE-ARGS */V251));restore_avma;}
	if(((V237))==Cnil){
	goto T718;}
	base[2]= (V237);
	vs_top=(vs_base=base+2)+1;
	Ldigit_char_p();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T718;}
	V252= number_times((V238),small_fixnum(10));
	{ save_avma;
	base[2]= (V237);
	vs_top=(vs_base=base+2)+1;
	Lchar_code();
	vs_top=sup;
	V253= vs_base[0];
	V254 = stoi((48));
	V255= make_integer(subii(otoi(V253),V254));
	V238= number_plus(/* INLINE-ARGS */V252,/* INLINE-ARGS */V255);restore_avma;}
	V233= (V233)+(1);
T718:;
	V256 = make_fixnum(V234);
	if(!(number_compare((V238),V256)>=0)){
	goto T732;}
	V234= fix((V238));
T732:;
	base[2]= nth(fixint((V238)),(V232));
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk87)();
	vs_top=sup;}
T683:;
	V233= (V233)+(2);
	goto T676;
T679:;
	(void)(princ(code_char(V236),symbol_value(VV[5])));
	V233= (V233)+(1);}
T676:;
	goto T671;}
T647:;
	base[2]= (V231);
	{object V257;
	V257= (V232);
	 vs_top=base+3;
	 while(!endp(V257))
	 {vs_push(car(V257));V257=cdr(V257);}
	vs_base=base+3;}
	super_funcall_no_event(base[2]);
	return;}
	}
}
/*	function definition for WT-INLINE	*/

static L16()
{register object *base=vs_base;
	register object *sup=base+VM16; VC16
	vs_reserve(VM16);
	{object V258;
	object V259;
	object V260;
	check_arg(3);
	V258=(base[0]);
	V259=(base[1]);
	V260=(base[2]);
	vs_top=sup;
TTL:;
	base[3]= (V259);
	base[4]= (V260);
	vs_top=(vs_base=base+3)+2;
	(void) (*Lnk107)();
	return;
	}
}
/*	local entry for function WT-INLINE-COND	*/

static object LI17(V264,V265,V266)

object V264;object V265;object V266;
{	 VMB17 VMS17 VMV17
TTL:;
	princ_char(40,VV[5]);
	base[0]= (V265);
	base[1]= (V266);
	vs_top=(vs_base=base+0)+2;
	(void) (*Lnk107)();
	vs_top=sup;
	princ_str("?Ct:Cnil)",VV[5]);
	{object V267 = Cnil;
	VMR17(V267)}
}
/*	local entry for function WT-INLINE-FIXNUM	*/

static object LI18(V271,V272,V273)

object V271;object V272;object V273;
{	 VMB18 VMS18 VMV18
TTL:;
	if(!(number_compare(small_fixnum(0),symbol_value(VV[55]))==0)){
	goto T752;}
	princ_str("CMP",VV[5]);
T752:;
	princ_str("make_fixnum(",VV[5]);
	base[0]= (V272);
	base[1]= (V273);
	vs_top=(vs_base=base+0)+2;
	(void) (*Lnk107)();
	vs_top=sup;
	princ_char(41,VV[5]);
	{object V274 = Cnil;
	VMR18(V274)}
}
/*	function definition for WT-INLINE-INTEGER	*/

static L19()
{register object *base=vs_base;
	register object *sup=base+VM19; VC19
	vs_reserve(VM19);
	{object V275;
	object V276;
	object V277;
	check_arg(3);
	V275=(base[0]);
	V276=(base[1]);
	V277=(base[2]);
	vs_top=sup;
TTL:;
	princ_str("make_integer(",VV[5]);
	base[3]= (V276);
	base[4]= (V277);
	vs_top=(vs_base=base+3)+2;
	(void) (*Lnk107)();
	vs_top=sup;
	princ_char(41,VV[5]);
	base[3]= Cnil;
	vs_top=(vs_base=base+3)+1;
	return;
	}
}
/*	local entry for function WT-INLINE-CHARACTER	*/

static object LI20(V281,V282,V283)

object V281;object V282;object V283;
{	 VMB20 VMS20 VMV20
TTL:;
	princ_str("code_char(",VV[5]);
	base[0]= (V282);
	base[1]= (V283);
	vs_top=(vs_base=base+0)+2;
	(void) (*Lnk107)();
	vs_top=sup;
	princ_char(41,VV[5]);
	{object V284 = Cnil;
	VMR20(V284)}
}
/*	local entry for function WT-INLINE-LONG-FLOAT	*/

static object LI21(V288,V289,V290)

object V288;object V289;object V290;
{	 VMB21 VMS21 VMV21
TTL:;
	princ_str("make_longfloat(",VV[5]);
	base[0]= (V289);
	base[1]= (V290);
	vs_top=(vs_base=base+0)+2;
	(void) (*Lnk107)();
	vs_top=sup;
	princ_char(41,VV[5]);
	{object V291 = Cnil;
	VMR21(V291)}
}
/*	local entry for function WT-INLINE-SHORT-FLOAT	*/

static object LI22(V295,V296,V297)

object V295;object V296;object V297;
{	 VMB22 VMS22 VMV22
TTL:;
	princ_str("make_shortfloat(",VV[5]);
	base[0]= (V296);
	base[1]= (V297);
	vs_top=(vs_base=base+0)+2;
	(void) (*Lnk107)();
	vs_top=sup;
	princ_char(41,VV[5]);
	{object V298 = Cnil;
	VMR22(V298)}
}
/*	local entry for function ARGS-CAUSE-SIDE-EFFECT	*/

static object LI23(V300)

object V300;
{	 VMB23 VMS23 VMV23
TTL:;
	{register object V301;
	V301= Cnil;
	{register object V302;
	register object V303;
	V302= (V300);
	V303= car((V302));
T790:;
	if(!(endp((V302)))){
	goto T791;}
	{object V304 = Cnil;
	VMR23(V304)}
T791:;
	{object V305= car((V303));
	if((V305!= VV[14])
	&& (V305!= VV[1])
	&& (V305!= VV[96]))goto T796;
	goto T795;
T796:;
	if((V305!= VV[81]))goto T797;
	{register object V306;
	V306= caddr((V303));
	if(((*(LnkLI82))((V306)))==Cnil){
	goto T799;}
	V307= cadddr((V303));
	V308= structure_ref(cadr((V303)),VV[0],2);
	V301= (*(LnkLI83))((V306),/* INLINE-ARGS */V307,/* INLINE-ARGS */V308);
	if(((V301))==Cnil){
	goto T799;}
	base[1]= (V301);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk105)();
	vs_top=sup;
	base[1]= small_fixnum(1);
	base[2]= caddr((V301));
	vs_top=(vs_base=base+1)+2;
	Llogbitp();
	vs_top=sup;
	V309= vs_base[0];
	if((V309)==Cnil){
	goto T795;}
T799:;
	{object V310 = Ct;
	VMR23(V310)}}
T797:;
	{object V311 = Ct;
	VMR23(V311)}}
T795:;
	V302= cdr((V302));
	V303= car((V302));
	goto T790;}}
}
/*	local entry for function LIST-INLINE	*/

static object LI24(va_alist)
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB24 VMS24 VMV24
	{object V312;
	narg= narg - 0;
	va_start(ap);
	V313 = list_vector(narg,ap);
	V312= V313;
	{object V314;
	object V315;
	V314= Cnil;
	V315= make_fixnum(length((V312)));
	if(type_of(symbol_value(VV[13]))==t_cons){
	goto T823;}
	V314= Cnil;
	goto T822;
T823:;
	if((car(symbol_value(VV[13])))==(VV[1])){
	goto T825;}
	V314= Cnil;
	goto T822;
T825:;
	V316= structure_ref(cadr(symbol_value(VV[13])),VV[1],5);
	V314= ((/* INLINE-ARGS */V316)==(VV[56])?Ct:Cnil);
T822:;
	if(((V314))==Cnil){
	goto T820;}
	princ_str("(ALLOCA_CONS(",VV[5]);
	(void)((*(LnkLI75))((V315)));
	princ_str("),ON_STACK_LIST(",VV[5]);
	(void)((*(LnkLI75))((V315)));
	goto T818;
T820:;
	princ_str("list(",VV[5]);
	V317 = make_fixnum(length((V312)));
	(void)((*(LnkLI75))(V317));
T818:;
	{register object V318;
	register object V319;
	V318= (V312);
	V319= car((V318));
T837:;
	if(!(endp((V318)))){
	goto T838;}
	goto T833;
T838:;
	(void)((*(LnkLI75))(VV[57]));
	(void)((*(LnkLI75))((V319)));
	V318= cdr((V318));
	V319= car((V318));
	goto T837;}
T833:;
	(void)((*(LnkLI75))(VV[58]));
	if(((V314))==Cnil){
	goto T853;}
	(void)((*(LnkLI75))(VV[58]));
	{object V320 = Cnil;
	VMR24(V320)}
T853:;
	{object V321 = Cnil;
	VMR24(V321)}}}
	}
/*	local entry for function LIST*-INLINE	*/

static object LI25(va_alist)
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB25 VMS25 VMV25
	{register object V322;
	narg= narg - 0;
	va_start(ap);
	V323 = list_vector(narg,ap);
	V322= V323;switch(length((V322))){
	case 1:
T857:;
	(void)((*(LnkLI75))(car((V322))));
	{object V324 = Cnil;
	VMR25(V324)}
	case 2:
T858:;
	princ_str("make_cons(",VV[5]);
	(void)((*(LnkLI75))(car((V322))));
	princ_char(44,VV[5]);
	(void)((*(LnkLI75))(cadr((V322))));
	princ_char(41,VV[5]);
	{object V325 = Cnil;
	VMR25(V325)}
	default:
T859:;
	princ_str("listA(",VV[5]);
	V326 = make_fixnum(length((V322)));
	(void)((*(LnkLI75))(V326));
	{register object V327;
	register object V328;
	V327= (V322);
	V328= car((V327));
T874:;
	if(!(endp((V327)))){
	goto T875;}
	goto T870;
T875:;
	(void)((*(LnkLI75))(VV[57]));
	(void)((*(LnkLI75))((V328)));
	V327= cdr((V327));
	V328= car((V327));
	goto T874;}
T870:;
	(void)((*(LnkLI75))(VV[58]));
	{object V329 = Cnil;
	VMR25(V329)}
	{object V330 = Cnil;
	VMR25(V330)}}
	{object V331 = Cnil;
	VMR25(V331)}}
	}
/*	local entry for function DEFSYSFUN	*/

static object LI26(V338,V339,V340,V341,V342,V343)

register object V338;object V339;object V340;register object V341;object V342;object V343;
{	 VMB26 VMS26 VMV26
TTL:;
	if(((V339))==Cnil){
	goto T888;}
	(void)(putprop((V338),(V339),VV[59]));
T888:;
	if(((V340))==Cnil){
	goto T891;}
	{object V345;
	object V346= (V340);
	if(endp(V346)){
	V344= Cnil;
	goto T894;}
	base[0]=V345=MMcons(Cnil,Cnil);
T895:;
	if(!(((V346->c.c_car))==(VV[60]))){
	goto T898;}
	(V345->c.c_car)= VV[60];
	goto T896;
T898:;
	(V345->c.c_car)= (*(LnkLI108))((V346->c.c_car));
T896:;
	if(endp(V346=MMcdr(V346))){
	V344= base[0];
	goto T894;}
	V345=MMcdr(V345)=MMcons(Cnil,Cnil);
	goto T895;}
T894:;
	(void)(putprop((V338),V344,VV[61]));
T891:;
	if(((V341))==Cnil){
	goto T900;}
	{register object V348;
	if(!(type_of((V341))!=t_cons)){
	goto T906;}
	V349= make_cons((V341),Cnil);
	goto T904;
T906:;
	V349= (V341);
T904:;
	V348= (*(LnkLI109))(V349);
	if(!(type_of((V348))==t_cons)){
	goto T909;}
	goto T908;
T909:;
	V348= make_cons((V348),Cnil);
T908:;
	if((cdr((V348)))!=Cnil){
	goto T914;}
	V350= car((V348));
	goto T912;
T914:;
	V350= make_cons(VV[62],(V348));
T912:;
	(void)(putprop((V338),V350,VV[63]));}
T900:;
	if(((V342))==Cnil){
	goto T916;}
	(void)(putprop((V338),Ct,VV[64]));
T916:;
	if(((V343))==Cnil){
	goto T920;}
	{object V351 = putprop((V338),Ct,VV[65]);
	VMR26(V351)}
T920:;
	{object V352 = Cnil;
	VMR26(V352)}
}
/*	local function CLOSURE	*/

static LC27(base0)
register object *base0;
{	register object *base=vs_base;
	register object *sup=base+VM27; VC27
	vs_reserve(VM27);
	{object V353;
	vs_top[0]=Cnil;
	{object *p=vs_top;
	 for(;p>vs_base;p--)p[-1]=MMcons(p[-1],p[0]);}
	V353=(base[0]);
	vs_top=sup;
	princ_str("(VFUN_NARGS=",VV[5]);
	V354 = make_fixnum(length((V353)));
	(void)((*(LnkLI75))(V354));
	princ_char(44,VV[5]);
	base[1]= (base0[0]->c.c_car);
	base[2]= (V353);
	vs_top=(vs_base=base+1)+2;
	(void) (*Lnk107)();
	vs_top=sup;
	princ_char(41,VV[5]);
	base[1]= Cnil;
	vs_top=(vs_base=base+1)+1;
	return;
	}
}
static object  LnkTLI109(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[109],&LnkLI109,1,ap);} /* FUNCTION-RETURN-TYPE */
static object  LnkTLI108(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[108],&LnkLI108,1,ap);} /* TYPE-FILTER */
static LnkT107(){ call_or_link(VV[107],&Lnk107);} /* WT-INLINE-LOC */
static object  LnkTLI106(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[106],&LnkLI106,2,ap);} /* TYPE>= */
static LnkT105(){ call_or_link(VV[105],&Lnk105);} /* FIX-OPT */
static object  LnkTLI104(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[104],&LnkLI104,3,ap);} /* INLINE-TYPE-MATCHES */
static object  LnkTLI103(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[103],&LnkLI103,3,ap);} /* ADD-FAST-LINK */
static object  LnkTLI102(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[102],&LnkLI102,ap);} /* FAST-LINK-PROCLAIMED-TYPE-P */
static object  LnkTLI101(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[101],&LnkLI101,1,ap);} /* INLINE-TYPE */
static object  LnkTLI100(){return call_proc0(VV[100],&LnkLI100);} /* BABOON */
static object  LnkTLI7(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[7],&LnkLI7,ap);} /* INLINE-ARGS */
static object  LnkTLI99(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[99],&LnkLI99,ap);} /* MAKE-VAR */
static object  LnkTLI97(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[97],&LnkLI97,2,ap);} /* COERCE-LOC-STRUCTURE-REF */
static object  LnkTLI95(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[95],&LnkLI95,1,ap);} /* C2EXPR* */
static object  LnkTLI94(){return call_proc0(VV[94],&LnkLI94);} /* VS-PUSH */
static LnkT93(){ call_or_link(VV[93],&Lnk93);} /* WT-SHORT-FLOAT-LOC */
static LnkT92(){ call_or_link(VV[92],&Lnk92);} /* WT-LONG-FLOAT-LOC */
static LnkT91(){ call_or_link(VV[91],&Lnk91);} /* WT-CHARACTER-LOC */
static LnkT90(){ call_or_link(VV[90],&Lnk90);} /* WT-INTEGER-LOC */
static LnkT88(){ call_or_link(VV[88],&Lnk88);} /* WT-FIXNUM-LOC */
static LnkT87(){ call_or_link(VV[87],&Lnk87);} /* WT-LOC */
static object  LnkTLI86(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[86],&LnkLI86,2,ap);} /* NEED-TO-PROTECT */
static object  LnkTLI85(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[85],&LnkLI85,2,ap);} /* GET-INLINE-LOC */
static LnkT84(){ call_or_link(VV[84],&Lnk84);} /* SAVE-AVMA */
static object  LnkTLI83(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[83],&LnkLI83,3,ap);} /* GET-INLINE-INFO */
static object  LnkTLI82(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[82],&LnkLI82,1,ap);} /* INLINE-POSSIBLE */
static object  LnkTLI80(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[80],&LnkLI80,ap);} /* CS-PUSH */
static object  LnkTLI79(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[79],&LnkLI79,2,ap);} /* WT-VAR */
static object  LnkTLI78(){return call_proc0(VV[78],&LnkLI78);} /* WT-C-PUSH */
static LnkT77(){ call_or_link(VV[77],&Lnk77);} /* INC-INLINE-BLOCKS */
static object  LnkTLI76(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[76],&LnkLI76,1,ap);} /* REP-TYPE */
static object  LnkTLI75(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[75],&LnkLI75,1,ap);} /* WT1 */
static object  LnkTLI74(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[74],&LnkLI74,2,ap);} /* ARGS-INFO-CHANGED-VARS */
static object  LnkTLI73(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[73],&LnkLI73,2,ap);} /* COERCE-LOC */
