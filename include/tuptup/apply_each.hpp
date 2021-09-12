#pragma once
#include "integer_sequence.hpp"
#include "tuple_traits.hpp"
#include "standard_functions.hpp"

namespace tuptup{
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

            constexpr static std::tuple<> call_all(F& f){ return std::tuple<>{}; }
            template<typename Head,
                typename std::enable_if<std::is_same<invoke_result_t<Head>, void>::value, std::nullptr_t>::type = nullptr,
                typename... Tails>
            constexpr static auto call_all(F& f, Head&& head, Tails&&... tails)
                -> typename call_result<void, Head, Tails...>::type {
                return (f(std::forward<Head>(head)), call_all(f, std::forward<Tails>(tails)...));
            }
            template<typename Head,
                typename std::enable_if<!std::is_same<invoke_result_t<Head>, void>::value, std::nullptr_t>::type = nullptr,
                typename... Tails>
            constexpr static auto call_all(F& f, Head&& head, Tails&&... tails)
                -> typename call_result<void, Head, Tails...>::type {
                return tuptup::tuple_cat(
                    tuptup::make_tuple(f(std::forward<Head>(head))),
                    call_all(f, std::forward<Tails>(tails)...)
                );
            }

            template<typename Tup>
            constexpr auto operator()(F& f, Tup&& t) const
                -> typename call_result<void, make_forward_type<typename std::tuple_element<I, Tuple>::type>...>::type {
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