#pragma once
/*
 * tuptup: https://github.com/akisute514/tuptup/
 * Copyright (c) 2021 akisute514
 * 
 * Released under the MIT License.
 */

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
#include "tuptup/type_placeholders.hpp"

#if (defined(__cplusplus) && __cplusplus >= 201402L) || (defined(_MSVC_LANG) && _MSVC_LANG >= 201402L) // TODO(C++11 support)
#include "tuptup/zip_iterator.hpp"
#endif

#if (defined(__cplusplus) && __cplusplus >= 201703L) || (defined(_MSVC_LANG) && _MSVC_LANG >= 201703L)
#include "tuptup/struct_binder.hpp"
#endif