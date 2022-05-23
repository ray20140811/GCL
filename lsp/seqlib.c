
#include <cmpinclude.h>
#include "seqlib.h"
init_seqlib(){do_init(VV);}
/*	local entry for function SEQTYPE	*/

static object LI1(V2)

register object V2;
{	 VMB1 VMS1 VMV1
TTL:;
	if(!(type_of((V2))==t_cons||((V2))==Cnil)){
	goto T2;}
	{object V3 = VV[0];
	VMR1(V3)}
T2:;
	if(!(type_of((V2))==t_string)){
	goto T5;}
	{object V4 = VV[1];
	VMR1(V4)}
T5:;
	if(!((type_of((V2))==t_bitvector))){
	goto T8;}
	{object V5 = VV[2];
	VMR1(V5)}
T8:;
	if(!(type_of((V2))==t_vector||
type_of((V2))==t_string||
type_of((V2))==t_bitvector)){
	goto T11;}
	base[0]= (V2);
	vs_top=(vs_base=base+0)+1;
	Larray_element_type();
	vs_top=sup;
	V6= vs_base[0];
	{object V7 = list(2,VV[3],V6);
	VMR1(V7)}
T11:;
	base[0]= VV[4];
	base[1]= (V2);
	vs_top=(vs_base=base+0)+2;
	Lerror();
	vs_top=sup;
	{object V8 = vs_base[0];
	VMR1(V8)}
}
/*	local entry for function CALL-TEST	*/

static object LI2(V13,V14,V15,V16)

object V13;object V14;object V15;object V16;
{	 VMB2 VMS2 VMV2
TTL:;
	if(((V13))==Cnil){
	goto T18;}
	base[0]= (V15);
	base[1]= (V16);
	vs_top=(vs_base=base+0)+2;
	super_funcall_no_event((V13));
	vs_top=sup;
	{object V17 = vs_base[0];
	VMR2(V17)}
T18:;
	if(((V14))==Cnil){
	goto T23;}
	base[0]= (V15);
	base[1]= (V16);
	vs_top=(vs_base=base+0)+2;
	super_funcall_no_event((V14));
	vs_top=sup;
	V18= vs_base[0];
	{object V19 = ((V18)==Cnil?Ct:Cnil);
	VMR2(V19)}
T23:;
	{object V20 = (eql((V15),(V16))?Ct:Cnil);
	VMR2(V20)}
}
/*	local entry for function CHECK-SEQ-START-END	*/

static object LI3(V23,V24)

object V23;object V24;
{	 VMB3 VMS3 VMV3
TTL:;
	if(!(type_of((V23))==t_fixnum)){
	goto T29;}
	if(type_of((V24))==t_fixnum){
	goto T28;}
T29:;
	base[0]= VV[5];
	vs_top=(vs_base=base+0)+1;
	Lerror();
	vs_top=sup;
T28:;
	if(!((fix((V23)))>(fix((V24))))){
	goto T35;}
	base[0]= VV[6];
	vs_top=(vs_base=base+0)+1;
	Lerror();
	vs_top=sup;
	{object V25 = vs_base[0];
	VMR3(V25)}
T35:;
	{object V26 = Cnil;
	VMR3(V26)}
}
/*	local entry for function TEST-ERROR	*/

static object LI4()

{	 VMB4 VMS4 VMV4
TTL:;
	base[0]= VV[7];
	vs_top=(vs_base=base+0)+1;
	Lerror();
	vs_top=sup;
	{object V27 = vs_base[0];
	VMR4(V27)}
}
/*	local entry for function BAD-SEQ-LIMIT	*/

static object LI5(V28,va_alist)
	object V28;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB5 VMS5 VMV5
	{object V29;
	object V30;
	if(narg <1) too_few_arguments();
	V29= V28;
	narg = narg - 1;
	if (narg <= 0) goto T39;
	else {
	va_start(ap);
	V30= va_arg(ap,object);}
	--narg; goto T40;
T39:;
	V30= Cnil;
T40:;
	base[0]= VV[8];
	if(((V30))==Cnil){
	goto T45;}
	base[1]= list(2,(V29),(V30));
	goto T43;
T45:;
	base[1]= (V29);
T43:;
	vs_top=(vs_base=base+0)+2;
	Lerror();
	vs_top=sup;
	{object V31 = vs_base[0];
	VMR5(V31)}}
	}
/*	local entry for function THE-END	*/

static int LI6(V34,V35)

register object V34;object V35;
{	 VMB6 VMS6 VMV6
TTL:;
	if(!(type_of((V34))==t_fixnum)){
	goto T48;}
	if(!((fix((V34)))<=(length((V35))))){
	goto T51;}
	goto T50;
T51:;
	(void)((VFUN_NARGS=1,(*(LnkLI17))((V34))));
T50:;
	{int V36 = fix((V34));
	VMR6(V36)}
T48:;
	if(((V34))!=Cnil){
	goto T54;}
	{int V37 = length((V35));
	VMR6(V37)}
T54:;
	{int V38 = fix((VFUN_NARGS=1,(*(LnkLI17))((V34))));
	VMR6(V38)}
}
/*	local entry for function THE-START	*/

static int LI7(V40)

register object V40;
{	 VMB7 VMS7 VMV7
TTL:;
	if(!(type_of((V40))==t_fixnum)){
	goto T57;}
	if(!((fix((V40)))>=(0))){
	goto T60;}
	goto T59;
T60:;
	(void)((VFUN_NARGS=1,(*(LnkLI17))((V40))));
T59:;
	{int V41 = fix((V40));
	VMR7(V41)}
T57:;
	if(((V40))!=Cnil){
	goto T63;}
	{int V42 = 0;
	VMR7(V42)}
T63:;
	{int V43 = fix((VFUN_NARGS=1,(*(LnkLI17))((V40))));
	VMR7(V43)}
}
/*	function definition for REDUCE	*/

static L8()
{register object *base=vs_base;
	register object *sup=base+VM8; VC8
	vs_reserve(VM8);
	{register object V44;
	register object V45;
	object V46;
	object V47;
	object V48;
	object V49;
	object V50;
	if(vs_top-vs_base<2) too_few_arguments();
	parse_key(vs_base+2,FALSE,FALSE,4,VV[10],VV[13],VV[14],VV[18]);
	V44=(base[0]);
	V45=(base[1]);
	vs_top=sup;
	V46=(base[2]);
	V47=(base[3]);
	V48=(base[4]);
	V49=(base[5]);
	V50=(base[9]);
	{register int V51;
	if(((V47))==Cnil){
	goto T67;}
	V51= (*(LnkLI19))((V47));
	goto T65;
T67:;
	V51= 0;
T65:;
	{register int V52;
	V52= (*(LnkLI20))((V48),(V45));
	if(!((V51)<=(V52))){
	goto T71;}
	goto T70;
T71:;
	V53 = make_fixnum(V51);
	V54 = make_fixnum(V52);
	(void)((VFUN_NARGS=2,(*(LnkLI17))(V53,V54)));
T70:;
	if(((V46))!=Cnil){
	goto T74;}
	if(((V50))!=Cnil){
	goto T76;}
	if(!((V51)>=(V52))){
	goto T79;}
	vs_base=vs_top;
	super_funcall_no_event((V44));
	return;
T79:;
	V49= elt((V45),V51);
	V51= (1)+(V51);
T76:;
	{register object V55;
	V55= (V49);
T86:;
	if(!((V51)>=(V52))){
	goto T87;}
	base[10]= (V55);
	vs_top=(vs_base=base+10)+1;
	return;
T87:;
	{object V57;
	V57= elt((V45),V51);
	V51= (1)+(V51);
	V56= (V57);}
	V55= (
	(type_of((V44)) == t_sfun ?(*(object (*)())(((V44))->sfn.sfn_self)):
	(fcall.fun=((V44)),fcall.argd=2,fcalln))((V55),V56));
	goto T86;}
T74:;
	if(((V50))!=Cnil){
	goto T98;}
	if(!((V51)>=(V52))){
	goto T101;}
	vs_base=vs_top;
	super_funcall_no_event((V44));
	return;
T101:;
	V52= (V52)+(-1);
	V49= elt((V45),V52);
T98:;
	{register object V58;
	V58= (V49);
T108:;
	if(!((V51)>=(V52))){
	goto T109;}
	base[10]= (V58);
	vs_top=(vs_base=base+10)+1;
	return;
T109:;
	V52= (-1)+(V52);
	V59= elt((V45),V52);
	V58= (
	(type_of((V44)) == t_sfun ?(*(object (*)())(((V44))->sfn.sfn_self)):
	(fcall.fun=((V44)),fcall.argd=2,fcalln))(/* INLINE-ARGS */V59,(V58)));
	goto T108;}}}
	}
}
/*	local entry for function FILL	*/

static object LI9(V61,V60,va_alist)
	object V61,V60;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB9 VMS9 VMV9
	{register object V62;
	register object V63;
	object V64;
	object V65;
	if(narg <2) too_few_arguments();
	V62= V61;
	V63= V60;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI9key,ap);
	V64=(Vcs[2]);
	V65=(Vcs[3]);
	{int V66;
	if(((V64))==Cnil){
	goto T120;}
	V66= (*(LnkLI19))((V64));
	goto T118;
T120:;
	V66= 0;
T118:;
	{register int V67;
	V67= (*(LnkLI20))((V65),(V62));
	if(!((V66)<=(V67))){
	goto T124;}
	goto T123;
T124:;
	V68 = make_fixnum(V66);
	V69 = make_fixnum(V67);
	(void)((VFUN_NARGS=2,(*(LnkLI17))(V68,V69)));
T123:;
	{register int V70;
	V70= V66;
T128:;
	if(!((V70)>=(V67))){
	goto T129;}
	{object V71 = (V62);
	VMR9(V71)}
T129:;
	(void)(elt_set((V62),V70,(V63)));
	V70= (1)+(V70);
	goto T128;}}}}
	}}
/*	local entry for function REPLACE	*/

