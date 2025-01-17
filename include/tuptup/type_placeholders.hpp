#pragma once
#include <type_traits>
/*
 * tuptup: https://github.com/MurakamiShun/tuptup/
 * Copyright (c) 2025 MurakamiShun
 * 
 * Released under the MIT License.
 */

namespace tuptup{
namespace type_placeholders {
    template<typename T, typename enabler = void>
    struct is_transformation_trait{
        static constexpr bool value = false;
    };
    template<typename T>
    struct is_transformation_trait<T, typename std::enable_if<(std::declval<typename T::type>(), true)>::type>{
        static constexpr bool value = true;
    };

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

    template<typename T, typename enabler = void>
    struct defer;
    template<typename T>
    struct defer<T, typename std::enable_if<is_transformation_trait<T>::value>::type> {
        using type = typename T::type;
    };

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
            struct replace_impl;
            template<typename T>
            struct replace_if_placeholder{
                using type = typename replace_impl<T>::type;
            };
            template<typename T>
            struct replace_if_placeholder<defer<T>>{
                using type = typename replace_impl<T>::type::type;
            };
            template<std::size_t N>
            struct replace_if_placeholder<placeholder_t<N>>{
                using type = typename type_tuple<Args...>::template get<N-1>;
            };
            template<std::size_t N>
            struct replace_if_placeholder<placeholder_t<N>&>{
                using type = typename type_tuple<Args...>::template get<N-1>::type&;
            };
            template<std::size_t N>
            struct replace_if_placeholder<placeholder_t<N>&&>{
                using type = typename type_tuple<Args...>::template get<N-1>::type&&;
            };
            template<std::size_t N>
            struct replace_if_placeholder<const placeholder_t<N>>{
                using type = typename type_tuple<Args...>::template get<N-1>;
            };
            template<std::size_t N>
            struct replace_if_placeholder<const placeholder_t<N>&>{
                using type = const typename type_tuple<Args...>::template get<N-1>::type&;
            };
            template<std::size_t N>
            struct replace_if_placeholder<const placeholder_t<N>&&>{
                using type = const typename type_tuple<Args...>::template get<N-1>::type&&;
            };
            template<template<typename...>class Type, typename... Elms>
            struct replace_impl<Type<Elms...>> {
                using type = Type<typename replace_if_placeholder<Elms>::type...>;
            };
            template<template<typename...>class Type, typename... Elms>
            struct replace_impl<Type<Elms...>&> {
                using type = Type<typename replace_if_placeholder<Elms>::type...>&;
            };
            template<template<typename...>class Type, typename... Elms>
            struct replace_impl<Type<Elms...>&&> {
                using type = Type<typename replace_if_placeholder<Elms>::type...>&&;
            };
            template<template<typename...>class Type, typename... Elms>
            struct replace_impl<const Type<Elms...>> {
                using type = const Type<typename replace_if_placeholder<Elms>::type...>;
            };
            template<template<typename...>class Type, typename... Elms>
            struct replace_impl<const Type<Elms...>&> {
                using type = const Type<typename replace_if_placeholder<Elms>::type...>&;
            };
            template<template<typename...>class Type, typename... Elms>
            struct replace_impl<const Type<Elms...>&&> {
                using type = const Type<typename replace_if_placeholder<Elms>::type...>&&;
            };
            template<typename T>
            struct replace_impl{ using type = T; };
            using type = typename replace_impl<Binded>::type;
        };
    }
    template<typename Binded, typename... Args>
    using replace = typename detail::replace_detail<Binded, Args...>::type;
    
    template<typename Binded>
    struct count;
    namespace detail{
        template<typename T, typename... Ts>
        struct count_placeholder;
        template<typename T, std::size_t Head, typename... Tails>
        struct count_placeholder<T, placeholder_t<Head>, Tails...>{
            static constexpr std::size_t value = count_placeholder<T, Tails...>::value + 1;
        };
        template<typename T, std::size_t Head, typename... Tails>
        struct count_placeholder<T, placeholder_t<Head>&, Tails...>{
            static constexpr std::size_t value = count_placeholder<T, Tails...>::value + 1;
        };
        template<typename T, std::size_t Head, typename... Tails>
        struct count_placeholder<T, placeholder_t<Head>&&, Tails...>{
            static constexpr std::size_t value = count_placeholder<T, Tails...>::value + 1;
        };
        template<typename T, std::size_t Head, typename... Tails>
        struct count_placeholder<T, const placeholder_t<Head>, Tails...>{
            static constexpr std::size_t value = count_placeholder<T, Tails...>::value + 1;
        };
        template<typename T, std::size_t Head, typename... Tails>
        struct count_placeholder<T, const placeholder_t<Head>&, Tails...>{
            static constexpr std::size_t value = count_placeholder<T, Tails...>::value + 1;
        };
        template<typename T, std::size_t Head, typename... Tails>
        struct count_placeholder<T, const placeholder_t<Head>&&, Tails...>{
            static constexpr std::size_t value = count_placeholder<T, Tails...>::value + 1;
        };
        template<typename T, typename Head, typename... Tails>
        struct count_placeholder<T, Head, Tails...>{
            static constexpr std::size_t value = count_placeholder<T, Tails...>::value + count<Head>::value;
        };
        template<typename T>
        struct count_placeholder<T>{
            static constexpr std::size_t value = 0;
        };
    }
    
    template<typename Binded>
    struct count{
        static constexpr std::size_t value = 0;
    };
    template<template<typename...>class Type, typename... Args>
    struct count<Type<Args...>>{
        static constexpr std::size_t value = detail::count_placeholder<void, Args...>::value;
    };
    template<template<typename...>class Type, typename... Args>
    struct count<Type<Args...>&>{
        static constexpr std::size_t value = detail::count_placeholder<void, Args...>::value;
    };
    template<template<typename...>class Type, typename... Args>
    struct count<Type<Args...>&&>{
        static constexpr std::size_t value = detail::count_placeholder<void, Args...>::value;
    };
    template<template<typename...>class Type, typename... Args>
    struct count<const Type<Args...>>{
        static constexpr std::size_t value = detail::count_placeholder<void, Args...>::value;
    };
    template<template<typename...>class Type, typename... Args>
    struct count<const Type<Args...>&>{
        static constexpr std::size_t value = detail::count_placeholder<void, Args...>::value;
    };
    template<template<typename...>class Type, typename... Args>
    struct count<const Type<Args...>&&>{
        static constexpr std::size_t value = detail::count_placeholder<void, Args...>::value;
    };
}
}