
#include <cmpinclude.h>
#include "cmpfun.h"
init_cmpfun(){do_init(VV);}
/*	local entry for function C1PRINC	*/

static object LI1(V2)

register object V2;
{	 VMB1 VMS1 VMV1
TTL:;
	{register object V3;
	register object V4;
	V3= Cnil;
	V4= (VFUN_NARGS=0,(*(LnkLI212))());
	if(!(endp((V2)))){
	goto T3;}
	(void)((*(LnkLI213))(VV[0],small_fixnum(1),small_fixnum(0)));
T3:;
	if(endp(cdr((V2)))){
	goto T6;}
	if(endp(cddr((V2)))){
	goto T6;}
	V5 = make_fixnum(length((V2)));
	(void)((*(LnkLI214))(VV[0],small_fixnum(2),V5));
T6:;
	if(!(endp(cdr((V2))))){
	goto T14;}
	V3= (*(LnkLI215))();
	goto T12;
T14:;
	V3= (*(LnkLI216))(cadr((V2)),(V4));
T12:;
	if(!(type_of(car((V2)))==t_string)){
	goto T19;}
	V6 = make_fixnum(length(car((V2))));
	if(number_compare(V6,symbol_value(VV[1]))<=0){
	goto T18;}
T19:;
	if(!(type_of(car((V2)))==t_character)){
	goto T17;}
T18:;
	if(endp(cdr((V2)))){
	goto T16;}
	if(!((car((V3)))==(VV[2]))){
	goto T17;}
	V8= structure_ref(caaddr((V3)),VV[2],1);
	{register object x= /* INLINE-ARGS */V8,V7= VV[3];
	while(!endp(V7))
	if(eql(x,V7->c.c_car)){
	goto T28;
	}else V7=V7->c.c_cdr;
	goto T17;}
T28:;
T16:;
	V9= car((V2));
	if(!(endp(cdr((V2))))){
	goto T31;}
	V10= Cnil;
	goto T29;
T31:;
	V10= structure_ref(caaddr((V3)),VV[2],4);
T29:;
	{object V11 = list(5,VV[0],(V4),/* INLINE-ARGS */V9,V10,(V3));
	VMR1(V11)}
T17:;
	V12= (*(LnkLI216))(car((V2)),(V4));
	{object V13 = list(4,VV[4],(V4),VV[0],list(2,/* INLINE-ARGS */V12,(V3)));
	VMR1(V13)}}
}
/*	local entry for function C2PRINC	*/

static object LI2(V17,V18,V19)

register object V17;register object V18;object V19;
{	 VMB2 VMS2 VMV2
TTL:;
	if(!((symbol_value(VV[5]))==(VV[6]))){
	goto T34;}
	if(!(type_of((V17))==t_character)){
	goto T38;}
	princ_str("\n	princ_char(",VV[7]);
	base[0]= (V17);
	vs_top=(vs_base=base+0)+1;
	Lchar_code();
	vs_top=sup;
	V20= vs_base[0];
	(void)((*(LnkLI217))(V20));
	if(((V18))!=Cnil){
	goto T47;}
	princ_str(",Cnil",VV[7]);
	goto T45;
T47:;
	princ_str(",VV[",VV[7]);
	(void)((*(LnkLI217))((V18)));
	princ_char(93,VV[7]);
T45:;
	princ_str(");",VV[7]);
	goto T36;
T38:;
	if(!((length((V17)))==(1))){
	goto T55;}
	princ_str("\n	princ_char(",VV[7]);
	base[0]= aref1((V17),0);
	vs_top=(vs_base=base+0)+1;
	Lchar_code();
	vs_top=sup;
	V21= vs_base[0];
	(void)((*(LnkLI217))(V21));
	if(((V18))!=Cnil){
	goto T64;}
	princ_str(",Cnil",VV[7]);
	goto T62;
T64:;
	princ_str(",VV[",VV[7]);
	(void)((*(LnkLI217))((V18)));
	princ_char(93,VV[7]);
T62:;
	princ_str(");",VV[7]);
	goto T36;
T55:;
	princ_str("\n	princ_str(\"",VV[7]);
	{register int V22;
	register int V23;
	V22= length((V17));
	V23= 0;
T77:;
	if(!((V23)>=(V22))){
	goto T78;}
	goto T73;
T78:;
	{register object V24;
	V24= elt((V17),V23);
	base[0]= (V24);
	base[1]= VV[8];
	vs_top=(vs_base=base+0)+2;
	Lchar_eq();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T85;}
	princ_str("\\\\",VV[7]);
	goto T82;
T85:;
	base[0]= (V24);
	base[1]= VV[9];
	vs_top=(vs_base=base+0)+2;
	Lchar_eq();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T91;}
	princ_str("\\\"",VV[7]);
	goto T82;
T91:;
	base[0]= (V24);
	base[1]= VV[10];
	vs_top=(vs_base=base+0)+2;
	Lchar_eq();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T97;}
	princ_str("\\n",VV[7]);
	goto T82;
T97:;
	(void)((*(LnkLI217))((V24)));}
T82:;
	V23= (V23)+1;
	goto T77;}
T73:;
	princ_str("\",",VV[7]);
	if(((V18))!=Cnil){
	goto T110;}
	princ_str("Cnil",VV[7]);
	goto T108;
T110:;
	princ_str("VV[",VV[7]);
	(void)((*(LnkLI217))((V18)));
	princ_char(93,VV[7]);
T108:;
	princ_str(");",VV[7]);
T36:;
	{object V25 = (VFUN_NARGS=1,(*(LnkLI218))(Cnil));
	VMR2(V25)}
T34:;
	if(!(eql((V17),VV[10]))){
	goto T118;}
	V26= make_cons((V19),Cnil);
	{object V27 = (*(LnkLI219))(VV[11],/* INLINE-ARGS */V26,Cnil,Ct);
	VMR2(V27)}
T118:;
	if(!(type_of((V17))==t_character)){
	goto T122;}
	V28= VV[14];
	goto T120;
T122:;
	V28= VV[15];
T120:;
	V29= (VFUN_NARGS=2,(*(LnkLI212))(VV[13],V28));
	V30= list(2,list(3,VV[12],/* INLINE-ARGS */V29,list(2,VV[16],(*(LnkLI220))((V17)))),(V19));
	{object V31 = (*(LnkLI219))(VV[0],/* INLINE-ARGS */V30,Cnil,Ct);
	VMR2(V31)}
}
/*	local entry for function C1TERPRI	*/

static object LI3(V33)

register object V33;
{	 VMB3 VMS3 VMV3
TTL:;
	{register object V34;
	object V35;
	V34= Cnil;
	V35= (VFUN_NARGS=0,(*(LnkLI212))());
	if(endp((V33))){
	goto T126;}
	if(endp(cdr((V33)))){
	goto T126;}
	V36 = make_fixnum(length((V33)));
	(void)((*(LnkLI214))(VV[11],small_fixnum(1),V36));
T126:;
	if(!(endp((V33)))){
	goto T134;}
	V34= (*(LnkLI215))();
	goto T132;
T134:;
	V34= (*(LnkLI216))(car((V33)),(V35));
T132:;
	if(endp((V33))){
	goto T136;}
	if(!((car((V34)))==(VV[2]))){
	goto T137;}
	V38= structure_ref(caaddr((V34)),VV[2],1);
	{register object x= /* INLINE-ARGS */V38,V37= VV[17];
	while(!endp(V37))
	if(eql(x,V37->c.c_car)){
	goto T142;
	}else V37=V37->c.c_cdr;
	goto T137;}
T142:;
T136:;
	if(!(endp((V33)))){
	goto T145;}
	V39= Cnil;
	goto T143;
T145:;
	V39= structure_ref(caaddr((V34)),VV[2],4);
T143:;
	{object V40 = list(5,VV[0],(V35),VV[10],V39,(V34));
	VMR3(V40)}
T137:;
	{object V41 = list(4,VV[4],(V35),VV[11],make_cons((V34),Cnil));
	VMR3(V41)}}
}
/*	local entry for function C1APPLY	*/

static object LI4(V43)

register object V43;
{	 VMB4 VMS4 VMV4
TTL:;
	{register object V44;
	V44= Cnil;
	if(endp((V43))){
	goto T149;}
	if(!(endp(cdr((V43))))){
	goto T148;}
T149:;
	V45 = make_fixnum(length((V43)));
	(void)((*(LnkLI213))(VV[18],small_fixnum(2),V45));
T148:;
	{register object V46;
	V46= (*(LnkLI221))(car((V43)));
	base[0]= cadr((V46));
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk222)();
	vs_top=sup;
	V44= vs_base[0];
	V43= (*(LnkLI223))(cdr((V43)),(V44));
	if(!((car((V46)))==(VV[19]))){
	goto T160;}
	{object V47;
	register object V48;
	V47= caddr((V46));
	V48= caddr((V47));
	if((cadr((V48)))!=Cnil){
	goto T165;}
	if((cadddr((V48)))!=Cnil){
	goto T165;}
	{object V49 = (*(LnkLI224))((V44),car((V48)),caddr((V48)),car(cddddr((V47))),(V43));
	VMR4(V49)}
T165:;
	{object V50 = list(4,VV[18],(V44),(V46),(V43));
	VMR4(V50)}}
T160:;
	{object V51 = list(4,VV[18],(V44),(V46),(V43));
	VMR4(V51)}}}
}
/*	local entry for function C2APPLY	*/

static object LI5(V54,V55)

object V54;object V55;
{	 VMB5 VMS5 VMV5
	bds_check;
TTL:;
	{object V56;
	bds_bind(VV[20],symbol_value(VV[20]));
	V56= Cnil;
	V56= (*(LnkLI225))((V54));
	{object V57;
	register object V58;
	base[1]= (VV[20]->s.s_dbind);
	V57= (VV[20]->s.s_dbind);
	setq(VV[22],number_plus(symbol_value(VV[22]),small_fixnum(1)));
	V58= list(2,VV[21],symbol_value(VV[22]));
	bds_bind(VV[20],base[1]);
	{register object V59;
	V59= (V55);
T179:;
	if(!(endp(cdr((V59))))){
	goto T180;}
	princ_str("\n	{object ",VV[7]);
	(void)((*(LnkLI217))((V58)));
	princ_char(59,VV[7]);
	bds_bind(VV[5],(V58));
	V60= (*(LnkLI226))(car((V59)));
	bds_unwind1;
	goto T177;
T180:;
	base[2]= list(2,VV[23],(*(LnkLI227))());
	bds_bind(VV[5],base[2]);
	V61= (*(LnkLI226))(car((V59)));
	bds_unwind1;
	V59= cdr((V59));
	goto T179;}
T177:;
	princ_str("\n	 vs_top=base+",VV[7]);
	(void)((*(LnkLI217))((VV[20]->s.s_dbind)));
	princ_char(59,VV[7]);
	setq(VV[24],Ct);
	if((symbol_value(VV[25]))==Cnil){
	goto T201;}
	princ_str("\n	 while(!endp(",VV[7]);
	(void)((*(LnkLI217))((V58)));
	princ_str("))",VV[7]);
	princ_str("\n	 {vs_push(car(",VV[7]);
	(void)((*(LnkLI217))((V58)));
	princ_str("));",VV[7]);
	(void)((*(LnkLI217))((V58)));
	princ_str("=cdr(",VV[7]);
	(void)((*(LnkLI217))((V58)));
	princ_str(");}",VV[7]);
	goto T199;
T201:;
	princ_str("\n	 while(",VV[7]);
	(void)((*(LnkLI217))((V58)));
	princ_str("!=Cnil)",VV[7]);
	princ_str("\n	 {vs_push((",VV[7]);
	(void)((*(LnkLI217))((V58)));
	princ_str(")->c.c_car);",VV[7]);
	(void)((*(LnkLI217))((V58)));
	princ_str("=(",VV[7]);
	(void)((*(LnkLI217))((V58)));
	princ_str(")->c.c_cdr;}",VV[7]);
T199:;
	princ_str("\n	vs_base=base+",VV[7]);
	(void)((*(LnkLI217))((V57)));
	princ_str(";}",VV[7]);
	setq(VV[24],Ct);
	bds_unwind1;}
	{object V62 = (VFUN_NARGS=3,(*(LnkLI228))((V54),VV[26],(V56)));
	bds_unwind1;
	VMR5(V62)}}
}
/*	local entry for function C1APPLY-OPTIMIZE	*/

static object LI6(V68,V69,V70,V71,V72)

