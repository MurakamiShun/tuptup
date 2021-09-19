#pragma once
#include <tuple>
#include "placeholder_t.hpp"

namespace tuptup {
    template<typename T>
    struct tuple_size;
    template<template<typename...>class TupleType, typename... Elems>
    struct tuple_size<TupleType<Elems...>>{
        constexpr static std::size_t value = sizeof...(Elems);
    };

    template<typename... Elms>
    using tuple = std::tuple<Elms...>;
    
    template<typename... Tuples>
    using tuple_cat_t = decltype(std::tuple_cat(std::declval<Tuples>()...));

    template<std::size_t I, typename T>
    using tuple_element = std::tuple_element<I, T>;
    template<std::size_t I, typename T>
    using tuple_element_t = typename std::tuple_element<I, T>::type;

    template<typename T>
    using tuple_front_t = typename tuple_element<0, T>::type;

    template<typename T>
    using tuple_back_t = typename tuple_element<tuple_size<T>::value - 1, T>::type;

    template<typename F, typename T, typename enabler = void>
    struct apply_type;
    template<typename F, template<typename...>class TupleType, typename... Elms>
    struct apply_type<F, TupleType<Elms...>, typename std::enable_if<placeholder_t_count<F>::value == 1>::type>{
        using type = TupleType<typename replace<F, Elms>::type...>;
    };

    template<typename F, typename T, typename std::enable_if<placeholder_t_count<F>::value == 1, std::nullptr_t>::type = nullptr>
    using apply_type_t = typename apply_type<F, T>::type;
}