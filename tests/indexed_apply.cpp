#include <sstream>
#include <cassert>
#include <iostream>
#include <tuptup.hpp>

struct func{
    std::ostringstream oss;
    template<std::size_t N>
    std::string operator()(const std::string& str){
        oss << N << "-string:" << str;
        return "eeee";
    }
    template<std::size_t N>
    int8_t operator()(const int8_t i){
        oss << N << "-int:" << i;
        return 99;
    }
    template<std::size_t N>
    int64_t operator()(const int64_t i){
        oss << N << "-int:" << i;
        return 99;
    }
};

int main(){
    std::tuple<std::string, int8_t, int64_t> sii{"test", 5, 6};
    
    func functor;

    auto result = tuptup::indexed_apply_each(functor, sii);

}