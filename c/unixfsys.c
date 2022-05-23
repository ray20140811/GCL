/*
 Copyright (C) 1994 M. Hagiya, W. Schelter, T. Yuasa

This file is part of GNU Common Lisp, herein referred to as GCL

GCL is free software; you can redistribute it and/or modify it under
the terms of the GNU LIBRARY GENERAL PUBLIC LICENSE as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GCL is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public 
License for more details.

You should have received a copy of the GNU Library General Public License 
along with GCL; see the file COPYING.  If not, write to the Free Software
Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.

*/

#define IN_UNIXFSYS
#include "include.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>


#define	MAXPATHLEN	1024


#ifdef NEED_GETWD
#include <sys/dir.h>


#ifndef GETCWD
char dotdot[3*16+2] = "../../../../../../../../../../../../../../../../.";
#include <mnttab.h>
static char *getwd_buf;
static int getwd_bufp;

char *
getwd(buffer)
char *buffer;
{
	getwd_buf = buffer;
	getwd1(0);
	if (getwd_bufp == 0)
		getwd_buf[getwd_bufp++] = '/';
	getwd_buf[getwd_bufp] = '\0';
	return(getwd_buf);
}

getwd1(n)
int n;
{
	struct stat st, dev_st;
	struct direct dir;
	ino_t ino;
	struct mnttab mnt;
	FILE *fp;
	register int i;
	char buf[BUFSIZ];
	static char dev_name[64];

	if (stat(dotdot+(16-n)*3, &st) < 0)
		FEerror("Can't get the current working directory.", 0);
	ino = st.st_ino;
	if (ino == 2)
		goto ROOT;
	getwd1(n+1);
	fp = fopen(dotdot+(16-n-1)*3, "r");
	if (fp == NULL)
		FEerror("Can't get the current working directory.", 0);
	setbuf(fp, buf);
	fread(&dir, sizeof(struct direct), 1, fp);
	fread(&dir, sizeof(struct direct), 1, fp);
	for (;;) {
		if (fread(&dir, sizeof(struct direct), 1, fp) <= 0)
			break;
		if (dir.d_ino == ino)
			goto FOUND;
	}
	fclose(fp);
	FEerror("Can't get the current working directory.", 0);

FOUND:
	fclose(fp);
	getwd_buf[getwd_bufp++] = '/';
	for (i = 0;  i < DIRSIZ && dir.d_name[i] != '\0';  i++)
		getwd_buf[getwd_bufp++] = dir.d_name[i];
	return;

ROOT:
	fp = fopen("/etc/mnttab", "r");
	if (fp == NULL)
		FEerror("Can't get the current working directory.", 0);
	setbuf(fp, buf);
	for (;;) {
		if (fread(&mnt, sizeof(struct mnttab), 1, fp) <= 0)
			break;
		if (mnt.mt_dev[0] != '/') {
			strcpy(dev_name, "/dev/dsk/");
			strcat(dev_name, mnt.mt_dev);
			stat(dev_name, &dev_st);
		} else
			stat(mnt.mt_dev, &dev_st);
		if (dev_st.st_rdev == st.st_dev)
			goto DEV_FOUND;
	}
	fclose(fp);
	getwd_bufp = 0;
	return;

DEV_FOUND:
	fclose(fp);
	getwd_bufp = 0;
	for (i = 0;  mnt.mt_filsys[i] != '\0';  i++)
		getwd_buf[i] = mnt.mt_filsys[i];
	/* BUG FIX by Grant J. Munsey */
	if (i == 1 && *getwd_buf == '/')
		i = 0;	/* don't add an empty directory name */
	/* END OF BUG FIX */
	getwd_bufp = i;
}
#endif   /* not GETCWD */
#endif

#ifdef GETCWD
char *
getwd(buffer)
char *buffer;
{
	char *getcwd();

	return(getcwd(buffer, MAXPATHLEN));
}
#endif

#ifdef DGUX



















































#endif


