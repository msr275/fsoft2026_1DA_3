#include <gtest/gtest.h>
#include "models/Carrinho.h"
#include "models/Album.h"
#include "models/Artista.h"

class CarrinhoFixture : public ::testing::Test {
protected:
    Artista* artistaFake;
    Album* alb1;
    Album* alb2;
    Carrinho carrinho;

    //Funciona como Arrange pré-configurado
    void SetUp() override {
        artistaFake = new Artista(1, "Pink Floyd", "UK" , "Rock");
        alb1 = new Album(1, artistaFake, "Wish You Were Here", 1975 , 29.99f, "Vinil");
        alb2 = new Album(2, artistaFake, "The Dark Side of the Moon", 1973 , 37.99f, "Vinil");
    }

    void TearDown() override {
        delete alb1;
        delete alb2;
        delete artistaFake;
    }
};

TEST_F(CarrinhoFixture, ValidarOperacoesECalculoTotal) {

    //Act 1
    carrinho.adicionarAlbum(alb1);
    carrinho.adicionarAlbum(alb2);

    //Assert 1
    EXPECT_FLOAT_EQ(carrinho.calcularTotal(), 67.98f);
    EXPECT_EQ(carrinho.getItens().size(), 2);

    //Act 2
    carrinho.removerAlbum(1);

    //Assert 2
    EXPECT_FLOAT_EQ(carrinho.calcularTotal(), 37.99f);

    //Act 3
    carrinho.limparCarrinho();

    //Assert 3
    EXPECT_EQ(carrinho.getItens().size(), 0);
}