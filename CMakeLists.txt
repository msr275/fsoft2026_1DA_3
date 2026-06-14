cmake_minimum_required(VERSION 3.28)
project(fsoft2026_1DA_3 CXX)

set(CMAKE_CXX_STANDARD 17)

# Diretório global de cabeçalhos
include_directories(Project/Headers)


# Executável Principal (Aplicação da loja)

add_executable(fsoft2026_1DA_3
        Project/main.cpp

        Project/Headers/persistence/DataManager.h
        Project/Sources/persistence/DataManager.cpp

        Project/Headers/models/Album.h
        Project/Sources/models/Album.cpp

        Project/Headers/models/Artista.h
        Project/Sources/models/Artista.cpp

        Project/Headers/models/Carrinho.h
        Project/Sources/models/Carrinho.cpp

        Project/Headers/views/Menus.h
        Project/Sources/views/Menus.cpp

        Project/Headers/views/Utils.h
        Project/Sources/views/Utils.cpp

        Project/Headers/models/Rating.h
        Project/Sources/models/Rating.cpp

        Project/Headers/models/Venda.h
        Project/Sources/models/Venda.cpp

        Project/Headers/controllers/Pesquisa.h
        Project/Sources/controllers/Pesquisa.cpp

        Project/Headers/exceptions/InvalidDataException.h
        Project/Sources/exceptions/InvalidDataException.cpp

)

target_include_directories(fsoft2026_1DA_3 PUBLIC Project/Headers)


# Executável de Testes (GoogleTest)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)


set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(runTests
        Project/Sources/models/Album.cpp
        Project/Sources/models/Artista.cpp
        Project/Sources/models/Carrinho.cpp
        Project/Sources/views/Utils.cpp
        Project/Sources/models/Rating.cpp
        Project/Sources/models/Venda.cpp
        Project/Sources/controllers/Pesquisa.cpp
        Project/Sources/persistence/DataManager.cpp
        Project/Sources/exceptions/InvalidDataException.cpp
        ProjectTester/main_test.cpp
)

target_include_directories(runTests PUBLIC Project/Headers)
target_link_libraries(runTests PRIVATE gtest gtest_main)