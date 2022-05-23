
#include <cmpinclude.h>
#include "predlib.h"
init_predlib(){do_init(VV);}
/*	macro definition for DEFTYPE	*/

static L1()
{register object *base=vs_base;
	register object *sup=base+VM1; VC1
	vs_reserve(VM1);
	check_arg(2);
	vs_top=sup;
	{object V1=base[0]->c.c_cdr;
	if(endp(V1))invalid_macro_call();
	base[2]= (V1->c.c_car);
	V1=V1->c.c_cdr;
	if(endp(V1))invalid_macro_call();
	base[3]= (V1->c.c_car);
	V1=V1->c.c_cdr;
	base[4]= V1;}
	{register object V2;
	register object V3;
	V2= base[3];
	V3= Cnil;
T3:;
	if(((V2))!=Cnil){
	goto T4;}
	goto T1;
T4:;
	{register object x= car((V2)),V4= VV[0];
	while(!endp(V4))
	if(eql(x,V4->c.c_car)){
	goto T10;
	}else V4=V4->c.c_cdr;
	goto T8;}
T10:;
	if((car((V2)))==(VV[1])){
	goto T11;}
	goto T1;
T11:;
	V3= make_cons(VV[1],(V3));
	V2= cdr((V2));
T20:;
	if(((V2))==Cnil){
	goto T22;}
	{register object x= car((V2)),V5= VV[0];
	while(!endp(V5))
	if(eql(x,V5->c.c_car)){
	goto T25;
	}else V5=V5->c.c_cdr;
	goto T21;}
T25:;
T22:;
	goto T18;
T21:;
	if(!(type_of(car((V2)))==t_symbol)){
	goto T29;}
	V6= list(2,car((V2)),VV[2]);
	V3= make_cons(/* INLINE-ARGS */V6,(V3));
	goto T27;
T29:;
	V3= make_cons(car((V2)),(V3));
T27:;
	V2= cdr((V2));
	goto T20;
T18:;
	base[5]= (V3);
	base[6]= (V2);
	vs_top=(vs_base=base+5)+2;
	Lreconc();
	vs_top=sup;
	base[3]= vs_base[0];
	goto T1;
T8:;
	{object V7;
	V7= cdr((V2));
	V3= make_cons(car((V2)),(V3));
	V2= (V7);}
	goto T3;}
T1:;
	V8= list(2,VV[6],base[2]);
	V9= list(4,VV[5],/* INLINE-ARGS */V8,list(2,VV[6],listA(4,VV[7],base[2],base[3],base[4])),VV[8]);
	V10= list(2,VV[6],base[2]);
	V11= list(4,VV[5],/* INLINE-ARGS */V10,list(2,VV[9],listA(3,VV[10],base[3],base[4])),VV[11]);
	V12= list(2,VV[6],base[2]);
	V13= (*(LnkLI71))(base[4]);
	V14= list(4,VV[5],/* INLINE-ARGS */V12,/* INLINE-ARGS */V13,VV[12]);
	base[5]= list(6,VV[3],VV[4],/* INLINE-ARGS */V9,/* INLINE-ARGS */V11,/* INLINE-ARGS */V14,list(2,VV[6],base[2]));
	vs_top=(vs_base=base+5)+1;
	return;
}
/*	function definition for G1054	*/

static L2()
{register object *base=vs_base;
	register object *sup=base+VM2; VC2
	vs_reserve(VM2);
	check_arg(0);
	vs_top=sup;
TTL:;
	base[0]= list(3,VV[13],VV[14],VV[15]);
	vs_top=(vs_base=base+0)+1;
	return;
}
/*	function definition for G1055	*/

static L3()
{register object *base=vs_base;
	register object *sup=base+VM3; VC3
	vs_reserve(VM3);
	check_arg(0);
	vs_top=sup;
TTL:;
	base[0]= VV[16];
	vs_top=(vs_base=base+0)+1;
	return;
}
/*	function definition for G1056	*/

static L4()
{register object *base=vs_base;
	register object *sup=base+VM4; VC4
	vs_reserve(VM4);
	{object V15;
	check_arg(1);
	V15=(base[0]);
	vs_top=sup;
TTL:;
	base[1]= list(3,VV[13],small_fixnum(0),one_minus((V15)));
	vs_top=(vs_base=base+1)+1;
	return;
	}
}
/*	function definition for G1057	*/

static L5()
{register object *base=vs_base;
	register object *sup=base+VM5; VC5
	vs_reserve(VM5);
	{object V16;
	if(vs_top-vs_base>1) too_many_arguments();
	if(vs_base>=vs_top){vs_top=sup;goto T45;}
	V16=(base[0]);
	vs_top=sup;
	goto T46;
T45:;
	V16= VV[17];
T46:;
	if(!(((V16))==(VV[17]))){
	goto T49;}
	base[1]= VV[18];
	vs_top=(vs_base=base+1)+1;
	return;
T49:;
	V17= one_minus((V16));
	V18= number_expt(small_fixnum(2),/* INLINE-ARGS */V17);
	V19= number_negate(/* INLINE-ARGS */V18);
	V20= one_minus((V16));
	V21= number_expt(small_fixnum(2),/* INLINE-ARGS */V20);
	base[1]= list(3,VV[13],/* INLINE-ARGS */V19,one_minus(/* INLINE-ARGS */V21));
	vs_top=(vs_base=base+1)+1;
	return;
	}
}
/*	function definition for G1058	*/

static L6()
{register object *base=vs_base;
	register object *sup=base+VM6; VC6
	vs_reserve(VM6);
	{object V22;
	if(vs_top-vs_base>1) too_many_arguments();
	if(vs_base>=vs_top){vs_top=sup;goto T51;}
	V22=(base[0]);
	vs_top=sup;
	goto T52;
T51:;
	V22= VV[17];
T52:;
	if(!(((V22))==(VV[17]))){
	goto T55;}
	base[1]= VV[19];
	vs_top=(vs_base=base+1)+1;
	return;
T55:;
	V23= number_expt(small_fixnum(2),(V22));
	base[1]= list(3,VV[13],small_fixnum(0),one_minus(/* INLINE-ARGS */V23));
	vs_top=(vs_base=base+1)+1;
	return;
	}
}
/*	function definition for G1059	*/

static L7()
{register object *base=vs_base;
	register object *sup=base+VM7; VC7
	vs_reserve(VM7);
	check_arg(0);
	vs_top=sup;
TTL:;
	base[0]= list(2,VV[20],small_fixnum(8));
	vs_top=(vs_base=base+0)+1;
	return;
}
/*	function definition for G1060	*/

static L8()
{register object *base=vs_base;
	register object *sup=base+VM8; VC8
	vs_reserve(VM8);
	check_arg(0);
	vs_top=sup;
TTL:;
	base[0]= list(2,VV[21],small_fixnum(8));
	vs_top=(vs_base=base+0)+1;
	return;
}
/*	function definition for G1061	*/

static L9()
{register object *base=vs_base;
	register object *sup=base+VM9; VC9
	vs_reserve(VM9);
	check_arg(0);
	vs_top=sup;
TTL:;
	base[0]= list(2,VV[20],small_fixnum(16));
	vs_top=(vs_base=base+0)+1;
	return;
}
/*	function definition for G1062	*/

static L10()
{register object *base=vs_base;
	register object *sup=base+VM10; VC10
	vs_reserve(VM10);
	check_arg(0);
	vs_top=sup;
TTL:;
	base[0]= list(2,VV[21],small_fixnum(16));
	vs_top=(vs_base=base+0)+1;
	return;
}
/*	function definition for G1063	*/

