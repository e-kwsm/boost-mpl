
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

#include <boost/mpl/apply.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/aux_/test.hpp>


template< typename T > struct std_vector
{
#if defined(BOOST_MPL_CFG_NO_IMPLICIT_METAFUNCTIONS)
    typedef std_vector type;
    BOOST_MPL_AUX_LAMBDA_SUPPORT(1, std_vector, (T))
#endif
};


MPL_TEST_CASE()
{
    using plus1 = plus<int_<2>,int_<3> >;
    using plus2 = lambda<plus1>::type;
    MPL_ASSERT(( is_same< plus1,plus2 > ));

    using v = lambda<std_vector<int> >::type;
    MPL_ASSERT(( is_same< v,std_vector<int> > ));

    using make_vector = lambda<std_vector<_1> >::type;
    using v_int = apply_wrap1<make_vector,int>::type;
    MPL_ASSERT(( is_same< v_int,std_vector<int> > ));
}

MPL_TEST_CASE()
{
    using plus_fun = plus<_1,_2>;
    using res = apply2<plus_fun,int_<2>,int_<3> >::type;

    MPL_ASSERT_RELATION( res::value, ==, 5 );
}

MPL_TEST_CASE()
{
    using plus_fun = apply1<_1, plus<_1,_2> >::type;
    MPL_ASSERT(( is_same< plus_fun,plus<_1,_2> > ));

    using res = apply2<plus_fun,int_<2>,int_<3> >::type;
    MPL_ASSERT_RELATION( res::value, ==, 5 );
}

MPL_TEST_CASE()
{
    using make_lambda = lambda< lambda<_1> >::type;
    using v = apply_wrap1< make_lambda,std_vector<int> >::type;
    MPL_ASSERT(( is_same< v,std_vector<int> > ));

    using make_vector = apply_wrap1< make_lambda,std_vector<_1> >::type;
    using v_int = apply_wrap1< make_vector,int >::type;
    MPL_ASSERT(( is_same< v_int,std_vector<int> > ));
}

MPL_TEST_CASE()
{
    using v = apply1< _1, std_vector<int> >::type;
    MPL_ASSERT(( is_same< v,std_vector<int> > ));

    using v_lambda = apply1< _1, std_vector<_1> >::type;
    using v_int = apply1<v_lambda,int>::type;
    MPL_ASSERT(( is_same< v_int,std_vector<int> > ));
}

MPL_TEST_CASE()
{
    using v = apply1< lambda<_1>, std_vector<int> >::type;
    MPL_ASSERT(( is_same< v,std_vector<int> > ));

    using make_vector = apply1< lambda<_1>, std_vector<_1> >::type;
    using v_int = apply_wrap1< make_vector,int >::type;
    MPL_ASSERT(( is_same< v_int,std_vector<int> > ));
}

MPL_TEST_CASE()
{
    using plus_fun = apply1< lambda<_1>, plus<_1,_2> >::type;
    using res = apply_wrap2< plus_fun,int_<2>,int_<3> >::type;

    MPL_ASSERT_RELATION( res::value, ==, 5 );
}

MPL_TEST_CASE()
{
    using b1 = bind2<plus<>,_1,_1>;
    using b2 = lambda<b1>::type;
    MPL_ASSERT(( is_same< b1,b2 > ));
}

MPL_TEST_CASE()
{
#if !BOOST_WORKAROUND(__MWERKS__, BOOST_TESTED_AT(0x3003))
    using make_lambda = lambda< lambda< bind2<plus<>,_1,_1> > >::type;
    using res = apply_wrap1< make_lambda::type, int_<5> >::type;
    MPL_ASSERT_RELATION( res::value, ==, 10 );
#endif
}

MPL_TEST_CASE()
{
    using res = apply1< bind2<plus<>,_1,_1>, int_<5> >::type;
    MPL_ASSERT_RELATION( res::value, ==, 10 );
}

MPL_TEST_CASE()
{
    using plus_fun = apply1<_1, lambda<plus<_1,_2> > >::type;
    using res = apply_wrap2< plus_fun::type, int_<2>,int_<3> >::type;

    MPL_ASSERT_RELATION( res::value, ==, 5 );
}
