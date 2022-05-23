
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*                                                                 */
/*                        Fichier Include PARI                     */
/*                                                                 */
/*                    commun a toutes les versions                 */
/*                                                                 */
/*                        copyright  Babecool                      */
/*                                                                 */
/*                                                                 */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

typedef long    *GEN;
#define ulong _ulong
typedef unsigned long ulong;

typedef struct entree {
  char *name;
  long valence;
  void *value;
  struct entree *next;
} entree;

typedef unsigned char *byteptr;

/*      Variables statiques communes :
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  */
extern  long    prec,precdl;
extern  GEN     bernzone,gpi,geuler;
extern  long    tglobal;
extern  long    *ordvar,varchanged;
extern  GEN     polvar;
extern  GEN     RAVYZARC;

extern  long    NUMFUNC;
extern  entree  fonctions[],*hashtable[];
extern  long    lontyp[],lontyp2[];

extern  jmp_buf environnement;

#ifndef IN_INIT_PARI
extern  unsigned long    avma,bot,top;
#endif

extern  GEN     gnil,gun,gdeux,ghalf,gi,gzero;

extern  GEN     *polun,*polx;
extern  byteptr diffptr;

extern  GEN     *g;
extern  entree  **varentries; /* noms des inconnues actives */
extern  GEN     *blocliste;   /* tableau des pointeur de blocs */
extern  long    nvar;         /* numero de la prochaine inconnue */
extern  long    glbfmt[];

extern  char    *helpmessage[]; /* un message pour chaque fonction predefinei */
extern  char    *errmessage[];  /* un par numero d'erreur */

#define STACKSIZE       500  /* nombre de gn possibles */
#define MAXVAR          150  /* nombre maximum de variables */
#define TBLSZ           135  /* taille de la table de hashcodes */
#define MAXBLOC        5000  /* nombre de blocs autorises dans le tas */

#define K       9.632959862             /* 32*log(2)/log(10)    */
#define K1      0.103810253             /* log(10)/(32*log(2))  */
#define K2      1.1239968               /* 1/(1-(log(2)/(2*pi)))*/
#define K3      0.900643041             /* 1/(1+(log(2)/(2*pi)))*/
#define LOG2    0.693147180559945       /* log(2)               */
#define L2SL10  0.301029995663981       /* log(2)/log(10)       */
#undef  PI
#define PI      3.141592653589          /* pi                   */
#define rac5    2.23606797749           /* racine de 5          */
#define C1      0.9189385332            /* log(2*pi)/2          */
#define C2      22.18070978             /* 32*log(2)            */
#define C3      0.0216950598            /* log((1+sqrt(5))/2)/(32*log(2)) */
#define C4      4294967296.0            /* 2^32                 */
#define C31     2147483648.0            /* 2^31                 */
#define CN31    -2147483648.0           /* -2^31                */
#define BIGINT  32767                   /* 2^15-1               */

#ifndef exp2
#define exp2(x) exp((double)(x)*log(2.))
#define log2(x) log((double)(x))/log(2.)
#endif

#define separe(c)     ((c==';')||(c==':')||(c=='\n'))

#define output(x)     {brute(x,'g',-1);printf("\n");fflush(stdout);}
#define outbeaut(x)   {sor(x,'g',-1,0);printf("\n");fflush(stdout);}

#define addis(x,s)  addsi(s,x)
#define addrs(x,s)  addsr(s,x)
#define mulis(x,s)  mulsi(s,x)
#define mulrs(x,s)  mulsr(s,x)

#define gval(x,v) ggval(x,polx[v])

