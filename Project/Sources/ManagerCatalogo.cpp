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

    bool removerArtista(int idparaapagar) {
        bool ArtistaEncontrado = false;

        for (int z=0; z<listaArtistas.size();z++) {

        }
    }
};