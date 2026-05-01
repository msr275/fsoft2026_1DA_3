cmake_minimum_required(VERSION 3.28)
project(fsoft2026_1DA_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(fsoft2026_1DA_3
        Project/sources/main.cpp
        Project/sources/Utils.cpp
        Project/headers/Menus.h
        Project/sources/views/Menus.cpp
        Project/headers/InvalidDataException.h
        Project/sources/exceptions/InvalidDataException.cpp
)

target_include_directories(fsoft2026_1DA_3 PUBLIC Project/headers)