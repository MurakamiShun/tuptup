#pragma once
/*
 * tuptup: https://github.com/akisute514/tuptup/
 * Copyright (c) 2021 akisute514
 * 
 * Released under the MIT Lisence.
 */

#include "integer_sequence.hpp"
#include "tuple_traits.hpp"

namespace tuptup {
#if (defined(__cplusplus) && __cplusplus >= 201703L) || (defined(_MSVC_LANG) && _MSVC_LANG >= 201703L)
    template<typename F, typename T>
    decltype(auto) apply(F&& f, T&& tup) {
        return std::apply(std::forward<F>(f), std::forward<T>(tup));
    }
#elif (defined(__cplusplus) && __cplusplus >=201402L) || (defined(_MSVC_LANG) && _MSVC_LANG >= 201402L)
    namespace detail {
        template<typename F, typename Tuple, std::size_t... I>
        decltype(auto) apply_impl(F&& f, Tuple&& tup, integer_sequence<std::size_t, I...>&&) {
            return f(std::get<I>(std::forward<Tuple>(tup))...);
        }
    }

    template<typename F, typename T>
    decltype(auto) apply(F&& f, T&& tup) {
        return detail::apply_impl(std::forward<F>(f), std::forward<T>(tup), make_integer_sequence<std::size_t, tuple_size<typename std::remove_reference<T>::type>::value>{});
    }
#elif (defined(__cplusplus) && __cplusplus >= 201103L) || defined(_MSC_VER)
    namespace detail {
        template<typename F, typename Tuple, std::size_t... I>
        auto apply_impl(F&& f, Tuple&& tup, integer_sequence<std::size_t, I...>&&)
            -> decltype(f(std::get<I>(std::forward<Tuple>(tup))...)){
            return f(std::get<I>(std::forward<Tuple>(tup))...);
        }
    }

    template<typename F, typename T>
    constexpr auto apply(F&& f, T&& tup)
        -> decltype(detail::apply_impl(std::forward<F>(f), std::forward<T>(tup), make_integer_sequence<std::size_t, tuple_size<typename std::remove_reference<T>::type>::value>{})) {
        return detail::apply_impl(std::forward<F>(f), std::forward<T>(tup), make_integer_sequence<std::size_t, tuple_size<typename std::remove_reference<T>::type>::value>{});
    }
#endif
}
