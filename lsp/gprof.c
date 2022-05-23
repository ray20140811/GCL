
#include <cmpinclude.h>
#include "gprof.h"
init_gprof(){do_init(VV);}
#include "gprof.hc"
/*	function definition for WRITE-GMON+SYMS	*/

static L1()
{register object *base=vs_base;
	register object *sup=base+VM1; VC1
	vs_reserve(VM1);
	check_arg(0);
	vs_top=sup;
TTL:;
	base[0]= small_fixnum(0);
	base[1]= small_fixnum(0);
	base[2]= small_fixnum(0);
	base[3]= small_fixnum(0);
	vs_top=(vs_base=base+0)+4;
	(void) (*Lnk0)();
	vs_top=sup;
	princ_str("writing syms..",Cnil);
	vs_base=vs_top;
	(void) (*Lnk1)();
	vs_top=sup;
	vs_base=vs_top;
	(void) (*Lnk2)();
	return;
}
/*	function definition for MONSTARTUP	*/

static L2()
{	object *old_base=vs_base;
	int x;
	check_arg(2);
	x=
	mymonstartup(
	object_to_int(vs_base[0]),
	object_to_int(vs_base[1]));
	vs_top=(vs_base=old_base)+1;
	vs_base[0]=make_fixnum(x);
}
/*	function definition for MONITOR2	*/

static L3()
{	object *old_base=vs_base;
	int x;
	check_arg(4);
	x=
	mymonitor(
	object_to_int(vs_base[0]),
	object_to_int(vs_base[1]),
	object_to_int(vs_base[2]),
	object_to_int(vs_base[3]));
	vs_top=(vs_base=old_base)+1;
	vs_base[0]=make_fixnum(x);
}
/*	function definition for MONCONTROL	*/

static L4()
{	object *old_base=vs_base;
	int x;
	check_arg(1);
	x=
	moncontrol(
	object_to_int(vs_base[0]));
	vs_top=(vs_base=old_base)+1;
	vs_base[0]=make_fixnum(x);
}
/*	function definition for WRITE_OUTSYMS	*/

static L5()
{	object *old_base=vs_base;
	int x;
	check_arg(0);
	x=
	write_outsyms();
	vs_top=(vs_base=old_base)+1;
	vs_base[0]=make_fixnum(x);
}
static LnkT2(){ call_or_link(VV[2],&Lnk2);} /* WRITE_OUTSYMS */
static LnkT1(){ call_or_link(VV[1],&Lnk1);} /* SET-UP-COMBINED */
static LnkT0(){ call_or_link(VV[0],&Lnk0);} /* MONITOR2 */
