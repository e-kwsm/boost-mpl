
// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//

// Preprocessed version of "boost/mpl/aux_/full_lambda.hpp" header
// -- DO NOT modify by hand!

namespace boost { namespace mpl {

namespace aux {

template<
      bool C1 = false, bool C2 = false, bool C3 = false, bool C4 = false
    , bool C5 = false
    >
struct lambda_or
    : true_
{
};

template<>
struct lambda_or< false,false,false,false,false >
    : false_
{
};

} // namespace aux

template<
      typename T
    , typename Tag
    , typename Arity
    >
struct lambda
{
    using is_le = false_;
    using result_ = T;
    using type = T;
};

template<
      typename T
    >
struct is_lambda_expression
    : lambda<T>::is_le
{
};

template< int N, typename Tag >
struct lambda< arg<N>,Tag, int_< -1 > >
{
    using is_le = true_;
    using result_ = mpl::arg<N>; // qualified for the sake of MIPSpro 7.41
    using type = mpl::protect<result_>;
};

template<
      typename F
    , typename Tag
    >
struct lambda<
          bind0<F>
        , Tag
        , int_<1>
        >
{
    using is_le = false_;
    using result_ = bind0<
          F
        >;

    using type = result_;
};

namespace aux {

template<
      typename IsLE, typename Tag
    , template< typename P1 > class F
    , typename L1
    >
struct le_result1
{
    using result_ = F<
          typename L1::type
        >;

    using type = result_;
};

template<
      typename Tag
    , template< typename P1 > class F
    , typename L1
    >
struct le_result1< true_,Tag,F,L1 >
{
    using result_ = bind1<
          quote1< F,Tag >
        , typename L1::result_
        >;

    using type = mpl::protect<result_>;
};

} // namespace aux

template<
      template< typename P1 > class F
    , typename T1
    , typename Tag
    >
struct lambda<
          F<T1>
        , Tag
        , int_<1>
        >
{
    using l1 = lambda< T1,Tag >;
    using is_le1 = typename l1::is_le;
    using is_le = typename aux::lambda_or<
          is_le1::value
        >::type;

    using le_result_ = aux::le_result1<
          is_le, Tag, F, l1
        >;

    using result_ = typename le_result_::result_;
    using type = typename le_result_::type;
};

template<
      typename F, typename T1
    , typename Tag
    >
struct lambda<
          bind1< F,T1 >
        , Tag
        , int_<2>
        >
{
    using is_le = false_;
    using result_ = bind1<
          F
        , T1
        >;

    using type = result_;
};

namespace aux {

template<
      typename IsLE, typename Tag
    , template< typename P1, typename P2 > class F
    , typename L1, typename L2
    >
struct le_result2
{
    using result_ = F<
          typename L1::type, typename L2::type
        >;

    using type = result_;
};

template<
      typename Tag
    , template< typename P1, typename P2 > class F
    , typename L1, typename L2
    >
struct le_result2< true_,Tag,F,L1,L2 >
{
    using result_ = bind2<
          quote2< F,Tag >
        , typename L1::result_, typename L2::result_
        >;

    using type = mpl::protect<result_>;
};

} // namespace aux

template<
      template< typename P1, typename P2 > class F
    , typename T1, typename T2
    , typename Tag
    >
struct lambda<
          F< T1,T2 >
        , Tag
        , int_<2>
        >
{
    using l1 = lambda< T1,Tag >;
    using l2 = lambda< T2,Tag >;
    
    using is_le1 = typename l1::is_le;
    using is_le2 = typename l2::is_le;
    

    using is_le = typename aux::lambda_or<
          is_le1::value, is_le2::value
        >::type;

    using le_result_ = aux::le_result2<
          is_le, Tag, F, l1, l2
        >;

    using result_ = typename le_result_::result_;
    using type = typename le_result_::type;
};

template<
      typename F, typename T1, typename T2
    , typename Tag
    >
struct lambda<
          bind2< F,T1,T2 >
        , Tag
        , int_<3>
        >
{
    using is_le = false_;
    using result_ = bind2<
          F
        , T1, T2
        >;

    using type = result_;
};

namespace aux {

template<
      typename IsLE, typename Tag
    , template< typename P1, typename P2, typename P3 > class F
    , typename L1, typename L2, typename L3
    >
struct le_result3
{
    using result_ = F<
          typename L1::type, typename L2::type, typename L3::type
        >;

