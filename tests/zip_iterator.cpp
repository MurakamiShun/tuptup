#include <cassert>
#include <cstdint>
#include <vector>
#include <array>
#include <algorithm>

#include <tuptup.hpp>

int main(){
    std::vector<int> value = {1,2,4,8,16};
    std::vector<std::size_t> key = {5,4,3,2,1};

    auto zip_begin = tuptup::make_zip_iterator(value.begin(), key.begin());
    auto zip_end = tuptup::make_zip_iterator(value.end(), key.end());
    std::sort(
        zip_begin,
        zip_end,
        [](const decltype(zip_begin)::value_type& a, const decltype(zip_begin)::value_type& b){
            return std::get<1>(a) < std::get<1>(b);
        }
    );

    std::vector<int> v = {1,2,4,8,16};
    std::vector<std::size_t> a = {2,1,5,4,3};
    std::sort(
        tuptup::make_zip_iterator(v.begin(), a.begin()),
        tuptup::make_zip_iterator(v.end(), a.end()),
        [](const auto& a, const auto& b){
            return std::get<1>(a) < std::get<1>(b);
        }
    );

    assert(v[0] == 2 && a[0] == 1);
}