#pragma once
#include "struct_as_tuple.hpp"
/*
 * tuptup: https://github.com/MurakamiShun/tuptup/
 * Copyright (c) 2025 MurakamiShun
 * 
 * Released under the MIT License.
 */

namespace tuptup{
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wundefined-var-template"
    namespace detail{
        template<auto D>
        class value_name {
        private:
            static constexpr auto impl(){
                #ifdef _MSC_VER
                constexpr auto str_ptr = __FUNCTION__;
                constexpr auto offset = std::char_traits<char>::length("detail::value_name<");
                constexpr auto begin = str_ptr + offset + std::char_traits<char>::length(str_ptr[offset] == 's' ? "struct " : "class ");
                
                constexpr auto end_pos = std::string_view(str_ptr).rfind("}>::impl");
                constexpr auto end = std::addressof(str_ptr[end_pos]);
                #elif defined(__clang__)
                constexpr auto str_ptr = __PRETTY_FUNCTION__;
                constexpr auto begin = std::char_traits<char>::find(str_ptr, std::char_traits<char>::length(str_ptr), '[') + std::char_traits<char>::length("D = ");
                constexpr auto end = std::char_traits<char>::find(str_ptr, std::char_traits<char>::length(str_ptr), ']');
                #elif defined(__GNUC__)
                constexpr auto str_ptr = __PRETTY_FUNCTION__;
                constexpr auto begin = std::char_traits<char>::find(str_ptr, std::char_traits<char>::length(str_ptr), '[') + std::char_traits<char>::length(" with auto D = ");
                constexpr auto end = std::char_traits<char>::find(str_ptr, std::char_traits<char>::length(str_ptr), ']');
                #endif
                return std::string_view(begin, std::distance(begin, end));
            }
        public:
            static constexpr auto value = impl();
        };

        template<typename T>
        extern const T fake_obj;

        template <typename T>
        struct fake_member_ptr{const T* ptr;};
    }

    template <std::size_t N, typename T>
    constexpr auto get_name(){
        auto& p = tuptup::get<N>(tuptup::tie_as_tuple(detail::fake_obj<std::remove_cvref_t<T>>));
        constexpr auto ptr_str = detail::value_name<detail::fake_member_ptr<std::remove_cvref_t<decltype(p)>>{std::addressof(p)}>::value;
        #ifdef _MSC_VER
        constexpr auto begin = ptr_str.rfind(">.") + 2;
        constexpr auto end = ptr_str.length();
        #elif defined(__clang__)
        constexpr auto begin = std::char_traits<char>::length("{&fake_obj.") + 1;
        constexpr auto end = ptr_str.rfind("}");
        #elif defined(__GNUC__)
        constexpr auto begin = ptr_str.rfind("::") + 2;
        constexpr auto end = ptr_str.rfind(")}");
        #endif
        return ptr_str.substr(begin, end - begin);
    }
    #pragma clang diagnostic pop
}
