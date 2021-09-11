#pragma once
#include <tuple>

namespace tuptup {
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

    template<typename... Tuples>
    constexpr auto tuple_cat(Tuples&&... tups)
        ->decltype(std::tuple_cat(std::forward<Tuples>(tups)...)) {
        return std::tuple_cat(std::forward<Tuples>(tups)...);
    }

    template<std::size_t I, template<typename...>class TupleType, typename... Elms>
    constexpr auto get(TupleType<Elms...>&& tup) noexcept
        -> typename std::tuple_element<I, TupleType<Elms...>>::type&&{
        return std::get<I>(std::forward<decltype(tup)>(tup));
    }
    template<std::size_t I, template<typename...>class TupleType, typename... Elms>
    constexpr auto get(TupleType<Elms...>& tup) noexcept
        -> typename std::tuple_element<I, TupleType<Elms...>>::type&{
        return std::get<I>(tup);
    }

    template<typename T>
    auto tuple_front(T&& t) noexcept
        ->typename std::tuple_element<0, T>::type&&{
        return get<0>(std::forward<decltype(t)>(t));
    }
    template<typename T>
    constexpr auto tuple_front(T& t) noexcept
        ->typename std::tuple_element<0, T>::type&{
        return get<0>(t);
    }

    template<typename T>
    constexpr auto tuple_back(T&& t) noexcept
        -> typename std::tuple_element<0, T>::type&&{
        return std::get<std::tuple_size<T>::value - 1>(std::forward<decltype(t)>(t));
    }
    template<typename T>
    constexpr auto tuple_back(T& t) noexcept
        -> typename std::tuple_element<0, T>::type& {
        return std::get<std::tuple_size<T>::value - 1>(t);
    }
}