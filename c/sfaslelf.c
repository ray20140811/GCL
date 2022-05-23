
#define ELF_TARGET_SPARC 1
/* #include "include.h" */
#include "ext_sym.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>


#include <elf.h>


#ifdef STAND
char *kcl_self;
main(argc,argv)
     char *argv[];
{char *file ;
 file = argv[1];
 kcl_self = argv[2];
 fasload(file);
}
#endif

static Elf32_Ehdr *file_h;
static Elf32_Shdr *section_h;
static caddr_t base;
static char *string_table;
static char *section_names;
static int text_index;
struct sect {int start;
      };
static struct sect *section;

static int symsize;

char *the_start,*start_address;


#define SECTION_H(n) \
     (*(Elf32_Shdr *) ((char *) section_h + file_h->e_shentsize * (n)))


/* align for power of two n */
void *
round_up(address,n)
     unsigned int address,n;
{
 return  (void *)((address + n -1) & ~(n-1)) ;
}
#define ROUND_UP(a,b) round_up(a,b) 


fasload(faslfile)
     object faslfile;
{  FILE *fp;
   object data;
   char filename[256];
   Elf32_Shdr *shp;
   int file;
   struct stat stat_buf;
   object     * old_vs_base =   vs_base ;
   object     * old_vs_top =   vs_top ;
   int symtab_index,j;
   int nsyms;
   int init_address=0;
   int extra_bss=0;
   object memory;
   int current = 0,max_align = 0;
   struct sect section_org[40];
   Elf32_Sym *symbol_table;

   section = section_org;

#ifdef STAND
   strcpy(filename,faslfile);
   fp=fopen(filename,RDONLY);
#else
   coerce_to_filename(faslfile, filename);
   faslfile = open_stream(faslfile, smm_input, Cnil, Kerror);
   fp = faslfile->sm.sm_fp;
#endif	

       
   file = fileno(fp);

   if (fstat (file, &stat_buf) == -1)
     FEerror ("Can't fstat(~a): errno %d\n", 1,faslfile);

   base = mmap (0, stat_buf.st_size,PROT_READ|PROT_WRITE, MAP_PRIVATE, file, 0);

   if (base == (caddr_t) -1)
     FEerror ("Can't mmap(~a):",1,faslfile);

   file_h = (Elf32_Ehdr *) base;

   section_h = (Elf32_Shdr *) ((char *) base + file_h->e_shoff);
  
   section_names = (char *) base
     + SECTION_H(file_h->e_shstrndx).sh_offset;

   symtab_index = get_section_number(".symtab");
   text_index = get_section_number(".text");

   /* calculate how much room is needed to align all the sections
    appropriately, and at what offsets they will be read in, presuming
    that the begin of the memory is aligned on max_align */
   for (j=1 ; j <  file_h->e_shnum ; j++)
      { 
	if ((SECTION_H(j).sh_flags & SHF_ALLOC)
	    && (SECTION_H(j).sh_type == SHT_PROGBITS))

	  { if (SECTION_H(j).sh_addralign > max_align)
	      max_align = SECTION_H(j).sh_addralign;
	    current = (int) ROUND_UP(current,SECTION_H(j).sh_addralign);
	    section[j].start = current;
	    current += SECTION_H(j).sh_size;
	  }
      }
	    
   
   shp = &SECTION_H(symtab_index);
   symbol_table = (void *) base + shp->sh_offset;
   nsyms = shp->sh_size/shp->sh_entsize;
   symsize = shp->sh_entsize;

   string_table = base + SECTION_H(get_section_number(".strtab")).sh_offset;

   /* seek to end of old file */
   SEEK_TO_END_OFILE(fp);


   if (!((c_table.ptable) && *(c_table.ptable)))
     build_symbol_table();

   extra_bss = 0;
   /*
   extra_bss=get_extra_bss(symbol_table,nsyms,current,
			   &init_address,bss_size);
			   */


   memory = alloc_object(t_cfdata);
   memory->cfd.cfd_self = 0;
   memory->cfd.cfd_start = 0;
   memory->cfd.cfd_size = current + (max_align > sizeof(char *) ?
				     max_align :0);
   

   the_start=start_address=        
     memory->cfd.cfd_start =	
       alloc_contblock(memory->cfd.cfd_size);

    /* make sure the memory is aligned */
   start_address = ROUND_UP(start_address,max_align);
   memory->cfd.cfd_size = memory->cfd.cfd_size - (start_address - the_start);
   memory->cfd.cfd_start = start_address;	


    for (j=1 ; j <  file_h->e_shnum ; j++)
      { if ((SECTION_H(j).sh_flags & SHF_ALLOC)
	    && (SECTION_H(j).sh_type == SHT_PROGBITS))
	  { 
	    bcopy(base + SECTION_H(j).sh_offset,start_address + section[j].start,
		  SECTION_H(j).sh_size);
	  }
      }
   
   relocate_symbols(symbol_table,nsyms);

