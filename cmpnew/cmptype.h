
static object LI1();
#define VMB1 register object *base=vs_top; object  V10 ,V8;
#define VMS1  register object *sup=vs_top+1;vs_top=sup;
#define VMV1 vs_reserve(1);
#define VMR1(VMT1) vs_top=base ; return(VMT1);
static object LI2();
#define VMB2 register object *base=vs_top; object  V34 ,V33;
#define VMS2  register object *sup=vs_top+2;vs_top=sup;
#define VMV2 vs_reserve(2);
#define VMR2(VMT2) vs_top=base ; return(VMT2);
static object LI3();
#define VMB3 register object *base=vs_top;
#define VMS3  register object *sup=vs_top+2;vs_top=sup;
#define VMV3 vs_reserve(2);
#define VMR3(VMT3) vs_top=base ; return(VMT3);
static object LI4();
#define VMB4 object  V116;
#define VMS4
#define VMV4
#define VMR4(VMT4) return(VMT4);
static object LI5();
#define VMB5 register object *base=vs_top;
#define VMS5  register object *sup=vs_top+1;vs_top=sup;
#define VMV5 vs_reserve(1);
#define VMR5(VMT5) vs_top=base ; return(VMT5);
static object LI6();
#define VMB6 register object *base=vs_top; object  V131 ,V130;
#define VMS6  register object *sup=vs_top+1;vs_top=sup;
#define VMV6 vs_reserve(1);
#define VMR6(VMT6) vs_top=base ; return(VMT6);
static object LI7();
#define VMB7 object  V141;
#define VMS7
#define VMV7
#define VMR7(VMT7) return(VMT7);
static object LI8();
#define VMB8
#define VMS8
#define VMV8
#define VMR8(VMT8) return(VMT8);
#define VM8 0
#define VM7 0
#define VM6 1
#define VM5 1
#define VM4 0
#define VM3 2
#define VM2 2
#define VM1 1
static char * VVi[72]={
#define Cdata VV[71]
(char *)(LI1),
(char *)(LI2),
(char *)(LI3),
(char *)(LI4),
(char *)(LI5),
(char *)(LI6),
(char *)(LI7),
(char *)(LI8)
};
#define VV ((object *)VVi)
static object  LnkTLI70() ;
static object  (*LnkLI70)() = LnkTLI70;
static object  LnkTLI69() ;
static object  (*LnkLI69)() = LnkTLI69;
static  LnkT68() ;
static  (*Lnk68)() = LnkT68;
static object  LnkTLI67() ;
static object  (*LnkLI67)() = LnkTLI67;
static object  LnkTLI36() ;
static object  (*LnkLI36)() = LnkTLI36;
static  LnkT60() ;
static  (*Lnk60)() = LnkT60;
static object  LnkTLI59() ;
static object  (*LnkLI59)() = LnkTLI59;
static object  LnkTLI58() ;
static object  (*LnkLI58)() = LnkTLI58;
static object  LnkTLI56() ;
static object  (*LnkLI56)() = LnkTLI56;
