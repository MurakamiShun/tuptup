#pragma once
#include <tuple>
#include "tuple_traits.hpp"
#include "standard_functions.hpp"
#include "integer_sequence.hpp"

namespace tuptup {
    namespace detail {
        /*
        template<template<typename>class F, template<typename...>class TupleType, typename... Elms>
        auto apply_filter_impl(Tuple_type<Elms...>&& tup) noexcept{
            return integer_sequence<bool, F<Elms>::value...>{};
        }*/
    }

    template<template<typename>class F, typename T, typename enabler = void>
    struct tuple_filter;
    template<template<typename>class F, template<typename...>class TupleType, typename Head, typename... Tails>
    struct tuple_filter<F, TupleType<Head, Tails...>, typename std::enable_if<F<Head>::value>::type> {
        using type = tuple_cat_t<TupleType<Head>, tuple_filter<F, TupleType<Tails...>>>;
    };
    template<template<typename>class F, template<typename...>class TupleType, typename Head, typename... Tails>
    struct tuple_filter<F, TupleType<Head, Tails...>, typename std::enable_if<!(F<Head>::value)>::type> {
        using type = tuple_cat_t<TupleType<>, tuple_filter<F, TupleType<Tails...>>>;
    };
    template<template<typename>class F, template<typename...>class TupleType>
    struct tuple_filter<F, TupleType<>> {
        using type = TupleType<>;
    };

    template<template<typename>class F, typename T>
    using tuple_filter_t = typename tuple_filter<F, T>::type;
    /*
    template<template<typename>class F, typename T>
    auto apply_filter(T&& t) noexcept
        -> decltype(detail::apply_filter_impl<F, 0>(std::forward<T>(t))){
        return detail::apply_filter_impl<F, 0>(std::forward<T>(t));
    }*/
}