   {int j=0;
    for (j=1 ; j <  file_h->e_shnum ; j++)
      { shp = &SECTION_H(j); 
	if (shp->sh_type == SHT_RELA)
	  { int index_to_relocate = shp->sh_info;
	    if (symtab_index != shp->sh_link)
	      FEerror("unexpected symbol table used");
	    the_start = start_address + section[index_to_relocate].start;
	    }
	else
	  if (shp->sh_type == SHT_REL)
	    FEerror("unknown rel type");
	  else continue;
	{int k=0;
	 char *rel = (char *) base +   shp->sh_offset;
	 for (k= 0; k< shp->sh_size ; k+= shp->sh_entsize)
	   relocate(symbol_table,rel + k);
       }}}

   SEEK_TO_END_OFILE(fp);
   if (feof(fp))
     data=0;
   else
     data = read_fasl_vector(faslfile);

   munmap(base, stat_buf.st_size);

   close_stream(faslfile, 1);

#ifdef CLEAR_CACHE
   CLEAR_CACHE;
#endif

   init_address = section[text_index].start;
   call_init(init_address,memory,data);
	
   vs_base = old_vs_base;
   vs_top = old_vs_top;
   if(symbol_value(Vload_verbose)!=Cnil)
     printf("start address -T %x ",memory->cfd.cfd_start);
   return(memory->cfd.cfd_size);

 }


get_section_number(name)
     char *name;
     
{int k ;
 for (k = 1; k < file_h->e_shnum;
      k++)
   {
     if (!strcmp (section_names + SECTION_H(k).sh_name,
		  name))
       return k;
   }
/* fprintf(stderr,"could not find section %s\n", name); */
 return 0;
}

relocate_symbols(sym,nsyms)
 Elf32_Sym *sym;
 int nsyms;
{  int siz = symsize;
  while (--nsyms >= 0)
    { switch(ELF32_ST_BIND(sym->st_info))
	{ case STB_LOCAL:
	    if (sym->st_shndx == SHN_ABS) break;
	    if ((SECTION_H(sym->st_shndx).sh_flags & SHF_ALLOC) == 0)
	      {printf("[unknown rel secn %d]",sym->st_shndx);}
	    else
	      sym->st_value += (int) (start_address + section[sym->st_shndx].start); 
	    break;
	  case STB_GLOBAL:
	 if (sym->st_shndx == SHN_UNDEF
	     || sym->st_shndx == SHN_COMMON)
	   {  set_symbol_address(sym,string_table + sym->st_name);
	    }
	    else
	      if (sym->st_shndx == text_index &&
		  bcmp("init_",string_table + sym->st_name,4) == 0) ;
	    else	
	      {printf("[unknown global sym %s]",string_table + sym->st_name);}
	    break;
	  default:
	    {printf("[unknown bind type %s]",ELF32_ST_BIND(sym->st_info));}
	  }
      sym = (void *)sym + siz;
    }
}

relocate(symbol_table,reloc_info)
Elf32_Rela *reloc_info;
Elf32_Sym *symbol_table;
{
  char *where ;
  {
    unsigned int new_value;
    unsigned int a,b,p,s,val;
    a = reloc_info->r_addend;
    b = (unsigned int) the_start;
    s = symbol_table[ELF32_R_SYM(reloc_info->r_info)].st_value;
    where = the_start + reloc_info->r_offset;
    p = (unsigned int) where;


#define MASK(n) (~(~0 << (n)))
#define STORE_VAL(where, mask, val) \
    *(unsigned int *)where = ((val & mask) | ((*(unsigned int *)where) & ~mask))
    
    switch(ELF32_R_TYPE(reloc_info->r_info)){
    case     R_SPARC_WDISP30:
      /* v-disp30*/
      val=(s+a-p) >> 2;
      STORE_VAL(where,MASK(30),val);
      break;
	
    case R_SPARC_HI22:
      /* t-sim22 */
      val = (s+a)>>10;
      STORE_VAL(where,MASK(22),val);
      break;

    case R_SPARC_32:
      /*    */
      val = (s+a) ;
      STORE_VAL(where,~0,val);
      break;
      
    case R_SPARC_LO10:
	/* T-simm13 */
      val = (s+a) & MASK(10);
      *(short *)(where +2) |= val;
      break;
    default:
      printf("(non supported relocation type %d)\n",
	     ELF32_R_TYPE(reloc_info->r_info));
    }
  }
}

 

#include "sfasli.c"

set_symbol_address(sym,string)
Elf32_Sym *sym;
char *string;
{struct node *answ;
 if (c_table.ptable)
   {
     answ = find_sym_ptable(string);
     if(answ)
       {
	 /* the old value of sym->n_value is the length of the common area
	    starting at this address */
	 sym->st_value = answ->address;
	 
	 
       }
     else
       { 
	 fprintf(stdout,"symbol %s is not in base image",string);
	 fflush(stdout);
       }}
    else{FEerror("symbol table not loaded",0,0);}
   
}

#define STRUCT_SYMENT Elf32_Sym

/* dont try to add extra bss stuff here.   It is not really
common so other files can't reference it, so we really
should use static.
*/

get_extra_bss(symbol_table,length,start,ptr,bsssize)
int length,bsssize,start;
STRUCT_SYMENT *symbol_table;
int *ptr;   /* store init address offset here */
{ return 0;
}


