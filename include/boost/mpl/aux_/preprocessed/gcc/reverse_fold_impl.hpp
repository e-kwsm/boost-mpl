
// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//

// Preprocessed version of "boost/mpl/aux_/reverse_fold_impl.hpp" header
// -- DO NOT modify by hand!

namespace boost { namespace mpl { namespace aux {

/// forward declaration

template<
      long N
    , typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    >
struct reverse_fold_impl;

template<
      typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    >
struct reverse_fold_impl< 0,First,Last,State,BackwardOp,ForwardOp >
{
    using iter0 = First;
    using fwd_state0 = State;
    using bkwd_state0 = fwd_state0;
    using state = bkwd_state0;
    using iterator = iter0;
};

template<
      typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    >
struct reverse_fold_impl< 1,First,Last,State,BackwardOp,ForwardOp >
{
    using iter0 = First;
    using fwd_state0 = State;
    using fwd_state1 = typename apply2< ForwardOp, fwd_state0, typename deref<iter0>::type >::type;
    using iter1 = typename mpl::next<iter0>::type;
    

    using bkwd_state1 = fwd_state1;
    using bkwd_state0 = typename apply2< BackwardOp, bkwd_state1, typename deref<iter0>::type >::type;
    using state = bkwd_state0;
    using iterator = iter1;
};

template<
      typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    >
struct reverse_fold_impl< 2,First,Last,State,BackwardOp,ForwardOp >
{
    using iter0 = First;
    using fwd_state0 = State;
    using fwd_state1 = typename apply2< ForwardOp, fwd_state0, typename deref<iter0>::type >::type;
    using iter1 = typename mpl::next<iter0>::type;
    using fwd_state2 = typename apply2< ForwardOp, fwd_state1, typename deref<iter1>::type >::type;
    using iter2 = typename mpl::next<iter1>::type;
    

    using bkwd_state2 = fwd_state2;
    using bkwd_state1 = typename apply2< BackwardOp, bkwd_state2, typename deref<iter1>::type >::type;
    using bkwd_state0 = typename apply2< BackwardOp, bkwd_state1, typename deref<iter0>::type >::type;
    

    using state = bkwd_state0;
    using iterator = iter2;
};

template<
      typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    >
struct reverse_fold_impl< 3,First,Last,State,BackwardOp,ForwardOp >
{
    using iter0 = First;
    using fwd_state0 = State;
    using fwd_state1 = typename apply2< ForwardOp, fwd_state0, typename deref<iter0>::type >::type;
    using iter1 = typename mpl::next<iter0>::type;
    using fwd_state2 = typename apply2< ForwardOp, fwd_state1, typename deref<iter1>::type >::type;
    using iter2 = typename mpl::next<iter1>::type;
    using fwd_state3 = typename apply2< ForwardOp, fwd_state2, typename deref<iter2>::type >::type;
    using iter3 = typename mpl::next<iter2>::type;
    

    using bkwd_state3 = fwd_state3;
    using bkwd_state2 = typename apply2< BackwardOp, bkwd_state3, typename deref<iter2>::type >::type;
    using bkwd_state1 = typename apply2< BackwardOp, bkwd_state2, typename deref<iter1>::type >::type;
    using bkwd_state0 = typename apply2< BackwardOp, bkwd_state1, typename deref<iter0>::type >::type;
    

    using state = bkwd_state0;
    using iterator = iter3;
};

template<
      typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    >
struct reverse_fold_impl< 4,First,Last,State,BackwardOp,ForwardOp >
{
    using iter0 = First;
    using fwd_state0 = State;
    using fwd_state1 = typename apply2< ForwardOp, fwd_state0, typename deref<iter0>::type >::type;
    using iter1 = typename mpl::next<iter0>::type;
    using fwd_state2 = typename apply2< ForwardOp, fwd_state1, typename deref<iter1>::type >::type;
    using iter2 = typename mpl::next<iter1>::type;
    using fwd_state3 = typename apply2< ForwardOp, fwd_state2, typename deref<iter2>::type >::type;
    using iter3 = typename mpl::next<iter2>::type;
    using fwd_state4 = typename apply2< ForwardOp, fwd_state3, typename deref<iter3>::type >::type;
    using iter4 = typename mpl::next<iter3>::type;
    

    using bkwd_state4 = fwd_state4;
    using bkwd_state3 = typename apply2< BackwardOp, bkwd_state4, typename deref<iter3>::type >::type;
    using bkwd_state2 = typename apply2< BackwardOp, bkwd_state3, typename deref<iter2>::type >::type;
    using bkwd_state1 = typename apply2< BackwardOp, bkwd_state2, typename deref<iter1>::type >::type;
    using bkwd_state0 = typename apply2< BackwardOp, bkwd_state1, typename deref<iter0>::type >::type;
    

    using state = bkwd_state0;
    using iterator = iter4;
};

template<
      long N
    , typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    >
struct reverse_fold_impl
{
    using iter0 = First;
    using fwd_state0 = State;
    using fwd_state1 = typename apply2< ForwardOp, fwd_state0, typename deref<iter0>::type >::type;
    using iter1 = typename mpl::next<iter0>::type;
    using fwd_state2 = typename apply2< ForwardOp, fwd_state1, typename deref<iter1>::type >::type;
    using iter2 = typename mpl::next<iter1>::type;
    using fwd_state3 = typename apply2< ForwardOp, fwd_state2, typename deref<iter2>::type >::type;
    using iter3 = typename mpl::next<iter2>::type;
    using fwd_state4 = typename apply2< ForwardOp, fwd_state3, typename deref<iter3>::type >::type;
    using iter4 = typename mpl::next<iter3>::type;
    

    using nested_chunk = reverse_fold_impl<
          ( (N - 4) < 0 ? 0 : N - 4 )
        , iter4
        , Last
        , fwd_state4
        , BackwardOp
        , ForwardOp
        >;

    using bkwd_state4 = typename nested_chunk::state;
    using bkwd_state3 = typename apply2< BackwardOp, bkwd_state4, typename deref<iter3>::type >::type;
    using bkwd_state2 = typename apply2< BackwardOp, bkwd_state3, typename deref<iter2>::type >::type;
    using bkwd_state1 = typename apply2< BackwardOp, bkwd_state2, typename deref<iter1>::type >::type;
    using bkwd_state0 = typename apply2< BackwardOp, bkwd_state1, typename deref<iter0>::type >::type;
    

    using state = bkwd_state0;
    using iterator = typename nested_chunk::iterator;
};

template<
      typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    >
struct reverse_fold_impl< -1,First,Last,State,BackwardOp,ForwardOp >
{
    using nested_step = reverse_fold_impl<
          -1
        , typename mpl::next<First>::type
        , Last
        , typename apply2<ForwardOp,State, typename deref<First>::type>::type
        , BackwardOp
        , ForwardOp
        >;

    using state = typename apply2<
          BackwardOp
        , typename nested_step::state
        , typename deref<First>::type
        >::type;

    using iterator = typename nested_step::iterator;
};

template<
      typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    >
struct reverse_fold_impl< -1,Last,Last,State,BackwardOp,ForwardOp >
{
    using state = State;
    using iterator = Last;
};

}}}
