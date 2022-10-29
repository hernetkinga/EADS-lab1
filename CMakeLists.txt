cmake_minimum_required(VERSION 3.20)
project(eads21w-lab)

add_executable(eads21w-lab main.cpp
        template.h
        test.cpp)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/googletest-main)
include_directories(lib/googletest-main/googletest/include)
include_directories(lib/googletest-main/googlemock/include)


target_link_libraries(eads21w-lab gtest gtest_main)