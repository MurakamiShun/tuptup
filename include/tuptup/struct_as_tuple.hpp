#pragma once
#include <type_traits>
#include <tuple>
/*
 * tuptup: https://github.com/MurakamiShun/tuptup/
 * Copyright (c) 2025 MurakamiShun
 * 
 * Released under the MIT License.
 */

#ifndef TUPTUP_STRUCT_BINDER_MAX_VAR_COUNT
#define TUPTUP_STRUCT_BINDER_MAX_VAR_COUNT 128
#endif

namespace tuptup::detail{
template<typename T>
constexpr auto make_reference_tuple([[maybe_unused]]T&, [[maybe_unused]] std::integral_constant<std::size_t, 0>) noexcept {
    return std::tuple<>{};
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 1>) noexcept {
    auto& [a0] = arg;
    return std::tie(a0);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 2>) noexcept {
    auto& [a0,a1] = arg;
    return std::tie(a0,a1);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 3>) noexcept {
    auto& [a0,a1,a2] = arg;
    return std::tie(a0,a1,a2);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 4>) noexcept {
    auto& [a0,a1,a2,a3] = arg;
    return std::tie(a0,a1,a2,a3);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 5>) noexcept {
    auto& [a0,a1,a2,a3,a4] = arg;
    return std::tie(a0,a1,a2,a3,a4);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 6>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 7>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 8>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 9>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 10>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 11>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 12>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 13>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 14>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 15>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 16>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15);
}
#if TUPTUP_STRUCT_BINDER_MAX_VAR_COUNT > 16
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 17>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   );
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 18>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 19>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 20>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 21>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 22>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 23>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 24>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 25>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 26>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 27>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 28>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 29>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 30>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 31>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 32>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31);
}
#endif
#if TUPTUP_STRUCT_BINDER_MAX_VAR_COUNT > 32
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 33>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   );
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 34>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 35>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 36>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 37>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 38>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 39>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 40>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 41>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 42>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 43>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 44>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 45>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 46>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 47>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 48>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47);
}
#endif
#if TUPTUP_STRUCT_BINDER_MAX_VAR_COUNT > 48
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 49>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   );
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 50>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 51>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 52>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 53>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 54>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 55>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 56>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 57>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 58>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 59>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 60>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 61>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 62>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 63>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 64>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63);
}
#endif
#if TUPTUP_STRUCT_BINDER_MAX_VAR_COUNT > 64
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 65>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   );
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 66>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 67>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 68>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 69>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 70>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 71>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 72>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 73>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 74>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 75>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 76>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 77>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 78>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 79>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 80>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79);
}
#endif
#if TUPTUP_STRUCT_BINDER_MAX_VAR_COUNT > 80
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 81>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   );
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 82>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 83>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 84>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 85>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 86>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 87>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 88>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 89>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 90>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 91>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 92>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 93>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 94>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 95>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 96>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95);
}
#endif
#if TUPTUP_STRUCT_BINDER_MAX_VAR_COUNT > 96
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 97>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   );
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 98>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 99>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 100>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 101>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 102>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 103>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 104>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 105>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 106>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 107>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 108>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 109>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 110>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 111>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 112>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111);
}
#endif
#if TUPTUP_STRUCT_BINDER_MAX_VAR_COUNT > 112
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 113>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
          ] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
                   );
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 114>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
          ,a113] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
                   ,a113);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 115>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
          ,a113,a114] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
                   ,a113,a114);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 116>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
          ,a113,a114,a115] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
                   ,a113,a114,a115);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 117>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
          ,a113,a114,a115,a116] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
                   ,a113,a114,a115,a116);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 118>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
          ,a113,a114,a115,a116,a117] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
                   ,a113,a114,a115,a116,a117);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 119>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
          ,a113,a114,a115,a116,a117,a118] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
                   ,a113,a114,a115,a116,a117,a118);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 120>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
          ,a113,a114,a115,a116,a117,a118,a119] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
                   ,a113,a114,a115,a116,a117,a118,a119);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 121>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
          ,a113,a114,a115,a116,a117,a118,a119,a120] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
                   ,a113,a114,a115,a116,a117,a118,a119,a120);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 122>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
          ,a113,a114,a115,a116,a117,a118,a119,a120,a121] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
                   ,a113,a114,a115,a116,a117,a118,a119,a120,a121);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 123>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
          ,a113,a114,a115,a116,a117,a118,a119,a120,a121,a122] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
                   ,a113,a114,a115,a116,a117,a118,a119,a120,a121,a122);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 124>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
          ,a113,a114,a115,a116,a117,a118,a119,a120,a121,a122,a123] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
                   ,a113,a114,a115,a116,a117,a118,a119,a120,a121,a122,a123);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 125>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
          ,a113,a114,a115,a116,a117,a118,a119,a120,a121,a122,a123,a124] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
                   ,a113,a114,a115,a116,a117,a118,a119,a120,a121,a122,a123,a124);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 126>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
          ,a113,a114,a115,a116,a117,a118,a119,a120,a121,a122,a123,a124,a125] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
                   ,a113,a114,a115,a116,a117,a118,a119,a120,a121,a122,a123,a124,a125);
}
template<typename T>
constexpr auto make_reference_tuple(T& arg, [[maybe_unused]] std::integral_constant<std::size_t, 127>) noexcept {
    auto& [a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
          ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
          ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
          ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
          ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
          ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
          ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
          ,a113,a114,a115,a116,a117,a118,a119,a120,a121,a122,a123,a124,a125,a126] = arg;
    return std::tie(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16
                   ,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32
                   ,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48
                   ,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62,a63,a64
                   ,a65,a66,a67,a68,a69,a70,a71,a72,a73,a74,a75,a76,a77,a78,a79,a80
                   ,a81,a82,a83,a84,a85,a86,a87,a88,a89,a90,a91,a92,a93,a94,a95,a96
                   ,a97,a98,a99,a100,a101,a102,a103,a104,a105,a106,a107,a108,a109,a110,a111,a112
                   ,a113,a114,a115,a116,a117,a118,a119,a120,a121,a122,a123,a124,a125,a126);
}
#endif
}
namespace tuptup{
    template<typename T, typename std::enable_if<std::is_aggregate<T>::value, std::nullptr_t>::type = nullptr>
    struct struct_as_tuple {
    private:
        template<auto>
        struct anything {
            template<typename Type>
            operator Type && () const&& noexcept;
        };

