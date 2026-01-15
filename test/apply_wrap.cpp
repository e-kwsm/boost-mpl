
// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/limits/arity.hpp>
#include <boost/mpl/aux_/preprocessor/params.hpp>
#include <boost/mpl/aux_/preprocessor/enum.hpp>
#include <boost/mpl/aux_/test.hpp>

#include <boost/preprocessor/repeat.hpp>
#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/dec.hpp>
#include <boost/preprocessor/if.hpp>
#include <boost/preprocessor/cat.hpp>

#if !defined(BOOST_MPL_CFG_NO_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
#   define APPLY_0_FUNC_DEF(z_ignored,i) \
    struct f0 \
    { \
        template< typename T = int > struct apply { using type = char; }; \
    }; \
/**/
#else
#   define APPLY_0_FUNC_DEF(z_ignored,i) \
    struct f0 \
    { \
        template< typename T > struct apply { using type = char; }; \
    }; \
/**/
#endif

#define APPLY_N_FUNC_DEF(z,i) \
    struct first##i \
    { \
        template< BOOST_MPL_PP_PARAMS_Z(z, i, typename U) > \
        struct apply { using type = U1; }; \
    }; \
    \
    struct last##i \
    { \
        template< BOOST_MPL_PP_PARAMS_Z(z, i, typename U) > \
        struct apply { using type = BOOST_PP_CAT(U,i); }; \
    }; \
/**/

#define APPLY_FUNC_DEF(z, i, unused) \
    BOOST_PP_IF( \
          i \
        , APPLY_N_FUNC_DEF \
        , APPLY_0_FUNC_DEF \
        )(z,i) \
/**/

namespace { namespace test {

BOOST_PP_REPEAT(
      BOOST_MPL_LIMIT_METAFUNCTION_ARITY
    , APPLY_FUNC_DEF
    , unused
    )

struct g0 { struct apply { using type = char; }; };

}}

#define APPLY_0_TEST(z_ignored, i, apply_) \
    using t = apply_<test::f##i>::type; \
    { MPL_ASSERT(( boost::is_same<t, char> )); } \
/**/

#define APPLY_N_TEST(z, i, apply_) \
    using t1##i = apply_< \
          test::first##i \
        , char \
        BOOST_PP_COMMA_IF(BOOST_PP_DEC(i)) \
        BOOST_MPL_PP_ENUM_Z(z, BOOST_PP_DEC(i), int) \
        >::type; \
    \
    using t2##i = apply_< \
          test::last##i \
        , BOOST_MPL_PP_ENUM_Z(z, BOOST_PP_DEC(i), int) \
        BOOST_PP_COMMA_IF(BOOST_PP_DEC(i)) char \
        >::type; \
    { MPL_ASSERT(( boost::is_same<t1##i, char> )); } \
    { MPL_ASSERT(( boost::is_same<t2##i, char> )); } \
/**/

#define APPLY_TEST(z, i, unused) \
    BOOST_PP_IF( \
          i \
        , APPLY_N_TEST \
        , APPLY_0_TEST \
        )(z, i, BOOST_PP_CAT(apply_wrap,i)) \
/**/


MPL_TEST_CASE()
{
    BOOST_PP_REPEAT(
          BOOST_MPL_LIMIT_METAFUNCTION_ARITY
        , APPLY_TEST
        , unused
        )

#if !defined(BOOST_MPL_CFG_NO_HAS_APPLY)
    {
        using t = apply_wrap0<test::g0>::type;
        MPL_ASSERT(( boost::is_same<t, char> ));
    }
#endif
}
