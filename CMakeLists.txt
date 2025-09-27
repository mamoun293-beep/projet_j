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

#tests
add_executable(
  test_two_sum
  tests/test_two_sum.cpp
)

target_link_libraries(
  test_two_sum
  GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(test_two_sum)

#hello_word
add_executable(projet_j src/main.cpp)

#exo1
add_executable(two_sum src/two_sum.cpp)
