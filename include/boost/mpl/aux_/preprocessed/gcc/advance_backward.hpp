
// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//

// Preprocessed version of "boost/mpl/aux_/advance_backward.hpp" header
// -- DO NOT modify by hand!

namespace boost { namespace mpl { namespace aux {

template< long N > struct advance_backward;
template<>
struct advance_backward<0>
{
    template< typename Iterator > struct apply
    {
        using iter0 = Iterator;
        using type = iter0;
    };
};

template<>
struct advance_backward<1>
{
    template< typename Iterator > struct apply
    {
        using iter0 = Iterator;
        using iter1 = typename prior<iter0>::type;
        using type = iter1;
    };
};

template<>
struct advance_backward<2>
{
    template< typename Iterator > struct apply
    {
        using iter0 = Iterator;
        using iter1 = typename prior<iter0>::type;
        using iter2 = typename prior<iter1>::type;
        using type = iter2;
    };
};

template<>
struct advance_backward<3>
{
    template< typename Iterator > struct apply
    {
        using iter0 = Iterator;
        using iter1 = typename prior<iter0>::type;
        using iter2 = typename prior<iter1>::type;
        using iter3 = typename prior<iter2>::type;
        using type = iter3;
    };
};

template<>
struct advance_backward<4>
{
    template< typename Iterator > struct apply
    {
        using iter0 = Iterator;
        using iter1 = typename prior<iter0>::type;
        using iter2 = typename prior<iter1>::type;
        using iter3 = typename prior<iter2>::type;
        using iter4 = typename prior<iter3>::type;
        using type = iter4;
    };
};

template< long N >
struct advance_backward
{
    template< typename Iterator > struct apply
    {
        using chunk_result_ = typename apply_wrap1<
              advance_backward<4>
            , Iterator
            >::type;

        using type = typename apply_wrap1<
              advance_backward<(
                (N - 4) < 0
                    ? 0
                    : N - 4
                    )>
            , chunk_result_
            >::type;
    };
};

}}}

