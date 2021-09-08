#pragma once
#include <tuple>
#include "tuple_traits.hpp"
#include "standard_functions.hpp"
#include "integer_sequence.hpp"

namespace tuptup {
    namespace detail {
        template<template<typename>class F, typename T, typename enabler = void>
        struct apply_filter_t_impl;
        template<template<typename>class F, template<typename...>class TupleType, typename Head, typename... Tails>
        struct apply_filter_t_impl<F, TupleType<Head, Tails...>, typename std::enable_if<F<Head>::value>::type> {
            using type = tuple_cat_t<TupleType<Head>, apply_filter_t_impl<F, TupleType<Tails...>>>;
        };
        template<template<typename>class F, template<typename...>class TupleType, typename Head, typename... Tails>
        struct apply_filter_t_impl<F, TupleType<Head, Tails...>, typename std::enable_if<!(F<Head>::value)>::type> {
            using type = tuple_cat_t<TupleType<>, apply_filter_t_impl<F, TupleType<Tails...>>>;
        };
        template<template<typename>class F, template<typename...>class TupleType>
        struct apply_filter_t_impl<F, TupleType<>> {
            using type = TupleType<>;
        };

        /*
        template<template<typename>class F>
        auto apply_filter_impl() noexcept
            -> std::tuple<> {
            return std::make_tuple();
        }
        template<template<typename>class F, typename Head, typename std::enable_if<F<typename std::remove_reference<Head>::type>::value, std::nullptr_t>::type = nullptr, typename... Tails>
        auto apply_filter_impl(Head&& head, Tails&&... tails) noexcept
            -> typename apply_filter_t_impl<F, std::tuple<Head, Tails...>>::type {
            return std::tuple_cat(std::make_tuple(std::forward<Head>(head)), apply_filter_impl<F>(std::tuple<Tails...>{tails}...));
        }
        template<template<typename>class F, typename Head, typename std::enable_if<!(F<typename std::remove_reference<Head>::type>::value), std::nullptr_t>::type = nullptr, typename... Tails>
        auto apply_filter_impl(std::tuple<Head, Tails...> t) noexcept
            -> typename apply_filter_t_impl<F, std::tuple<Head, Tails...>>::type{
            return apply_filter_impl<F>(std::forward<Tails>(tails)...);
        }
        template<template<typename>class F, typename T, std::size_t... I>
        auto extract_for_apply_filter(T&& t, integer_sequence<std::size_t, I...>&&) noexcept
            -> decltype(apply_filter_impl<F>(std::get<I>(std::forward<T>(t))...)) {
            return apply_filter_impl<F>(std::get<I>(std::forward<T>(t))...);
        }
        */
    }

    template<template<typename>class F, typename T>
    using apply_filter_t = typename detail::apply_filter_t_impl<F, T>::type;

    /*
    template<template<typename>class F, typename T>
    auto apply_filter(T&& t) noexcept
        -> decltype(detail::extract_for_apply_filter<F>(std::forward<T>(t), make_integer_sequence<std::size_t, std::tuple_size<typename std::remove_reference<T>::type>::value>{})){
        return detail::extract_for_apply_filter<F>(std::forward<T>(t), make_integer_sequence<std::size_t, std::tuple_size<typename std::remove_reference<T>::type>::value>{});
    }
    */
}