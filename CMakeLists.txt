cmake_minimum_required(VERSION 2.8.6)
project(mathclass)
add_compile_options(-std=gnu++11)

file(GLOB srcs "src/*.cpp" "include/*.h")

add_library(mathclass ${srcs})
target_include_directories(mathclass PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/ )
set_target_properties(mathclass PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../)

