
#ifndef BOOST_MPL_TRANSFORM_VIEW_HPP_INCLUDED
#define BOOST_MPL_TRANSFORM_VIEW_HPP_INCLUDED

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

#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/aux_/transform_iter.hpp>
#include <boost/mpl/aux_/na_spec.hpp>

namespace boost { namespace mpl {

template<
      typename BOOST_MPL_AUX_NA_PARAM(Sequence)
    , typename BOOST_MPL_AUX_NA_PARAM(F)
    >
struct transform_view
{
 private:
    using f_ = typename lambda<F>::type;
    using first_ = typename begin<Sequence>::type;
    using last_ = typename end<Sequence>::type;
 
 public:
    struct tag;
    using type = transform_view;
    using begin = aux::transform_iter< first_,last_,f_ >;
    using end = aux::transform_iter< last_,last_,f_ >;
};

BOOST_MPL_AUX_NA_SPEC(2, transform_view)

}}

#endif // BOOST_MPL_TRANSFORM_VIEW_HPP_INCLUDED