#define lgeti   (long)cgeti
#define lgetr   (long)cgetr
#define lpile   (long)gerepile
#define lstoi   (long)stoi
#define lnegi   (long)negi
#define lnegr   (long)negr
#define lmpneg  (long)mpneg
#define labsi   (long)absi
#define labsr   (long)absr
#define lmpabs  (long)mpabs
#define lmptrunc (long)mptrunc
#define lmpent  (long)mpent
#define lshifts (long)shifts
#define lshifti (long)shifti
#define lshiftr (long)shiftr
#define lmpshift (long)mpshift
#define laddsi  (long)addsi
#define laddsr  (long)addsr
#define laddis  (long)addis
#define laddrs  (long)addrs
#define laddii  (long)addii
#define laddir  (long)addir
#define laddrr  (long)addrr
#define lmpadd  (long)mpadd
#define lsubsi  (long)subsi
#define lsubis  (long)subis
#define lsubsr  (long)subsr
#define lsubrs  (long)subrs
#define lsubii  (long)subii
#define lsubir  (long)subir
#define lsubri  (long)subri
#define lsubrr  (long)subrr
#define lmpsub  (long)mpsub
#define lmulss  (long)mulss
#define lmulsi  (long)mulsi
#define lmulsr  (long)mulsr
#define lmulis  (long)mulis
#define lmulrs  (long)mulrs
#define lmulii  (long)mulii
#define lmulir  (long)mulir
#define lmulrr  (long)mulrr
#define lmpmul  (long)mpmul
#define ldivsi  (long)divsi
#define ldivis  (long)divis
#define ldivsr  (long)divsr
#define ldivrs  (long)divrs
#define ldivii  (long)divii
#define ldivir  (long)divir
#define ldivri  (long)divri
#define ldivrr  (long)divrr
#define lmpdiv  (long)mpdiv
#define lmodii  (long)modii
#define lresii  (long)resii
#define ldvmdii (long)dvmdii
#define ldvmdsi (long)dvmdsi
#define ldvmdis (long)dvmdis
  
#define ltree   (long)gettree
#define lgen    (long)getgen
#define lcopy   (long)gcopy
#define lclone  (long)gclone
#define lgetg   (long)cgetg
#define lgetp   (long)cgetp
#define laddpex (long)gaddpex
#define lgreffe (long)greffe
#define lopsg2  (long)gopsg2
#define lopgs2  (long)gopgs2
#define lco8    (long)co8
#define lneg    (long)gneg
#define labs    (long)gabs
#define lmax    (long)gmax
#define lmin    (long)gmin
#define ladd    (long)gadd
#define lsub    (long)gsub
#define lmul    (long)gmul
#define ldiv    (long)gdiv
#define linv    (long)ginv
#define lmod    (long)gmod
#define ldivmod (long)gdivmod
#define lshift  (long)gshift
#define lmul2n  (long)gmul2n
#define lpuigs  (long)gpuigs
#define lpui    (long)gpui
#define lsubst  (long)gsubst
#define lderiv  (long)deriv
#define linteg  (long)integ
#define lrecip  (long)recip
#define lceil   (long)gceil
#define lfloor  (long)gfloor
#define lround  (long)ground
#define lcvtoi  (long)gcvtoi
#define lrndtoi (long)grndtoi
#define lfrac   (long)gfrac
#define ltrunc  (long)gtrunc
  
#define lconcat (long)concat
#define lnorm   (long)gnorm
#define lnorml2 (long)gnorml2
#define lconj   (long)gconj
#define lreal   (long)greal
#define limag   (long)gimag
#define lmppi   (long)mppi
#define lmpeuler (long)mpeuler
#define lmpsqrt (long)mpsqrt
#define lsqrt   (long)gsqrt
#define lmpexp1 (long)mpexp1
#define lmpexp  (long)mpexp
#define lexp    (long)gexp
#define lmplog  (long)mplog
#define llog    (long)glog
#define lmpsc1  (long)mpsc1
#define lmpcos  (long)mpcos
#define lcos    (long)gcos
#define lmpsin  (long)mpsin
#define lsin    (long)gsin
#define lmpaut  (long)mpaut
#define lmptan  (long)mptan
#define ltan    (long)gtan
#define lmpatan (long)mpatan
#define latan   (long)gatan
#define lmpasin (long)mpasin
#define lasin   (long)gasin
#define lmpacos (long)mpacos
#define lacos   (long)gacos
#define lmpch   (long)mpch
#define lch     (long)gch
#define lmpsh   (long)mpsh
#define lsh     (long)gsh
#define lmpth   (long)mpth
#define lth     (long)gth
#define lmpath  (long)mpath
#define lath    (long)gath
#define lmpash  (long)mpash
#define lash    (long)gash
#define lmpach  (long)mpach
#define lach    (long)gach
#define lmpgamma (long)mpgamma
#define lgamma  (long)ggamma
#define lgamd   (long)ggamd
#define lmppsi  (long)mppsi
#define lpsi    (long)gpsi
#define lmpgamd (long)mpgamd
#define larg    (long)garg
#define lsqr    (long)gsqr
  
