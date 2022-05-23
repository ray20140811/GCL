
#ifndef FIRSTWORD
#include        <setjmp.h>
#endif
/*
#include        <signal.h>
#include        <stdio.h>
#include        <string.h>
#include        <math.h>
#include        <malloc.h>
#include        <ctype.h>
#include        <sys/time.h>
#include        <sys/file.h>
#include        <sys/resource.h>
*/

#ifdef AIX3
#define ulong ulong_
#endif

#include "gencom.h"
#include "erreurs.h"
#include "genport.h"

extern ulong ABS_MOST_NEGS[];
extern ulong MOST_NEGS[];

GEN addii();
GEN icopy();
GEN divss();
GEN rcopy();

int in_saved_avma ;

/* #define DEBUG_AVMA */

#ifdef DEBUG_AVMA
#define save_avma long lvma = (in_saved_avma = 1, avma)
#define restore_avma avma = (in_saved_avma = 0, lvma)
#else
#define save_avma long lvma = avma
#define restore_avma avma = lvma
#endif











