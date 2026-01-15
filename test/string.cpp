
// Copyright Eric Niebler 2009
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: string.cpp 49240 2009-04-01 09:21:07Z eric_niebler $
// $Date: 2009-04-01 02:21:07 -0700 (Wed, 1 Apr 2009) $
// $Revision: 49240 $

#include <string>
#include <cstring>
#include <iostream>

#include <boost/mpl/string.hpp>

#include <boost/mpl/at.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/erase.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/advance.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/pop_back.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/detail/lightweight_test.hpp>

namespace mpl = boost::mpl;

// Accept a string as a template parameter!
template<char const *sz>
struct greeting
{
    std::string say_hello() const
    {
        return sz;
    }
};

struct push_char
{
    push_char(std::string &str)
      : str_(&str)
    {}

    void operator()(char ch) const
    {
        this->str_->push_back(ch);
    }

    std::string *str_;
};

int main()
{
    // Test mpl::size of strings
    {
        using almost_full = mpl::string<'aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaa'>;
        using full = mpl::string<'aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa'>;

        BOOST_MPL_ASSERT_RELATION(0,  ==, (mpl::size<mpl::string<> >::value));
        BOOST_MPL_ASSERT_RELATION(1,  ==, (mpl::size<mpl::string<'a'> >::value));
        BOOST_MPL_ASSERT_RELATION(2,  ==, (mpl::size<mpl::string<'ab'> >::value));
        BOOST_MPL_ASSERT_RELATION(2,  ==, (mpl::size<mpl::string<'a','b'> >::value));
        BOOST_MPL_ASSERT_RELATION(4,  ==, (mpl::size<mpl::string<'abcd'> >::value));
        BOOST_MPL_ASSERT_RELATION(5,  ==, (mpl::size<mpl::string<'abcd','e'> >::value));
        BOOST_MPL_ASSERT_RELATION(31, ==, (mpl::size<almost_full>::value));
        BOOST_MPL_ASSERT_RELATION(32, ==, (mpl::size<full>::value));
    }

    // Test mpl::begin and mpl::end with strings
    {
        using almost_full = mpl::string<'aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaa'>;
        using full = mpl::string<'aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa'>;

        BOOST_MPL_ASSERT((
            boost::is_same<
                mpl::begin<mpl::string<> >::type
              , mpl::end<mpl::string<> >::type
            >
        ));

        BOOST_MPL_ASSERT((
            boost::is_same<
                mpl::begin<mpl::string<'a'> >::type
              , mpl::string_iterator<mpl::string<'a'>, 0, 0>
            >
        ));

        BOOST_MPL_ASSERT((
            boost::is_same<
                mpl::end<mpl::string<'a'> >::type
              , mpl::string_iterator<mpl::string<'a'>, 1, 0>
            >
        ));

        BOOST_MPL_ASSERT((
            boost::is_same<
                mpl::begin<almost_full>::type
              , mpl::string_iterator<almost_full, 0, 0>
            >
        ));

        BOOST_MPL_ASSERT((
            boost::is_same<
                mpl::end<almost_full>::type
              , mpl::string_iterator<almost_full, 8, 0>
            >
        ));

        BOOST_MPL_ASSERT((
            boost::is_same<
                mpl::begin<full>::type
              , mpl::string_iterator<full, 0, 0>
            >
        ));

        BOOST_MPL_ASSERT((
            boost::is_same<
                mpl::end<full>::type
              , mpl::string_iterator<full, 8, 0>
            >
        ));
    }

    // testing push_back
    {
        using t1 = mpl::push_back<mpl::string<>, mpl::char_<'a'> >::type;
        BOOST_MPL_ASSERT((boost::is_same<t1, mpl::string<'a'> >));

        using t2 = mpl::push_back<t1, mpl::char_<'b'> >::type;
        BOOST_MPL_ASSERT((boost::is_same<t2, mpl::string<'ab'> >));

        using t3 = mpl::push_back<t2, mpl::char_<'c'> >::type;
        BOOST_MPL_ASSERT((boost::is_same<t3, mpl::string<'abc'> >));

        using t4 = mpl::push_back<t3, mpl::char_<'d'> >::type;
        BOOST_MPL_ASSERT((boost::is_same<t4, mpl::string<'abcd'> >));

        using t5 = mpl::push_back<t4, mpl::char_<'e'> >::type;
        BOOST_MPL_ASSERT((boost::is_same<t5, mpl::string<'abcd','e'> >));

        using almost_full = mpl::string<'aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaa'>;
        using t6 = mpl::push_back<almost_full, mpl::char_<'X'> >::type;
        BOOST_MPL_ASSERT((boost::is_same<t6, mpl::string<'aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaX'> >));
    }

    // Test mpl::next
    {
        using s = mpl::string<'a','bc','def','ghij'>;

        using i0 = mpl::begin<s>::type;
        BOOST_MPL_ASSERT((boost::is_same<i0, mpl::string_iterator<s,0,0> >));

        using i1 = mpl::next<i0>::type;
        BOOST_MPL_ASSERT((boost::is_same<i1, mpl::string_iterator<s,1,0> >));

        using i2 = mpl::next<i1>::type;
        BOOST_MPL_ASSERT((boost::is_same<i2, mpl::string_iterator<s,1,1> >));

        using i3 = mpl::next<i2>::type;
        BOOST_MPL_ASSERT((boost::is_same<i3, mpl::string_iterator<s,2,0> >));

        using i4 = mpl::next<i3>::type;
        BOOST_MPL_ASSERT((boost::is_same<i4, mpl::string_iterator<s,2,1> >));

        using i5 = mpl::next<i4>::type;
        BOOST_MPL_ASSERT((boost::is_same<i5, mpl::string_iterator<s,2,2> >));

        using i6 = mpl::next<i5>::type;
        BOOST_MPL_ASSERT((boost::is_same<i6, mpl::string_iterator<s,3,0> >));

        using i7 = mpl::next<i6>::type;
        BOOST_MPL_ASSERT((boost::is_same<i7, mpl::string_iterator<s,3,1> >));

        using i8 = mpl::next<i7>::type;
        BOOST_MPL_ASSERT((boost::is_same<i8, mpl::string_iterator<s,3,2> >));

        using i9 = mpl::next<i8>::type;
        BOOST_MPL_ASSERT((boost::is_same<i9, mpl::string_iterator<s,3,3> >));

        using i10 = mpl::next<i9>::type;
        BOOST_MPL_ASSERT((boost::is_same<i10, mpl::string_iterator<s,4,0> >));

        BOOST_MPL_ASSERT((boost::is_same<i10, mpl::end<s>::type>));
    }

    // Test mpl::prior
    {
        using s = mpl::string<'a','bc','def','ghij'>;

        using i10 = mpl::end<s>::type;
        BOOST_MPL_ASSERT((boost::is_same<i10, mpl::string_iterator<s,4,0> >));

        using i9 = mpl::prior<i10>::type;
        BOOST_MPL_ASSERT((boost::is_same<i9, mpl::string_iterator<s,3,3> >));

        using i8 = mpl::prior<i9>::type;
        BOOST_MPL_ASSERT((boost::is_same<i8, mpl::string_iterator<s,3,2> >));

        using i7 = mpl::prior<i8>::type;
        BOOST_MPL_ASSERT((boost::is_same<i7, mpl::string_iterator<s,3,1> >));

        using i6 = mpl::prior<i7>::type;
        BOOST_MPL_ASSERT((boost::is_same<i6, mpl::string_iterator<s,3,0> >));

        using i5 = mpl::prior<i6>::type;
        BOOST_MPL_ASSERT((boost::is_same<i5, mpl::string_iterator<s,2,2> >));

        using i4 = mpl::prior<i5>::type;
        BOOST_MPL_ASSERT((boost::is_same<i4, mpl::string_iterator<s,2,1> >));

        using i3 = mpl::prior<i4>::type;
        BOOST_MPL_ASSERT((boost::is_same<i3, mpl::string_iterator<s,2,0> >));

        using i2 = mpl::prior<i3>::type;
        BOOST_MPL_ASSERT((boost::is_same<i2, mpl::string_iterator<s,1,1> >));

        using i1 = mpl::prior<i2>::type;
        BOOST_MPL_ASSERT((boost::is_same<i1, mpl::string_iterator<s,1,0> >));

        using i0 = mpl::prior<i1>::type;
        BOOST_MPL_ASSERT((boost::is_same<i0, mpl::string_iterator<s,0,0> >));

        BOOST_MPL_ASSERT((boost::is_same<i0, mpl::begin<s>::type>));
    }

    // Test mpl::deref
    {
        using s = mpl::string<'a','bc','def','ghij'>;

        using i0 = mpl::begin<s>::type;
        BOOST_MPL_ASSERT((boost::is_same<mpl::deref<i0>::type, mpl::char_<'a'> >));

        using i1 = mpl::next<i0>::type;
        BOOST_MPL_ASSERT((boost::is_same<mpl::deref<i1>::type, mpl::char_<'b'> >));

        using i2 = mpl::next<i1>::type;
        BOOST_MPL_ASSERT((boost::is_same<mpl::deref<i2>::type, mpl::char_<'c'> >));

        using i3 = mpl::next<i2>::type;
        BOOST_MPL_ASSERT((boost::is_same<mpl::deref<i3>::type, mpl::char_<'d'> >));

        using i4 = mpl::next<i3>::type;
        BOOST_MPL_ASSERT((boost::is_same<mpl::deref<i4>::type, mpl::char_<'e'> >));

        using i5 = mpl::next<i4>::type;
        BOOST_MPL_ASSERT((boost::is_same<mpl::deref<i5>::type, mpl::char_<'f'> >));

        using i6 = mpl::next<i5>::type;
        BOOST_MPL_ASSERT((boost::is_same<mpl::deref<i6>::type, mpl::char_<'g'> >));

        using i7 = mpl::next<i6>::type;
        BOOST_MPL_ASSERT((boost::is_same<mpl::deref<i7>::type, mpl::char_<'h'> >));

        using i8 = mpl::next<i7>::type;
        BOOST_MPL_ASSERT((boost::is_same<mpl::deref<i8>::type, mpl::char_<'i'> >));

        using i9 = mpl::next<i8>::type;
        BOOST_MPL_ASSERT((boost::is_same<mpl::deref<i9>::type, mpl::char_<'j'> >));
    }

    // testing push_back
    {
        using t1 = mpl::push_back<mpl::string<>, mpl::char_<'a'> >::type;
        BOOST_MPL_ASSERT((boost::is_same<t1, mpl::string<'a'> >));

        using t2 = mpl::push_back<t1, mpl::char_<'b'> >::type;
        BOOST_MPL_ASSERT((boost::is_same<t2, mpl::string<'ab'> >));

        using t3 = mpl::push_back<t2, mpl::char_<'c'> >::type;
        BOOST_MPL_ASSERT((boost::is_same<t3, mpl::string<'abc'> >));

        using t4 = mpl::push_back<t3, mpl::char_<'d'> >::type;
        BOOST_MPL_ASSERT((boost::is_same<t4, mpl::string<'abcd'> >));

        using t5 = mpl::push_back<t4, mpl::char_<'e'> >::type;
        BOOST_MPL_ASSERT((boost::is_same<t5, mpl::string<'abcd','e'> >));

        using almost_full = mpl::string<'aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaa'>;
        using t6 = mpl::push_back<almost_full, mpl::char_<'X'> >::type;
        BOOST_MPL_ASSERT((boost::is_same<t6, mpl::string<'aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaX'> >));

        using must_repack = mpl::string<'a','a','a','a','a','a','a','aaaa'>;
        using t7 = mpl::push_back<must_repack, mpl::char_<'X'> >::type;
        BOOST_MPL_ASSERT((boost::is_same<t7, mpl::string<'aaaa','aaaa','aaaX'> >));
    }

    BOOST_MPL_ASSERT((mpl::empty<mpl::string<> >));
    BOOST_MPL_ASSERT_NOT((mpl::empty<mpl::string<'hi!'> >));

    // testing push_front
    {
        using t1 = mpl::push_front<mpl::string<>, mpl::char_<'a'> >::type;
        BOOST_MPL_ASSERT((boost::is_same<t1, mpl::string<'a'> >));

        using t2 = mpl::push_front<t1, mpl::char_<'b'> >::type;
        BOOST_MPL_ASSERT((boost::is_same<t2, mpl::string<'ba'> >));

        using t3 = mpl::push_front<t2, mpl::char_<'c'> >::type;
        BOOST_MPL_ASSERT((boost::is_same<t3, mpl::string<'cba'> >));

        using t4 = mpl::push_front<t3, mpl::char_<'d'> >::type;
        BOOST_MPL_ASSERT((boost::is_same<t4, mpl::string<'dcba'> >));

        using t5 = mpl::push_front<t4, mpl::char_<'e'> >::type;
        BOOST_MPL_ASSERT((boost::is_same<t5, mpl::string<'e','dcba'> >));

        using almost_full = mpl::string<'aaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa'>;
        using t6 = mpl::push_front<almost_full, mpl::char_<'X'> >::type;
        BOOST_MPL_ASSERT((boost::is_same<t6, mpl::string<'Xaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa'> >));

        using must_repack = mpl::string<'aaaa','a','a','a','a','a','a','a'>;
        using t7 = mpl::push_front<must_repack, mpl::char_<'X'> >::type;
        BOOST_MPL_ASSERT((boost::is_same<t7, mpl::string<'Xaaa','aaaa','aaaa'> >));
    }

    // Test c_str<>
    BOOST_TEST(0 == std::strcmp(
        mpl::c_str<mpl::string<> >::value
                             , ""
    ));

    BOOST_TEST(0 == std::strcmp(
        mpl::c_str<mpl::string<'Hell','o wo','rld!'> >::value
                             , "Hell" "o wo" "rld!"
    ));

    BOOST_TEST(0 == std::strcmp(
        mpl::c_str<mpl::string<'aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaX'> >::value
                             , "aaaa" "aaaa" "aaaa" "aaaa" "aaaa" "aaaa" "aaaa" "aaaX"
    ));

    // test using a string as a template parameter
    greeting<mpl::c_str<mpl::string<'Hell','o wo','rld!'> >::value> g;
    BOOST_TEST("Hello world!" == g.say_hello());

    std::string result;
    mpl::for_each<mpl::string<'Hell','o wo','rld!'> >(push_char(result));
    BOOST_TEST("Hello world!" == result);

    BOOST_TEST(('h' == mpl::front<mpl::string<'hi!'> >::type()));
    BOOST_TEST(('!' == mpl::back<mpl::string<'hi!'> >::type()));

    // back-inserter with copy
    using rgc = mpl::vector_c<char, 'a','b','c','d','e'>;
    BOOST_TEST(0 == std::strcmp("abcde", mpl::c_str<rgc>::value));
    using str = mpl::copy<rgc, mpl::back_inserter<mpl::string<> > >::type;
    BOOST_TEST(0 == std::strcmp("abcde", mpl::c_str<str>::value));

    // test insert_range and erase
    {
        using hello = mpl::string<'Hell','o wo','rld!'>;
        using where = mpl::advance_c<mpl::begin<hello>::type, 5>::type;
        using cruel = mpl::string<' cru','el'>;
        using hello_cruel = mpl::insert_range<hello, where, cruel>::type;
        BOOST_TEST(0 == std::strcmp("Hello cruel world!", mpl::c_str<hello_cruel>::value));

        using erased1 = mpl::erase<hello, mpl::begin<hello>::type, where>::type;
        BOOST_TEST(0 == std::strcmp(" world!", mpl::c_str<erased1>::value));
    }

    // test pop_front
    {
        BOOST_MPL_ASSERT((
            boost::is_same<
                mpl::pop_front<mpl::string<'a'> >::type
              , mpl::string<>
            >
        ));

        BOOST_MPL_ASSERT((
            boost::is_same<
                mpl::pop_front<mpl::string<'ab'> >::type
              , mpl::string<'b'>
            >
        ));

        BOOST_MPL_ASSERT((
            boost::is_same<
                mpl::pop_front<mpl::string<'abc'> >::type
              , mpl::string<'bc'>
            >
        ));

        BOOST_MPL_ASSERT((
            boost::is_same<
                mpl::pop_front<mpl::string<'abcd'> >::type
              , mpl::string<'bcd'>
            >
        ));

        BOOST_MPL_ASSERT((
            boost::is_same<
                mpl::pop_front<mpl::string<'abcd','e'> >::type
              , mpl::string<'bcd','e'>
            >
        ));

        BOOST_MPL_ASSERT((
            boost::is_same<
                mpl::pop_front<mpl::string<'d','e'> >::type
              , mpl::string<'e'>
            >
        ));

        BOOST_MPL_ASSERT((
            boost::is_same<
                mpl::pop_front<mpl::string<'aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa'> >::type
              , mpl::string<'aaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa'>
            >
        ));
    }

    // test pop_back
    {
        BOOST_MPL_ASSERT((
            boost::is_same<
                mpl::pop_back<mpl::string<'a'> >::type
              , mpl::string<>
            >
        ));

        BOOST_MPL_ASSERT((
            boost::is_same<
                mpl::pop_back<mpl::string<'ab'> >::type
              , mpl::string<'a'>
            >
        ));

        BOOST_MPL_ASSERT((
            boost::is_same<
                mpl::pop_back<mpl::string<'abc'> >::type
              , mpl::string<'ab'>
            >
        ));

        BOOST_MPL_ASSERT((
            boost::is_same<
                mpl::pop_back<mpl::string<'abcd'> >::type
              , mpl::string<'abc'>
            >
        ));

        BOOST_MPL_ASSERT((
            boost::is_same<
                mpl::pop_back<mpl::string<'abcd','e'> >::type
              , mpl::string<'abcd'>
            >
        ));

        BOOST_MPL_ASSERT((
            boost::is_same<
                mpl::pop_back<mpl::string<'d','e'> >::type
              , mpl::string<'d'>
            >
        ));

        BOOST_MPL_ASSERT((
            boost::is_same<
                mpl::pop_back<mpl::string<'aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa'> >::type
              , mpl::string<'aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaaa','aaa'>
            >
        ));
    }

    {
        BOOST_TEST((
            mpl::at_c<
                mpl::string<'\x7f'>
              , 0
            >::type::value == (char)0x7f
        ));

        BOOST_TEST((
            mpl::at_c<
                mpl::string<'\x80'>
              , 0
            >::type::value == (char)0x80
        ));

        BOOST_TEST((
            mpl::at_c<
                mpl::string<
                    mpl::at_c<
                        mpl::string<'\x7f'>
                      , 0
                    >::type::value
                >
              , 0
            >::type::value == (char)0x7f
        ));

        BOOST_TEST((
            mpl::at_c<
                mpl::string<
                    mpl::at_c<
                        mpl::string<'\x80'>
                      , 0
                    >::type::value
                >
              , 0
            >::type::value == (char)0x80
        ));
    }

    return boost::report_errors();
}
