#include <gtest/gtest.h>
#include "models/Album.h"
#include "models/Artista.h"
#include "exceptions/InvalidDataException.h"


TEST(AlbumTest, ValidarPrecoNegativo) {

    //Arrange
    Artista artistaFake(1, "Pink Floyd", "UK" , "Rock");
    Album albumTeste (1, &artistaFake, "Wish You Were Here", 1975 , 29.99f, "Vinil");
    float precoInvalido = -5.00f;

    //Act & Assert
    EXPECT_THROW({
        albumTeste.set_preco(precoInvalido);
    }, InvalidDataException);
}

TEST(AlbumTest, ValidarFormatos) {

    //Arrange
    Artista artistaFake(2, "Kendrick Lamar", "EUA", "Hip Hop");
    Album albumTeste(4, &artistaFake, "To Pimp a Butterfly", 2015, 42.99f, "Vinil");

    //Act & Assert
    EXPECT_NO_THROW(albumTeste.set_formato("vinil"));
    EXPECT_EQ(albumTeste.formato1(), "Vinil");

    EXPECT_THROW({
        albumTeste.set_formato("Cassete");
    }, InvalidDataException);
}

TEST(AlbumTest, ValidarLimitesDoAno) {

    //Arrange
    Artista artistaFake(1, "Pink Floyd", "UK" , "Rock");
    Album albumTeste(1, &artistaFake, "Wish You Were Here", 1975 , 29.99f, "Vinil");
    int anoFuturo = 2027;
    int anoPassadoRemoto = 1899;

    //Act & Assert
    EXPECT_THROW({
        albumTeste.set_ano(anoFuturo);
    },  InvalidDataException);

    EXPECT_THROW({
        albumTeste.set_ano(anoPassadoRemoto);
    },  InvalidDataException);
}