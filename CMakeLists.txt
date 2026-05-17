cmake_minimum_required(VERSION 3.28)
project(fsoft2026_1DA_3 CXX)

set(CMAKE_CXX_STANDARD 17)


include_directories(Project/Headers)

add_executable(fsoft2026_1DA_3
        Project/main.cpp

        Project/Headers/persistence/DataManager.h
        Project/Sources/persistence/DataManager.cpp

        Project/Headers/models/Album.h
        Project/Sources/models/Album.cpp

        Project/Headers/models/Artista.h
        Project/Sources/models/Artista.cpp

        Project/Headers/controllers/ManagerCatalogo.h
        Project/Sources/controllers/ManagerCatalogo.cpp

        Project/Headers/models/Carrinho.h
        Project/Sources/models/Carrinho.cpp

        Project/Headers/views/Menus.h
        Project/Sources/views/Menus.cpp

        Project/Headers/views/Utils.h
        Project/Sources/models/Utils.cpp

        Project/Headers/models/Rating.h
        Project/Sources/models/Rating.cpp

        Project/Headers/models/Venda.h

        Project/Headers/exceptions/InvalidDataException.h
        Project/Sources/exceptions/InvalidDataException.cpp
)

target_include_directories(fsoft2026_1DA_3 PUBLIC Project/Headers)