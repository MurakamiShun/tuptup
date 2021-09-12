#pragma once
#include "integer_sequence.hpp"
#include "tuple_traits.hpp"
#include "standard_functions.hpp"
#include <tuple>

namespace tuptup{
        namespace detail {
        template<typename F, typename T, typename IntSeq>
        struct indexed_apply_each_impl;
        template<typename F, typename T, std::size_t... I>
        struct indexed_apply_each_impl<F, T, integer_sequence<std::size_t, I...>> {
            template<std::size_t N, typename Elm>
            constexpr static auto call(F& f, Elm&& elm, int)
                -> decltype(tuptup::make_tuple(f.template operator()<N>(std::forward<Elm>(elm))));
            template<std::size_t N, typename Elm>
            constexpr static std::tuple<> call(F& f, Elm&& elm, char);

            template<typename Tup, std::size_t Head, typename NextBuff, std::size_t... Tails>
            constexpr static auto call_all(F& f, Tup&& tup, integer_sequence<std::size_t, Head, Tails...>, NextBuff buff, int)
                -> decltype(typename std::enable_if<(sizeof...(Tails)>0), std::nullptr_t>::type{}, tuptup::tuple_cat(
                    tuptup::make_tuple(f.template operator()<Head>(std::get<Head>(std::forward<Tup>(tup)))),
                    call<Tails>(f, std::get<Tails>(std::forward<Tup>(tup)), 0)...
                )) {
                return (buff = f.template operator()<Head>(std::get<Head>(std::forward<Tup>(tup))),
                tuptup::tuple_cat(
                    tuptup::make_tuple(std::move(buff)),
                    call_all(
                        f, std::forward<Tup>(tup), integer_sequence<std::size_t, Tails...>{},
                        decltype(f.template operator()<Head+1>(std::get<Head+1>(std::forward<Tup>(tup)))){}, 0
                    )
                ));
            }
            template<typename Tup, std::size_t Head, typename NextBuff, std::size_t... Tails>
            constexpr static auto call_all(F& f, Tup&& tup, integer_sequence<std::size_t, Head, Tails...>, NextBuff, char)
                -> decltype(typename std::enable_if<(sizeof...(Tails)>0), std::nullptr_t>::type{}, tuptup::tuple_cat(
                    call<Tails>(f, std::get<Tails>(std::forward<Tup>(tup)), 0)...
                )) {
                return (f.template operator()<Head>(std::get<Head>(std::forward<Tup>(tup))),
                call_all(
                    f, std::forward<Tup>(tup), integer_sequence<std::size_t, Tails...>{},
                    decltype(f.template operator()<Head+1>(std::get<Head+1>(std::forward<Tup>(tup)))){},0
                ));
            }
            template<typename Tup, std::size_t Head, typename NextBuff, std::size_t... Tails>
            constexpr static auto call_all(F& f, Tup&& tup, integer_sequence<std::size_t, Head, Tails...>, NextBuff, int)
                -> decltype(typename std::enable_if<(sizeof...(Tails) == 0), std::nullptr_t>::type{}, tuptup::tuple_cat(
                    tuptup::make_tuple(f.template operator()<Head>(std::get<Head>(std::forward<Tup>(tup)))),
                    call<Tails>(f, std::get<Tails>(std::forward<Tup>(tup)), 0)...
                )) {
                return tuptup::make_tuple(f.template operator()<Head>(std::get<Head>(std::forward<Tup>(tup))));
            }
            template<typename Tup, std::size_t Head, typename NextBuff, std::size_t... Tails>
            constexpr static auto call_all(F& f, Tup&& tup, integer_sequence<std::size_t, Head, Tails...>, NextBuff, char)
                -> decltype(typename std::enable_if<(sizeof...(Tails) == 0), std::nullptr_t>::type{}, tuptup::tuple_cat(
                    call<Tails>(f, std::get<Tails>(std::forward<Tup>(tup)), 0)...
                )) {
                return (f.template operator()<Head>(std::get<Head>(std::forward<Tup>(tup))), std::tuple<>{});
            }

            template<typename Tup>
            constexpr auto operator()(F& f, Tup&& t) const
                -> decltype(call_all(f, std::forward<Tup>(t), integer_sequence<std::size_t, I...>{},
                    decltype(f.template operator()<0>(std::get<0>(std::forward<Tup>(t)))){},0)) {
                return call_all(f, std::forward<Tup>(t), integer_sequence<std::size_t, I...>{},
                    decltype(f.template operator()<0>(std::get<0>(std::forward<Tup>(t)))){}, 0);
            }
        };
    }
    template<typename F, typename T>
    constexpr auto indexed_apply_each(F&& f, T&& tup)
        -> decltype(detail::indexed_apply_each_impl<
            typename std::remove_reference<F>::type, T,
            make_integer_sequence<std::size_t, tuple_size<typename std::remove_reference<T>::type>::value>>{}(f, std::forward<T>(tup))) {
        return detail::indexed_apply_each_impl<
            typename std::remove_reference<F>::type, T,
            make_integer_sequence<std::size_t, tuple_size<typename std::remove_reference<T>::type>::value>>{}(f, std::forward<T>(tup));
    }
}