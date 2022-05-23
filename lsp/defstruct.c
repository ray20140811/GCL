
#include <cmpinclude.h>
#include "defstruct.h"
init_defstruct(){do_init(VV);}
/*	local entry for function MAKE-ACCESS-FUNCTION	*/

static object LI1(V11,V10,V9,V8,V7,V6,V5,V4,V3,V2,V1,va_alist)
	object V11,V10,V9,V8,V7,V6,V5,V4,V3,V2,V1;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB1 VMS1 VMV1
	{object V12;
	object V13;
	object V14;
	object V15;
	object V16;
	object V17;
	object V18;
	object V19;
	object V20;
	object V21;
	object V22;
	if(narg <11) too_few_arguments();
	V12= V11;
	V13= V10;
	V14= V9;
	V15= V8;
	V16= V7;
	V17= V6;
	V18= V5;
	V19= V4;
	V20= V3;
	V21= V2;
	Vcs[10]=MMcons(V1,Cnil);
	narg = narg - 11;
	if (narg <= 0) goto T1;
	else {
	va_start(ap);
	V22= va_arg(ap,object);}
	--narg; goto T2;
T1:;
	V22= Cnil;
T2:;
	{register object V23;
	register object V24;
	object V25;
	base[1]= coerce_to_string((V13));
	base[2]= coerce_to_string((V18));
	vs_top=(vs_base=base+1)+2;
	(void) (*Lnk106)();
	vs_top=sup;
	base[0]= vs_base[0];
	vs_top=(vs_base=base+0)+1;
	Lintern();
	vs_top=sup;
	V23= vs_base[0];
	V24= Cnil;
	V25= Cnil;
	{object V26= (V14);
	if((V26!= Cnil))goto T9;
	V24= symbol_value(VV[0]);
	goto T8;
T9:;
	if((V26!= VV[20]))goto T11;
	V24= symbol_value(VV[1]);
	goto T8;
T11:;
	if((V26!= VV[19]))goto T13;
	V24= symbol_value(VV[2]);
	goto T8;
T13:;
	FEerror("The ECASE key value ~s is illegal.",1,V26);}
T8:;
	V27 = make_fixnum(length((V24)));
	if(!(number_compare(V27,(Vcs[10]->c.c_car))>0)){
	goto T16;}
	goto T15;
T16:;
	V28= number_plus((Vcs[10]->c.c_car),small_fixnum(10));
	(void)((VFUN_NARGS=2,(*(LnkLI107))((V24),/* INLINE-ARGS */V28)));
T15:;
	if(((V25))!=Cnil){
	goto T18;}
	base[0]= (V23);
	base[1]= VV[3];
	base[2]= VV[4];
	base[3]= (V20);
	vs_top=(vs_base=base+0)+4;
	(void) (*Lnk108)();
	vs_top=sup;
	if((V17)!=Cnil){
	goto T18;}{object V29;
	base[0]= (V23);
	vs_top=(vs_base=base+0)+1;
	Lfboundp();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T28;}
	V29= Cnil;
	goto T27;
T28:;
	V30= aref1((V24),fixint((Vcs[10]->c.c_car)));
	base[0]= (V23);
	vs_top=(vs_base=base+0)+1;
	Lsymbol_function();
	vs_top=sup;
	V31= vs_base[0];
	V29= ((/* INLINE-ARGS */V30)==(V31)?Ct:Cnil);
T27:;
	if(V29==Cnil)goto T26;
	goto T18;
T26:;}
	base[0]= (V23);{object V32;
	V32= aref1((V24),fixint((Vcs[10]->c.c_car)));
	if(V32==Cnil)goto T35;
	base[1]= V32;
	goto T34;
T35:;}
	if(!(((V24))==(symbol_value(VV[0])))){
	goto T39;}
	V33= 
	make_cclosure_new(LC16,Cnil,Vcs[10],Cdata);
	goto T37;
T39:;
	if(!(((V24))==(symbol_value(VV[1])))){
	goto T42;}
	V33= 
	make_cclosure_new(LC17,Cnil,Vcs[10],Cdata);
	goto T37;
T42:;
	if(!(((V24))==(symbol_value(VV[2])))){
	goto T45;}
	V33= 
	make_cclosure_new(LC18,Cnil,Vcs[10],Cdata);
	goto T37;
T45:;
	V33= Cnil;
T37:;
	base[1]= aset1((V24),fixint((Vcs[10]->c.c_car)),V33);
T34:;
	vs_top=(vs_base=base+0)+2;
	siLfset();
	vs_top=sup;
T18:;
	if(((V21))==Cnil){
	goto T49;}
	(void)(remprop((V23),VV[6]));
	(void)(sputprop((V23),VV[7],Ct));
	goto T47;
T49:;
	(void)(remprop((V23),VV[8]));
	(void)(remprop((V23),VV[9]));
	(void)(remprop((V23),VV[10]));
	{object V34;
	V34= get((V23),VV[6],Cnil);
	if(!(type_of((V34))==t_cons)){
	goto T57;}
	if(((V16))==Cnil){
	goto T57;}
	base[0]= (V16);
	base[1]= car((V34));
	vs_top=(vs_base=base+0)+2;
	(void) (*Lnk109)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T57;}
	if(!(eql(cdr((V34)),(Vcs[10]->c.c_car)))){
	goto T57;}
	V25= Ct;
	goto T47;
T57:;
	if(((V14))==Cnil){
	goto T70;}
	V35= (V14);
	goto T68;
T70:;
	V35= (V12);
T68:;
	V36= make_cons(V35,(Vcs[10]->c.c_car));
	(void)(sputprop((V23),VV[6],/* INLINE-ARGS */V36));}
T47:;
	{object V37 = Cnil;
	VMR1(V37)}}}
	}
/*	local entry for function MAKE-CONSTRUCTOR	*/

static object LI2(V43,V44,V45,V46,V47)

