#pragma once
#include "integer_sequence.hpp"

namespace tuptup {
    namespace detail {
        template<typename T, typename IntSeq>
        struct tuple_slice_impl;
        template<typename T, typename Int, Int... I>
        struct tuple_slice_impl<T, integer_sequence<Int, I...>> {
            using type = std::tuple<typename std::tuple_element<I, T>::type...>;
        };
    }

    template<typename IntSeq, typename T>
    using tuple_slice_t = typename detail::tuple_slice_impl<T, IntSeq>::type;
}