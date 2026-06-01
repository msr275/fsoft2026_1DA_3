#include "../../Headers/models/Artista.h"
#include "../../Headers/exceptions/InvalidDataException.h"
#include "../Headers/views/Utils.h"

// Construtor
Artista::Artista(int idArtista, const std::string& nome, const std::string& pais, const std::string& genero) {
    this->idArtista = idArtista;
    set_nome(nome);
    set_pais(pais);
    set_genero(genero);
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
    std::string nomeValido = limparEspacos(nome);
    if (nomeValido.empty()) {
        throw InvalidDataException("Erro: O nome do artista não pode estar em branco!");
    }
    this->nome = nomeValido;
}

void Artista::set_pais(const std::string& pais) {
    std::string paisValido = limparEspacos(pais);
    if (paisValido.empty()) {
        throw InvalidDataException("Erro: O país do artista não pode estar em branco!");
    }
    this->pais = paisValido;
}

void Artista::set_genero(const std::string& genero) {
    std::string generoValido = limparEspacos(genero);
    if (generoValido.empty()) {
        throw InvalidDataException("Erro: O género do artista não pode estar em branco!");
    }
    this->genero = generoValido;
}