object V43;object V44;object V45;object V46;object V47;
{	 VMB2 VMS2 VMV2
TTL:;
	{object V48;
	register object V49;
	{object V50;
	object V51= (V47);
	if(endp(V51)){
	V48= Cnil;
	goto T72;}
	base[0]=V50=MMcons(Cnil,Cnil);
T73:;
	if(((V51->c.c_car))!=Cnil){
	goto T76;}
	(V50->c.c_car)= Cnil;
	goto T74;
T76:;
	if((car((V51->c.c_car)))!=Cnil){
	goto T79;}
	(V50->c.c_car)= list(2,VV[11],cadr((V51->c.c_car)));
	goto T74;
T79:;
	(V50->c.c_car)= car((V51->c.c_car));
T74:;
	if(endp(V51=MMcdr(V51))){
	V48= base[0];
	goto T72;}
	V50=MMcdr(V50)=MMcons(Cnil,Cnil);
	goto T73;}
T72:;
	{object V53;
	object V54= (V47);
	if(endp(V54)){
	V49= Cnil;
	goto T81;}
	base[0]=V53=MMcons(Cnil,Cnil);
T82:;
	if(((V54->c.c_car))!=Cnil){
	goto T85;}
	(V53->c.c_cdr)= Cnil;
	goto T83;
T85:;
	if((car((V54->c.c_car)))!=Cnil){
	goto T88;}
	(V53->c.c_cdr)= Cnil;
	goto T83;
T88:;
	if((cadr((V54->c.c_car)))!=Cnil){
	goto T91;}
	(V53->c.c_cdr)= make_cons(car((V54->c.c_car)),Cnil);
	goto T83;
T91:;
	V56= list(2,car((V54->c.c_car)),cadr((V54->c.c_car)));
	(V53->c.c_cdr)= make_cons(/* INLINE-ARGS */V56,Cnil);
T83:;
	while(!endp(MMcdr(V53)))V53=MMcdr(V53);
	if(endp(V54=MMcdr(V54))){
	base[0]=base[0]->c.c_cdr;
	V49= base[0];
	goto T81;}
	goto T82;}
T81:;
	if(!(type_of((V44))==t_cons)){
	goto T95;}
	{register object V57;
	register object V58;
	register object V59;
	V57= cadr((V44));
	V58= Cnil;
	V59= Cnil;
T100:;
	if(!(endp((V57)))){
	goto T101;}
	base[0]= make_cons(VV[12],(V58));
	{object V60;
	object V61= (V49);
	if(endp(V61)){
	base[1]= Cnil;
	goto T106;}
	base[2]=V60=MMcons(Cnil,Cnil);
T107:;
	if(!(type_of((V61->c.c_car))!=t_cons)){
	goto T114;}
	V64= (V61->c.c_car);
	goto T112;
T114:;
	V64= car((V61->c.c_car));
T112:;
	{register object x= V64,V63= (V59);
	while(!endp(V63))
	if(eql(x,V63->c.c_car)){
	goto T111;
	}else V63=V63->c.c_cdr;
	goto T110;}
T111:;
	(V60->c.c_cdr)= Cnil;
	goto T108;
T110:;
	(V60->c.c_cdr)= make_cons((V61->c.c_car),Cnil);
T108:;
	while(!endp(MMcdr(V60)))V60=MMcdr(V60);
	if(endp(V61=MMcdr(V61))){
	base[2]=base[2]->c.c_cdr;
	base[1]= base[2];
	goto T106;}
	goto T107;}
T106:;
	vs_top=(vs_base=base+0)+2;
	Lreconc();
	vs_top=sup;
	V49= vs_base[0];
	goto T97;
T101:;
	{register object x= car((V57)),V65= VV[13];
	while(!endp(V65))
	if(eql(x,V65->c.c_car)){
	goto T119;
	}else V65=V65->c.c_cdr;
	goto T117;}
T119:;
	if(!((car((V57)))==(VV[14]))){
	goto T120;}
	goto T117;
T120:;
	V57= make_cons(VV[14],(V57));
T117:;
	if(!((car((V57)))==(VV[14]))){
	goto T125;}
	V58= make_cons(VV[14],(V58));
	{register object V66;
	object V67;
	object V68;
	V66= cdr((V57));
	V67= Cnil;
	V68= Cnil;
T132:;
	if(!(endp((V66)))){
	goto T133;}
	base[0]= make_cons(VV[12],(V58));
	{object V69;
	object V70= (V49);
	if(endp(V70)){
	base[1]= Cnil;
	goto T139;}
	base[2]=V69=MMcons(Cnil,Cnil);
T140:;
	if(!(type_of((V70->c.c_car))!=t_cons)){
	goto T147;}
	V73= (V70->c.c_car);
	goto T145;
T147:;
	V73= car((V70->c.c_car));
T145:;
	{register object x= V73,V72= (V59);
	while(!endp(V72))
	if(eql(x,V72->c.c_car)){
	goto T144;
	}else V72=V72->c.c_cdr;
	goto T143;}
T144:;
	(V69->c.c_cdr)= Cnil;
	goto T141;
T143:;
	(V69->c.c_cdr)= make_cons((V70->c.c_car),Cnil);
T141:;
	while(!endp(MMcdr(V69)))V69=MMcdr(V69);
	if(endp(V70=MMcdr(V70))){
	base[2]=base[2]->c.c_cdr;
	base[1]= base[2];
	goto T139;}
	goto T140;}
T139:;
	vs_top=(vs_base=base+0)+2;
	Lreconc();
	vs_top=sup;
	V49= vs_base[0];
	goto T129;
T133:;
	{register object x= car((V66)),V74= VV[13];
	while(!endp(V74))
	if(eql(x,V74->c.c_car)){
	goto T152;
	}else V74=V74->c.c_cdr;
	goto T150;}
T152:;
	if(!((car((V66)))==(VV[15]))){
	goto T153;}
	V58= make_cons(VV[15],(V58));
	V66= cdr((V66));
	if(endp((V66))){
	goto T161;}
	if(type_of(car((V66)))==t_symbol){
	goto T160;}
T161:;
	(void)((*(LnkLI110))());
T160:;
	V59= make_cons(car((V66)),(V59));
	V58= make_cons(car((V66)),(V58));
	V66= cdr((V66));
	if(!(endp((V66)))){
	goto T153;}
	base[0]= make_cons(VV[12],(V58));
	{object V75;
	object V76= (V49);
	if(endp(V76)){
	base[1]= Cnil;
	goto T176;}
	base[2]=V75=MMcons(Cnil,Cnil);
T177:;
	if(!(type_of((V76->c.c_car))!=t_cons)){
	goto T184;}
	V79= (V76->c.c_car);
	goto T182;
T184:;
	V79= car((V76->c.c_car));
T182:;
	{register object x= V79,V78= (V59);
	while(!endp(V78))
	if(eql(x,V78->c.c_car)){
	goto T181;
	}else V78=V78->c.c_cdr;
	goto T180;}
T181:;
	(V75->c.c_cdr)= Cnil;
	goto T178;
T180:;
	(V75->c.c_cdr)= make_cons((V76->c.c_car),Cnil);
T178:;
	while(!endp(MMcdr(V75)))V75=MMcdr(V75);
	if(endp(V76=MMcdr(V76))){
	base[2]=base[2]->c.c_cdr;
	base[1]= base[2];
	goto T176;}
	goto T177;}
T176:;
	vs_top=(vs_base=base+0)+2;
	Lreconc();
	vs_top=sup;
	V49= vs_base[0];
	goto T129;
T153:;
	if((car((V66)))==(VV[12])){
	goto T186;}
	(void)((*(LnkLI110))());
T186:;
	V58= make_cons(VV[12],(V58));
	{register object V80;
	V80= cdr((V66));
T194:;
	if(!(endp((V80)))){
	goto T195;}
	goto T191;
T195:;
	V58= make_cons(car((V80)),(V58));
	if(!(type_of(car((V80)))!=t_cons)){
	goto T203;}
	if(!(type_of(car((V80)))==t_symbol)){
	goto T203;}
	V59= make_cons(car((V80)),(V59));
	goto T201;
T203:;
	if(!(type_of(caar((V80)))==t_symbol)){
	goto T209;}
	if(endp(cdar((V80)))){
	goto T208;}
	if(!(endp(cddar((V80))))){
	goto T209;}
T208:;
	V59= make_cons(caar((V80)),(V59));
	goto T201;
T209:;
	(void)((*(LnkLI110))());
T201:;
	V80= cdr((V80));
	goto T194;}
T191:;
	base[0]= (V58);
	{object V81;
	object V82= (V49);
	if(endp(V82)){
	base[1]= Cnil;
	goto T222;}
	base[2]=V81=MMcons(Cnil,Cnil);
T223:;
	if(!(type_of((V82->c.c_car))!=t_cons)){
	goto T230;}
	V85= (V82->c.c_car);
	goto T228;
T230:;
	V85= car((V82->c.c_car));
T228:;
	{register object x= V85,V84= (V59);
	while(!endp(V84))
	if(eql(x,V84->c.c_car)){
	goto T227;
	}else V84=V84->c.c_cdr;
	goto T226;}
T227:;
	(V81->c.c_cdr)= Cnil;
	goto T224;
T226:;
	(V81->c.c_cdr)= make_cons((V82->c.c_car),Cnil);
T224:;
	while(!endp(MMcdr(V81)))V81=MMcdr(V81);
	if(endp(V82=MMcdr(V82))){
	base[2]=base[2]->c.c_cdr;
	base[1]= base[2];
	goto T222;}
	goto T223;}
T222:;
	vs_top=(vs_base=base+0)+2;
	Lreconc();
	vs_top=sup;
	V49= vs_base[0];
	goto T129;
T150:;
	if(!(type_of(car((V66)))!=t_cons)){
	goto T238;}
	V67= car((V66));
	goto T236;
T238:;
	if(!(endp(cdar((V66))))){
	goto T243;}
	V67= caar((V66));
	goto T236;
T243:;
	goto T234;
T236:;
	base[0]= (V67);
	base[1]= (V49);
	base[2]= VV[16];
	base[3]= VV[111];
	vs_top=(vs_base=base+0)+4;
	Lmember();
	vs_top=sup;
	V68= vs_base[0];
	if(((V68))==Cnil){
	goto T234;}
	V58= make_cons(car((V68)),(V58));
	goto T232;
T234:;
	V58= make_cons(car((V66)),(V58));
T232:;
	if(!(type_of(car((V66)))!=t_cons)){
	goto T257;}
	if(type_of(car((V66)))==t_symbol){
	goto T259;}
	(void)((*(LnkLI110))());
T259:;
	V59= make_cons(car((V66)),(V59));
	goto T255;
T257:;
	if(type_of(caar((V66)))==t_symbol){
	goto T264;}
	(void)((*(LnkLI110))());
	goto T255;
T264:;
	if(endp(cdar((V66)))){
	goto T266;}
	if(!(endp(cddar((V66))))){
	goto T267;}
T266:;
	V59= make_cons(caar((V66)),(V59));
	goto T255;
T267:;
	if(type_of(caddar((V66)))==t_symbol){
	goto T273;}
	(void)((*(LnkLI110))());
	goto T255;
T273:;
	if(endp(cdddar((V66)))){
	goto T276;}
	(void)((*(LnkLI110))());
	goto T255;
T276:;
	V59= make_cons(caar((V66)),(V59));
	V59= make_cons(caddar((V66)),(V59));
T255:;
	V66= cdr((V66));
	goto T132;}
T129:;
	goto T97;
T125:;
	if(type_of(car((V57)))==t_symbol){
	goto T284;}
	(void)((*(LnkLI110))());
T284:;
	V58= make_cons(car((V57)),(V58));
	V59= make_cons(car((V57)),(V59));
	V57= cdr((V57));
	goto T100;}
T97:;
	V44= car((V44));
	goto T93;
T95:;
	V49= make_cons(VV[17],(V49));
T93:;
	if(((V45))!=Cnil){
	goto T296;}
	{object V86 = list(4,VV[3],(V44),(V49),listA(3,VV[18],list(2,VV[11],(V43)),(V48)));
	VMR2(V86)}
T296:;
	if(((V45))==(VV[19])){
	goto T298;}
	if(!(type_of((V45))==t_cons)){
	goto T299;}
	if(!((car((V45)))==(VV[19]))){
	goto T299;}
T298:;
	{object V87 = list(4,VV[3],(V44),(V49),make_cons(VV[19],(V48)));
	VMR2(V87)}
T299:;
	if(!(((V45))==(VV[20]))){
	goto T306;}
	{object V88 = list(4,VV[3],(V44),(V49),make_cons(VV[20],(V48)));
	VMR2(V88)}
T306:;
	{object V89;
	base[0]= VV[21];
	base[1]= (V45);
	vs_top=(vs_base=base+0)+2;
	Lerror();
	vs_top=sup;
	V89= vs_base[0];
	if(((V89))==Cnil){
	goto T312;}
	{object V90 = (V89);
	VMR2(V90)}
T312:;
	{object V91 = Cnil;
	VMR2(V91)}}}
}
/*	local entry for function ILLEGAL-BOA	*/