static object LI10(V73,V72,va_alist)
	object V73,V72;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB10 VMS10 VMV10
	{register object V74;
	object V75;
	object V76;
	object V77;
	object V78;
	object V79;
	if(narg <2) too_few_arguments();
	V74= V73;
	V75= V72;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI10key,ap);
	V76=(Vcs[2]);
	V77=(Vcs[3]);
	V78=(Vcs[4]);
	V79=(Vcs[5]);
	{int V80;
	if(((V76))==Cnil){
	goto T139;}
	V80= (*(LnkLI19))((V76));
	goto T137;
T139:;
	V80= 0;
T137:;
	{int V81;
	V81= (*(LnkLI20))((V77),(V74));
	if(!((V80)<=(V81))){
	goto T143;}
	goto T142;
T143:;
	V82 = make_fixnum(V80);
	V83 = make_fixnum(V81);
	(void)((VFUN_NARGS=2,(*(LnkLI17))(V82,V83)));
T142:;
	{int V84;
	if(((V78))==Cnil){
	goto T147;}
	V84= (*(LnkLI19))((V78));
	goto T145;
T147:;
	V84= 0;
T145:;
	{int V85;
	V85= (*(LnkLI20))((V79),(V75));
	if(!((V84)<=(V85))){
	goto T151;}
	goto T150;
T151:;
	V86 = make_fixnum(V84);
	V87 = make_fixnum(V85);
	(void)((VFUN_NARGS=2,(*(LnkLI17))(V86,V87)));
T150:;
	if(!(((V74))==((V75)))){
	goto T154;}
	if(!((V80)>(V84))){
	goto T154;}
	{register int V88;
	int V89;
	register int V90;
	register int V91;
	V88= 0;
	if(!(((V81)-(V80))<((V85)-(V84)))){
	goto T161;}
	V89= (V81)-(V80);
	goto T159;
T161:;
	V89= (V85)-(V84);
T159:;
	V90= (V80)+((-1)+(V89));
	V91= (V84)+((-1)+(V89));
T166:;
	if(!((V88)>=(V89))){
	goto T167;}
	{object V92 = (V74);
	VMR10(V92)}
T167:;
	V93= elt((V75),V91);
	(void)(elt_set((V74),V90,/* INLINE-ARGS */V93));
	V88= (1)+(V88);
	V90= (-1)+(V90);
	V91= (-1)+(V91);
	goto T166;}
T154:;
	{register int V94;
	int V95;
	register int V96;
	register int V97;
	V94= 0;
	if(!(((V81)-(V80))<((V85)-(V84)))){
	goto T182;}
	V95= (V81)-(V80);
	goto T180;
T182:;
	V95= (V85)-(V84);
T180:;
	V96= V80;
	V97= V84;
T187:;
	if(!((V94)>=(V95))){
	goto T188;}
	{object V98 = (V74);
	VMR10(V98)}
T188:;
	V99= elt((V75),V97);
	(void)(elt_set((V74),V96,/* INLINE-ARGS */V99));
	V94= (1)+(V94);
	V96= (1)+(V96);
	V97= (1)+(V97);
	goto T187;}}}}}}
	}}
/*	local entry for function REMOVE	*/

static object LI11(V101,V100,va_alist)
	object V101,V100;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB11 VMS11 VMV11
	{object V102;
	object V103;
	object V104;
	object V105;
	object V106;
	object V107;
	object V108;
	object V109;
	object V110;
	if(narg <2) too_few_arguments();
	V102= V101;
	V103= V100;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI11key,ap);
	V104=(Vcs[2]);
	V105=(Vcs[3]);
	V106=(Vcs[4]);
	V107=(Vcs[5]);
	V108=(Vcs[6]);
	V109=(Vcs[7]);
	if(Vcs[8]==0){
	V110= symbol_function(VV[25]);
	}else{
	V110=(Vcs[8]);}
	{int V111;
	if(((V107))==Cnil){
	goto T201;}
	V111= (*(LnkLI19))((V107));
	goto T199;
T201:;
	V111= 0;
T199:;
	{int V112;
	V112= (*(LnkLI20))((V108),(V103));
	if(!((V111)<=(V112))){
	goto T205;}
	goto T204;
T205:;
	V113 = make_fixnum(V111);
	V114 = make_fixnum(V112);
	(void)((VFUN_NARGS=2,(*(LnkLI17))(V113,V114)));
T204:;
	{int V115;
	if(((V109))!=Cnil){
	goto T209;}
	V115= 2147483647;
	goto T207;
T209:;
	V115= fix((V109));
T207:;
	if((V105)==Cnil){
	goto T212;}
	if((V106)==Cnil){
	goto T212;}
	(void)((*(LnkLI26))());
T212:;
	if(((V104))!=Cnil){
	goto T214;}
	if(!(type_of((V103))==t_cons||((V103))==Cnil)){
	goto T217;}
	{register object V116;
	register object V117;
	V116= (V103);
	V117= Cnil;
	{register int V118;
	V118= 0;
T222:;
	if(!((V118)>=(V111))){
	goto T223;}
	goto T219;
T223:;
	V117= make_cons(car((V116)),(V117));
	{register object V119;
	V119= car((V116));
	V116= cdr((V116));}
	V118= (1)+(V118);
	goto T222;}
T219:;
	{register int V120;
	register int V121;
	V120= V111;
	V121= 0;
T239:;
	if((V120)>=(V112)){
	goto T241;}
	if((V121)>=(V115)){
	goto T241;}
	if(!(endp((V116)))){
	goto T240;}
T241:;
	base[0]= (V117);
	base[1]= (V116);
	vs_top=(vs_base=base+0)+2;
	Lreconc();
	vs_top=sup;
	{object V122 = vs_base[0];
	VMR11(V122)}
T240:;
	base[0]= car((V116));
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V110));
	vs_top=sup;
	V123= vs_base[0];
	if(((*(LnkLI27))((V105),(V106),(V102),V123))==Cnil){
	goto T252;}
	V121= (1)+(V121);
	{register object V124;
	V124= car((V116));
	V116= cdr((V116));
	goto T250;}
T252:;
	V117= make_cons(car((V116)),(V117));
	{register object V125;
	V125= car((V116));
	V116= cdr((V116));}
T250:;
	V120= (1)+(V120);
	goto T239;}}
T217:;
	V126 = make_fixnum(V111);
	V127 = make_fixnum(V112);
	V128 = make_fixnum(V115);
	{object V129 = (VFUN_NARGS=16,(*(LnkLI28))((V102),(V103),VV[10],(V104),VV[11],(V105),VV[12],(V106),VV[13],V126,VV[14],V127,VV[15],V128,VV[16],(V110)));
	VMR11(V129)}
T214:;
	V130 = make_fixnum(V111);
	V131 = make_fixnum(V112);
	V132 = make_fixnum(V115);
	{object V133 = (VFUN_NARGS=16,(*(LnkLI28))((V102),(V103),VV[10],(V104),VV[11],(V105),VV[12],(V106),VV[13],V130,VV[14],V131,VV[15],V132,VV[16],(V110)));
	VMR11(V133)}}}}}
	}}
/*	local entry for function REMOVE-IF	*/

static object LI12(V135,V134,va_alist)
	object V135,V134;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB12 VMS12 VMV12
	{object V136;
	object V137;
	object V138;
	object V139;
	object V140;
	object V141;
	object V142;
	if(narg <2) too_few_arguments();
	V136= V135;
	V137= V134;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI12key,ap);
	V138=(Vcs[2]);
	V139=(Vcs[3]);
	V140=(Vcs[4]);
	V141=(Vcs[5]);
	if(Vcs[6]==0){
	V142= symbol_function(VV[25]);
	}else{
	V142=(Vcs[6]);}
	V143= symbol_function(VV[30]);
	{object V144 = (VFUN_NARGS=14,(*(LnkLI29))((V136),(V137),VV[10],(V138),VV[11],V143,VV[13],(V139),VV[14],(V140),VV[15],(V141),VV[16],(V142)));
	VMR12(V144)}}
	}}
/*	local entry for function REMOVE-IF-NOT	*/

static object LI13(V146,V145,va_alist)
	object V146,V145;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB13 VMS13 VMV13
	{object V147;
	object V148;
	object V149;
	object V150;
	object V151;
	object V152;
	object V153;
	if(narg <2) too_few_arguments();
	V147= V146;
	V148= V145;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI13key,ap);
	V149=(Vcs[2]);
	V150=(Vcs[3]);
	V151=(Vcs[4]);
	V152=(Vcs[5]);
	if(Vcs[6]==0){
	V153= symbol_function(VV[25]);
	}else{
	V153=(Vcs[6]);}
	V154= symbol_function(VV[30]);
	{object V155 = (VFUN_NARGS=14,(*(LnkLI29))((V147),(V148),VV[10],(V149),VV[12],V154,VV[13],(V150),VV[14],(V151),VV[15],(V152),VV[16],(V153)));
	VMR13(V155)}}
	}}
/*	local entry for function DELETE	*/

static object LI14(V157,V156,va_alist)
	object V157,V156;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB14 VMS14 VMV14
	{object V158;
	register object V159;
	object V160;
	object V161;
	object V162;
	object V163;
	object V164;
	object V165;
	object V166;
	if(narg <2) too_few_arguments();
	V158= V157;
	V159= V156;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI14key,ap);
	V160=(Vcs[2]);
	V161=(Vcs[3]);
	V162=(Vcs[4]);
	V163=(Vcs[5]);
	V164=(Vcs[6]);
	V165=(Vcs[7]);
	if(Vcs[8]==0){
	V166= symbol_function(VV[25]);
	}else{
	V166=(Vcs[8]);}
	{int V167;
	V167= length((V159));
	{register int V168;
	if(((V163))==Cnil){
	goto T277;}
	V168= (*(LnkLI19))((V163));
	goto T275;
T277:;
	V168= 0;
T275:;
	{register int V169;
	V169= (*(LnkLI20))((V164),(V159));
	if(!((V168)<=(V169))){
	goto T281;}
	goto T280;
T281:;
	V170 = make_fixnum(V168);
	V171 = make_fixnum(V169);
	(void)((VFUN_NARGS=2,(*(LnkLI17))(V170,V171)));
T280:;
	{register int V172;
	if(((V165))!=Cnil){
	goto T285;}
	V172= 2147483647;
	goto T283;
T285:;
	V172= fix((V165));
T283:;
	if((V161)==Cnil){
	goto T288;}
	if((V162)==Cnil){
	goto T288;}
	(void)((*(LnkLI26))());
T288:;
	if(((V160))!=Cnil){
	goto T290;}
	if(!(type_of((V159))==t_cons||((V159))==Cnil)){
	goto T293;}
	{object V173;
	register object V174;
	V173= make_cons(Cnil,(V159));
	V174= (V173);
	{int V175;
	V175= 0;
T300:;
	if(!((V175)>=(V168))){
	goto T301;}
	goto T297;
T301:;
	{object V176;
	V176= car((V174));
	V174= cdr((V174));}
	V175= (1)+(V175);
	goto T300;}
T297:;
	{int V177;
	int V178;
	V177= V168;
	V178= 0;
T315:;
	if((V177)>=(V169)){
	goto T317;}
	if((V178)>=(V172)){
	goto T317;}
	if(!(endp(cdr((V174))))){
	goto T316;}
T317:;
	{object V179 = cdr((V173));
	VMR14(V179)}
T316:;
	base[1]= cadr((V174));
	vs_top=(vs_base=base+1)+1;
	super_funcall_no_event((V166));
	vs_top=sup;
	V180= vs_base[0];
	if(((*(LnkLI27))((V161),(V162),(V158),V180))==Cnil){
	goto T326;}
	V178= (1)+(V178);
	if(type_of((V174))!=t_cons)FEwrong_type_argument(Scons,(V174));
	((V174))->c.c_cdr = cddr((V174));
	goto T324;
T326:;
	V174= cdr((V174));
T324:;
	V177= (1)+(V177);
	goto T315;}}
T293:;
	{int V181;
	V182 = make_fixnum(V168);
	V183 = make_fixnum(V169);
	V184 = make_fixnum(V172);
	V181= fix((VFUN_NARGS=16,(*(LnkLI31))((V158),(V159),VV[10],(V160),VV[11],(V161),VV[12],(V162),VV[13],V182,VV[14],V183,VV[15],V184,VV[16],(V166))));
	if(!((V181)<(V172))){
	goto T337;}
	V172= V181;
T337:;
	{object V185;
	register int V186;
	int V187;
	int V188;
	V189= (*(LnkLI33))((V159));
	V190 = make_fixnum((V167)-(V172));
	V185= (VFUN_NARGS=2,(*(LnkLI32))(/* INLINE-ARGS */V189,V190));
	V186= 0;
	V187= 0;
	V188= 0;
T346:;
	if(!((V186)>=(V167))){
	goto T347;}
	{object V191 = (V185);
	VMR14(V191)}
T347:;
	if(!((V168)<=(V186))){
	goto T353;}
	if(!((V186)<(V169))){
	goto T353;}
	if(!((V188)<(V172))){
	goto T353;}
	base[0]= elt((V159),V186);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V166));
	vs_top=sup;
	V192= vs_base[0];
	if(((*(LnkLI27))((V161),(V162),(V158),V192))==Cnil){
	goto T353;}
	V188= (1)+(V188);
	goto T351;
T353:;
	V193= elt((V159),V186);
	(void)(elt_set((V185),V187,/* INLINE-ARGS */V193));
	V187= (1)+(V187);
T351:;
	V186= (1)+(V186);
	goto T346;}}
T290:;
	{int V194;
	V195 = make_fixnum(V168);
	V196 = make_fixnum(V169);
	V197 = make_fixnum(V172);
	V194= fix((VFUN_NARGS=16,(*(LnkLI31))((V158),(V159),VV[10],(V160),VV[11],(V161),VV[12],(V162),VV[13],V195,VV[14],V196,VV[15],V197,VV[16],(V166))));
	if(!((V194)<(V172))){
	goto T370;}
	V172= V194;
T370:;
	{object V198;
	register int V199;
	int V200;
	int V201;
	V202= (*(LnkLI33))((V159));
	V203 = make_fixnum((V167)-(V172));
	V198= (VFUN_NARGS=2,(*(LnkLI32))(/* INLINE-ARGS */V202,V203));
	V199= (-1)+(V167);
	V200= ((-1)+(V169))-(V194);
	V201= 0;
T379:;
	if(!((V199)<(0))){
	goto T380;}
	{object V204 = (V198);
	VMR14(V204)}
T380:;
	if(!((V168)<=(V199))){
	goto T386;}
	if(!((V199)<(V169))){
	goto T386;}
	if(!((V201)<(V172))){
	goto T386;}
	base[0]= elt((V159),V199);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V166));
	vs_top=sup;
	V205= vs_base[0];
	if(((*(LnkLI27))((V161),(V162),(V158),V205))==Cnil){
	goto T386;}
	V201= (1)+(V201);
	goto T384;
T386:;
	V206= elt((V159),V199);
	(void)(elt_set((V198),V200,/* INLINE-ARGS */V206));
	V200= (-1)+(V200);
T384:;
	V199= (-1)+(V199);
	goto T379;}}}}}}}
	}}
