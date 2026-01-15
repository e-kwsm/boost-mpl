
#ifndef BOOST_MPL_PAIR_VIEW_HPP_INCLUDED
#define BOOST_MPL_PAIR_VIEW_HPP_INCLUDED

// Copyright David Abrahams 2003-2004
// Copyright Aleksey Gurtovoy 2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/iterator_category.hpp>
#include <boost/mpl/advance.hpp>
#include <boost/mpl/distance.hpp>
#include <boost/mpl/next_prior.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/min_max.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/iterator_tags.hpp>
#include <boost/mpl/aux_/config/ctps.hpp>
#include <boost/mpl/aux_/na_spec.hpp>

namespace boost { namespace mpl {

namespace aux {
struct pair_iter_tag;

#if defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template< typename Iter1, typename Iter2, typename Category >
struct pair_iter;

template< typename Category > struct prior_pair_iter
{
    template< typename Iter1, typename Iter2 > struct apply
    {
        typedef typename mpl::prior<Iter1>::type i1_;
        typedef typename mpl::prior<Iter2>::type i2_;
        typedef pair_iter<i1_,i2_,Category> type;
    };
};

template<> struct prior_pair_iter<forward_iterator_tag>
{
    template< typename Iter1, typename Iter2 > struct apply
    {
        typedef pair_iter<Iter1,Iter2,forward_iterator_tag> type;
    };
};

#endif
}

template< 
      typename Iter1
    , typename Iter2
    , typename Category
    >
struct pair_iter
{
    using tag = aux::pair_iter_tag;
    using category = Category;
    using first = Iter1;
    using second = Iter2;
    
#if defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
    typedef pair< 
          typename deref<Iter1>::type
        , typename deref<Iter2>::type
        > type;

    typedef typename mpl::next<Iter1>::type i1_;
    typedef typename mpl::next<Iter2>::type i2_;
    typedef pair_iter<i1_,i2_,Category> next;
    
    typedef apply_wrap2< aux::prior_pair_iter<Category>,Iter1,Iter2 >::type prior;
#endif
};


#if !defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template< typename Iter1, typename Iter2, typename C >
struct deref< pair_iter<Iter1,Iter2,C> >
{
    using type = pair< 
          typename deref<Iter1>::type
        , typename deref<Iter2>::type
        >;
};

template< typename Iter1, typename Iter2, typename C >
struct next< pair_iter<Iter1,Iter2,C> >
{
    using i1_ = typename mpl::next<Iter1>::type;
    using i2_ = typename mpl::next<Iter2>::type;
    using type = pair_iter<i1_,i2_,C>;
};

template< typename Iter1, typename Iter2, typename C >
struct prior< pair_iter<Iter1,Iter2,C> >
{
    using i1_ = typename mpl::prior<Iter1>::type;
    using i2_ = typename mpl::prior<Iter2>::type;
    using type = pair_iter<i1_,i2_,C>;
};

#endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION


template<> struct advance_impl<aux::pair_iter_tag>
{
    template< typename Iter, typename D > struct apply
    {
        using i1_ = typename mpl::advance< typename Iter::first,D >::type;
        using i2_ = typename mpl::advance< typename Iter::second,D >::type;
        using type = pair_iter<i1_,i2_,typename Iter::category>;
    };
};

template<> struct distance_impl<aux::pair_iter_tag>
{
    template< typename Iter1, typename Iter2 > struct apply
    {
        // agurt, 10/nov/04: MSVC 6.5 ICE-s on forwarding
        using type = typename mpl::distance<
              typename first<Iter1>::type
            , typename first<Iter2>::type
            >::type;
    };
};


template<
      typename BOOST_MPL_AUX_NA_PARAM(Sequence1)
    , typename BOOST_MPL_AUX_NA_PARAM(Sequence2)
    >
struct pair_view
{
    using tag = nested_begin_end_tag;

    using iter1_ = typename begin<Sequence1>::type;
    using iter2_ = typename begin<Sequence2>::type;
    using category_ = typename min<
          typename iterator_category<iter1_>::type
        , typename iterator_category<iter2_>::type
        >::type;
    
    using begin = pair_iter<iter1_,iter2_,category_>;
    
    using end = pair_iter<
          typename end<Sequence1>::type
        , typename end<Sequence2>::type
        , category_
        >;
};

BOOST_MPL_AUX_NA_SPEC(2, pair_view)

}}

#endif // BOOST_MPL_PAIR_VIEW_HPP_INCLUDED
