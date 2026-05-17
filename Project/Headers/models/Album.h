#ifndef FSOFT2026_1DA_3_ALBUM_H
#define FSOFT2026_1DA_3_ALBUM_H
#include <string>

class Album {
private:
    int idAlbum;
    int idArtista;
    std::string titulo;
    int ano;
    float preco;
    std::string formato;
    float rating;

public:
    //construtor
    Album(int idAlbum, int idArtista, const std::string& titulo, int ano, float preco, const std::string& formato,float novoRating = 0.0f) {
        this->idAlbum = idAlbum;
        this->idArtista = idArtista;
        this->titulo = titulo;
        this->ano = ano;
        this->preco = preco;
        this->formato = formato;
        this->rating = novoRating;
    }

    // Getters
    int id_album() const { return idAlbum; }
    int id_artista() const { return idArtista; }
    std::string titulo1() const { return titulo; }
    int ano1() const { return ano; }
    float preco1() const { return preco; }
    std::string formato1() const { return formato; }
    float rating1() const { return rating; }


    // Setters
    void set_id_album(int id_album) { idAlbum = id_album; }
    void set_id_artista(int id_artista) { idArtista = id_artista; }
    void set_titulo(const std::string &titulo) { this->titulo = titulo; }
    void set_ano(int ano) { this->ano = ano; }
    void set_preco(float preco) { this->preco = preco; }
    void set_rating(float novoRating) { rating = novoRating; }
};

#endif//FSOFT2026_1DA_3_ALBUM_H