
#include <cmpinclude.h>
#include "littleXlsp.h"
init_littleXlsp(){do_init(VV);}
/*	function definition for OPEN-WINDOW	*/

static L1()
{	object *old_base=vs_base;
	int x;
	check_arg(0);
	x=
	open_window();
	vs_top=(vs_base=old_base)+1;
	vs_base[0]=make_fixnum(x);
}
/*	function definition for CLOSE-WINDOW	*/

static L2()
{	object *old_base=vs_base;
	int x;
	check_arg(1);
	x=
	close_window(
	object_to_int(vs_base[0]));
	vs_top=(vs_base=old_base)+1;
	vs_base[0]=make_fixnum(x);
}
/*	function definition for CLEAR-WINDOW	*/

static L3()
{	object *old_base=vs_base;
	int x;
	check_arg(1);
	x=
	clear_window(
	object_to_int(vs_base[0]));
	vs_top=(vs_base=old_base)+1;
	vs_base[0]=make_fixnum(x);
}
/*	function definition for DRAW-LINE	*/

static L4()
{	object *old_base=vs_base;
	int x;
	check_arg(5);
	x=
	draw_line(
	object_to_int(vs_base[0]),
	object_to_int(vs_base[1]),
	object_to_int(vs_base[2]),
	object_to_int(vs_base[3]),
	object_to_int(vs_base[4]));
	vs_top=(vs_base=old_base)+1;
	vs_base[0]=make_fixnum(x);
}
/*	function definition for ERASE-LINE	*/

static L5()
{	object *old_base=vs_base;
	int x;
	check_arg(5);
	x=
	erase_line(
	object_to_int(vs_base[0]),
	object_to_int(vs_base[1]),
	object_to_int(vs_base[2]),
	object_to_int(vs_base[3]),
	object_to_int(vs_base[4]));
	vs_top=(vs_base=old_base)+1;
	vs_base[0]=make_fixnum(x);
}
/*	function definition for DRAW-ARC	*/

static L6()
{	object *old_base=vs_base;
	int x;
	check_arg(7);
	x=
	draw_arc(
	object_to_int(vs_base[0]),
	object_to_int(vs_base[1]),
	object_to_int(vs_base[2]),
	object_to_int(vs_base[3]),
	object_to_int(vs_base[4]),
	object_to_int(vs_base[5]),
	object_to_int(vs_base[6]));
	vs_top=(vs_base=old_base)+1;
	vs_base[0]=make_fixnum(x);
}
/*	function definition for CLEAR-ARC	*/

static L7()
{	object *old_base=vs_base;
	int x;
	check_arg(7);
	x=
	clear_arc(
	object_to_int(vs_base[0]),
	object_to_int(vs_base[1]),
	object_to_int(vs_base[2]),
	object_to_int(vs_base[3]),
	object_to_int(vs_base[4]),
	object_to_int(vs_base[5]),
	object_to_int(vs_base[6]));
	vs_top=(vs_base=old_base)+1;
	vs_base[0]=make_fixnum(x);
}
/*	function definition for FILL-ARC	*/

static L8()
{	object *old_base=vs_base;
	int x;
	check_arg(7);
	x=
	fill_arc(
	object_to_int(vs_base[0]),
	object_to_int(vs_base[1]),
	object_to_int(vs_base[2]),
	object_to_int(vs_base[3]),
	object_to_int(vs_base[4]),
	object_to_int(vs_base[5]),
	object_to_int(vs_base[6]));
	vs_top=(vs_base=old_base)+1;
	vs_base[0]=make_fixnum(x);
}
/*	function definition for RESIZE-WINDOW	*/

static L9()
{	object *old_base=vs_base;
	int x;
	check_arg(3);
	x=
	resize_window(
	object_to_int(vs_base[0]),
	object_to_int(vs_base[1]),
	object_to_int(vs_base[2]));
	vs_top=(vs_base=old_base)+1;
	vs_base[0]=make_fixnum(x);
}
/*	function definition for RAISE-WINDOW	*/