object V68;register object V69;object V70;object V71;register object V72;
{	 VMB6 VMS6 VMV6
TTL:;
	{register object V73;
	register object V74;
	V73= Cnil;
	V74= Cnil;
T236:;
	if(endp(cdr((V72)))){
	goto T238;}
	if(!(endp((V69)))){
	goto T237;}
T238:;
	goto T234;
T237:;
	{register object V76;
	V76= car((V69));
	V69= cdr((V69));
	V75= (V76);}
	V73= make_cons(V75,(V73));
	{register object V78;
	V78= car((V72));
	V72= cdr((V72));
	V77= (V78);}
	V74= make_cons(V77,(V74));
	goto T236;
T234:;
	if((cdr((V72)))==Cnil){
	goto T258;}
	if(((V70))!=Cnil){
	goto T260;}
	(void)((VFUN_NARGS=1,(*(LnkLI229))(VV[27])));
T260:;
	V73= make_cons((V70),(V73));
	V79= list(4,VV[4],(V68),VV[28],(V72));
	V74= make_cons(/* INLINE-ARGS */V79,(V74));
	V80= reverse((V73));
	{object V81 = list(5,VV[29],(V68),/* INLINE-ARGS */V80,reverse((V74)),(V71));
	VMR6(V81)}
T258:;
	if(((V69))==Cnil){
	goto T268;}
	{object V82;
	V82= (VFUN_NARGS=4,(*(LnkLI230))(VV[30],VV[31],VV[32],Ct));
	V73= make_cons((V82),(V73));
	V74= make_cons(car((V72)),(V74));
	V83= reverse((V73));
	V84= reverse((V74));
	{object V85 = list(5,VV[29],(V68),/* INLINE-ARGS */V83,/* INLINE-ARGS */V84,list(6,VV[33],cadr((V71)),(V82),(V69),(V70),(V71)));
	VMR6(V85)}}
T268:;
	if(((V70))==Cnil){
	goto T276;}
	V73= make_cons((V70),(V73));
	V74= make_cons(car((V72)),(V74));
	V86= reverse((V73));
	{object V87 = list(5,VV[29],(V68),/* INLINE-ARGS */V86,reverse((V74)),(V71));
	VMR6(V87)}
T276:;
	{object V88;
	V88= (VFUN_NARGS=4,(*(LnkLI230))(VV[30],VV[31],VV[32],Ct));
	V73= make_cons((V88),(V73));
	V74= make_cons(car((V72)),(V74));
	V89= reverse((V73));
	V90= reverse((V74));
	{object V91 = list(5,VV[29],(V68),/* INLINE-ARGS */V89,/* INLINE-ARGS */V90,list(6,VV[33],cadr((V71)),(V88),(V69),(V70),(V71)));
	VMR6(V91)}}}
}
/*	function definition for C2APPLY-OPTIMIZE	*/

static L7()
{register object *base=vs_base;
	register object *sup=base+VM7; VC7
	vs_reserve(VM7);
	bds_check;
	{object V92;
	object V93;
	object V94;
	object V95;
	check_arg(4);
	V92=(base[0]);
	V93=(base[1]);
	V94=(base[2]);
	V95=(base[3]);
	vs_top=sup;
TTL:;
	bds_bind(VV[34],symbol_value(VV[34]));
	bds_bind(VV[20],symbol_value(VV[20]));
	bds_bind(VV[35],symbol_value(VV[35]));
	bds_bind(VV[36],symbol_value(VV[36]));
	if((symbol_value(VV[25]))!=Cnil){
	goto T288;}
	if((symbol_value(VV[37]))==Cnil){
	goto T287;}
T288:;
	princ_str("\n	",VV[7]);
	if(((V94))==Cnil){
	goto T297;}
	V96= VV[38];
	goto T295;
T297:;
	V96= VV[39];
T295:;
	(void)((*(LnkLI217))(V96));
	princ_char(40,VV[7]);
	V97 = make_fixnum(length((V93)));
	(void)((*(LnkLI217))(V97));
	princ_char(44,VV[7]);
	(void)((*(LnkLI231))((V92),Cnil));
	princ_str(");",VV[7]);
T287:;
	{object V98;
	object V99;
	V98= (V93);
	V99= car((V98));
T308:;
	if(!(endp((V98)))){
	goto T309;}
	goto T304;
T309:;
	V100= (*(LnkLI227))();
	(void)(structure_set((V99),VV[2],2,/* INLINE-ARGS */V100));
	V98= cdr((V98));
	V99= car((V98));
	goto T308;}
T304:;
	if(((V94))==Cnil){
	goto T319;}
	V101= (*(LnkLI227))();
	(void)(structure_set((V94),VV[2],2,/* INLINE-ARGS */V101));
T319:;
	{register int V102;
	object V103;
	V102= 0;
	V103= (V93);
T325:;
	if(!(endp((V103)))){
	goto T326;}
	if(((V94))==Cnil){
	goto T322;}
	princ_str("\n	",VV[7]);
	V104= structure_ref((V94),VV[2],2);
	(void)((*(LnkLI232))(/* INLINE-ARGS */V104));
	princ_str("= ",VV[7]);
	{int V105;
	register int V106;
	V105= V102;
	V106= 0;
T339:;
	if(!((V106)>=(V105))){
	goto T340;}
	goto T335;
T340:;
	princ_char(40,VV[7]);
	V106= (V106)+1;
	goto T339;}
T335:;
	(void)((*(LnkLI231))((V92),Cnil));
	{int V107;
	register int V108;
	V107= V102;
	V108= 0;
T354:;
	if(!((V108)>=(V107))){
	goto T355;}
	goto T350;
T355:;
	princ_str("\n	)->c.c_cdr",VV[7]);
	V108= (V108)+1;
	goto T354;}
T350:;
	princ_char(59,VV[7]);
	goto T322;
T326:;
	princ_str("\n	",VV[7]);
	V109= structure_ref(car((V103)),VV[2],2);
	(void)((*(LnkLI232))(/* INLINE-ARGS */V109));
	princ_str("=(",VV[7]);
	{int V110;
	register int V111;
	V110= V102;
	V111= 0;
T374:;
	if(!((V111)>=(V110))){
	goto T375;}
	goto T370;
T375:;
	princ_char(40,VV[7]);
	V111= (V111)+1;
	goto T374;}
T370:;
	(void)((*(LnkLI231))((V92),Cnil));
	{int V112;
	register int V113;
	V112= V102;
	V113= 0;
T389:;
	if(!((V113)>=(V112))){
	goto T390;}
	goto T385;
T390:;
	princ_str("\n	)->c.c_cdr",VV[7]);
	V113= (V113)+1;
	goto T389;}
T385:;
	princ_str(")->c.c_car;",VV[7]);
	V102= (V102)+1;
	V103= cdr((V103));
	goto T325;}
T322:;
	{object V114;
	object V115;
	V114= (V93);
	V115= car((V114));
T409:;
	if(!(endp((V114)))){
	goto T410;}
	goto T405;
T410:;
	(void)((*(LnkLI233))((V115)));
	V114= cdr((V114));
	V115= car((V114));
	goto T409;}
T405:;
	if(((V94))==Cnil){
	goto T420;}
	(void)((*(LnkLI233))((V94)));
T420:;
	base[8]= (V95);
	vs_top=(vs_base=base+8)+1;
	(void) (*Lnk234)();
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	return;
	}
}
/*	local entry for function C1FUNCALL	*/

static object LI8(V117)

object V117;
{	 VMB8 VMS8 VMV8
TTL:;
	{object V118;
	object V119;
	V118= Cnil;
	V119= (VFUN_NARGS=0,(*(LnkLI212))());
	if(!(endp((V117)))){
	goto T426;}
	(void)((*(LnkLI213))(VV[40],small_fixnum(1),small_fixnum(0)));
T426:;
	V118= (*(LnkLI221))(car((V117)));
	(void)((*(LnkLI235))((V119),cadr((V118))));
	{object V120 = list(4,VV[40],(V119),(V118),(*(LnkLI223))(cdr((V117)),(V119)));
	VMR8(V120)}}
}
/*	local entry for function C1RPLACA	*/

static object LI9(V122)

register object V122;
{	 VMB9 VMS9 VMV9
TTL:;
	{object V123;
	V123= (VFUN_NARGS=0,(*(LnkLI212))());
	if(endp((V122))){
	goto T434;}
	if(!(endp(cdr((V122))))){
	goto T433;}
T434:;
	V124 = make_fixnum(length((V122)));
	(void)((*(LnkLI213))(VV[41],small_fixnum(2),V124));
T433:;
	if(endp(cddr((V122)))){
	goto T438;}
	V125 = make_fixnum(length((V122)));
	(void)((*(LnkLI214))(VV[41],small_fixnum(2),V125));
T438:;
	V122= (*(LnkLI223))((V122),(V123));
	{object V126 = list(3,VV[41],(V123),(V122));
	VMR9(V126)}}
}
/*	local entry for function C2RPLACA	*/

static object LI10(V128)

register object V128;
{	 VMB10 VMS10 VMV10
	bds_check;
TTL:;
	bds_bind(VV[20],symbol_value(VV[20]));
	bds_bind(VV[42],small_fixnum(0));
	V128= (VFUN_NARGS=2,(*(LnkLI236))((V128),VV[43]));
	if((symbol_value(VV[25]))==Cnil){
	goto T445;}
	princ_str("\n	if(type_of(",VV[7]);
	(void)((*(LnkLI217))(car((V128))));
	princ_str(")!=t_cons)",VV[7]);
	princ_str("FEwrong_type_argument(Scons,",VV[7]);
	(void)((*(LnkLI217))(car((V128))));
	princ_str(");",VV[7]);
T445:;
	princ_str("\n	(",VV[7]);
	(void)((*(LnkLI217))(car((V128))));
	princ_str(")->c.c_car = ",VV[7]);
	(void)((*(LnkLI217))(cadr((V128))));
	princ_char(59,VV[7]);
	(void)((VFUN_NARGS=1,(*(LnkLI218))(car((V128)))));
	{object V129 = (*(LnkLI237))();
	bds_unwind1;
	bds_unwind1;
	VMR10(V129)}
}
/*	local entry for function C1RPLACD	*/

static object LI11(V131)

register object V131;
{	 VMB11 VMS11 VMV11
TTL:;
	{object V132;
	V132= (VFUN_NARGS=0,(*(LnkLI212))());
	if(endp((V131))){
	goto T463;}
	if(!(endp(cdr((V131))))){
	goto T462;}
T463:;
	V133 = make_fixnum(length((V131)));
	(void)((*(LnkLI213))(VV[44],small_fixnum(2),V133));
T462:;
	if(endp(cddr((V131)))){
	goto T467;}
	V134 = make_fixnum(length((V131)));
	(void)((*(LnkLI214))(VV[44],small_fixnum(2),V134));
T467:;
	V131= (*(LnkLI223))((V131),(V132));
	{object V135 = list(3,VV[44],(V132),(V131));
	VMR11(V135)}}
}
/*	local entry for function C2RPLACD	*/

static object LI12(V137)

register object V137;
{	 VMB12 VMS12 VMV12
	bds_check;
TTL:;
	bds_bind(VV[20],symbol_value(VV[20]));
	bds_bind(VV[42],small_fixnum(0));
	V137= (VFUN_NARGS=2,(*(LnkLI236))((V137),VV[45]));
	if((symbol_value(VV[25]))==Cnil){
	goto T474;}
	princ_str("\n	if(type_of(",VV[7]);
	(void)((*(LnkLI217))(car((V137))));
	princ_str(")!=t_cons)",VV[7]);
	princ_str("FEwrong_type_argument(Scons,",VV[7]);
	(void)((*(LnkLI217))(car((V137))));
	princ_str(");",VV[7]);
T474:;
	princ_str("\n	(",VV[7]);
	(void)((*(LnkLI217))(car((V137))));
	princ_str(")->c.c_cdr = ",VV[7]);
	(void)((*(LnkLI217))(cadr((V137))));
	princ_char(59,VV[7]);
	(void)((VFUN_NARGS=1,(*(LnkLI218))(car((V137)))));
	{object V138 = (*(LnkLI237))();
	bds_unwind1;
	bds_unwind1;
	VMR12(V138)}
}
/*	local entry for function C1MEMQ	*/

static object LI13(V140)

