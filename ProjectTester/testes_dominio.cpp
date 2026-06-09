#include <gtest/gtest.h>
#include <models/Album.h>
#include <models/Artista.h>
#include <models/Carrinho.h>
#include <models/Rating.h>
#include <models/Venda.h>
#include <persistence/DataManager.h>
#include <controllers/Pesquisa.h>
#include <exceptions/InvalidDataException.h>


// 1. TESTES UNITÁRIOS: Artista (Artista Válido, Id por Nome e Bloquear Campos Vazios)

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



// 2. TESTES UNITÁRIOS: Álbum (Preço, Formato e Anos de Fronteira)

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

TEST(AlbumTest, ValidarLimitesDoAno) {
    Artista artistaFake(1, "Pink Floyd", "UK" , "Rock");
    Album albumTeste(1, &artistaFake, "Wish You Were Here", 1975 , 29.99f, "Vinil");

    EXPECT_THROW({
        albumTeste.set_ano(2027);
    },  InvalidDataException);

    EXPECT_THROW({
        albumTeste.set_ano(1899);
    },  InvalidDataException);
}


// 3. TEST FIXTURES (TEST_F): Reutilização e Gestão de Memória

class CarrinhoFixture : public ::testing::Test {
    protected:
    Artista* artistaFake;
    Album* alb1;
    Album* alb2;
    Carrinho carrinho;

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
    carrinho.adicionarAlbum(alb1);
    carrinho.adicionarAlbum(alb2);

    EXPECT_FLOAT_EQ(carrinho.calcularTotal(), 67.98f);
    EXPECT_EQ(carrinho.getItens().size(), 2);

    carrinho.removerAlbum(1);
    EXPECT_FLOAT_EQ(carrinho.calcularTotal(), 37.99f);

    carrinho.limparCarrinho();
    EXPECT_EQ(carrinho.getItens().size(), 0);
}


//  4. INTEGRAÇÃO: Persistência  (Ficheiros CSV)

TEST(IntegracaoPersistenciaTest, CarregarDadosDoSistema) {

    EXPECT_NO_THROW({
        DataManager::getInstance().carregarDados();
    });
}


//  5. INTEGRAÇÃO: Controller de Pesquisa

TEST(IntegracaoPesquisaTest, MotoresDeBusca) {

    EXPECT_NO_THROW({
        controllerPesquisa.pesquisarPorGenero("Rock");
        controllerPesquisa.pesquisaPorArtista("Kendrick Lamar");
    });
}


//  6. INTEGRACAO: Regras de Negócio (Venda e Rating)

TEST(IntegracaoRegrasNegocioTest, FluxosEfetivos) {

    Artista artistaFake(1, "Pink Floyd", "UK" , "Rock");
    Album albumTeste(1, &artistaFake, "Wish You Were Here", 1975 , 29.99f, "Vinil");

    Rating ratingTeste;
    EXPECT_NO_THROW({
        ratingTeste.adicionarNota(5);
    });

    EXPECT_NO_THROW({
        Venda novaVenda(1, "2026-06-09", 29.99f);
    });
}