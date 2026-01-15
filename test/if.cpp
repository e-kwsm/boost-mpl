
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

#include <boost/mpl/if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/aux_/test.hpp>

MPL_TEST_CASE()
{
    using t1 = if_<true_,char,long>::type;
    using t2 = if_c<true,char,long>::type;
    using t3 = if_<false_,char,long>::type;
    using t4 = if_c<false,char,long>::type;

    MPL_ASSERT(( is_same<t1, char> ));
    MPL_ASSERT(( is_same<t2, char> ));
    MPL_ASSERT(( is_same<t3, long> ));
    MPL_ASSERT(( is_same<t4, long> ));
}