static object LI3()

{	 VMB3 VMS3 VMV3
TTL:;
	base[0]= VV[22];
	vs_top=(vs_base=base+0)+1;
	Lerror();
	vs_top=sup;
	{object V92 = vs_base[0];
	VMR3(V92)}
}
/*	local entry for function MAKE-PREDICATE	*/

static object LI4(V98,V99,V100,V101,V102)

object V98;object V99;register object V100;object V101;register object V102;
{	 VMB4 VMS4 VMV4
TTL:;
	{object V103;
	V103= (((V100))==Cnil?Ct:Cnil);
	if(((V103))==Cnil){
	goto T317;}
	{object V104 = (V103);
	VMR4(V104)}
T317:;
	if(((V100))==(VV[19])){
	goto T319;}
	if(!(type_of((V100))==t_cons)){
	goto T320;}
	if(!((car((V100)))==(VV[19]))){
	goto T320;}
T319:;
	if(((V101))!=Cnil){
	goto T326;}
	base[0]= VV[23];
	vs_top=(vs_base=base+0)+1;
	Lerror();
	vs_top=sup;
T326:;
	V105= list(3,VV[27],VV[28],(V102));
	V106= list(3,VV[30],VV[31],(V102));
	{object V107 = list(4,VV[3],(V99),VV[24],list(4,VV[25],VV[26],/* INLINE-ARGS */V105,list(3,VV[29],/* INLINE-ARGS */V106,list(2,VV[11],(V98)))));
	VMR4(V107)}
T320:;
	if(!(((V100))==(VV[20]))){
	goto T331;}
	if(((V101))!=Cnil){
	goto T333;}
	base[0]= VV[32];
	vs_top=(vs_base=base+0)+1;
	Lerror();
	vs_top=sup;
T333:;
	if(!(number_compare((V102),small_fixnum(0))==0)){
	goto T338;}
	{object V108 = list(4,VV[3],(V99),VV[33],list(3,VV[25],VV[34],list(3,VV[29],VV[35],list(2,VV[11],(V98)))));
	VMR4(V108)}
T338:;
	V109= list(2,list(3,VV[38],(V102),VV[39]),VV[40]);
	{object V110 = list(4,VV[3],(V99),VV[36],listA(4,VV[37],/* INLINE-ARGS */V109,list(2,VV[41],list(3,VV[25],VV[42],list(3,VV[29],VV[43],list(2,VV[11],(V98))))),VV[44]));
	VMR4(V110)}
T331:;
	{object V111;
	base[0]= VV[45];
	vs_top=(vs_base=base+0)+1;
	Lerror();
	vs_top=sup;
	V111= vs_base[0];
	if(((V111))==Cnil){
	goto T343;}
	{object V112 = (V111);
	VMR4(V112)}
T343:;
	{object V113 = Cnil;
	VMR4(V113)}}}
}
/*	local entry for function PARSE-SLOT-DESCRIPTION	*/

static object LI5(V116,V117)

register object V116;object V117;
{	 VMB5 VMS5 VMV5
TTL:;
	{object V118;
	object V119;
	register object V120;
	register object V121;
	V118= Cnil;
	V119= Cnil;
	V120= Cnil;
	V121= Cnil;
	if(!(type_of((V116))!=t_cons)){
	goto T347;}
	V118= (V116);
	goto T345;
T347:;
	if(!(endp(cdr((V116))))){
	goto T351;}
	V118= car((V116));
	goto T345;
T351:;
	V118= car((V116));
	V119= cadr((V116));
	{register object V122;
	register object V123;
	register object V124;
	V122= cddr((V116));
	V123= Cnil;
	V124= Cnil;
T360:;
	if(!(endp((V122)))){
	goto T361;}
	goto T345;
T361:;
	V123= car((V122));
	if(!(endp(cdr((V122))))){
	goto T367;}
	base[0]= VV[46];
	base[1]= (V122);
	vs_top=(vs_base=base+0)+2;
	Lerror();
	vs_top=sup;
T367:;
	V124= cadr((V122));
	{object V125= (V123);
	if((V125!= VV[74]))goto T375;
	V120= (V124);
	goto T374;
T375:;
	if((V125!= VV[112]))goto T377;
	V121= (V124);
	goto T374;
T377:;
	base[0]= VV[47];
	base[1]= (V122);
	vs_top=(vs_base=base+0)+2;
	Lerror();
	vs_top=sup;}
T374:;
	V122= cddr((V122));
	goto T360;}
T345:;
	{object V126 = list(5,(V118),(V119),(V120),(V121),(V117));
	VMR5(V126)}}
}
/*	local entry for function OVERWRITE-SLOT-DESCRIPTIONS	*/

static object LI6(V129,V130)

object V129;register object V130;
{	 VMB6 VMS6 VMV6
TTL:;
	if(((V130))!=Cnil){
	goto T385;}
	{object V131 = Cnil;
	VMR6(V131)}
T385:;
	{register object V132;
	base[0]= caar((V130));
	base[1]= (V129);
	base[2]= VV[16];
	base[3]= symbol_function(VV[113]);
	vs_top=(vs_base=base+0)+4;
	Lmember();
	vs_top=sup;
	V132= vs_base[0];
	if(((V132))==Cnil){
	goto T393;}
	if((cadddr(car((V132))))!=Cnil){
	goto T395;}
	if((cadddr(car((V130))))==Cnil){
	goto T395;}
	base[0]= VV[48];
	base[1]= (V132);
	vs_top=(vs_base=base+0)+2;
	Lerror();
	vs_top=sup;
T395:;
	{object V133;
	object V134;
	V133= car((V132));
	V134= (*(LnkLI114))(caddr(car((V132))));
	if(type_of(cddr((V133)))!=t_cons)FEwrong_type_argument(Scons,cddr((V133)));
	(cddr((V133)))->c.c_car = (V134);
	(void)(cddr((V133)));}{object V136;
	V136= caddr(car((V132)));
	if(V136==Cnil)goto T410;
	V135= V136;
	goto T409;
T410:;}
	V135= Ct;
T409:;
	V137= (*(LnkLI115))(V135);{object V139;
	V139= caddr(car((V130)));
	if(V139==Cnil)goto T413;
	V138= V139;
	goto T412;
T413:;}
	V138= Ct;
T412:;
	V140= (*(LnkLI115))(V138);
	if(equal(/* INLINE-ARGS */V137,/* INLINE-ARGS */V140)){
	goto T406;}
	base[0]= VV[49];
	base[1]= car((V132));
	vs_top=(vs_base=base+0)+2;
	Lerror();
	vs_top=sup;
T406:;
	V141= list(5,caar((V132)),cadar((V132)),caddar((V132)),cadddr(car((V132))),car(cddddr(car((V130)))));
	V142= (*(LnkLI116))((V129),cdr((V130)));
	{object V143 = make_cons(/* INLINE-ARGS */V141,/* INLINE-ARGS */V142);
	VMR6(V143)}
T393:;
	V144= car((V130));
	V145= (*(LnkLI116))((V129),cdr((V130)));
	{object V146 = make_cons(/* INLINE-ARGS */V144,/* INLINE-ARGS */V145);
	VMR6(V146)}}
}
/*	local entry for function MAKE-T-TYPE	*/

