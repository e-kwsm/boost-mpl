
#ifndef BOOST_MPL_ZIP_VIEW_HPP_INCLUDED
#define BOOST_MPL_ZIP_VIEW_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2010
// Copyright David Abrahams 2000-2002
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <boost/mpl/transform.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/iterator_tags.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/aux_/na_spec.hpp>

namespace boost { namespace mpl {

template< typename IteratorSeq >
struct zip_iterator
{
    using category = forward_iterator_tag;
    using type = typename transform1<
          IteratorSeq
        , deref<_1>
        >::type;

    using next = zip_iterator<
          typename transform1<
                IteratorSeq
              , mpl::next<_1>
            >::type
        >;
};

template<
      typename BOOST_MPL_AUX_NA_PARAM(Sequences)
    >
struct zip_view
{
 private:
    using first_ones_ = typename transform1< Sequences, mpl::begin<_1> >::type;
    using last_ones_ = typename transform1< Sequences, mpl::end<_1> >::type;
    
 public:
    using tag = nested_begin_end_tag;
    using type = zip_view;
    using begin = zip_iterator<first_ones_>;
    using end = zip_iterator<last_ones_>;
};

BOOST_MPL_AUX_NA_SPEC(1, zip_view)

}}

#endif // BOOST_MPL_ZIP_VIEW_HPP_INCLUDED
