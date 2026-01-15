
// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//

// Preprocessed version of "boost/mpl/aux_/iter_fold_impl.hpp" header
// -- DO NOT modify by hand!

namespace boost { namespace mpl { namespace aux {

/// forward declaration

template<
      int N
    , typename First
    , typename Last
    , typename State
    , typename ForwardOp
    >
struct iter_fold_impl;

template<
      typename First
    , typename Last
    , typename State
    , typename ForwardOp
    >
struct iter_fold_impl< 0,First,Last,State,ForwardOp >
{
    using iter0 = First;
    using state0 = State;
    using state = state0;
    using iterator = iter0;
};

template<
      typename First
    , typename Last
    , typename State
    , typename ForwardOp
    >
struct iter_fold_impl< 1,First,Last,State,ForwardOp >
{
    using iter0 = First;
    using state0 = State;
    using state1 = typename apply2< ForwardOp,state0,iter0 >::type;
    using iter1 = typename mpl::next<iter0>::type;
    

    using state = state1;
    using iterator = iter1;
};

template<
      typename First
    , typename Last
    , typename State
    , typename ForwardOp
    >
struct iter_fold_impl< 2,First,Last,State,ForwardOp >
{
    using iter0 = First;
    using state0 = State;
    using state1 = typename apply2< ForwardOp,state0,iter0 >::type;
    using iter1 = typename mpl::next<iter0>::type;
    using state2 = typename apply2< ForwardOp,state1,iter1 >::type;
    using iter2 = typename mpl::next<iter1>::type;
    

    using state = state2;
    using iterator = iter2;
};

template<
      typename First
    , typename Last
    , typename State
    , typename ForwardOp
    >
struct iter_fold_impl< 3,First,Last,State,ForwardOp >
{
    using iter0 = First;
    using state0 = State;
    using state1 = typename apply2< ForwardOp,state0,iter0 >::type;
    using iter1 = typename mpl::next<iter0>::type;
    using state2 = typename apply2< ForwardOp,state1,iter1 >::type;
    using iter2 = typename mpl::next<iter1>::type;
    using state3 = typename apply2< ForwardOp,state2,iter2 >::type;
    using iter3 = typename mpl::next<iter2>::type;
    

    using state = state3;
    using iterator = iter3;
};

template<
      typename First
    , typename Last
    , typename State
    , typename ForwardOp
    >
struct iter_fold_impl< 4,First,Last,State,ForwardOp >
{
    using iter0 = First;
    using state0 = State;
    using state1 = typename apply2< ForwardOp,state0,iter0 >::type;
    using iter1 = typename mpl::next<iter0>::type;
    using state2 = typename apply2< ForwardOp,state1,iter1 >::type;
    using iter2 = typename mpl::next<iter1>::type;
    using state3 = typename apply2< ForwardOp,state2,iter2 >::type;
    using iter3 = typename mpl::next<iter2>::type;
    using state4 = typename apply2< ForwardOp,state3,iter3 >::type;
    using iter4 = typename mpl::next<iter3>::type;
    

    using state = state4;
    using iterator = iter4;
};

template<
      int N
    , typename First
    , typename Last
    , typename State
    , typename ForwardOp
    >
struct iter_fold_impl
{
    using chunk_ = iter_fold_impl<
          4
        , First
        , Last
        , State
        , ForwardOp
        >;

    using res_ = iter_fold_impl<
          ( (N - 4) < 0 ? 0 : N - 4 )
        , typename chunk_::iterator
        , Last
        , typename chunk_::state
        , ForwardOp
        >;

    using state = typename res_::state;
    using iterator = typename res_::iterator;
};

template<
      typename First
    , typename Last
    , typename State
    , typename ForwardOp
    >
struct iter_fold_impl< -1,First,Last,State,ForwardOp >
    : iter_fold_impl<
          -1
        , typename mpl::next<First>::type
        , Last
        , typename apply2< ForwardOp,State,First >::type
        , ForwardOp
        >
{
};

template<
      typename Last
    , typename State
    , typename ForwardOp
    >
struct iter_fold_impl< -1,Last,Last,State,ForwardOp >
{
    using state = State;
    using iterator = Last;
};

}}}
