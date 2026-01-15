
#ifndef BOOST_MPL_AUX_SORT_IMPL_HPP_INCLUDED
#define BOOST_MPL_AUX_SORT_IMPL_HPP_INCLUDED

// Copyright Eric Friedman 2002-2003
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <boost/mpl/partition.hpp>
#include <boost/mpl/copy.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/back_inserter.hpp>
#include <boost/mpl/front_inserter.hpp>
#include <boost/mpl/iterator_range.hpp>
#include <boost/mpl/joint_view.hpp>
#include <boost/mpl/single_view.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/less.hpp>
#include <boost/mpl/aux_/na.hpp>

namespace boost { namespace mpl { namespace aux {

template< typename Seq, typename Pred >
struct quick_sort;

// agurt, 10/nov/04: for the sake of deficeint compilers 
template< typename Pred, typename Pivot >
struct quick_sort_pred
{
    template< typename T > struct apply
    {
        using type = typename apply2<Pred,T,Pivot>::type;
    };
};

template< 
      typename Seq
    , typename Pred
    >
struct quick_sort_impl
{
    using pivot = typename begin<Seq>::type;
    using partitioned = typename partition<
          iterator_range< 
              typename next<pivot>::type
            , typename end<Seq>::type
            >
        , protect< aux::quick_sort_pred< Pred, typename deref<pivot>::type > >
        , back_inserter< vector<> >
        , back_inserter< vector<> >
        >::type;

    using part1 = typename quick_sort< typename partitioned::first, Pred >::type;
    using part2 = typename quick_sort< typename partitioned::second, Pred >::type;

    using type = joint_view< 
              joint_view< part1, single_view< typename deref<pivot>::type > >
            , part2
            >;
};

template< 
      typename Seq
    , typename Pred
    >
struct quick_sort
    : eval_if<
          empty<Seq>
        , identity<Seq>
        , quick_sort_impl<Seq,Pred>
        >
{
};


template <
      typename Sequence
    , typename Pred
    , typename In
    >
struct sort_impl
{
    using result_ = typename quick_sort< 
          Sequence
        , typename if_na<Pred,less<> >::type
        >::type;
        
    using type = typename copy<result_,In>::type;
};

template <
      typename Sequence
    , typename Pred
    , typename In
    >
struct reverse_sort_impl
{
    using result_ = typename quick_sort< 
          Sequence
        , typename if_na<Pred,less<> >::type
        >::type;
        
    using type = typename reverse_copy<result_,In>::type;
};

}}}

#endif // BOOST_MPL_AUX_SORT_IMPL_HPP_INCLUDED
