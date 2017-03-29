cmake_minimum_required(VERSION 2.8.6)
set(MATHCLASS_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/../include/)
set(MATHCLASS_LIBRARIES_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/../build/)
set(MATHCLASS_LIBRARIES mathclass)
include_directories(${MATHCLASS_INCLUDE_DIRS})
link_directories(${MATHCLASS_LIBRARIES_DIRS})

project(test_vector)
add_compile_options(-std=gnu++11)

file(GLOB srcs "test_vector.cpp")

add_executable(test_vector ${srcs})
target_link_libraries(test_vector ${MATHCLASS_LIBRARIES})


project(test_quaternion)
add_compile_options(-std=gnu++11)

file(GLOB srcs "test_quaternion.cpp")

add_executable(test_quaternion ${srcs})
target_link_libraries(test_quaternion ${MATHCLASS_LIBRARIES})


project(test_matrix)
add_compile_options(-std=gnu++11)

file(GLOB srcs "test_matrix.cpp")

add_executable(test_matrix ${srcs})
target_link_libraries(test_matrix ${MATHCLASS_LIBRARIES})

