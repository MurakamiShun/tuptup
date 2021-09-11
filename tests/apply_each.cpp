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
}