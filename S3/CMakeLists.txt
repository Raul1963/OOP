cmake_minimum_required(VERSION 3.27)
project(S3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(S3
        GeometricForm.cpp
        GeometricForm.h
        Circle.h
        Circle.cpp
        main.cpp
        Square.cpp)
