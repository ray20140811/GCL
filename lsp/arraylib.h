
static object LI2();
static object LI5();
static object LI7();
static object LI8();
static object LI9();
static object LI10();
static object LI11();
static object LI12();
static object LI13();
static object LI14();
static object LI15();
static object LI16();
static object LI17();
static object LI18();
static object LI19();
static object LI20();
static object LI21();
static object LI23();
static object LI25();
static object LI1();
#define VMB1 register object *base=vs_top;
#define VMS1  register object *sup=vs_top+3;vs_top=sup;
#define VMV1 vs_reserve(3);
#define VMR1(VMT1) vs_top=base ; return(VMT1);
static object LI2();
static int VK2defaults[8]={-1,-2,-1,-2,-2,-2,17,-2};
static struct { short n,allow_other_keys;int *defaults;
	 int keys[8];} LI2key={8,0,VK2defaults,{18,19,20,11,14,9,7,8}};
#define VMB2 register object *base=vs_top; object  V30; object Vcs[17];
#define VMS2  register object *sup=vs_top+8;vs_top=sup;
#define VMV2 vs_reserve(8);
#define VMR2(VMT2) vs_top=base ; return(VMT2);
static object LI3();
#define VMB3 object  V44;
#define VMS3
#define VMV3
#define VMR3(VMT3) return(VMT3);
static object LI4();
#define VMB4
#define VMS4
#define VMV4
#define VMR4(VMT4) return(VMT4);
static object LI5();
#define VMB5 register object *base=vs_top; object  V55 ,V53; object Vcs[1];
#define VMS5 vs_top += 1;
#define VMV5 vs_reserve(1);
#define VMR5(VMT5) vs_top=base ; return(VMT5);
static object LI6();
#define VMB6 register object *base=vs_top; object  V62;
#define VMS6  register object *sup=vs_top+2;vs_top=sup;
#define VMV6 vs_reserve(2);
#define VMR6(VMT6) vs_top=base ; return(VMT6);
static object LI7();
#define VMB7 register object *base=vs_top; object  V73 ,V72 ,V68 ,V66; object Vcs[2];
#define VMS7  register object *sup=vs_top+4;vs_top=sup;
#define VMV7 vs_reserve(4);
#define VMR7(VMT7) vs_top=base ; return(VMT7);
static object LI8();
#define VMB8 register object *base=vs_top; object  V85 ,V84 ,V78; object Vcs[2];
#define VMS8  register object *sup=vs_top+2;vs_top=sup;
#define VMV8 vs_reserve(2);
#define VMR8(VMT8) vs_top=base ; return(VMT8);
static object LI9();
#define VMB9 register object *base=vs_top; object  V89; object Vcs[2];
#define VMS9  register object *sup=vs_top+1;vs_top=sup;
#define VMV9 vs_reserve(1);
#define VMR9(VMT9) vs_top=base ; return(VMT9);
static object LI10();
#define VMB10 register object *base=vs_top; object  V95; object Vcs[2];
#define VMS10  register object *sup=vs_top+1;vs_top=sup;
#define VMV10 vs_reserve(1);
#define VMR10(VMT10) vs_top=base ; return(VMT10);
static object LI11();
#define VMB11 register object *base=vs_top; object Vcs[3];
#define VMS11  register object *sup=vs_top+4;vs_top=sup;
#define VMV11 vs_reserve(4);
#define VMR11(VMT11) vs_top=base ; return(VMT11);
static object LI12();
#define VMB12 register object *base=vs_top; object Vcs[3];
#define VMS12  register object *sup=vs_top+4;vs_top=sup;
#define VMV12 vs_reserve(4);
#define VMR12(VMT12) vs_top=base ; return(VMT12);
static object LI13();
#define VMB13 register object *base=vs_top; object Vcs[3];
#define VMS13  register object *sup=vs_top+4;vs_top=sup;
#define VMV13 vs_reserve(4);
#define VMR13(VMT13) vs_top=base ; return(VMT13);
static object LI14();
#define VMB14 register object *base=vs_top; object Vcs[3];
#define VMS14  register object *sup=vs_top+4;vs_top=sup;
#define VMV14 vs_reserve(4);
#define VMR14(VMT14) vs_top=base ; return(VMT14);
static object LI15();
#define VMB15 register object *base=vs_top; object Vcs[3];
#define VMS15  register object *sup=vs_top+4;vs_top=sup;
#define VMV15 vs_reserve(4);
#define VMR15(VMT15) vs_top=base ; return(VMT15);
static object LI16();
#define VMB16 register object *base=vs_top; object Vcs[3];
#define VMS16  register object *sup=vs_top+4;vs_top=sup;
#define VMV16 vs_reserve(4);
#define VMR16(VMT16) vs_top=base ; return(VMT16);
static object LI17();
#define VMB17 register object *base=vs_top; object Vcs[3];
#define VMS17  register object *sup=vs_top+4;vs_top=sup;
#define VMV17 vs_reserve(4);
#define VMR17(VMT17) vs_top=base ; return(VMT17);
static object LI18();
#define VMB18 register object *base=vs_top; object Vcs[3];
#define VMS18  register object *sup=vs_top+4;vs_top=sup;
#define VMV18 vs_reserve(4);
#define VMR18(VMT18) vs_top=base ; return(VMT18);
static object LI19();
#define VMB19 register object *base=vs_top; object Vcs[3];
#define VMS19  register object *sup=vs_top+4;vs_top=sup;
#define VMV19 vs_reserve(4);
#define VMR19(VMT19) vs_top=base ; return(VMT19);
static object LI20();
#define VMB20 register object *base=vs_top; object Vcs[3];
#define VMS20  register object *sup=vs_top+4;vs_top=sup;
#define VMV20 vs_reserve(4);
#define VMR20(VMT20) vs_top=base ; return(VMT20);
static object LI21();
#define VMB21 register object *base=vs_top; object Vcs[2];
#define VMS21  register object *sup=vs_top+4;vs_top=sup;
#define VMV21 vs_reserve(4);
#define VMR21(VMT21) vs_top=base ; return(VMT21);
static object LI22();
#define VMB22 register object *base=vs_top; object  V167;
#define VMS22  register object *sup=vs_top+2;vs_top=sup;
#define VMV22 vs_reserve(2);
#define VMR22(VMT22) vs_top=base ; return(VMT22);
static object LI23();
#define VMB23 register object *base=vs_top; object  V184 ,V183 ,V182 ,V181 ,V180 ,V179 ,V178 ,V176; object Vcs[3];
#define VMS23  register object *sup=vs_top+2;vs_top=sup;
#define VMV23 vs_reserve(2);
#define VMR23(VMT23) vs_top=base ; return(VMT23);
static object LI24();
#define VMB24 register object *base=vs_top;
#define VMS24  register object *sup=vs_top+2;vs_top=sup;
#define VMV24 vs_reserve(2);
#define VMR24(VMT24) vs_top=base ; return(VMT24);
static object LI25();
static struct { short n,allow_other_keys;int *defaults;
	 int keys[7];} LI25key={7,0,(int *)Cstd_key_defaults,{18,19,20,11,9,7,8}};
