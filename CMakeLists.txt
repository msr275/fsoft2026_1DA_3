cmake_minimum_required(VERSION 3.28)
project(fsoft2026_1DA_3 CXX)

set(CMAKE_CXX_STANDARD 17)


include_directories(Project/Headers)
include_directories(Project/headers)


add_executable(fsoft2026_1DA_3
        Project/main.cpp
        Project/Sources/DataManager.cpp
        Project/Headers/DataManager.h
        Project/Sources/Album.cpp
        Project/Sources/Artista.cpp
        Project/Sources/ManagerCatalogo.cpp
        Project/Headers/Album.h
        Project/Headers/Artista.h
        Project/Headers/ManagerCatalogo.h
        Project/sources/Utils.cpp
        Project/headers/Menus.h
        Project/sources/views/Menus.cpp
        Project/headers/InvalidDataException.h
        Project/sources/exceptions/InvalidDataException.cpp
)

target_include_directories(fsoft2026_1DA_3 PUBLIC Project/headers)