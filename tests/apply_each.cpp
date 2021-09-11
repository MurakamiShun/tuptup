#include <sstream>
#include <cassert>
#include <tuptup.hpp>

int main(){
    std::tuple<std::string, int, int> sii{"test", 5, 6};
    
    struct {
        std::ostringstream oss;
        void operator()(const std::string& str){
            oss << "string:" << str;
        }
        void operator()(const int i){
            oss << "int:" << i;
        }
    } functor;

    tuptup::apply_each(functor, sii);

    assert(functor.oss.str() == "string:testint:5int:6");
    
    struct {
        void operator()(const std::string& str){}
        int64_t operator()(int& i){
            auto tmp = i;
            i = i*2;
            return tmp;
        }
    } square_if_int;

    auto before = tuptup::apply_each(square_if_int, sii);

    assert((before == std::tuple<int64_t, int64_t>{5,6}));
    assert((sii == decltype(sii){"test",10,12}));
}