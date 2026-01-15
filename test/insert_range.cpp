
// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <boost/mpl/insert_range.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/set.hpp>
#include <boost/mpl/set_c.hpp>
#include <boost/mpl/map.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/range_c.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/logical.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/joint_view.hpp>

#include <boost/mpl/aux_/test.hpp>

MPL_TEST_CASE()
{
    using numbers = vector_c<int,0,1,7,8,9>;
    using pos = find< numbers,integral_c<int,7> >::type;
    using range = insert_range< numbers,pos,range_c<int,2,7> >::type;

    MPL_ASSERT_RELATION( size<range>::value, ==, 10 );
    MPL_ASSERT(( equal< range,range_c<int,0,10> > ));

    using result2 = insert_range< list0<>,end< list0<> >::type,list1<int> >::type;
    MPL_ASSERT_RELATION( size<result2>::value, ==, 1 );
}

template<typename A, typename B>
void test_associative()
{
    using C = typename insert_range< A,typename end< A >::type,B >::type;

    MPL_ASSERT_RELATION( size<C>::value, <=, (size<A>::value + size<B>::value) );
    MPL_ASSERT(( fold< joint_view< A,B >,true_,and_< _1,contains< C,_2 > > > ));
}

MPL_TEST_CASE()
{
    using signed_integers = set3< short,int,long >;
    using unsigned_integers = set3< unsigned short,unsigned int,unsigned long >;
    test_associative<signed_integers, unsigned_integers>();

    using odds = set_c< int,1,3,5,7,9 >;
    using evens = set_c< int,0,2,4,6,8 >;
    test_associative<odds, evens>();

    using pointers = map2<
              pair< void,void* >
            , pair< int,int* >
            >;
    using pointers_to_const = map2<
              pair< void const,void const* >
            , pair< int const,int const* >
            >;
    test_associative<pointers, pointers_to_const>();
}