/*	local entry for function DELETE-IF	*/

static object LI15(V208,V207,va_alist)
	object V208,V207;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB15 VMS15 VMV15
	{object V209;
	object V210;
	object V211;
	object V212;
	object V213;
	object V214;
	object V215;
	if(narg <2) too_few_arguments();
	V209= V208;
	V210= V207;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI15key,ap);
	V211=(Vcs[2]);
	V212=(Vcs[3]);
	V213=(Vcs[4]);
	V214=(Vcs[5]);
	if(Vcs[6]==0){
	V215= symbol_function(VV[25]);
	}else{
	V215=(Vcs[6]);}
	V216= symbol_function(VV[30]);
	{object V217 = (VFUN_NARGS=14,(*(LnkLI28))((V209),(V210),VV[10],(V211),VV[11],V216,VV[13],(V212),VV[14],(V213),VV[15],(V214),VV[16],(V215)));
	VMR15(V217)}}
	}}
/*	local entry for function DELETE-IF-NOT	*/

static object LI16(V219,V218,va_alist)
	object V219,V218;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB16 VMS16 VMV16
	{object V220;
	object V221;
	object V222;
	object V223;
	object V224;
	object V225;
	object V226;
	if(narg <2) too_few_arguments();
	V220= V219;
	V221= V218;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI16key,ap);
	V222=(Vcs[2]);
	V223=(Vcs[3]);
	V224=(Vcs[4]);
	V225=(Vcs[5]);
	if(Vcs[6]==0){
	V226= symbol_function(VV[25]);
	}else{
	V226=(Vcs[6]);}
	V227= symbol_function(VV[30]);
	{object V228 = (VFUN_NARGS=14,(*(LnkLI28))((V220),(V221),VV[10],(V222),VV[12],V227,VV[13],(V223),VV[14],(V224),VV[15],(V225),VV[16],(V226)));
	VMR16(V228)}}
	}}
/*	local entry for function COUNT	*/

static object LI17(V230,V229,va_alist)
	object V230,V229;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB17 VMS17 VMV17
	{object V231;
	register object V232;
	object V233;
	register object V234;
	register object V235;
	object V236;
	object V237;
	object V238;
	if(narg <2) too_few_arguments();
	V231= V230;
	V232= V229;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI17key,ap);
	V233=(Vcs[2]);
	V234=(Vcs[3]);
	V235=(Vcs[4]);
	V236=(Vcs[5]);
	V237=(Vcs[6]);
	if(Vcs[7]==0){
	V238= symbol_function(VV[25]);
	}else{
	V238=(Vcs[7]);}
	{int V239;
	if(((V236))==Cnil){
	goto T409;}
	V239= (*(LnkLI19))((V236));
	goto T407;
T409:;
	V239= 0;
T407:;
	{int V240;
	V240= (*(LnkLI20))((V237),(V232));
	if(!((V239)<=(V240))){
	goto T413;}
	goto T412;
T413:;
	V241 = make_fixnum(V239);
	V242 = make_fixnum(V240);
	(void)((VFUN_NARGS=2,(*(LnkLI17))(V241,V242)));
T412:;
	if((V234)==Cnil){
	goto T415;}
	if((V235)==Cnil){
	goto T415;}
	(void)((*(LnkLI26))());
T415:;
	if(((V233))!=Cnil){
	goto T417;}
	{register int V243;
	register int V244;
	V243= V239;
	V244= 0;
T422:;
	if(!((V243)>=(V240))){
	goto T423;}
	{object V245 = make_fixnum(V244);
	VMR17(V245)}
T423:;
	base[0]= elt((V232),V243);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V238));
	vs_top=sup;
	V246= vs_base[0];
	if(((*(LnkLI27))((V234),(V235),(V231),V246))==Cnil){
	goto T427;}
	V244= (1)+(V244);
T427:;
	V243= (1)+(V243);
	goto T422;}
T417:;
	{register int V247;
	register int V248;
	V247= (-1)+(V240);
	V248= 0;
T439:;
	if(!((V247)<(V239))){
	goto T440;}
	{object V249 = make_fixnum(V248);
	VMR17(V249)}
T440:;
	base[0]= elt((V232),V247);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V238));
	vs_top=sup;
	V250= vs_base[0];
	if(((*(LnkLI27))((V234),(V235),(V231),V250))==Cnil){
	goto T444;}
	V248= (1)+(V248);
T444:;
	V247= (-1)+(V247);
	goto T439;}}}}
	}}
/*	local entry for function COUNT-IF	*/

static object LI18(V252,V251,va_alist)
	object V252,V251;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB18 VMS18 VMV18
	{object V253;
	object V254;
	object V255;
	object V256;
	object V257;
	object V258;
	if(narg <2) too_few_arguments();
	V253= V252;
	V254= V251;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI18key,ap);
	V255=(Vcs[2]);
	V256=(Vcs[3]);
	V257=(Vcs[4]);
	if(Vcs[5]==0){
	V258= symbol_function(VV[25]);
	}else{
	V258=(Vcs[5]);}
	V259= symbol_function(VV[30]);
	{object V260 = (VFUN_NARGS=12,(*(LnkLI34))((V253),(V254),VV[10],(V255),VV[11],V259,VV[13],(V256),VV[14],(V257),VV[16],(V258)));
	VMR18(V260)}}
	}}
/*	local entry for function COUNT-IF-NOT	*/

static object LI19(V262,V261,va_alist)
	object V262,V261;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB19 VMS19 VMV19
	{object V263;
	object V264;
	object V265;
	object V266;
	object V267;
	object V268;
	if(narg <2) too_few_arguments();
	V263= V262;
	V264= V261;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI19key,ap);
	V265=(Vcs[2]);
	V266=(Vcs[3]);
	V267=(Vcs[4]);
	if(Vcs[5]==0){
	V268= symbol_function(VV[25]);
	}else{
	V268=(Vcs[5]);}
	V269= symbol_function(VV[30]);
	{object V270 = (VFUN_NARGS=12,(*(LnkLI34))((V263),(V264),VV[10],(V265),VV[12],V269,VV[13],(V266),VV[14],(V267),VV[16],(V268)));
	VMR19(V270)}}
	}}
/*	local entry for function INTERNAL-COUNT	*/

static object LI20(V272,V271,va_alist)
	object V272,V271;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB20 VMS20 VMV20
	{object V273;
	register object V274;
	object V275;
	register object V276;
	register object V277;
	object V278;
	object V279;
	object V280;
	object V281;
	if(narg <2) too_few_arguments();
	V273= V272;
	V274= V271;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI20key,ap);
	V275=(Vcs[2]);
	V276=(Vcs[3]);
	V277=(Vcs[4]);
	V278=(Vcs[5]);
	V279=(Vcs[6]);
	V280=(Vcs[7]);
	if(Vcs[8]==0){
	V281= symbol_function(VV[25]);
	}else{
	V281=(Vcs[8]);}
	{int V282;
	if(((V278))==Cnil){
	goto T460;}
	V282= (*(LnkLI19))((V278));
	goto T458;
T460:;
	V282= 0;
T458:;
	{int V283;
	V283= (*(LnkLI20))((V279),(V274));
	if(!((V282)<=(V283))){
	goto T464;}
	goto T463;
T464:;
	V284 = make_fixnum(V282);
	V285 = make_fixnum(V283);
	(void)((VFUN_NARGS=2,(*(LnkLI17))(V284,V285)));
T463:;
	{int V286;
	if(((V280))!=Cnil){
	goto T468;}
	V286= 2147483647;
	goto T466;
T468:;
	V286= fix((V280));
T466:;
	if((V276)==Cnil){
	goto T471;}
	if((V277)==Cnil){
	goto T471;}
	(void)((*(LnkLI26))());
T471:;
	if(((V275))!=Cnil){
	goto T473;}
	{register int V287;
	register int V288;
	V287= V282;
	V288= 0;
T478:;
	if(!((V287)>=(V283))){
	goto T479;}
	{object V289 = make_fixnum(V288);
	VMR20(V289)}
T479:;
	if(!((V288)<(V286))){
	goto T483;}
	base[0]= elt((V274),V287);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V281));
	vs_top=sup;
	V290= vs_base[0];
	if(((*(LnkLI27))((V276),(V277),(V273),V290))==Cnil){
	goto T483;}
	V288= (1)+(V288);
T483:;
	V287= (1)+(V287);
	goto T478;}
T473:;
	{register int V291;
	register int V292;
	V291= (-1)+(V283);
	V292= 0;
T497:;
	if(!((V291)<(V282))){
	goto T498;}
	{object V293 = make_fixnum(V292);
	VMR20(V293)}
T498:;
	if(!((V292)<(V286))){
	goto T502;}
	base[0]= elt((V274),V291);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V281));
	vs_top=sup;
	V294= vs_base[0];
	if(((*(LnkLI27))((V276),(V277),(V273),V294))==Cnil){
	goto T502;}
	V292= (1)+(V292);
