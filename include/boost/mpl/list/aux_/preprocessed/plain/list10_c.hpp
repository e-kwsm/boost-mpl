
// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//

// Preprocessed version of "boost/mpl/list/list10_c.hpp" header
// -- DO NOT modify by hand!

namespace boost { namespace mpl {

template<
      typename T
    , T C0
    >
struct list1_c
    : l_item<
          long_<1>
        , integral_c< T,C0 >
        , l_end
        >
{
    using type = list1_c;
    using value_type = T;
};

template<
      typename T
    , T C0, T C1
    >
struct list2_c
    : l_item<
          long_<2>
        , integral_c< T,C0 >
        , list1_c< T,C1 >
        >
{
    using type = list2_c;
    using value_type = T;
};

template<
      typename T
    , T C0, T C1, T C2
    >
struct list3_c
    : l_item<
          long_<3>
        , integral_c< T,C0 >
        , list2_c< T,C1,C2 >
        >
{
    using type = list3_c;
    using value_type = T;
};

template<
      typename T
    , T C0, T C1, T C2, T C3
    >
struct list4_c
    : l_item<
          long_<4>
        , integral_c< T,C0 >
        , list3_c< T,C1,C2,C3 >
        >
{
    using type = list4_c;
    using value_type = T;
};

template<
      typename T
    , T C0, T C1, T C2, T C3, T C4
    >
struct list5_c
    : l_item<
          long_<5>
        , integral_c< T,C0 >
        , list4_c< T,C1,C2,C3,C4 >
        >
{
    using type = list5_c;
    using value_type = T;
};

template<
      typename T
    , T C0, T C1, T C2, T C3, T C4, T C5
    >
struct list6_c
    : l_item<
          long_<6>
        , integral_c< T,C0 >
        , list5_c< T,C1,C2,C3,C4,C5 >
        >
{
    using type = list6_c;
    using value_type = T;
};

template<
      typename T
    , T C0, T C1, T C2, T C3, T C4, T C5, T C6
    >
struct list7_c
    : l_item<
          long_<7>
        , integral_c< T,C0 >
        , list6_c< T,C1,C2,C3,C4,C5,C6 >
        >
{
    using type = list7_c;
    using value_type = T;
};

template<
      typename T
    , T C0, T C1, T C2, T C3, T C4, T C5, T C6, T C7
    >
struct list8_c
    : l_item<
          long_<8>
        , integral_c< T,C0 >
        , list7_c< T,C1,C2,C3,C4,C5,C6,C7 >
        >
{
    using type = list8_c;
    using value_type = T;
};

template<
      typename T
    , T C0, T C1, T C2, T C3, T C4, T C5, T C6, T C7, T C8
    >
struct list9_c
    : l_item<
          long_<9>
        , integral_c< T,C0 >
        , list8_c< T,C1,C2,C3,C4,C5,C6,C7,C8 >
        >
{
    using type = list9_c;
    using value_type = T;
};

template<
      typename T
    , T C0, T C1, T C2, T C3, T C4, T C5, T C6, T C7, T C8, T C9
    >
struct list10_c
    : l_item<
          long_<10>
        , integral_c< T,C0 >
        , list9_c< T,C1,C2,C3,C4,C5,C6,C7,C8,C9 >
        >
{
    using type = list10_c;
    using value_type = T;
};

}}
