#pragma once
#include "integer_sequence.hpp"
#include "tuple_traits.hpp"
#include <tuple>

namespace tuptup {
#if __cplusplus >= 201703L
    template<typename F, typename T>
    decltype(auto) apply(F&& f, T&& tup) {
        return std::apply(std::forward<F>(f), std::forward<T>(tup));
    }
#elif __cplusplus >= 201402L
    namespace detail {
        template<typename F, typename Tuple, std::size_t... I>
        decltype(auto) apply_impl(F&& f, Tuple&& tup, integer_sequence<std::size_t, I...>&&) {
            return f(std::get<I>(tup)...);
        }
    }

    template<typename F, typename T>
    decltype(auto) apply(F&& f, T&& tup) {
        return detail::apply_impl(std::forward<F>(f), std::forward<T>(tup), make_integer_sequence<std::size_t, tuple_size<typename std::remove_reference<T>::type>::value>{});
    }
#elif __cplusplus >= 201103L
    namespace detail {
        template<typename F, typename Tuple, std::size_t... I>
        auto apply_impl(F&& f, Tuple&& tup, integer_sequence<std::size_t, I...>&&)
            -> decltype(f(std::get<I>(tup)...)){
            return f(std::get<I>(tup)...);
        }
    }

    template<typename F, typename T>
    constexpr auto apply(F&& f, T&& tup)
        -> decltype(detail::apply_impl(std::forward<F>(f), std::forward<T>(tup), make_integer_sequence<std::size_t, tuple_size<typename std::remove_reference<T>::type>::value>{})) {
        return detail::apply_impl(std::forward<F>(f), std::forward<T>(tup), make_integer_sequence<std::size_t, tuple_size<typename std::remove_reference<T>::type>::value>{});
    }
#endif
    namespace detail {
        template<typename F, typename T, typename IntSeq>
        struct apply_each_impl;
        template<typename F, typename T, std::size_t... I>
        struct apply_each_impl<F, T, integer_sequence<std::size_t, I...>> {

            constexpr static void call_all(F&& f){}
            template<typename Head, typename... Tails>
            constexpr static void call_all(F&& f, Head&& head, Tails&&... tails){
                f(std::forward<Head>(head));
                call_all(std::forward<F>(f), std::forward<Tails>(tails)...);
            }

            /*
            template<std::size_t N>
            using call_result_t = decltype(std::declval<F>()(std::declval<typename std::tuple_element<N, T>::type>()));

            template<template<typename...>class TupleType, typename... Elms>
            auto operator()(F&& f, TupleType<Elms...>&& t) const
                -> decltype(std::declval<TupleType<call_result_t<I>...>>()){
                //call_all(std::forward<F>(f), std::get<I>(std::forward<TupleType<Elms...>&&>(t))...);
            }
            template<template<typename...>class TupleType, typename... Elms>
            auto operator()(F&& f, TupleType<Elms...>& t) const
                -> decltype(std::declval<TupleType<call_result_t<I>...>>()){
                //call_all(std::forward<F>(f), std::get<I>(std::forward<decltype(t)>(t))...);
            }
            */

            void operator()(F&& f, T&& t) const {
                call_all(std::forward<F>(f), std::get<I>(std::forward<decltype(t)>(t))...);
            }
        };
    }
    template<typename F, typename T>
    constexpr auto apply_each(F&& f, T&& tup)
        -> decltype(detail::apply_each_impl<
            F, T,
            make_integer_sequence<std::size_t, tuple_size<typename std::remove_reference<T>::type>::value>>{}(std::forward<decltype(f)>(f), std::forward<decltype(tup)>(tup))) {
        return detail::apply_each_impl<
            F, T,
            make_integer_sequence<std::size_t, tuple_size<typename std::remove_reference<T>::type>::value>>{}(std::forward<decltype(f)>(f), std::forward<decltype(tup)>(tup));
    }
}
