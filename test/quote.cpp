
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

#include <boost/mpl/quote.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/mpl/aux_/test.hpp>

template< typename T > struct f1
{
    using type = T;
};

template<
      typename T1, typename T2, typename T3, typename T4, typename T5
    >
struct f5
{
#if !defined(BOOST_MPL_CFG_NO_IMPLICIT_METAFUNCTIONS)
    // no 'type' member!
#else
    typedef f5 type;
#endif
};

MPL_TEST_CASE()
{
    using t1 = quote1<f1>::apply<int>::type;
    using t5 = quote5<f5>::apply<char,short,int,long,float>::type;
    
    MPL_ASSERT(( boost::is_same< t1, int > ));
    MPL_ASSERT(( boost::is_same< t5, f5<char,short,int,long,float> > ));
}