#define VMB25 register object *base=vs_top; object  V212 ,V211 ,V209 ,V208 ,V207 ,V204 ,V202; object Vcs[17];
#define VMS25  register object *sup=vs_top+6;vs_top=sup;
#define VMV25 vs_reserve(6);
#define VMR25(VMT25) vs_top=base ; return(VMT25);
#define VM25 6
#define VM24 2
#define VM23 2
#define VM22 2
#define VM21 4
#define VM20 4
#define VM19 4
#define VM18 4
#define VM17 4
#define VM16 4
#define VM15 4
#define VM14 4
#define VM13 4
#define VM12 4
#define VM11 4
#define VM10 1
#define VM9 1
#define VM8 2
#define VM7 4
#define VM6 2
#define VM5 1
#define VM4 0
#define VM3 0
#define VM2 8
#define VM1 3
static char * VVi[33]={
#define Cdata VV[32]
(char *)(LI1),
(char *)(LI2),
(char *)(&LI2key),
(char *)(LI3),
(char *)(LI4),
(char *)(LI5),
(char *)(LI6),
(char *)(LI7),
(char *)(LI8),
(char *)(LI9),
(char *)(LI10),
(char *)(LI11),
(char *)(LI12),
(char *)(LI13),
(char *)(LI14),
(char *)(LI15),
(char *)(LI16),
(char *)(LI17),
(char *)(LI18),
(char *)(LI19),
(char *)(LI20),
(char *)(LI21),
(char *)(LI22),
(char *)(LI23),
(char *)(LI24),
(char *)(LI25),
(char *)(&LI25key)
};
#define VV ((object *)VVi)
static  LnkT31() ;
static  (*Lnk31)() = LnkT31;
static  LnkT30() ;
static  (*Lnk30)() = LnkT30;
static  LnkT29() ;
static  (*Lnk29)() = LnkT29;
static object  LnkTLI28() ;
static object  (*LnkLI28)() = LnkTLI28;
static  LnkT25() ;
static  (*Lnk25)() = LnkT25;
static  LnkT27() ;
static  (*Lnk27)() = LnkT27;
static object  LnkTLI26() ;
static object  (*LnkLI26)() = LnkTLI26;
static object  LnkTLI25() ;
static object  (*LnkLI25)() = LnkTLI25;
static object  LnkTLI24() ;
static object  (*LnkLI24)() = LnkTLI24;
static  LnkT23() ;
static  (*Lnk23)() = LnkT23;
static object  LnkTLI22() ;
static object  (*LnkLI22)() = LnkTLI22;
static object  LnkTLI21() ;
static object  (*LnkLI21)() = LnkTLI21;
static  LnkT16() ;
static  (*Lnk16)() = LnkT16;
