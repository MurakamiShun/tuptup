#include <string>
#include <cassert>
#include <tuptup.hpp>

int main(){
    std::tuple<std::string, int, int> sii{"test", 5, 6};
    
    struct {
        std::size_t operator()(std::string& str, int& i1, int& i2){
            str = "changed";
            i1 = 0;
            i2 = 1;
            return 999;
        }
    } functor;

    assert((tuptup::apply(functor, sii) == 999));

    assert((sii == std::tuple<std::string, int, int>{"changed", 0, 1}));

    static_assert(std::is_same<
        tuptup::apply_type_t<std::add_const<tuptup::placeholder_t::_1>, decltype(sii)>,
        std::tuple<const std::string, const int, const int>>::value
    ,"");
}