static L11()
{register object *base=vs_base;
	register object *sup=base+VM11; VC11
	vs_reserve(VM11);
	{object V24;
	object V25;
	if(vs_top-vs_base>2) too_many_arguments();
	if(vs_base>=vs_top){vs_top=sup;goto T57;}
	V24=(base[0]);
	vs_base++;
	if(vs_base>=vs_top){vs_top=sup;goto T58;}
	V25=(base[1]);
	vs_top=sup;
	goto T59;
T57:;
	V24= VV[17];
T58:;
	V25= VV[17];
T59:;
	base[2]= list(3,VV[22],(V24),make_cons((V25),Cnil));
	vs_top=(vs_base=base+2)+1;
	return;
	}
}
/*	function definition for G1064	*/

static L12()
{register object *base=vs_base;
	register object *sup=base+VM12; VC12
	vs_reserve(VM12);
	{object V26;
	if(vs_top-vs_base>1) too_many_arguments();
	if(vs_base>=vs_top){vs_top=sup;goto T62;}
	V26=(base[0]);
	vs_top=sup;
	goto T63;
T62:;
	V26= VV[17];
T63:;
	base[1]= list(3,VV[23],VV[24],(V26));
	vs_top=(vs_base=base+1)+1;
	return;
	}
}
/*	function definition for G1065	*/

static L13()
{register object *base=vs_base;
	register object *sup=base+VM13; VC13
	vs_reserve(VM13);
	{object V27;
	if(vs_top-vs_base>1) too_many_arguments();
	if(vs_base>=vs_top){vs_top=sup;goto T65;}
	V27=(base[0]);
	vs_top=sup;
	goto T66;
T65:;
	V27= VV[17];
T66:;
	base[1]= list(3,VV[23],VV[25],(V27));
	vs_top=(vs_base=base+1)+1;
	return;
	}
}
/*	function definition for G1066	*/

static L14()
{register object *base=vs_base;
	register object *sup=base+VM14; VC14
	vs_reserve(VM14);
	{object V28;
	if(vs_top-vs_base>1) too_many_arguments();
	if(vs_base>=vs_top){vs_top=sup;goto T68;}
	V28=(base[0]);
	vs_top=sup;
	goto T69;
T68:;
	V28= VV[17];
T69:;
	base[1]= list(3,VV[26],Ct,make_cons((V28),Cnil));
	vs_top=(vs_base=base+1)+1;
	return;
	}
}
/*	function definition for G1067	*/

static L15()
{register object *base=vs_base;
	register object *sup=base+VM15; VC15
	vs_reserve(VM15);
	{object V29;
	if(vs_top-vs_base>1) too_many_arguments();
	if(vs_base>=vs_top){vs_top=sup;goto T71;}
	V29=(base[0]);
	vs_top=sup;
	goto T72;
T71:;
	V29= VV[17];
T72:;
	base[1]= list(3,VV[26],VV[24],make_cons((V29),Cnil));
	vs_top=(vs_base=base+1)+1;
	return;
	}
}
/*	function definition for G1068	*/

static L16()
{register object *base=vs_base;
	register object *sup=base+VM16; VC16
	vs_reserve(VM16);
	{object V30;
	if(vs_top-vs_base>1) too_many_arguments();
	if(vs_base>=vs_top){vs_top=sup;goto T74;}
	V30=(base[0]);
	vs_top=sup;
	goto T75;
T74:;
	V30= VV[17];
T75:;
	base[1]= list(3,VV[26],VV[25],make_cons((V30),Cnil));
	vs_top=(vs_base=base+1)+1;
	return;
	}
}
/*	local entry for function SIMPLE-ARRAY-P	*/

static object LI17(V32)

register object V32;
{	 VMB17 VMS17 VMV17
TTL:;
	if(type_of((V32))==t_array||
type_of((V32))==t_vector||
type_of((V32))==t_string||
type_of((V32))==t_bitvector){
	goto T77;}
	{object V33 = Cnil;
	VMR17(V33)}
T77:;
	base[0]= (V32);
	vs_top=(vs_base=base+0)+1;
	Ladjustable_array_p();
	vs_top=sup;
	V34= vs_base[0];
	if((V34)==Cnil){
	goto T79;}
	{object V35 = Cnil;
	VMR17(V35)}
T79:;
	base[0]= (V32);
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk72)();
	vs_top=sup;
	V36= vs_base[0];
	if((V36)==Cnil){
	goto T83;}
	{object V37 = Cnil;
	VMR17(V37)}
T83:;
	base[0]= (V32);
	vs_top=(vs_base=base+0)+1;
	siLdisplaced_array_p();
	vs_top=sup;
	V38= vs_base[0];
	{object V39 = ((V38)==Cnil?Ct:Cnil);
	VMR17(V39)}
}
/*	function definition for TYPEP	*/

static L18()
{register object *base=vs_base;
	register object *sup=base+VM18; VC18
	vs_reserve(VM18);
	{register object V40;
	register object V41;
	check_arg(2);
	V40=(base[0]);
	V41=(base[1]);
	vs_top=sup;
TTL:;
	{register object V42;
	register object V43;
	object V44;
	V42= Cnil;
	V43= Cnil;
	V44= Cnil;
	if(!(type_of((V41))!=t_cons)){
	goto T94;}
	V42= (V41);
	V43= Cnil;
	goto T92;
T94:;
	V42= car((V41));
	V43= cdr((V41));
T92:;
	{object V45;
	V45= get((V42),VV[27],Cnil);
	if(((V45))==Cnil){
	goto T102;}
	base[2]= (V40);
	vs_top=(vs_base=base+2)+1;
	super_funcall_no_event((V45));
	return;}
T102:;
	{object V46= (V42);
	if((V46!= VV[36]))goto T107;
	{register object x= (V40),V47= (V43);
	while(!endp(V47))
	if(eql(x,V47->c.c_car)){
	base[2]= V47;
	vs_top=(vs_base=base+2)+1;
	return;
	}else V47=V47->c.c_cdr;
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;}
T107:;
	if((V46!= VV[39]))goto T108;
	base[2]= (V40);
	base[3]= car((V43));
	vs_top=(vs_base=base+2)+2;
	(void) (*Lnk73)();
	vs_top=sup;
	V48= vs_base[0];
	base[2]= ((V48)==Cnil?Ct:Cnil);
	vs_top=(vs_base=base+2)+1;
	return;
T108:;
	if((V46!= VV[37]))goto T112;
	{register object V49;
	V49= (V43);
T114:;
	if(((V49))!=Cnil){
	goto T115;}
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T115:;
	base[2]= (V40);
	base[3]= car((V49));
	vs_top=(vs_base=base+2)+2;
	(void) (*Lnk73)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T119;}
	base[2]= Ct;
	vs_top=(vs_base=base+2)+1;
	return;
T119:;
	V49= cdr((V49));
	goto T114;}
T112:;
	if((V46!= VV[38]))goto T127;
	{register object V50;
	V50= (V43);
T129:;
	if(((V50))!=Cnil){
	goto T130;}
	base[2]= Ct;
	vs_top=(vs_base=base+2)+1;
	return;
T130:;
	base[2]= (V40);
	base[3]= car((V50));
	vs_top=(vs_base=base+2)+2;
	(void) (*Lnk73)();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T134;}
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T134:;
	V50= cdr((V50));
	goto T129;}
T127:;
	if((V46!= VV[74]))goto T142;
	base[2]= car((V43));
	base[3]= (V40);
	vs_top=(vs_base=base+3)+1;
	super_funcall_no_event(base[2]);
	return;
T142:;
	if((V46!= Ct))goto T145;
	base[2]= Ct;
	vs_top=(vs_base=base+2)+1;
	return;
T145:;
	if((V46!= Cnil))goto T146;
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T146:;
	if((V46!= VV[28]))goto T147;
	base[2]= (V40);
	vs_top=(vs_base=base+2)+1;
	Ltype_of();
	vs_top=sup;
	V51= vs_base[0];
	base[2]= ((V51)==(VV[28])?Ct:Cnil);
	vs_top=(vs_base=base+2)+1;
	return;
T147:;
	if((V46!= VV[29]))goto T150;
	base[2]= (V40);
	vs_top=(vs_base=base+2)+1;
	Ltype_of();
	vs_top=sup;
	V52= vs_base[0];
	base[2]= ((V52)==(VV[29])?Ct:Cnil);
	vs_top=(vs_base=base+2)+1;
	return;
T150:;
	if((V46!= VV[30]))goto T153;
	base[2]= (V40);
	vs_top=(vs_base=base+2)+1;
	Ltype_of();
	vs_top=sup;
	V53= vs_base[0];
	base[2]= ((V53)==(VV[30])?Ct:Cnil);
	vs_top=(vs_base=base+2)+1;
	return;
T153:;
	if((V46!= VV[75]))goto T156;
	if(type_of((V40))==t_character){
	goto T157;}
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T157:;
	base[2]= (V40);
	vs_top=(vs_base=base+2)+1;
	Lstandard_char_p();
	return;
T156:;
	if((V46!= VV[24]))goto T160;
	if(type_of((V40))==t_character){
	goto T161;}
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T161:;
	base[2]= (V40);
	vs_top=(vs_base=base+2)+1;
	Lstring_char_p();
	return;
T160:;
	if((V46!= VV[13]))goto T164;
	if(type_of((V40))==t_fixnum||type_of((V40))==t_bignum){
	goto T165;}
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T165:;
	base[2]= (*(LnkLI76))((V40),(V43));
	vs_top=(vs_base=base+2)+1;
	return;
T164:;
	if((V46!= VV[59]))goto T167;
	base[2]= (V40);
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk77)();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T168;}
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T168:;
	base[2]= (*(LnkLI76))((V40),(V43));
	vs_top=(vs_base=base+2)+1;
	return;