static object LI7(V150,V151,V152)

object V150;object V151;object V152;
{	 VMB7 VMS7 VMV7
TTL:;
	{object V153;
	V153= Cnil;
	{register object V154;
	V154= (VFUN_NARGS=5,(*(LnkLI117))((V150),VV[50],VV[51],VV[52],Ct));
	if(((V151))==Cnil){
	goto T419;}
	{object V155;
	object V156;
	V155= get((V151),VV[53],Cnil);
	V156= Cnil;
	if((V155)!=Cnil){
	goto T423;}
	base[0]= VV[54];
	base[1]= (V151);
	vs_top=(vs_base=base+0)+2;
	Lerror();
	vs_top=sup;
T423:;
	V156= structure_ref((V155),VV[53],2);
	{object V157;
	register object V158;
	V159 = make_fixnum(length((V156)));
	V157= (number_compare((V150),V159)<=0?((V150)):V159);
	V158= small_fixnum(0);
T431:;
	if(!(number_compare((V158),(V157))>=0)){
	goto T432;}
	goto T419;
T432:;
	V160= aref1((V156),fixint((V158)));
	(void)(aset1((V154),fixint((V158)),/* INLINE-ARGS */V160));
	V158= one_plus((V158));
	goto T431;}}
T419:;
	{register object V161;
	register object V162;
	V161= (V152);
	V162= car((V161));
T444:;
	if(!(endp((V161)))){
	goto T445;}
	goto T440;
T445:;
	V153= car(cddddr((V162)));
	{register object V163;
	V163= caddr((V162));
	base[1]= (V163);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk118)();
	vs_top=sup;
	V164= vs_base[0];
	if(!((fix(V164))<=(4))){
	goto T451;}
	base[1]= (V163);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk119)();
	vs_top=sup;
	V165= vs_base[0];
	(void)(aset1((V154),fixint((V153)),V165));}
T451:;
	V161= cdr((V161));
	V162= car((V161));
	goto T444;}
T440:;
	V166 = make_fixnum(length(symbol_value(VV[55])));
	if(!(number_compare((V150),V166)<0)){
	goto T465;}
	{register object V168;
	V168= small_fixnum(0);
T470:;
	if(!(number_compare((V168),V150)>=0)){
	goto T471;}
	goto T467;
T471:;
	{int V169= fix(aref1((V154),fixint((V168))));
	if((/* INLINE-ARGS */V169)==(0)){
	goto T475;}}
	{object V170 = (V154);
	VMR7(V170)}
T475:;
	V168= one_plus((V168));
	goto T470;}
T467:;
	{object V171 = symbol_value(VV[55]);
	VMR7(V171)}
T465:;
	{object V172 = (V154);
	VMR7(V172)}}}
}
/*	local entry for function ROUND-UP	*/

static int LI8(V175,V176)

int V175;int V176;
{	 VMB8 VMS8 VMV8
TTL:;
	base[0]= make_fixnum(V175);
	base[1]= make_fixnum(V176);
	vs_top=(vs_base=base+0)+2;
	Lceiling();
	vs_top=sup;
	V175= fix(vs_base[0]);
	{int V177 = (V175)*(V176);
	VMR8(V177)}
}
/*	local entry for function GET-SLOT-POS	*/

static object LI9(V181,V182,V183)

object V181;object V182;object V183;
{	 VMB9 VMS9 VMV9
TTL:;
	{register object V184;
	object V185;
	object V186;
	V184= Cnil;
	V185= Cnil;
	V186= Cnil;
	{register object V187;
	register object V188;
	V187= (V183);
	V188= car((V187));
T493:;
	if(!(endp((V187)))){
	goto T494;}
	goto T489;
T494:;
	if(((V188))==Cnil){
	goto T498;}
	if((car((V188)))==Cnil){
	goto T498;}
	V184= (*(LnkLI114))(caddr((V188)));
	if(type_of(cddr(V188))!=t_cons)FEwrong_type_argument(Scons,cddr(V188));
	(cddr(V188))->c.c_car = V184;
	(void)(cddr(V188));
	{register object V191;
	V191= cadr((V188));
	base[1]= (V191);
	base[2]= (V184);
	vs_top=(vs_base=base+1)+2;
	(void) (*Lnk120)();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T507;}
	if(!(type_of((V191))==t_symbol)){
	goto T513;}
	base[1]= (V191);
	vs_top=(vs_base=base+1)+1;
	Lconstantp();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T513;}
	base[1]= (V191);
	vs_top=(vs_base=base+1)+1;
	Lsymbol_value();
	vs_top=sup;
	V191= vs_base[0];
T513:;
	base[1]= (V191);
	vs_top=(vs_base=base+1)+1;
	Lconstantp();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T521;}
	goto T507;
T521:;
	{object V193;
	V193= (*(LnkLI121))((V191),(V184));
	if(type_of(cdr(V188))!=t_cons)FEwrong_type_argument(Scons,cdr(V188));
	(cdr(V188))->c.c_car = (V193);
	(void)(cdr(V188));}}
T507:;
	{register object x= (V184),V194= VV[57];
	while(!endp(V194))
	if(x==(V194->c.c_car)){
	goto T527;
	}else V194=V194->c.c_cdr;
	goto T498;}
T527:;
	V185= Ct;
T498:;
	V187= cdr((V187));
	V188= car((V187));
	goto T493;}
T489:;
	{object V195;
	if(((V185))==Cnil){
	goto T535;}
	V195= Cnil;
	goto T534;
T535:;
	V196 = make_fixnum(length(symbol_value(VV[56])));
	if(number_compare((V181),V196)<0){
	goto T537;}
	V195= Cnil;
	goto T534;
T537:;{object V197;
	V197= symbol_value(VV[56]);
	V195= list(3,V197,number_times((V181),small_fixnum(4)),Cnil);}
T534:;
	if(((V195))==Cnil){
	goto T540;}
	{object V198 = (V195);
	VMR9(V198)}
T540:;
	{object V199;
	register int V200;
	int V201;
	int V202;
	object V203;
	int V204;
	V199= (VFUN_NARGS=5,(*(LnkLI117))((V181),VV[50],VV[58],VV[52],Ct));
	V200= 0;
	V201= 0;
	V202= 0;
	V204= 0;
	V203= Cnil;
	{register object V205;
	register object V206;
	V205= (V183);
	V206= car((V205));
T551:;
	if(!(endp((V205)))){
	goto T552;}
	goto T547;
T552:;
	V203= caddr((V206));
	base[1]= (V203);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk118)();
	vs_top=sup;
	V202= fix(vs_base[0]);
	if((V202)<=(4)){
	goto T561;}
	V203= Ct;
	if(type_of(cddr(V206))!=t_cons)FEwrong_type_argument(Scons,cddr(V206));
	(cddr(V206))->c.c_car = Ct;
	(void)(cddr(V206));
	V202= 4;
	V206= nconc((V206),VV[59]);
T561:;
	V204= (*(LnkLI122))(V200,V202);
	if(!((V200)==(V204))){
	goto T574;}
	goto T573;
T574:;
	V186= Ct;
T573:;
	V200= V204;
	V209 = make_fixnum(V200);
	(void)(aset1((V199),V201,V209));
	V210 = make_fixnum(V200);
	base[1]= (V203);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk123)();
	vs_top=sup;
	V211= vs_base[0];
	V200= fix(number_plus(V210,V211));
	V201= (V201)+(1);
	V205= cdr((V205));
	V206= car((V205));
	goto T551;}
