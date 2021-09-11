#pragma once
#include "integer_sequence.hpp"
#include "tuple_traits.hpp"
#include <tuple>

namespace tuptup {
#if __cplusplus >= 201703L
    template<typename F, typename T>
    decltype(auto) apply(F&& f, T&& tup) {
        return std::apply(std::forward<F>(f), std::forward<T>(tup));
    }
#elif __cplusplus >= 201402L
    namespace detail {
        template<typename F, typename Tuple, std::size_t... I>
        decltype(auto) apply_impl(F&& f, Tuple&& tup, integer_sequence<std::size_t, I...>&&) {
            return f(std::get<I>(std::forward<Tuple>(tup))...);
        }
    }

    template<typename F, typename T>
    decltype(auto) apply(F&& f, T&& tup) {
        return detail::apply_impl(std::forward<F>(f), std::forward<T>(tup), make_integer_sequence<std::size_t, tuple_size<typename std::remove_reference<T>::type>::value>{});
    }
#elif __cplusplus >= 201103L
    namespace detail {
        template<typename F, typename Tuple, std::size_t... I>
        auto apply_impl(F&& f, Tuple&& tup, integer_sequence<std::size_t, I...>&&)
            -> decltype(f(std::get<I>(std::forward<Tuple>(tup))...)){
            return f(std::get<I>(std::forward<Tuple>(tup))...);
        }
    }

    template<typename F, typename T>
    constexpr auto apply(F&& f, T&& tup)
        -> decltype(detail::apply_impl(std::forward<F>(f), std::forward<T>(tup), make_integer_sequence<std::size_t, tuple_size<typename std::remove_reference<T>::type>::value>{})) {
        return detail::apply_impl(std::forward<F>(f), std::forward<T>(tup), make_integer_sequence<std::size_t, tuple_size<typename std::remove_reference<T>::type>::value>{});
    }
#endif
    namespace detail {
        template<typename F, typename T, typename IntSeq>
        struct apply_each_impl;
        template<typename F, typename T, std::size_t... I>
        struct apply_each_impl<F, T, integer_sequence<std::size_t, I...>> {
            template<typename ElmType>
            using make_forward_type = typename std::conditional<std::is_lvalue_reference<T>::value,
                typename std::add_lvalue_reference<ElmType>::type,
                typename std::add_rvalue_reference<ElmType>::type
            >::type;

            using Tuple = typename std::remove_reference<T>::type;

            #if __cplusplus >= 201703L
            template<typename... ArgTypes>
            using invoke_result_t = std::invoke_result_t<F, ArgTypes...>;
            #else
            template<typename... Args>
            using invoke_result_t = typename std::result_of<F(Args...)>::type;
            #endif
            template<typename Damy, typename... Elms>
            struct call_result;
            template<typename Damy, typename Head, typename... Elms>
            struct call_result<Damy, Head, Elms...>{
                using type = tuple_cat_t<typename std::conditional<
                    std::is_same<invoke_result_t<Head>, void>::value,
                    std::tuple<>,
                    std::tuple<invoke_result_t<Head>>
                >::type, typename call_result<void, Elms...>::type>;
            };
            template<typename Damy>
            struct call_result<Damy>{
                using type = std::tuple<>;
            };

            using call_result_t = typename call_result<void, make_forward_type<typename std::tuple_element<I, Tuple>::type>...>::type;

            constexpr static std::tuple<> call_all(F& f){ return std::tuple<>{}; }
            template<typename Head,
                typename std::enable_if<std::is_same<invoke_result_t<Head>, void>::value, std::nullptr_t>::type = nullptr,
                typename... Tails
            >
            constexpr static auto call_all(F& f, Head&& head, Tails&&... tails)
                -> typename call_result<void, Head, Tails...>::type {
                return (f(std::forward<Head>(head)), call_all(f, std::forward<Tails>(tails)...));
            }
            template<typename Head,
                typename std::enable_if<!std::is_same<invoke_result_t<Head>, void>::value, std::nullptr_t>::type = nullptr,
                typename... Tails
            >
            constexpr static auto call_all(F& f, Head&& head, Tails&&... tails)
                -> typename call_result<void, Head, Tails...>::type {
                return tuple_cat(
                    make_tuple(f(std::forward<Head>(head))),
                    call_all(f, std::forward<Tails>(tails)...)
                );
            }

            template<typename Tup>
            constexpr auto operator()(F& f, Tup&& t) const -> call_result_t {
                return call_all(f, std::get<I>(std::forward<decltype(t)>(t))...);
            }
        };
    }
    template<typename F, typename T>
    constexpr auto apply_each(F&& f, T&& tup)
        -> decltype(detail::apply_each_impl<
            typename std::remove_reference<F>::type, T,
            make_integer_sequence<std::size_t, tuple_size<typename std::remove_reference<T>::type>::value>>{}(f, std::forward<T>(tup))) {
        return detail::apply_each_impl<
            typename std::remove_reference<F>::type, T,
            make_integer_sequence<std::size_t, tuple_size<typename std::remove_reference<T>::type>::value>>{}(f, std::forward<T>(tup));
    }
}
