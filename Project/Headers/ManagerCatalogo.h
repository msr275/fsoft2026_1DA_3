#ifndef FSOFT2026_1DA_3_MANAGERCATALOGO_H
#define FSOFT2026_1DA_3_MANAGERCATALOGO_H

#include "Artista.h"
#include "Album.h"
#include <vector>
#include <string>

class ManagerCatalogo {
private:
    //vetores de cada coisa
    std::vector<Artista> listaArtistas; // vetor de artistas
    std::vector<Album> listaAlbuns;     // vetor de álbuns

    // para poder atribuir incrementalmente os ids
    int idproximoArtista = 1;
    int idproximoAlbum = 1;

public:
    // EDIÇÃO DE CATÁLOGO
    void adicionarArtista(const std::string& nome, const std::string& pais, const std::string& genero);
    void adicionarAlbum(const std::string& titulo, int id_artista, int ano, float preco, const std::string& formato);
    bool removerAlbum(int idParaApagar);
    bool removerArtista(int idParaApagar);

    // Getters e Auxiliares
    const std::vector<Artista>& obterArtistas() const;
    const std::vector<Album>& obterAlbuns() const;
    Album* obterAlbumPorId(int id);


    // PESQUISA
    std::vector<Album> pesquisarPorGenero(const std::string& generoProcurado);
    std::vector<Album> pesquisaPorAno(int anoProcurado);
    std::vector<Album> pesquisarPorNomedeAlbum(const std::string& nomeProcurado);
    std::vector<Album> pesquisaPorNomedeArtista(const std::string& artistaProcurado);
};

#endif