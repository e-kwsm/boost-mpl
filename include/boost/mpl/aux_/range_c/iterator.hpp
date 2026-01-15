
#ifndef BOOST_MPL_AUX_RANGE_C_ITERATOR_HPP_INCLUDED
#define BOOST_MPL_AUX_RANGE_C_ITERATOR_HPP_INCLUDED

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

#include <boost/mpl/iterator_tags.hpp>
#include <boost/mpl/advance_fwd.hpp>
#include <boost/mpl/distance_fwd.hpp>
#include <boost/mpl/next_prior.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/aux_/value_wknd.hpp>
#include <boost/mpl/aux_/config/ctps.hpp>

namespace boost { namespace mpl {

// theoretically will work on any discrete numeric type
template< typename N > struct r_iter
{
    using tag = aux::r_iter_tag;
    using category = random_access_iterator_tag;
    using type = N;

#if defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
    typedef r_iter< typename mpl::next<N>::type > next;
    typedef r_iter< typename mpl::prior<N>::type > prior;
#endif
};

#if !defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template<
      typename N
    >
struct next< r_iter<N> >
{
    using type = r_iter< typename mpl::next<N>::type >;
};

template<
      typename N
    >
struct prior< r_iter<N> >
{
    using type = r_iter< typename mpl::prior<N>::type >;
};

#endif


template<> struct advance_impl<aux::r_iter_tag>
{
    template< typename Iter, typename Dist > struct apply
    {
        using n_ = typename deref<Iter>::type;
#if BOOST_WORKAROUND(BOOST_MSVC, <= 1300)
        typedef typename plus_impl<integral_c_tag,integral_c_tag>
            ::template apply<n_,Dist>::type m_;
#else
        using m_ = typename plus<n_,Dist>::type;
#endif
        // agurt, 10/nov/04: to be generic, the code have to do something along
        // the lines below...
        //
        // typedef typename apply_wrap1<
        //       numeric_cast< typename m_::tag, typename n_::tag >
        //     , m_
        //     >::type result_;
        //
        // ... meanwhile:
        
        using result_ = integral_c< 
              typename aux::value_type_wknd<n_>::type
            , BOOST_MPL_AUX_VALUE_WKND(m_)::value 
            >;
        
        using type = r_iter<result_>;
    };
};

template<> struct distance_impl<aux::r_iter_tag>
{
    template< typename Iter1, typename Iter2 > struct apply
        : minus<
              typename Iter2::type
            , typename Iter1::type
            >
    {
    };
};

}}

#endif // BOOST_MPL_AUX_RANGE_C_ITERATOR_HPP_INCLUDED
