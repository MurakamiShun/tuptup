#pragma once
#if (defined(__cplusplus) && __cplusplus < 201103L) && !defined(_MSC_VER) // MSVC is broken on C++11
#error requires C++11 or later
#endif

#include "tuptup/standard_functions.hpp"
#include "tuptup/integer_sequence.hpp"
#include "tuptup/apply.hpp"
#include "tuptup/apply_each.hpp"
#include "tuptup/indexed_apply_each.hpp"
#include "tuptup/tuple_traits.hpp"
#include "tuptup/tuple_slice.hpp"
#include "tuptup/tuple_filter.hpp"

#if (defined(__cplusplus) && __cplusplus >= 201703L) || (defined(_MSVC_LANG) && _MSVC_LANG >= 201703L)
#include "tuptup/struct_binder.hpp"
#endif