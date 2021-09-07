#pragma once
#include "integer_sequence.hpp"
#include <tuple>

namespace tuptup {
#if __cplusplus >= 201703L
	template<typename F, typename T>
	decltype(auto) apply(F&& f, T&& tup) {
		return std::apply(std::forward<F>(f), std::forward<T>(tup));
	}
#elif __cplusplus >= 201402L
	namespace impl {
		template<typename F, typename Tuple, std::size_t... I>
		decltype(auto) apply_impl(F&& f, Tuple&& tup, integer_sequence<std::size_t, I...>&&) {
			return f(std::get<I>(tup)...);
		}
	}

	template<typename F, typename T>
	decltype(auto) apply(F&& f, T&& tup) {
		return impl::apply_impl(std::forward<F>(f), std::forward<T>(tup), make_integer_sequence<std::size_t, std::tuple_size<typename std::remove_reference<T>::type>::value>{});
	}
#elif __cplusplus >= 201103L
	namespace impl {
		template<typename F, typename Tuple, std::size_t... I>
		auto apply_impl(F&& f, Tuple&& tup, integer_sequence<std::size_t, I...>&&)
			-> decltype(f(std::get<I>(tup)...)){
			return f(std::get<I>(tup)...);
		}
	}

	template<typename F, typename T>
	auto apply(F&& f, T&& tup)
		-> decltype(impl::apply_impl(std::forward<F>(f), std::forward<T>(tup), make_integer_sequence<std::size_t, std::tuple_size<typename std::remove_reference<T>::type>::value>{})) {
		return impl::apply_impl(std::forward<F>(f), std::forward<T>(tup), make_integer_sequence<std::size_t, std::tuple_size<typename std::remove_reference<T>::type>::value>{});
	}
#endif
	namespace detail {
		template<typename F, typename T, typename IntSeq>
		struct apply_each_impl;
		template<typename F, typename T, std::size_t... I>
		struct apply_each_impl<F, T, integer_sequence<std::size_t, I...>> {
			template<typename Input>
			using invoke_result_t = decltype(F{}(std::declval<Input>()));
			template<template<typename...>class TupleType, typename... Elms>
			auto operator()(F&& f, TupleType<Elms...>&& t) const
				-> TupleType<invoke_result_t<Elms>...> {
				return std::make_tuple(f(std::get<I>(t))...);
			}
		};
	}
	template<typename F, typename T>
	constexpr auto apply_each(F&& f, T&& tup)
		-> decltype(apply_each_impl(std::forward<decltype(f)>(f), std::forward<decltype(tup)>(tup))){
		return apply_each_impl(std::forward<decltype(f)>(f), std::forward<decltype(tup)>(tup));
	}
}
