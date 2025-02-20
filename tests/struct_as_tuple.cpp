#include <string>
#include <array>
#include <cassert>
#include <tuptup.hpp>
struct Base{};

/*
struct Test : public Base{
    int a,b;
    char c[4];
    std::string str;
};
*/
struct Test : public Base{
    int a,b;
    std::array<char,4> c;
    std::string str;
};

int main(){
    assert(tuptup::struct_as_tuple<Test>::base_class_num == 1);
    assert(tuptup::struct_as_tuple<Test>::variable_num == 4);

    Test t = {{}, 0,1,"fff", "test"};
    std::tuple<int&, int&, std::array<char,4>&, std::string&> ref_tuple = tuptup::tie_as_tuple(t);
    std::get<3>(ref_tuple) = "changed";

    tuptup::make_as_tuple(static_cast<const Test>(t));

    assert(t.str == "changed");
}