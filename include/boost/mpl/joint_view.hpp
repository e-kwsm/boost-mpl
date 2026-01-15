
#ifndef BOOST_MPL_JOINT_VIEW_HPP_INCLUDED
#define BOOST_MPL_JOINT_VIEW_HPP_INCLUDED

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

#include <boost/mpl/aux_/joint_iter.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/size_fwd.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/aux_/na_spec.hpp>

namespace boost { namespace mpl {

namespace aux {
struct joint_view_tag;
}

template<>
struct size_impl< aux::joint_view_tag >
{
    template < typename JointView > struct apply
      : plus<
            size<typename JointView::sequence1_>
          , size<typename JointView::sequence2_>
          >
    {};
};

template<
      typename BOOST_MPL_AUX_NA_PARAM(Sequence1_)
    , typename BOOST_MPL_AUX_NA_PARAM(Sequence2_)
    >
struct joint_view
{
    using first1_ = typename mpl::begin<Sequence1_>::type;
    using last1_ = typename mpl::end<Sequence1_>::type;
    using first2_ = typename mpl::begin<Sequence2_>::type;
    using last2_ = typename mpl::end<Sequence2_>::type;

    // agurt, 25/may/03: for the 'size_traits' implementation above
    using sequence1_ = Sequence1_;
    using sequence2_ = Sequence2_;

    using type = joint_view;
    using tag = aux::joint_view_tag;
    using begin = joint_iter<first1_,last1_,first2_>;
    using end = joint_iter<last1_,last1_,last2_>;
};

BOOST_MPL_AUX_NA_SPEC(2, joint_view)

}}

#endif // BOOST_MPL_JOINT_VIEW_HPP_INCLUDED
