#include "include/tuptup.hpp"

#include <iostream>
#include <string>

struct mul2 {
    constexpr int operator()(int i) const noexcept{ return i * 2; }
};

int main() {
    using namespace tuptup;
    auto t = integer_sequence_push_back<integer_sequence <int, 3>, 4>();
    auto a = integer_sequence <int, 5, 6, 7>();
    auto b = integer_sequence_cat<decltype(t), decltype(a)>();
    std::cout << std::is_same<decltype(b), integer_sequence <int, 3,4, 5, 6, 7>>::value << std::endl;
    std::cout << std::is_same<integer_sequence_push_back<decltype(b), 4>, integer_sequence <int, 3,4, 5, 6, 7, 4>>::value << std::endl;
    std::cout << std::is_same<integer_sequence_push_front<decltype(b), 4>, integer_sequence <int,4, 3,4, 5, 6, 7>>::value << std::endl;
    std::cout << std::is_same<make_integer_sequence<int, 4>, integer_sequence <int, 0,1,2,3>>::value << std::endl;
    std::cout << std::is_same<make_integer_range<int, 1, 4>, integer_sequence <int, 1, 2, 3>>::value << std::endl;


    auto c = make_integer_range<int, 1, 4>{};

    std::cout << std::is_same < integer_sequence_for_each < decltype(c),  mul2> , integer_sequence <int, 2, 4, 6>>::value << std::endl;

    std::tuple<int, int> bb{1,4};
    std::cout << tuptup::apply([](int a, int b) {return a + b; }, bb) << std::endl;

    apply_type_t<std::make_unsigned, decltype(bb)> u_bb;

    std::tuple<std::string, int, int> sii{"test", 5, 6};
    struct {
        void operator()(const std::string& str){
            std::cout << "string:" << str << ",";
        }
        void operator()(const int i){
            std::cout << "int:" << i << ",";
        }
    } functor;
    apply_each(functor, sii);

    tuple_slice_t<make_integer_range<std::size_t, 1,3>, decltype(sii)> ii;
    std::cout << std::is_same<decltype(ii), std::tuple<int, int>>::value << std::endl;

    //apply_filter<std::is_integral>(sii);

    #if __cplusplus >= 201703L
    struct {} base;
    struct :decltype(base){ int a,b,c; } some_aggregate;

    std::cout << struct_binder<decltype(some_aggregate)>::variable_num // 3
              << struct_binder<decltype(some_aggregate)>::base_class_num; // 1
    #endif

}