T547:;
	base[0]= Ct;
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk123)();
	vs_top=sup;
	V212= vs_base[0];
	V213 = make_fixnum((*(LnkLI122))(V200,fix(V212)));
	{object V214 = list(3,(V199),V213,(V186));
	VMR9(V214)}}}}
}
/*	local entry for function DEFINE-STRUCTURE	*/

static object LI10(V226,V225,V224,V223,V222,V221,V220,V219,V218,V217,V216,V215,va_alist)
	object V226,V225,V224,V223,V222,V221,V220,V219,V218,V217,V216,V215;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB10 VMS10 VMV10
	{object V227;
	register object V228;
	object V229;
	object V230;
	object V231;
	object V232;
	register object V233;
	object V234;
	object V235;
	object V236;
	object V237;
	object V238;
	register object V239;
	if(narg <12) too_few_arguments();
	Vcs[0]=MMcons(V226,Cnil);
	V227= V225;
	V228= V224;
	V229= V223;
	V230= V222;
	V231= V221;
	V232= V220;
	V233= V219;
	V234= V218;
	V235= V217;
	V236= V216;
	V237= V215;
	narg = narg - 12;
	if (narg <= 0) goto T593;
	else {
	va_start(ap);
	V238= va_arg(ap,object);}
	if (--narg <= 0) goto T594;
	else {
	V239= va_arg(ap,object);}
	--narg; goto T595;
T593:;
	V238= Cnil;
T594:;
	V239= Cnil;
T595:;
	{object V240;
	object V241;
	V240= Cnil;
	V241= Cnil;
	if(type_of((V228))==t_cons){
	goto T601;}
	goto T600;
T601:;
	if((car((V228)))==(VV[19])){
	goto T603;}
	goto T600;
T603:;
	V228= VV[19];
T600:;
	V241= make_fixnum(length((V230)));
	{register object V242;
	register object V243;
	V242= (V230);
	V243= car((V242));
T612:;
	if(!(endp((V242)))){
	goto T613;}
	goto T608;
T613:;
	if((V243)==Cnil){
	goto T617;}
	if((car((V243)))!=Cnil){
	goto T618;}
	goto T617;
T618:;
	base[1]= (Vcs[0]->c.c_car);
	base[2]= (V227);
	base[3]= (V228);
	base[4]= (V229);
	base[5]= (V233);
	base[6]= (V239);
	{object V244;
	V244= (V243);
	 vs_top=base+7;
	 while(!endp(V244))
	 {vs_push(car(V244));V244=cdr(V244);}
	vs_base=base+1;}
	(void) (*Lnk124)();
	vs_top=sup;
T617:;
	V242= cdr((V242));
	V243= car((V242));
	goto T612;}
T608:;
	if(((V231))==Cnil){
	goto T632;}
	if(((V239))!=Cnil){
	goto T632;}
	base[0]= (V231);
	{object V245= (V228);
	if((V245!= Cnil))goto T639;
	base[1]= symbol_function(VV[125]);
	goto T638;
T639:;
	if((V245!= VV[20]))goto T640;
	base[1]= symbol_function(VV[126]);
	goto T638;
T640:;
	if((V245!= VV[19]))goto T641;
	base[1]= symbol_function(VV[127]);
	goto T638;
T641:;
	FEerror("The ECASE key value ~s is illegal.",1,V245);}
T638:;
	vs_top=(vs_base=base+0)+2;
	siLfset();
	vs_top=sup;
T632:;
	if(((V228))!=Cnil){
	goto T644;}
	if(!(((Vcs[0]->c.c_car))==(VV[53]))){
	goto T644;}
	base[0]= (VFUN_NARGS=5,(*(LnkLI117))((V241),VV[50],VV[60],VV[52],Ct));
	base[1]= (*(LnkLI128))((V241),Cnil,(V230));
	base[2]= symbol_value(VV[56]);
	base[3]= (V230);
	base[4]= Ct;
	vs_top=(vs_base=base+0)+5;
	(void) (*Lnk129)();
	vs_top=sup;
	V240= vs_base[0];
	goto T642;
T644:;
	{object V246;
	object V247;
	object V248;
	object V249;
	if((V233)==Cnil){
	V249= Cnil;
	goto T654;}
	V249= get((V233),VV[53],Cnil);
T654:;
	V246= Cnil;
	V247= small_fixnum(0);
	V248= Cnil;
	if(((V249))==Cnil){
	goto T655;}
	if((structure_ref((V249),VV[53],11))==Cnil){
	goto T658;}
	if((structure_ref((V249),VV[53],3))==Cnil){
	goto T659;}
	{object V250;
	V250= get((Vcs[0]->c.c_car),VV[53],Cnil);
	if((V250)==Cnil){
	goto T664;}
	V251= structure_ref((V250),VV[53],4);
	if((/* INLINE-ARGS */V251)==((V249))){
	goto T658;}}
T664:;
T659:;
	(void)((VFUN_NARGS=2,(*(LnkLI130))(VV[61],(V233))));
T658:;
	{object V253;
	base[1]= (Vcs[0]->c.c_car);
	base[2]= structure_ref(V249,VV[53],3);
	vs_top=(vs_base=base+1)+2;
	Ladjoin();
	vs_top=sup;
	V253= vs_base[0];
	(void)(structure_set(V249,VV[53],3,(V253)));}
T655:;
	if(((V228))!=Cnil){
	goto T669;}
	V246= (*(LnkLI131))((V241),(V233),(V230));
	V247= cadr((V246));
	V248= caddr((V246));
	V246= car((V246));
T669:;
	if(((V228))==Cnil){
	goto T681;}
	V254= Cnil;
	goto T680;
T681:;
	V254= (*(LnkLI128))((V241),(V233),(V230));
T680:;
	V240= (VFUN_NARGS=32,(*(LnkLI132))(VV[62],(Vcs[0]->c.c_car),VV[63],(V241),VV[64],V254,VV[65],(V246),VV[66],(V247),VV[67],(V248),VV[68],(V232),VV[69],(V249),VV[70],(V234),VV[71],(V230),VV[72],(V235),VV[73],(V236),VV[74],(V228),VV[75],(V229),VV[76],(V238),VV[77],(V227)));}
T642:;
	{object V255;
	V255= get((Vcs[0]->c.c_car),VV[53],Cnil);
	if(!(((Vcs[0]->c.c_car))==(VV[53]))){
	goto T687;}
	if(((V255))==Cnil){
	goto T689;}
	(void)((VFUN_NARGS=1,(*(LnkLI130))(VV[78])));
T689:;
	if((V255)!=Cnil){
	goto T685;}
	(void)(sputprop((Vcs[0]->c.c_car),VV[53],(V240)));
	goto T685;
T687:;
	if(((V255))==Cnil){
	goto T693;}
	(void)((*(LnkLI133))((V255),(V240),(Vcs[0]->c.c_car)));
	goto T685;
T693:;
	(void)(sputprop((Vcs[0]->c.c_car),VV[53],(V240)));
T685:;
	if(((V238))==Cnil){
	goto T695;}
	(void)(sputprop((Vcs[0]->c.c_car),VV[79],(V238)));
T695:;
	if(((V228))!=Cnil){
	goto T683;}
	if(((V237))==Cnil){
	goto T683;}
	base[0]= (V237);
	base[1]= VV[3];
	base[2]= VV[80];
	base[3]= Ct;
	vs_top=(vs_base=base+0)+4;
	(void) (*Lnk108)();
	vs_top=sup;
	if((V239)!=Cnil){
	goto T707;}
	base[0]= (V237);
	base[1]= 
	make_cclosure_new(LC20,Cnil,Vcs[0],Cdata);
	vs_top=(vs_base=base+0)+2;
	siLfset();
	vs_top=sup;
T707:;
	(void)(sputprop((V237),VV[81],VV[82]));
	(void)(sputprop((V237),VV[83],(Vcs[0]->c.c_car)));}
T683:;
	{object V256 = Cnil;
	VMR10(V256)}}}
	}
/*	macro definition for DEFSTRUCT	*/

