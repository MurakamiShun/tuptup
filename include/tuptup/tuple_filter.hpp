#pragma once
#include <tuple>
#include <array>
/*
 * tuptup: https://github.com/akisute514/tuptup/
 * Copyright (c) 2021 akisute514
 * 
 * Released under the MIT License.
 */

#include "tuple_slice.hpp"
#include "type_placeholders.hpp"

namespace tuptup {
    namespace detail {
        template<typename F, typename T>
        struct make_bool_sequence;
        template<typename F, template<typename...>class TupleType, typename... Elms>
        struct make_bool_sequence<F, TupleType<Elms...>>{
            using type = integer_sequence<bool, static_cast<bool>(type_placeholders::replace<F, Elms>::value)...>;
        };
        template<typename F, template<typename...>class TupleType, typename... Elms>
        struct make_bool_sequence<F, const TupleType<Elms...>>{
            using type = integer_sequence<bool, static_cast<bool>(type_placeholders::replace<F, Elms>::value)...>;
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
    }

    template<typename F, typename T>
    constexpr auto tuple_filter(T&& tup)
        -> decltype(tuple_slice<typename detail::bool_sequence_to_index<typename detail::make_bool_sequence<F, typename std::remove_reference<T>::type>::type>::type>(std::forward<T>(tup))){
        using BoolSeq = typename detail::make_bool_sequence<F, typename std::remove_reference<T>::type>::type;
        return tuple_slice<typename detail::bool_sequence_to_index<BoolSeq>::type>(std::forward<T>(tup));
    }

    template<typename F, typename T>
    using tuple_filter_t = decltype(tuple_filter<F>(std::declval<T>()));
}