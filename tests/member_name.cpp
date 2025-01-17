#include <array>
#include "../include/tuptup.hpp"

struct Test{
    int aaeta,bbae4;
    std::array<char,4> creaw;
    struct T{
        int dagae, ehnjsr;
    };
    T vegauh;
};

int main(){
    static_assert(tuptup::get_name<0, Test>() == "aaeta");
    static_assert(tuptup::get_name<1, Test>() == "bbae4");
    static_assert(tuptup::get_name<2, Test>() == "creaw");
    static_assert(tuptup::get_name<3, Test>() == "vegauh");

    static_assert(tuptup::get_name<0, Test::T>() == "dagae");
    static_assert(tuptup::get_name<1, Test::T>() == "ehnjsr");
}