static L11()
{register object *base=vs_base;
	register object *sup=base+VM11; VC11
	vs_reserve(VM11);
	check_arg(2);
	vs_top=sup;
	{object V257=base[0]->c.c_cdr;
	if(endp(V257))invalid_macro_call();
	base[2]= (V257->c.c_car);
	V257=V257->c.c_cdr;
	base[3]= V257;}
	{register object V258;
	object V259;
	register object V260;
	register object V261;
	register object V262;
	register object V263;
	register object V264;
	register object V265;
	register object V266;
	register object V267;
	register object V268;
	register object V269;
	register object V270;
	register object V271;
	register object V272;
	object V273;
	object V274;
	register object V275;
	V258= base[3];
	V259= Cnil;
	V260= Cnil;
	V261= Cnil;
	V262= Cnil;
	V263= Cnil;
	V264= Cnil;
	V265= Cnil;
	V266= Cnil;
	V267= Cnil;
	V268= Cnil;
	V269= Cnil;
	V270= Cnil;
	V271= Cnil;
	V272= Cnil;
	V273= Cnil;
	V274= Cnil;
	V275= Cnil;
	if(!(type_of(base[2])==t_cons)){
	goto T711;}
	V259= cdr(base[2]);
	base[2]= car(base[2]);
T711:;
	base[4]= coerce_to_string(base[2]);
	base[5]= VV[84];
	vs_top=(vs_base=base+4)+2;
	(void) (*Lnk106)();
	vs_top=sup;
	V260= vs_base[0];
	base[5]= VV[85];
	base[6]= coerce_to_string(base[2]);
	vs_top=(vs_base=base+5)+2;
	(void) (*Lnk106)();
	vs_top=sup;
	base[4]= vs_base[0];
	vs_top=(vs_base=base+4)+1;
	Lintern();
	vs_top=sup;
	V262= vs_base[0];
	base[5]= VV[86];
	base[6]= coerce_to_string(base[2]);
	vs_top=(vs_base=base+5)+2;
	(void) (*Lnk106)();
	vs_top=sup;
	base[4]= vs_base[0];
	vs_top=(vs_base=base+4)+1;
	Lintern();
	vs_top=sup;
	V264= vs_base[0];
	base[5]= coerce_to_string(base[2]);
	base[6]= VV[87];
	vs_top=(vs_base=base+5)+2;
	(void) (*Lnk106)();
	vs_top=sup;
	base[4]= vs_base[0];
	vs_top=(vs_base=base+4)+1;
	Lintern();
	vs_top=sup;
	V265= vs_base[0];
	{register object V276;
	register object V277;
	register object V278;
	V276= (V259);
	V277= Cnil;
	V278= Cnil;
T738:;
	if(!(endp((V276)))){
	goto T739;}
	goto T736;
T739:;
	if(!(type_of(car((V276)))==t_cons)){
	goto T745;}
	if(endp(cdar((V276)))){
	goto T745;}
	V277= caar((V276));
	V278= cadar((V276));
	{object V279= (V277);
	if((V279!= VV[77]))goto T753;
	if(((V278))!=Cnil){
	goto T755;}
	V260= VV[88];
	goto T743;
T755:;
	V260= (V278);
	goto T743;
T753:;
	if((V279!= VV[134]))goto T759;
	if(((V278))!=Cnil){
	goto T761;}
	V263= Ct;
	goto T743;
T761:;
	if(!(endp(cddar((V276))))){
	goto T765;}
	V261= make_cons((V278),(V261));
	goto T743;
T765:;
	V261= make_cons(cdar((V276)),(V261));
	goto T743;
T759:;
	if((V279!= VV[135]))goto T769;
	V264= (V278);
	goto T743;
T769:;
	if((V279!= VV[52]))goto T771;
	V275= (V278);
	goto T743;
T771:;
	if((V279!= VV[136]))goto T773;
	V265= (V278);
	V266= Ct;
	goto T743;
T773:;
	if((V279!= VV[137]))goto T777;
	V267= cdar((V276));
	if((get((V278),VV[53],Cnil))!=Cnil){
	goto T743;}
	base[4]= VV[89];
	base[5]= (V278);
	vs_top=(vs_base=base+4)+2;
	Lerror();
	vs_top=sup;
	goto T743;
T777:;
	if((V279!= VV[70]))goto T784;
	if(type_of((V278))==t_cons){
	goto T786;}
	goto T785;
T786:;
	if((car((V278)))==(VV[90])){
	goto T788;}
	goto T785;
T788:;
	V278= cadr((V278));
T785:;
	V268= (V278);
	goto T743;
T784:;
	if((V279!= VV[74]))goto T792;
	V269= (V278);
	goto T743;
T792:;
	if((V279!= VV[138]))goto T794;
	V271= (V278);
	goto T743;
T794:;
	base[4]= VV[91];
	base[5]= (V277);
	vs_top=(vs_base=base+4)+2;
	Lerror();
	vs_top=sup;
	goto T743;}
T745:;
	if(!(type_of(car((V276)))==t_cons)){
	goto T800;}
	V277= caar((V276));
	goto T798;
T800:;
	V277= car((V276));
T798:;
	{object V280= (V277);
	if((V280!= VV[134]))goto T804;
	V261= make_cons((V262),(V261));
	goto T743;
T804:;
	if((V280!= VV[77])
	&& (V280!= VV[135])
	&& (V280!= VV[136])
	&& (V280!= VV[70]))goto T806;
	goto T743;
T806:;
	if((V280!= VV[75]))goto T807;
	V270= Ct;
	goto T743;
T807:;
	base[4]= VV[92];
	base[5]= (V277);
	vs_top=(vs_base=base+4)+2;
	Lerror();
	vs_top=sup;}
T743:;
	V276= cdr((V276));
	goto T738;}
T736:;
	base[4]= coerce_to_string((V260));
	vs_top=(vs_base=base+4)+1;
	Lintern();
	vs_top=sup;
	V260= vs_base[0];
	if((V267)==Cnil){
	goto T817;}
	if(((V268))==Cnil){
	goto T818;}
	goto T817;
T818:;
	V281= get(car((V267)),VV[53],Cnil);
	V268= structure_ref(V281,VV[53],6);
T817:;
	if(endp((V258))){
	goto T822;}
	if(!(type_of(car((V258)))==t_string)){
	goto T822;}
	V274= car((V258));
	V258= cdr((V258));
T822:;
	if(((V267))==Cnil){
	goto T830;}
	V282= get(car((V267)),VV[53],Cnil);
	V283= structure_ref(V282,VV[53],16);
	if(equal((V269),/* INLINE-ARGS */V283)){
	goto T830;}
	base[4]= VV[93];
	base[5]= car((V267));
	vs_top=(vs_base=base+4)+2;
	Lerror();
	vs_top=sup;
T830:;
	if(((V267))!=Cnil){
	goto T840;}
	V272= small_fixnum(0);
	goto T838;
T840:;
	V284= get(car((V267)),VV[53],Cnil);
	V272= structure_ref(V284,VV[53],14);
T838:;
	if(((V269))==Cnil){
	goto T845;}
	if(((V271))==Cnil){
	goto T845;}
	V272= number_plus((V272),(V271));
T845:;
	if(((V269))==Cnil){
	goto T851;}
	if(((V270))==Cnil){
	goto T851;}
	V273= (V272);
	V272= one_plus((V272));
T851:;
	{register object V285;
	register object V286;
	V285= (V258);
	V286= Cnil;
T861:;
	if(!(endp((V285)))){
	goto T862;}
	V258= nreverse((V286));
	goto T859;
T862:;
	V287= (*(LnkLI139))(car((V285)),(V272));
	V286= make_cons(/* INLINE-ARGS */V287,(V286));
	V272= one_plus((V272));
	V285= cdr((V285));
	goto T861;}
T859:;
	if(((V269))==Cnil){
	goto T874;}
	if(((V270))==Cnil){
	goto T874;}
	V288= list(2,Cnil,base[2]);
	V258= make_cons(/* INLINE-ARGS */V288,(V258));
T874:;
	if(((V269))==Cnil){
	goto T880;}
	if(((V271))==Cnil){
	goto T880;}
	base[4]= (V271);
	vs_top=(vs_base=base+4)+1;
	Lmake_list();
	vs_top=sup;
	V289= vs_base[0];
	V258= append(V289,(V258));
T880:;
	{object V290;
	V290= (((V267))==Cnil?Ct:Cnil);
	if(((V290))==Cnil){
	goto T891;}
	goto T888;
T891:;
	if(!(endp(cdr((V267))))){
	goto T894;}
	V291= get(car((V267)),VV[53],Cnil);
	V292= structure_ref(V291,VV[53],7);
	V258= append(/* INLINE-ARGS */V292,(V258));
	goto T888;
T894:;
	{object V294;
	object V295= cdr((V267));
	if(endp(V295)){
	V293= Cnil;
	goto T899;}
	base[4]=V294=MMcons(Cnil,Cnil);
T900:;
	(V294->c.c_car)= (*(LnkLI139))((V295->c.c_car),small_fixnum(0));
	if(endp(V295=MMcdr(V295))){
	V293= base[4];
	goto T899;}
	V294=MMcdr(V294)=MMcons(Cnil,Cnil);
	goto T900;}
T899:;
	V297= get(car((V267)),VV[53],Cnil);
	V298= structure_ref(V297,VV[53],7);
	V299= (*(LnkLI116))(V293,/* INLINE-ARGS */V298);
	V258= append(/* INLINE-ARGS */V299,(V258));}
T888:;
	if(((V263))==Cnil){
	goto T905;}
	if(((V261))==Cnil){
	goto T903;}
	base[4]= VV[94];
	vs_top=(vs_base=base+4)+1;
	Lerror();
	vs_top=sup;
	goto T903;
T905:;
	if(((V261))!=Cnil){
	goto T903;}
	V261= make_cons((V262),Cnil);
T903:;{object V300;
	{object V303;
	object V304= (V261);
	if(endp(V304)){
	V302= Cnil;
	goto T916;}
	base[4]=V303=MMcons(Cnil,Cnil);
T917:;
	base[5]= (V304->c.c_car);
	vs_top=(vs_base=base+5)+1;
	Lsymbolp();
	vs_top=sup;
	(V303->c.c_car)= vs_base[0];
	if(endp(V304=MMcdr(V304))){
	V302= base[4];
	goto T916;}
	V303=MMcdr(V303)=MMcons(Cnil,Cnil);
	goto T917;}
T916:;
	{register object x= Ct,V301= V302;
	while(!endp(V301))
	if(eql(x,V301->c.c_car)){
	V300= V301;
	goto T915;
	}else V301=V301->c.c_cdr;
	V300= Cnil;}
T915:;
	if(V300==Cnil)goto T914;
	goto T913;
T914:;}
	base[5]= VV[95];
	base[6]= (V262);
	vs_top=(vs_base=base+5)+2;
	(void) (*Lnk106)();
	vs_top=sup;
	base[4]= vs_base[0];
	vs_top=(vs_base=base+4)+1;
	Lintern();
	vs_top=sup;
	V305= vs_base[0];
	V261= make_cons(V305,(V261));
T913:;
	if(((V269))==Cnil){
	goto T925;}
	if(((V270))!=Cnil){
	goto T925;}
	if(((V266))==Cnil){
	goto T930;}
	base[4]= VV[96];
	base[5]= (V265);
	vs_top=(vs_base=base+4)+2;
	Lerror();
	vs_top=sup;
T930:;
	V265= Cnil;
T925:;
	if(((V267))==Cnil){
	goto T936;}
	V267= car((V267));
T936:;
	if(((V268))==Cnil){
	goto T940;}
	if(((V269))==Cnil){
	goto T940;}
	base[4]= VV[97];
	vs_top=(vs_base=base+4)+1;
	Lerror();
	vs_top=sup;
T940:;
	base[4]= VV[99];
	base[5]= list(2,VV[11],base[2]);
	base[6]= list(2,VV[11],(V260));
	base[7]= list(2,VV[11],(V269));
	base[8]= list(2,VV[11],(V270));
	base[9]= list(2,VV[11],(V258));
	base[10]= list(2,VV[11],(V264));
	base[11]= list(2,VV[11],(V275));
	base[12]= list(2,VV[11],(V267));
	base[13]= list(2,VV[11],(V268));
	base[14]= list(2,VV[11],(V261));
	base[15]= list(2,VV[11],(V272));
	base[16]= list(2,VV[11],(V265));
	base[17]= list(2,VV[11],(V274));
	vs_top=(vs_base=base+4)+14;
	Llist();
	vs_top=sup;
	V306= vs_base[0];
	{object V308;
	object V309= (V261);
	if(endp(V309)){
	base[4]= Cnil;
	goto T962;}
	base[5]=V308=MMcons(Cnil,Cnil);
T963:;
	(V308->c.c_car)= (*(LnkLI140))(base[2],(V309->c.c_car),(V269),(V270),(V258));
	if(endp(V309=MMcdr(V309))){
	base[4]= base[5];
	goto T962;}
	V308=MMcdr(V308)=MMcons(Cnil,Cnil);
	goto T963;}
T962:;
	if(((V269))==Cnil){
	goto T967;}
	if(((V265))==Cnil){
	goto T967;}
	V311= (*(LnkLI141))(base[2],(V265),(V269),(V270),(V273));
	base[5]= make_cons(/* INLINE-ARGS */V311,Cnil);
	goto T965;
T967:;
	base[5]= Cnil;
T965:;
	V312= list(2,VV[11],base[2]);
	base[6]= make_cons(/* INLINE-ARGS */V312,Cnil);
	vs_top=(vs_base=base+4)+3;
	Lappend();
	vs_top=sup;
	V307= vs_base[0];
	base[4]= listA(3,VV[98],V306,V307);
	vs_top=(vs_base=base+4)+1;
	return;}
}
/*	local entry for function MAKE-S-DATA	*/

