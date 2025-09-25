cmake_minimum_required(VERSION 3.16)
project(projet_j LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#hello_word
add_executable(projet_j src/main.cpp)

#exo1
add_executable(two_sum src/two_sum.cpp)