#define ltrans  (long)gtrans
#define lscalmat (long)gscalmat
#define lscalsmat (long)gscalsmat
#define laddmat (long)gaddmat
#define laddsmat (long)gaddsmat
#define lgauss  (long)gauss
#define linvmat (long)invmat
#define linvmulmat (long)invmulmat
#define ldet    (long)det
#define ldet2   (long)det2
#define lcaract (long)caract
#define lcaradj (long)caradj
#define ladj    (long)adj
#define ltrace  (long)trace
#define lassmat (long)assmat
#define lscal   (long)gscal
  
#define linvmod (long)ginvmod
#define lred    (long)gred
#define ldeuc   (long)gdeuc
#define lres    (long)gres
#define ldivres (long)poldivres
#define lpoleval (long)poleval
#define lroots  (long)roots
#define lgcd    (long)ggcd
#define lpolgcd (long)polgcd
#define lcontent (long)content
#define lprimpart (long)primpart
#define lpsres  (long)psres
#define lsubres (long)subres
#define ldiscsr (long)discsr
#define lquadpoly (long)quadpoly
#define lquadgen (long)quadgen
  
#define llegendre (long)legendre
#define ltchebi (long)tchebi
#define lhilb   (long)hilb
#define lpasc   (long)pasc
#define lprec   (long)gprec
#define lbinome (long)binome
  
#define lracine (long)racine
#define lmppgcd (long)mppgcd
#define lmpfact (long)mpfact
#define lsfcont (long)sfcont
#define lbezout (long)bezout
#define lmpinvmod (long)mpinvmod
#define lpuissmodulo (long)puissmodulo
#define lfibo   (long)fibo
#define lchangevar (long)changevar
  
#define zero    (long)gzero
#define un      (long)gun
#define deux    (long)gdeux
#define lhalf   (long)ghalf
  
#define lpolx   (long)polx
#define lpolun   (long)polun

#define laddsg(s,y)         (lopsg2(gadd,s,y))
#define laddgs(y,s)         (lopsg2(gadd,s,y))
#define lsubsg(s,y)         (lopsg2(gsub,s,y))
#define lsubgs(y,s)         (lopgs2(gsub,y,s))
#define lmulsg(s,y)         ((long)gmulsg(s,y))
#define lmulgs(y,s)         ((long)gmulsg(s,y))
#define ldivsg(s,y)         (lopsg2(gdiv,s,y))
#define ldivgs(x,s)         ((long)gdivgs(x,s))
#define lmodsg(s,y)         (lopsg2(gmod,s,y))
#define lmodgs(y,s)         (lopgs2(gmod,y,s))
#define ldiventsg(s,y)      (lopsg2(gdivent,s,y))
#define ldiventgs(y,s)      (lopgs2(gdivent,y,s))
#define lminsg(s,y)         (lopsg2(gmin,s,y))
#define lmings(y,s)         (lopgs2(gmin,y,s))
#define lmaxsg(s,y)         (lopsg2(gmax,s,y))
#define lmaxgs(y,s)         (lopgs2(gmax,y,s))


