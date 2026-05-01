cmake_minimum_required(VERSION 3.28)
project(fsoft2026_1DA_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(fsoft2026_1DA_3
        sources/main.cpp
        sources/Utils.cpp
)

target_include_directories(fsoft2026_1DA_3 PUBLIC headers)