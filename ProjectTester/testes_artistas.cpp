#include <gtest/gtest.h>
#include <models/Artista.h>
#include "exceptions/InvalidDataException.h"



TEST(ArtistaTest, CriarArtistaValido) {

    //Arrange
    std::string nome = "Pink Floyd";
    std::string pais = "EUA";
    std::string genero = "Rock";

    //Act
    EXPECT_NO_THROW({
        Artista::adicionarArtista(nome,pais,genero);
    });

    int id = Artista::obterIdPorNome(nome);

    //Assert
    EXPECT_NE(id, -1);
}


TEST(ArtistaTest, BloquearCamposVazios) {

    //Arrange
    int idInvalido = 99;
    std::string nomeVazio = "";

    //Act & Assert
    EXPECT_THROW({
         Artista artistaErrado(idInvalido, nomeVazio, "UK", "Rock");
    }, InvalidDataException);
}
