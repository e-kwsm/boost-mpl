
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

#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/aux_/test.hpp>

MPL_TEST_CASE()
{
    using types1 = list<long>::type;
    using types2 = list<int,long>::type;
    using types3 = list<char,int,long>::type;

    using result1 = pop_front<types1>::type;
    using result2 = pop_front<types2>::type;
    using result3 = pop_front<types3>::type;
    
    MPL_ASSERT_RELATION( size<result1>::value, ==, 0 );
    MPL_ASSERT_RELATION( size<result2>::value, ==, 1 );
    MPL_ASSERT_RELATION( size<result3>::value, ==, 2 );
    
    MPL_ASSERT(( is_same< front<result2>::type, long > ));
    MPL_ASSERT(( is_same< front<result3>::type, int > ));
}
