
static object LI1();
#define VMB1 register object *base=vs_top;
#define VMS1 vs_top += 1;
#define VMV1 vs_reserve(1);
#define VMR1(VMT1) vs_top=base ; return(VMT1);
static object LI2();
#define VMB2 register object *base=vs_top; object  V10;
#define VMS2  register object *sup=vs_top+3;vs_top=sup;
#define VMV2 vs_reserve(3);
#define VMR2(VMT2) vs_top=base ; return(VMT2);
static object LI3();
#define VMB3
#define VMS3
#define VMV3
#define VMR3(VMT3) return(VMT3);
static object LI4();
#define VMB4 register object *base=vs_top; object  V19;
#define VMS4 vs_top += 4;
#define VMV4 vs_reserve(4);
#define VMR4(VMT4) vs_top=base ; return(VMT4);
static object LI5();
#define VMB5 register object *base=vs_top; object  V28 ,V27;
#define VMS5 vs_top += 4;
#define VMV5 vs_reserve(4);
#define VMR5(VMT5) vs_top=base ; return(VMT5);
static object LI6();
#define VMB6 register object *base=vs_top; object  V35 ,V34;
#define VMS6 vs_top += 1;
#define VMV6 vs_reserve(1);
#define VMR6(VMT6) vs_top=base ; return(VMT6);
static object LI7();
#define VMB7 register object *base=vs_top; object  V44 ,V43;
#define VMS7 vs_top += 2;
#define VMV7 vs_reserve(2);
#define VMR7(VMT7) vs_top=base ; return(VMT7);
#define VM7 2
#define VM6 1
#define VM5 4
#define VM4 4
#define VM3 0
#define VM2 3
#define VM1 1
static char * VVi[37]={
#define Cdata VV[36]
(char *)(LI1),
(char *)(LI2),
(char *)(LI3),
(char *)(LI4),
(char *)(LI5),
(char *)(LI6),
(char *)(LI7)
};
#define VV ((object *)VVi)
static object  LnkTLI34() ;
static object  (*LnkLI34)() = LnkTLI34;
static object  LnkTLI33() ;
static object  (*LnkLI33)() = LnkTLI33;
static object  LnkTLI32() ;
static object  (*LnkLI32)() = LnkTLI32;
static object  LnkTLI31() ;
static object  (*LnkLI31)() = LnkTLI31;
static  LnkT30() ;
static  (*Lnk30)() = LnkT30;
static object  LnkTLI29() ;
static object  (*LnkLI29)() = LnkTLI29;
static object  LnkTLI28() ;
static object  (*LnkLI28)() = LnkTLI28;
static object  LnkTLI27() ;
static object  (*LnkLI27)() = LnkTLI27;
static object  LnkTLI26() ;
static object  (*LnkLI26)() = LnkTLI26;
static object  LnkTLI25() ;
static object  (*LnkLI25)() = LnkTLI25;
static object  LnkTLI24() ;
static object  (*LnkLI24)() = LnkTLI24;
static object  LnkTLI23() ;
static object  (*LnkLI23)() = LnkTLI23;
