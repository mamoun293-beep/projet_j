cmake_minimum_required(VERSION 3.16)
project(projet_j LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Test_environnment
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)
enable_testing()

include(GoogleTest)

#hello_word
add_executable(projet_j src/main.cpp)

#tests
add_library(two_sum_lib src/two_sum.cpp)
target_include_directories(two_sum_lib PUBLIC /home/yanis/dev/projet_j/include)

file(GLOB TEST_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/tests/test_*.cpp")
message(STATUS "Adding tests: ${TEST_SOURCES}")

foreach(test_src ${TEST_SOURCES})
    get_filename_component(test_name ${test_src} NAME_WE)
    add_executable(${test_name} ${test_src})
    target_include_directories(${test_name} PRIVATE ${CMAKE_SOURCE_DIR}/include)
    target_link_libraries(${test_name} PRIVATE GTest::gtest_main two_sum_lib)
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()
