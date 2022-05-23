#ifndef FIRSTWORD
#include "include.h"
#endif

memory_save(original_file,save_file)
     char *original_file,*save_file;
{
  
  unexec(save_file,original_file,0,0,0);
}


Lsave()
{
	char filename[256];

	check_arg(1);
	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	coerce_to_filename(vs_base[0], filename);

	_cleanup();
	memory_save(kcl_self, filename);

	exit(0);
	/*  no return  */
}
