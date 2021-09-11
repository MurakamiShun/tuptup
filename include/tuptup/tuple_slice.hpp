#pragma once
#include "integer_sequence.hpp"
#include "tuple_traits.hpp"

namespace tuptup {
    namespace detail {
        template<typename IntSeq, typename T>
        struct tuple_slice_impl;
        template<typename T, typename Int, Int... I>
        struct tuple_slice_impl<integer_sequence<Int, I...>, T> {
            using type = std::tuple<typename std::tuple_element<I, T>::type...>;
        };

        template<typename Int, typename T, Int... I>
        constexpr auto tuple_slice_func_impl(integer_sequence<Int, I...>, T&& tup)
            -> decltype(std::make_tuple(std::get<I>(std::forward<T>(tup))...)){
            return std::make_tuple(std::get<I>(std::forward<T>(tup))...);
        }
    }

    template<typename IntSeq, typename T>
    using tuple_slice_t = typename detail::tuple_slice_impl<IntSeq, T>::type;

    template<typename IntSeq, typename T>
    constexpr auto tuple_slice(T&& tup)
        -> typename detail::tuple_slice_impl<IntSeq, typename std::remove_reference<T>::type>::type {
        return detail::tuple_slice_func_impl(IntSeq{}, std::forward<T>(tup));
    }
}