register object V140;
{	 VMB13 VMS13 VMV13
TTL:;
	{object V141;
	V141= (VFUN_NARGS=0,(*(LnkLI212))());
	if(endp((V140))){
	goto T492;}
	if(!(endp(cdr((V140))))){
	goto T491;}
T492:;
	V142 = make_fixnum(length((V140)));
	(void)((*(LnkLI213))(VV[46],small_fixnum(2),V142));
T491:;
	if(endp(cddr((V140)))){
	goto T496;}
	V143 = make_fixnum(length((V140)));
	(void)((*(LnkLI214))(VV[46],small_fixnum(2),V143));
T496:;
	V144= list(2,car((V140)),cadr((V140)));
	{object V145 = list(4,VV[47],(V141),VV[48],(*(LnkLI223))(/* INLINE-ARGS */V144,(V141)));
	VMR13(V145)}}
}
/*	local entry for function C1MEMBER	*/

static object LI14(V147)

register object V147;
{	 VMB14 VMS14 VMV14
TTL:;
	{register object V148;
	V148= (VFUN_NARGS=0,(*(LnkLI212))());
	if(endp((V147))){
	goto T501;}
	if(!(endp(cdr((V147))))){
	goto T500;}
T501:;
	V149 = make_fixnum(length((V147)));
	(void)((*(LnkLI213))(VV[49],small_fixnum(2),V149));
T500:;
	if(!(endp(cddr((V147))))){
	goto T506;}
	{object V150 = list(4,VV[47],(V148),VV[50],(*(LnkLI223))((V147),(V148)));
	VMR14(V150)}
T506:;
	if(!((caddr((V147)))==(VV[51]))){
	goto T509;}
	if(!((length((V147)))==(4))){
	goto T509;}
	{register object x= cadddr((V147)),V151= VV[52];
	while(!endp(V151))
	if(equal(x,V151->c.c_car)){
	goto T514;
	}else V151=V151->c.c_cdr;
	goto T509;}
T514:;
	V152= cadr(cadddr((V147)));
	V153= list(2,car((V147)),cadr((V147)));
	{object V154 = list(4,VV[47],(V148),/* INLINE-ARGS */V152,(*(LnkLI223))(/* INLINE-ARGS */V153,(V148)));
	VMR14(V154)}
T509:;
	{object V155 = list(4,VV[4],(V148),VV[49],(*(LnkLI223))((V147),(V148)));
	VMR14(V155)}}
}
/*	local entry for function C2MEMBER!2	*/

static object LI15(V158,V159)

object V158;register object V159;
{	 VMB15 VMS15 VMV15
	bds_check;
TTL:;
	{register object V160;
	bds_bind(VV[20],symbol_value(VV[20]));
	bds_bind(VV[42],small_fixnum(0));
	setq(VV[22],number_plus(symbol_value(VV[22]),small_fixnum(1)));
	V160= symbol_value(VV[22]);
	V159= (VFUN_NARGS=2,(*(LnkLI236))((V159),VV[53]));
	princ_str("\n	{register object x= ",VV[7]);
	(void)((*(LnkLI217))(car((V159))));
	princ_str(",V",VV[7]);
	(void)((*(LnkLI217))((V160)));
	princ_str("= ",VV[7]);
	(void)((*(LnkLI217))(cadr((V159))));
	princ_char(59,VV[7]);
	if((symbol_value(VV[25]))==Cnil){
	goto T529;}
	princ_str("\n	while(!endp(V",VV[7]);
	(void)((*(LnkLI217))((V160)));
	princ_str("))",VV[7]);
	goto T527;
T529:;
	princ_str("\n	while(V",VV[7]);
	(void)((*(LnkLI217))((V160)));
	princ_str("!=Cnil)",VV[7]);
T527:;
	if(!(((V158))==(VV[48]))){
	goto T539;}
	princ_str("\n	if(x==(V",VV[7]);
	(void)((*(LnkLI217))((V160)));
	princ_str("->c.c_car)){",VV[7]);
	goto T537;
T539:;
	princ_str("\n	if(",VV[7]);
	base[3]= symbol_name((V158));
	vs_top=(vs_base=base+3)+1;
	Lstring_downcase();
	vs_top=sup;
	V161= vs_base[0];
	(void)((*(LnkLI217))(V161));
	princ_str("(x,V",VV[7]);
	(void)((*(LnkLI217))((V160)));
	princ_str("->c.c_car)){",VV[7]);
T537:;
	if(!(type_of(symbol_value(VV[5]))==t_cons)){
	goto T553;}
	if((car(symbol_value(VV[5])))==(VV[54])){
	goto T552;}
	if(!((car(symbol_value(VV[5])))==(VV[55]))){
	goto T553;}
T552:;
	(void)((VFUN_NARGS=2,(*(LnkLI218))(Ct,VV[56])));
	goto T551;
T553:;
	V162= list(2,VV[21],(V160));
	(void)((VFUN_NARGS=2,(*(LnkLI218))(/* INLINE-ARGS */V162,VV[56])));
T551:;
	princ_str("\n	}else V",VV[7]);
	(void)((*(LnkLI217))((V160)));
	princ_str("=V",VV[7]);
	(void)((*(LnkLI217))((V160)));
	princ_str("->c.c_cdr;",VV[7]);
	(void)((VFUN_NARGS=1,(*(LnkLI218))(Cnil)));
	princ_char(125,VV[7]);
	{object V163 = (*(LnkLI237))();
	bds_unwind1;
	bds_unwind1;
	VMR15(V163)}}
}
/*	local entry for function C1ASSOC	*/

static object LI16(V165)

register object V165;
{	 VMB16 VMS16 VMV16
TTL:;
	{register object V166;
	V166= (VFUN_NARGS=0,(*(LnkLI212))());
	if(endp((V165))){
	goto T570;}
	if(!(endp(cdr((V165))))){
	goto T569;}
T570:;
	V167 = make_fixnum(length((V165)));
	(void)((*(LnkLI213))(VV[57],small_fixnum(2),V167));
T569:;
	if(!(endp(cddr((V165))))){
	goto T575;}
	{object V168 = list(4,VV[58],(V166),VV[50],(*(LnkLI223))((V165),(V166)));
	VMR16(V168)}
T575:;
	if(!((caddr((V165)))==(VV[51]))){
	goto T578;}
	if(!((length((V165)))==(4))){
	goto T578;}
	{register object x= cadddr((V165)),V169= VV[59];
	while(!endp(V169))
	if(equal(x,V169->c.c_car)){
	goto T583;
	}else V169=V169->c.c_cdr;
	goto T578;}
T583:;
	V170= cadr(cadddr((V165)));
	V171= list(2,car((V165)),cadr((V165)));
	{object V172 = list(4,VV[58],(V166),/* INLINE-ARGS */V170,(*(LnkLI223))(/* INLINE-ARGS */V171,(V166)));
	VMR16(V172)}
T578:;
	{object V173 = list(4,VV[4],(V166),VV[57],(*(LnkLI223))((V165),(V166)));
	VMR16(V173)}}
}
/*	local entry for function C2ASSOC!2	*/

static object LI17(V176,V177)

object V176;register object V177;
{	 VMB17 VMS17 VMV17
	bds_check;
TTL:;
	{register object V178;
	register object V179;
	bds_bind(VV[20],symbol_value(VV[20]));
	bds_bind(VV[42],small_fixnum(0));
	setq(VV[22],number_plus(symbol_value(VV[22]),small_fixnum(1)));
	V178= symbol_value(VV[22]);
	V179= Cnil;
	V177= (VFUN_NARGS=2,(*(LnkLI236))((V177),VV[60]));
	V179= symbol_name((V176));
	if(!(((V176))==(VV[48]))){
	goto T592;}
	goto T591;
T592:;
	base[3]= (V179);
	vs_top=(vs_base=base+3)+1;
	Lstring_downcase();
	vs_top=sup;
	V179= vs_base[0];
T591:;
	princ_str("\n	{register object x= ",VV[7]);
	(void)((*(LnkLI217))(car((V177))));
	princ_str(",V",VV[7]);
	(void)((*(LnkLI217))((V178)));
	princ_str("= ",VV[7]);
	(void)((*(LnkLI217))(cadr((V177))));
	princ_char(59,VV[7]);
	if((symbol_value(VV[25]))==Cnil){
	goto T606;}
	princ_str("\n	while(!endp(V",VV[7]);
	(void)((*(LnkLI217))((V178)));
	princ_str("))",VV[7]);
	princ_str("\n	if(type_of(V",VV[7]);
	(void)((*(LnkLI217))((V178)));
	princ_str("->c.c_car)==t_cons &&",VV[7]);
	(void)((*(LnkLI217))((V179)));
	princ_str("(x,V",VV[7]);
	(void)((*(LnkLI217))((V178)));
	princ_str("->c.c_car->c.c_car)){",VV[7]);
	goto T604;
T606:;
	princ_str("\n	while(V",VV[7]);
	(void)((*(LnkLI217))((V178)));
	princ_str("!=Cnil)",VV[7]);
	princ_str("\n	if(",VV[7]);
	(void)((*(LnkLI217))((V179)));
	princ_str("(x,V",VV[7]);
	(void)((*(LnkLI217))((V178)));
	princ_str("->c.c_car->c.c_car) &&",VV[7]);
	princ_char(86,VV[7]);
	(void)((*(LnkLI217))((V178)));
	princ_str("->c.c_car != Cnil){",VV[7]);
T604:;
	if(!(type_of(symbol_value(VV[5]))==t_cons)){
	goto T633;}
	if((car(symbol_value(VV[5])))==(VV[54])){
	goto T632;}
	if(!((car(symbol_value(VV[5])))==(VV[55]))){
	goto T633;}
T632:;
	(void)((VFUN_NARGS=2,(*(LnkLI218))(Ct,VV[56])));
	goto T631;
T633:;
	V180= list(2,VV[61],(V178));
	(void)((VFUN_NARGS=2,(*(LnkLI218))(/* INLINE-ARGS */V180,VV[56])));
T631:;
	princ_str("\n	}else V",VV[7]);
	(void)((*(LnkLI217))((V178)));
	princ_str("=V",VV[7]);
	(void)((*(LnkLI217))((V178)));
	princ_str("->c.c_cdr;",VV[7]);
	(void)((VFUN_NARGS=1,(*(LnkLI218))(Cnil)));
	princ_char(125,VV[7]);
	{object V181 = (*(LnkLI237))();
	bds_unwind1;
	bds_unwind1;
	VMR17(V181)}}
}
/*	local entry for function C1BOOLE-CONDITION	*/

static object LI18(V183)

object V183;
{	 VMB18 VMS18 VMV18
TTL:;
	if(((endp(cddr((V183)))?Ct:Cnil))==Cnil){
	goto T648;}
	{object V184 = Cnil;
	VMR18(V184)}
T648:;
	if(endp(cdddr((V183)))){
	goto T650;}
	{object V185 = Cnil;
	VMR18(V185)}
T650:;
	{object V186 = (*(LnkLI238))(car((V183)));
	VMR18(V186)}
}
/*	local entry for function C1BOOLE3	*/

static object LI19(V188)

object V188;
{	 VMB19 VMS19 VMV19
TTL:;
	V189= make_cons(VV[62],(V188));
	{object V190 = (*(LnkLI239))(/* INLINE-ARGS */V189);
	VMR19(V190)}
}
/*	function definition for INLINE-BOOLE3	*/

static L20()
{register object *base=vs_base;
	register object *sup=base+VM20; VC20
	vs_reserve(VM20);
	{object V191;
	vs_top[0]=Cnil;
	{object *p=vs_top;
	 for(;p>vs_base;p--)p[-1]=MMcons(p[-1],p[0]);}
	V191=(base[0]);
	vs_top=sup;
	{object V192;
	V192= cadr(car((V191)));
	if(!((car((V192)))==(VV[63]))){
	goto T654;}
	goto T653;
T654:;
	base[1]= VV[64];
	vs_top=(vs_base=base+1)+1;
	Lerror();
	vs_top=sup;
T653:;
	{object V193;
	V193= (*(LnkLI238))(caddr((V192)));
	if((V193)!=Cnil){
	goto T658;}
	base[1]= VV[65];
	vs_top=(vs_base=base+1)+1;
	Lerror();
	vs_top=sup;
T658:;
	base[1]= (V193);
	base[2]= cdr((V191));
	vs_top=(vs_base=base+1)+2;
	(void) (*Lnk240)();
	return;}}
	}
}
/*	local entry for function INLINE-BOOLE3-STRING	*/

static object LI21(V195)

register object V195;
{	 VMB21 VMS21 VMV21
TTL:;
	base[0]= (V195);
	vs_top=(vs_base=base+0)+1;
	Lconstantp();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T663;}
	goto T662;
T663:;
	base[0]= (V195);
	vs_top=(vs_base=base+0)+1;
	Leval();
	vs_top=sup;
	V195= vs_base[0];
