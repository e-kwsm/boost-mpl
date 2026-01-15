
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

#include <boost/mpl/inherit.hpp>
#include <boost/mpl/aux_/test.hpp>

struct her { using herself = her; };
struct my { using myself = my; };

MPL_TEST_CASE()
{
    MPL_ASSERT(( is_same<inherit<her>::type, her> ));

    using her_my1 = inherit<her,my>::type;
    MPL_ASSERT(( is_same<her_my1::herself, her> ));
    MPL_ASSERT(( is_same<her_my1::myself, my> ));
    
    using her1 = inherit<empty_base,her>::type;
    MPL_ASSERT(( is_same<her1, her> ));
    
    using her2 = inherit<empty_base,her,empty_base,empty_base>::type;
    MPL_ASSERT(( is_same<her2, her> ));

    using her_my2 = inherit<her,empty_base,my>::type;
    MPL_ASSERT(( is_same<her_my2::herself, her> ));
    MPL_ASSERT(( is_same<her_my2::myself, my> ));

    using empty = inherit<empty_base,empty_base>::type;
    MPL_ASSERT(( is_same<empty, empty_base> ));
}