static object LI12(va_alist)
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB12 VMS12 VMV12
	{object V313;
	object V314;
	object V315;
	object V316;
	object V317;
	object V318;
	object V319;
	object V320;
	object V321;
	object V322;
	object V323;
	object V324;
	object V325;
	object V326;
	object V327;
	object V328;
	object V329;
	object V330;
	narg= narg - 0;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +0,&LI12key,ap);
	V313=(Vcs[0]);
	V314=(Vcs[1]);
	V315=(Vcs[2]);
	V316=(Vcs[3]);
	V317=(Vcs[4]);
	V318=(Vcs[5]);
	V319=(Vcs[6]);
	V320=(Vcs[7]);
	V321=(Vcs[8]);
	V322=(Vcs[9]);
	V323=(Vcs[10]);
	V324=(Vcs[11]);
	V325=(Vcs[12]);
	V326=(Vcs[13]);
	V327=(Vcs[14]);
	V328=(Vcs[15]);
	V329=(Vcs[16]);
	V330=(Vcs[17]);
	base[0]= VV[53];
	base[1]= (V313);
	base[2]= (V314);
	base[3]= (V315);
	base[4]= (V316);
	base[5]= (V317);
	base[6]= (V318);
	base[7]= (V319);
	base[8]= (V320);
	base[9]= (V321);
	base[10]= (V322);
	base[11]= (V323);
	base[12]= (V324);
	base[13]= (V325);
	base[14]= (V326);
	base[15]= (V327);
	base[16]= (V328);
	base[17]= (V329);
	base[18]= (V330);
	vs_top=(vs_base=base+0)+19;
	siLmake_structure();
	vs_top=sup;
	{object V331 = vs_base[0];
	VMR12(V331)}}
	}}
/*	local entry for function CHECK-S-DATA	*/

static object LI13(V335,V336,V337)

register object V335;register object V336;object V337;
{	 VMB13 VMS13 VMV13
TTL:;
	if((structure_ref((V335),VV[53],3))==Cnil){
	goto T991;}
	V338= structure_ref((V335),VV[53],3);
	(void)(structure_set((V336),VV[53],3,/* INLINE-ARGS */V338));
T991:;
	if((structure_ref((V335),VV[53],11))==Cnil){
	goto T994;}
	(void)(structure_set((V336),VV[53],11,Ct));
T994:;
	if(equalp((V336),(V335))){
	goto T998;}
	(void)((VFUN_NARGS=2,(*(LnkLI130))(VV[100],(V337))));
	{object V339 = sputprop((V337),VV[53],(V336));
	VMR13(V339)}
T998:;
	{object V340 = Cnil;
	VMR13(V340)}
}
/*	local entry for function FREEZE-DEFSTRUCT	*/

static object LI14(V342)

object V342;
{	 VMB14 VMS14 VMV14
TTL:;
	{object V343;
	if(type_of((V342))==t_symbol){
	goto T1002;}
	V343= Cnil;
	goto T1001;
T1002:;
	V343= get((V342),VV[53],Cnil);
T1001:;
	if(((V343))==Cnil){
	goto T1005;}
	{object V344 = structure_set((V343),VV[53],11,Ct);
	VMR14(V344)}
T1005:;
	{object V345 = Cnil;
	VMR14(V345)}}
}
/*	function definition for SHARP-S-READER	*/

