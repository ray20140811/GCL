#define IN_INIT_PARI

#ifndef STANDALONE
#include "include.h"
#endif
#include "genpari.h"  


GEN     gnil,gzero,gun,gdeux,ghalf,polvar,gi,RAVYZARC;
long    lontyp[30]={0,0x10000,0x10000,1,1,1,1,2,1,0,2,2,1,1,1,0,1,1,1,1};
unsigned long hiremainder,overflow;

#ifdef STANDALONE
#define FEerror printf
#define make_si_sfun(a,b,c) 
#endif

#define INITIAL_PARI_STACK 400
char initial_pari_stack[400];

ulong bot= (ulong) initial_pari_stack;
ulong top = (ulong)(initial_pari_stack+INITIAL_PARI_STACK);
/* not initted */
ulong avma= 0;


void
err(s)
     int s;
{ if (s==errpile)
  FEerror("Out of bignum stack space, (si::MULTIPLY-BIGNUM-STACK n) to grow");
  else
      FEerror("bignum error");
}




multiply_bignum_stack(n)
     int n;
{ int parisize = n* (top - bot);
  in_saved_avma = 0;
  if (n> 1) 
    { if (bot != (ulong)initial_pari_stack) free(bot);
      set_pari_stack(parisize);
    }
  return parisize;
}
  
set_pari_stack(parisize)
     int parisize;
{
  bot=(long)malloc(parisize);
  top = avma = bot + parisize;
}


init_pari()
{
  if (avma==0)
    { 
	make_si_sfun("MULTIPLY-BIGNUM-STACK",multiply_bignum_stack,
		     ARGTYPE1(f_fixnum) | RESTYPE(f_fixnum));
	avma = top;
      }
 /* room for the permanent things */
 
  gnil = cgeti(2);gnil[1]=2; setpere(gnil,255);
  gzero = cgeti(2);gzero[1]=2; setpere(gzero, 255);
  gun = stoi(1); setpere(gun, 255);
  gdeux = stoi(2); setpere(gdeux, 255);
  ghalf = cgetg(3,4);ghalf[1]=un;ghalf[2]=deux; setpere(ghalf, 255);
  gi = cgetg(3,6); gi[1] = zero; gi[2] = un; setpere(gi, 255);

  /* set_pari_stack(BIGNUM_STACK_SIZE);*/
 }