T662:;
	{object V196= (V195);
	if(!eql(V196,VV[66]))goto T668;
	{object V197 = VV[67];
	VMR21(V197)}
T668:;
	if(!eql(V196,VV[68]))goto T669;
	{object V198 = VV[69];
	VMR21(V198)}
T669:;
	if(!eql(V196,VV[70]))goto T670;
	{object V199 = VV[71];
	VMR21(V199)}
T670:;
	if(!eql(V196,VV[72]))goto T671;
	{object V200 = VV[73];
	VMR21(V200)}
T671:;
	if(!eql(V196,VV[74]))goto T672;
	{object V201 = VV[75];
	VMR21(V201)}
T672:;
	if(!eql(V196,VV[76]))goto T673;
	{object V202 = VV[77];
	VMR21(V202)}
T673:;
	if(!eql(V196,VV[78]))goto T674;
	{object V203 = VV[79];
	VMR21(V203)}
T674:;
	if(!eql(V196,VV[80]))goto T675;
	{object V204 = VV[81];
	VMR21(V204)}
T675:;
	if(!eql(V196,VV[82]))goto T676;
	{object V205 = VV[83];
	VMR21(V205)}
T676:;
	if(!eql(V196,VV[84]))goto T677;
	{object V206 = VV[85];
	VMR21(V206)}
T677:;
	{object V207 = Cnil;
	VMR21(V207)}}
}
/*	local entry for function C1ASH-CONDITION	*/

static object LI22(V209)

object V209;
{	 VMB22 VMS22 VMV22
TTL:;
	{register object V210;
	V210= cadr((V209));{object V211;
	{register object V212;
	V212= (V210);
	if(type_of((V212))==t_fixnum){
	goto T681;}
	V211= Cnil;
	goto T680;
T681:;
	if((fix((V212)))>=(0)){
	goto T683;}
	V211= Cnil;
	goto T680;
T683:;
	V211= ((fix((V212)))<=(31)?Ct:Cnil);}
T680:;
	if(V211==Cnil)goto T679;
	{object V213 = V211;
	VMR22(V213)}
T679:;}
	if(type_of((V210))==t_cons){
	goto T685;}
	{object V214 = Cnil;
	VMR22(V214)}
T685:;
	if((car((V210)))==(VV[86])){
	goto T687;}
	{object V215 = Cnil;
	VMR22(V215)}
T687:;
	{object V216;
	V216= cadr((V210));
	base[0]= (V216);
	base[1]= VV[87];
	vs_top=(vs_base=base+0)+2;
	(void) (*Lnk241)();
	vs_top=sup;
	{object V217 = vs_base[0];
	VMR22(V217)}}}
}
/*	local entry for function C1ASH	*/

static object LI23(V219)

object V219;
{	 VMB23 VMS23 VMV23
TTL:;
	{register object V220;
	register object V221;
	V220= cadr((V219));
	V221= Cnil;
	base[0]= (V220);
	vs_top=(vs_base=base+0)+1;
	Lconstantp();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T695;}
	base[0]= (V220);
	vs_top=(vs_base=base+0)+1;
	Leval();
	vs_top=sup;
	V220= vs_base[0];{object V222;
	base[0]= (V220);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk242)();
	vs_top=sup;
	V222= vs_base[0];
	if(V222==Cnil)goto T702;
	goto T701;
T702:;}
	base[0]= VV[88];
	vs_top=(vs_base=base+0)+1;
	Lerror();
	vs_top=sup;
T701:;
	if(!(number_compare((V220),small_fixnum(0))<0)){
	goto T707;}
	V221= VV[89];
	goto T693;
T707:;
	if(!(number_compare((V220),small_fixnum(0))>=0)){
	goto T693;}
	V221= VV[90];
	goto T693;
T695:;
	{object V223;
	V223= cadr((V220));
	base[0]= (V223);
	base[1]= VV[91];
	vs_top=(vs_base=base+0)+2;
	(void) (*Lnk241)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T715;}
	V221= VV[90];
	goto T693;
T715:;
	base[0]= (V223);
	base[1]= VV[92];
	vs_top=(vs_base=base+0)+2;
	(void) (*Lnk241)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T721;}
	V221= VV[89];
	goto T693;
T721:;
	base[0]= VV[93];
	vs_top=(vs_base=base+0)+1;
	Lerror();
	vs_top=sup;}
T693:;
	V224= make_cons((V221),(V219));
	{object V225 = (*(LnkLI239))(/* INLINE-ARGS */V224);
	VMR23(V225)}}
}
/*	local entry for function SHIFT>>	*/

static object LI24(V228,V229)

object V228;object V229;
{	 VMB24 VMS24 VMV24
TTL:;
	base[0]= (V228);
	base[1]= (V229);
	vs_top=(vs_base=base+0)+2;
	Lash();
	vs_top=sup;
	{object V230 = vs_base[0];
	VMR24(V230)}
}
/*	local entry for function SHIFT<<	*/

static object LI25(V233,V234)

object V233;object V234;
{	 VMB25 VMS25 VMV25
TTL:;
	base[0]= (V233);
	base[1]= (V234);
	vs_top=(vs_base=base+0)+2;
	Lash();
	vs_top=sup;
	{object V235 = vs_base[0];
	VMR25(V235)}
}
/*	function definition for CO1LDB	*/

static L26()
{register object *base=vs_base;
	register object *sup=base+VM26; VC26
	vs_reserve(VM26);
	{object V236;
	object V237;
	check_arg(2);
	V236=(base[0]);
	V237=(base[1]);
	vs_top=sup;
TTL:;
	{register object V238;
	object V239;
	V238= Cnil;
	base[3]= VV[94];
	vs_top=(vs_base=base+3)+1;
	Linteger_length();
	vs_top=sup;
	V239= vs_base[0];
	{register object V240;
	{object V241;
	V238= car((V237));
	if(type_of((V238))==t_cons){
	goto T737;}
	V241= Cnil;
	goto T736;
T737:;
	if((VV[95])==(car((V238)))){
	goto T740;}
	V241= Cnil;
	goto T736;
T740:;
	V241= make_cons(cadr((V238)),caddr((V238)));
T736:;
	if(((V241))==Cnil){
	goto T743;}
	V240= (V241);
	goto T735;
T743:;
	V240= Cnil;}
T735:;
	{object V242= cdr((V240));
	if(!(type_of(V242)==t_fixnum||type_of(V242)==t_bignum)){
	goto T746;}}
	{object V243= car((V240));
	if(!(type_of(V243)==t_fixnum||type_of(V243)==t_bignum)){
	goto T746;}}
	V244= number_plus(car((V240)),cdr((V240)));
	if(!(number_compare(/* INLINE-ARGS */V244,(V239))<0)){
	goto T746;}
	base[3]= (*(LnkLI243))(cadr((V237)));
	base[4]= VV[96];
	vs_top=(vs_base=base+3)+2;
	(void) (*Lnk241)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T746;}
	V245= list(3,VV[86],VV[96],list(4,VV[97],car((V240)),cdr((V240)),cadr((V237))));
	base[3]= (*(LnkLI239))(/* INLINE-ARGS */V245);
	vs_top=(vs_base=base+3)+1;
	return;
T746:;
	base[3]= Cnil;
	vs_top=(vs_base=base+3)+1;
	return;}}
	}
}
/*	local entry for function C1LENGTH	*/

static object LI27(V247)

register object V247;
{	 VMB27 VMS27 VMV27
TTL:;
	{register object V248;
	V248= (VFUN_NARGS=0,(*(LnkLI212))());
	(void)(structure_set((V248),VV[98],2,VV[96]));
	{object V249;
	if(type_of(car((V247)))==t_cons){
	goto T759;}
	V249= Cnil;
	goto T758;
T759:;
	if((caar((V247)))==(VV[99])){
	goto T761;}
	V249= Cnil;
	goto T758;
T761:;
	{object V250;
	V250= cdr(car((V247)));
	if((V250)==Cnil){
	V249= Cnil;
	goto T758;}
	if((cddr((V250)))==Cnil){
	goto T764;}
	V249= Cnil;
	goto T758;
T764:;
	V249= list(4,VV[4],(V248),VV[100],(*(LnkLI223))((V250),(V248)));}
T758:;
	if(((V249))==Cnil){
	goto T767;}
	{object V251 = (V249);
	VMR27(V251)}
T767:;
	V247= (*(LnkLI223))((V247),(V248));
	{object V252 = list(4,VV[4],(V248),VV[101],(V247));
	VMR27(V252)}}}
}
/*	local entry for function C1GET	*/

static object LI28(V254)

register object V254;
{	 VMB28 VMS28 VMV28
TTL:;
	{object V255;
	V255= (VFUN_NARGS=0,(*(LnkLI212))());
	if(endp((V254))){
	goto T773;}
	if(!(endp(cdr((V254))))){
	goto T772;}
T773:;
	V256 = make_fixnum(length((V254)));
	(void)((*(LnkLI213))(VV[102],small_fixnum(2),V256));
T772:;
	if(endp(cddr((V254)))){
	goto T777;}
	if(endp(cdddr((V254)))){
	goto T777;}
	V257 = make_fixnum(length((V254)));
	(void)((*(LnkLI214))(VV[102],small_fixnum(3),V257));
T777:;
	{object V258 = list(3,VV[102],(V255),(*(LnkLI223))((V254),(V255)));
	VMR28(V258)}}
}
/*	local entry for function C2GET	*/

static object LI29(V260)

register object V260;
{	 VMB29 VMS29 VMV29
	bds_check;
TTL:;
	if((symbol_value(VV[25]))==Cnil){
	goto T783;}
	{object V261 = (*(LnkLI219))(VV[102],(V260),Cnil,Ct);
	VMR29(V261)}
T783:;
	{register object V262;
	base[0]= symbol_value(VV[20]);
	setq(VV[22],number_plus(symbol_value(VV[22]),small_fixnum(1)));
	V262= symbol_value(VV[22]);
	bds_bind(VV[20],base[0]);
	bds_bind(VV[42],small_fixnum(0));
	if((cddr((V260)))==Cnil){
	goto T792;}
	V263= VV[103];
	goto T790;
T792:;
	V263= VV[104];
T790:;
	V260= (VFUN_NARGS=2,(*(LnkLI236))((V260),V263));
	princ_str("\n	{object V",VV[7]);
	(void)((*(LnkLI217))((V262)));
	princ_str(" =(",VV[7]);
	(void)((*(LnkLI217))(car((V260))));
	princ_str(")->s.s_plist;",VV[7]);
	princ_str("\n	 object ind= ",VV[7]);
	(void)((*(LnkLI217))(cadr((V260))));
	princ_char(59,VV[7]);
	princ_str("\n	while(V",VV[7]);
	(void)((*(LnkLI217))((V262)));
	princ_str("!=Cnil){",VV[7]);
	princ_str("\n	if(V",VV[7]);
	(void)((*(LnkLI217))((V262)));
	princ_str("->c.c_car==ind){",VV[7]);
	V264= list(2,VV[105],(V262));
	(void)((VFUN_NARGS=2,(*(LnkLI218))(/* INLINE-ARGS */V264,VV[56])));
	princ_str("\n	}else V",VV[7]);
	(void)((*(LnkLI217))((V262)));
	princ_str("=V",VV[7]);
	(void)((*(LnkLI217))((V262)));
	princ_str("->c.c_cdr->c.c_cdr;}",VV[7]);
	if((cddr((V260)))==Cnil){
	goto T822;}
	V265= caddr((V260));
	goto T820;
T822:;
	V265= Cnil;
T820:;
	(void)((VFUN_NARGS=1,(*(LnkLI218))(V265)));
	princ_char(125,VV[7]);
	{object V266 = (*(LnkLI237))();
	bds_unwind1;
	bds_unwind1;
	VMR29(V266)}}
}
/*	local entry for function CO1EQL	*/

static object LI30(V269,V270)

