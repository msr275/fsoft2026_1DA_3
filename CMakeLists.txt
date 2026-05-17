cmake_minimum_required(VERSION 3.28)
project(fsoft2026_1DA_3 CXX)

set(CMAKE_CXX_STANDARD 17)


include_directories(Project/Headers)

add_executable(fsoft2026_1DA_3
        Project/main.cpp

        Project/Headers/DataManager.h
        Project/Sources/DataManager.cpp

        Project/Headers/Album.h
        Project/Sources/Album.cpp

        Project/Headers/Artista.h
        Project/Sources/Artista.cpp

        Project/Headers/ManagerCatalogo.h
        Project/Sources/ManagerCatalogo.cpp

        Project/Headers/Carrinho.h
        Project/Sources/Carrinho.cpp

        Project/Headers/Menus.h
        Project/Sources/Menus.cpp

        Project/Headers/Utils.h
        Project/Sources/Utils.cpp

        Project/Headers/Rating.h
        Project/Sources/Rating.cpp

        Project/Headers/Venda.h

        Project/Headers/InvalidDataException.h
        Project/sources/InvalidDataException.cpp
)

target_include_directories(fsoft2026_1DA_3 PUBLIC Project/Headers)