T167:;
	if((V46!= VV[60]))goto T171;
	if(type_of((V40))==t_shortfloat||type_of((V40))==t_longfloat){
	goto T172;}
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T172:;
	base[2]= (*(LnkLI76))((V40),(V43));
	vs_top=(vs_base=base+2)+1;
	return;
T171:;
	if((V46!= VV[31]))goto T174;
	base[2]= (V40);
	vs_top=(vs_base=base+2)+1;
	Ltype_of();
	vs_top=sup;
	V54= vs_base[0];
	if((V54)==(VV[31])){
	goto T175;}
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T175:;
	base[2]= (*(LnkLI76))((V40),(V43));
	vs_top=(vs_base=base+2)+1;
	return;
T174:;
	if((V46!= VV[78])
	&& (V46!= VV[79])
	&& (V46!= VV[32]))goto T179;
	base[2]= (V40);
	vs_top=(vs_base=base+2)+1;
	Ltype_of();
	vs_top=sup;
	V55= vs_base[0];
	if((V55)==(VV[32])){
	goto T180;}
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T180:;
	base[2]= (*(LnkLI76))((V40),(V43));
	vs_top=(vs_base=base+2)+1;
	return;
T179:;
	if((V46!= VV[63]))goto T184;
	base[2]= (V40);
	vs_top=(vs_base=base+2)+1;
	Lcomplexp();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T185;}
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T185:;
	if(!(((V43))==Cnil)){
	goto T188;}
	base[2]= Ct;
	vs_top=(vs_base=base+2)+1;
	return;
T188:;
	base[3]= (V40);
	vs_top=(vs_base=base+3)+1;
	Lrealpart();
	vs_top=sup;
	base[2]= vs_base[0];
	base[3]= car((V43));
	vs_top=(vs_base=base+2)+2;
	(void) (*Lnk73)();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T190;}
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T190:;
	base[2]= (V40);
	vs_top=(vs_base=base+2)+1;
	Limagpart();
	vs_top=sup;
	V40= vs_base[0];
	V41= car((V43));
	goto TTL;
T184:;
	if((V46!= VV[43]))goto T199;
	if(!(type_of((V40))==t_cons||((V40))==Cnil)){
	goto T200;}
	base[2]= Ct;
	vs_top=(vs_base=base+2)+1;
	return;
T200:;
	base[2]= (type_of((V40))==t_vector||
type_of((V40))==t_string||
type_of((V40))==t_bitvector?Ct:Cnil);
	vs_top=(vs_base=base+2)+1;
	return;
T199:;
	if((V46!= VV[80]))goto T202;
	if(type_of((V40))==t_string){
	goto T203;}
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T203:;
	if(!(((V43))==Cnil)){
	goto T205;}
	base[2]= Ct;
	vs_top=(vs_base=base+2)+1;
	return;
T205:;
	V56= (*(LnkLI82))((V40));
	base[2]= (*(LnkLI81))(/* INLINE-ARGS */V56,(V43));
	vs_top=(vs_base=base+2)+1;
	return;
T202:;
	if((V46!= VV[83]))goto T207;
	if((type_of((V40))==t_bitvector)){
	goto T208;}
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T208:;
	if(!(((V43))==Cnil)){
	goto T210;}
	base[2]= Ct;
	vs_top=(vs_base=base+2)+1;
	return;
T210:;
	V57= (*(LnkLI82))((V40));
	base[2]= (*(LnkLI81))(/* INLINE-ARGS */V57,(V43));
	vs_top=(vs_base=base+2)+1;
	return;
T207:;
	if((V46!= VV[84]))goto T212;
	base[2]= (V40);
	vs_top=(vs_base=base+2)+1;
	Lsimple_string_p();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T213;}
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T213:;
	if(!(((V43))==Cnil)){
	goto T216;}
	base[2]= Ct;
	vs_top=(vs_base=base+2)+1;
	return;
T216:;
	V58= (*(LnkLI82))((V40));
	base[2]= (*(LnkLI81))(/* INLINE-ARGS */V58,(V43));
	vs_top=(vs_base=base+2)+1;
	return;
T212:;
	if((V46!= VV[85]))goto T218;
	base[2]= (V40);
	vs_top=(vs_base=base+2)+1;
	Lsimple_bit_vector_p();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T219;}
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T219:;
	if(!(((V43))==Cnil)){
	goto T222;}
	base[2]= Ct;
	vs_top=(vs_base=base+2)+1;
	return;
T222:;
	V59= (*(LnkLI82))((V40));
	base[2]= (*(LnkLI81))(/* INLINE-ARGS */V59,(V43));
	vs_top=(vs_base=base+2)+1;
	return;
T218:;
	if((V46!= VV[86]))goto T224;
	base[2]= (V40);
	vs_top=(vs_base=base+2)+1;
	Lsimple_vector_p();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T225;}
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T225:;
	if(!(((V43))==Cnil)){
	goto T228;}
	base[2]= Ct;
	vs_top=(vs_base=base+2)+1;
	return;
T228:;
	V60= (*(LnkLI82))((V40));
	base[2]= (*(LnkLI81))(/* INLINE-ARGS */V60,(V43));
	vs_top=(vs_base=base+2)+1;
	return;
T224:;
	if((V46!= VV[26]))goto T230;
	if(((*(LnkLI87))((V40)))!=Cnil){
	goto T231;}
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T231:;
	if(!(endp((V43)))){
	goto T235;}
	goto T233;
T235:;
	if(!((car((V43)))==(VV[17]))){
	goto T237;}
	goto T233;
T237:;
	base[2]= (V40);
	vs_top=(vs_base=base+2)+1;
	Larray_element_type();
	vs_top=sup;
	V61= vs_base[0];
	V62= (*(LnkLI88))(car((V43)));
	if(equal(V61,/* INLINE-ARGS */V62)){
	goto T233;}
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T233:;
	if(!(endp(cdr((V43))))){
	goto T241;}
	base[2]= Ct;
	vs_top=(vs_base=base+2)+1;
	return;
