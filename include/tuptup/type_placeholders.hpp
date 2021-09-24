#pragma once
#include <type_traits>
/*
 * tuptup: https://github.com/akisute514/tuptup/
 * Copyright (c) 2021 akisute514
 * 
 * Released under the MIT Lisence.
 */

namespace tuptup::type_placeholders {
    template<std::size_t N>
    struct placeholder_t {
        static constexpr std::size_t value = N;
    };

    using _1 = placeholder_t<1>;
    using _2 = placeholder_t<2>;
    using _3 = placeholder_t<3>;
    using _4 = placeholder_t<4>;
    using _5 = placeholder_t<5>;
    using _6 = placeholder_t<6>;
    using _7 = placeholder_t<7>;
    using _8 = placeholder_t<8>;
    using _9 = placeholder_t<9>;
    using _10 = placeholder_t<10>;
    using _11 = placeholder_t<11>;
    using _12 = placeholder_t<12>;
    using _13 = placeholder_t<13>;
    using _14 = placeholder_t<14>;
    using _15 = placeholder_t<15>;
    using _16 = placeholder_t<16>;

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
            struct replace_if_placeholder<placeholder_t<N>>{
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

    template<typename Binded>
    struct count;
    template<template<typename...>class Type, typename... Args>
    struct count<Type<Args...>>{
        template<typename T, typename... Ts>
        struct count_placeholder;
        template<typename T, std::size_t Head, typename... Tails>
        struct count_placeholder<T, placeholder_t<Head>, Tails...>{
            static constexpr std::size_t value = count_placeholder<T, Tails...>::value + 1;
        };
        template<typename T, typename Head, typename... Tails>
        struct count_placeholder<T, Head, Tails...>{
            static constexpr std::size_t value = count_placeholder<T, Tails...>::value;
        };
        template<typename T>
        struct count_placeholder<T>{
            static constexpr std::size_t value = 0;
        };
        static constexpr std::size_t value = count_placeholder<void, Args...>::value;
    };
}