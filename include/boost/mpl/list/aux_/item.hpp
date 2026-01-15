
#ifndef BOOST_MPL_LIST_AUX_NODE_HPP_INCLUDED
#define BOOST_MPL_LIST_AUX_NODE_HPP_INCLUDED

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

#include <boost/mpl/long.hpp>
#include <boost/mpl/list/aux_/tag.hpp>
#include <boost/mpl/aux_/config/msvc.hpp>
#include <boost/mpl/aux_/config/workaround.hpp>

namespace boost { namespace mpl {

template<
      typename Size
    , typename T
    , typename Next
    >
struct l_item
{
// agurt, 17/jul/03: to facilitate the deficient 'is_sequence' implementation 
#if BOOST_WORKAROUND(BOOST_MSVC, <= 1300)
    typedef int begin;
#endif
    using tag = aux::list_tag;
    using type = l_item;

    using size = Size;
    using item = T;
    using next = Next;
};

struct l_end
{
#if BOOST_WORKAROUND(BOOST_MSVC, <= 1300)
    typedef int begin;
#endif
    using tag = aux::list_tag;
    using type = l_end;
    using size = long_<0>;
};

}}

#endif // BOOST_MPL_LIST_AUX_NODE_HPP_INCLUDED