coerce_to_filename(pathname, p)
object pathname;
char *p;
{
  int n;
  object namestring;
  namestring = coerce_to_namestring(pathname);
  if(namestring->st.st_self[0]=='~')
    {char name[20];
     int j;
     object ans;
     char *q = namestring->st.st_self;
     extern struct passwd *getpwuid();
     extern struct passwd *getpwnam();
	   
     char filename[MAXPATHLEN];
     struct passwd *pwent;
     int m;
     q=namestring->st.st_self;
     for (n=0; n< namestring->st.st_fillp; n++)
       if (q[n]=='/') break;
     bcopy(q+1,name,n-1);
     name[n-1]= 0;
     pwent = (n==1 ? getpwuid(getuid()) : getpwnam(name));
     if (pwent==0 || ((m = strlen(pwent->pw_dir))
		     && (m + namestring->st.st_fillp -n) >= MAXPATHLEN -16))
       {FEerror("Can't expand pathname ~a", 1,namestring);}
     bcopy(pwent->pw_dir,p,m);
     bcopy(namestring->st.st_self+n,p+m,namestring->st.st_fillp-n);
     p[m+namestring->st.st_fillp-n]=0;}
  else
    {if (namestring->st.st_fillp >= MAXPATHLEN - 16) {
      vs_push(namestring);
      FEerror("Too long filename: ~S.", 1, namestring);}
     bcopy(namestring->st.st_self,p,namestring->st.st_fillp);
     p[namestring->st.st_fillp]=0;}
}

object
truename(pathname)
object pathname;
{
	register char *p, *q;
	char filename[MAXPATHLEN];
	char truefilename[MAXPATHLEN];
	char current_directory[MAXPATHLEN];
	char directory[MAXPATHLEN];
	char *getwd();

	coerce_to_filename(pathname, filename);
	for (p = filename, q = 0;  *p != '\0';  p++)
		if (*p == '/')
			q = p;
	if (q == filename) {
		q++;
		getwd(current_directory);
		p = "/";
	} else if (q == 0) {
		q = filename;
		p = getwd(current_directory);
	} else {
		*q++ = '\0';
		getwd(current_directory);
		if (chdir(filename) < 0)
		    FEerror("Cannot get the truename of ~S.", 1, pathname);
		p = getwd(directory);
	}
	if (p[0] == '/' && p[1] == '\0') {
		if (strcmp(q, "..") == 0)
			strcpy(truefilename, "/.");
		else
			sprintf(truefilename, "/%s", q);
	} else if (strcmp(q, ".") == 0)
		strcpy(truefilename, p);
	else if (strcmp(q, "..") == 0) {
		for (q = p + strlen(p);  *--q != '/';) ;
		if (p == q)
			strcpy(truefilename, "/.");
		else {
			*q = '\0';
			strcpy(truefilename, p);
			*q = '/';
		}
	} else
		sprintf(truefilename, "%s/%s", p, q);
	chdir(current_directory);
	vs_push(make_simple_string(truefilename));
	pathname = coerce_to_pathname(vs_head);
	vs_pop;
	return(pathname);
}

bool
file_exists(file)
object file;
{
	char filename[MAXPATHLEN];
	struct stat filestatus;

	coerce_to_filename(file, filename);
	if (stat(filename, &filestatus) >= 0)
	  {
#ifdef AIX
	    /* if /tmp/foo is not a directory /tmp/foo/ should not exist */
	    if (filename[strlen(filename)-1] == '/' &&
		!( filestatus.st_mode & S_IFDIR))
		return(FALSE);
#endif	    

	    return TRUE;
	  }
	
	else
		return(FALSE);
}

FILE *
backup_fopen(filename, option)
char *filename,*option;
{
	char backupfilename[MAXPATHLEN];
	char command[MAXPATHLEN * 2];

	strcat(strcpy(backupfilename, filename), ".BAK");
	sprintf(command, "mv %s %s", filename, backupfilename);
	system(command);
	return(fopen(filename, option));
}

int
file_len(fp)
FILE *fp;
{
	struct stat filestatus;

	fstat(fileno(fp), &filestatus);
	return(filestatus.st_size);
}

Ltruename()
{
	check_arg(1);
	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	vs_base[0] = truename(vs_base[0]);
}

Lrename_file()
{
	char filename[MAXPATHLEN];
	char newfilename[MAXPATHLEN];
	char command[MAXPATHLEN * 2];

	check_arg(2);
	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	check_type_or_Pathname_string_symbol(&vs_base[1]);
	coerce_to_filename(vs_base[0], filename);
	vs_base[0] = coerce_to_pathname(vs_base[0]);
	vs_base[1] = coerce_to_pathname(vs_base[1]);
	vs_base[1] = merge_pathnames(vs_base[1], vs_base[0], Cnil);
	coerce_to_filename(vs_base[1], newfilename);
#ifdef BSD
	if (rename(filename, newfilename) < 0)
		FEerror("Cannot rename the file ~S to ~S.",
			2, vs_base[0], vs_base[1]);
#else
	sprintf(command, "mv %s %s", filename, newfilename);
	system(command);
#endif
	vs_push(vs_base[1]);
	vs_push(truename(vs_base[0]));
	vs_push(truename(vs_base[1]));
	vs_base += 2;
}

