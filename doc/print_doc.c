#include <stdio.h>
#include <sys/types.h>
#include <sys/file.h>

#define error(a,b) do {printf(a,b); exit(1);}while(0)

main(argc,argv)
int argc; char* argv[];
{FILE *fd;
 char *name=argv[1];
 int filepos;
char ch;
 if (argc != 3) error("Need 2 args %d provided",argc-1);
 sscanf(argv[2],"%d",&filepos);
	fd = fopen (name, "r");
  if (!fd)
   error  ("Cannot open doc string file \"%s\"", name);
  if (fseek (fd, filepos, 0))
    {      close (fd);
	   printf("Going to pos %d.  ",filepos);
	   error ("Position out of range in doc string file \"%s\"",
	      name);}
 while(ch=fgetc(fd))
   { if (ch==EOF || ch=='\037') break;
     fputc(ch,stdout);}
 fputc('\n',stdout);
 fclose(fd);
}

       
       
