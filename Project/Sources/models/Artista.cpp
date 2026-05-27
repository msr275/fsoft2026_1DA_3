#include "../../Headers/models/Artista.h"

// Construtor
Artista::Artista(int idArtista, const std::string& nome, const std::string& pais, const std::string& genero) {
    this->idArtista = idArtista;
    this->nome = nome;
    this->pais = pais;
    this->genero = genero;
}

// Implementação dos Getters
int Artista::get_id_artista() const {
    return idArtista;
}

std::string Artista::get_nome() const {
    return nome;
}

std::string Artista::get_pais() const {
    return pais;
}

std::string Artista::get_genero() const {
    return genero;
}

// Implementação dos Setters
void Artista::set_nome(const std::string& nome) {
    this->nome = nome;
}

void Artista::set_pais(const std::string& pais) {
    this->pais = pais;
}

void Artista::set_genero(const std::string& genero) {
    this->genero = genero;
}