
static object LI1();
static L5();
static object LI6();
static L15();
static L16();
static L19();
static object LI24();
static object LI25();
static object LI1();
static int VK1defaults[5]={-2,-2,-1,-2,-2};
static struct { short n,allow_other_keys;int *defaults;
	 int keys[5];} LI1key={5,0,VK1defaults,{66,67,16,68,69}};
#define VMB1 register object *base=vs_top; object Vcs[10];
#define VMS1  register object *sup=vs_top+6;vs_top=sup;
#define VMV1 vs_reserve(6);
#define VMR1(VMT1) vs_top=base ; return(VMT1);
static object LI2();
#define VMB2 object  V16 ,V15 ,V14 ,V13 ,V12 ,V11;
#define VMS2
#define VMV2
#define VMR2(VMT2) return(VMT2);
static object LI3();
#define VMB3 register object *base=vs_top; object  V36 ,V29 ,V24;
#define VMS3 vs_top += 1;
#define VMV3 vs_reserve(1);
#define VMR3(VMT3) vs_top=base ; return(VMT3);
static object LI4();
#define VMB4 register object *base=vs_top; object  V54 ,V48 ,V43;
#define VMS4 vs_top += 1;
#define VMV4 vs_reserve(1);
#define VMR4(VMT4) vs_top=base ; return(VMT4);
#define VC5
static object LI6();
#define VMB6 register object *base=vs_top; object  V117 ,V116 ,V114 ,V113 ,V111 ,V110 ,V107 ,V106 ,V105 ,V103 ,V102 ,V100 ,V97 ,V96 ,V92 ,V91 ,V89 ,V88 ,V87 ,V86 ,V85 ,V83 ,V82 ,V80 ,V78 ,V77 ,V76 ,V74 ,V73 ,V71; object Vcs[3];
#define VMS6  register object *sup=vs_top+2;vs_top=sup;
#define VMV6 vs_reserve(2);
#define VMR6(VMT6) vs_top=base ; return(VMT6);
static object LI7();
#define VMB7
#define VMS7
#define VMV7
#define VMR7(VMT7) return(VMT7);
static object LI8();
#define VMB8 register object *base=vs_top; object  V153 ,V151 ,V143 ,V138;
#define VMS8  register object *sup=vs_top+4;vs_top=sup;
#define VMV8 vs_reserve(4);
#define VMR8(VMT8) vs_top=base ; return(VMT8);
static object LI9();
#define VMB9 object  V158;
#define VMS9
#define VMV9
#define VMR9(VMT9) return(VMT9);
static object LI10();
#define VMB10 register object *base=vs_top; object  V184 ,V183 ,V182;
#define VMS10  register object *sup=vs_top+4;vs_top=sup;
#define VMV10 vs_reserve(4);
#define VMR10(VMT10) vs_top=base ; return(VMT10);
static object LI11();
#define VMB11 register object *base=vs_top; object  V198;
#define VMS11  register object *sup=vs_top+1;vs_top=sup;
#define VMV11 vs_reserve(1);
#define VMR11(VMT11) vs_top=base ; return(VMT11);
static object LI12();
#define VMB12 register object *base=vs_top; object  V221 ,V218 ,V217 ,V214 ,V213 ,V212;
#define VMS12  register object *sup=vs_top+2;vs_top=sup;
#define VMV12 vs_reserve(2);
#define VMR12(VMT12) vs_top=base ; return(VMT12);
static object LI13();
#define VMB13 register object *base=vs_top;
#define VMS13  register object *sup=vs_top+0;vs_top=sup;
#define VMV13
#define VMR13(VMT13) return(VMT13);
static object LI14();
#define VMB14
#define VMS14
#define VMV14
#define VMR14(VMT14) return(VMT14);
#define VC15 object  V256 ,V255; GEN  V254= 0,V254alloc; object  V253 ,V252 ,V251; GEN  V250= 0,V250alloc ,V248= 0,V248alloc ,V247= 0,V247alloc ,V246= 0,V246alloc; object  V245 ,V244 ,V243 ,V241 ,V240 ,V239;
#define VC16
static object LI17();
#define VMB17 register object *base=vs_top;
#define VMS17  register object *sup=vs_top+2;vs_top=sup;
#define VMV17 vs_reserve(2);
#define VMR17(VMT17) vs_top=base ; return(VMT17);
static object LI18();
#define VMB18 register object *base=vs_top;
#define VMS18  register object *sup=vs_top+2;vs_top=sup;
#define VMV18 vs_reserve(2);
#define VMR18(VMT18) vs_top=base ; return(VMT18);
#define VC19
static object LI20();
#define VMB20 register object *base=vs_top;
#define VMS20  register object *sup=vs_top+2;vs_top=sup;
#define VMV20 vs_reserve(2);
#define VMR20(VMT20) vs_top=base ; return(VMT20);
static object LI21();
#define VMB21 register object *base=vs_top;
#define VMS21  register object *sup=vs_top+2;vs_top=sup;
#define VMV21 vs_reserve(2);
#define VMR21(VMT21) vs_top=base ; return(VMT21);
static object LI22();
#define VMB22 register object *base=vs_top;
#define VMS22  register object *sup=vs_top+2;vs_top=sup;
#define VMV22 vs_reserve(2);
#define VMR22(VMT22) vs_top=base ; return(VMT22);
static object LI23();
#define VMB23 register object *base=vs_top; object  V309 ,V308 ,V307;
#define VMS23  register object *sup=vs_top+3;vs_top=sup;
#define VMV23 vs_reserve(3);
#define VMR23(VMT23) vs_top=base ; return(VMT23);
static object LI24();
#define VMB24 register object *base=vs_top; object  V317 ,V316 ,V313; object Vcs[1];
#define VMS24 vs_top += 2;
#define VMV24 vs_reserve(2);
#define VMR24(VMT24) vs_top=base ; return(VMT24);
static object LI25();
#define VMB25 register object *base=vs_top; object  V326 ,V323; object Vcs[1];
#define VMS25 vs_top += 1;
#define VMV25 vs_reserve(1);
#define VMR25(VMT25) vs_top=base ; return(VMT25);
static object LI26();
#define VMB26 register object *base=vs_top; object  V350 ,V349 ,V344;
#define VMS26 vs_top += 1;
#define VMV26 vs_reserve(1);
#define VMR26(VMT26) vs_top=base ; return(VMT26);
static LC27();
#define VC27 object  V354;
static LC27();
#define VM27 3
#define VM26 1
#define VM25 1
#define VM24 2
#define VM23 3
#define VM22 2
#define VM21 2
#define VM20 2
#define VM19 5
#define VM18 2
#define VM17 2
#define VM16 5
#define VM15 4
#define VM14 0
#define VM13 0
#define VM12 2
#define VM11 1
#define VM10 4
#define VM9 0
#define VM8 4
#define VM7 0
#define VM6 2
#define VM5 2
#define VM4 1
#define VM3 1
#define VM2 0
#define VM1 6
static char * VVi[111]={
#define Cdata VV[110]
(char *)(LI1),
(char *)(&LI1key),
(char *)(LI2),
(char *)(LI3),
(char *)(LI4),
(char *)(L5),
(char *)(LI6),
(char *)(LI7),
(char *)(LI8),
(char *)(LI9),
(char *)(LI10),
(char *)(LI11),
(char *)(LI12),
(char *)(LI13),
(char *)(LI14),
(char *)(L15),
(char *)(L16),
(char *)(LI17),
(char *)(LI18),
(char *)(L19),
(char *)(LI20),
(char *)(LI21),
(char *)(LI22),
(char *)(LI23),
(char *)(LI24),
(char *)(LI25),
(char *)(LI26)
};
#define VV ((object *)VVi)
static object  LnkTLI109() ;
static object  (*LnkLI109)() = LnkTLI109;
static object  LnkTLI108() ;
static object  (*LnkLI108)() = LnkTLI108;
static  LnkT107() ;
static  (*Lnk107)() = LnkT107;
static object  LnkTLI106() ;
static object  (*LnkLI106)() = LnkTLI106;
static  LnkT105() ;
static  (*Lnk105)() = LnkT105;
static object  LnkTLI104() ;
static object  (*LnkLI104)() = LnkTLI104;
static object  LnkTLI103() ;
static object  (*LnkLI103)() = LnkTLI103;
static object  LnkTLI102() ;
static object  (*LnkLI102)() = LnkTLI102;
static object  LnkTLI101() ;
static object  (*LnkLI101)() = LnkTLI101;
static object  LnkTLI100() ;
static object  (*LnkLI100)() = LnkTLI100;
static object  LnkTLI7() ;
static object  (*LnkLI7)() = LnkTLI7;
static object  LnkTLI99() ;
static object  (*LnkLI99)() = LnkTLI99;
static object  LnkTLI97() ;
static object  (*LnkLI97)() = LnkTLI97;
static object  LnkTLI95() ;
static object  (*LnkLI95)() = LnkTLI95;
static object  LnkTLI94() ;
static object  (*LnkLI94)() = LnkTLI94;
static  LnkT93() ;
static  (*Lnk93)() = LnkT93;
static  LnkT92() ;
static  (*Lnk92)() = LnkT92;
static  LnkT91() ;
static  (*Lnk91)() = LnkT91;
static  LnkT90() ;
static  (*Lnk90)() = LnkT90;
static  LnkT88() ;
static  (*Lnk88)() = LnkT88;
static  LnkT87() ;
static  (*Lnk87)() = LnkT87;
static object  LnkTLI86() ;
static object  (*LnkLI86)() = LnkTLI86;
static object  LnkTLI85() ;
static object  (*LnkLI85)() = LnkTLI85;
static  LnkT84() ;
static  (*Lnk84)() = LnkT84;
static object  LnkTLI83() ;
static object  (*LnkLI83)() = LnkTLI83;
static object  LnkTLI82() ;
static object  (*LnkLI82)() = LnkTLI82;
static object  LnkTLI80() ;
static object  (*LnkLI80)() = LnkTLI80;
static object  LnkTLI79() ;
static object  (*LnkLI79)() = LnkTLI79;
static object  LnkTLI78() ;
static object  (*LnkLI78)() = LnkTLI78;
static  LnkT77() ;
static  (*Lnk77)() = LnkT77;
static object  LnkTLI76() ;
static object  (*LnkLI76)() = LnkTLI76;
static object  LnkTLI75() ;
static object  (*LnkLI75)() = LnkTLI75;
static object  LnkTLI74() ;
static object  (*LnkLI74)() = LnkTLI74;
static object  LnkTLI73() ;
static object  (*LnkLI73)() = LnkTLI73;