object V269;register object V270;
{	 VMB30 VMS30 VMV30
TTL:;{object V271;
	if((cdr((V270)))!=Cnil){
	goto T830;}
	V271= Cnil;
	goto T829;
T830:;
	V271= ((symbol_value(VV[25]))==Cnil?Ct:Cnil);
T829:;
	if(V271==Cnil)goto T828;
	goto T827;
T828:;}
	{object V272 = Cnil;
	VMR30(V272)}
T827:;
	if(((*(LnkLI244))((V270)))==Cnil){
	goto T833;}
	if(!(type_of(cadr((V270)))==t_character)){
	goto T835;}
	V270= reverse((V270));
T835:;
	if(!(type_of(car((V270)))==t_character)){
	goto T840;}
	{register object V273;
	vs_base=vs_top;
	Lgensym();
	vs_top=sup;
	V273= vs_base[0];
	V274= list(2,(V273),cadr((V270)));
	V275= make_cons(/* INLINE-ARGS */V274,Cnil);
	V276= (*(LnkLI243))(cadr((V270)));
	V277= list(2,VV[106],list(3,VV[107],/* INLINE-ARGS */V276,(V273)));
	V278= list(3,VV[109],(V273),VV[110]);
	V279= list(2,VV[112],car((V270)));
	V280= list(4,VV[29],/* INLINE-ARGS */V275,/* INLINE-ARGS */V277,list(3,VV[108],/* INLINE-ARGS */V278,list(3,VV[111],/* INLINE-ARGS */V279,list(3,VV[86],VV[96],list(2,VV[112],list(3,VV[86],VV[14],(V273)))))));
	{object V281 = (*(LnkLI239))(/* INLINE-ARGS */V280);
	VMR30(V281)}}
T840:;
	{object V282 = Cnil;
	VMR30(V282)}
T833:;
	{object V283 = Cnil;
	VMR30(V283)}
}
/*	local entry for function RESULT-TYPE	*/

static object LI31(V285)

register object V285;
{	 VMB31 VMS31 VMV31
TTL:;
	if(!(type_of((V285))==t_symbol)){
	goto T844;}
	{object V286;
	V286= (*(LnkLI239))((V285));
	{object V287 = structure_ref(cadr((V286)),VV[98],2);
	VMR31(V287)}}
T844:;
	base[0]= (V285);
	vs_top=(vs_base=base+0)+1;
	Lconstantp();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T848;}
	base[0]= (V285);
	vs_top=(vs_base=base+0)+1;
	Ltype_of();
	vs_top=sup;
	V288= vs_base[0];
	{object V289 = (*(LnkLI245))(V288);
	VMR31(V289)}
T848:;
	if(!(type_of((V285))==t_cons)){
	goto T854;}
	if(!((car((V285)))==(VV[86]))){
	goto T854;}
	{object V290 = (*(LnkLI245))(cadr((V285)));
	VMR31(V290)}
T854:;
	{object V291 = Ct;
	VMR31(V291)}
}
/*	local entry for function CO1TYPEP	*/

static object LI32(V294,V295)

object V294;register object V295;
{	 VMB32 VMS32 VMV32
TTL:;
	{register object V296;
	V296= Cnil;
	{register object V297;
	register object V298;
	register object V299;
	V297= car((V295));
	V298= Cnil;
	if(type_of(cadr((V295)))==t_cons){
	goto T863;}
	V299= Cnil;
	goto T862;
T863:;
	if((car(cadr((V295))))==(VV[113])){
	goto T865;}
	V299= Cnil;
	goto T862;
T865:;
	V299= cadr(cadr((V295)));
T862:;
	base[2]= (*(LnkLI243))(car((V295)));
	base[3]= (V299);
	vs_top=(vs_base=base+2)+2;
	(void) (*Lnk241)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T867;}
	V298= Ct;
	{object V300 = (*(LnkLI239))((V298));
	VMR32(V300)}
T867:;
	if(((V299))!=Cnil){
	goto T877;}
	V298= Cnil;
	goto T875;
T877:;
	{register object x= (V299),V301= symbol_value(VV[114]);
	while(!endp(V301))
	if(type_of(V301->c.c_car)==t_cons &&equal(x,V301->c.c_car->c.c_car)){
	V294= (V301->c.c_car);
	goto T882;
	}else V301=V301->c.c_cdr;
	V294= Cnil;}
T882:;
	if(((V294))==Cnil){
	goto T880;}
	V298= list(2,cdr((V294)),(V297));
	goto T875;
T880:;
	if(!(type_of((V299))==t_cons)){
	goto T884;}
	if(!((car((V299)))==(VV[115]))){
	goto T887;}
	if((cddr((V299)))==Cnil){
	goto T883;}
T887:;
	{register object x= car((V299)),V302= VV[116];
	while(!endp(V302))
	if(eql(x,V302->c.c_car)){
	goto T892;
	}else V302=V302->c.c_cdr;
	goto T884;}
T892:;
	if(!(equal(caddr((V299)),VV[117]))){
	goto T884;}
T883:;
	V296= (*(LnkLI246))(cadr((V299)));
	if(!(((V296))==(VV[118]))){
	goto T897;}
	V298= list(2,VV[119],(V297));
	goto T875;
T897:;
	if(!(((V296))==(VV[120]))){
	goto T900;}
	V298= list(2,VV[121],(V297));
	goto T875;
T900:;
	V296= (VFUN_NARGS=2,(*(LnkLI247))((V296),symbol_value(VV[122])));
	if(((V296))==Cnil){
	goto T903;}
	V298= list(3,VV[86],VV[123],list(3,VV[124],(V297),(V296)));
	goto T875;
T903:;
	V298= Cnil;
	goto T875;
T884:;
	{object V303;
	if(type_of((V299))==t_cons){
	goto T907;}
	V303= Cnil;
	goto T906;
T907:;
	if((car((V299)))==(VV[125])){
	goto T909;}
	V303= Cnil;
	goto T906;
T909:;
	if(type_of(cdr((V299)))==t_cons){
	goto T911;}
	V303= Cnil;
	goto T906;
T911:;
	if((cadr((V299)))!=Cnil){
	goto T913;}
	V303= Cnil;
	goto T906;
T913:;
	if(type_of(cadr((V299)))==t_symbol){
	goto T915;}
	V303= Cnil;
	goto T906;
T915:;
	base[2]= cadr((V299));
	vs_top=(vs_base=base+2)+1;
	Lsymbol_package();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T917;}
	V303= Cnil;
	goto T906;
T917:;
	if((cddr((V299)))==Cnil){
	goto T920;}
	V303= Cnil;
	goto T906;
T920:;
	V303= list(2,cadr((V299)),(V297));
T906:;
	if(((V303))==Cnil){
	goto T923;}
	V298= (V303);
	goto T875;
T923:;
	base[2]= (V299);
	base[3]= VV[96];
	vs_top=(vs_base=base+2)+2;
	(void) (*Lnk241)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T926;}
	V296= (*(LnkLI248))((V299));
	if(type_of((V296))==t_cons){
	goto T932;}
	V298= Cnil;
	goto T875;
T932:;
	base[2]= cadr((V296));
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk242)();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T934;}
	V298= Cnil;
	goto T875;
T934:;
	base[2]= caddr((V296));
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk242)();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T937;}
	V298= Cnil;
	goto T875;
T937:;
	V304= list(2,VV[126],(V297));
	V305= make_cons(/* INLINE-ARGS */V304,Cnil);
	V306= (*(LnkLI243))((V297));
	V307= list(2,VV[106],list(3,VV[107],/* INLINE-ARGS */V306,VV[126]));
	V308= list(3,VV[128],VV[129],cadr((V296)));
	V298= list(4,VV[29],/* INLINE-ARGS */V305,/* INLINE-ARGS */V307,list(4,VV[108],VV[127],/* INLINE-ARGS */V308,list(3,VV[130],VV[131],caddr((V296)))));
	goto T875;
T926:;
	if(!(type_of((V299))==t_symbol)){
	goto T941;}
	V296= get((V299),VV[132],Cnil);
	if(((V296))==Cnil){
	goto T941;}
	if((structure_ref((V296),VV[132],11))!=Cnil){
	goto T946;}
	if((symbol_value(VV[133]))==Cnil){
	goto T947;}
T946:;
	V298= (*(LnkLI249))((V297),(V296));
	goto T875;
T947:;
	V298= list(3,VV[134],(V297),list(2,VV[113],(V299)));
	goto T875;
T941:;
	V298= Cnil;}
T875:;
	if((V298)==Cnil){
	{object V309 = Cnil;
	VMR32(V309)}}
	V310= list(3,VV[86],VV[123],(V298));
	{object V311 = (*(LnkLI239))(/* INLINE-ARGS */V310);
	VMR32(V311)}}}
}
/*	local entry for function STRUCT-TYPE-OPT	*/

static object LI33(V314,V315)

object V314;object V315;
{	 VMB33 VMS33 VMV33
TTL:;
	{register object V316;
	object V317;
	vs_base=vs_top;
	Lgensym();
	vs_top=sup;
	V316= vs_base[0];
	V318= structure_ref((V315),VV[132],0);
	V317= (*(LnkLI250))(/* INLINE-ARGS */V318);
	V319= list(2,(V316),(V314));
	V320= make_cons(/* INLINE-ARGS */V319,Cnil);
	V321= list(2,VV[135],(V316));
	if(!((length((V317)))<(3))){
	goto T955;}
	{object V324;
	object V325= (V317);
	if(endp(V325)){
	V323= Cnil;
	goto T957;}
	base[0]=V324=MMcons(Cnil,Cnil);
T958:;
	V327= list(2,VV[137],(V316));
	(V324->c.c_car)= list(3,VV[48],/* INLINE-ARGS */V327,(*(LnkLI251))((V325->c.c_car)));
	if(endp(V325=MMcdr(V325))){
	V323= base[0];
	goto T957;}
	V324=MMcdr(V324)=MMcons(Cnil,Cnil);
	goto T958;}
T957:;
	V322= make_cons(VV[136],V323);
	goto T953;
T955:;
	V328= structure_ref((V315),VV[132],0);
	V322= list(3,VV[134],(V316),(*(LnkLI251))(/* INLINE-ARGS */V328));
T953:;
	{object V329 = list(3,VV[29],/* INLINE-ARGS */V320,list(3,VV[108],/* INLINE-ARGS */V321,V322));
	VMR33(V329)}}
}
/*	local entry for function GET-INCLUDED	*/

static object LI34(V331)

object V331;
{	 VMB34 VMS34 VMV34
TTL:;
	{object V332;
	V332= get((V331),VV[132],Cnil);
	V333= structure_ref((V332),VV[132],0);
	V337= structure_ref((V332),VV[132],3);
	{object V335;
	object V336= /* INLINE-ARGS */V337;
	if(endp(V336)){
	V334= Cnil;
	goto T961;}
	base[0]=V335=MMcons(Cnil,Cnil);
T962:;
	(V335->c.c_cdr)= (*(LnkLI250))((V336->c.c_car));
	while(!endp(MMcdr(V335)))V335=MMcdr(V335);
	if(endp(V336=MMcdr(V336))){
	base[0]=base[0]->c.c_cdr;
	V334= base[0];
	goto T961;}
	goto T962;}
T961:;
	{object V338 = make_cons(/* INLINE-ARGS */V333,V334);
	VMR34(V338)}}
}
/*	local entry for function CO1SCHAR	*/

static object LI35(V341,V342)

object V341;register object V342;
{	 VMB35 VMS35 VMV35
TTL:;
	{object V343= car((V342));
	if(type_of(V343)==t_cons||(V343)==Cnil){
	goto T965;}}
	{object V344 = Cnil;
	VMR35(V344)}
T965:;
	if((symbol_value(VV[25]))==Cnil){
	goto T967;}
	{object V345 = Cnil;
	VMR35(V345)}
T967:;
	if((cdr((V342)))!=Cnil){
	goto T969;}
	{object V346 = Cnil;
	VMR35(V346)}
T969:;
	if((caar((V342)))==(VV[99])){
	goto T971;}
	{object V347 = Cnil;
	VMR35(V347)}
T971:;
	V348= list(3,VV[138],list(3,VV[86],VV[15],cadr(car((V342)))),cadr((V342)));
	{object V349 = (*(LnkLI239))(/* INLINE-ARGS */V348);
	VMR35(V349)}
}
/*	local entry for function CONS-TO-LISTA	*/

static object LI36(V351)

object V351;
{	 VMB36 VMS36 VMV36
TTL:;
	{register object V352;
	base[0]= (V351);
	vs_top=(vs_base=base+0)+1;
	Llast();
	vs_top=sup;
	V352= vs_base[0];
	{object V353;
	if(type_of((V352))==t_cons){
	goto T976;}
	V353= Cnil;
	goto T975;
T976:;
	if(type_of(car((V352)))==t_cons){
	goto T978;}
	V353= Cnil;
	goto T975;
T978:;
	if((caar((V352)))==(VV[139])){
	goto T980;}
	V353= Cnil;
	goto T975;
T980:;
	if((length(cdar((V352))))==(2)){
	goto T982;}
	V353= Cnil;
	goto T975;
T982:;
	base[0]= (V351);
	vs_top=(vs_base=base+0)+1;
	Lbutlast();
	vs_top=sup;
	V354= vs_base[0];
	V355= append(V354,cdar((V352)));
	V353= (*(LnkLI252))(/* INLINE-ARGS */V355);
T975:;
	if(((V353))==Cnil){
	goto T987;}
	{object V356 = (V353);
	VMR36(V356)}
T987:;
	{object V357 = (V351);
	VMR36(V357)}}}
}
/*	local entry for function CO1CONS	*/

