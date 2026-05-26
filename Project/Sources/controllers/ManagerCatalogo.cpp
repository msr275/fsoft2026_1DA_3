#include "../../Headers/controllers/ManagerCatalogo.h"
#include <iostream>
#include <stdexcept>

#include "exceptions/InvalidDataException.h"

//--------------------------------------EDIÇÃO DE CATÁLOGO------------------------------

void ManagerCatalogo::adicionarArtista(const std::string& nome, const std::string& pais, const std::string& genero) {
    Artista a(idproximoArtista, nome, pais, genero);
    listaArtistas.push_back(a);
    idproximoArtista++;
}

void ManagerCatalogo::adicionarAlbum(const std::string& titulo, int id_artista, int ano, float preco, const std::string& formato) {
    Artista* artistaEncontrado = nullptr;

    // verifica se já existe o artista
    for (size_t i = 0; i < listaArtistas.size(); i++) {
        if (listaArtistas[i].get_id_artista() == id_artista) {
            artistaEncontrado = &listaArtistas[i];
            break;
        }
    }
    if (artistaEncontrado != nullptr) {
        Album novoAlbum(idproximoAlbum, artistaEncontrado, titulo, ano, preco, formato);
        listaAlbuns.push_back(novoAlbum);
        idproximoAlbum++;
    } else {
        // erro se não houver artista associado ao álbum
        throw std::invalid_argument("Erro: Álbum sem artista associado.");
    }
}

bool ManagerCatalogo::removerAlbum(int idParaApagar) {
    for (size_t i = 0; i < listaAlbuns.size(); i++) {
        if (listaAlbuns[i].id_album() == idParaApagar) {
            listaAlbuns.erase(listaAlbuns.begin() + i);
            return true;
        }
    }
    return false;
}

bool ManagerCatalogo::removerArtista(int idParaApagar) {
    for (int i = static_cast<int>(listaAlbuns.size()) - 1; i >= 0; i--) {
        if (listaAlbuns[i].get_artista() != nullptr && listaAlbuns[i].get_artista()->get_id_artista()==idParaApagar) {
            listaAlbuns.erase(listaAlbuns.begin() + i);
        }
    }
    for (size_t i = 0; i < listaArtistas.size(); i++) {
        if (listaArtistas[i].get_id_artista() == idParaApagar) {
            listaArtistas.erase(listaArtistas.begin() + i);
            return true;
        }
    }
    return false;
}

Album* ManagerCatalogo::obterAlbumPorId(int id) {
    for (size_t i = 0; i < listaAlbuns.size(); i++) {
        if (listaAlbuns[i].id_album() == id) {
            return &listaAlbuns[i];
        }
    }
    return nullptr;
}

const std::vector<Artista>& ManagerCatalogo::obterArtistas() const {
    return listaArtistas;
}

const std::vector<Album>& ManagerCatalogo::obterAlbuns() const {
    return listaAlbuns;
}

//---------------------------------- PESQUISA----------------------------------------

std::vector<Album> ManagerCatalogo::pesquisarPorGenero(const std::string& generoProcurado) {
    std::vector<Album> resultados;
    for (size_t i = 0; i < listaAlbuns.size(); i++) {
            if (listaAlbuns[i].get_artista() != nullptr && listaAlbuns[i].get_artista()->get_genero() == generoProcurado){
                    resultados.push_back(listaAlbuns[i]);


            }
    }
    return resultados;
}

std::vector<Album> ManagerCatalogo::pesquisaPorAno(int anoProcurado) {
    std::vector<Album> resultados;
    for (size_t i = 0; i < listaAlbuns.size(); i++) {
        if (listaAlbuns[i].ano1() == anoProcurado) {
            resultados.push_back(listaAlbuns[i]);
        }
    }
    return resultados;
}

std::vector<Album> ManagerCatalogo::pesquisarPorNomedeAlbum(const std::string& nomeProcurado) {
    std::vector<Album> resultados;
    for (size_t i = 0; i < listaAlbuns.size(); i++) {
        std::string tituloAlbum = listaAlbuns[i].titulo1();
        if (tituloAlbum.find(nomeProcurado) != std::string::npos) {
            resultados.push_back(listaAlbuns[i]);
        }
    }
    return resultados;
}

std::vector<Album> ManagerCatalogo::pesquisaPorNomedeArtista(const std::string& artistaProcurado) {
    std::vector<Album> resultados;
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