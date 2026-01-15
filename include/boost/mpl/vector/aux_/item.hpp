
#ifndef BOOST_MPL_VECTOR_AUX_ITEM_HPP_INCLUDED
#define BOOST_MPL_VECTOR_AUX_ITEM_HPP_INCLUDED

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
#include <boost/mpl/void.hpp>
#include <boost/mpl/next_prior.hpp>
#include <boost/mpl/aux_/type_wrapper.hpp>
#include <boost/mpl/aux_/config/typeof.hpp>
#include <boost/mpl/aux_/config/ctps.hpp>

namespace boost { namespace mpl {

#if defined(BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES)

template< 
      typename T
    , typename Base
    , int at_front = 0
    >
struct v_item
    : Base
{
    using index_ = typename Base::upper_bound_;
    using upper_bound_ = typename next<index_>::type;
    using size = typename next<typename Base::size>::type;
    using base = Base;
    using type = v_item;

    // agurt 10/sep/04: MWCW <= 9.3 workaround here and below; the compiler
    // breaks if using declaration comes _before_ the new overload
    static aux::type_wrapper<T> item_(index_);
    using Base::item_;
};

template<
      typename T
    , typename Base
    >
struct v_item<T,Base,1>
    : Base
{
    using index_ = typename prior<typename Base::lower_bound_>::type;
    using lower_bound_ = index_;
    using size = typename next<typename Base::size>::type;
    using base = Base;
    using type = v_item;

    static aux::type_wrapper<T> item_(index_);
    using Base::item_;
};

// "erasure" item
template< 
      typename Base
    , int at_front
    >
struct v_mask
    : Base
{
    using index_ = typename prior<typename Base::upper_bound_>::type;
    using upper_bound_ = index_;
    using size = typename prior<typename Base::size>::type;
    using base = Base;
    using type = v_mask;

    static aux::type_wrapper<void_> item_(index_);
    using Base::item_;
};

template< 
      typename Base
    >
struct v_mask<Base,1>
    : Base
{
    using index_ = typename Base::lower_bound_;
    using lower_bound_ = typename next<index_>::type;
    using size = typename prior<typename Base::size>::type;
    using base = Base;
    using type = v_mask;

    static aux::type_wrapper<void_> item_(index_);
    using Base::item_;
};

#endif // BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES

}}

#endif // BOOST_MPL_VECTOR_AUX_ITEM_HPP_INCLUDED