T241:;
	if(!((cadr((V43)))==(VV[17]))){
	goto T243;}
	base[2]= Ct;
	vs_top=(vs_base=base+2)+1;
	return;
T243:;
	V63= (*(LnkLI82))((V40));
	base[2]= (*(LnkLI81))(/* INLINE-ARGS */V63,cadr((V43)));
	vs_top=(vs_base=base+2)+1;
	return;
T230:;
	if((V46!= VV[22]))goto T245;
	if(type_of((V40))==t_array||
type_of((V40))==t_vector||
type_of((V40))==t_string||
type_of((V40))==t_bitvector){
	goto T246;}
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T246:;
	if(!(endp((V43)))){
	goto T250;}
	goto T248;
T250:;
	if(!((car((V43)))==(VV[17]))){
	goto T252;}
	goto T248;
T252:;
	base[2]= (V40);
	vs_top=(vs_base=base+2)+1;
	Larray_element_type();
	vs_top=sup;
	V64= vs_base[0];
	V65= (*(LnkLI88))(car((V43)));
	if(equal(V64,/* INLINE-ARGS */V65)){
	goto T248;}
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;
T248:;
	if(!(endp(cdr((V43))))){
	goto T256;}
	base[2]= Ct;
	vs_top=(vs_base=base+2)+1;
	return;
T256:;
	if(!((cadr((V43)))==(VV[17]))){
	goto T258;}
	base[2]= Ct;
	vs_top=(vs_base=base+2)+1;
	return;
T258:;
	V66= (*(LnkLI82))((V40));
	base[2]= (*(LnkLI81))(/* INLINE-ARGS */V66,cadr((V43)));
	vs_top=(vs_base=base+2)+1;
	return;
T245:;
	V44= get((V42),VV[33],Cnil);
	if(((V44))==Cnil){
	goto T261;}
	base[2]= (V40);
	base[3]= (V44);
	vs_top=(vs_base=base+2)+2;
	(void) (*Lnk89)();
	return;
T261:;
	if((get((V42),VV[34],Cnil))==Cnil){
	goto T267;}
	base[2]= get((V42),VV[34],Cnil);
	{object V67;
	V67= (V43);
	 vs_top=base+3;
	 while(!endp(V67))
	 {vs_push(car(V67));V67=cdr(V67);}
	vs_base=base+3;}
	super_funcall_no_event(base[2]);
	vs_top=sup;
	V41= vs_base[0];
	goto TTL;
T267:;
	base[2]= Cnil;
	vs_top=(vs_base=base+2)+1;
	return;}}
	}
}
/*	local entry for function NORMALIZE-TYPE	*/

static object LI19(V69)

register object V69;
{	 VMB19 VMS19 VMV19
TTL:;
	{register object V70;
	register object V71;
	V70= Cnil;
	V71= Cnil;
T277:;
	if(!(type_of((V69))!=t_cons)){
	goto T281;}
	V70= (V69);
	V71= Cnil;
	goto T279;
T281:;
	V70= car((V69));
	V71= cdr((V69));
T279:;
	if((get((V70),VV[34],Cnil))==Cnil){
	goto T290;}
	base[0]= get((V70),VV[34],Cnil);
	{object V72;
	V72= (V71);
	 vs_top=base+1;
	 while(!endp(V72))
	 {vs_push(car(V72));V72=cdr(V72);}
	vs_base=base+1;}
	super_funcall_no_event(base[0]);
	vs_top=sup;
	V69= vs_base[0];
	goto T278;
T290:;
	if(!(type_of((V69))!=t_cons)){
	goto T296;}
	{object V73 = make_cons((V69),Cnil);
	VMR19(V73)}
T296:;
	{object V74 = (V69);
	VMR19(V74)}
T278:;
	goto T277;}
}
/*	local entry for function KNOWN-TYPE-P	*/

static object LI20(V76)

register object V76;
{	 VMB20 VMS20 VMV20
TTL:;
	if(!(type_of((V76))==t_cons)){
	goto T299;}
	V76= car((V76));
T299:;
	{register object x= (V76),V77= VV[35];
	while(!endp(V77))
	if(eql(x,V77->c.c_car)){
	goto T303;
	}else V77=V77->c.c_cdr;}
	if((get((V76),VV[33],Cnil))==Cnil){
	goto T304;}
T303:;
	{object V78 = Ct;
	VMR20(V78)}
T304:;
	{object V79 = Cnil;
	VMR20(V79)}
}
/*	function definition for SUBTYPEP	*/