static L15()
{register object *base=vs_base;
	register object *sup=base+VM15; VC15
	vs_reserve(VM15);
	{object V346;
	object V347;
	object V348;
	check_arg(3);
	V346=(base[0]);
	V347=(base[1]);
	V348=(base[2]);
	vs_top=sup;
TTL:;
	if(((V348))==Cnil){
	goto T1007;}
	if((symbol_value(VV[101]))!=Cnil){
	goto T1007;}
	base[3]= VV[102];
	vs_top=(vs_base=base+3)+1;
	Lerror();
	vs_top=sup;
T1007:;
	{register object V349;
	register object V350;
	{object V351;
	base[5]= (V346);
	base[6]= Ct;
	base[7]= Cnil;
	base[8]= Ct;
	vs_top=(vs_base=base+5)+4;
	Lread();
	vs_top=sup;
	V351= vs_base[0];
	if((symbol_value(VV[101]))==Cnil){
	goto T1019;}
	base[5]= Cnil;
	vs_top=(vs_base=base+5)+1;
	return;
T1019:;
	V349= (V351);}{object V352;
	V352= get(car((V349)),VV[53],Cnil);
	if(V352==Cnil)goto T1023;
	V350= V352;
	goto T1022;
T1023:;}
	base[5]= VV[103];
	base[6]= car((V349));
	vs_top=(vs_base=base+5)+2;
	Lerror();
	vs_top=sup;
	V350= vs_base[0];
T1022:;
	{register object V353;
	V353= cdr((V349));
T1029:;
	if(!(endp((V353)))){
	goto T1030;}
	{register object V354;
	V354= structure_ref((V350),VV[53],13);
T1035:;
	if(!(endp((V354)))){
	goto T1036;}
	base[5]= VV[104];
	base[6]= car((V349));
	vs_top=(vs_base=base+5)+2;
	Lerror();
	return;
T1036:;
	if(!(type_of(car((V354)))==t_symbol)){
	goto T1042;}
	base[5]= car((V354));
	{object V355;
	V355= cdr((V349));
	 vs_top=base+6;
	 while(!endp(V355))
	 {vs_push(car(V355));V355=cdr(V355);}
	vs_base=base+6;}
	super_funcall_no_event(base[5]);
	return;
T1042:;
	V354= cdr((V354));
	goto T1035;}
T1030:;
	base[5]= coerce_to_string(car((V353)));
	base[6]= VV[105];
	vs_top=(vs_base=base+5)+2;
	Lintern();
	vs_top=sup;
	V356= vs_base[0];
	if(type_of((V353))!=t_cons)FEwrong_type_argument(Scons,(V353));
	((V353))->c.c_car = V356;
	V353= cddr((V353));
	goto T1029;}}
	}
}
/*	local function CLOSURE	*/

static LC20(base0)
register object *base0;
{	register object *base=vs_base;
	register object *sup=base+VM16; VC16
	vs_reserve(VM16);
	{object V357;
	check_arg(1);
	V357=(base[0]);
	vs_top=sup;
	base[1]= (V357);
	base[2]= (base0[0]->c.c_car);
	vs_top=(vs_base=base+1)+2;
	(void) (*Lnk145)();
	return;
	}
}
/*	local function CLOSURE	*/

static LC19(base0)
register object *base0;
{	register object *base=vs_base;
	register object *sup=base+VM17; VC17
	vs_reserve(VM17);
	{object V358;
	check_arg(1);
	V358=(base[0]);
	vs_top=sup;
	if(!(type_of((V358))==t_cons)){
	goto T1061;}
	base[1]= car((V358));
	vs_top=(vs_base=base+1)+1;
	return;
T1061:;
	base[1]= Cnil;
	vs_top=(vs_base=base+1)+1;
	return;
	}
}
/*	local function CLOSURE	*/

static LC18(base0)
register object *base0;
{	register object *base=vs_base;
	register object *sup=base+VM18; VC18
	vs_reserve(VM18);
	{object V359;
	check_arg(1);
	V359=(base[0]);
	vs_top=sup;
	base[1]= aref1((V359),fixint((base0[0]->c.c_car)));
	vs_top=(vs_base=base+1)+1;
	return;
	}
}
/*	local function CLOSURE	*/

static LC17(base0)
register object *base0;
{	register object *base=vs_base;
	register object *sup=base+VM19; VC19
	vs_reserve(VM19);
	{object V360;
	check_arg(1);
	V360=(base[0]);
	vs_top=sup;
	base[1]= (base0[0]->c.c_car);
	base[2]= (V360);
	vs_top=(vs_base=base+1)+2;
	siLlist_nth();
	return;
	}
}
/*	local function CLOSURE	*/

static LC16(base0)
register object *base0;
{	register object *base=vs_base;
	register object *sup=base+VM20; VC20
	vs_reserve(VM20);
	{object V361;
	check_arg(1);
	V361=(base[0]);
	vs_top=sup;
	if(!(type_of((V361))==t_structure)){
	goto T1066;}
	goto T1065;
T1066:;
	base[1]= VV[5];
	base[2]= (V361);
	vs_top=(vs_base=base+1)+2;
	Lerror();
	vs_top=sup;
T1065:;
	base[1]= (V361);
	base[2]= (base0[0]->c.c_car);
	vs_top=(vs_base=base+1)+2;
	(void) (*Lnk146)();
	return;
	}
}
static LnkT146(){ call_or_link(VV[146],&Lnk146);} /* STRUCTURE-REF1 */
static LnkT145(){ call_or_link(VV[145],&Lnk145);} /* STRUCTURE-SUBTYPE-P */
static object  LnkTLI141(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[141],&LnkLI141,5,ap);} /* MAKE-PREDICATE */
static object  LnkTLI140(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[140],&LnkLI140,5,ap);} /* MAKE-CONSTRUCTOR */
static object  LnkTLI139(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[139],&LnkLI139,2,ap);} /* PARSE-SLOT-DESCRIPTION */
static object  LnkTLI133(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[133],&LnkLI133,3,ap);} /* CHECK-S-DATA */
static object  LnkTLI132(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[132],&LnkLI132,ap);} /* MAKE-S-DATA */
static object  LnkTLI131(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[131],&LnkLI131,3,ap);} /* GET-SLOT-POS */
static object  LnkTLI130(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[130],&LnkLI130,ap);} /* WARN */
static LnkT129(){ call_or_link(VV[129],&Lnk129);} /* MAKE-S-DATA-STRUCTURE */
static object  LnkTLI128(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[128],&LnkLI128,3,ap);} /* MAKE-T-TYPE */
static LnkT124(){ call_or_link(VV[124],&Lnk124);} /* MAKE-ACCESS-FUNCTION */
static LnkT123(){ call_or_link(VV[123],&Lnk123);} /* SIZE-OF */
static int  LnkTLI122(va_alist)va_dcl{va_list ap;va_start(ap);return(int )call_proc(VV[122],&LnkLI122,20738,ap);} /* ROUND-UP */
static object  LnkTLI121(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[121],&LnkLI121,2,ap);} /* COERCE */
static LnkT120(){ call_or_link(VV[120],&Lnk120);} /* TYPEP */
static LnkT119(){ call_or_link(VV[119],&Lnk119);} /* AET-TYPE */
static LnkT118(){ call_or_link(VV[118],&Lnk118);} /* ALIGNMENT */
static object  LnkTLI117(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[117],&LnkLI117,ap);} /* MAKE-ARRAY */
static object  LnkTLI116(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[116],&LnkLI116,2,ap);} /* OVERWRITE-SLOT-DESCRIPTIONS */
static object  LnkTLI115(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[115],&LnkLI115,1,ap);} /* NORMALIZE-TYPE */
static object  LnkTLI114(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[114],&LnkLI114,1,ap);} /* BEST-ARRAY-ELEMENT-TYPE */
static object  LnkTLI110(){return call_proc0(VV[110],&LnkLI110);} /* ILLEGAL-BOA */
static LnkT109(){ call_or_link(VV[109],&Lnk109);} /* SUBTYPEP */
static LnkT108(){ call_or_link(VV[108],&Lnk108);} /* RECORD-FN */
static object  LnkTLI107(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[107],&LnkLI107,ap);} /* ADJUST-ARRAY */
static LnkT106(){ call_or_link(VV[106],&Lnk106);} /* STRING-CONCATENATE */
