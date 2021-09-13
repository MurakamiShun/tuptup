#include <sstream>
#include <tuptup.hpp>
#include <cassert>

struct func{
    std::ostringstream oss;
    template<std::size_t N>
    std::string operator()(const std::string& str){
        oss << "string-" << N << ":" << str;
        return "eeee";
    }
    template<std::size_t N>
    void operator()(const int8_t i){
        oss << "int8-"  << N << ":" << static_cast<int>(i);
    }
    template<std::size_t N>
    int8_t operator()(const int64_t i){
        oss << "int64-"  << N << ":" << i;
        return 99;
    }
};

int main(){
    std::tuple<std::string, int8_t, int64_t> sii{"test", 5, 6};
    
    func functor;

    auto result = tuptup::indexed_apply_each(functor, sii);

    assert((functor.oss.str() == "string-0:testint8-1:5int64-2:6"));
    assert((std::is_same<decltype(result), std::tuple<std::string, int8_t>>::value));
}