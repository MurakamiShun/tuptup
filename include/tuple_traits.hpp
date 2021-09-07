#pragma once
#include <tuple>

namespace tuptup {
	template<typename T>
	using tuple_size = std::tuple_size<T>;

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
	
	template<std::size_t I, template<typename...>class TupleType, typename... Elms>
	auto get(TupleType<Elms...>&& tup) noexcept
		-> typename tuple_element<I, TupleType<Elms...>>::type&&{
		return std::get<I>(std::forward<decltype(tup)>(tup));
	}
	template<std::size_t I, template<typename...>class TupleType, typename... Elms>
	auto get(TupleType<Elms...>& tup) noexcept
		-> typename tuple_element<I, TupleType<Elms...>>::type&{
		return std::get<I>(tup);
	}

	template<typename T>
	auto tuple_front(T&& t) noexcept
		->typename tuple_element<0, T>::type&&{
		return get<0>(std::forward<decltype(t)>(t));
	}
	template<typename T>
	auto tuple_front(T& t) noexcept
		->typename tuple_element<0, T>::type&{
		return get<0>(t);
	}
	template<typename T>
	using tuple_front_t = typename tuple_element<0, T>::type;

	template<typename T>
	auto tuple_back(T&& t) noexcept
		-> typename tuple_element<0, T>::type&&{
		return get<tuple_size<T>::value - 1>(std::forward<decltype(t)>(t));
	}
	template<typename T>
	auto tuple_back(T& t) noexcept
		-> typename tuple_element<0, T>::type& {
		return get<tuple_size<T>::value - 1>(t);
	}
	template<typename T>
	using tuple_back_t = typename tuple_element<tuple_size<T>::value - 1, T>::type;
}