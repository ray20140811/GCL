#define BSD386
#include "bsd.h"
/* #include "386.h" */
#undef HAVE_SIGVEC
#undef RUN_PROCESS

#define ADDITIONAL_FEATURES \
		     ADD_FEATURE("BSD386"); \
      	     ADD_FEATURE("MC68020")


#define	I386
#define	IEEEFLOAT
       

#undef HAVE_XDR

#ifdef IN_UNIXSAVE
#include <linux/user.h> 
#endif

#define USE_ULONG_
  
#define USE_ATT_TIME

/* fix this later.   How to check for input */
#undef LISTEN_FOR_INPUT

/* we dont need to worry about zeroing fp->_base , to prevent  */
#define FCLOSE_SETBUF_OK 

/* #define DATA_BEGIN((TXTRELOC+header.a_text+(SEGSIZ-1)) & ~(SEGSIZ-1)); */
#define DATA_BEGIN (char *)(char *)N_DATADDR(header);

/*
#undef   FILECPY_HEADER
#define FILECPY_HEADER \
	if (header.a_magic == ZMAGIC) \
		filecpy(save, original, PAGSIZ - sizeof(header)); \
	filecpy(save, original, header.a_text);
*/

#define RELOC_FILE "rel_sun3.c"



#define LITTLE_ENDIAN

#define	PAGSIZ		(NBPG)
#define	SEGSIZ		(NBPG * CLSIZE)
#define	TXTRELOC	0

#define USE_DIRENT
#define GETPATHNAME
#define PATHNAME_CACHE	10


/* try out the gnu malloc */
/* #define GNU_MALLOC */

/* #define SIGPROTV SIGBUS */
/* In my implementation I have put the address in code
   Doubtless this will change in Xinu code.
   
 */
#define GET_FAULT_ADDR(sig,code,sv,a) ((char *) code)

#define INSTALL_SEGMENTATION_CATCHER \
  	 (void) signal(SIGSEGV,segmentation_catcher)
/* if you are in an early version of linux without SIGBUS, uncomment
   the next line */
/* #define SIGBUS SIGSEGV */
#define SIGSYS SIGSEGV
#define SIGEMT SIGSEGV

/* get the fileno of a FILE* */
#define FILENO(x) fileno(x)

#define ULONG_DEFINED
#define NO_PROFILE

#define UNIXSAVE "unexlin.c"

#undef LD_COMMAND
#define LD_COMMAND(command,main,start,input,ldarg,output) \
  sprintf(command, "ld -d -S -N -x -A %s -T %x %s %s -o %s", \
            main,start,input,ldarg,output)

/* Begin for cmpinclude */
/* yes we have alloca */
#define HAVE_ALLOCA


/* NOTE: If you don't have the system call mprotect DON'T
   define this.
   I have added it to my own kernel.
   */
   
/* #define SGC */

/* _setjmp and _longjmp exist on bsd and are more efficient
   and handle the C stack which is all we need. [I think!]
   
 */


/* End for cmpinclude */


