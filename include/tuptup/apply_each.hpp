#pragma once
#include "integer_sequence.hpp"
#include "tuple_traits.hpp"
#include "standard_functions.hpp"

namespace tuptup{
    namespace detail {
        template<typename F, typename IntSeq>
        struct apply_each_impl;
        template<typename F, std::size_t... I>
        struct apply_each_impl<F, integer_sequence<std::size_t, I...>> {
            template<typename V>
            using convert_to_constructible = typename std::conditional<std::is_same<V, void>::value, std::false_type, V>::type;

            template<std::size_t N, typename Elm>
            constexpr static auto call(F& f, Elm&& elm, int)
                -> decltype(tuptup::make_tuple(f(std::forward<Elm>(elm))));
            template<std::size_t N, typename Elm>
            constexpr static std::tuple<> call(F& f, Elm&& elm, char);

            template<typename Tup, std::size_t Head, typename NextBuff, std::size_t... Tails>
            constexpr static auto call_all(F& f, Tup&& tup, integer_sequence<std::size_t, Head, Tails...>, NextBuff buff, int)
                -> decltype(typename std::enable_if<(sizeof...(Tails)>0), std::nullptr_t>::type{}, tuptup::tuple_cat(
                    tuptup::make_tuple(f(std::get<Head>(std::forward<Tup>(tup)))),
                    call<Tails>(f, std::get<Tails>(std::forward<Tup>(tup)), 0)...
                )) {
                return (buff = f(std::get<Head>(std::forward<Tup>(tup))),
                tuptup::tuple_cat(
                    tuptup::make_tuple(std::move(buff)),
                    call_all(
                        f, std::forward<Tup>(tup), integer_sequence<std::size_t, Tails...>{},
                        convert_to_constructible<decltype(f(std::get<Head+1>(std::forward<Tup>(tup))))>{}, 0
                    )
                ));
            }
            template<typename Tup, std::size_t Head, typename NextBuff, std::size_t... Tails>
            constexpr static auto call_all(F& f, Tup&& tup, integer_sequence<std::size_t, Head, Tails...>, NextBuff, char)
                -> decltype(typename std::enable_if<(sizeof...(Tails)>0), std::nullptr_t>::type{}, tuptup::tuple_cat(
                    call<Tails>(f, std::get<Tails>(std::forward<Tup>(tup)), 0)...
                )) {
                return (f(std::get<Head>(std::forward<Tup>(tup))),
                call_all(
                    f, std::forward<Tup>(tup), integer_sequence<std::size_t, Tails...>{},
                    convert_to_constructible<decltype(f(std::get<Head+1>(std::forward<Tup>(tup))))>{},0
                ));
            }
            template<typename Tup, std::size_t Head, typename NextBuff, std::size_t... Tails>
            constexpr static auto call_all(F& f, Tup&& tup, integer_sequence<std::size_t, Head, Tails...>, NextBuff, int)
                -> decltype(typename std::enable_if<(sizeof...(Tails) == 0), std::nullptr_t>::type{}, tuptup::tuple_cat(
                    tuptup::make_tuple(f(std::get<Head>(std::forward<Tup>(tup)))),
                    call<Tails>(f, std::get<Tails>(std::forward<Tup>(tup)), 0)...
                )) {
                return tuptup::make_tuple(f(std::get<Head>(std::forward<Tup>(tup))));
            }
            template<typename Tup, std::size_t Head, typename NextBuff, std::size_t... Tails>
            constexpr static auto call_all(F& f, Tup&& tup, integer_sequence<std::size_t, Head, Tails...>, NextBuff, char)
                -> decltype(typename std::enable_if<(sizeof...(Tails) == 0), std::nullptr_t>::type{}, tuptup::tuple_cat(
                    call<Tails>(f, std::get<Tails>(std::forward<Tup>(tup)), 0)...
                )) {
                return (f(std::get<Head>(std::forward<Tup>(tup))), std::tuple<>{});
            }

            template<typename Tup>
            constexpr auto operator()(F& f, Tup&& t) const
                -> decltype(call_all(f, std::forward<Tup>(t), integer_sequence<std::size_t, I...>{},
                    convert_to_constructible<decltype(f(std::get<0>(std::forward<Tup>(t))))>{}, 0)) {
                return call_all(f, std::forward<Tup>(t), integer_sequence<std::size_t, I...>{},
                    convert_to_constructible<decltype(f(std::get<0>(std::forward<Tup>(t))))>{}, 0);
            }
        };
    }
    template<typename F, typename T>
    constexpr auto apply_each(F&& f, T&& tup)
        -> decltype(detail::apply_each_impl<
            typename std::remove_reference<F>::type,
            make_integer_sequence<std::size_t, tuple_size<typename std::remove_reference<T>::type>::value>>{}(f, std::forward<T>(tup))) {
        return detail::apply_each_impl<
            typename std::remove_reference<F>::type,
            make_integer_sequence<std::size_t, tuple_size<typename std::remove_reference<T>::type>::value>>{}(f, std::forward<T>(tup));
    }
}