static L21()
{register object *base=vs_base;
	register object *sup=base+VM21; VC21
	vs_reserve(VM21);
	{object V80;
	object V81;
	check_arg(2);
	V80=(base[0]);
	V81=(base[1]);
	vs_top=sup;
TTL:;
	{object V82;
	object V83;
	object V84;
	object V85;
	object V86;
	object V87;
	object V88;
	V82= Cnil;
	V83= Cnil;
	V84= Cnil;
	V85= Cnil;
	V86= Cnil;
	V87= Cnil;
	V88= Cnil;
	V80= (*(LnkLI90))((V80));
	V81= (*(LnkLI90))((V81));
	if(!(equal((V80),(V81)))){
	goto T319;}
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T319:;
	V82= car((V80));
	V83= car((V81));
	V84= cdr((V80));
	V85= cdr((V81));
	if(!(((V82))==(VV[36]))){
	goto T334;}
	{register object V89;
	object V90;
	V89= (V84);
	V90= car((V89));
T340:;
	if(!(endp((V89)))){
	goto T341;}
	goto T336;
T341:;
	base[3]= (V90);
	base[4]= (V81);
	vs_top=(vs_base=base+3)+2;
	(void) (*Lnk73)();
	vs_top=sup;
	if((vs_base[0])!=Cnil){
	goto T345;}
	base[3]= Cnil;
	base[4]= Ct;
	vs_top=(vs_base=base+3)+2;
	return;
T345:;
	V89= cdr((V89));
	V90= car((V89));
	goto T340;}
T336:;
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T334:;
	if(!(((V82))==(VV[37]))){
	goto T360;}
	{register object V91;
	object V92;
	V91= (V84);
	V92= car((V91));
T366:;
	if(!(endp((V91)))){
	goto T367;}
	goto T362;
T367:;
	{object V93;
	object V94;
	base[3]= (V92);
	base[4]= (V81);
	vs_top=(vs_base=base+3)+2;
	(void) (*Lnk91)();
	if(vs_base>=vs_top){vs_top=sup;goto T375;}
	V93= vs_base[0];
	vs_base++;
	if(vs_base>=vs_top){vs_top=sup;goto T376;}
	V94= vs_base[0];
	vs_top=sup;
	goto T377;
T375:;
	V93= Cnil;
T376:;
	V94= Cnil;
T377:;
	if(((V93))!=Cnil){
	goto T371;}
	base[3]= (V93);
	base[4]= (V94);
	vs_top=(vs_base=base+3)+2;
	return;}
T371:;
	V91= cdr((V91));
	V92= car((V91));
	goto T366;}
T362:;
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T360:;
	if(!(((V82))==(VV[38]))){
	goto T390;}
	{register object V95;
	object V96;
	V95= (V84);
	V96= car((V95));
T396:;
	if(!(endp((V95)))){
	goto T397;}
	goto T392;
T397:;
	{object V97;
	base[3]= (V96);
	base[4]= (V81);
	vs_top=(vs_base=base+3)+2;
	(void) (*Lnk91)();
	vs_top=sup;
	V97= vs_base[0];
	if(((V97))==Cnil){
	goto T401;}
	base[3]= Ct;
	base[4]= Ct;
	vs_top=(vs_base=base+3)+2;
	return;}
T401:;
	V95= cdr((V95));
	V96= car((V95));
	goto T396;}
T392:;
	base[2]= Cnil;
	base[3]= Cnil;
	vs_top=(vs_base=base+2)+2;
	return;
T390:;
	if(!(((V82))==(VV[39]))){
	goto T332;}
	if(!(((V83))==(VV[39]))){
	goto T419;}
	V80= car((V85));
	V81= car((V84));
	goto TTL;
T419:;
	V80= Ct;
	V81= list(3,VV[37],(V81),car((V84)));
	goto TTL;
T332:;
	if(!(((V83))==(VV[36]))){
	goto T429;}
	base[2]= Cnil;
	base[3]= Cnil;
	vs_top=(vs_base=base+2)+2;
	return;
T429:;
	if(!(((V83))==(VV[37]))){
	goto T434;}
	{register object V98;
	object V99;
	V98= (V85);
	V99= car((V98));
T440:;
	if(!(endp((V98)))){
	goto T441;}
	goto T436;
T441:;
	{object V100;
	base[3]= (V80);
	base[4]= (V99);
	vs_top=(vs_base=base+3)+2;
	(void) (*Lnk91)();
	vs_top=sup;
	V100= vs_base[0];
	if(((V100))==Cnil){
	goto T445;}
	base[3]= Ct;
	base[4]= Ct;
	vs_top=(vs_base=base+3)+2;
	return;}
T445:;
	V98= cdr((V98));
	V99= car((V98));
	goto T440;}
T436:;
	base[2]= Cnil;
	base[3]= Cnil;
	vs_top=(vs_base=base+2)+2;
	return;
T434:;
	if(!(((V83))==(VV[38]))){
	goto T461;}
	{register object V101;
	object V102;
	V101= (V85);
	V102= car((V101));
T467:;
	if(!(endp((V101)))){
	goto T468;}
	goto T463;
T468:;
	{object V103;
	object V104;
	base[3]= (V80);
	base[4]= (V102);
	vs_top=(vs_base=base+3)+2;
	(void) (*Lnk91)();
	if(vs_base>=vs_top){vs_top=sup;goto T476;}
	V103= vs_base[0];
	vs_base++;
	if(vs_base>=vs_top){vs_top=sup;goto T477;}
	V104= vs_base[0];
	vs_top=sup;
	goto T478;
T476:;
	V103= Cnil;
T477:;
	V104= Cnil;
T478:;
	if(((V103))!=Cnil){
	goto T472;}
	base[3]= (V103);
	base[4]= (V104);
	vs_top=(vs_base=base+3)+2;
	return;}
T472:;
	V101= cdr((V101));
	V102= car((V101));
	goto T467;}
T463:;
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T461:;
	if(!(((V83))==(VV[39]))){
	goto T427;}
	V80= list(3,VV[38],(V80),car((V85)));
	V81= Cnil;
	goto TTL;
T427:;
	V86= (*(LnkLI92))((V80));
	V87= (*(LnkLI92))((V81));
	if(((V82))==(Cnil)){
	goto T499;}
	if(((V83))==(Ct)){
	goto T499;}
	if(!(((V83))==(VV[40]))){
	goto T500;}
T499:;
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T500:;
	if(!(((V83))==(Cnil))){
	goto T509;}
	base[2]= Cnil;
	base[3]= (V86);
	vs_top=(vs_base=base+2)+2;
	return;
T509:;
	if(!(((V82))==(Ct))){
	goto T514;}
	base[2]= Cnil;
	base[3]= (V87);
	vs_top=(vs_base=base+2)+2;
	return;
T514:;
	if(!(((V82))==(VV[40]))){
	goto T519;}
	base[2]= Cnil;
	base[3]= (V87);
	vs_top=(vs_base=base+2)+2;
	return;
T519:;
	if(!(((V83))==(VV[41]))){
	goto T524;}
	{register object x= (V82),V105= VV[42];
	while(!endp(V105))
	if(eql(x,V105->c.c_car)){
	goto T528;
	}else V105=V105->c.c_cdr;
	goto T527;}
T528:;
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T527:;
	base[2]= Cnil;
	base[3]= (V86);
	vs_top=(vs_base=base+2)+2;
	return;
T524:;
	if(!(((V83))==(VV[43]))){
	goto T534;}
	{register object x= (V82),V106= VV[44];
	while(!endp(V106))
	if(eql(x,V106->c.c_car)){
	goto T538;
	}else V106=V106->c.c_cdr;
	goto T537;}
T538:;
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T537:;
	if(!(((V82))==(VV[22]))){
	goto T542;}
	if((cdr((V84)))==Cnil){
	goto T545;}
	if(!(type_of(cadr((V84)))==t_cons)){
	goto T545;}
	if((cdadr((V84)))!=Cnil){
	goto T545;}
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T545:;
	base[2]= Cnil;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T542:;
	base[2]= Cnil;
	base[3]= (V86);
	vs_top=(vs_base=base+2)+2;
	return;
T534:;
	if(!(((V82))==(VV[41]))){
	goto T558;}
	base[2]= Cnil;
	base[3]= (V87);
	vs_top=(vs_base=base+2)+2;
	return;
T558:;
	if(!(((V82))==(VV[43]))){
	goto T563;}
	base[2]= Cnil;
	base[3]= (V87);
	vs_top=(vs_base=base+2)+2;
	return;
T563:;
	if(!(((V83))==(VV[45]))){
	goto T568;}
	{register object x= (V82),V107= VV[46];
	while(!endp(V107))
	if(eql(x,V107->c.c_car)){
	goto T572;
	}else V107=V107->c.c_cdr;
	goto T571;}
T572:;
	base[2]= Cnil;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T571:;
	if(((V86))==Cnil){
	goto T576;}
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T576:;
	base[2]= Cnil;
	base[3]= Cnil;
	vs_top=(vs_base=base+2)+2;
	return;
T568:;
	if(!(((V82))==(VV[45]))){
	goto T583;}
	base[2]= Cnil;
	base[3]= (V87);
	vs_top=(vs_base=base+2)+2;
	return;
T583:;
	if(!(((V83))==(VV[47]))){
	goto T588;}
	{register object x= (V82),V108= VV[48];
	while(!endp(V108))
	if(eql(x,V108->c.c_car)){
	goto T592;
	}else V108=V108->c.c_cdr;
	goto T591;}
T592:;
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T591:;
	base[2]= Cnil;
	base[3]= (V86);
	vs_top=(vs_base=base+2)+2;
	return;
T588:;
	if(!(((V83))==(VV[49]))){
	goto T598;}
	if(!(((V82))==(VV[49]))){
	goto T601;}
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T601:;
	base[2]= Cnil;
	base[3]= (V86);
	vs_top=(vs_base=base+2)+2;
	return;
T598:;
	if(!(((V83))==(VV[50]))){
	goto T608;}
	if(!(((V82))==(VV[50]))){
	goto T611;}
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T611:;
	base[2]= Cnil;
	base[3]= (V86);
	vs_top=(vs_base=base+2)+2;
	return;
T608:;
	if(!(((V83))==(VV[51]))){
	goto T618;}
	{register object x= (V82),V109= VV[52];
	while(!endp(V109))
	if(eql(x,V109->c.c_car)){
	goto T622;
	}else V109=V109->c.c_cdr;
	goto T621;}
T622:;
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T621:;
	base[2]= Cnil;
	base[3]= (V86);
	vs_top=(vs_base=base+2)+2;
	return;
T618:;
	if(!(((V82))==(VV[51]))){
	goto T628;}
	base[2]= Cnil;
	base[3]= (V87);
	vs_top=(vs_base=base+2)+2;
	return;
T628:;
	if(!(((V83))==(VV[53]))){
	goto T633;}
	if(((V82))==(VV[53])){
	goto T635;}
	if((get((V82),VV[33],Cnil))==Cnil){
	goto T636;}
T635:;
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T636:;
	base[2]= Cnil;
	base[3]= (V86);
	vs_top=(vs_base=base+2)+2;
	return;
T633:;
	if(!(((V82))==(VV[53]))){
	goto T645;}
	base[2]= Cnil;
	base[3]= (V87);
	vs_top=(vs_base=base+2)+2;
	return;
T645:;
	V88= get((V82),VV[33],Cnil);
	if(((V88))==Cnil){
	goto T650;}
	{object V110;
	V110= get((V83),VV[33],Cnil);
	if(((V110))==Cnil){
	goto T655;}
	{register object V111;
	V111= (V88);
T658:;
	if(((V111))!=Cnil){
	goto T659;}
	base[2]= Cnil;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T659:;
	if(!(((V111))==(V110))){
	goto T665;}
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T665:;
	V111= structure_ref((V111),VV[33],4);
	goto T658;}
T655:;
	base[2]= Cnil;
	base[3]= (V87);
	vs_top=(vs_base=base+2)+2;
	return;}
T650:;
	if((get((V83),VV[33],Cnil))==Cnil){
	goto T676;}
	base[2]= Cnil;
	base[3]= (V86);
	vs_top=(vs_base=base+2)+2;
	return;
T676:;
	{object V113= (V82);
	if((V113!= VV[29]))goto T680;
	{object V114= (V83);
	if((V114!= VV[29]))goto T681;
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T681:;
	if((V114!= VV[13])
	&& (V114!= VV[59]))goto T684;
	if(((*(LnkLI93))(VV[54],(V85)))==Cnil){
	goto T686;}
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T686:;
	base[2]= Cnil;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T684:;
	base[2]= Cnil;
	base[3]= (V87);
	vs_top=(vs_base=base+2)+2;
	return;}
T680:;
	if((V113!= VV[30]))goto T694;
	{object V115= (V83);
	if((V115!= VV[30]))goto T695;
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T695:;
	if((V115!= VV[59]))goto T698;
	if(((*(LnkLI93))(VV[55],(V85)))==Cnil){
	goto T700;}
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T700:;
	base[2]= Cnil;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T698:;
	base[2]= Cnil;
	base[3]= (V87);
	vs_top=(vs_base=base+2)+2;
	return;}
T694:;
	if((V113!= VV[75]))goto T708;
	{register object x= (V83),V116= VV[56];
	while(!endp(V116))
	if(eql(x,V116->c.c_car)){
	goto T711;
	}else V116=V116->c.c_cdr;
	goto T710;}
T711:;
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T710:;
	base[2]= Cnil;
	base[3]= (V87);
	vs_top=(vs_base=base+2)+2;
	return;
T708:;
	if((V113!= VV[24]))goto T716;
	{register object x= (V83),V117= VV[57];
	while(!endp(V117))
	if(eql(x,V117->c.c_car)){
	goto T719;
	}else V117=V117->c.c_cdr;
	goto T718;}
T719:;
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T718:;
	base[2]= Cnil;
	base[3]= (V87);
	vs_top=(vs_base=base+2)+2;
	return;
T716:;
	if((V113!= VV[13]))goto T724;
	{register object x= (V83),V118= VV[58];
	while(!endp(V118))
	if(eql(x,V118->c.c_car)){
	goto T727;
	}else V118=V118->c.c_cdr;
	goto T726;}
T727:;
	base[2]= (*(LnkLI93))((V84),(V85));
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T726:;
	base[2]= Cnil;
	base[3]= (V87);
	vs_top=(vs_base=base+2)+2;
	return;
T724:;
	if((V113!= VV[59]))goto T732;
	if(!(((V83))==(VV[59]))){
	goto T734;}
	base[2]= (*(LnkLI93))((V84),(V85));
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T734:;
	base[2]= Cnil;
	base[3]= (V87);
	vs_top=(vs_base=base+2)+2;
	return;
T732:;
	if((V113!= VV[60]))goto T740;
	if(!(((V83))==(VV[60]))){
	goto T742;}
	base[2]= (*(LnkLI93))((V84),(V85));
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T742:;
	base[2]= Cnil;
	base[3]= (V87);
	vs_top=(vs_base=base+2)+2;
	return;
T740:;
	if((V113!= VV[31]))goto T748;
	{register object x= (V83),V119= VV[61];
	while(!endp(V119))
	if(eql(x,V119->c.c_car)){
	goto T751;
	}else V119=V119->c.c_cdr;
	goto T750;}
T751:;
	base[2]= (*(LnkLI93))((V84),(V85));
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T750:;
	base[2]= Cnil;
	base[3]= (V87);
	vs_top=(vs_base=base+2)+2;
	return;
T748:;
	if((V113!= VV[78])
	&& (V113!= VV[79])
	&& (V113!= VV[32]))goto T756;
	{register object x= (V83),V120= VV[62];
	while(!endp(V120))
	if(eql(x,V120->c.c_car)){
	goto T759;
	}else V120=V120->c.c_cdr;
	goto T758;}
T759:;
	base[2]= (*(LnkLI93))((V84),(V85));
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T758:;
	base[2]= Cnil;
	base[3]= (V87);
	vs_top=(vs_base=base+2)+2;
	return;
T756:;
	if((V113!= VV[63]))goto T764;
	if(!(((V83))==(VV[63]))){
	goto T766;}{object V121;
	V121= car((V84));
	if(V121==Cnil)goto T770;
	V80= V121;
	goto T769;
T770:;}
	V80= Ct;
T769:;{object V122;
	V122= car((V85));
	if(V122==Cnil)goto T773;
	V81= V122;
	goto T772;
T773:;}
	V81= Ct;
T772:;
	goto TTL;
T766:;
	base[2]= Cnil;
	base[3]= (V87);
	vs_top=(vs_base=base+2)+2;
	return;
T764:;
	if((V113!= VV[26]))goto T777;
	if(((V83))==(VV[26])){
	goto T778;}
	if(!(((V83))==(VV[22]))){
	goto T779;}
T778:;
	if(endp((V84))){
	goto T784;}
	if(!((car((V84)))==(VV[17]))){
	goto T785;}
T784:;
	if(endp((V85))){
	goto T783;}
	if((car((V85)))==(VV[17])){
	goto T783;}
	base[2]= Cnil;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T785:;
	if(endp((V85))){
	goto T783;}
	if((car((V85)))==(VV[17])){
	goto T783;}
	if(equal(car((V84)),car((V85)))){
	goto T783;}
	base[2]= Cnil;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T783:;
	if(endp(cdr((V84)))){
	goto T804;}
	if(!((cadr((V84)))==(VV[17]))){
	goto T803;}
T804:;
	if(endp(cdr((V85)))){
	goto T808;}
	if(!((cadr((V85)))==(VV[17]))){
	goto T809;}
T808:;
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T809:;
	base[2]= Cnil;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T803:;
	if(endp(cdr((V85)))){
	goto T818;}
	if(!((cadr((V85)))==(VV[17]))){
	goto T817;}
T818:;
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T817:;
	base[2]= (*(LnkLI81))(cadr((V84)),cadr((V85)));
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T779:;
	base[2]= Cnil;
	base[3]= (V87);
	vs_top=(vs_base=base+2)+2;
	return;
T777:;
	if((V113!= VV[22]))goto T828;
	if(!(((V83))==(VV[22]))){
	goto T830;}
	if(endp((V84))){
	goto T833;}
	if(!((car((V84)))==(VV[17]))){
	goto T834;}
T833:;
	if(endp((V85))){
	goto T832;}
	if((car((V85)))==(VV[17])){
	goto T832;}
	base[2]= Cnil;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T834:;
	if(endp((V85))){
	goto T832;}
	if((car((V85)))==(VV[17])){
	goto T832;}
	if(equal(car((V84)),car((V85)))){
	goto T832;}
	base[2]= Cnil;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T832:;
	if(endp(cdr((V84)))){
	goto T853;}
	if(!((cadr((V84)))==(VV[17]))){
	goto T852;}
T853:;
	if(endp(cdr((V85)))){
	goto T857;}
	if(!((cadr((V85)))==(VV[17]))){
	goto T858;}
T857:;
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T858:;
	base[2]= Cnil;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T852:;
	if(endp(cdr((V85)))){
	goto T867;}
	if(!((cadr((V85)))==(VV[17]))){
	goto T866;}
T867:;
	base[2]= Ct;
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T866:;
	base[2]= (*(LnkLI81))(cadr((V84)),cadr((V85)));
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T830:;
	base[2]= Cnil;
	base[3]= (V87);
	vs_top=(vs_base=base+2)+2;
	return;
T828:;
	if(((V86))==Cnil){
	goto T878;}
	base[2]= (((V82))==((V83))?Ct:Cnil);
	base[3]= Ct;
	vs_top=(vs_base=base+2)+2;
	return;
T878:;
	base[2]= Cnil;
	base[3]= Cnil;
	vs_top=(vs_base=base+2)+2;
	return;}}
	}
}
/*	local entry for function SUB-INTERVAL-P	*/

