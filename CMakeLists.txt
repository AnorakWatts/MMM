cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -std=c++0x")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -pthread -lX11 -L /lib64")

add_executable(untitled Source.cpp Plotter.cpp Plotter.h MathFuncs.h MathFuncs.cpp)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

target_link_libraries(untitled sfml-graphics sfml-audio pthread)