#define mppiz(x)              (gop0z(mppi,x))
#define mpeulerz(x)           (gop0z(mpeuler,x))
#define mpsqrtz(x,y)        (gop1z(mpsqrt,x,y))
#define mpexpz(x,y)         (gop1z(mpexp,x,y))
#define mpexp1z(x,y)        (gop1z(mpexp1,x,y))
#define mplogz(x,y)         (gop1z(mplog,x,y))
#define mpcosz(x,y)         (gop1z(mpcos,x,y))
#define mpsinz(x,y)         (gop1z(mpsin,x,y))
#define autz(x,y)           (gop1z(mpaut,x,y))
#define mptanz(x,y)         (gop1z(mptan,x,y))
#define mpatanz(x,y)        (gop1z(mpatan,x,y))
#define mpasinz(x,y)        (gop1z(mpasin,x,y))
#define mpacosz(x,y)        (gop1z(mpacos,x,y))
#define mpchz(x,y)          (gop1z(mpch,x,y))
#define mpshz(x,y)          (gop1z(mpsh,x,y))
#define mpthz(x,y)          (gop1z(mpth,x,y))
#define mpathz(x,y)         (gop1z(mpath,x,y))
#define mpashz(x,y)         (gop1z(mpash,x,y))
#define mpachz(x,y)         (gop1z(mpach,x,y))
#define mpgammaz(x,y)       (gop1z(mpgamma,x,y))
#define mpargz(x,y,z)      (gop2z(mparg,x,y,z))
#define mpfactz(s,y)        (gops1z(mpfact,s,y))

#define gredz(x,y)          (gop1z(gred,x,y))
#define gnegz(x,y)          (gop1z(gneg,x,y))
#define gabsz(x,y)          (gop1z(gabs,x,y))
#define gmaxz(x,y,z)       (gop2z(gmax,x,y,z))
#define gminz(x,y,z)       (gop2z(gmin,x,y,z))
#define gaddz(x,y,z)       (gop2z(gadd,x,y,z))
#define gsubz(x,y,z)       (gop2z(gsub,x,y,z))
#define gmulz(x,y,z)       (gop2z(gmul,x,y,z))
#define gdivz(x,y,z)       (gop2z(gdiv,x,y,z))
#define gdeucz(x,y,z)      (gop2z(gdeuc,x,y,z))
#define gmodz(x,y,z)       (gop2z(gmod,x,y,z))
#define gshiftz(x,s,z)      (gops2gsz(gshift,x,s,z))
#define gmul2nz(x,s,z)      (gops2gsz(gmul2n,x,s,z))
#define gaddsg(s,y)         (gopsg2(gadd,s,y))
#define gaddgs(y,s)         (gopsg2(gadd,s,y))
#define gsubsg(s,y)         (gopsg2(gsub,s,y))
#define gsubgs(y,s)         (gopgs2(gsub,y,s))
#define gcmpsg(s,y)         (-opgs2(gcmp,y,s))
#define gcmpgs(y,s)         (opgs2(gcmp,y,s))
#define gegalsg(s,y)        (opgs2(gegal,y,s))
#define gegalgs(y,s)        (opgs2(gegal,y,s))
#define gmulgs(y,s)         (gmulsg(s,y))
#define gdivsg(s,y)         (gopsg2(gdiv,s,y))
#define gdiventsg(s,y)      (gopsg2(gdivent,s,y))
#define gdiventgs(y,s)      (gopgs2(gdivent,y,s))
#define gmodsg(s,y)         (gopsg2(gmod,s,y))
#define gmodgs(y,s)         (gopgs2(gmod,y,s))
#define gminsg(s,y)         (gopsg2(gmin,s,y))
#define gmings(y,s)         (gopgs2(gmin,y,s))
#define gmaxsg(s,y)         (gopsg2(gmax,s,y))
#define gmaxgs(y,s)         (gopgs2(gmax,y,s))


