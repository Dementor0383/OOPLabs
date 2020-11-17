cmake_minimum_required(VERSION 3.17)
project(Lab1)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest)

include_directories(lib/googletest/googletest/include/gtest)
add_executable(Lab1 Test.cpp Trit.cpp Trit.h TritSet.cpp TritSet.h)
target_link_libraries(Lab1 gtest gtest_main)