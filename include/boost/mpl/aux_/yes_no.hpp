
#ifndef BOOST_MPL_AUX_YES_NO_HPP_INCLUDED
#define BOOST_MPL_AUX_YES_NO_HPP_INCLUDED

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

#include <boost/mpl/aux_/nttp_decl.hpp>
#include <boost/mpl/aux_/config/arrays.hpp>
#include <boost/mpl/aux_/config/msvc.hpp>
#include <boost/mpl/aux_/config/workaround.hpp>
#include <cstddef>


namespace boost { namespace mpl { namespace aux {

using no_tag = char(&)[1];
using yes_tag = char(&)[2];

template< bool C_ > struct yes_no_tag
{
    using type = no_tag;
};

template<> struct yes_no_tag<true>
{
    using type = yes_tag;
};


template< BOOST_MPL_AUX_NTTP_DECL(std::size_t, n) > struct weighted_tag
{
#if !BOOST_WORKAROUND(BOOST_MSVC, < 1300)
    using type = char(&)[n];
#else
    char buf[n];
    typedef weighted_tag type;
#endif
};

#if defined(BOOST_MPL_CFG_NO_DEPENDENT_ARRAY_TYPES)
template<> struct weighted_tag<0>
{
    typedef char (&type)[1];
};
#endif

}}}

#endif // BOOST_MPL_AUX_YES_NO_HPP_INCLUDED
