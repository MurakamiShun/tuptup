 
cmake_minimum_required(VERSION 3.1)

project(tests LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
enable_testing()

add_executable(apply_each apply_each.cpp)
add_test(NAME apply_each_test COMMAND apply_each)