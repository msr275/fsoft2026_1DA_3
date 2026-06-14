#include  <gtest/gtest.h>

#include "testes_artistas.cpp"
#include "testes_album.cpp"
#include "testes_carrinho.cpp"
#include "testes_integracao.cpp"

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}