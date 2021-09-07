#pragma once
#include <tuple>

namespace tuptup {
    template<typename T>
    struct tuple_size;
    template<template<typename...>class TupleType, typename... Elems>
    struct tuple_size<TupleType<Elems...>>{
        constexpr static std::size_t value = sizeof...(Elems);
    };
    

    template<typename... Tuples>
    auto tuple_cat(Tuples&&... tups)
        ->decltype(std::tuple_cat(std::forward<Tuples>(tups)...)) {
        return std::tuple_cat(std::forward<Tuples>(tups)...);
    }
    template<typename... Tuples>
    using tuple_cat_t = decltype(tuple_cat(std::declval<Tuples>()...));

    template<std::size_t I, typename T>
    using tuple_element = std::tuple_element<I, T>;
    template<std::size_t I, typename T>
    using tuple_element_t = typename std::tuple_element<I, T>::type;

    template<typename T>
    using tuple_front_t = typename tuple_element<0, T>::type;

    template<typename T>
    using tuple_back_t = typename tuple_element<tuple_size<T>::value - 1, T>::type;
}