        template<auto>
        struct any_base {
            template<typename Type, typename std::enable_if<std::is_base_of<Type, T>::value, std::nullptr_t>::type = nullptr>
            operator Type && () const&& noexcept;
        };

        template<template<auto>class Any, std::size_t... I>
        static constexpr auto initializable(std::index_sequence<I...>, int) noexcept
            -> decltype(T{ (Any<I>{})... }, bool{}) {
            return true;
        }
        template<template<auto>class Any, std::size_t... I>
        static constexpr auto initializable(std::index_sequence<I...>, char) noexcept {
            return false;
        }

        template<template<auto>class Any, std::size_t N>
        static constexpr std::size_t max_initializable_arg_count() noexcept {
            if constexpr(!initializable<Any>(std::make_index_sequence<N>{}, 0)) return N-1;
            else return max_initializable_arg_count<Any, N+1>();
        }
    public:
        static constexpr std::size_t base_class_num = []() constexpr noexcept {
            return max_initializable_arg_count<any_base, 0>();
        }();

        static constexpr std::size_t variable_num = []() constexpr noexcept {
           return max_initializable_arg_count<anything, base_class_num>();
        }() - base_class_num;

        using type = decltype(detail::make_reference_tuple(std::declval<T&>(), std::integral_constant<std::size_t, variable_num>{}));
    };

    namespace detail{
        struct make_tuple_from_struct_impl{
            template<typename Tup, std::size_t... I>
            static auto make_tuple_by_move_impl(Tup& tup, std::index_sequence<I...>){
                return std::make_tuple(std::move(std::get<I>(tup)...));
            }
            template<typename Tup>
            static auto make_tuple_by_move(Tup& tup) {
                return make_tuple_by_move_impl(tup, std::make_index_sequence<std::tuple_size_v<Tup>>{});
            }
            template<typename Tup, std::size_t... I>
            static auto make_tuple_impl(Tup& tup, std::index_sequence<I...>){
                return std::make_tuple(std::get<I>(tup)...);
            }
            template<typename Tup>
            static auto make_tuple(Tup& tup) {
                return make_tuple_impl(tup, std::make_index_sequence<std::tuple_size_v<Tup>>{});
            }
        };
    }

    template<typename T>
    constexpr auto tie_as_tuple(T&& t) noexcept {
      return detail::make_reference_tuple(t, std::integral_constant<std::size_t, struct_as_tuple<std::remove_cv_t<std::remove_reference_t<T>>>::variable_num>{});
    }

    template<typename T>
    constexpr auto make_as_tuple(T&& t){
        auto member_ref_tuple = tie_as_tuple(t);
        if constexpr(std::is_rvalue_reference_v<T>){
            return detail::make_tuple_from_struct_impl::make_tuple_by_move(member_ref_tuple);
        }
        else{
            return detail::make_tuple_from_struct_impl::make_tuple(member_ref_tuple);
        }
    }


}