#pragma once
#include "integer_sequence.hpp"
#include "tuple_traits.hpp"
#include <tuple>

namespace tuptup{
        namespace detail {
        template<typename F, typename T, typename IntSeq>
        struct indexed_apply_each_impl;
        template<typename F, typename T, std::size_t... I>
        struct indexed_apply_each_impl<F, T, integer_sequence<std::size_t, I...>> {
            template<std::size_t N, typename Elm>
            constexpr static auto call(F& f, Elm&& elm, int)
                -> decltype(make_tuple(f.template operator()<N>(std::forward<Elm>(elm)))) {
                return make_tuple(f.template operator()<N>(std::forward<Elm>(elm)));
            }
            template<std::size_t N, typename Elm>
            constexpr static std::tuple<> call(F& f, Elm&& elm, char) {
                return (f.template operator()<N>(std::forward<Elm>(elm)), std::tuple<>{});
            }

            template<typename Tup>
            constexpr auto operator()(F& f, Tup&& t) const
                -> decltype(tuple_cat(call<I>(f, std::get<I>(std::forward<Tup>(t)), 0)...)) {
                return tuple_cat(call<I>(f, std::get<I>(std::forward<Tup>(t)), 0)...); // expression evaluation order is undefined
            }
        };
    }
    template<typename F, typename T>
    constexpr auto indexed_apply_each(F&& f, T&& tup)
        -> decltype(detail::indexed_apply_each_impl<
            typename std::remove_reference<F>::type, T,
            make_integer_sequence<std::size_t, tuple_size<typename std::remove_reference<T>::type>::value>>{}(f, std::forward<T>(tup))) {
        return detail::indexed_apply_each_impl<
            typename std::remove_reference<F>::type, T,
            make_integer_sequence<std::size_t, tuple_size<typename std::remove_reference<T>::type>::value>>{}(f, std::forward<T>(tup));
    }
}