static object LI22(V125,V126)

register object V125;register object V126;
{	 VMB22 VMS22 VMV22
TTL:;
	{register object V127;
	register object V128;
	register object V129;
	register object V130;
	V127= Cnil;
	V128= Cnil;
	V129= Cnil;
	V130= Cnil;
	if(!(endp((V125)))){
	goto T886;}
	V127= VV[17];
	V128= VV[17];
	goto T884;
T886:;
	if(!(endp(cdr((V125))))){
	goto T892;}
	V127= car((V125));
	V128= VV[17];
	goto T884;
T892:;
	V127= car((V125));
	V128= cadr((V125));
T884:;
	if(!(endp((V126)))){
	goto T902;}
	V129= VV[17];
	V130= VV[17];
	goto T900;
T902:;
	if(!(endp(cdr((V126))))){
	goto T908;}
	V129= car((V126));
	V130= VV[17];
	goto T900;
T908:;
	V129= car((V126));
	V130= cadr((V126));
T900:;
	if(!(((V127))==(VV[17]))){
	goto T918;}
	if(((V129))==(VV[17])){
	goto T916;}
	{object V131 = Cnil;
	VMR22(V131)}
T918:;
	{object V132;
	V132= (((V129))==(VV[17])?Ct:Cnil);
	if(((V132))==Cnil){
	goto T924;}
	goto T916;
T924:;
	if(!(type_of((V127))==t_cons)){
	goto T927;}
	if(!(type_of((V129))==t_cons)){
	goto T930;}
	if(!(number_compare(car((V127)),car((V129)))<0)){
	goto T916;}
	{object V133 = Cnil;
	VMR22(V133)}
T930:;
	if(!(number_compare(car((V127)),(V129))<0)){
	goto T916;}
	{object V134 = Cnil;
	VMR22(V134)}
T927:;
	{object V135;
	if(!(type_of((V129))==t_cons)){
	goto T938;}
	if(!(number_compare((V127),car((V129)))<=0)){
	goto T941;}
	{object V136 = Cnil;
	VMR22(V136)}
T941:;
	V135= Cnil;
	goto T936;
T938:;
	if(!(number_compare((V127),(V129))<0)){
	goto T944;}
	{object V137 = Cnil;
	VMR22(V137)}
T944:;
	V135= Cnil;
T936:;
	if(((V135))==Cnil){
	goto T916;}}}
T916:;
	if(!(((V128))==(VV[17]))){
	goto T950;}
	if(((V130))==(VV[17])){
	goto T948;}
	{object V138 = Cnil;
	VMR22(V138)}
T950:;
	{object V139;
	V139= (((V130))==(VV[17])?Ct:Cnil);
	if(((V139))==Cnil){
	goto T956;}
	goto T948;
T956:;
	if(!(type_of((V128))==t_cons)){
	goto T959;}
	if(!(type_of((V130))==t_cons)){
	goto T962;}
	if(!(number_compare(car((V128)),car((V130)))>0)){
	goto T948;}
	{object V140 = Cnil;
	VMR22(V140)}
T962:;
	if(!(number_compare(car((V128)),(V130))>0)){
	goto T948;}
	{object V141 = Cnil;
	VMR22(V141)}
T959:;
	{object V142;
	if(!(type_of((V130))==t_cons)){
	goto T970;}
	if(!(number_compare((V128),car((V130)))>=0)){
	goto T973;}
	{object V143 = Cnil;
	VMR22(V143)}
T973:;
	V142= Cnil;
	goto T968;
T970:;
	if(!(number_compare((V128),(V130))>0)){
	goto T976;}
	{object V144 = Cnil;
	VMR22(V144)}
T976:;
	V142= Cnil;
T968:;
	if(((V142))==Cnil){
	goto T948;}}}
T948:;
	{object V145 = Ct;
	VMR22(V145)}}
}
/*	local entry for function IN-INTERVAL-P	*/

