// -*- C++ -*-
/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v4.0.1
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       https://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     https://www.dre.vanderbilt.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_codegen.cpp:148

#ifndef _TAO_IDL_CETCDC_BYICSW_H_
#define _TAO_IDL_CETCDC_BYICSW_H_


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include <string>
#include <vector>

#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/UserException.h"
#include "tao/Basic_Types.h"
#include "tao/ORB_Constants.h"
#include "tao/Object.h"
#include "tao/String_Manager_T.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/VarOut_T.h"
#include "tao/Arg_Traits_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/Any_Insert_Policy_T.h"
#include "tao/Fixed_Size_Argument_T.h"
#include "tao/Var_Size_Argument_T.h"
#include "tao/Object_Argument_T.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/UB_String_Arguments.h"
#include /**/ "tao/Version.h"
#include /**/ "tao/Versioned_Namespace.h"

#if TAO_MAJOR_VERSION != 4 || TAO_MINOR_VERSION != 0 || TAO_MICRO_VERSION != 1
#error This file should be regenerated with TAO_IDL
#endif
// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_root/root_ch.cpp:155


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<typename T> class Narrow_Utils;
}
TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_exception/exception_ch.cpp:40



class  InvalidKey : public ::CORBA::UserException
{
public:

  InvalidKey ();
  InvalidKey (const InvalidKey &);
  ~InvalidKey () = default;

  InvalidKey &operator= (const InvalidKey &);

  static void _tao_any_destructor (void *);

  static InvalidKey *_downcast (::CORBA::Exception *);
  static const InvalidKey *_downcast (::CORBA::Exception const *);

  static ::CORBA::Exception *_alloc ();

  virtual ::CORBA::Exception *_tao_duplicate () const;

  virtual void _raise () const;

  virtual void _tao_encode (TAO_OutputCDR &cdr) const;
  virtual void _tao_decode (TAO_InputCDR &cdr);

  virtual ::CORBA::TypeCode_ptr _tao_type () const;
};
// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_typecode/typecode_decl.cpp:33

extern  ::CORBA::TypeCode_ptr const _tc_InvalidKey;
// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_interface.cpp:742



#if !defined (_CETCD__VAR_OUT_CH_)
#define _CETCD__VAR_OUT_CH_

class CEtcd;
using CEtcd_ptr = CEtcd*;
using CEtcd_var = TAO_Objref_Var_T<CEtcd>;
using CEtcd_out = TAO_Objref_Out_T<CEtcd>;

#endif /* end #if !defined */


// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:39



class  CEtcd
  : public virtual ::CORBA::Object
{
public:
  friend class TAO::Narrow_Utils<CEtcd>;
  // TAO_IDL - Generated from
  // /opt/ACE_wrappers/TAO/TAO_IDL/be/be_type.cpp:297

  using _ptr_type = CEtcd_ptr;
  using _var_type = CEtcd_var;
  using _out_type = CEtcd_out;

  static void _tao_any_destructor (void *);

  // The static operations.
  static CEtcd_ptr _duplicate (CEtcd_ptr obj);

  static void _tao_release (CEtcd_ptr obj);

  static CEtcd_ptr _narrow (::CORBA::Object_ptr obj);
  static CEtcd_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
  static CEtcd_ptr _nil ();

  virtual std::string id ();

  virtual ::CORBA::Boolean put (
    const std::string key,
    const std::string val);

  virtual std::string get (
    const std::string key);

  virtual void del (
    const std::string key);

  
  // TAO_IDL - Generated from
  // /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:135

  

  virtual ::CORBA::Boolean _is_a (const char *type_id);
  virtual const char* _interface_repository_id () const;
  virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);

protected:
  // Concrete interface only.
  CEtcd ();

  // Concrete non-local interface only.
  CEtcd (::IOP::IOR *ior, TAO_ORB_Core *orb_core);
  
  // Non-local interface only.
  CEtcd (
      TAO_Stub *objref,
      ::CORBA::Boolean _tao_collocated = false,
      TAO_Abstract_ServantBase *servant = nullptr,
      TAO_ORB_Core *orb_core = nullptr);

  virtual ~CEtcd () = default;

private:
  // Private and unimplemented for concrete interfaces.
  CEtcd (const CEtcd &) = delete;
  CEtcd (CEtcd &&) = delete;
  CEtcd &operator= (const CEtcd &) = delete;
  CEtcd &operator= (CEtcd &&) = delete;
};
// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_typecode/typecode_decl.cpp:33

extern  ::CORBA::TypeCode_ptr const _tc_CEtcd;
// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:64



TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{
  // TAO_IDL - Generated from
  // /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:142

  

#if !defined (_CETCD__ARG_TRAITS_)
#define _CETCD__ARG_TRAITS_

  template<>
  class  Arg_Traits< ::CEtcd>
    : public Object_Arg_Traits_T<
        ::CEtcd_ptr,
        ::CEtcd_var,
        ::CEtcd_out,
        TAO::Objref_Traits<CEtcd>,
        TAO::Any_Insert_Policy_Stream>
  {
  };

#endif /* end #if !defined */
}

TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_traits.cpp:58



TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_CETCD__TRAITS_)
#define _CETCD__TRAITS_

  template<>
  struct  Objref_Traits< ::CEtcd>
  {
    static ::CEtcd_ptr duplicate (::CEtcd_ptr p);
    static void release (::CEtcd_ptr p);
    static ::CEtcd_ptr nil ();
    static ::CORBA::Boolean marshal (const ::CEtcd_ptr p,TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_exception/any_op_ch.cpp:36


TAO_BEGIN_VERSIONED_NAMESPACE_DECL
namespace CORBA {



 void operator<<= (::CORBA::Any &, const InvalidKey &); // copying version
 void operator<<= (::CORBA::Any &, InvalidKey*); // noncopying version
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const InvalidKey *&);
}
TAO_END_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/any_op_ch.cpp:40




TAO_BEGIN_VERSIONED_NAMESPACE_DECL
namespace CORBA {

 void operator<<= (::CORBA::Any &, CEtcd_ptr); // copying
 void operator<<= (::CORBA::Any &, CEtcd_ptr *); // non-copying
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, CEtcd_ptr &);
}
TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_exception/cdr_op_ch.cpp:36


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const InvalidKey &);
 ::CORBA::Boolean operator>> (TAO_InputCDR &, InvalidKey &);

TAO_END_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/cdr_op_ch.cpp:40



TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const CEtcd_ptr );
 ::CORBA::Boolean operator>> (TAO_InputCDR &, CEtcd_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /opt/ACE_wrappers/TAO/TAO_IDL/be/be_codegen.cpp:1648

#if defined (__ACE_INLINE__)
#include "CEtcdC.inl"
#endif /* defined INLINE */

#endif /* ifndef */

