#pragma once
#include <type_traits>

namespace tuptup{
    namespace placeholder_t {
        template<std::size_t N>
        struct placeholder{
            static constexpr std::size_t value = N;
        };

        using _1 = placeholder<1>;
        using _2 = placeholder<2>;
        using _3 = placeholder<3>;
        using _4 = placeholder<4>;
        using _5 = placeholder<5>;
        using _6 = placeholder<6>;
        using _7 = placeholder<7>;
        using _8 = placeholder<8>;
        using _9 = placeholder<9>;
        using _10 = placeholder<10>;
        using _11 = placeholder<11>;
        using _12 = placeholder<12>;
        using _13 = placeholder<13>;
        using _14 = placeholder<14>;
        using _15 = placeholder<15>;
        using _16 = placeholder<16>;
        using _17 = placeholder<17>;
        using _18 = placeholder<18>;
        using _19 = placeholder<19>;
        using _20 = placeholder<20>;
    }
    namespace detail{
        template<typename... Ts>
        struct type_tuple;
        template<typename T, typename... Ts>
        struct type_tuple<T, Ts...>{
            template<std::size_t N, typename enabler = void>
            struct get_impl;
            template<std::size_t N>
            struct get_impl<N, typename std::enable_if<(N == 0)>::type>{
                using type = T;
            };
            template<std::size_t N>
            struct get_impl<N, typename std::enable_if<(N > 0)>::type>{
                using type = typename type_tuple<Ts...>::template get<N-1>;
            };
            template<std::size_t N>
            using get = typename get_impl<N>::type;
        };
        template<>
        struct type_tuple<>{
            template<std::size_t N>
            using get = void;
        };
        template<typename Binded, typename... Args>
        struct replace_detail{
            template<typename T>
            struct replace_if_placeholder{
                using type = T;
            };
            template<std::size_t N>
            struct replace_if_placeholder<placeholder_t::placeholder<N>>{
                using type = typename type_tuple<Args...>::template get<N-1>;
            };
            template<typename T>
            struct replace_impl;
            template<template<typename...>class Type, typename... Elms>
            struct replace_impl<Type<Elms...>> {
                using type = Type<typename replace_if_placeholder<Elms>::type...>;
            };
            using type = typename replace_impl<Binded>::type;
        };
    }
    template<typename Binded, typename... Args>
    using replace = typename detail::replace_detail<Binded, Args...>::type;
}