T502:;
	V291= (-1)+(V291);
	goto T497;}}}}}
	}}
/*	local entry for function INTERNAL-COUNT-IF	*/

static object LI21(V296,V295,va_alist)
	object V296,V295;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB21 VMS21 VMV21
	{object V297;
	object V298;
	object V299;
	object V300;
	object V301;
	object V302;
	object V303;
	if(narg <2) too_few_arguments();
	V297= V296;
	V298= V295;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI21key,ap);
	V299=(Vcs[2]);
	V300=(Vcs[3]);
	V301=(Vcs[4]);
	V302=(Vcs[5]);
	if(Vcs[6]==0){
	V303= symbol_function(VV[25]);
	}else{
	V303=(Vcs[6]);}
	V304= symbol_function(VV[30]);
	{object V305 = (VFUN_NARGS=14,(*(LnkLI31))((V297),(V298),VV[10],(V299),VV[11],V304,VV[13],(V300),VV[14],(V301),VV[15],(V302),VV[16],(V303)));
	VMR21(V305)}}
	}}
/*	local entry for function INTERNAL-COUNT-IF-NOT	*/

static object LI22(V307,V306,va_alist)
	object V307,V306;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB22 VMS22 VMV22
	{object V308;
	object V309;
	object V310;
	object V311;
	object V312;
	object V313;
	object V314;
	if(narg <2) too_few_arguments();
	V308= V307;
	V309= V306;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI22key,ap);
	V310=(Vcs[2]);
	V311=(Vcs[3]);
	V312=(Vcs[4]);
	V313=(Vcs[5]);
	if(Vcs[6]==0){
	V314= symbol_function(VV[25]);
	}else{
	V314=(Vcs[6]);}
	V315= symbol_function(VV[30]);
	{object V316 = (VFUN_NARGS=14,(*(LnkLI31))((V308),(V309),VV[10],(V310),VV[12],V315,VV[13],(V311),VV[14],(V312),VV[15],(V313),VV[16],(V314)));
	VMR22(V316)}}
	}}
/*	local entry for function SUBSTITUTE	*/

static object LI23(V319,V318,V317,va_alist)
	object V319,V318,V317;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB23 VMS23 VMV23
	{object V320;
	object V321;
	register object V322;
	object V323;
	object V324;
	object V325;
	object V326;
	object V327;
	object V328;
	object V329;
	if(narg <3) too_few_arguments();
	V320= V319;
	V321= V318;
	V322= V317;
	narg= narg - 3;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +3,&LI23key,ap);
	V323=(Vcs[3]);
	V324=(Vcs[4]);
	V325=(Vcs[5]);
	V326=(Vcs[6]);
	V327=(Vcs[7]);
	V328=(Vcs[8]);
	if(Vcs[9]==0){
	V329= symbol_function(VV[25]);
	}else{
	V329=(Vcs[9]);}
	{int V330;
	V330= length((V322));
	{int V331;
	if(((V326))==Cnil){
	goto T521;}
	V331= (*(LnkLI19))((V326));
	goto T519;
T521:;
	V331= 0;
T519:;
	{int V332;
	V332= (*(LnkLI20))((V327),(V322));
	if(!((V331)<=(V332))){
	goto T525;}
	goto T524;
T525:;
	V333 = make_fixnum(V331);
	V334 = make_fixnum(V332);
	(void)((VFUN_NARGS=2,(*(LnkLI17))(V333,V334)));
T524:;
	{int V335;
	if(((V328))!=Cnil){
	goto T529;}
	V335= 2147483647;
	goto T527;
T529:;
	V335= fix((V328));
T527:;
	if((V324)==Cnil){
	goto T532;}
	if((V325)==Cnil){
	goto T532;}
	(void)((*(LnkLI26))());
T532:;
	if(((V323))!=Cnil){
	goto T534;}
	{register object V336;
	register int V337;
	register int V338;
	V339= (*(LnkLI33))((V322));
	V340 = make_fixnum(V330);
	V336= (VFUN_NARGS=2,(*(LnkLI32))(/* INLINE-ARGS */V339,V340));
	V337= 0;
	V338= 0;
T540:;
	if(!((V337)>=(V330))){
	goto T541;}
	{object V341 = (V336);
	VMR23(V341)}
T541:;
	if(!((V331)<=(V337))){
	goto T547;}
	if(!((V337)<(V332))){
	goto T547;}
	if(!((V338)<(V335))){
	goto T547;}
	base[0]= elt((V322),V337);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V329));
	vs_top=sup;
	V342= vs_base[0];
	if(((*(LnkLI27))((V324),(V325),(V321),V342))==Cnil){
	goto T547;}
	(void)(elt_set((V336),V337,(V320)));
	V338= (1)+(V338);
	goto T545;
T547:;
	V343= elt((V322),V337);
	(void)(elt_set((V336),V337,/* INLINE-ARGS */V343));
T545:;
	V337= (1)+(V337);
	goto T540;}
T534:;
	{register object V344;
	register int V345;
	register int V346;
	V347= (*(LnkLI33))((V322));
	V348 = make_fixnum(V330);
	V344= (VFUN_NARGS=2,(*(LnkLI32))(/* INLINE-ARGS */V347,V348));
	V345= (-1)+(V330);
	V346= 0;
T566:;
	if(!((V345)<(0))){
	goto T567;}
	{object V349 = (V344);
	VMR23(V349)}
T567:;
	if(!((V331)<=(V345))){
	goto T573;}
	if(!((V345)<(V332))){
	goto T573;}
	if(!((V346)<(V335))){
	goto T573;}
	base[0]= elt((V322),V345);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V329));
	vs_top=sup;
	V350= vs_base[0];
	if(((*(LnkLI27))((V324),(V325),(V321),V350))==Cnil){
	goto T573;}
	(void)(elt_set((V344),V345,(V320)));
	V346= (1)+(V346);
	goto T571;
T573:;
	V351= elt((V322),V345);
	(void)(elt_set((V344),V345,/* INLINE-ARGS */V351));
T571:;
	V345= (-1)+(V345);
	goto T566;}}}}}}
	}}
/*	local entry for function SUBSTITUTE-IF	*/

static object LI24(V354,V353,V352,va_alist)
	object V354,V353,V352;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB24 VMS24 VMV24
	{object V355;
	object V356;
	object V357;
	object V358;
	object V359;
	object V360;
	object V361;
	object V362;
	if(narg <3) too_few_arguments();
	V355= V354;
	V356= V353;
	V357= V352;
	narg= narg - 3;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +3,&LI24key,ap);
	V358=(Vcs[3]);
	V359=(Vcs[4]);
	V360=(Vcs[5]);
	V361=(Vcs[6]);
	if(Vcs[7]==0){
	V362= symbol_function(VV[25]);
	}else{
	V362=(Vcs[7]);}
	V363= symbol_function(VV[30]);
	{object V364 = (VFUN_NARGS=15,(*(LnkLI35))((V355),(V356),(V357),VV[10],(V358),VV[11],V363,VV[13],(V359),VV[14],(V360),VV[15],(V361),VV[16],(V362)));
	VMR24(V364)}}
	}}
/*	local entry for function SUBSTITUTE-IF-NOT	*/

static object LI25(V367,V366,V365,va_alist)
	object V367,V366,V365;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB25 VMS25 VMV25
	{object V368;
	object V369;
	object V370;
	object V371;
	object V372;
	object V373;
	object V374;
	object V375;
	if(narg <3) too_few_arguments();
	V368= V367;
	V369= V366;
	V370= V365;
	narg= narg - 3;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +3,&LI25key,ap);
	V371=(Vcs[3]);
	V372=(Vcs[4]);
	V373=(Vcs[5]);
	V374=(Vcs[6]);
	if(Vcs[7]==0){
	V375= symbol_function(VV[25]);
	}else{
	V375=(Vcs[7]);}
	V376= symbol_function(VV[30]);
	{object V377 = (VFUN_NARGS=15,(*(LnkLI35))((V368),(V369),(V370),VV[10],(V371),VV[12],V376,VV[13],(V372),VV[14],(V373),VV[15],(V374),VV[16],(V375)));
	VMR25(V377)}}
	}}
/*	local entry for function NSUBSTITUTE	*/

static object LI26(V380,V379,V378,va_alist)
	object V380,V379,V378;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB26 VMS26 VMV26
	{object V381;
	object V382;
	register object V383;
	object V384;
	register object V385;
	register object V386;
	object V387;
	object V388;
	object V389;
	object V390;
	if(narg <3) too_few_arguments();
	V381= V380;
	V382= V379;
	V383= V378;
	narg= narg - 3;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +3,&LI26key,ap);
	V384=(Vcs[3]);
	V385=(Vcs[4]);
	V386=(Vcs[5]);
	V387=(Vcs[6]);
	V388=(Vcs[7]);
	V389=(Vcs[8]);
	if(Vcs[9]==0){
	V390= symbol_function(VV[25]);
	}else{
	V390=(Vcs[9]);}
	{int V391;
	if(((V387))==Cnil){
	goto T595;}
	V391= (*(LnkLI19))((V387));
	goto T593;
T595:;
	V391= 0;
T593:;
	{int V392;
	V392= (*(LnkLI20))((V388),(V383));
	if(!((V391)<=(V392))){
	goto T599;}
	goto T598;
T599:;
	V393 = make_fixnum(V391);
	V394 = make_fixnum(V392);
	(void)((VFUN_NARGS=2,(*(LnkLI17))(V393,V394)));
T598:;
	{int V395;
	if(((V389))!=Cnil){
	goto T603;}
	V395= 2147483647;
	goto T601;
T603:;
	V395= fix((V389));
T601:;
	if((V385)==Cnil){
	goto T606;}
	if((V386)==Cnil){
	goto T606;}
	(void)((*(LnkLI26))());
T606:;
	if(((V384))!=Cnil){
	goto T608;}
	{register int V396;
	register int V397;
	V396= V391;
	V397= 0;
T613:;
	if(!((V396)>=(V392))){
	goto T614;}
	{object V398 = (V383);
	VMR26(V398)}
T614:;
	if(!((V397)<(V395))){
	goto T618;}
	base[0]= elt((V383),V396);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V390));
	vs_top=sup;
	V399= vs_base[0];
	if(((*(LnkLI27))((V385),(V386),(V382),V399))==Cnil){
	goto T618;}
	(void)(elt_set((V383),V396,(V381)));
	V397= (1)+(V397);
T618:;
	V396= (1)+(V396);
	goto T613;}
T608:;
	{register int V400;
	register int V401;
	V400= (-1)+(V392);
	V401= 0;
T633:;
	if(!((V400)<(V391))){
	goto T634;}
	{object V402 = (V383);
	VMR26(V402)}
T634:;
	if(!((V401)<(V395))){
	goto T638;}
	base[0]= elt((V383),V400);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V390));
	vs_top=sup;
	V403= vs_base[0];
	if(((*(LnkLI27))((V385),(V386),(V382),V403))==Cnil){
	goto T638;}
	(void)(elt_set((V383),V400,(V381)));
	V401= (1)+(V401);
