cmake_minimum_required(VERSION 3.17)
project(polymorphicShapes)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(polymorphicShapes main.cpp
        src/shapesss.cpp)