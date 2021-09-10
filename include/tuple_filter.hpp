#pragma once
#include <tuple>
#include "tuple_traits.hpp"
#include "standard_functions.hpp"
#include "integer_sequence.hpp"

namespace tuptup {
    namespace detail {
        template<template<typename>class F, typename T, typename enabler = void>
        struct tuple_filter_t_impl;
        template<template<typename>class F, template<typename...>class TupleType, typename Head, typename... Tails>
        struct tuple_filter_t_impl<F, TupleType<Head, Tails...>, typename std::enable_if<F<Head>::value>::type> {
            using type = tuple_cat_t<TupleType<Head>, typename tuple_filter_t_impl<F, TupleType<Tails...>>::type>;
        };
        template<template<typename>class F, template<typename...>class TupleType, typename Head, typename... Tails>
        struct tuple_filter_t_impl<F, TupleType<Head, Tails...>, typename std::enable_if<!(F<Head>::value)>::type> {
            using type = typename tuple_filter_t_impl<F, TupleType<Tails...>>::type;
        };
        template<template<typename>class F, template<typename...>class TupleType>
        struct tuple_filter_t_impl<F, TupleType<>> {
            using type = TupleType<>;
        };

        template<template<typename>class F, typename T>
        struct make_bool_sequence;
        template<template<typename>class F, template<typename...>class TupleType, typename... Elms>
        struct make_bool_sequence<F, TupleType<Elms...>>{
            using type = integer_sequence<bool, F<Elms>::value...>;
        };
        
        template<typename BoolSeq>
        struct bool_sequence_to_index;
        template<bool... B>
        struct bool_sequence_to_index<integer_sequence<bool, B...>> {
            static constexpr std::array<bool, sizeof...(B)> bool_list = { B... };
            template<std::size_t N, typename IndexSeq, typename enabler = void>
            struct push_back;
            template<std::size_t N, typename IndexSeq>
            struct push_back<N, IndexSeq, typename std::enable_if<(N < sizeof...(B))>::type>{
                using type = typename push_back<N+1, typename std::conditional<bool_list[N], integer_sequence_push_back<IndexSeq, N>, IndexSeq>::type>::type;
            };
            template<std::size_t N, typename IndexSeq>
            struct push_back<N, IndexSeq, typename std::enable_if<(N >= sizeof...(B))>::type>{
                using type = IndexSeq;
            };

            using type = typename push_back<0, integer_sequence<std::size_t>>::type;
        };

        template<template<typename>class F, typename T, std::size_t... I>
        auto tuple_filter_impl(T&& tup, integer_sequence<std::size_t, I...>) noexcept
            -> typename tuple_filter_t_impl<F,  typename std::remove_reference<T>::type>::type{
            return std::make_tuple(std::get<I>(std::forward<T>(tup))...);
        }
    }

    template<template<typename>class F, typename T>
    using tuple_filter_t = typename detail::tuple_filter_t_impl<F, T>::type;

    template<template<typename>class F, typename T>
    auto tuple_filter(T&& tup) noexcept
        -> typename detail::tuple_filter_t_impl<F, typename std::remove_reference<T>::type>::type{
        using BoolSeq = typename detail::make_bool_sequence<F, typename std::remove_reference<T>::type>::type;
        return detail::tuple_filter_impl<F>(std::forward<T>(tup), typename detail::bool_sequence_to_index<BoolSeq>::type{});
    }
}