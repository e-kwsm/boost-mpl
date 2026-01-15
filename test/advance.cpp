
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

#include <boost/mpl/advance.hpp>
#include <boost/mpl/iterator_tags.hpp>
#include <boost/mpl/aux_/test.hpp>

template< int pos > struct iter
{
    using category = mpl::bidirectional_iterator_tag;
    using next = iter<(pos + 1)>;
    using prior = iter<(pos - 1)>;
    using type = int_<pos>;
};

#if BOOST_WORKAROUND(__MWERKS__, BOOST_TESTED_AT(0x3003))
namespace boost { namespace mpl {
template< int pos, typename Default > struct tag< iter<pos>,Default > : void_ {};
}}
#endif

using first = iter<0>;
using last = iter<10>;

MPL_TEST_CASE()
{
    using iter1 = mpl::advance<first,int_<10> >::type;
    using iter2 = advance_c<first,10>::type;

    MPL_ASSERT(( is_same<iter1, last> ));
    MPL_ASSERT(( is_same<iter2, last> ));
}

MPL_TEST_CASE()
{
    using iter1 = mpl::advance<last,int_<-10> >::type;
    using iter2 = advance_c<last,-10>::type;

    MPL_ASSERT(( is_same<iter1, first> ));
    MPL_ASSERT(( is_same<iter2, first> ));
}
