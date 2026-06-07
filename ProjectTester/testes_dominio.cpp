#include <gtest/gtest.h>
#include <models/Album.h>
#include <models/Artista.h>
#include <models/Carrinho.h>
#include <exceptions/InvalidDataException.h>


// Testes da Classe Artista

TEST(ArtistaTest, CriarArtistaInvalido) {
    EXPECT_NO_THROW({
    Artista::adicionarArtista("Pink Floyd", "UK" , "Rock");
    });

    int id = Artista::obterIdPorNome("Pink Floyd");
    EXPECT_NE(id, -1);
}