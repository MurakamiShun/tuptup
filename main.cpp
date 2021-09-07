#include "include/tuptup.hpp"

#include <iostream>
#include <tuple>

struct mul2 {
	constexpr int operator()(int i) const noexcept{ return i * 2; }
};


struct Base {};

struct Test : public Base{
	int a, b;
	int c;
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

	apply_to_types_t<std::make_unsigned, decltype(bb)> u_bb;

	#if __cplusplus >= 201703L
	std::cout << tuptup::struct_binder<Test>::variable_num << std::endl;
	std::cout << tuptup::struct_binder<Test>::base_class_num << std::endl;
	#endif

}