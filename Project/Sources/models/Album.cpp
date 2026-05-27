#include "../../Headers/models/Album.h"
#include "../../Headers/models/Artista.h"

// Construtor
Album::Album(int idAlbum, Artista* artistaPtr, const std::string& titulo, int ano, float preco, const std::string& formato, float novoRating) {
    this->idAlbum = idAlbum;
    this->artista = artistaPtr;
    this->titulo = titulo;
    this->ano = ano;
    this->preco = preco;
    this->formato = formato;
    this->rating = novoRating;
}

// Implementação dos Getters
int Album::id_album() const {
    return idAlbum;
}

Artista* Album::get_artista() const {
    return artista;
}

int Album::id_artista() const {
    if (artista != nullptr) {
        return artista->get_id_artista();
    }
    return -1;
}

std::string Album::titulo1() const {
    return titulo;
}

int Album::ano1() const {
    return ano;
}

float Album::preco1() const {
    return preco;
}

std::string Album::formato1() const {
    return formato;
}

float Album::rating1() const {
    return rating;
}

//Implementação dos Setters
void Album::set_id_album(int id_album) {
    idAlbum = id_album;
}

void Album::set_artista(Artista* novoArtista) {
    artista = novoArtista;
}

void Album::set_titulo(const std::string &titulo) {
    this->titulo = titulo;
}

void Album::set_ano(int ano) {
    this->ano = ano;
}

void Album::set_preco(float preco) {
    this->preco = preco;
}

void Album::set_rating(float novoRating) {
    rating = novoRating;
}
