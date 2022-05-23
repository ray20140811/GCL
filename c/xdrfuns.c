
#ifdef HAVE_XDR

#ifdef AIX3
#include <sys/select.h>
#endif
#include <rpc/rpc.h>

extern short aet_sizes[];
object
siGxdr_open(f)
     object f;
{ XDR *xdrs;
  object ar= alloc_simple_string(sizeof(XDR));
  array_allocself(ar,1,0);
  xdrs= (XDR *) ar->a.a_self;
  if (f->sm.sm_fp == 0) FEerror("stream not ok for xdr io");
  xdrstdio_create(xdrs, f->sm.sm_fp,
		  (f->sm.sm_mode == smm_input ?  XDR_DECODE :
		   f->sm.sm_mode == smm_output ?  XDR_ENCODE :
		   FEerror("stream not input or output")))
		   ;
  return ar;
}

object
siGxdr_write(str,elt)
     object str,elt;
{ XDR *xdrp= (XDR *) str->ust.ust_self;

  switch (type_of(elt))
   { case t_fixnum:
       if(!xdr_long(xdrp,&fix(elt))) goto error;
        return elt;
     case t_longfloat:
       if(!xdr_double(xdrp,&lf(elt))) goto error;
        return elt;
     case t_shortfloat:
       if(!xdr_float(xdrp,&sf(elt))) goto error;
        return elt;
     case t_vector:
       if(!xdr_array(xdrp,&elt->v.v_self,
		 &elt->v.v_fillp,
		 elt->v.v_dim,
		 aet_sizes[elt->v.v_elttype],
		 (elt->v.v_elttype == aet_lf ? xdr_double :
		  elt->v.v_elttype == aet_sf ? xdr_float :
		  elt->v.v_elttype == aet_fix ? xdr_int :
		  elt->v.v_elttype == aet_short ? xdr_short :
		  (FEerror("unsupported xdr size",0),xdr_short))))
	 goto error ;
       return elt;
     default:
       FEerror("unsupported xdr ~a",1,elt);
     }
  return elt;
 error:
  FEerror("bad xdr read");
     }

object
siGxdr_read(str,elt)
          object str,elt;
{ XDR *xdrp= (XDR *) str->ust.ust_self;
  switch (type_of(elt))
   { case t_fixnum:
       {int l;
	
       if(!xdr_long(xdrp,&l)) goto error;
	return make_fixnum(l);}
       break;
     case t_longfloat:
       { double x;
       if(!xdr_double(xdrp,&x)) goto error;
        return make_longfloat(x);}
     case t_shortfloat:
       { float x;
       if(!xdr_float(xdrp,&x)) goto error;
        return make_shortfloat(x);}
     case t_vector:
      if(! xdr_array(xdrp,&elt->v.v_self,
		 &elt->v.v_fillp,
		 elt->v.v_dim,
		 aet_sizes[elt->v.v_elttype],
		 (elt->v.v_elttype == aet_lf ? xdr_double :
		  elt->v.v_elttype == aet_sf ? xdr_float :
		  elt->v.v_elttype == aet_fix ? xdr_int :
		  elt->v.v_elttype == aet_short ? xdr_short :
		  (FEerror("unsupported xdr size",0),xdr_short))))
	goto error;
       return elt;
     default:
       FEerror("unsupported xdr ~a",1,elt);
     }
     error:
  FEerror("bad xdr read");
  return elt;
}

init_xdrfuns()
{ make_si_sfun("XDR-WRITE",siGxdr_write,
	       ARGTYPE2(f_object,f_object)|RESTYPE(f_object));

  make_si_sfun("XDR-READ",siGxdr_read,
	       ARGTYPE2(f_object,f_object)|RESTYPE(f_object));
  make_si_sfun("XDR-OPEN",siGxdr_open,
	       ARGTYPE1(f_object)|RESTYPE(f_object));
  
}
#else
init_xdrfuns(){;}
#endif     