    using type = result_;
};

template<
      typename Tag
    , template< typename P1, typename P2, typename P3 > class F
    , typename L1, typename L2, typename L3
    >
struct le_result3< true_,Tag,F,L1,L2,L3 >
{
    using result_ = bind3<
          quote3< F,Tag >
        , typename L1::result_, typename L2::result_, typename L3::result_
        >;

    using type = mpl::protect<result_>;
};

} // namespace aux

template<
      template< typename P1, typename P2, typename P3 > class F
    , typename T1, typename T2, typename T3
    , typename Tag
    >
struct lambda<
          F< T1,T2,T3 >
        , Tag
        , int_<3>
        >
{
    using l1 = lambda< T1,Tag >;
    using l2 = lambda< T2,Tag >;
    using l3 = lambda< T3,Tag >;
    
    using is_le1 = typename l1::is_le;
    using is_le2 = typename l2::is_le;
    using is_le3 = typename l3::is_le;
    

    using is_le = typename aux::lambda_or<
          is_le1::value, is_le2::value, is_le3::value
        >::type;

    using le_result_ = aux::le_result3<
          is_le, Tag, F, l1, l2, l3
        >;

    using result_ = typename le_result_::result_;
    using type = typename le_result_::type;
};

template<
      typename F, typename T1, typename T2, typename T3
    , typename Tag
    >
struct lambda<
          bind3< F,T1,T2,T3 >
        , Tag
        , int_<4>
        >
{
    using is_le = false_;
    using result_ = bind3<
          F
        , T1, T2, T3
        >;

    using type = result_;
};

namespace aux {

template<
      typename IsLE, typename Tag
    , template< typename P1, typename P2, typename P3, typename P4 > class F
    , typename L1, typename L2, typename L3, typename L4
    >
struct le_result4
{
    using result_ = F<
          typename L1::type, typename L2::type, typename L3::type
        , typename L4::type
        >;

    using type = result_;
};

template<
      typename Tag
    , template< typename P1, typename P2, typename P3, typename P4 > class F
    , typename L1, typename L2, typename L3, typename L4
    >
struct le_result4< true_,Tag,F,L1,L2,L3,L4 >
{
    using result_ = bind4<
          quote4< F,Tag >
        , typename L1::result_, typename L2::result_, typename L3::result_
        , typename L4::result_
        >;

    using type = mpl::protect<result_>;
};

} // namespace aux

template<
      template< typename P1, typename P2, typename P3, typename P4 > class F
    , typename T1, typename T2, typename T3, typename T4
    , typename Tag
    >
struct lambda<
          F< T1,T2,T3,T4 >
        , Tag
        , int_<4>
        >
{
    using l1 = lambda< T1,Tag >;
    using l2 = lambda< T2,Tag >;
    using l3 = lambda< T3,Tag >;
    using l4 = lambda< T4,Tag >;
    
    using is_le1 = typename l1::is_le;
    using is_le2 = typename l2::is_le;
    using is_le3 = typename l3::is_le;
    using is_le4 = typename l4::is_le;
    

    using is_le = typename aux::lambda_or<
          is_le1::value, is_le2::value, is_le3::value, is_le4::value
        >::type;

    using le_result_ = aux::le_result4<
          is_le, Tag, F, l1, l2, l3, l4
        >;

    using result_ = typename le_result_::result_;
    using type = typename le_result_::type;
};

template<
      typename F, typename T1, typename T2, typename T3, typename T4
    , typename Tag
    >
struct lambda<
          bind4< F,T1,T2,T3,T4 >
        , Tag
        , int_<5>
        >
{
    using is_le = false_;
    using result_ = bind4<
          F
        , T1, T2, T3, T4
        >;

    using type = result_;
};

namespace aux {

template<
      typename IsLE, typename Tag
    , template< typename P1, typename P2, typename P3, typename P4, typename P5 > class F
    , typename L1, typename L2, typename L3, typename L4, typename L5
    >
struct le_result5
{
    using result_ = F<
          typename L1::type, typename L2::type, typename L3::type
        , typename L4::type, typename L5::type
        >;

