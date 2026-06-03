#include "../../Headers/controllers/Pesquisa.h"
#include "../../Headers/models/Album.h"
#include "../../Headers/models/Artista.h"

std::vector<Album> Pesquisa::pesquisarPorGenero(const std::string& generoProcurado) {
    std::vector<Album> resultados;
    // Importa a lista real e estática guardada na classe Album
    const std::vector<Album>& listaAlbuns = Album::obterAlbuns();

    for (size_t i = 0; i < listaAlbuns.size(); i++) {
        if (listaAlbuns[i].get_artista() != nullptr && listaAlbuns[i].get_artista()->get_genero() == generoProcurado){
            resultados.push_back(listaAlbuns[i]);
        }
    }
    return resultados;
}

std::vector<Album> Pesquisa::pesquisaPorAno(int anoProcurado) {
    std::vector<Album> resultados;
    const std::vector<Album>& listaAlbuns = Album::obterAlbuns();

    for (size_t i = 0; i < listaAlbuns.size(); i++) {
        if (listaAlbuns[i].ano1() == anoProcurado) {
            resultados.push_back(listaAlbuns[i]);
        }
    }
    return resultados;
}

std::vector<Album> Pesquisa::pesquisarPorNomedeAlbum(const std::string& nomeProcurado) {
    std::vector<Album> resultados;
    const std::vector<Album>& listaAlbuns = Album::obterAlbuns();

    for (size_t i = 0; i < listaAlbuns.size(); i++) {
        std::string tituloAlbum = listaAlbuns[i].titulo1();
        if (tituloAlbum.find(nomeProcurado) != std::string::npos) {
            resultados.push_back(listaAlbuns[i]);
        }
    }
    return resultados;
}

std::vector<Album> Pesquisa::pesquisaPorNomedeArtista(const std::string& artistaProcurado) {
    std::vector<Album> resultados;
    const std::vector<Album>& listaAlbuns = Album::obterAlbuns();

    for (size_t i = 0; i < listaAlbuns.size(); i++) {
        if (listaAlbuns[i].get_artista() != nullptr) {
            std::string nomeArtista = listaAlbuns[i].get_artista()->get_nome();
            if (nomeArtista.find(artistaProcurado) != std::string::npos) {
                resultados.push_back(listaAlbuns[i]);
            }
        }
    }
    return resultados;
}