static L10()
{	object *old_base=vs_base;
	int x;
	check_arg(1);
	x=
	raise_window(
	object_to_int(vs_base[0]));
	vs_top=(vs_base=old_base)+1;
	vs_base[0]=make_fixnum(x);
}
/*	function definition for DRAW-TEXT-2	*/

static L11()
{	object *old_base=vs_base;
	int x;
	check_arg(4);
	x=
	draw_text(
	object_to_int(vs_base[0]),
	vs_base[1],
	object_to_int(vs_base[2]),
	object_to_int(vs_base[3]));
	vs_top=(vs_base=old_base)+1;
	vs_base[0]=make_fixnum(x);
}
/*	function definition for DRAW-TEXT	*/

static L12()
{register object *base=vs_base;
	register object *sup=base+VM1; VC1
	vs_reserve(VM1);
	{object V1;
	object V2;
	object V3;
	object V4;
	check_arg(4);
	V1=(base[0]);
	V2=(base[1]);
	V3=(base[2]);
	V4=(base[3]);
	vs_top=sup;
TTL:;
	base[4]= (V1);
	base[6]= (V2);
	vs_top=(vs_base=base+6)+1;
	(void) (*Lnk3)();
	vs_top=sup;
	base[5]= vs_base[0];
	base[6]= (V3);
	base[7]= (V4);
	vs_top=(vs_base=base+4)+4;
	(void) (*Lnk4)();
	return;
	}
}
/*	function definition for CLEAR-TEXT-2	*/

static L13()
{	object *old_base=vs_base;
	int x;
	check_arg(4);
	x=
	erase_text(
	object_to_int(vs_base[0]),
	vs_base[1],
	object_to_int(vs_base[2]),
	object_to_int(vs_base[3]));
	vs_top=(vs_base=old_base)+1;
	vs_base[0]=make_fixnum(x);
}
/*	function definition for CLEAR-TEXT	*/

static L14()
{register object *base=vs_base;
	register object *sup=base+VM2; VC2
	vs_reserve(VM2);
	{object V5;
	object V6;
	object V7;
	object V8;
	check_arg(4);
	V5=(base[0]);
	V6=(base[1]);
	V7=(base[2]);
	V8=(base[3]);
	vs_top=sup;
TTL:;
	base[4]= (V5);
	base[6]= (V6);
	vs_top=(vs_base=base+6)+1;
	(void) (*Lnk3)();
	vs_top=sup;
	base[5]= vs_base[0];
	base[6]= (V7);
	base[7]= (V8);
	vs_top=(vs_base=base+4)+4;
	(void) (*Lnk5)();
	return;
	}
}
/*	function definition for SET-ARC-MODE-2	*/

static L15()
{	object *old_base=vs_base;
	int x;
	check_arg(1);
	x=
	set_arc_mode(
	object_to_int(vs_base[0]));
	vs_top=(vs_base=old_base)+1;
	vs_base[0]=make_fixnum(x);
}
/*	function definition for SET-ARC-MODE	*/

static L16()
{register object *base=vs_base;
	register object *sup=base+VM3; VC3
	vs_reserve(VM3);
	{object V9;
	check_arg(1);
	V9=(base[0]);
	vs_top=sup;
TTL:;
	if(!((V9)==VV[0])){
	goto T12;}
	base[1]= small_fixnum(1);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk6)();
	return;
T12:;
	base[1]= small_fixnum(0);
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk6)();
	return;
	}
}
/*	function definition for USE-FONT-2	*/

static L17()
{	object *old_base=vs_base;
	int x;
	check_arg(1);
	x=
	use_font(
	vs_base[0]);
	vs_top=(vs_base=old_base)+1;
	vs_base[0]=make_fixnum(x);
}
/*	function definition for USE-FONT	*/