static object LI37(V360,V361)

object V360;object V361;
{	 VMB37 VMS37 VMV37
TTL:;
	{register object V362;
	if((length((V361)))==(2)){
	goto T991;}
	V362= Cnil;
	goto T990;
T991:;
	V362= (*(LnkLI252))((V361));
T990:;
	if(((((V362))==((V361))?Ct:Cnil))==Cnil){
	goto T993;}
	{object V363 = Cnil;
	VMR37(V363)}
T993:;
	base[0]= (V362);
	vs_top=(vs_base=base+0)+1;
	Llast();
	vs_top=sup;
	V365= vs_base[0];
	if(!(equal(VV[140],V365))){
	goto T997;}
	base[0]= (V362);
	vs_top=(vs_base=base+0)+1;
	Lbutlast();
	vs_top=sup;
	V366= vs_base[0];
	V364= make_cons(VV[141],V366);
	goto T995;
T997:;
	V364= make_cons(VV[28],(V362));
T995:;
	{object V367 = (*(LnkLI239))(V364);
	VMR37(V367)}}
}
/*	local entry for function C1NTH-CONDITION	*/

static object LI38(V369)

register object V369;
{	 VMB38 VMS38 VMV38
TTL:;
	if(((endp((V369))?Ct:Cnil))==Cnil){
	goto T1003;}
	{object V370 = Cnil;
	VMR38(V370)}
T1003:;
	if(((endp(cdr((V369)))?Ct:Cnil))==Cnil){
	goto T1005;}
	{object V371 = Cnil;
	VMR38(V371)}
T1005:;
	if(endp(cddr((V369)))){
	goto T1007;}
	{object V372 = Cnil;
	VMR38(V372)}
T1007:;
	{object V373= car((V369));
	if(type_of(V373)==t_fixnum||
type_of(V373)==t_bignum||
type_of(V373)==t_ratio||
type_of(V373)==t_shortfloat||
type_of(V373)==t_longfloat||
type_of(V373)==t_complex){
	goto T1009;}}
	{object V374 = Cnil;
	VMR38(V374)}
T1009:;
	base[0]= small_fixnum(0);
	base[1]= car((V369));
	base[2]= small_fixnum(7);
	vs_top=(vs_base=base+0)+3;
	Lmonotonically_nondecreasing();
	vs_top=sup;
	{object V375 = vs_base[0];
	VMR38(V375)}
}
/*	local entry for function C1NTH	*/

static object LI39(V377)

register object V377;
{	 VMB39 VMS39 VMV39
TTL:;
	{object V379= car((V377));
	if(!eql(V379,VV[142]))goto T1015;
	V378= make_cons(VV[61],cdr((V377)));
	goto T1014;
T1015:;
	if(!eql(V379,VV[80]))goto T1016;
	V378= make_cons(VV[105],cdr((V377)));
	goto T1014;
T1016:;
	if(!eql(V379,VV[68]))goto T1017;
	V378= make_cons(VV[143],cdr((V377)));
	goto T1014;
T1017:;
	if(!eql(V379,VV[144]))goto T1018;
	V378= make_cons(VV[145],cdr((V377)));
	goto T1014;
T1018:;
	if(!eql(V379,VV[66]))goto T1019;
	V378= list(2,VV[61],make_cons(VV[146],cdr((V377))));
	goto T1014;
T1019:;
	if(!eql(V379,VV[147]))goto T1020;
	V378= list(2,VV[105],make_cons(VV[146],cdr((V377))));
	goto T1014;
T1020:;
	if(!eql(V379,VV[82]))goto T1021;
	V378= list(2,VV[143],make_cons(VV[146],cdr((V377))));
	goto T1014;
T1021:;
	if(!eql(V379,VV[84]))goto T1022;
	V378= list(2,VV[145],make_cons(VV[146],cdr((V377))));
	goto T1014;
T1022:;
	V378= Cnil;}
T1014:;
	{object V380 = (*(LnkLI239))(V378);
	VMR39(V380)}
}
/*	local entry for function C1NTHCDR-CONDITION	*/

static object LI40(V382)

register object V382;
{	 VMB40 VMS40 VMV40
TTL:;
	if(((endp((V382))?Ct:Cnil))==Cnil){
	goto T1023;}
	{object V383 = Cnil;
	VMR40(V383)}
T1023:;
	if(((endp(cdr((V382)))?Ct:Cnil))==Cnil){
	goto T1025;}
	{object V384 = Cnil;
	VMR40(V384)}
T1025:;
	if(endp(cddr((V382)))){
	goto T1027;}
	{object V385 = Cnil;
	VMR40(V385)}
T1027:;
	{object V386= car((V382));
	if(type_of(V386)==t_fixnum||
type_of(V386)==t_bignum||
type_of(V386)==t_ratio||
type_of(V386)==t_shortfloat||
type_of(V386)==t_longfloat||
type_of(V386)==t_complex){
	goto T1029;}}
	{object V387 = Cnil;
	VMR40(V387)}
T1029:;
	base[0]= small_fixnum(0);
	base[1]= car((V382));
	base[2]= small_fixnum(7);
	vs_top=(vs_base=base+0)+3;
	Lmonotonically_nondecreasing();
	vs_top=sup;
	{object V388 = vs_base[0];
	VMR40(V388)}
}
/*	local entry for function C1NTHCDR	*/

static object LI41(V390)

register object V390;
{	 VMB41 VMS41 VMV41
TTL:;
	{object V392= car((V390));
	if(!eql(V392,VV[142]))goto T1035;
	V391= cadr((V390));
	goto T1034;
T1035:;
	if(!eql(V392,VV[80]))goto T1036;
	V391= make_cons(VV[148],cdr((V390)));
	goto T1034;
T1036:;
	if(!eql(V392,VV[68]))goto T1037;
	V391= make_cons(VV[149],cdr((V390)));
	goto T1034;
T1037:;
	if(!eql(V392,VV[144]))goto T1038;
	V391= make_cons(VV[150],cdr((V390)));
	goto T1034;
T1038:;
	if(!eql(V392,VV[66]))goto T1039;
	V391= make_cons(VV[146],cdr((V390)));
	goto T1034;
T1039:;
	if(!eql(V392,VV[147]))goto T1040;
	V391= list(2,VV[148],make_cons(VV[146],cdr((V390))));
	goto T1034;
T1040:;
	if(!eql(V392,VV[82]))goto T1041;
	V391= list(2,VV[149],make_cons(VV[146],cdr((V390))));
	goto T1034;
T1041:;
	if(!eql(V392,VV[84]))goto T1042;
	V391= list(2,VV[150],make_cons(VV[146],cdr((V390))));
	goto T1034;
T1042:;
	V391= Cnil;}
T1034:;
	{object V393 = (*(LnkLI239))(V391);
	VMR41(V393)}
}
/*	local entry for function C1RPLACA-NTHCDR	*/

static object LI42(V395)

register object V395;
{	 VMB42 VMS42 VMV42
TTL:;
	{object V396;
	V396= (VFUN_NARGS=0,(*(LnkLI212))());
	if(endp((V395))){
	goto T1045;}
	if(endp(cdr((V395)))){
	goto T1045;}
	if(!(endp(cddr((V395))))){
	goto T1044;}
T1045:;
	V397 = make_fixnum(length((V395)));
	(void)((*(LnkLI213))(VV[151],small_fixnum(3),V397));
T1044:;
	if(endp(cdddr((V395)))){
	goto T1051;}
	V398 = make_fixnum(length((V395)));
	(void)((*(LnkLI213))(VV[151],small_fixnum(3),V398));
T1051:;
	{object V399= cadr((V395));
	if(!(type_of(V399)==t_fixnum||
type_of(V399)==t_bignum||
type_of(V399)==t_ratio||
type_of(V399)==t_shortfloat||
type_of(V399)==t_longfloat||
type_of(V399)==t_complex)){
	goto T1055;}}
	base[1]= small_fixnum(0);
	base[2]= cadr((V395));
	base[3]= small_fixnum(10);
	vs_top=(vs_base=base+1)+3;
	Lmonotonically_nondecreasing();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T1055;}
	{register object V400;
	object V401;
	vs_base=vs_top;
	Lgensym();
	vs_top=sup;
	V400= vs_base[0];
	vs_base=vs_top;
	Lgensym();
	vs_top=sup;
	V401= vs_base[0];
	V402= list(2,(V400),car((V395)));
	V403= list(2,/* INLINE-ARGS */V402,list(2,(V401),caddr((V395))));
	V404= list(3,VV[152],(V400),list(3,VV[153],cadr((V395)),(V400)));
	V405= list(5,VV[29],/* INLINE-ARGS */V403,/* INLINE-ARGS */V404,list(3,VV[152],list(2,VV[61],(V400)),(V401)),(V401));
	{object V406 = (*(LnkLI239))(/* INLINE-ARGS */V405);
	VMR42(V406)}}
T1055:;
	{object V407 = list(4,VV[4],(V396),VV[151],(*(LnkLI223))((V395),(V396)));
	VMR42(V407)}}
}
/*	local entry for function FAST-READ	*/

static object LI43(V410,V411)

register object V410;object V411;
{	 VMB43 VMS43 VMV43
TTL:;
	if((symbol_value(VV[25]))!=Cnil){
	goto T1065;}
	if(!(number_compare(symbol_value(VV[154]),small_fixnum(2))<0)){
	goto T1065;}
	if((cadr((V410)))!=Cnil){
	goto T1065;}
	base[0]= VV[155];
	vs_top=(vs_base=base+0)+1;
	Lboundp();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T1065;}
	if(!(type_of(car((V410)))!=t_cons)){
	goto T1075;}{object V412;
	V412= car((V410));
	if(V412==Cnil)goto T1078;
	goto T1077;
T1078:;}
	V410= make_cons(VV[156],cdr((V410)));
T1077:;
	{object V413;
	object V414;
	V413= car((V410));
	V414= caddr((V410));
	V415= list(2,list(2,VV[157],list(2,VV[158],(V413))),VV[159]);
	V416= list(2,VV[162],list(3,(V411),(V413),(V414)));
	V417= list(3,VV[50],VV[164],small_fixnum(-1));
	V418= list(2,list(3,VV[108],/* INLINE-ARGS */V417,list(2,VV[165],list(3,VV[86],VV[96],list(2,VV[158],list(3,VV[86],VV[166],(V413)))))),(V414));
	if(!(((V411))==(VV[167]))){
	goto T1085;}
	V419= VV[168];
	goto T1083;
T1085:;
	V419= VV[164];
T1083:;
	{object V420 = list(4,VV[29],/* INLINE-ARGS */V415,VV[160],list(3,VV[161],/* INLINE-ARGS */V416,list(3,Ct,VV[163],list(3,VV[161],/* INLINE-ARGS */V418,list(2,Ct,V419)))));
	VMR43(V420)}}
T1075:;
	V421= list(2,VV[169],car((V410)));
	V422= make_cons(/* INLINE-ARGS */V421,Cnil);
	V423= (*(LnkLI243))(car((V410)));
	V424= list(2,VV[106],list(3,VV[107],/* INLINE-ARGS */V423,VV[169]));
	V425= make_cons(VV[169],cdr((V410)));
	{object V426 = list(4,VV[29],/* INLINE-ARGS */V422,/* INLINE-ARGS */V424,(*(LnkLI253))(/* INLINE-ARGS */V425,(V411)));
	VMR43(V426)}
T1065:;
	{object V427 = Cnil;
	VMR43(V427)}
}
/*	local entry for function CO1READ-BYTE	*/

static object LI44(V430,V431)

object V430;object V431;
{	 VMB44 VMS44 VMV44
	bds_check;
TTL:;
	{object V432;
	V432= Cnil;
	V432= (*(LnkLI253))((V431),VV[170]);
	if(((V432))==Cnil){
	goto T1090;}
	bds_bind(VV[154],small_fixnum(10));
	{object V433 = (*(LnkLI239))((V432));
	bds_unwind1;
	VMR44(V433)}
T1090:;
	{object V434 = Cnil;
	VMR44(V434)}}
}
/*	local entry for function CO1READ-CHAR	*/

static object LI45(V437,V438)