static object LI23(V148,V149)

register object V148;register object V149;
{	 VMB23 VMS23 VMV23
TTL:;
	{register object V150;
	register object V151;
	V150= Cnil;
	V151= Cnil;
	if(!(endp((V149)))){
	goto T982;}
	V150= VV[17];
	V151= VV[17];
	goto T980;
T982:;
	if(!(endp(cdr((V149))))){
	goto T988;}
	V150= car((V149));
	V151= VV[17];
	goto T980;
T988:;
	V150= car((V149));
	V151= cadr((V149));
T980:;
	{object V152;
	V152= (((V150))==(VV[17])?Ct:Cnil);
	if(((V152))==Cnil){
	goto T999;}
	goto T996;
T999:;
	if(!(type_of((V150))==t_cons)){
	goto T1002;}
	if(!(number_compare((V148),car((V150)))<=0)){
	goto T996;}
	{object V153 = Cnil;
	VMR23(V153)}
T1002:;
	{object V154;
	if(!(number_compare((V148),(V150))<0)){
	goto T1008;}
	{object V155 = Cnil;
	VMR23(V155)}
T1008:;
	V154= Cnil;
	if(((V154))==Cnil){
	goto T996;}}}
T996:;
	{object V156;
	V156= (((V151))==(VV[17])?Ct:Cnil);
	if(((V156))==Cnil){
	goto T1015;}
	goto T1012;
T1015:;
	if(!(type_of((V151))==t_cons)){
	goto T1018;}
	if(!(number_compare((V148),car((V151)))>=0)){
	goto T1012;}
	{object V157 = Cnil;
	VMR23(V157)}
T1018:;
	{object V158;
	if(!(number_compare((V148),(V151))>0)){
	goto T1024;}
	{object V159 = Cnil;
	VMR23(V159)}
T1024:;
	V158= Cnil;
	if(((V158))==Cnil){
	goto T1012;}}}
T1012:;
	{object V160 = Ct;
	VMR23(V160)}}
}
/*	local entry for function MATCH-DIMENSIONS	*/

static object LI24(V163,V164)

object V163;register object V164;
{	 VMB24 VMS24 VMV24
TTL:;
	if(((V163))!=Cnil){
	goto T1029;}
	{object V165 = (((V164))==Cnil?Ct:Cnil);
	VMR24(V165)}
T1029:;
	if(!((car((V164)))==(VV[17]))){
	goto T1033;}
	goto T1031;
T1033:;
	if((car((V163)))==(car((V164)))){
	goto T1031;}
	{object V166 = Cnil;
	VMR24(V166)}
T1031:;
	V163= cdr((V163));
	V164= cdr((V164));
	goto TTL;
}
/*	local entry for function COERCE	*/

