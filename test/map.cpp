
// Copyright Aleksey Gurtovoy 2003-2004
// Copyright David Abrahams 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <boost/mpl/map.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/erase_key.hpp>
#include <boost/mpl/erase_key.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/clear.hpp>
#include <boost/mpl/has_key.hpp>
#include <boost/mpl/order.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/type_traits/is_same.hpp>

#include <boost/mpl/aux_/test.hpp>


MPL_TEST_CASE()
{
    using m_ = map2<
          mpl::pair<int,unsigned>
        , mpl::pair<char,unsigned char>
        >;

    using m = erase_key<m_,char>::type;

    MPL_ASSERT_RELATION( size<m>::type::value, ==, 1 );
    MPL_ASSERT_NOT(( empty<m> ));
    MPL_ASSERT(( is_same< clear<m>::type,map0<> > ));
    
    MPL_ASSERT(( is_same< at<m,int>::type,unsigned > ));
    MPL_ASSERT(( is_same< at<m,char>::type,void_ > ));
    MPL_ASSERT(( contains< m,mpl::pair<int,unsigned> > ));
    MPL_ASSERT_NOT(( contains< m,mpl::pair<int,int> > ));
    MPL_ASSERT_NOT(( contains< m,mpl::pair<char,unsigned char> > ));

    MPL_ASSERT_NOT(( has_key<m,char>::type ));
    MPL_ASSERT(( has_key<m,int>::type ));
    
    MPL_ASSERT_NOT(( is_same< order<m,int>::type, void_ > ));
    MPL_ASSERT(( is_same< order<m,char>::type,void_ > ));

    using first = begin<m>::type;
    using last = end<m>::type;

    MPL_ASSERT(( is_same< deref<first>::type,mpl::pair<int,unsigned> > ));
    MPL_ASSERT(( is_same< next<first>::type,last > ));

    using m2 = insert<m,mpl::pair<char,long> >::type;

    MPL_ASSERT_RELATION( size<m2>::type::value, ==, 2 );
    MPL_ASSERT_NOT(( empty<m2>::type ));
    MPL_ASSERT(( is_same< clear<m2>::type,map0<> > ));
    MPL_ASSERT(( is_same< at<m2,int>::type,unsigned > ));
    MPL_ASSERT(( is_same< at<m2,char>::type,long > ));

    MPL_ASSERT(( contains< m2,mpl::pair<int,unsigned> > ));
    MPL_ASSERT_NOT(( contains< m2,mpl::pair<int,int> > ));
    MPL_ASSERT_NOT(( contains< m2,mpl::pair<char,unsigned char> > ));
    MPL_ASSERT(( contains< m2,mpl::pair<char,long> > ));

    MPL_ASSERT(( has_key<m2,char>::type ));
    MPL_ASSERT_NOT(( has_key<m2,long>::type ));
    MPL_ASSERT_NOT(( is_same< order<m2,int>::type, void_ > ));
    MPL_ASSERT_NOT(( is_same< order<m2,char>::type, void_ > ));
    MPL_ASSERT_NOT(( is_same< order<m2,char>::type, order<m2,int>::type > ));

    using first2 = begin<m2>::type;
    using last2 = end<m2>::type;

    MPL_ASSERT(( is_same<deref<first2>::type,mpl::pair<int,unsigned> > ));
    using iter = next<first2>::type;
    MPL_ASSERT(( is_same<deref<iter>::type,mpl::pair<char,long> > ));
    MPL_ASSERT(( is_same< next<iter>::type,last2 > ));

    using s2_1 = insert<m2,mpl::pair<int,unsigned> >::type;
    MPL_ASSERT(( is_same<m2,s2_1> ));

    using m3 = insert<m2,mpl::pair<long,unsigned> >::type;
    MPL_ASSERT_RELATION( size<m3>::type::value, ==, 3 );
    MPL_ASSERT(( has_key<m3,long>::type ));
    MPL_ASSERT(( has_key<m3,int>::type ));
    MPL_ASSERT(( has_key<m3,char>::type ));
    MPL_ASSERT(( contains< m3,mpl::pair<long,unsigned> > ));
    MPL_ASSERT(( contains< m3,mpl::pair<int,unsigned> > ));

    using m1 = insert<m,mpl::pair<char,long> >::type;
    MPL_ASSERT_RELATION( size<m1>::type::value, ==, 2 );
    MPL_ASSERT(( is_same< at<m1,int>::type,unsigned > ));
    MPL_ASSERT(( is_same< at<m1,char>::type,long > ));

    MPL_ASSERT(( contains< m1,mpl::pair<int,unsigned> > ));
    MPL_ASSERT_NOT(( contains< m1,mpl::pair<int,int> > ));
    MPL_ASSERT_NOT(( contains< m1,mpl::pair<char,unsigned char> > ));
    MPL_ASSERT(( contains< m1,mpl::pair<char,long> > ));

    MPL_ASSERT(( is_same< m1,m2 > ));

    using m_1 = erase_key<m1,char>::type;
    MPL_ASSERT(( is_same<m,m_1> ));
    MPL_ASSERT_RELATION( size<m_1>::type::value, ==, 1 );
    MPL_ASSERT(( is_same< at<m_1,char>::type,void_ > ));
    MPL_ASSERT(( is_same< at<m_1,int>::type,unsigned > ));

    using m2_1 = erase_key<m3,char>::type;
    MPL_ASSERT_RELATION( size<m2_1>::type::value, ==, 2 );
    MPL_ASSERT(( is_same< at<m2_1,char>::type,void_ > ));
    MPL_ASSERT(( is_same< at<m2_1,int>::type,unsigned > ));
    MPL_ASSERT(( is_same< at<m2_1,long>::type,unsigned > ));
}

