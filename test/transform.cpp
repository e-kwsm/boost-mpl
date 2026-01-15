
// Copyright Aleksey Gurtovoy 2000-2004
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

#include <boost/mpl/transform.hpp>

#include <boost/mpl/list.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/aux_/test.hpp>
#include <boost/mpl/aux_/config/gcc.hpp>
#include <boost/mpl/aux_/config/workaround.hpp>

#include <boost/type_traits/add_pointer.hpp>


MPL_TEST_CASE()
{
    using types = list<char,short,int,long,float,double>;
    using pointers = list<char*,short*,int*,long*,float*,double*>;
    
    using result = transform1< types,add_pointer<_1> >::type;
    MPL_ASSERT(( equal<result,pointers> ));
}

MPL_TEST_CASE()
{
    using evens = list_c<long,0,2,4,6,8,10>;
    using primes = list_c<long,2,3,5,7,11,13>;
    using sums = list_c<long,2,5,9,13,19,23>;

    using result = transform2< evens, primes, plus<> >::type;
    MPL_ASSERT(( equal< result,sums,equal_to<_1,_2> > ));

#if !defined(BOOST_MPL_CFG_NO_HAS_XXX)
    using result2 = transform< evens, primes, plus<> >::type;
    MPL_ASSERT(( is_same<result2,result> ));
#endif
}