T638:;
	V400= (-1)+(V400);
	goto T633;}}}}}
	}}
/*	local entry for function NSUBSTITUTE-IF	*/

static object LI27(V406,V405,V404,va_alist)
	object V406,V405,V404;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB27 VMS27 VMV27
	{object V407;
	object V408;
	object V409;
	object V410;
	object V411;
	object V412;
	object V413;
	object V414;
	if(narg <3) too_few_arguments();
	V407= V406;
	V408= V405;
	V409= V404;
	narg= narg - 3;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +3,&LI27key,ap);
	V410=(Vcs[3]);
	V411=(Vcs[4]);
	V412=(Vcs[5]);
	V413=(Vcs[6]);
	if(Vcs[7]==0){
	V414= symbol_function(VV[25]);
	}else{
	V414=(Vcs[7]);}
	V415= symbol_function(VV[30]);
	{object V416 = (VFUN_NARGS=15,(*(LnkLI36))((V407),(V408),(V409),VV[10],(V410),VV[11],V415,VV[13],(V411),VV[14],(V412),VV[15],(V413),VV[16],(V414)));
	VMR27(V416)}}
	}}
/*	local entry for function NSUBSTITUTE-IF-NOT	*/

static object LI28(V419,V418,V417,va_alist)
	object V419,V418,V417;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB28 VMS28 VMV28
	{object V420;
	object V421;
	object V422;
	object V423;
	object V424;
	object V425;
	object V426;
	object V427;
	if(narg <3) too_few_arguments();
	V420= V419;
	V421= V418;
	V422= V417;
	narg= narg - 3;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +3,&LI28key,ap);
	V423=(Vcs[3]);
	V424=(Vcs[4]);
	V425=(Vcs[5]);
	V426=(Vcs[6]);
	if(Vcs[7]==0){
	V427= symbol_function(VV[25]);
	}else{
	V427=(Vcs[7]);}
	V428= symbol_function(VV[30]);
	{object V429 = (VFUN_NARGS=15,(*(LnkLI36))((V420),(V421),(V422),VV[10],(V423),VV[12],V428,VV[13],(V424),VV[14],(V425),VV[15],(V426),VV[16],(V427)));
	VMR28(V429)}}
	}}
/*	local entry for function FIND	*/

static object LI29(V431,V430,va_alist)
	object V431,V430;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB29 VMS29 VMV29
	{register object V432;
	register object V433;
	object V434;
	register object V435;
	register object V436;
	object V437;
	object V438;
	register object V439;
	if(narg <2) too_few_arguments();
	V432= V431;
	V433= V430;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI29key,ap);
	V434=(Vcs[2]);
	V435=(Vcs[3]);
	V436=(Vcs[4]);
	V437=(Vcs[5]);
	V438=(Vcs[6]);
	if(Vcs[7]==0){
	V439= symbol_function(VV[25]);
	}else{
	V439=(Vcs[7]);}
	{int V440;
	if(((V437))==Cnil){
	goto T657;}
	V440= (*(LnkLI19))((V437));
	goto T655;
T657:;
	V440= 0;
T655:;
	{int V441;
	V441= (*(LnkLI20))((V438),(V433));
	if(!((V440)<=(V441))){
	goto T661;}
	goto T660;
T661:;
	V442 = make_fixnum(V440);
	V443 = make_fixnum(V441);
	(void)((VFUN_NARGS=2,(*(LnkLI17))(V442,V443)));
T660:;
	if((V435)==Cnil){
	goto T663;}
	if((V436)==Cnil){
	goto T663;}
	(void)((*(LnkLI26))());
T663:;
	if(((V434))!=Cnil){
	goto T665;}
	{register int V444;
	V444= V440;
T669:;
	if(!((V444)>=(V441))){
	goto T670;}
	{object V445 = Cnil;
	VMR29(V445)}
T670:;
	base[0]= elt((V433),V444);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V439));
	vs_top=sup;
	V446= vs_base[0];
	if(((*(LnkLI27))((V435),(V436),(V432),V446))==Cnil){
	goto T674;}
	{object V447 = elt((V433),V444);
	VMR29(V447)}
T674:;
	V444= (1)+(V444);
	goto T669;}
T665:;
	{register int V448;
	V448= (-1)+(V441);
T684:;
	if(!((V448)<(V440))){
	goto T685;}
	{object V449 = Cnil;
	VMR29(V449)}
T685:;
	base[0]= elt((V433),V448);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V439));
	vs_top=sup;
	V450= vs_base[0];
	if(((*(LnkLI27))((V435),(V436),(V432),V450))==Cnil){
	goto T689;}
	{object V451 = elt((V433),V448);
	VMR29(V451)}
T689:;
	V448= (-1)+(V448);
	goto T684;}}}}
	}}
/*	local entry for function FIND-IF	*/

static object LI30(V453,V452,va_alist)
	object V453,V452;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB30 VMS30 VMV30
	{object V454;
	object V455;
	object V456;
	object V457;
	object V458;
	object V459;
	if(narg <2) too_few_arguments();
	V454= V453;
	V455= V452;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI30key,ap);
	V456=(Vcs[2]);
	V457=(Vcs[3]);
	V458=(Vcs[4]);
	if(Vcs[5]==0){
	V459= symbol_function(VV[25]);
	}else{
	V459=(Vcs[5]);}
	V460= symbol_function(VV[30]);
	{object V461 = (VFUN_NARGS=12,(*(LnkLI37))((V454),(V455),VV[10],(V456),VV[11],V460,VV[13],(V457),VV[14],(V458),VV[16],(V459)));
	VMR30(V461)}}
	}}
/*	local entry for function FIND-IF-NOT	*/

static object LI31(V463,V462,va_alist)
	object V463,V462;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB31 VMS31 VMV31
	{object V464;
	object V465;
	object V466;
	object V467;
	object V468;
	object V469;
	if(narg <2) too_few_arguments();
	V464= V463;
	V465= V462;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI31key,ap);
	V466=(Vcs[2]);
	V467=(Vcs[3]);
	V468=(Vcs[4]);
	if(Vcs[5]==0){
	V469= symbol_function(VV[25]);
	}else{
	V469=(Vcs[5]);}
	V470= symbol_function(VV[30]);
	{object V471 = (VFUN_NARGS=12,(*(LnkLI37))((V464),(V465),VV[10],(V466),VV[12],V470,VV[13],(V467),VV[14],(V468),VV[16],(V469)));
	VMR31(V471)}}
	}}
/*	local entry for function POSITION	*/

static object LI32(V473,V472,va_alist)
	object V473,V472;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB32 VMS32 VMV32
	{register object V474;
	register object V475;
	object V476;
	register object V477;
	register object V478;
	object V479;
	object V480;
	register object V481;
	if(narg <2) too_few_arguments();
	V474= V473;
	V475= V472;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI32key,ap);
	V476=(Vcs[2]);
	V477=(Vcs[3]);
	V478=(Vcs[4]);
	V479=(Vcs[5]);
	V480=(Vcs[6]);
	if(Vcs[7]==0){
	V481= symbol_function(VV[25]);
	}else{
	V481=(Vcs[7]);}
	{int V482;
	if(((V479))==Cnil){
	goto T704;}
	V482= (*(LnkLI19))((V479));
	goto T702;
T704:;
	V482= 0;
T702:;
	{int V483;
	V483= (*(LnkLI20))((V480),(V475));
	if(!((V482)<=(V483))){
	goto T708;}
	goto T707;
T708:;
	V484 = make_fixnum(V482);
	V485 = make_fixnum(V483);
	(void)((VFUN_NARGS=2,(*(LnkLI17))(V484,V485)));
T707:;
	if((V477)==Cnil){
	goto T710;}
	if((V478)==Cnil){
	goto T710;}
	(void)((*(LnkLI26))());
T710:;
	if(((V476))!=Cnil){
	goto T712;}
	{register int V486;
	V486= V482;
T716:;
	if(!((V486)>=(V483))){
	goto T717;}
	{object V487 = Cnil;
	VMR32(V487)}
T717:;
	base[0]= elt((V475),V486);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V481));
	vs_top=sup;
	V488= vs_base[0];
	if(((*(LnkLI27))((V477),(V478),(V474),V488))==Cnil){
	goto T721;}
	{object V489 = make_fixnum(V486);
	VMR32(V489)}
T721:;
	V486= (1)+(V486);
	goto T716;}
T712:;
	{register int V490;
	V490= (-1)+(V483);
T731:;
	if(!((V490)<(V482))){
	goto T732;}
	{object V491 = Cnil;
	VMR32(V491)}
T732:;
	base[0]= elt((V475),V490);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V481));
	vs_top=sup;
	V492= vs_base[0];
	if(((*(LnkLI27))((V477),(V478),(V474),V492))==Cnil){
	goto T736;}
	{object V493 = make_fixnum(V490);
	VMR32(V493)}
T736:;
	V490= (-1)+(V490);
	goto T731;}}}}
	}}
/*	local entry for function POSITION-IF	*/

static object LI33(V495,V494,va_alist)
	object V495,V494;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB33 VMS33 VMV33
	{object V496;
	object V497;
	object V498;
	object V499;
	object V500;
	object V501;
	if(narg <2) too_few_arguments();
	V496= V495;
	V497= V494;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI33key,ap);
	V498=(Vcs[2]);
	V499=(Vcs[3]);
	V500=(Vcs[4]);
	if(Vcs[5]==0){
	V501= symbol_function(VV[25]);
	}else{
	V501=(Vcs[5]);}
	V502= symbol_function(VV[30]);
	{object V503 = (VFUN_NARGS=12,(*(LnkLI38))((V496),(V497),VV[10],(V498),VV[11],V502,VV[13],(V499),VV[14],(V500),VV[16],(V501)));
	VMR33(V503)}}
	}}
/*	local entry for function POSITION-IF-NOT	*/

static object LI34(V505,V504,va_alist)
	object V505,V504;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB34 VMS34 VMV34
	{object V506;
	object V507;
	object V508;
	object V509;
	object V510;
	object V511;
	if(narg <2) too_few_arguments();
	V506= V505;
	V507= V504;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI34key,ap);
	V508=(Vcs[2]);
	V509=(Vcs[3]);
	V510=(Vcs[4]);
	if(Vcs[5]==0){
	V511= symbol_function(VV[25]);
	}else{
	V511=(Vcs[5]);}
	V512= symbol_function(VV[30]);
	{object V513 = (VFUN_NARGS=12,(*(LnkLI38))((V506),(V507),VV[10],(V508),VV[12],V512,VV[13],(V509),VV[14],(V510),VV[16],(V511)));
	VMR34(V513)}}
	}}
/*	local entry for function REMOVE-DUPLICATES	*/

