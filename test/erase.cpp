
// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License,Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <boost/mpl/erase.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/aux_/test.hpp>

MPL_TEST_CASE()
{
    using types = list<int,char,long,short,char,long,double,long>;
    using iter = find<types,short>::type;
    
    using result = erase<types, iter>::type;
    MPL_ASSERT_RELATION( size<result>::value, ==, 7 );

    using result_iter = find<result,short>::type;
    MPL_ASSERT(( is_same< result_iter, end<result>::type > ));
}

MPL_TEST_CASE()
{
    using values = list_c<int,1,0,5,1,7,5,0,5>;
    using iter = find< values, integral_c<int,7> >::type;

    using result = erase<values, iter>::type;
    MPL_ASSERT_RELATION( size<result>::value, ==, 7 );

    using result_iter = find<result, integral_c<int,7> >::type;
    MPL_ASSERT(( is_same< result_iter, end<result>::type > ));
}
