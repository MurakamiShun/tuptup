#pragma once
namespace tuptup {
    template<template<typename>class F, typename T>
    struct apply_to_types;
    template<template<typename>class F, template<typename...>class TupleType, typename... Elms>
    struct apply_to_types<F, TupleType<Elms...>>{
        using type = TupleType<typename F<Elms>::type...>;
    };

	template<template<typename>class F, typename T>
	using apply_to_types_t = typename apply_to_types<F, T>::type;
}