#pragma once
#include <tuple>

namespace tuptup {
	template<typename... Elms>
	using tuple = std::tuple<Elms...>;

	template<typename... Types>
	constexpr auto make_tuple(Types&&... args)
		-> decltype(std::make_tuple(std::forward<Types>(args)...)) {
		return std::make_tuple(std::forward<Types>(args)...);
	}
	template<typename... Types>
	constexpr auto tie(Types&... args) noexcept
		->decltype(std::tie(args...)) {
		return std::tie(args...);
	}
	template<typename... Types>
	constexpr auto forward_as_tuple(Types&&... args) noexcept
		-> decltype(std::forward_as_tuple(std::forward<Types>(args)...)) {
		return std::forward_as_tuple(std::forward<Types>(args)...);
	}
}