static object LI35(V514,va_alist)
	object V514;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB35 VMS35 VMV35
	{register object V515;
	object V516;
	register object V517;
	register object V518;
	object V519;
	object V520;
	register object V521;
	if(narg <1) too_few_arguments();
	V515= V514;
	narg= narg - 1;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +1,&LI35key,ap);
	V516=(Vcs[1]);
	V517=(Vcs[2]);
	V518=(Vcs[3]);
	V519=(Vcs[4]);
	V520=(Vcs[5]);
	if(Vcs[6]==0){
	V521= symbol_function(VV[25]);
	}else{
	V521=(Vcs[6]);}
	if((V517)==Cnil){
	goto T749;}
	if((V518)==Cnil){
	goto T749;}
	(void)((*(LnkLI26))());
T749:;
	if(!(type_of((V515))==t_cons||((V515))==Cnil)){
	goto T750;}
	if(((V516))!=Cnil){
	goto T750;}
	if(((V519))!=Cnil){
	goto T750;}
	if(((V520))!=Cnil){
	goto T750;}
	if(!(endp((V515)))){
	goto T759;}
	{object V522 = Cnil;
	VMR35(V522)}
T759:;
	{register object V523;
	register object V524;
	V523= (V515);
	V524= Cnil;
T763:;
	if(!(endp(cdr((V523))))){
	goto T764;}
	base[0]= (V524);
	base[1]= (V523);
	vs_top=(vs_base=base+0)+2;
	Lreconc();
	vs_top=sup;
	{object V525 = vs_base[0];
	VMR35(V525)}
T764:;
	base[0]= car((V523));
	base[1]= cdr((V523));
	base[2]= VV[11];
	base[3]= (V517);
	base[4]= VV[12];
	base[5]= (V518);
	base[6]= VV[16];
	base[7]= (V521);
	vs_top=(vs_base=base+0)+8;
	(void) (*Lnk39)();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T770;}
	V524= make_cons(car((V523)),(V524));
T770:;
	V523= cdr((V523));
	goto T763;}
T750:;
	{object V526 = (VFUN_NARGS=13,(*(LnkLI40))((V515),VV[10],(V516),VV[11],(V517),VV[12],(V518),VV[13],(V519),VV[14],(V520),VV[16],(V521)));
	VMR35(V526)}}
	}}
/*	local entry for function DELETE-DUPLICATES	*/

static object LI36(V527,va_alist)
	object V527;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB36 VMS36 VMV36
	{register object V528;
	object V529;
	object V530;
	object V531;
	object V532;
	object V533;
	register object V534;
	if(narg <1) too_few_arguments();
	V528= V527;
	narg= narg - 1;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +1,&LI36key,ap);
	V529=(Vcs[1]);
	V530=(Vcs[2]);
	V531=(Vcs[3]);
	V532=(Vcs[4]);
	V533=(Vcs[5]);
	if(Vcs[6]==0){
	V534= symbol_function(VV[25]);
	}else{
	V534=(Vcs[6]);}
	{int V535;
	V535= length((V528));
	if((V530)==Cnil){
	goto T787;}
	if((V531)==Cnil){
	goto T787;}
	(void)((*(LnkLI26))());
T787:;
	if(!(type_of((V528))==t_cons||((V528))==Cnil)){
	goto T788;}
	if(((V529))!=Cnil){
	goto T788;}
	if(((V532))!=Cnil){
	goto T788;}
	if(((V533))!=Cnil){
	goto T788;}
	if(!(endp((V528)))){
	goto T797;}
	{object V536 = Cnil;
	VMR36(V536)}
T797:;
	{register object V537;
	V537= (V528);
T801:;
	if(!(endp(cdr((V537))))){
	goto T802;}
	{object V538 = (V528);
	VMR36(V538)}
T802:;
	base[0]= car((V537));
	base[1]= cdr((V537));
	base[2]= VV[11];
	base[3]= (V530);
	base[4]= VV[12];
	base[5]= (V531);
	base[6]= VV[16];
	base[7]= (V534);
	vs_top=(vs_base=base+0)+8;
	(void) (*Lnk39)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T808;}
	if(type_of((V537))!=t_cons)FEwrong_type_argument(Scons,(V537));
	((V537))->c.c_car = cadr((V537));
	if(type_of((V537))!=t_cons)FEwrong_type_argument(Scons,(V537));
	((V537))->c.c_cdr = cddr((V537));
	goto T806;
T808:;
	V537= cdr((V537));
T806:;
	goto T801;}
T788:;
	{register int V539;
	if(((V532))==Cnil){
	goto T824;}
	V539= (*(LnkLI19))((V532));
	goto T822;
T824:;
	V539= 0;
T822:;
	{register int V540;
	V540= (*(LnkLI20))((V533),(V528));
	if(!((V539)<=(V540))){
	goto T828;}
	goto T827;
T828:;
	V541 = make_fixnum(V539);
	V542 = make_fixnum(V540);
	(void)((VFUN_NARGS=2,(*(LnkLI17))(V541,V542)));
T827:;
	if(((V529))!=Cnil){
	goto T831;}
	{int V543;
	int V544;
	V543= 0;
	V544= V539;
T836:;
	if(!((V544)>=(V540))){
	goto T837;}
	{object V545;
	register int V546;
	int V547;
	V548= (*(LnkLI33))((V528));
	V549 = make_fixnum((V535)-(V543));
	V545= (VFUN_NARGS=2,(*(LnkLI32))(/* INLINE-ARGS */V548,V549));
	V546= 0;
	V547= 0;
T844:;
	if(!((V546)>=(V535))){
	goto T845;}
	{object V550 = (V545);
	VMR36(V550)}
T845:;
	{object V551;
	if((V539)<=(V546)){
	goto T851;}
	V551= Cnil;
	goto T850;
T851:;
	if((V546)<(V540)){
	goto T853;}
	V551= Cnil;
	goto T850;
T853:;
	base[0]= elt((V528),V546);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V534));
	vs_top=sup;
	V552= vs_base[0];
	V553 = make_fixnum((1)+(V546));
	V554 = make_fixnum(V540);
	V551= (VFUN_NARGS=12,(*(LnkLI38))(V552,(V528),VV[11],(V530),VV[12],(V531),VV[13],V553,VV[14],V554,VV[16],(V534)));
T850:;
	if(((V551))==Cnil){
	goto T858;}
	goto T849;
T858:;
	V555= elt((V528),V546);
	(void)(elt_set((V545),V547,/* INLINE-ARGS */V555));
	V547= (1)+(V547);}
T849:;
	V546= (1)+(V546);
	goto T844;}
T837:;
	base[0]= elt((V528),V544);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V534));
	vs_top=sup;
	V556= vs_base[0];
	V557 = make_fixnum((1)+(V544));
	V558 = make_fixnum(V540);
	if(((VFUN_NARGS=12,(*(LnkLI38))(V556,(V528),VV[11],(V530),VV[12],(V531),VV[13],V557,VV[14],V558,VV[16],(V534))))==Cnil){
	goto T866;}
	V543= (1)+(V543);
T866:;
	V544= (1)+(V544);
	goto T836;}
T831:;
	{int V559;
	int V560;
	V559= 0;
	V560= (-1)+(V540);
T878:;
	if(!((V560)<(V539))){
	goto T879;}
	{object V561;
	register int V562;
	int V563;
	V564= (*(LnkLI33))((V528));
	V565 = make_fixnum((V535)-(V559));
	V561= (VFUN_NARGS=2,(*(LnkLI32))(/* INLINE-ARGS */V564,V565));
	V562= (-1)+(V535);
	V563= ((-1)+(V535))-(V559);
T886:;
	if(!((V562)<(0))){
	goto T887;}
	{object V566 = (V561);
	VMR36(V566)}
T887:;
	{object V567;
	if((V539)<=(V562)){
	goto T893;}
	V567= Cnil;
	goto T892;
T893:;
	if((V562)<(V540)){
	goto T895;}
	V567= Cnil;
	goto T892;
T895:;
	base[0]= elt((V528),V562);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V534));
	vs_top=sup;
	V568= vs_base[0];
	V569 = make_fixnum(V539);
	V570 = make_fixnum(V562);
	V567= (VFUN_NARGS=14,(*(LnkLI38))(V568,(V528),VV[10],Ct,VV[11],(V530),VV[12],(V531),VV[13],V569,VV[14],V570,VV[16],(V534)));
T892:;
	if(((V567))==Cnil){
	goto T900;}
	goto T891;
T900:;
	V571= elt((V528),V562);
	(void)(elt_set((V561),V563,/* INLINE-ARGS */V571));
	V563= (-1)+(V563);}
T891:;
	V562= (-1)+(V562);
	goto T886;}
T879:;
	base[0]= elt((V528),V560);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V534));
	vs_top=sup;
	V572= vs_base[0];
	V573 = make_fixnum(V539);
	V574 = make_fixnum(V560);
	if(((VFUN_NARGS=14,(*(LnkLI38))(V572,(V528),VV[10],Ct,VV[11],(V530),VV[12],(V531),VV[13],V573,VV[14],V574,VV[16],(V534))))==Cnil){
	goto T908;}
	V559= (1)+(V559);
T908:;
	V560= (-1)+(V560);
	goto T878;}}}}}
	}}
/*	local entry for function MISMATCH	*/

static object LI37(V576,V575,va_alist)
	object V576,V575;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB37 VMS37 VMV37
	{object V577;
	object V578;
	object V579;
	object V580;
	object V581;
	register object V582;
	object V583;
	object V584;
	object V585;
	object V586;
	if(narg <2) too_few_arguments();
	V577= V576;
	V578= V575;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI37key,ap);
	V579=(Vcs[2]);
	V580=(Vcs[3]);
	V581=(Vcs[4]);
	if(Vcs[5]==0){
	V582= symbol_function(VV[25]);
	}else{
	V582=(Vcs[5]);}
	V583=(Vcs[6]);
	V584=(Vcs[7]);
	V585=(Vcs[8]);
	V586=(Vcs[9]);
	if((V580)==Cnil){
	goto T918;}
	if((V581)==Cnil){
	goto T918;}
	(void)((*(LnkLI26))());
T918:;
	{register int V587;
	if(((V583))==Cnil){
	goto T921;}
	V587= (*(LnkLI19))((V583));
	goto T919;
T921:;
	V587= 0;
T919:;
	{register int V588;
	V588= (*(LnkLI20))((V585),(V577));
	if(!((V587)<=(V588))){
	goto T925;}
	goto T924;
T925:;
	V589 = make_fixnum(V587);
	V590 = make_fixnum(V588);
	(void)((VFUN_NARGS=2,(*(LnkLI17))(V589,V590)));
T924:;
	{register int V591;
	if(((V584))==Cnil){
	goto T929;}
	V591= (*(LnkLI19))((V584));
	goto T927;
T929:;
	V591= 0;
T927:;
	{register int V592;
	V592= (*(LnkLI20))((V586),(V578));
	if(!((V591)<=(V592))){
	goto T933;}
	goto T932;
T933:;
	V593 = make_fixnum(V591);
	V594 = make_fixnum(V592);
	(void)((VFUN_NARGS=2,(*(LnkLI17))(V593,V594)));
T932:;
	if(((V579))!=Cnil){
	goto T936;}
	{register int V595;
	register int V596;
	V595= V587;
	V596= V591;
T941:;
	if((V595)>=(V588)){
	goto T943;}
	if(!((V596)>=(V592))){
	goto T942;}
T943:;
	if(!((V595)>=(V588))){
	goto T948;}
	if(!((V596)>=(V592))){
	goto T948;}
	{object V597 = Cnil;
	VMR37(V597)}
T948:;
	{object V598 = make_fixnum(V595);
	VMR37(V598)}
T942:;
	base[0]= elt((V577),V595);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V582));
	vs_top=sup;
	V599= vs_base[0];
	base[0]= elt((V578),V596);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V582));
	vs_top=sup;
	V600= vs_base[0];
	if(((*(LnkLI27))((V580),(V581),V599,V600))!=Cnil){
	goto T953;}
	{object V601 = make_fixnum(V595);
	VMR37(V601)}
T953:;
	V595= (1)+(V595);
	V596= (1)+(V596);
	goto T941;}
