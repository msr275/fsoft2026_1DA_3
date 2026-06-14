#include <gtest/gtest.h>
#include "persistence/DataManager.h"
#include "controllers/Pesquisa.h"
#include "models/Album.h"
#include "models/Artista.h"
#include "models/Carrinho.h"
#include "models/Rating.h"
#include "models/Venda.h"


// Persistência (Ficheiros CSV)
TEST(IntegracaoPersistenciaTest, CarregarDadosDoSistema) {

    //Arrange
    DataManager dm("data");

    //Act & Assert
    EXPECT_NO_THROW({
        dm.carregarDados()  ;
    });
}


// Controller de Pesquisa
TEST(IntegracaoPesquisaTest, MotoresDeBusca) {

    //Act & Assert
    EXPECT_NO_THROW({
        Pesquisa::pesquisarPorGenero(("Rock"));
        Pesquisa::pesquisaPorNomedeArtista(("Kendrick Lamar"));
    });
}


// Regras de Negócio (Venda e Rating)
TEST(IntegracaoRegrasNegocioTest, FluxosEfetivos) {

    //Arrange
    Artista artistaFake(1, "Pink Floyd", "UK" , "Rock");
    Album albumTeste(1, &artistaFake, "Wish You Were Here", 1975 , 29.99f, "Vinil");

    //Act & Assert
    EXPECT_NO_THROW({
        Rating ratingTeste(1, 5);
        EXPECT_EQ(ratingTeste.getPontuacao(), 5);
    });

    //Arrange
    Carrinho carrinhoDeTeste;
    carrinhoDeTeste.adicionarAlbum((&albumTeste));

    //Act & Assert
    EXPECT_NO_THROW({
        Venda novaVenda(1, "2026-06-09", carrinhoDeTeste);
        EXPECT_EQ(novaVenda.getIdVenda(), 1);
    });
}