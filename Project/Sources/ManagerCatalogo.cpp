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

    //--------------------------------------EDIÇÃO DE CATÁLOGO------------------------------
    //adiciona aos vetores respetivos
    void adicionarArtista(const std :: string& nome,const std :: string& pais,const std :: string& genero) {
        Artista a(idproximoArtista,nome,pais,genero);
        listaArtistas.push_back(a);
        idproximoArtista++;
    }

    void adicionarAlbum(const std::string& titulo, int id_artista, int ano, float preco, const std::string& formato) {
        bool artistaEncontrado = false;

        //verifica se exista já o artista
        for (int i = 0; i < listaArtistas.size(); i++) {
            if (listaArtistas[i].get_id_artista() == id_artista) {
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




   //---------------------------------- PESQUISA----------------------------------------

//pesquisa por género, vai retornar vetor de albuns que correspondem a X género
    std::vector<Album> pesquisarPorGenero(const std::string& generoProcurado) {
        std::vector<Album> resultados;
//percorre albuns, vai ver cada artista associado ao album e ve o seu género associado, se corresponder, adiciona ao vetor resultados
        for (int i = 0; i < listaAlbuns.size(); i++) {
            for (int j = 0; j < listaArtistas.size(); j++) {
                if (listaArtistas[j].get_id_artista() == listaAlbuns[i].id_artista()) {
                    if (listaArtistas[j].get_genero() == generoProcurado) {
                        resultados.push_back(listaAlbuns[i]);
                    }
                    break;
                }
            }
        }
        return resultados;
    }

//pesquisa por ano
    std::vector<Album> pesquisaPorAno(int anoProcurado) {
        std::vector<Album> resultados;

        for (int i=0; i< listaAlbuns.size();i++) {
            if (listaAlbuns[i].ano1()==anoProcurado) {
                resultados.push_back((listaAlbuns[i]));
            }
        }
        return resultados;
    }

//pesquisa por nome de Álbum
    std::vector<Album> pesquisarPorNomedeAlbum(const std::string& nomeProcurado) {
        std::vector<Album> resultados;

        for (int i = 0; i < listaAlbuns.size(); i++) {
            std::string tituloAlbum = listaAlbuns[i].titulo1();
            //find procura nomes semelhantes ao escrito pelo utilizador e devolve o sítio(indíce) em q a palavra começa
            if (tituloAlbum.find(nomeProcurado) != std::string::npos) { //npos basicamente diz q n encontrou nada
                resultados.push_back(listaAlbuns[i]);
            }
        }
        return resultados;
    }

    // pesquisa por nome de artista
    std::vector<Album> pesquisaPorNomedeArtista(const std::string& artistaProcurado) {
        std::vector<Album> resultados;
//percorre albuns e ve artista associado, guardando o seu nome. Usa-se se o find para ver se o utilizador pesquisou por algo parecido ocm esse artista
        for (int i = 0; i < listaAlbuns.size(); i++) {
            for (int j = 0; j < listaArtistas.size(); j++) {
                if (listaArtistas[j].get_id_artista() == listaAlbuns[i].id_artista()) {
                    std::string nomeArtista = listaArtistas[j].get_nome();

                    if (nomeArtista.find(artistaProcurado) != std::string::npos) {
                        resultados.push_back(listaAlbuns[i]);
                    }
                    break;
                }
            }
        }
        return resultados;
    }
};