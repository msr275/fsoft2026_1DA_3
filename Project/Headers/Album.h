#ifndef FSOFT2026_1DA_3_ALBUM_H
#define FSOFT2026_1DA_3_ALBUM_H
#include <string>


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

    int id_album() const;
    int id_artista() const;
    std::string titulo1() const;
    int ano1() const;
    float preco1() const;


    void set_id_album(int id_album);
    void set_id_artista(int id_artista);
    void set_titulo(const std::string &titulo);
    void set_ano(int ano);
    void set_preco(float preco);

};

#endif //FSOFT2026_1DA_3_ALBUM_H