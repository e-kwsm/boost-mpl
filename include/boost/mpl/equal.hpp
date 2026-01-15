
#ifndef BOOST_MPL_EQUAL_HPP_INCLUDED
#define BOOST_MPL_EQUAL_HPP_INCLUDED

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

#include <boost/mpl/aux_/iter_fold_if_impl.hpp>
#include <boost/mpl/aux_/iter_apply.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/always.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/bind.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/void.hpp>
#include <boost/mpl/aux_/na_spec.hpp>
#include <boost/mpl/aux_/lambda_support.hpp>
#include <boost/mpl/aux_/msvc_eti_base.hpp>

#include <boost/type_traits/is_same.hpp>

namespace boost { namespace mpl {

namespace aux {

template<
      typename Predicate
    , typename LastIterator1
    , typename LastIterator2
    >
struct equal_pred
{
    template<
          typename Iterator2
        , typename Iterator1
        >
    struct apply
    {
        using type = typename and_< 
              not_< is_same<Iterator1,LastIterator1> >
            , not_< is_same<Iterator2,LastIterator2> >
            , aux::iter_apply2<Predicate,Iterator1,Iterator2>
            >::type;
    };
};

template<
      typename Sequence1
    , typename Sequence2
    , typename Predicate
    >
struct equal_impl
{
    using first1_ = typename begin<Sequence1>::type;
    using first2_ = typename begin<Sequence2>::type;
    using last1_ = typename end<Sequence1>::type;
    using last2_ = typename end<Sequence2>::type;

    using fold_ = aux::iter_fold_if_impl<
          first1_
        , first2_
        , next<>
        , protect< aux::equal_pred<Predicate,last1_,last2_> >
        , void_
        , always<false_>
        >;

    using iter1_ = typename fold_::iterator;
    using iter2_ = typename fold_::state;
    using result_ = and_<
          is_same<iter1_,last1_>
        , is_same<iter2_,last2_>
        >;

    using type = typename result_::type;
};


} // namespace aux


template<
      typename BOOST_MPL_AUX_NA_PARAM(Sequence1)
    , typename BOOST_MPL_AUX_NA_PARAM(Sequence2)
    , typename Predicate = is_same<_,_>
    >
struct equal
    : aux::msvc_eti_base< 
          typename aux::equal_impl<Sequence1,Sequence2,Predicate>::type
        >::type
{
    BOOST_MPL_AUX_LAMBDA_SUPPORT(2,equal,(Sequence1,Sequence2))
};

BOOST_MPL_AUX_NA_SPEC(2, equal)

}}

#endif // BOOST_MPL_EQUAL_HPP_INCLUDED
