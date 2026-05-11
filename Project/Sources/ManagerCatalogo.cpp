#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include "Artista.h"
#include "Album.h"

class ManagerCatalogo {
private:
    std::vector<Artista> listaArtistas;//vetor de artistas
    std::vector<Album> listaAlbuns;//vetor de albuns

    //para poder atribuir,incrementalmente os ids
    int idproximoArtista = 1;
    int idproximoAlbum = 1;

public:
    //adiciona aos vetores respetivos
    void adicionarArtista(const std :: string& nome,const std :: string& pais,const std :: string& genero) {
        Artista a(idproximoArtista,nome,pais,genero);
        listaArtistas.push_back(a);
        idproximoArtista++;
    }

    void adicionarAlbum(const std::string& titulo, int id_artista, int ano, float preco, const std::string& formato) {
        bool artistaEncontrado = false;

        //verifica se exista já o artista
        for (int z = 0; z < listaArtistas.size(); z++) {
            if (listaArtistas.at(z).get_id_artista() == id_artista) {
                artistaEncontrado = true;
                break;
            }
        }
        if (artistaEncontrado) {
            Album novoAlbum(idproximoAlbum, id_artista, titulo, ano, preco, formato);

            listaAlbuns.push_back(novoAlbum);
            idproximoAlbum++;
        } else {
            //erro se não houver artista associado ao álbum
            throw std::invalid_argument("Erro: Álbum sem artista associado.");
        }
    }

    bool removerAlbum(int idParaApagar) {
        for (int i = 0; i < listaAlbuns.size(); i++) {
            if (listaAlbuns[i].id_album() == idParaApagar) {
                listaAlbuns.erase(listaAlbuns.begin() + i);
                return true;
            }
        }
        return false;
    }

    bool removerArtista(int idParaApagar) {
        for (int i = listaAlbuns.size()-1;i>=0; i--) {
            if (listaAlbuns[i].id_artista() == idParaApagar) {
                listaAlbuns.erase(listaAlbuns.begin()+i);
            }
        }
        for (int i=0;i<listaArtistas.size();i++) {
            if (listaArtistas[i].get_id_artista() == idParaApagar) {
                listaArtistas.erase(listaArtistas.begin()+i);
                return true;
            }
        }
        return false;
    }
};