static L18()
{register object *base=vs_base;
	register object *sup=base+VM4; VC4
	vs_reserve(VM4);
	{object V10;
	check_arg(1);
	V10=(base[0]);
	vs_top=sup;
TTL:;
	base[2]= (V10);
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk3)();
	vs_top=sup;
	base[1]= vs_base[0];
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk7)();
	return;
	}
}
/*	function definition for SET-BACKGROUND-2	*/

static L19()
{	object *old_base=vs_base;
	int x;
	check_arg(2);
	x=
	set_background(
	object_to_int(vs_base[0]),
	vs_base[1]);
	vs_top=(vs_base=old_base)+1;
	vs_base[0]=make_fixnum(x);
}
/*	function definition for SET-BACKGROUND	*/

static L20()
{register object *base=vs_base;
	register object *sup=base+VM5; VC5
	vs_reserve(VM5);
	{object V11;
	object V12;
	check_arg(2);
	V11=(base[0]);
	V12=(base[1]);
	vs_top=sup;
TTL:;
	base[2]= (V11);
	base[4]= (V12);
	vs_top=(vs_base=base+4)+1;
	(void) (*Lnk3)();
	vs_top=sup;
	base[3]= vs_base[0];
	vs_top=(vs_base=base+2)+2;
	(void) (*Lnk8)();
	return;
	}
}
/*	function definition for SET-FOREGROUND-2	*/

static L21()
{	object *old_base=vs_base;
	int x;
	check_arg(1);
	x=
	set_foreground(
	vs_base[0]);
	vs_top=(vs_base=old_base)+1;
	vs_base[0]=make_fixnum(x);
}
/*	function definition for SET-FOREGROUND	*/

static L22()
{register object *base=vs_base;
	register object *sup=base+VM6; VC6
	vs_reserve(VM6);
	{object V13;
	check_arg(1);
	V13=(base[0]);
	vs_top=sup;
TTL:;
	base[2]= (V13);
	vs_top=(vs_base=base+2)+1;
	(void) (*Lnk3)();
	vs_top=sup;
	base[1]= vs_base[0];
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk9)();
	return;
	}
}
/*	C function defined by DEFCFUN	*/

object get_c_string(s) object s;
{
object *vs=vs_top;
object *old_top=vs_top+0;
{
 return(s->st.st_self);
}
vs_top=vs;
}
/*	function definition for GET_C_STRING_2	*/

static L23()
{	object *old_base=vs_base;
	object x;
	check_arg(1);
	x=
	get_c_string(
	vs_base[0]);
	vs_top=(vs_base=old_base)+1;
	vs_base[0]=x;
}
/*	function definition for GET-C-STRING	*/

static L24()
{register object *base=vs_base;
	register object *sup=base+VM7; VC7
	vs_reserve(VM7);
	{object V14;
	check_arg(1);
	V14=(base[0]);
	vs_top=sup;
TTL:;
	base[1]= (VFUN_NARGS=3,(*(LnkLI10))(VV[1],(V14),VV[2]));
	vs_top=(vs_base=base+1)+1;
	(void) (*Lnk11)();
	return;
	}
}
static LnkT11(){ call_or_link(VV[11],&Lnk11);} /* GET_C_STRING_2 */
static object  LnkTLI10(va_alist)va_dcl{va_list ap;va_start(ap);return(object )call_vproc(VV[10],&LnkLI10,ap);} /* CONCATENATE */
static LnkT9(){ call_or_link(VV[9],&Lnk9);} /* SET-FOREGROUND-2 */
static LnkT8(){ call_or_link(VV[8],&Lnk8);} /* SET-BACKGROUND-2 */
static LnkT7(){ call_or_link(VV[7],&Lnk7);} /* USE-FONT-2 */
static LnkT6(){ call_or_link(VV[6],&Lnk6);} /* SET-ARC-MODE-2 */
static LnkT5(){ call_or_link(VV[5],&Lnk5);} /* CLEAR-TEXT-2 */
static LnkT4(){ call_or_link(VV[4],&Lnk4);} /* DRAW-TEXT-2 */
static LnkT3(){ call_or_link(VV[3],&Lnk3);} /* GET-C-STRING */
