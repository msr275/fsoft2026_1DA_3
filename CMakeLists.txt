cmake_minimum_required(VERSION 3.20)
project(fsoft2026_1DA_3 CXX)

set(CMAKE_CXX_STANDARD 17)

# Isto ajuda o CLion a encontrar os teus .h automaticamente
include_directories(Project/Headers)

# Tenta listar os ficheiros garantindo que o caminho existe:
add_executable(fsoft2026_1DA_3
        Project/main.cpp
        Project/Sources/Album.cpp
        Project/Sources/Artista.cpp
        Project/Sources/ManagerCatalogo.cpp
        Project/Headers/Album.h
        Project/Headers/Artista.h
        Project/Headers/ManagerCatalogo.h
        Project/main.cpp
)