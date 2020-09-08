cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(untitled main.cpp mymath.h mymath.cpp UICalc.cpp UICalc.h)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

target_link_libraries(untitled sfml-graphics sfml-audio)