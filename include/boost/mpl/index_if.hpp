
#ifndef BOOST_MPL_INDEX_IF_HPP_INCLUDED
#define BOOST_MPL_INDEX_IF_HPP_INCLUDED

// Copyright Eric Friedman 2003
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <boost/mpl/aux_/find_if_pred.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/iter_fold_if.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/void.hpp>
#include <boost/mpl/aux_/na_spec.hpp>
#include <boost/mpl/aux_/lambda_support.hpp>
#include <boost/type_traits/is_same.hpp>

namespace boost { namespace mpl {

template<
      typename BOOST_MPL_AUX_NA_PARAM(Sequence)
    , typename BOOST_MPL_AUX_NA_PARAM(Predicate)
    >
struct index_if
{
    using result_ = typename iter_fold_if<
          Sequence
        , int_<0>
        , next<>
        , aux::find_if_pred<Predicate>
        >::type;

    using not_found_ = typename end<Sequence>::type;
    using result_index_ = typename first<result_>::type;
    using result_iterator_ = typename second<result_>::type;

    using type = typename if_<
          is_same< result_iterator_,not_found_ >
        , void_
        , result_index_
        >::type;

    BOOST_MPL_AUX_LAMBDA_SUPPORT(2,index_if,(Sequence,Predicate))
};

BOOST_MPL_AUX_NA_SPEC(2, index_if)

}}

#endif // BOOST_MPL_INDEX_IF_HPP_INCLUDED