static object LI25(V169,V170)

register object V169;object V170;
{	 VMB25 VMS25 VMV25
TTL:;
	base[0]= (V169);
	base[1]= (V170);
	vs_top=(vs_base=base+0)+2;
	(void) (*Lnk73)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T1038;}
	{object V171 = (V169);
	VMR25(V171)}
T1038:;
	V170= (*(LnkLI90))((V170));
	{object V172= car((V170));
	if((V172!= VV[41]))goto T1045;
	{register object V173;
	register object V174;
	V175 = make_fixnum(length((V169)));
	V174= one_minus(V175);
	V173= Cnil;
T1048:;
	if(!(number_compare((V174),small_fixnum(0))<0)){
	goto T1049;}
	{object V176 = (V173);
	VMR25(V176)}
T1049:;
	V177= elt((V169),fixint((V174)));
	V173= make_cons(/* INLINE-ARGS */V177,(V173));
	V174= one_minus((V174));
	goto T1048;}
T1045:;
	if((V172!= VV[22])
	&& (V172!= VV[26]))goto T1057;
	if(endp(cdr((V170)))){
	goto T1058;}
	if(endp(cddr((V170)))){
	goto T1058;}
	if((caddr((V170)))==(VV[17])){
	goto T1058;}
	if(endp(cdr(caddr((V170))))){
	goto T1058;}
	base[0]= VV[64];
	vs_top=(vs_base=base+0)+1;
	Lerror();
	vs_top=sup;
T1058:;
	{register object V178;
	register object V179;
	register object V180;
	V181 = make_fixnum(length((V169)));
	V178= (VFUN_NARGS=2,(*(LnkLI94))((V170),V181));
	V180= make_fixnum(length((V169)));
	V179= small_fixnum(0);
T1071:;
	if(!(number_compare((V179),(V180))>=0)){
	goto T1072;}
	{object V182 = (V178);
	VMR25(V182)}
T1072:;
	V183= elt((V169),fixint((V179)));
	(void)(elt_set((V178),fixint((V179)),/* INLINE-ARGS */V183));
	V179= one_plus((V179));
	goto T1071;}
T1057:;
	if((V172!= VV[95]))goto T1080;
	base[0]= (V169);
	vs_top=(vs_base=base+0)+1;
	Lcharacter();
	vs_top=sup;
	{object V184 = vs_base[0];
	VMR25(V184)}
T1080:;
	if((V172!= VV[60]))goto T1082;
	base[0]= (V169);
	vs_top=(vs_base=base+0)+1;
	Lfloat();
	vs_top=sup;
	{object V185 = vs_base[0];
	VMR25(V185)}
T1082:;
	if((V172!= VV[31]))goto T1084;
	base[0]= (V169);
	base[1]= VV[65];
	vs_top=(vs_base=base+0)+2;
	Lfloat();
	vs_top=sup;
	{object V186 = vs_base[0];
	VMR25(V186)}
T1084:;
	if((V172!= VV[78])
	&& (V172!= VV[79])
	&& (V172!= VV[32]))goto T1087;
	base[0]= (V169);
	base[1]= VV[66];
	vs_top=(vs_base=base+0)+2;
	Lfloat();
	vs_top=sup;
	{object V187 = vs_base[0];
	VMR25(V187)}
T1087:;
	if((V172!= VV[63]))goto T1090;
	if((cdr((V170)))==Cnil){
	goto T1091;}
	if((cadr((V170)))==Cnil){
	goto T1091;}
	if(!((cadr((V170)))==(VV[17]))){
	goto T1092;}
T1091:;
	base[1]= (V169);
	vs_top=(vs_base=base+1)+1;
	Lrealpart();
	vs_top=sup;
	base[0]= vs_base[0];
	base[2]= (V169);
	vs_top=(vs_base=base+2)+1;
	Limagpart();
	vs_top=sup;
	base[1]= vs_base[0];
	vs_top=(vs_base=base+0)+2;
	Lcomplex();
	vs_top=sup;
	{object V188 = vs_base[0];
	VMR25(V188)}
T1092:;
	base[1]= (V169);
	vs_top=(vs_base=base+1)+1;
	Lrealpart();
	vs_top=sup;
	V189= vs_base[0];
	base[0]= (*(LnkLI96))(V189,cadr((V170)));
	base[2]= (V169);
	vs_top=(vs_base=base+2)+1;
	Limagpart();
	vs_top=sup;
	V190= vs_base[0];
	base[1]= (*(LnkLI96))(V190,cadr((V170)));
	vs_top=(vs_base=base+0)+2;
	Lcomplex();
	vs_top=sup;
	{object V191 = vs_base[0];
	VMR25(V191)}
T1090:;
	base[0]= VV[67];
	base[1]= (V169);
	base[2]= (V170);
	vs_top=(vs_base=base+0)+3;
	Lerror();
	vs_top=sup;
	{object V192 = vs_base[0];
	VMR25(V192)}}
}
/*	function definition for WARN-VERSION	*/

static L26()
{register object *base=vs_base;
	register object *sup=base+VM26; VC26
	vs_reserve(VM26);
	{object V193;
	check_arg(1);
	V193=(base[0]);
	vs_top=sup;
TTL:;
	if(symbol_value(VV[68])==Cnil){
	base[1]= Cnil;
	vs_top=(vs_base=base+1)+1;
	return;}
	if(((eql((V193),symbol_value(VV[68]))?Ct:Cnil))==Cnil){
	goto T1111;}
	base[1]= Cnil;
	vs_top=(vs_base=base+1)+1;
	return;
T1111:;
	if(symbol_value(VV[69])==Cnil){
	base[1]= Cnil;
	vs_top=(vs_base=base+1)+1;
	return;}
	base[1]= Ct;
	base[2]= VV[70];
	base[3]= (V193);
	vs_top=(vs_base=base+1)+3;
	Lformat();
	return;
	}
}
static object  LnkTLI96(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[96],&LnkLI96,2,ap);} /* COERCE */
static object  LnkTLI94(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[94],&LnkLI94,ap);} /* MAKE-SEQUENCE */
static object  LnkTLI93(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[93],&LnkLI93,2,ap);} /* SUB-INTERVAL-P */
static object  LnkTLI92(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[92],&LnkLI92,1,ap);} /* KNOWN-TYPE-P */
static LnkT91(){ call_or_link(VV[91],&Lnk91);} /* SUBTYPEP */
static object  LnkTLI90(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[90],&LnkLI90,1,ap);} /* NORMALIZE-TYPE */
static LnkT89(){ call_or_link(VV[89],&Lnk89);} /* STRUCTURE-SUBTYPE-P */
static object  LnkTLI88(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[88],&LnkLI88,1,ap);} /* BEST-ARRAY-ELEMENT-TYPE */
static object  LnkTLI87(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[87],&LnkLI87,1,ap);} /* SIMPLE-ARRAY-P */
static object  LnkTLI82(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[82],&LnkLI82,1,ap);} /* ARRAY-DIMENSIONS */
static object  LnkTLI81(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[81],&LnkLI81,2,ap);} /* MATCH-DIMENSIONS */
static LnkT77(){ call_or_link(VV[77],&Lnk77);} /* RATIONALP */
static object  LnkTLI76(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[76],&LnkLI76,2,ap);} /* IN-INTERVAL-P */
static LnkT73(){ call_or_link(VV[73],&Lnk73);} /* TYPEP */
static LnkT72(){ call_or_link(VV[72],&Lnk72);} /* ARRAY-HAS-FILL-POINTER-P */
static object  LnkTLI71(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_proc(VV[71],&LnkLI71,1,ap);} /* FIND-DOCUMENTATION */
