#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

class Album {
private:
    int idAlbum;
    int idArtista;
    std :: string titulo;
    int ano;
    float preco;
    std :: string formato;
public:
    //inicializaçao do album
    Album(int idAlbum, int idArtista, const std :: string& titulo, int ano, float preco,const std :: string& formato) {
        this -> idAlbum = idAlbum;
        this -> idArtista = idArtista;
        this -> titulo = titulo;
        this -> ano = ano;
        this -> preco = preco;
        this -> formato = formato;
    }

    int id_album() const { return idAlbum; }
    int id_artista() const { return idArtista; }
    std::string titulo1() const { return titulo; }
    int ano1() const { return ano; }
    float preco1() const { return preco; }


    void set_id_album(int id_album) { idAlbum = id_album; }
    void set_id_artista(int id_artista) { idArtista = id_artista; }
    void set_titulo(const std::string &titulo) { this->titulo = titulo; }
    void set_ano(int ano) { this->ano = ano; }
    void set_preco(float preco) { this->preco = preco; }

};