T936:;
	{register int V602;
	register int V603;
	V602= (-1)+(V588);
	V603= (-1)+(V592);
T967:;
	if((V602)<(V587)){
	goto T969;}
	if(!((V603)<(V591))){
	goto T968;}
T969:;
	if(!((V602)<(V587))){
	goto T974;}
	if(!((V603)<(V591))){
	goto T974;}
	{object V604 = Cnil;
	VMR37(V604)}
T974:;
	{object V605 = make_fixnum((1)+(V602));
	VMR37(V605)}
T968:;
	base[0]= elt((V577),V602);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V582));
	vs_top=sup;
	V606= vs_base[0];
	base[0]= elt((V578),V603);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V582));
	vs_top=sup;
	V607= vs_base[0];
	if(((*(LnkLI27))((V580),(V581),V606,V607))!=Cnil){
	goto T979;}
	{object V608 = make_fixnum((1)+(V602));
	VMR37(V608)}
T979:;
	V602= (-1)+(V602);
	V603= (-1)+(V603);
	goto T967;}}}}}}
	}}
/*	local entry for function SEARCH	*/

static object LI38(V610,V609,va_alist)
	object V610,V609;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB38 VMS38 VMV38
	{object V611;
	object V612;
	object V613;
	object V614;
	object V615;
	register object V616;
	object V617;
	object V618;
	object V619;
	object V620;
	if(narg <2) too_few_arguments();
	V611= V610;
	V612= V609;
	narg= narg - 2;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +2,&LI38key,ap);
	V613=(Vcs[2]);
	V614=(Vcs[3]);
	V615=(Vcs[4]);
	if(Vcs[5]==0){
	V616= symbol_function(VV[25]);
	}else{
	V616=(Vcs[5]);}
	V617=(Vcs[6]);
	V618=(Vcs[7]);
	V619=(Vcs[8]);
	V620=(Vcs[9]);
	if((V614)==Cnil){
	goto T991;}
	if((V615)==Cnil){
	goto T991;}
	(void)((*(LnkLI26))());
T991:;
	{int V621;
	if(((V617))==Cnil){
	goto T994;}
	V621= (*(LnkLI19))((V617));
	goto T992;
T994:;
	V621= 0;
T992:;
	{int V622;
	V622= (*(LnkLI20))((V619),(V611));
	if(!((V621)<=(V622))){
	goto T998;}
	goto T997;
T998:;
	V623 = make_fixnum(V621);
	V624 = make_fixnum(V622);
	(void)((VFUN_NARGS=2,(*(LnkLI17))(V623,V624)));
T997:;
	{register int V625;
	if(((V618))==Cnil){
	goto T1002;}
	V625= (*(LnkLI19))((V618));
	goto T1000;
T1002:;
	V625= 0;
T1000:;
	{int V626;
	V626= (*(LnkLI20))((V620),(V612));
	if(!((V625)<=(V626))){
	goto T1006;}
	goto T1005;
T1006:;
	V627 = make_fixnum(V625);
	V628 = make_fixnum(V626);
	(void)((VFUN_NARGS=2,(*(LnkLI17))(V627,V628)));
T1005:;
	if(((V613))!=Cnil){
	goto T1009;}
T1012:;
	{register int V629;
	register int V630;
	V629= V621;
	V630= V625;
T1018:;
	if(!((V629)>=(V622))){
	goto T1019;}
	{object V631 = make_fixnum(V625);
	VMR38(V631)}
T1019:;
	if(!((V630)>=(V626))){
	goto T1023;}
	{object V632 = Cnil;
	VMR38(V632)}
T1023:;
	base[0]= elt((V611),V629);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V616));
	vs_top=sup;
	V633= vs_base[0];
	base[0]= elt((V612),V630);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V616));
	vs_top=sup;
	V634= vs_base[0];
	if(((*(LnkLI27))((V614),(V615),V633,V634))!=Cnil){
	goto T1026;}
	goto T1014;
T1026:;
	V629= (1)+(V629);
	V630= (1)+(V630);
	goto T1018;}
T1014:;
	V625= (1)+(V625);
	goto T1012;
T1009:;
T1040:;
	{register int V635;
	register int V636;
	V635= (-1)+(V622);
	V636= (-1)+(V626);
T1046:;
	if(!((V635)<(V621))){
	goto T1047;}
	{object V637 = make_fixnum((1)+(V636));
	VMR38(V637)}
T1047:;
	if(!((V636)<(V625))){
	goto T1051;}
	{object V638 = Cnil;
	VMR38(V638)}
T1051:;
	base[0]= elt((V611),V635);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V616));
	vs_top=sup;
	V639= vs_base[0];
	base[0]= elt((V612),V636);
	vs_top=(vs_base=base+0)+1;
	super_funcall_no_event((V616));
	vs_top=sup;
	V640= vs_base[0];
	if(((*(LnkLI27))((V614),(V615),V639,V640))!=Cnil){
	goto T1054;}
	goto T1042;
T1054:;
	V635= (-1)+(V635);
	V636= (-1)+(V636);
	goto T1046;}
T1042:;
	V626= (-1)+(V626);
	goto T1040;}}}}}
	}}
/*	function definition for SORT	*/

static L39()
{register object *base=vs_base;
	register object *sup=base+VM39; VC39
	vs_reserve(VM39);
	{register object V641;
	object V642;
	object V643;
	if(vs_top-vs_base<2) too_few_arguments();
	parse_key(vs_base+2,FALSE,FALSE,1,VV[16]);
	V641=(base[0]);
	V642=(base[1]);
	vs_top=sup;
	if(base[3]==Cnil){
	V643= symbol_function(VV[25]);
	}else{
	V643=(base[2]);}
	if(!(type_of((V641))==t_cons||((V641))==Cnil)){
	goto T1069;}
	base[4]= (V641);
	base[5]= (V642);
	base[6]= (V643);
	vs_top=(vs_base=base+4)+3;
	(void) (*Lnk41)();
	return;
T1069:;
	base[4]= (*(LnkLI42))((V641),0,length((V641)),(V642),(V643));
	vs_top=(vs_base=base+4)+1;
	return;
	}
}
/*	function definition for LIST-MERGE-SORT	*/

static L40()
{register object *base=vs_base;
	register object *sup=base+VM40; VC40
	vs_reserve(VM40);
	{object V644;
	check_arg(3);
	V644=(base[0]);
	vs_top=sup;
TTL:;
	base[3]= (V644);
	vs_top=(vs_base=base+3)+1;
	L41(base);
	return;
	}
}
/*	local entry for function QUICK-SORT	*/

static object LI42(V650,V651,V652,V653,V654)

register object V650;int V651;int V652;register object V653;register object V654;
{	 VMB41 VMS41 VMV41
TTL:;
	if(!((V652)<=((1)+(V651)))){
	goto T1076;}
	{object V655 = (V650);
	VMR41(V655)}
T1076:;
	{register int V656;
	register int V657;
	object V658;
	register object V659;
	V656= V651;
	V657= V652;
	V658= elt((V650),V651);
	V659= (
	(type_of((V654)) == t_sfun ?(*(object (*)())(((V654))->sfn.sfn_self)):
	(fcall.fun=((V654)),fcall.argd=1,fcalln))((V658)));
T1084:;
T1088:;
	V657= (-1)+(V657);
	if((V656)<(V657)){
	goto T1092;}
	goto T1082;
T1092:;
	base[3]= elt((V650),V657);
	vs_top=(vs_base=base+3)+1;
	super_funcall_no_event((V654));
	vs_top=sup;
	base[2]= vs_base[0];
	base[3]= (V659);
	vs_top=(vs_base=base+2)+2;
	super_funcall_no_event((V653));
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T1089;}
	goto T1086;
T1089:;
	goto T1088;
T1086:;
T1103:;
	V656= (1)+(V656);
	if((V656)<(V657)){
	goto T1107;}
	goto T1082;
T1107:;
	base[3]= elt((V650),V656);
	vs_top=(vs_base=base+3)+1;
	super_funcall_no_event((V654));
	vs_top=sup;
	base[2]= vs_base[0];
	base[3]= (V659);
	vs_top=(vs_base=base+2)+2;
	super_funcall_no_event((V653));
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T1104;}
	goto T1101;
T1104:;
	goto T1103;
T1101:;
	{object V660;
	V660= elt((V650),V656);
	V661= elt((V650),V657);
	(void)(elt_set((V650),V656,/* INLINE-ARGS */V661));
	(void)(elt_set((V650),V657,(V660)));}
	goto T1084;
T1082:;
	V662= elt((V650),V656);
	(void)(elt_set((V650),V651,/* INLINE-ARGS */V662));
	(void)(elt_set((V650),V656,(V658)));
	(void)((*(LnkLI42))((V650),V651,V656,(V653),(V654)));
	V651= (1)+(V656);
	goto TTL;}
}
/*	function definition for STABLE-SORT	*/

static L43()
{register object *base=vs_base;
	register object *sup=base+VM42; VC42
	vs_reserve(VM42);
	{register object V663;
	object V664;
	object V665;
	if(vs_top-vs_base<2) too_few_arguments();
	parse_key(vs_base+2,FALSE,FALSE,1,VV[16]);
	V663=(base[0]);
	V664=(base[1]);
	vs_top=sup;
	if(base[3]==Cnil){
	V665= symbol_function(VV[25]);
	}else{
	V665=(base[2]);}
	if(!(type_of((V663))==t_cons||((V663))==Cnil)){
	goto T1130;}
	base[4]= (V663);
	base[5]= (V664);
	base[6]= (V665);
	vs_top=(vs_base=base+4)+3;
	(void) (*Lnk41)();
	return;
T1130:;
	if(type_of((V663))==t_string){
	goto T1135;}
	if(!((type_of((V663))==t_bitvector))){
	goto T1136;}
T1135:;
	base[4]= (V663);
	base[5]= (V664);
	base[6]= VV[16];
	base[7]= (V665);
	vs_top=(vs_base=base+4)+4;
	(void) (*Lnk43)();
	return;
T1136:;
	base[4]= (*(LnkLI44))((V663),VV[0]);
	base[5]= (V664);
	base[6]= (V665);
	vs_top=(vs_base=base+4)+3;
	(void) (*Lnk41)();
	vs_top=sup;
	V666= vs_base[0];
	V667= (*(LnkLI33))((V663));
	base[4]= (*(LnkLI44))(V666,/* INLINE-ARGS */V667);
	vs_top=(vs_base=base+4)+1;
	return;
	}
}
/*	local entry for function MERGE	*/

