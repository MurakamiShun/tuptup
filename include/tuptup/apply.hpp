#pragma once
#include "integer_sequence.hpp"
#include "tuple_traits.hpp"

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
            return f(std::get<I>(std::forward<Tuple>(tup))...);
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
