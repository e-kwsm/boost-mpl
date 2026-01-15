
// Copyright Eric Friedman 2003
//
// Distributed under the Boost Software License,Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$


#include <boost/mpl/index_of.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/void.hpp>
#include <boost/mpl/aux_/test.hpp>

MPL_TEST_CASE()
{
    using types = list< int, double, float >::type;

    using index_of_int = index_of< types, int    >::type;
    using index_of_double = index_of< types, double >::type;
    using index_of_float = index_of< types, float  >::type;
    using index_of_char = index_of< types, char   >::type;

    MPL_ASSERT_RELATION( index_of_int::value, ==, 0 );
    MPL_ASSERT_RELATION( index_of_double::value, ==, 1 );
    MPL_ASSERT_RELATION( index_of_float::value, ==, 2 );

    MPL_ASSERT(( is_void_< index_of_char > ));
}