static object LI44(V671,V670,V669,V668,va_alist)
	object V671,V670,V669,V668;
	va_dcl 
{	
	va_list ap;
	int narg = VFUN_NARGS; VMB43 VMS43 VMV43
	{object V672;
	register object V673;
	register object V674;
	object V675;
	object V676;
	if(narg <4) too_few_arguments();
	V672= V671;
	V673= V670;
	V674= V669;
	V675= V668;
	narg= narg - 4;
	va_start(ap);
	{
	parse_key_new(narg,Vcs +4,&LI44key,ap);
	if(Vcs[4]==0){
	V676= symbol_function(VV[25]);
	}else{
	V676=(Vcs[4]);}
	{int V677;
	int V678;
	V677= length((V673));
	V678= length((V674));
	{register object V679;
	register int V680;
	register int V681;
	register int V682;
	V683 = make_fixnum((V677)+(V678));
	V679= (VFUN_NARGS=2,(*(LnkLI32))((V672),V683));
	V680= 0;
	V681= 0;
	V682= 0;
T1156:;
	if(!((V681)==(V677))){
	goto T1157;}
	if(!((V682)==(V678))){
	goto T1157;}
	{object V684 = (V679);
	VMR43(V684)}
T1157:;
	if(!((V681)<(V677))){
	goto T1165;}
	if(!((V682)<(V678))){
	goto T1165;}
	base[1]= elt((V673),V681);
	vs_top=(vs_base=base+1)+1;
	super_funcall_no_event((V676));
	vs_top=sup;
	base[0]= vs_base[0];
	base[2]= elt((V674),V682);
	vs_top=(vs_base=base+2)+1;
	super_funcall_no_event((V676));
	vs_top=sup;
	base[1]= vs_base[0];
	vs_top=(vs_base=base+0)+2;
	super_funcall_no_event((V675));
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T1170;}
	V685= elt((V673),V681);
	(void)(elt_set((V679),V680,/* INLINE-ARGS */V685));
	V681= (1)+(V681);
	goto T1163;
T1170:;
	base[1]= elt((V674),V682);
	vs_top=(vs_base=base+1)+1;
	super_funcall_no_event((V676));
	vs_top=sup;
	base[0]= vs_base[0];
	base[2]= elt((V673),V681);
	vs_top=(vs_base=base+2)+1;
	super_funcall_no_event((V676));
	vs_top=sup;
	base[1]= vs_base[0];
	vs_top=(vs_base=base+0)+2;
	super_funcall_no_event((V675));
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T1179;}
	V686= elt((V674),V682);
	(void)(elt_set((V679),V680,/* INLINE-ARGS */V686));
	V682= (1)+(V682);
	goto T1163;
T1179:;
	V687= elt((V673),V681);
	(void)(elt_set((V679),V680,/* INLINE-ARGS */V687));
	V681= (1)+(V681);
	goto T1163;
T1165:;
	if(!((V681)<(V677))){
	goto T1190;}
	V688= elt((V673),V681);
	(void)(elt_set((V679),V680,/* INLINE-ARGS */V688));
	V681= (1)+(V681);
	goto T1163;
T1190:;
	V689= elt((V674),V682);
	(void)(elt_set((V679),V680,/* INLINE-ARGS */V689));
	V682= (1)+(V682);
T1163:;
	V680= (1)+(V680);
	goto T1156;}}}
	}}
/*	local function SORT	*/

static L41(base0)
register object *base0;
{	register object *base=vs_base;
	register object *sup=base+VM44; VC44
	vs_reserve(VM44);
	{object V690;
	check_arg(1);
	V690=(base[0]);
	vs_top=sup;
TTL:;
	{int V691;
	register object V692;
	register object V693;
	object V694;
	register object V695;
	register object V696;
	register object V697;
	V691= 0;
	V692= Cnil;
	V693= Cnil;
	V694= Cnil;
	V695= Cnil;
	V696= Cnil;
	V697= Cnil;
	V691= length((V690));
	if(!((V691)<(2))){
	goto T1208;}
	base[1]= (V690);
	vs_top=(vs_base=base+1)+1;
	return;
T1208:;
	if(!((V691)==(2))){
	goto T1206;}
	V696= (
	(type_of(base0[2]) == t_sfun ?(*(object (*)())((base0[2])->sfn.sfn_self)):
	(fcall.fun=(base0[2]),fcall.argd=1,fcalln))(car((V690))));
	V697= (
	(type_of(base0[2]) == t_sfun ?(*(object (*)())((base0[2])->sfn.sfn_self)):
	(fcall.fun=(base0[2]),fcall.argd=1,fcalln))(cadr((V690))));
	base[1]= (V696);
	base[2]= (V697);
	vs_top=(vs_base=base+1)+2;
	super_funcall_no_event(base0[1]);
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T1217;}
	base[1]= (V690);
	vs_top=(vs_base=base+1)+1;
	return;
T1217:;
	base[1]= (V697);
	base[2]= (V696);
	vs_top=(vs_base=base+1)+2;
	super_funcall_no_event(base0[1]);
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T1222;}
	base[1]= nreverse((V690));
	vs_top=(vs_base=base+1)+1;
	return;
T1222:;
	base[1]= (V690);
	vs_top=(vs_base=base+1)+1;
	return;
T1206:;
	V691= (V691>=0&&(2)>0?(V691)/(2):ifloor(V691,2));
	{int V698;
	register object V699;
	V698= 1;
	V699= (V690);
T1231:;
	if(!((V698)>=(V691))){
	goto T1232;}
	V692= (V690);
	V693= cdr((V699));
	if(type_of((V699))!=t_cons)FEwrong_type_argument(Scons,(V699));
	((V699))->c.c_cdr = Cnil;
	goto T1228;
T1232:;
	V698= (1)+(V698);
	V699= cdr((V699));
	goto T1231;}
T1228:;
	base[1]= (V692);
	vs_top=(vs_base=base+1)+1;
	L41(base0);
	vs_top=sup;
	V692= vs_base[0];
	base[1]= (V693);
	vs_top=(vs_base=base+1)+1;
	L41(base0);
	vs_top=sup;
	V693= vs_base[0];
	if(!(endp((V692)))){
	goto T1252;}
	base[1]= (V693);
	vs_top=(vs_base=base+1)+1;
	return;
T1252:;
	if(!(endp((V693)))){
	goto T1250;}
	base[1]= (V692);
	vs_top=(vs_base=base+1)+1;
	return;
T1250:;
	V694= make_cons(Cnil,Cnil);
	V695= (V694);
	V696= (
	(type_of(base0[2]) == t_sfun ?(*(object (*)())((base0[2])->sfn.sfn_self)):
	(fcall.fun=(base0[2]),fcall.argd=1,fcalln))(car((V692))));
	V697= (
	(type_of(base0[2]) == t_sfun ?(*(object (*)())((base0[2])->sfn.sfn_self)):
	(fcall.fun=(base0[2]),fcall.argd=1,fcalln))(car((V693))));
T1201:;
	base[1]= (V696);
	base[2]= (V697);
	vs_top=(vs_base=base+1)+2;
	super_funcall_no_event(base0[1]);
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T1264;}
	goto T1202;
T1264:;
	base[1]= (V697);
	base[2]= (V696);
	vs_top=(vs_base=base+1)+2;
	super_funcall_no_event(base0[1]);
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T1269;}
	goto T1203;
T1269:;
	goto T1202;
T1202:;
	if(type_of((V695))!=t_cons)FEwrong_type_argument(Scons,(V695));
	((V695))->c.c_cdr = (V692);
	V695= cdr((V695));
	V692= cdr((V692));
	if(!(endp((V692)))){
	goto T1278;}
	if(type_of((V695))!=t_cons)FEwrong_type_argument(Scons,(V695));
	((V695))->c.c_cdr = (V693);
	base[1]= cdr((V694));
	vs_top=(vs_base=base+1)+1;
	return;
T1278:;
	V696= (
	(type_of(base0[2]) == t_sfun ?(*(object (*)())((base0[2])->sfn.sfn_self)):
	(fcall.fun=(base0[2]),fcall.argd=1,fcalln))(car((V692))));
	goto T1201;
T1203:;
	if(type_of((V695))!=t_cons)FEwrong_type_argument(Scons,(V695));
	((V695))->c.c_cdr = (V693);
	V695= cdr((V695));
	V693= cdr((V693));
	if(!(endp((V693)))){
	goto T1289;}
	if(type_of((V695))!=t_cons)FEwrong_type_argument(Scons,(V695));
	((V695))->c.c_cdr = (V692);
	base[1]= cdr((V694));
	vs_top=(vs_base=base+1)+1;
	return;
T1289:;
	V697= (
	(type_of(base0[2]) == t_sfun ?(*(object (*)())((base0[2])->sfn.sfn_self)):
	(fcall.fun=(base0[2]),fcall.argd=1,fcalln))(car((V693))));
	goto T1201;}
	}
}
static object  LnkTLI44(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[44],&LnkLI44,2,ap);} /* COERCE */
static LnkT43(){ call_or_link(VV[43],&Lnk43);} /* SORT */
static object  LnkTLI42(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[42],&LnkLI42,81925,ap);} /* QUICK-SORT */
static LnkT41(){ call_or_link(VV[41],&Lnk41);} /* LIST-MERGE-SORT */
static object  LnkTLI40(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[40],&LnkLI40,ap);} /* DELETE-DUPLICATES */
static LnkT39(){ call_or_link(VV[39],&Lnk39);} /* MEMBER1 */
static object  LnkTLI38(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[38],&LnkLI38,ap);} /* POSITION */
static object  LnkTLI37(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[37],&LnkLI37,ap);} /* FIND */
static object  LnkTLI36(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[36],&LnkLI36,ap);} /* NSUBSTITUTE */
static object  LnkTLI35(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[35],&LnkLI35,ap);} /* SUBSTITUTE */
static object  LnkTLI34(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[34],&LnkLI34,ap);} /* COUNT */
static object  LnkTLI33(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[33],&LnkLI33,1,ap);} /* SEQTYPE */
static object  LnkTLI32(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[32],&LnkLI32,ap);} /* MAKE-SEQUENCE */
static object  LnkTLI31(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[31],&LnkLI31,ap);} /* INTERNAL-COUNT */
static object  LnkTLI29(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[29],&LnkLI29,ap);} /* REMOVE */
static object  LnkTLI28(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[28],&LnkLI28,ap);} /* DELETE */
static object  LnkTLI27(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[27],&LnkLI27,4,ap);} /* CALL-TEST */
static object  LnkTLI26(){return call_proc0(VV[26],&LnkLI26);} /* TEST-ERROR */
static int  LnkTLI20(va_alist)va_dcl{va_list ap;va_start(ap);return(int )call_proc(VV[20],&LnkLI20,258,ap);} /* THE-END */
static int  LnkTLI19(va_alist)va_dcl{va_list ap;va_start(ap);return(int )call_proc(VV[19],&LnkLI19,257,ap);} /* THE-START */
static object  LnkTLI17(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[17],&LnkLI17,ap);} /* BAD-SEQ-LIMIT */
