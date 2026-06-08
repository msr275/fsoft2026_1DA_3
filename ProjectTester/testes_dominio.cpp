#include <gtest/gtest.h>
#include <models/Album.h>
#include <models/Artista.h>
#include <models/Carrinho.h>
#include <exceptions/InvalidDataException.h>


// Testes da Classe Artista

TEST(ArtistaTest, CriarArtistaValido) {
    EXPECT_NO_THROW({
    Artista::adicionarArtista("Pink Floyd", "UK" , "Rock");
    });

    int id = Artista::obterIdPorNome("Pink Floyd");
    EXPECT_NE(id, -1);
}

TEST(ArtistaTest, BloquearCamposVazios) {
    EXPECT_THROW({
        Artista artistaErrado(99 , "", "UK", "Rock");
    }, InvalidDataException);
}



// Testes da Classe Álbum

TEST(AlbumTest, ValidarPrecoNegativo) {
    Artista artistaFake(1, "Pink Floyd", "UK" , "Rock");
    Album albumTeste (1, &artistaFake, "Wish You Were Here", 1975 , 29.99f, "Vinil");

    EXPECT_THROW({
        albumTeste.set_preco(-5.00f);
    }, InvalidDataException);
}

TEST(AlbumTest, ValidarFormatos) {
    Artista artistaFake(2, "Kendrick Lamar", "EUA", "Hip Hop");
    Album albumTeste(4, &artistaFake, "To Pimp a Butterfly", 2015, 42.99f, "Vinil");

    EXPECT_NO_THROW(albumTeste.set_formato("vinil"));
    EXPECT_EQ(albumTeste.formato1(), "Vinil");

    EXPECT_THROW({
        albumTeste.set_formato("Cassete");
    }, InvalidDataException);
}


// Testes da Classe Carrinho

TEST(CarrinhoTest, ValidarOperacoesECalculoTotal) {
    Carrinho carrinho;
    Artista artistaFake(1, "Pink Floyd", "UK", "Rock");

    Album alb1(1, &artistaFake, "Wish You Were Here", 1975, 29.99f, "Vinil");
    Album alb2(2, &artistaFake, "Dark Side of the Moon", 1975, 37.99f, "Vinil");

    carrinho.adicionarAlbum(&alb1);
    carrinho.adicionarAlbum(&alb2);


    EXPECT_FLOAT_EQ(carrinho.calcularTotal(), 67.98f);
    EXPECT_EQ(carrinho.getItens().size(), 2);

    carrinho.removerAlbum(1);
    EXPECT_FLOAT_EQ(carrinho.calcularTotal(), 37.99f);

    carrinho.limparCarrinho();
    EXPECT_EQ(carrinho.getItens().size(), 0);
    EXPECT_FLOAT_EQ(carrinho.calcularTotal(), 0.00f);
}