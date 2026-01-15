
// Copyright Aleksey Gurtovoy 2000-2005
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <boost/mpl/vector.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/mpl/equal.hpp>
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
    using v0 = vector0<>;
    using v1 = vector1<char>;
    using v2 = vector2<char,long>;
    using v9 = vector9<char,char,char,char,char,char,char,char,int>;

    MPL_ASSERT(( equal< v0,v0::type > ));
    MPL_ASSERT(( equal< v1,v1::type > ));
    MPL_ASSERT(( equal< v2,v2::type > ));
    MPL_ASSERT(( equal< v9,v9::type > ));

    MPL_ASSERT_RELATION( size<v0>::value, ==, 0 );
    MPL_ASSERT_RELATION( size<v1>::value, ==, 1 );
    MPL_ASSERT_RELATION( size<v2>::value, ==, 2 );
    MPL_ASSERT_RELATION( size<v9>::value, ==, 9 );

    MPL_ASSERT(( empty<v0> ));
    MPL_ASSERT_NOT(( empty<v1> ));
    MPL_ASSERT_NOT(( empty<v2> ));
    MPL_ASSERT_NOT(( empty<v9> ));

    MPL_ASSERT(( is_same< front<v1>::type,char > ));
    MPL_ASSERT(( is_same< back<v1>::type,char > ));
    MPL_ASSERT(( is_same< front<v2>::type,char > ));
    MPL_ASSERT(( is_same< back<v2>::type,long > ));
    MPL_ASSERT(( is_same< front<v9>::type,char > ));
    MPL_ASSERT(( is_same< back<v9>::type,int > ));
}


MPL_TEST_CASE()
{
    using v2 = vector2<char,long>;
    
    using i1 = begin<v2>::type;
    using i2 = next<i1>::type;
    using i3 = next<i2>::type;
    
    MPL_ASSERT(( is_same<deref<i1>::type,char> ));
    MPL_ASSERT(( is_same<deref<i2>::type,long> ));
    MPL_ASSERT(( is_same< i3, end<v2>::type > ));
}

MPL_TEST_CASE()
{
    using v0 = vector0<>;

    using v1 = push_back<v0,int>::type;
    using v2 = push_front<v1,char>::type;
    using v3 = push_back<v2,long>::type;

    MPL_ASSERT(( is_same< back<v1>::type,int > ));
    MPL_ASSERT(( is_same< back<v2>::type,int > ));
    MPL_ASSERT(( is_same< front<v2>::type,char > ));
    MPL_ASSERT(( is_same< back<v3>::type,long > ));

    MPL_ASSERT(( equal< v1,v1::type > ));
    MPL_ASSERT(( equal< v2,v2::type > ));
    MPL_ASSERT(( equal< v3,v3::type > ));
}

MPL_TEST_CASE()
{
    using v9 = vector9<char,bool,char,char,char,char,bool,long,int>;

    using v8 = pop_back<v9>::type;
    using v7 = pop_front<v8>::type;

    MPL_ASSERT(( is_same< back<v9>::type,int > ));
    MPL_ASSERT(( is_same< back<v8>::type,long > ));
    MPL_ASSERT(( is_same< back<v7>::type,long > ));
    MPL_ASSERT(( is_same< front<v7>::type,bool > ));

    MPL_ASSERT(( equal< v9,v9::type > ));
    MPL_ASSERT(( equal< v8,v8::type > ));
    MPL_ASSERT(( equal< v7,v7::type > ));
}

MPL_TEST_CASE()
{
    using v0 = vector<>;
    using v1 = vector<char>;
    using v2 = vector<char,long>;
    using v9 = vector<char,char,char,char,char,char,char,char,int>;

    MPL_ASSERT(( equal< v0,v0::type > ));
    MPL_ASSERT(( equal< v1,v1::type > ));
    MPL_ASSERT(( equal< v2,v2::type > ));
    MPL_ASSERT(( equal< v9,v9::type > ));

    MPL_ASSERT_RELATION( size<v0>::value, ==, 0 );
    MPL_ASSERT_RELATION( size<v1>::value, ==, 1 );
    MPL_ASSERT_RELATION( size<v2>::value, ==, 2 );
    MPL_ASSERT_RELATION( size<v9>::value, ==, 9 );
}
