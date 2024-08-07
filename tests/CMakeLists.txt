cmake_minimum_required(VERSION 3.19.2)

project(inner_tests)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(test_sources_dir ${CMAKE_CURRENT_SOURCE_DIR})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(..)

enable_testing()
function(add_gtest_executable target_name main_source)
  add_executable(${target_name} ${main_source} ${ARGN})
  target_link_libraries(${target_name} GTest::gtest_main)
  include(GoogleTest)
  gtest_discover_tests(${target_name})
endfunction(add_icpc_executable)

file(GLOB_RECURSE INNER_TEST_SRC_LIST ${test_sources_dir}/*.cc)
foreach(v ${INNER_TEST_SRC_LIST})
    string(REGEX MATCH "${test_sources_dir}/.*" relative_path ${v})
    string(REGEX REPLACE "${test_sources_dir}/" "" target_name ${relative_path})
    string(REGEX REPLACE ".cc" "" target_name ${target_name})
    add_gtest_executable(inner_test_${target_name} ${relative_path})
endforeach()