Ldelete_file()
{
	char filename[MAXPATHLEN];

	check_arg(1);
	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	coerce_to_filename(vs_base[0], filename);
	if (unlink(filename) < 0)
		FEerror("Cannot delete the file ~S.", 1, vs_base[0]);
	vs_base[0] = Ct;
}

Lprobe_file()
{
	check_arg(1);

	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	if (file_exists(vs_base[0]))
		vs_base[0] = truename(vs_base[0]);
	else
		vs_base[0] = Cnil;
}

Lfile_write_date()
{
	char filename[MAXPATHLEN];
	struct stat filestatus;

	check_arg(1);
	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	coerce_to_filename(vs_base[0], filename);
	if (stat(filename, &filestatus) < 0) { vs_base[0] = Cnil; return;}
	vs_base[0] = unix_time_to_universal_time(filestatus.st_mtime);
}

Lfile_author()
{
	char filename[MAXPATHLEN];
	struct stat filestatus;
	struct passwd *pwent;
	extern struct passwd *getpwuid();

	check_arg(1);
	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	coerce_to_filename(vs_base[0], filename);
	if (stat(filename, &filestatus) < 0) { vs_base[0] = Cnil; return;}
	pwent = getpwuid(filestatus.st_uid);
	vs_base[0] = make_simple_string(pwent->pw_name);
}

Luser_homedir_pathname()
{
	struct passwd *pwent;
	char filename[MAXPATHLEN];
	register int i;
	extern struct passwd *getpwuid();

	if (vs_top - vs_base > 1)
		too_many_arguments();
	pwent = getpwuid(getuid());
	strcpy(filename, pwent->pw_dir);
	i = strlen(filename);
	if (filename[i-1] != '/') {
		filename[i++] = '/';
		filename[i] = '\0';
	}
	vs_base[0] = make_simple_string(filename);
	vs_top = vs_base+1;
	vs_base[0] = coerce_to_pathname(vs_base[0]);
}


#ifdef BSD
Ldirectory()
{
	char filename[MAXPATHLEN];
	char command[MAXPATHLEN * 2];
	FILE *fp;
	register i, c;
	object *top = vs_top;
	char iobuffer[BUFSIZ];
	extern FILE *popen();

	check_arg(1);

	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	vs_base[0] = coerce_to_pathname(vs_base[0]);
	if (vs_base[0]->pn.pn_name==Cnil && vs_base[0]->pn.pn_type==Cnil) {
		coerce_to_filename(vs_base[0], filename);
		strcat(filename, "*");
	} else if (vs_base[0]->pn.pn_name==Cnil) {
		vs_base[0]->pn.pn_name = Kwild;
		coerce_to_filename(vs_base[0], filename);
		vs_base[0]->pn.pn_name = Cnil;
	} else if (vs_base[0]->pn.pn_type==Cnil) {
		coerce_to_filename(vs_base[0], filename);
		strcat(filename, "*");
	} else
		coerce_to_filename(vs_base[0], filename);
	sprintf(command, "ls -d %s 2> /dev/null", filename);
	fp = popen(command, "r");
	setbuf(fp, iobuffer);
	for (;;) {
		for (i = 0;  c = getc(fp);  i++)
			if (c <= 0)
				goto L;
			else if (c == '\n')
				break;
			else
				filename[i] = c;
		filename[i] = '\0';
		vs_push(make_simple_string(filename));
		vs_head = truename(vs_head);
	}
L:
	pclose(fp);
	vs_push(Cnil);
	while (vs_top > top + 1)
		stack_cons();
	vs_base = top;
}
#endif