#define gaddsgz(s,y,z)    (gopsg2z(gadd,s,y,z))
#define gaddgsz(y,s,z)    (gopsg2z(gadd,s,y,z))
#define gsubsgz(s,y,z)    (gopsg2z(gsub,s,y,z))
#define gsubgsz(y,s,z)    (gopgs2z(gsub,y,s,z))
#define gmulsgz(s,y,z)    (gops2sgz(gmulsg,s,y,z))
#define gmulgsz(y,s,z)    (gops2sgz(gmulsg,s,y,z))
#define gdivsgz(s,y,z)    (gopsg2z(gdiv,s,y,z))
#define gdivgsz(y,s,z)    (gops2gsz(gdivgs,y,s,z))
#define gdiventsgz(s,y,z) (gopsg2z(gdivent,s,y,z))
#define gdiventgsz(y,s,z) (gopgs2z(gdivent,y,s,z))
#define gmodsgz(s,y,z)    (gopsg2z(gmod,s,y,z))
#define gmodgsz(y,s,z)    (gopgs2z(gmod,y,s,z))
#define gminsgz(s,y,z)    (gopsg2z(gmin,s,y,z))
#define gmingsz(y,s,z)    (gopgs2z(gmin,y,s,z))
#define gmaxsgz(s,y,z)    (gopsg2z(gmax,s,y,z))
#define gmaxgsz(y,s,z)    (gopgs2z(gmax,y,s,z))

#define coeff(a,i,j)      (*((long*)(*(a+(j)))+(i)))
#define coef1(a,i,j)      (*((long*)(*(a+(j)+1))+(i)+1))
#define bern(i)         (bernzone + (i)*(*(bernzone + 2)) + 3)

#define isonstack(x)   (RAVYZARC=(GEN)(x),((RAVYZARC>=(GEN)bot)&&(RAVYZARC<(GEN)top)))
#define copyifstack(x) (RAVYZARC=(GEN)(x),((RAVYZARC>=(GEN)bot)&&(RAVYZARC<(GEN)top))?lcopy(RAVYZARC):(long)RAVYZARC)


#define odd(x)                (x & 1)
#define mpodd(x) (signe(x) && odd(mant(x,lgef(x) - 2)))
     
/* alglin.c */
     
GEN     gtrans(),gscalmat(),gscalsmat(),gaddmat(),gaddsmat();
GEN     ker(),keri(),kerreel(),eigen(),hess(),carhess();
GEN     gauss(),invmat(),det(),detreel(),det2(),caract(),caradj(),adj(),trace();
GEN     assmat(),gnorm(),gnorml2(),gconj(),concat(),idmat();
GEN     extract(),matextract(),gtomat(),invmulmat(),invmulmatreel(),invmatreel();
GEN     sqred(),sqred1(),signat(),jacobi();
long    rank();

/* anal.c */
     
GEN     lisexpr(),readexpr(),lisseq(),readseq();
     
/* arith.c */
     
GEN     racine(),mppgcd(),mpfact(),sfcont(),fc(),bezout(),chinois();
GEN     mpinvmod(),puissmodulo(),fibo(),bigprem(),prime(),primes();
GEN     phi(),decomp(),auxdecomp(),smallfact(),boundfact(),sumdiv(),sumdivk(),numbdiv();
GEN     ellfacteur(),classno(),classno2(),classno3(),fundunit(),regula();
GEN     compose(),sqcomp(),qf(),compose2(),sqcomp2(),qfred1(),primeform();
GEN     binaire(),order(),gener(),divisors();
     
long    kronecker(),krosg(),krogs(),kross(),kro8();
long    mu(),omega(),bigomega(),hil(),carreparfait();
long    isprime(),ispsp(),issquarefree(),isfundamental();
byteptr initprimes();

/* base.c */

GEN     base(),discf(),hnf(),smith();

/* bibli1.c */
     
GEN     tayl(),legendre(),tchebi(),hilb(),pasc(),laplace();
GEN     gprec(),convol(),ggrando(),gconvsp(),gaminc();
GEN     lll(),lllrat(),lllgram(),binome(),gscal();
GEN     lindep(),lindep2(),algdep(),changevar(),ordred();
GEN     polrecip(),reorder(),sort(),indexsort(),polred(),polsym();

     
/* bibli2.c */

