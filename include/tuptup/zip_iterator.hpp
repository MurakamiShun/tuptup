#pragma once
#include <iterator>
/*
 * tuptup: https://github.com/akisute514/tuptup/
 * Copyright (c) 2022 akisute514
 * 
 * Released under the MIT License.
 */
#include "apply_each.hpp"
#include "integer_sequence.hpp"

namespace tuptup{
template<typename IterList>
struct zip_iterator;

template<typename ZipIterator>
struct zip_iterator_reference_tuple_impl;

template<typename... Iterators>
struct zip_iterator<tuple<Iterators...>>{
public:
    using difference_type = std::ptrdiff_t;
    using value_type = tuple<typename Iterators::value_type...>;
    using reference = zip_iterator_reference_tuple_impl<zip_iterator<tuple<Iterators...>>>;
    using pointer = tuple<typename Iterators::value_type*...>;
    using iterator_category = std::random_access_iterator_tag;
    using iterator_tuple = tuple<Iterators...>;
    static constexpr auto iterator_tuple_size_v = sizeof...(Iterators);
private:
    iterator_tuple iters;
public:
    explicit zip_iterator(iterator_tuple&);
    explicit zip_iterator(const iterator_tuple&);
    explicit zip_iterator(iterator_tuple&&);

    difference_type operator-(const zip_iterator&);
    zip_iterator operator-(difference_type);
    zip_iterator operator+(difference_type);

    zip_iterator& operator++();
    zip_iterator& operator--();

    bool operator==(const zip_iterator&) const;
    bool operator!=(const zip_iterator&) const;
    bool operator<(const zip_iterator&) const;

    reference operator*();
};

#if __cplusplus >= 201703L
template<typename... Iterators>
zip_iterator(tuple<Iterators...>)->zip_iterator<tuple<Iterators...>>;
#endif

template<typename... Iterators>
zip_iterator<tuple<Iterators...>> make_zip_iterator(Iterators&&...);

template<typename ZipIterator>
void swap(zip_iterator_reference_tuple_impl<ZipIterator>, zip_iterator_reference_tuple_impl<ZipIterator>); // Customization Point

/*--- Implementations ---*/

template<typename... Iterators>
struct zip_iterator_reference_tuple_impl<zip_iterator<tuple<Iterators...>>> : tuple<typename Iterators::reference...>{
    using tuple<typename Iterators::reference...>::tuple;
    using tuple<typename Iterators::reference...>::operator=;
    using tuple_type = tuple<typename Iterators::reference...>;
    zip_iterator_reference_tuple_impl(tuple<typename Iterators::reference...>&& t) : tuple<typename Iterators::reference...>(std::move(t)){}
};

template<typename... Iterators>
zip_iterator<tuple<Iterators...>>::zip_iterator(iterator_tuple& it):
iters(it){
}

template<class... Iterators>
zip_iterator<tuple<Iterators...>>::zip_iterator(const iterator_tuple& it):
iters(it){
}
template<class... Iterators>
zip_iterator<tuple<Iterators...>>::zip_iterator(iterator_tuple&& it):
iters(std::move(it)){
}

template<class... Iterators>
typename zip_iterator<tuple<Iterators...>>::difference_type zip_iterator<tuple<Iterators...>>::operator-(const zip_iterator& z_it){
    return std::get<0>(iters) - std::get<0>(z_it.iters);
}
template<class... Iterators>
zip_iterator<tuple<Iterators...>> zip_iterator<tuple<Iterators...>>::operator-(difference_type d){
    zip_iterator<tuple<Iterators...>> rtn(*this);
    tuptup::apply_each([d](auto& it){ it -= d; }, rtn.iters);
    return rtn;
}
template<class... Iterators>
zip_iterator<tuple<Iterators...>> zip_iterator<tuple<Iterators...>>::operator+(difference_type d){
    zip_iterator<tuple<Iterators...>> rtn(*this);
    tuptup::apply_each([d](auto& it){ it+= d; }, rtn.iters);
    return rtn;
}
template<class... Iterators>
zip_iterator<tuple<Iterators...>>& zip_iterator<tuple<Iterators...>>::operator++(){
    tuptup::apply_each([](auto& it){ ++it; }, iters);
    return *this;
}
template<class... Iterators>
zip_iterator<tuple<Iterators...>>& zip_iterator<tuple<Iterators...>>::operator--(){
    tuptup::apply_each([](auto& it){ --it; }, iters);
    return *this;
}
template<class... Iterators>
bool zip_iterator<tuple<Iterators...>>::operator==(const zip_iterator& zip_iter) const{
    return iters == zip_iter.iters;
}
template<class... Iterators>
bool zip_iterator<tuple<Iterators...>>::operator!=(const zip_iterator& zip_iter) const{
    return iters != zip_iter.iters;
}
template<class... Iterators>
bool zip_iterator<tuple<Iterators...>>::operator<(const zip_iterator& zip_iter) const{
    return iters < zip_iter.iters;
}
namespace detail{
    template<typename IterTuple, std::size_t... I>
    auto make_reference_tuple_helper(IterTuple& iters, index_sequence<I...>){
        return std::forward_as_tuple((*std::get<I>(iters))...);
    }
}
template<class... Iterators>
typename zip_iterator<tuple<Iterators...>>::reference zip_iterator<tuple<Iterators...>>::operator*(){
    return detail::make_reference_tuple_helper(iters, make_index_sequence<sizeof...(Iterators)>{});
}


template<typename... Iterators>
zip_iterator<tuple<Iterators...>> make_zip_iterator(Iterators&&... iters){
    return zip_iterator<tuple<Iterators...>>(tuptup::make_tuple(iters...));
}

namespace detail{
    template<typename IterTuple>
    void zip_iterator_swap_helper(IterTuple& a, IterTuple& b, index_sequence<>){}

    template<typename IterTuple, std::size_t N, std::size_t... I>
    void zip_iterator_swap_helper(IterTuple& a, IterTuple& b, index_sequence<N, I...>){
        using std::swap;
        swap(get<N>(a), get<N>(b));
        zip_iterator_swap_helper(a, b, index_sequence<I...>{});
    }
}
template<typename ZipIterator>
void swap(zip_iterator_reference_tuple_impl<ZipIterator> a, zip_iterator_reference_tuple_impl<ZipIterator> b){ // Customization Point
    using tuple_type = typename decltype(a)::tuple_type;
    auto ref_tup_a = static_cast<tuple_type>(a);
    auto ref_tup_b = static_cast<tuple_type>(b);
    detail::zip_iterator_swap_helper(ref_tup_a, ref_tup_b, make_index_sequence<ZipIterator::iterator_tuple_size_v>{});
}
}