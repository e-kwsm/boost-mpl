
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

#include <boost/mpl/deque.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/pop_back.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/empty.hpp>

#include <boost/mpl/aux_/test.hpp>


MPL_TEST_CASE()
{
    using d0 = deque<>;
    using d1 = deque<char>;
    using d2 = deque<char,long>;
    using d9 = deque<char,char,char,char,char,char,char,char,int>;

    MPL_ASSERT_RELATION( size<d0>::value, ==, 0 );
    MPL_ASSERT_RELATION( size<d1>::value, ==, 1 );
    MPL_ASSERT_RELATION( size<d2>::value, ==, 2 );
    MPL_ASSERT_RELATION( size<d9>::value, ==, 9 );

    MPL_ASSERT(( empty<d0> ));
    MPL_ASSERT_NOT(( empty<d1> ));
    MPL_ASSERT_NOT(( empty<d2> ));
    MPL_ASSERT_NOT(( empty<d9> ));

    MPL_ASSERT(( is_same< front<d1>::type,char > ));
    MPL_ASSERT(( is_same< back<d1>::type,char > ));
    MPL_ASSERT(( is_same< front<d2>::type,char > ));
    MPL_ASSERT(( is_same< back<d2>::type,long > ));
    MPL_ASSERT(( is_same< front<d9>::type,char > ));
    MPL_ASSERT(( is_same< back<d9>::type,int > ));
}


MPL_TEST_CASE()
{
    using d2 = deque<char,long>;
    
    using i1 = begin<d2>::type;
    using i2 = next<i1>::type;
    using i3 = next<i2>::type;
    
    MPL_ASSERT(( is_same<deref<i1>::type,char> ));
    MPL_ASSERT(( is_same<deref<i2>::type,long> ));
    MPL_ASSERT(( is_same< i3, end<d2>::type > ));
}

MPL_TEST_CASE()
{
    using d0 = deque<>;

    using d1 = push_back<d0,int>::type;
    MPL_ASSERT(( is_same< back<d1>::type,int > ));

    using d2 = push_front<d1,char>::type;
    MPL_ASSERT(( is_same< back<d2>::type,int > ));
    MPL_ASSERT(( is_same< front<d2>::type,char > ));

    using d3 = push_back<d2,long>::type;
    MPL_ASSERT(( is_same< back<d3>::type,long > ));
}

MPL_TEST_CASE()
{
    using d0 = deque<>;
    using d1 = deque<char>;
    using d2 = deque<char,long>;
    using d9 = deque<char,char,char,char,char,char,char,char,int>;

    MPL_ASSERT_RELATION( size<d0>::value, ==, 0 );
    MPL_ASSERT_RELATION( size<d1>::value, ==, 1 );
    MPL_ASSERT_RELATION( size<d2>::value, ==, 2 );
    MPL_ASSERT_RELATION( size<d9>::value, ==, 9 );
}
