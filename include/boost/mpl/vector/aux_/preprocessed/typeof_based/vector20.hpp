
// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//

// Preprocessed version of "boost/mpl/vector/vector20.hpp" header
// -- DO NOT modify by hand!

namespace boost { namespace mpl {

template<
      typename T0, typename T1, typename T2, typename T3, typename T4
    , typename T5, typename T6, typename T7, typename T8, typename T9
    , typename T10
    >
struct vector11
    : v_item<
          T10
        , vector10< T0,T1,T2,T3,T4,T5,T6,T7,T8,T9 >
        >
{
    using type = vector11;
};

template<
      typename T0, typename T1, typename T2, typename T3, typename T4
    , typename T5, typename T6, typename T7, typename T8, typename T9
    , typename T10, typename T11
    >
struct vector12
    : v_item<
          T11
        , vector11< T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10 >
        >
{
    using type = vector12;
};

template<
      typename T0, typename T1, typename T2, typename T3, typename T4
    , typename T5, typename T6, typename T7, typename T8, typename T9
    , typename T10, typename T11, typename T12
    >
struct vector13
    : v_item<
          T12
        , vector12< T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11 >
        >
{
    using type = vector13;
};

template<
      typename T0, typename T1, typename T2, typename T3, typename T4
    , typename T5, typename T6, typename T7, typename T8, typename T9
    , typename T10, typename T11, typename T12, typename T13
    >
struct vector14
    : v_item<
          T13
        , vector13< T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12 >
        >
{
    using type = vector14;
};

template<
      typename T0, typename T1, typename T2, typename T3, typename T4
    , typename T5, typename T6, typename T7, typename T8, typename T9
    , typename T10, typename T11, typename T12, typename T13, typename T14
    >
struct vector15
    : v_item<
          T14
        , vector14< T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13 >
        >
{
    using type = vector15;
};

template<
      typename T0, typename T1, typename T2, typename T3, typename T4
    , typename T5, typename T6, typename T7, typename T8, typename T9
    , typename T10, typename T11, typename T12, typename T13, typename T14
    , typename T15
    >
struct vector16
    : v_item<
          T15
        , vector15< T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14 >
        >
{
    using type = vector16;
};

template<
      typename T0, typename T1, typename T2, typename T3, typename T4
    , typename T5, typename T6, typename T7, typename T8, typename T9
    , typename T10, typename T11, typename T12, typename T13, typename T14
    , typename T15, typename T16
    >
struct vector17
    : v_item<
          T16
        , vector16< T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15 >
        >
{
    using type = vector17;
};

template<
      typename T0, typename T1, typename T2, typename T3, typename T4
    , typename T5, typename T6, typename T7, typename T8, typename T9
    , typename T10, typename T11, typename T12, typename T13, typename T14
    , typename T15, typename T16, typename T17
    >
struct vector18
    : v_item<
          T17
        , vector17< T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16 >
        >
{
    using type = vector18;
};

template<
      typename T0, typename T1, typename T2, typename T3, typename T4
    , typename T5, typename T6, typename T7, typename T8, typename T9
    , typename T10, typename T11, typename T12, typename T13, typename T14
    , typename T15, typename T16, typename T17, typename T18
    >
struct vector19
    : v_item<
          T18
        , vector18< T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17 >
        >
{
    using type = vector19;
};

template<
      typename T0, typename T1, typename T2, typename T3, typename T4
    , typename T5, typename T6, typename T7, typename T8, typename T9
    , typename T10, typename T11, typename T12, typename T13, typename T14
    , typename T15, typename T16, typename T17, typename T18, typename T19
    >
struct vector20
    : v_item<
          T19
        , vector19< T0,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18 >
        >
{
    using type = vector20;
};

}}
