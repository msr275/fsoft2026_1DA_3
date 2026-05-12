#ifndef FSOFT2026_1DA_3_MANAGERCATALOGO_H
#define FSOFT2026_1DA_3_MANAGERCATALOGO_H
#include "Artista.h"
#include "Album.h"
#include <vector>


class ManagerCatalogo {
private:
    std::vector<Artista> listaArtistas;//vetor de artistas
    std::vector<Album> listaAlbuns;//vetor de albuns

    //para poder atribuir,incrementalmente os ids
    int idproximoArtista = 1;
    int idproximoAlbum = 1;

public:
    //adiciona aos vetores respetivos
    void adicionarArtista(const std :: string& nome,const std :: string& pais,const std :: string& genero);
    void adicionarAlbum(const Album &b);
    //remove dos vetores
    bool removerAlbum(int idParaApagar);
    bool removerArtista(int idParaApagar);

    //PESQUISA
    std::vector<Album> pesquisarPorGenero(const std::string& generoProcurado);
    std::vector<Album> pesquisaPorAno(int anoProcurado);
    std::vector<Album> pesquisarPorNomedeAlbum(const std::string& nomeProcurado);
    std::vector<Album> pesquisaPorNomedeArtista(const std::string& artistaProcurado);
};

#endif //FSOFT2026_1DA_3_MANAGERCATALOGO_H