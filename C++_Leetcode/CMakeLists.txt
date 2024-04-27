cmake_minimum_required(VERSION 3.23)
project(C___Leetcode)
#include_directories(SYSTEM "/foo/bar")

set(CMAKE_CXX_STANDARD 14)

add_executable(C___Leetcode main.cpp )


add_executable(main main.cpp)

add_executable(TheMax1000 NiuKe/TheMax1000.cpp)
add_executable(0.1_bug leetcode/editor/cn/0.1_bug.cpp)
add_executable(AnyConvert NiuKe/AnyConvert.cpp)
add_executable(set NiuKe/set.cpp)

add_executable(Single NiuKe/Single.cpp)
add_executable(Auto_ptr Review_code/Auto_ptr.cpp)