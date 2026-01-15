
#ifndef BOOST_MPL_FILTER_VIEW_HPP_INCLUDED
#define BOOST_MPL_FILTER_VIEW_HPP_INCLUDED

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
#include <boost/mpl/aux_/filter_iter.hpp>
#include <boost/mpl/aux_/na_spec.hpp>

namespace boost { namespace mpl {

template<
      typename BOOST_MPL_AUX_NA_PARAM(Sequence)
    , typename BOOST_MPL_AUX_NA_PARAM(Predicate)
    >
struct filter_view
{
 private:    
    using pred_ = typename lambda<Predicate>::type;
    using first_ = typename begin<Sequence>::type;
    using last_ = typename end<Sequence>::type;

 public:
    struct tag;
    using type = filter_view;
    using begin = typename aux::next_filter_iter< first_,last_,pred_ >::type;
    using end = aux::filter_iter< last_,last_,pred_ >;
};

BOOST_MPL_AUX_NA_SPEC(2, filter_view)

}}

#endif // BOOST_MPL_FILTER_VIEW_HPP_INCLUDED