MPL_TEST_CASE()
{
    using m = map0<>;
    
    MPL_ASSERT_RELATION( size<m>::type::value, ==, 0 );
    MPL_ASSERT(( empty<m>::type ));

    MPL_ASSERT(( is_same< clear<m>::type,map0<> > ));
    MPL_ASSERT(( is_same< at<m,char>::type,void_ > ));

    MPL_ASSERT_NOT(( has_key<m,char>::type ));
    MPL_ASSERT_NOT(( has_key<m,int>::type ));
    MPL_ASSERT_NOT(( has_key<m,UDT>::type ));
    MPL_ASSERT_NOT(( has_key<m,incomplete>::type ));

    MPL_ASSERT_NOT(( has_key<m,char const>::type ));
    MPL_ASSERT_NOT(( has_key<m,int const>::type ));
    MPL_ASSERT_NOT(( has_key<m,UDT const>::type ));
    MPL_ASSERT_NOT(( has_key<m,incomplete const>::type ));

    MPL_ASSERT_NOT(( has_key<m,int*>::type ));
    MPL_ASSERT_NOT(( has_key<m,UDT*>::type ));
    MPL_ASSERT_NOT(( has_key<m,incomplete*>::type ));

    MPL_ASSERT_NOT(( has_key<m,int&>::type ));
    MPL_ASSERT_NOT(( has_key<m,UDT&>::type ));
    MPL_ASSERT_NOT(( has_key<m,incomplete&>::type ));

    using m1 = insert<m,mpl::pair<char,int> >::type;
    MPL_ASSERT_RELATION( size<m1>::type::value, ==, 1 );
    MPL_ASSERT(( is_same< at<m1,char>::type,int > ));

    using m0_1 = erase_key<m,char>::type;
    MPL_ASSERT_RELATION( size<m0_1>::type::value, ==, 0 );
    MPL_ASSERT(( is_same< at<m0_1,char>::type,void_ > ));
}

// Use a template for testing so that GCC will show us the actual types involved
template <class M>
void test()
{
    MPL_ASSERT_RELATION( size<M>::value, ==, 3 );

    using not_found = typename end<M>::type;
    BOOST_MPL_ASSERT_NOT(( is_same<BOOST_DEDUCED_TYPENAME find<M,mpl::pair<int,int*> >::type,not_found> ));
    BOOST_MPL_ASSERT_NOT(( is_same<BOOST_DEDUCED_TYPENAME find<M,mpl::pair<long,long*> >::type,not_found> ));
    BOOST_MPL_ASSERT_NOT(( is_same<BOOST_DEDUCED_TYPENAME find<M,mpl::pair<char,char*> >::type,not_found> ));
    BOOST_MPL_ASSERT(( is_same<BOOST_DEDUCED_TYPENAME find<M,int>::type,not_found> ));
};

MPL_TEST_CASE()
{
    using map_of_1_pair = map< mpl::pair<int,int*> >;
    using iter_to_1_pair = begin<map_of_1_pair>::type;
    
    BOOST_MPL_ASSERT((
        is_same<
             deref<iter_to_1_pair>::type
           , mpl::pair<int,int*>
        >
    ));
    
    using mymap = map<
        mpl::pair<int,int*>
      , mpl::pair<long,long*>
      , mpl::pair<char,char*>
    >;
    
    test<mymap>();
    test<mymap::type>();
}

MPL_TEST_CASE()
{
    using int_to_float_map = mpl::erase_key<
        mpl::map<
            mpl::pair<char, double>
          , mpl::pair<int, float>
        >
      , char
    >::type;

    using with_char_too = mpl::insert<
        int_to_float_map
      , mpl::pair<char, long>
    >::type;

    BOOST_MPL_ASSERT((
        boost::is_same<
            mpl::at<with_char_too, char>::type
          , long
        >
    ));
}

MPL_TEST_CASE()
{
    using little_map = insert< map<>, pair<int,int> >::type;

    MPL_ASSERT_RELATION(size<little_map>::value, ==, 1);
    MPL_ASSERT_RELATION(size<little_map::type>::value, ==, 1);
}

MPL_TEST_CASE()
{
    using little_map = erase_key< map< pair<float,float>, pair<int,int> >, float >::type;

    MPL_ASSERT_RELATION(size<little_map>::value, ==, 1);
    MPL_ASSERT_RELATION(size<little_map::type>::value, ==, 1);
}
