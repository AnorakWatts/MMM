cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp mymath.h mymath.cpp intf.h)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

target_link_libraries(untitled sfml-graphics sfml-audio)