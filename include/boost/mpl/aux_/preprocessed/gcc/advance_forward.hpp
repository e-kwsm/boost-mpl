
// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//

// Preprocessed version of "boost/mpl/aux_/advance_forward.hpp" header
// -- DO NOT modify by hand!

namespace boost { namespace mpl { namespace aux {

template< long N > struct advance_forward;
template<>
struct advance_forward<0>
{
    template< typename Iterator > struct apply
    {
        using iter0 = Iterator;
        using type = iter0;
    };
};

template<>
struct advance_forward<1>
{
    template< typename Iterator > struct apply
    {
        using iter0 = Iterator;
        using iter1 = typename next<iter0>::type;
        using type = iter1;
    };
};

template<>
struct advance_forward<2>
{
    template< typename Iterator > struct apply
    {
        using iter0 = Iterator;
        using iter1 = typename next<iter0>::type;
        using iter2 = typename next<iter1>::type;
        using type = iter2;
    };
};

template<>
struct advance_forward<3>
{
    template< typename Iterator > struct apply
    {
        using iter0 = Iterator;
        using iter1 = typename next<iter0>::type;
        using iter2 = typename next<iter1>::type;
        using iter3 = typename next<iter2>::type;
        using type = iter3;
    };
};

template<>
struct advance_forward<4>
{
    template< typename Iterator > struct apply
    {
        using iter0 = Iterator;
        using iter1 = typename next<iter0>::type;
        using iter2 = typename next<iter1>::type;
        using iter3 = typename next<iter2>::type;
        using iter4 = typename next<iter3>::type;
        using type = iter4;
    };
};

template< long N >
struct advance_forward
{
    template< typename Iterator > struct apply
    {
        using chunk_result_ = typename apply_wrap1<
              advance_forward<4>
            , Iterator
            >::type;

        using type = typename apply_wrap1<
              advance_forward<(
                (N - 4) < 0
                    ? 0
                    : N - 4
                    )>
            , chunk_result_
            >::type;
    };
};

}}}