GEN     somme(),produit(),suminf(),prodinf(),prodinf1(),prodeuler();
GEN     vecteur(),vvecteur(),matrice(),divsomme();
GEN     qromb(),qromo(),qromi(),rombint();
GEN     polint(),plot(),ploth(),ploth2(),zbrent(),sumalt(),sumpos();
GEN     forpari(),forstep(),fordiv(),forprime(),ghell(),ghell2(),ghell3();
GEN     initell(),zell(),coordch(),pointch();
GEN     addell(),subell(),powell(),matell(),ordell(),apell(),apell1(),apell2();
int     oncurve();
void    eulsum();

/* es.c */

void    sor(),brute(),texe();

/* gen1.c */

GEN     gadd(),gsub(),gmul(),gdiv();

/* gen2.c gen3.c */

GEN     gcopy(),gclone(),cgetg(),cgetp(),gaddpex();
GEN     greffe(),gopsg2(),gopgs2(),co8(),cvtop(),compo(),gsqr();
GEN     gneg(),gabs(),gmax(),gmin(),ginv(),denom(),numer(),lift();
GEN     gmulsg(),gdivgs(),gmodulo(),gmodulcp();
GEN     gmod(),gshift(),gmul2n(),gpuigs(),gpui();
GEN     gsubst(),deriv(),integ(),recip(),ground(),gcvtoi(),grndtoi();
GEN     gceil(),gfloor(),gfrac(),gtrunc(),gdivent(),gdiventres();
GEN     gdivmod(),geval(),glt(),gle(),ggt(),gge(),geq(),gne();
GEN     gand(),gor(),glength(),truecoeff();
GEN     gtopoly(),gtoser(),gtovec(),dbltor();

void    gop0z(),gop1z(),gop2z(),gops2gsz(),gops2sgz(),gops2ssz();
void    gop3z(),gops1z(),gopsg2z(),gopgs2z();
long    taille(),gexpo(),gsigne(),gcmp(),gtolong(),gegal();
long    polegal(),tdeg(),ismonome(),iscomplex(),gvar(),ggval();
double  rtodbl(),gtodouble();

/* init.c */

GEN     newbloc(),geni();
long    marklist();
void    init(),killbloc(),newvalue(),killvalue();
void    err(),recover(),changevalue();

/* polarit.c */
     
GEN     ginvmod(),gred(),gdeuc(),gres(),poldivres();
GEN     poleval(),roots(),ggcd(),gbezout(),vecbezout(),glcm();
GEN     polgcd(),srgcd(),polgcdnun(),content(),primpart(),psres();
GEN     factmod(),rootmod(),decpol(),factor(),factpol(),factpol2();
GEN     subres(),discsr(),quadpoly(),quadgen(),bezoutpol(),polinvmod();
long    sturm();
void    gredsp();
     
/* trans.c */
     
GEN     greal(),gimag(),teich(),agm(),palog();
GEN     mpsqrt(),gsqrt(),mpexp1(),mpexp(),gexp(),logagm(),glogagm();
GEN     mplog(),glog(),mpsc1(),mpcos(),gcos(),mpsin(),gsin();
GEN     mpaut(),mptan(),gtan(),mpatan(),gatan(),mpasin(),gasin();
GEN     mpacos(),gacos(),mparg(),mpch(),gch(),mpsh(),gsh();
GEN     mpth(),gth(),mpath(),gath(),mpash(),gash();
GEN     garg(),sarg(),mppsi(),gpsi(),transc(),kbessel(),hyperu();
GEN     cxpsi(),jbesselh(),gzeta();
GEN     kbessel2(),eint1(),gerfc(),eta(),jell(),wf2(),wf();
GEN     incgam(),incgam1(),incgam2(),incgam3(),bernreal(),bernvec();
GEN     mpach(),gach(),mpgamma(),cxgamma(),ggamma(),mpgamd(),ggamd(),mppi();
GEN     mpeuler(),polylog(),dilog(),polylogd(),polylogp();
GEN     theta(),thetanullk();

void    constpi(),consteuler(),gsincos();

/* version.c */

GEN     gerepilc();
void    printversion();