object V437;object V438;
{	 VMB45 VMS45 VMV45
	bds_check;
TTL:;
	{object V439;
	V439= Cnil;
	V439= (*(LnkLI253))((V438),VV[167]);
	if(((V439))==Cnil){
	goto T1096;}
	bds_bind(VV[154],small_fixnum(10));
	{object V440 = (*(LnkLI239))((V439));
	bds_unwind1;
	VMR45(V440)}
T1096:;
	{object V441 = Cnil;
	VMR45(V441)}}
}
/*	local entry for function CFAST-WRITE	*/

static object LI46(V444,V445)

object V444;object V445;
{	 VMB46 VMS46 VMV46
TTL:;
	if((symbol_value(VV[25]))!=Cnil){
	goto T1100;}
	if(!(number_compare(symbol_value(VV[154]),small_fixnum(2))<0)){
	goto T1100;}
	base[0]= VV[155];
	vs_top=(vs_base=base+0)+1;
	Lboundp();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T1100;}
	{register object V446;
	V446= cadr((V444));
	if((V446)!=Cnil){
	goto T1108;}
	V446= VV[171];
T1108:;
	if(!(type_of((V446))!=t_cons)){
	goto T1111;}
	V447= list(2,VV[157],list(2,VV[158],(V446)));
	V448= make_cons(/* INLINE-ARGS */V447,Cnil);
	{object V449 = list(4,VV[29],/* INLINE-ARGS */V448,VV[172],list(3,VV[161],list(2,VV[173],list(3,(V445),VV[174],(V446))),VV[175]));
	VMR46(V449)}
T1111:;
	V450= list(2,VV[176],(V446));
	V451= make_cons(/* INLINE-ARGS */V450,Cnil);
	V452= (*(LnkLI243))((V446));
	V453= list(2,VV[106],list(3,VV[107],/* INLINE-ARGS */V452,VV[176]));
	V454= list(2,VV[174],VV[176]);
	{object V455 = list(4,VV[29],/* INLINE-ARGS */V451,/* INLINE-ARGS */V453,(*(LnkLI254))(/* INLINE-ARGS */V454,(V445)));
	VMR46(V455)}}
T1100:;
	{object V456 = Cnil;
	VMR46(V456)}
}
/*	local entry for function CO1WRITE-BYTE	*/

static object LI47(V459,V460)

object V459;register object V460;
{	 VMB47 VMS47 VMV47
	bds_check;
TTL:;
	{object V461;
	V461= (*(LnkLI254))((V460),VV[177]);
	if(((V461))==Cnil){
	goto T1116;}
	bds_bind(VV[154],small_fixnum(10));
	V462= list(2,VV[174],car((V460)));
	V463= make_cons(/* INLINE-ARGS */V462,Cnil);
	if(!(type_of(car((V460)))!=t_cons)){
	goto T1120;}
	V464= car((V460));
	goto T1118;
T1120:;
	V464= VV[174];
T1118:;
	V465= list(5,VV[29],/* INLINE-ARGS */V463,VV[178],(V461),V464);
	{object V466 = (*(LnkLI239))(/* INLINE-ARGS */V465);
	bds_unwind1;
	VMR47(V466)}
T1116:;
	{object V467 = Cnil;
	VMR47(V467)}}
}
/*	local entry for function CO1WRITE-CHAR	*/

static object LI48(V470,V471)

object V470;register object V471;
{	 VMB48 VMS48 VMV48
	bds_check;
TTL:;
	{object V472;
	V472= (*(LnkLI254))((V471),VV[179]);
	if(((V472))==Cnil){
	goto T1125;}
	bds_bind(VV[154],small_fixnum(10));
	V473= list(2,VV[174],car((V471)));
	V474= make_cons(/* INLINE-ARGS */V473,Cnil);
	if(!(type_of(car((V471)))!=t_cons)){
	goto T1129;}
	V475= car((V471));
	goto T1127;
T1129:;
	V475= VV[174];
T1127:;
	V476= list(5,VV[29],/* INLINE-ARGS */V474,VV[180],(V472),V475);
	{object V477 = (*(LnkLI239))(/* INLINE-ARGS */V476);
	bds_unwind1;
	VMR48(V477)}
T1125:;
	{object V478 = Cnil;
	VMR48(V478)}}
}
/*	local entry for function AET-C-TYPE	*/

static object LI49(V480)

object V480;
{	 VMB49 VMS49 VMV49
TTL:;
	{object V481= (V480);
	if((V481!= Ct))goto T1131;
	{object V482 = VV[181];
	VMR49(V482)}
T1131:;
	if((V481!= VV[118])
	&& (V481!= VV[255]))goto T1132;
	{object V483 = VV[182];
	VMR49(V483)}
T1132:;
	if((V481!= VV[96]))goto T1133;
	{object V484 = VV[183];
	VMR49(V484)}
T1133:;
	if((V481!= VV[256]))goto T1134;
	{object V485 = VV[184];
	VMR49(V485)}
T1134:;
	if((V481!= VV[257]))goto T1135;
	{object V486 = VV[185];
	VMR49(V486)}
T1135:;
	if((V481!= VV[258]))goto T1136;
	{object V487 = VV[186];
	VMR49(V487)}
T1136:;
	if((V481!= VV[257]))goto T1137;
	{object V488 = VV[187];
	VMR49(V488)}
T1137:;
	if((V481!= VV[259]))goto T1138;
	{object V489 = VV[188];
	VMR49(V489)}
T1138:;
	if((V481!= VV[260]))goto T1139;
	{object V490 = VV[189];
	VMR49(V490)}
T1139:;
	FEerror("The ECASE key value ~s is illegal.",1,V481);}
}
/*	local entry for function CO1VECTOR-PUSH	*/

static object LI50(V493,V494)

object V493;register object V494;
{	 VMB50 VMS50 VMV50
	bds_check;
TTL:;
	if((symbol_value(VV[25]))!=Cnil){
	goto T1142;}
	if(number_compare(symbol_value(VV[154]),small_fixnum(3))>0){
	goto T1142;}
	if((cdr((V494)))==Cnil){
	goto T1142;}
	bds_bind(VV[154],small_fixnum(10));
	V495= list(2,VV[191],car((V494)));
	V496= listA(3,/* INLINE-ARGS */V495,list(2,VV[192],cadr((V494))),VV[193]);
	V497= (*(LnkLI243))(cadr((V494)));
	V498= list(2,VV[106],list(3,VV[107],/* INLINE-ARGS */V497,VV[192]));
	V499= (*(LnkLI243))(car((V494)));
	V500= list(2,VV[106],list(3,VV[107],/* INLINE-ARGS */V499,VV[191]));
	if(!(((V493))==(VV[196]))){
	goto T1150;}
	V501= listA(4,VV[196],VV[191],VV[192],cddr((V494)));
	goto T1148;
T1150:;
	V501= Cnil;
T1148:;
	V502= list(6,VV[190],/* INLINE-ARGS */V496,VV[194],/* INLINE-ARGS */V498,/* INLINE-ARGS */V500,list(3,VV[161],VV[195],list(2,Ct,V501)));
	{object V503 = (*(LnkLI239))(/* INLINE-ARGS */V502);
	bds_unwind1;
	VMR50(V503)}
T1142:;
	{object V504 = Cnil;
	VMR50(V504)}
}
/*	local entry for function CONSTANT-FOLD-P	*/

static object LI51(V506)

register object V506;
{	 VMB51 VMS51 VMV51
TTL:;
	base[0]= (V506);
	vs_top=(vs_base=base+0)+1;
	Lconstantp();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T1153;}
	{object V507 = Ct;
	VMR51(V507)}
T1153:;
	if(!(type_of((V506))!=t_cons)){
	goto T1157;}
	{object V508 = Cnil;
	VMR51(V508)}
T1157:;
	if(!((car((V506)))==(VV[86]))){
	goto T1160;}
	V506= caddr((V506));
	goto TTL;
T1160:;
	if(!(type_of(car((V506)))==t_symbol)){
	goto T1165;}
	V509= get(car((V506)),VV[197],Cnil);
	if(!((V509)==(VV[198]))){
	goto T1165;}
	{register object V510;
	register object V511;
	V510= cdr((V506));
	V511= car((V510));
T1174:;
	if(!(endp((V510)))){
	goto T1175;}
	goto T1170;
T1175:;{object V512;
	V512= (*(LnkLI261))((V511));
	if(V512==Cnil)goto T1180;
	goto T1179;
T1180:;}
	{object V513 = Cnil;
	VMR51(V513)}
T1179:;
	V510= cdr((V510));
	V511= car((V510));
	goto T1174;}
T1170:;
	{object V514 = Ct;
	VMR51(V514)}
T1165:;
	{object V515 = Cnil;
	VMR51(V515)}
}
/*	local entry for function CO1CONSTANT-FOLD	*/

static object LI52(V518,V519)

object V518;object V519;
{	 VMB52 VMS52 VMV52
TTL:;
	base[0]= (V518);
	vs_top=(vs_base=base+0)+1;
	Lfboundp();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T1188;}
	{register object V520;
	register object V521;
	V520= (V519);
	V521= car((V520));
T1196:;
	if(!(endp((V520)))){
	goto T1197;}
	goto T1192;
T1197:;{object V522;
	V522= (*(LnkLI261))((V521));
	if(V522==Cnil)goto T1202;
	goto T1201;
T1202:;}
	{object V523 = Cnil;
	VMR52(V523)}
T1201:;
	V520= cdr((V520));
	V521= car((V520));
	goto T1196;}
T1192:;
	base[0]= make_cons((V518),(V519));
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk262)();
	vs_top=sup;
	V524= vs_base[0];
	{object V525 = (*(LnkLI239))(V524);
	VMR52(V525)}
T1188:;
	{object V526 = Cnil;
	VMR52(V526)}
}
/*	local entry for function CO1SPECIAL-FIX-DECL	*/

static object LI53(V529,V530)

object V529;register object V530;
{	 VMB53 VMS53 VMV53
TTL:;
	{object V532= (V529);
	if((V532!= VV[264])
	&& (V532!= VV[265]))goto T1212;
	V533= car((V530));
	V534= cadr((V530));
	base[0]= cddr((V530));
	vs_top=(vs_base=base+0)+1;
	L54(base);
	vs_top=sup;
	V535= vs_base[0];
	V531= listA(4,(V529),/* INLINE-ARGS */V533,/* INLINE-ARGS */V534,V535);
	goto T1211;
T1212:;
	if((V532!= VV[266])
	&& (V532!= VV[267]))goto T1215;
	V536= car((V530));
	base[0]= cdr((V530));
	vs_top=(vs_base=base+0)+1;
	L54(base);
	vs_top=sup;
	V537= vs_base[0];
	V531= listA(3,(V529),/* INLINE-ARGS */V536,V537);
	goto T1211;
T1215:;
	V531= Cnil;}
T1211:;
	V538= (*(LnkLI263))(V531);
	{object V539 = (*(LnkLI239))(/* INLINE-ARGS */V538);
	VMR53(V539)}
}
/*	local entry for function CO1SUBLIS	*/

static object LI55(V542,V543)

object V542;register object V543;
{	 VMB54 VMS54 VMV54
TTL:;
	{register object V544;
	V544= Cnil;switch(length((V543))){
	case 2:
T1223:;
	V544= VV[50];
	if((VV[50])!=Cnil){
	goto T1220;}
	goto T1221;
	case 4:
T1224:;
	if((caddr((V543)))==(VV[51])){
	goto T1227;}
	goto T1221;
T1227:;
	{register object x= cadddr((V543)),V545= VV[199];
	while(!endp(V545))
	if(eql(x,V545->c.c_car)){
	goto T1231;
	}else V545=V545->c.c_cdr;
	goto T1230;}
T1231:;
	V544= VV[200];
	if((VV[200])!=Cnil){
	goto T1220;}
	goto T1221;
T1230:;
	{register object x= cadddr((V543)),V546= VV[201];
	while(!endp(V546))
	if(eql(x,V546->c.c_car)){
	goto T1235;
	}else V546=V546->c.c_cdr;
	goto T1234;}
T1235:;
	V544= VV[50];
	if((VV[50])!=Cnil){
	goto T1220;}
	goto T1221;
T1234:;
	{register object x= cadddr((V543)),V547= VV[202];
	while(!endp(V547))
	if(eql(x,V547->c.c_car)){
	goto T1239;
	}else V547=V547->c.c_cdr;
	goto T1238;}
T1239:;
	V544= VV[48];
	if((VV[48])!=Cnil){
	goto T1220;}
	goto T1221;
T1238:;
	goto T1221;
	default:
T1225:;
	goto T1221;}
T1221:;
	{object V548 = Cnil;
	VMR54(V548)}
T1220:;
	{object V549;
	vs_base=vs_top;
	Lgensym();
	vs_top=sup;
	V549= vs_base[0];
	V550= list(2,(V549),car((V543)));
	V551= make_cons(/* INLINE-ARGS */V550,Cnil);
	V552= cadr((V543));
	V553= list(3,VV[29],/* INLINE-ARGS */V551,list(4,VV[203],(V549),/* INLINE-ARGS */V552,list(2,VV[113],(V544))));
	{object V554 = (*(LnkLI239))(/* INLINE-ARGS */V553);
	VMR54(V554)}}}
}
/*	local entry for function SUBLIS1-INLINE	*/