#ifdef ATT
Ldirectory()
{
	object name, type;
	char filename[MAXPATHLEN];
	FILE *fp;
	object *top = vs_top;
	char iobuffer[BUFSIZ];
	struct direct dir;
	int i;

	check_arg(1);

	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	vs_base[0] = coerce_to_pathname(vs_base[0]);
	vs_push(vs_base[0]->pn.pn_name);
	vs_push(vs_base[0]->pn.pn_type);
	vs_base[0]->pn.pn_name = Cnil;
	vs_base[0]->pn.pn_type = Cnil;
	coerce_to_filename(vs_base[0], filename);
	type = vs_base[0]->pn.pn_type = vs_pop;
	name = vs_base[0]->pn.pn_name = vs_pop;
	i = strlen(filename);
	if (i > 1 && filename[i-1] == '/')
		filename[i-1] = '\0';
	if (i == 0)
		strcpy(filename, ".");
	fp = fopen(filename, "r");
	if (fp == NULL) {
		vs_push(make_simple_string(filename));
		FEerror("Can't open the directory ~S.", 1, vs_head);
	}
	setbuf(fp, iobuffer);
	fread(&dir, sizeof(struct direct), 1, fp);
	fread(&dir, sizeof(struct direct), 1, fp);
	filename[DIRSIZ] = '\0';
	for (;;) {
		if (fread(&dir, sizeof(struct direct), 1, fp) <=0)
			break;
		if (dir.d_ino == 0)
			continue;
		strncpy(filename, dir.d_name, DIRSIZ);
		vs_push(make_simple_string(filename));
		vs_head = coerce_to_pathname(vs_head);
		if ((name == Cnil || name == Kwild ||
		     equal(name, vs_head->pn.pn_name)) &&
		    (type == Cnil || type == Kwild ||
		     equal(type, vs_head->pn.pn_type))) {
			vs_head->pn.pn_directory
			= vs_base[0]->pn.pn_directory;
			vs_head = truename(vs_head);
		} else
			vs_pop;
	}
	fclose(fp);
	vs_push(Cnil);
	while (vs_top > top + 1)
		stack_cons();
	vs_base = top;
}
#endif


#ifdef E15
#include <sys/dir.h>
Ldirectory()
{
	object name, type;
	char filename[MAXPATHLEN];
	FILE *fp;
	object *top = vs_top;
	char iobuffer[BUFSIZ];
	struct direct dir;
	int i;

	check_arg(1);

	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	vs_base[0] = coerce_to_pathname(vs_base[0]);
	vs_push(vs_base[0]->pn.pn_name);
	vs_push(vs_base[0]->pn.pn_type);
	vs_base[0]->pn.pn_name = Cnil;
	vs_base[0]->pn.pn_type = Cnil;
	coerce_to_filename(vs_base[0], filename);
	type = vs_base[0]->pn.pn_type = vs_pop;
	name = vs_base[0]->pn.pn_name = vs_pop;
	i = strlen(filename);
	if (i > 1 && filename[i-1] == '/')
		filename[i-1] = '\0';
	if (i == 0)
		strcpy(filename, ".");
	fp = fopen(filename, "r");
	if (fp == NULL) {
		vs_push(make_simple_string(filename));
		FEerror("Can't open the directory ~S.", 1, vs_head);
	}
	setbuf(fp, iobuffer);
	fread(&dir, sizeof(struct direct), 1, fp);
	fread(&dir, sizeof(struct direct), 1, fp);
	filename[DIRSIZ] = '\0';
	for (;;) {
		if (fread(&dir, sizeof(struct direct), 1, fp) <=0)
			break;
		if (dir.d_ino == 0)
			continue;
		strncpy(filename, dir.d_name, DIRSIZ);
		vs_push(make_simple_string(filename));
		vs_head = coerce_to_pathname(vs_head);
		if ((name == Cnil || name == Kwild ||
		     equal(name, vs_head->pn.pn_name)) &&
		    (type == Cnil || type == Kwild ||
		     equal(type, vs_head->pn.pn_type))) {
			vs_head->pn.pn_directory
			= vs_base[0]->pn.pn_directory;
			vs_head = truename(vs_head);
		} else
			vs_pop;
	}
	fclose(fp);
	vs_push(Cnil);
	while (vs_top > top + 1)
		stack_cons();
	vs_base = top;
}
#endif


#ifdef DGUX
















































#endif

siLchdir()
{
	char filename[MAXPATHLEN];

	check_arg(1);
	check_type_or_pathname_string_symbol_stream(&vs_base[0]);
	coerce_to_filename(vs_base[0], filename);
	if (chdir(filename) < 0)
		FEerror("Can't change the current directory to ~S.",
			1, vs_base[0]);
}

init_unixfsys()
{
	make_function("TRUENAME", Ltruename);
	make_function("RENAME-FILE", Lrename_file);
	make_function("DELETE-FILE", Ldelete_file);
	make_function("PROBE-FILE", Lprobe_file);
	make_function("FILE-WRITE-DATE", Lfile_write_date);
	make_function("FILE-AUTHOR", Lfile_author);
	make_function("USER-HOMEDIR-PATHNAME", Luser_homedir_pathname);
	make_function("DIRECTORY", Ldirectory);

	make_si_function("CHDIR", siLchdir);
}
