
// Copyright Peter Dimov 2001
// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//

// Preprocessed version of "boost/mpl/bind.hpp" header
// -- DO NOT modify by hand!

namespace boost { namespace mpl {

namespace aux {

template<
      typename T, typename U1, typename U2, typename U3, typename U4
    , typename U5
    >
struct resolve_bind_arg
{
    using type = T;
};

template<
      typename T
    , typename Arg
    >
struct replace_unnamed_arg
{
    using next = Arg;
    using type = T;
};

template<
      typename Arg
    >
struct replace_unnamed_arg< arg< -1 >, Arg >
{
    using next = typename Arg::next;
    using type = Arg;
};

template<
      int N, typename U1, typename U2, typename U3, typename U4, typename U5
    >
struct resolve_bind_arg< arg<N>, U1, U2, U3, U4, U5 >
{
    using type = typename apply_wrap5<mpl::arg<N>, U1, U2, U3, U4, U5>::type;
};

template<
      typename F, typename T1, typename T2, typename T3, typename T4
    , typename T5, typename U1, typename U2, typename U3, typename U4
    , typename U5
    >
struct resolve_bind_arg< bind< F,T1,T2,T3,T4,T5 >, U1, U2, U3, U4, U5 >
{
    using f_ = bind< F,T1,T2,T3,T4,T5 >;
    using type = typename apply_wrap5< f_,U1,U2,U3,U4,U5 >::type;
};

} // namespace aux

template<
      typename F
    >
struct bind0
{
    template<
          typename U1 = na, typename U2 = na, typename U3 = na
        , typename U4 = na, typename U5 = na
        >
    struct apply
    {
     private:
        using r0 = aux::replace_unnamed_arg< F, mpl::arg<1> >;
        using a0 = typename r0::type;
        using n1 = typename r0::next;
        using f_ = typename aux::resolve_bind_arg< a0,U1,U2,U3,U4,U5 >::type;
        ///
     public:
        using type = typename apply_wrap0<
              f_
            >::type;

    };
};

namespace aux {

template<
      typename F, typename U1, typename U2, typename U3, typename U4
    , typename U5
    >
struct resolve_bind_arg<
      bind0<F>, U1, U2, U3, U4, U5
    >
{
    using f_ = bind0<F>;
    using type = typename apply_wrap5< f_,U1,U2,U3,U4,U5 >::type;
};

} // namespace aux

BOOST_MPL_AUX_ARITY_SPEC(1, bind0)
BOOST_MPL_AUX_TEMPLATE_ARITY_SPEC(1, bind0)

template<
      typename F
    >
struct bind< F,na,na,na,na,na >
    : bind0<F>
{
};

template<
      typename F, typename T1
    >
struct bind1
{
    template<
          typename U1 = na, typename U2 = na, typename U3 = na
        , typename U4 = na, typename U5 = na
        >
    struct apply
    {
     private:
        using r0 = aux::replace_unnamed_arg< F, mpl::arg<1> >;
        using a0 = typename r0::type;
        using n1 = typename r0::next;
        using f_ = typename aux::resolve_bind_arg< a0,U1,U2,U3,U4,U5 >::type;
        ///
        using r1 = aux::replace_unnamed_arg< T1,n1 >;
        using a1 = typename r1::type;
        using n2 = typename r1::next;
        using t1 = aux::resolve_bind_arg< a1,U1,U2,U3,U4,U5 >;
        ///
     public:
        using type = typename apply_wrap1<
              f_
            , typename t1::type
            >::type;

    };
};

namespace aux {

template<
      typename F, typename T1, typename U1, typename U2, typename U3
    , typename U4, typename U5
    >
struct resolve_bind_arg<
      bind1< F,T1 >, U1, U2, U3, U4, U5
    >
{
    using f_ = bind1< F,T1 >;
    using type = typename apply_wrap5< f_,U1,U2,U3,U4,U5 >::type;
};

} // namespace aux

BOOST_MPL_AUX_ARITY_SPEC(2, bind1)
BOOST_MPL_AUX_TEMPLATE_ARITY_SPEC(2, bind1)

template<
      typename F, typename T1
    >
struct bind< F,T1,na,na,na,na >
    : bind1< F,T1 >
{
};

template<
      typename F, typename T1, typename T2
    >
struct bind2
{
    template<
          typename U1 = na, typename U2 = na, typename U3 = na
        , typename U4 = na, typename U5 = na
        >
    struct apply
    {
     private:
        using r0 = aux::replace_unnamed_arg< F, mpl::arg<1> >;
        using a0 = typename r0::type;
        using n1 = typename r0::next;
        using f_ = typename aux::resolve_bind_arg< a0,U1,U2,U3,U4,U5 >::type;
        ///
        using r1 = aux::replace_unnamed_arg< T1,n1 >;
        using a1 = typename r1::type;
        using n2 = typename r1::next;
        using t1 = aux::resolve_bind_arg< a1,U1,U2,U3,U4,U5 >;
        ///
        using r2 = aux::replace_unnamed_arg< T2,n2 >;
        using a2 = typename r2::type;
        using n3 = typename r2::next;
        using t2 = aux::resolve_bind_arg< a2,U1,U2,U3,U4,U5 >;
        ///
     public:
        using type = typename apply_wrap2<
              f_
            , typename t1::type, typename t2::type
            >::type;

    };
};

namespace aux {

template<
      typename F, typename T1, typename T2, typename U1, typename U2
    , typename U3, typename U4, typename U5
    >
struct resolve_bind_arg<
      bind2< F,T1,T2 >, U1, U2, U3, U4, U5
    >
{
    using f_ = bind2< F,T1,T2 >;
    using type = typename apply_wrap5< f_,U1,U2,U3,U4,U5 >::type;
};

} // namespace aux

BOOST_MPL_AUX_ARITY_SPEC(3, bind2)
BOOST_MPL_AUX_TEMPLATE_ARITY_SPEC(3, bind2)

template<
      typename F, typename T1, typename T2
    >
struct bind< F,T1,T2,na,na,na >
    : bind2< F,T1,T2 >
{
};

template<
      typename F, typename T1, typename T2, typename T3
    >
struct bind3
{
    template<
          typename U1 = na, typename U2 = na, typename U3 = na
        , typename U4 = na, typename U5 = na
        >
    struct apply
    {
     private:
        using r0 = aux::replace_unnamed_arg< F, mpl::arg<1> >;
        using a0 = typename r0::type;
        using n1 = typename r0::next;
        using f_ = typename aux::resolve_bind_arg< a0,U1,U2,U3,U4,U5 >::type;
        ///
        using r1 = aux::replace_unnamed_arg< T1,n1 >;
        using a1 = typename r1::type;
        using n2 = typename r1::next;
        using t1 = aux::resolve_bind_arg< a1,U1,U2,U3,U4,U5 >;
        ///
        using r2 = aux::replace_unnamed_arg< T2,n2 >;
        using a2 = typename r2::type;
        using n3 = typename r2::next;
        using t2 = aux::resolve_bind_arg< a2,U1,U2,U3,U4,U5 >;
        ///
        using r3 = aux::replace_unnamed_arg< T3,n3 >;
        using a3 = typename r3::type;
        using n4 = typename r3::next;
        using t3 = aux::resolve_bind_arg< a3,U1,U2,U3,U4,U5 >;
        ///
     public:
        using type = typename apply_wrap3<
              f_
            , typename t1::type, typename t2::type, typename t3::type
            >::type;

    };
};

namespace aux {

template<
      typename F, typename T1, typename T2, typename T3, typename U1
    , typename U2, typename U3, typename U4, typename U5
    >
struct resolve_bind_arg<
      bind3< F,T1,T2,T3 >, U1, U2, U3, U4, U5
    >
{
    using f_ = bind3< F,T1,T2,T3 >;
    using type = typename apply_wrap5< f_,U1,U2,U3,U4,U5 >::type;
};

} // namespace aux

BOOST_MPL_AUX_ARITY_SPEC(4, bind3)
BOOST_MPL_AUX_TEMPLATE_ARITY_SPEC(4, bind3)

template<
      typename F, typename T1, typename T2, typename T3
    >
struct bind< F,T1,T2,T3,na,na >
    : bind3< F,T1,T2,T3 >
{
};

template<
      typename F, typename T1, typename T2, typename T3, typename T4
    >
struct bind4
{
    template<
          typename U1 = na, typename U2 = na, typename U3 = na
        , typename U4 = na, typename U5 = na
        >
    struct apply
    {
     private:
        using r0 = aux::replace_unnamed_arg< F, mpl::arg<1> >;
        using a0 = typename r0::type;
        using n1 = typename r0::next;
        using f_ = typename aux::resolve_bind_arg< a0,U1,U2,U3,U4,U5 >::type;
        ///
        using r1 = aux::replace_unnamed_arg< T1,n1 >;
        using a1 = typename r1::type;
        using n2 = typename r1::next;
        using t1 = aux::resolve_bind_arg< a1,U1,U2,U3,U4,U5 >;
        ///
        using r2 = aux::replace_unnamed_arg< T2,n2 >;
        using a2 = typename r2::type;
        using n3 = typename r2::next;
        using t2 = aux::resolve_bind_arg< a2,U1,U2,U3,U4,U5 >;
        ///
        using r3 = aux::replace_unnamed_arg< T3,n3 >;
        using a3 = typename r3::type;
        using n4 = typename r3::next;
        using t3 = aux::resolve_bind_arg< a3,U1,U2,U3,U4,U5 >;
        ///
        using r4 = aux::replace_unnamed_arg< T4,n4 >;
        using a4 = typename r4::type;
        using n5 = typename r4::next;
        using t4 = aux::resolve_bind_arg< a4,U1,U2,U3,U4,U5 >;
        ///
     public:
        using type = typename apply_wrap4<
              f_
            , typename t1::type, typename t2::type, typename t3::type
            , typename t4::type
            >::type;

    };
};

namespace aux {

template<
      typename F, typename T1, typename T2, typename T3, typename T4
    , typename U1, typename U2, typename U3, typename U4, typename U5
    >
struct resolve_bind_arg<
      bind4< F,T1,T2,T3,T4 >, U1, U2, U3, U4, U5
    >
{
    using f_ = bind4< F,T1,T2,T3,T4 >;
    using type = typename apply_wrap5< f_,U1,U2,U3,U4,U5 >::type;
};

} // namespace aux

BOOST_MPL_AUX_ARITY_SPEC(5, bind4)
BOOST_MPL_AUX_TEMPLATE_ARITY_SPEC(5, bind4)

template<
      typename F, typename T1, typename T2, typename T3, typename T4
    >
struct bind< F,T1,T2,T3,T4,na >
    : bind4< F,T1,T2,T3,T4 >
{
};

template<
      typename F, typename T1, typename T2, typename T3, typename T4
    , typename T5
    >
struct bind5
{
    template<
          typename U1 = na, typename U2 = na, typename U3 = na
        , typename U4 = na, typename U5 = na
        >
    struct apply
    {
     private:
        using r0 = aux::replace_unnamed_arg< F, mpl::arg<1> >;
        using a0 = typename r0::type;
        using n1 = typename r0::next;
        using f_ = typename aux::resolve_bind_arg< a0,U1,U2,U3,U4,U5 >::type;
        ///
        using r1 = aux::replace_unnamed_arg< T1,n1 >;
        using a1 = typename r1::type;
        using n2 = typename r1::next;
        using t1 = aux::resolve_bind_arg< a1,U1,U2,U3,U4,U5 >;
        ///
        using r2 = aux::replace_unnamed_arg< T2,n2 >;
        using a2 = typename r2::type;
        using n3 = typename r2::next;
        using t2 = aux::resolve_bind_arg< a2,U1,U2,U3,U4,U5 >;
        ///
        using r3 = aux::replace_unnamed_arg< T3,n3 >;
        using a3 = typename r3::type;
        using n4 = typename r3::next;
        using t3 = aux::resolve_bind_arg< a3,U1,U2,U3,U4,U5 >;
        ///
        using r4 = aux::replace_unnamed_arg< T4,n4 >;
        using a4 = typename r4::type;
        using n5 = typename r4::next;
        using t4 = aux::resolve_bind_arg< a4,U1,U2,U3,U4,U5 >;
        ///
        using r5 = aux::replace_unnamed_arg< T5,n5 >;
        using a5 = typename r5::type;
        using n6 = typename r5::next;
        using t5 = aux::resolve_bind_arg< a5,U1,U2,U3,U4,U5 >;
        ///
     public:
        using type = typename apply_wrap5<
              f_
            , typename t1::type, typename t2::type, typename t3::type
            , typename t4::type, typename t5::type
            >::type;

    };
};

namespace aux {

template<
      typename F, typename T1, typename T2, typename T3, typename T4
    , typename T5, typename U1, typename U2, typename U3, typename U4
    , typename U5
    >
struct resolve_bind_arg<
      bind5< F,T1,T2,T3,T4,T5 >, U1, U2, U3, U4, U5
    >
{
    using f_ = bind5< F,T1,T2,T3,T4,T5 >;
    using type = typename apply_wrap5< f_,U1,U2,U3,U4,U5 >::type;
};

} // namespace aux

BOOST_MPL_AUX_ARITY_SPEC(6, bind5)
BOOST_MPL_AUX_TEMPLATE_ARITY_SPEC(6, bind5)

/// primary template (not a specialization!)

template<
      typename F, typename T1, typename T2, typename T3, typename T4
    , typename T5
    >
struct bind
    : bind5< F,T1,T2,T3,T4,T5 >
{
};

/// if_/eval_if specializations
template< template< typename T1, typename T2, typename T3 > class F, typename Tag >
struct quote3;

template< typename T1, typename T2, typename T3 > struct if_;

template<
      typename Tag, typename T1, typename T2, typename T3
    >
struct bind3<
      quote3< if_,Tag >
    , T1, T2, T3
    >
{
    template<
          typename U1 = na, typename U2 = na, typename U3 = na
        , typename U4 = na, typename U5 = na
        >
    struct apply
    {
     private:
        using n1 = mpl::arg<1>;
        using r1 = aux::replace_unnamed_arg< T1,n1 >;
        using a1 = typename r1::type;
        using n2 = typename r1::next;
        using t1 = aux::resolve_bind_arg< a1,U1,U2,U3,U4,U5 >;
        ///
        using r2 = aux::replace_unnamed_arg< T2,n2 >;
        using a2 = typename r2::type;
        using n3 = typename r2::next;
        using t2 = aux::resolve_bind_arg< a2,U1,U2,U3,U4,U5 >;
        ///
        using r3 = aux::replace_unnamed_arg< T3,n3 >;
        using a3 = typename r3::type;
        using n4 = typename r3::next;
        using t3 = aux::resolve_bind_arg< a3,U1,U2,U3,U4,U5 >;
        ///
        using f_ = typename if_<
              typename t1::type
            , t2, t3
            >::type;

     public:
        using type = typename f_::type;
    };
};

template<
      template< typename T1, typename T2, typename T3 > class F, typename Tag
    >
struct quote3;

template< typename T1, typename T2, typename T3 > struct eval_if;

template<
      typename Tag, typename T1, typename T2, typename T3
    >
struct bind3<
      quote3< eval_if,Tag >
    , T1, T2, T3
    >
{
    template<
          typename U1 = na, typename U2 = na, typename U3 = na
        , typename U4 = na, typename U5 = na
        >
    struct apply
    {
     private:
        using n1 = mpl::arg<1>;
        using r1 = aux::replace_unnamed_arg< T1,n1 >;
        using a1 = typename r1::type;
        using n2 = typename r1::next;
        using t1 = aux::resolve_bind_arg< a1,U1,U2,U3,U4,U5 >;
        ///
        using r2 = aux::replace_unnamed_arg< T2,n2 >;
        using a2 = typename r2::type;
        using n3 = typename r2::next;
        using t2 = aux::resolve_bind_arg< a2,U1,U2,U3,U4,U5 >;
        ///
        using r3 = aux::replace_unnamed_arg< T3,n3 >;
        using a3 = typename r3::type;
        using n4 = typename r3::next;
        using t3 = aux::resolve_bind_arg< a3,U1,U2,U3,U4,U5 >;
        ///
        using f_ = typename eval_if<
              typename t1::type
            , t2, t3
            >::type;

     public:
        using type = typename f_::type;
    };
};

}}