static object LI56(V558,V559,V560)

object V558;object V559;object V560;
{	 VMB55 VMS55 VMV55
TTL:;
	{object V561;
	V562= (VFUN_NARGS=4,(*(LnkLI268))(cadr((V560)),symbol_value(VV[204]),VV[205],VV[105]));
	V561= car(/* INLINE-ARGS */V562);{object V563;
	{register object x= (V561),V564= VV[206];
	while(!endp(V564))
	if(eql(x,V564->c.c_car)){
	V563= V564;
	goto T1245;
	}else V564=V564->c.c_cdr;
	V563= Cnil;}
T1245:;
	if(V563==Cnil)goto T1244;
	goto T1243;
T1244:;}
	base[0]= VV[207];
	vs_top=(vs_base=base+0)+1;
	Lerror();
	vs_top=sup;
T1243:;
	princ_str("(check_alist(",VV[7]);
	(void)((*(LnkLI217))((V558)));
	princ_str("),sublis1(",VV[7]);
	(void)((*(LnkLI217))((V558)));
	princ_char(44,VV[7]);
	(void)((*(LnkLI217))((V559)));
	princ_char(44,VV[7]);
	base[0]= Cnil;
	base[1]= VV[208];
	base[2]= (V561);
	vs_top=(vs_base=base+0)+3;
	Lformat();
	vs_top=sup;
	V565= vs_base[0];
	(void)((*(LnkLI217))(V565));
	{object V566 = Cnil;
	VMR55(V566)}}
}
/*	local entry for function C1LIST-NTH	*/

static object LI57(V568)

register object V568;
{	 VMB56 VMS56 VMV56
TTL:;
	{register object V569;
	V569= (VFUN_NARGS=0,(*(LnkLI212))());
	if(endp((V568))){
	goto T1261;}
	if(!(endp(cdr((V568))))){
	goto T1260;}
T1261:;
	V570 = make_fixnum(length((V568)));
	(void)((*(LnkLI213))(VV[151],small_fixnum(2),V570));
T1260:;
	if(endp(cddr((V568)))){
	goto T1265;}
	V571 = make_fixnum(length((V568)));
	(void)((*(LnkLI213))(VV[151],small_fixnum(2),V571));
T1265:;
	{object V572= car((V568));
	if(!(type_of(V572)==t_fixnum||
type_of(V572)==t_bignum||
type_of(V572)==t_ratio||
type_of(V572)==t_shortfloat||
type_of(V572)==t_longfloat||
type_of(V572)==t_complex)){
	goto T1269;}}
	base[1]= small_fixnum(0);
	base[2]= car((V568));
	base[3]= small_fixnum(10);
	vs_top=(vs_base=base+1)+3;
	Lmonotonically_nondecreasing();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T1269;}
	V573= car((V568));
	V574= make_cons(cadr((V568)),Cnil);
	{object V575 = list(4,VV[209],(V569),/* INLINE-ARGS */V573,(*(LnkLI223))(/* INLINE-ARGS */V574,(V569)));
	VMR56(V575)}
T1269:;
	{object V576 = list(4,VV[4],(V569),VV[210],(*(LnkLI223))((V568),(V569)));
	VMR56(V576)}}
}
/*	local entry for function C2LIST-NTH-IMMEDIATE	*/

static object LI58(V579,V580)

object V579;object V580;
{	 VMB57 VMS57 VMV57
	bds_check;
TTL:;
	{object V581;
	setq(VV[22],number_plus(symbol_value(VV[22]),small_fixnum(1)));
	V581= symbol_value(VV[22]);
	bds_bind(VV[20],symbol_value(VV[20]));
	bds_bind(VV[42],small_fixnum(0));
	V580= (VFUN_NARGS=2,(*(LnkLI236))((V580),VV[211]));
	princ_str("\n	{object V",VV[7]);
	(void)((*(LnkLI217))((V581)));
	princ_str("= ",VV[7]);
	if((symbol_value(VV[25]))==Cnil){
	goto T1286;}
	{register int V582;
	register int V583;
	V582= fix((V579));
	V583= 0;
T1292:;
	if(!((V583)>=(V582))){
	goto T1293;}
	goto T1288;
T1293:;
	princ_str("cdr(",VV[7]);
	V583= (V583)+1;
	goto T1292;}
T1288:;
	(void)((*(LnkLI217))(car((V580))));
	{register int V584;
	register int V585;
	V584= fix((V579));
	V585= 0;
T1308:;
	if(!((V585)>=(V584))){
	goto T1309;}
	goto T1304;
T1309:;
	princ_char(41,VV[7]);
	V585= (V585)+1;
	goto T1308;}
T1304:;
	princ_char(59,VV[7]);
	princ_str("\n	if((type_of(V",VV[7]);
	(void)((*(LnkLI217))((V581)));
	princ_str(")!=t_cons) && (",VV[7]);
	(void)((*(LnkLI217))(car((V580))));
	princ_str("!= Cnil))",VV[7]);
	princ_str("\n	 FEwrong_type_argument(Scons,V",VV[7]);
	(void)((*(LnkLI217))((V581)));
	princ_str(");",VV[7]);
	goto T1284;
T1286:;
	princ_str("\n	",VV[7]);
	(void)((*(LnkLI217))(car((V580))));
	{register int V586;
	register int V587;
	V586= fix((V579));
	V587= 0;
T1336:;
	if(!((V587)>=(V586))){
	goto T1337;}
	goto T1332;
T1337:;
	princ_str("\n	->c.c_cdr",VV[7]);
	V587= (V587)+1;
	goto T1336;}
T1332:;
	princ_char(59,VV[7]);
T1284:;
	V588= list(2,VV[61],(V581));
	(void)((VFUN_NARGS=1,(*(LnkLI218))(/* INLINE-ARGS */V588)));
	princ_char(125,VV[7]);
	{object V589 = (*(LnkLI237))();
	bds_unwind1;
	bds_unwind1;
	VMR57(V589)}}
}
/*	local function FIXUP	*/

static L54(base0)
register object *base0;
{	register object *base=vs_base;
	register object *sup=base+VM58; VC58
	vs_reserve(VM58);
	{register object V590;
	check_arg(1);
	V590=(base[0]);
	vs_top=sup;
TTL:;
	{register object V591;
	V591= Cnil;
T1352:;
	if(!(type_of((V590))==t_cons)){
	goto T1355;}
	goto T1354;
T1355:;
	goto T1353;
T1354:;
	{register object V592;
	V592= car((V590));
	if(!(type_of((V592))==t_cons)){
	goto T1360;}
	V592= (*(LnkLI263))((V592));
	if(((V592))==Cnil){
	goto T1360;}
	if(!((car((V592)))==(VV[106]))){
	goto T1360;}
	V591= make_cons((V592),(V591));
	{register object V593;
	V593= car((V590));
	V590= cdr((V590));
	goto T1357;}
T1360:;
	goto T1353;}
T1357:;
	goto T1352;
T1353:;
	V594= nreverse((V591));
	base[1]= nconc(/* INLINE-ARGS */V594,(V590));
	vs_top=(vs_base=base+1)+1;
	return;
	base[1]= Cnil;
	vs_top=(vs_base=base+1)+1;
	return;}
	}
}
static object  LnkTLI268(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[268],&LnkLI268,ap);} /* FIND */
static object  LnkTLI263(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[263],&LnkLI263,1,ap);} /* CMP-MACROEXPAND */
static LnkT262(){ call_or_link(VV[262],&Lnk262);} /* CMP-EVAL */
static object  LnkTLI261(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[261],&LnkLI261,1,ap);} /* CONSTANT-FOLD-P */
static object  LnkTLI254(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[254],&LnkLI254,2,ap);} /* CFAST-WRITE */
static object  LnkTLI253(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[253],&LnkLI253,2,ap);} /* FAST-READ */
static object  LnkTLI252(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[252],&LnkLI252,1,ap);} /* CONS-TO-LISTA */
static object  LnkTLI251(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[251],&LnkLI251,1,ap);} /* NAME-SD1 */
static object  LnkTLI250(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[250],&LnkLI250,1,ap);} /* GET-INCLUDED */
static object  LnkTLI249(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[249],&LnkLI249,2,ap);} /* STRUCT-TYPE-OPT */
static object  LnkTLI248(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[248],&LnkLI248,1,ap);} /* NORMALIZE-TYPE */
static object  LnkTLI247(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[247],&LnkLI247,ap);} /* POSITION */
static object  LnkTLI246(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[246],&LnkLI246,1,ap);} /* BEST-ARRAY-ELEMENT-TYPE */
static object  LnkTLI245(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[245],&LnkLI245,1,ap);} /* TYPE-FILTER */
static object  LnkTLI244(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[244],&LnkLI244,1,ap);} /* REPLACE-CONSTANT */
static object  LnkTLI243(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[243],&LnkLI243,1,ap);} /* RESULT-TYPE */
static LnkT242(){ call_or_link(VV[242],&Lnk242);} /* FIXNUMP */
static LnkT241(){ call_or_link(VV[241],&Lnk241);} /* SUBTYPEP */
static LnkT240(){ call_or_link(VV[240],&Lnk240);} /* WT-INLINE-LOC */
static object  LnkTLI239(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[239],&LnkLI239,1,ap);} /* C1EXPR */
static object  LnkTLI238(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[238],&LnkLI238,1,ap);} /* INLINE-BOOLE3-STRING */
static object  LnkTLI237(){return call_proc0(VV[237],&LnkLI237);} /* CLOSE-INLINE-BLOCKS */
static object  LnkTLI236(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[236],&LnkLI236,ap);} /* INLINE-ARGS */
static object  LnkTLI235(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[235],&LnkLI235,2,ap);} /* ADD-INFO */
static LnkT234(){ call_or_link(VV[234],&Lnk234);} /* C2EXPR */
static object  LnkTLI233(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[233],&LnkLI233,1,ap);} /* C2BIND */
static object  LnkTLI232(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[232],&LnkLI232,1,ap);} /* WT-VS */
static object  LnkTLI231(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[231],&LnkLI231,2,ap);} /* WT-VAR */
static object  LnkTLI230(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[230],&LnkLI230,ap);} /* MAKE-VAR */
static object  LnkTLI229(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[229],&LnkLI229,ap);} /* CMPERR */
static object  LnkTLI228(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[228],&LnkLI228,ap);} /* C2FUNCALL */
static object  LnkTLI227(){return call_proc0(VV[227],&LnkLI227);} /* VS-PUSH */
static object  LnkTLI226(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[226],&LnkLI226,1,ap);} /* C2EXPR* */
static object  LnkTLI225(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[225],&LnkLI225,1,ap);} /* SAVE-FUNOB */
static object  LnkTLI224(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[224],&LnkLI224,5,ap);} /* C1APPLY-OPTIMIZE */
static object  LnkTLI223(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[223],&LnkLI223,2,ap);} /* C1ARGS */
static LnkT222(){ call_or_link(VV[222],&Lnk222);} /* COPY-INFO */
static object  LnkTLI221(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[221],&LnkLI221,1,ap);} /* C1FUNOB */
static object  LnkTLI220(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[220],&LnkLI220,1,ap);} /* ADD-OBJECT */
static object  LnkTLI219(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[219],&LnkLI219,4,ap);} /* C2CALL-GLOBAL */
static object  LnkTLI218(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[218],&LnkLI218,ap);} /* UNWIND-EXIT */
static object  LnkTLI217(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[217],&LnkLI217,1,ap);} /* WT1 */
static object  LnkTLI216(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[216],&LnkLI216,2,ap);} /* C1EXPR* */
static object  LnkTLI215(){return call_proc0(VV[215],&LnkLI215);} /* C1NIL */
static object  LnkTLI214(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[214],&LnkLI214,3,ap);} /* TOO-MANY-ARGS */
static object  LnkTLI213(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[213],&LnkLI213,3,ap);} /* TOO-FEW-ARGS */
static object  LnkTLI212(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[212],&LnkLI212,ap);} /* MAKE-INFO */
