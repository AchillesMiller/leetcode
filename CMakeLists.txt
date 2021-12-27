cmake_minimum_required(VERSION 3.10)

project(leetcode VERSION 1.0)

include_directories(PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()
add_subdirectory(tests)