cmake_minimum_required(VERSION 3.26)
project(lab11_12)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab11_12
        consumption.cpp
        consumption.h
        process.cpp
        process.h
        resource.cpp
        resource.h
        banker.h
        banker.cpp
        main.cpp)