    using type = result_;
};

template<
      typename Tag
    , template< typename P1, typename P2, typename P3, typename P4, typename P5 > class F
    , typename L1, typename L2, typename L3, typename L4, typename L5
    >
struct le_result5< true_,Tag,F,L1,L2,L3,L4,L5 >
{
    using result_ = bind5<
          quote5< F,Tag >
        , typename L1::result_, typename L2::result_, typename L3::result_
        , typename L4::result_, typename L5::result_
        >;

    using type = mpl::protect<result_>;
};

} // namespace aux

template<
      template<
          typename P1, typename P2, typename P3, typename P4
        , typename P5
        >
      class F
    , typename T1, typename T2, typename T3, typename T4, typename T5
    , typename Tag
    >
struct lambda<
          F< T1,T2,T3,T4,T5 >
        , Tag
        , int_<5>
        >
{
    using l1 = lambda< T1,Tag >;
    using l2 = lambda< T2,Tag >;
    using l3 = lambda< T3,Tag >;
    using l4 = lambda< T4,Tag >;
    using l5 = lambda< T5,Tag >;
    
    using is_le1 = typename l1::is_le;
    using is_le2 = typename l2::is_le;
    using is_le3 = typename l3::is_le;
    using is_le4 = typename l4::is_le;
    using is_le5 = typename l5::is_le;
    

    using is_le = typename aux::lambda_or<
          is_le1::value, is_le2::value, is_le3::value, is_le4::value
        , is_le5::value
        >::type;

    using le_result_ = aux::le_result5<
          is_le, Tag, F, l1, l2, l3, l4, l5
        >;

    using result_ = typename le_result_::result_;
    using type = typename le_result_::type;
};

template<
      typename F, typename T1, typename T2, typename T3, typename T4
    , typename T5
    , typename Tag
    >
struct lambda<
          bind5< F,T1,T2,T3,T4,T5 >
        , Tag
        , int_<6>
        >
{
    using is_le = false_;
    using result_ = bind5<
          F
        , T1, T2, T3, T4, T5
        >;

    using type = result_;
};

/// special case for 'protect'
template< typename T, typename Tag >
struct lambda< mpl::protect<T>,Tag, int_<1> >
{
    using is_le = false_;
    using result_ = mpl::protect<T>;
    using type = result_;
};

/// specializations for the main 'bind' form

template<
      typename F, typename T1, typename T2, typename T3, typename T4
    , typename T5
    , typename Tag
    >
struct lambda<
          bind< F,T1,T2,T3,T4,T5 >
        , Tag
        , int_<6>
        >
{
    using is_le = false_;
    using result_ = bind< F,T1,T2,T3,T4,T5 >;
    using type = result_;
};

template<
      typename F
    , typename Tag1
    , typename Tag2
    , typename Arity
    >
struct lambda<
          lambda< F,Tag1,Arity >
        , Tag2
        , int_<3>
        >
{
    using l1 = lambda< F,Tag2 >;
    using l2 = lambda< Tag1,Tag2 >;
    using is_le = typename l1::is_le;
    using arity_ = bind1< quote1<aux::template_arity>, typename l1::result_ >;
    using l3 = lambda< typename if_< is_le,arity_,Arity >::type, Tag2 >;
    using le_result_ = aux::le_result3<is_le, Tag2, mpl::lambda, l1, l2, l3>;
    using result_ = typename le_result_::result_;
    using type = typename le_result_::type;
};

BOOST_MPL_AUX_NA_SPEC2(2, 3, lambda)

}}

