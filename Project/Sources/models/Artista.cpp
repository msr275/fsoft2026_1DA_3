#include "../../Headers/models/Artista.h"
#include "../../Headers/models/Album.h"
#include "../../Headers/exceptions/InvalidDataException.h"
#include "../../Headers/views/Utils.h"

std::vector<Artista> Artista::listaArtistas = {};
int Artista::idproximoArtista = 1;

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

//-------------------------MANAGER CATÁLOGO----------------------------------//

void Artista::adicionarArtista(const std::string& nome, const std::string& pais, const std::string& genero) {
    Artista a(idproximoArtista, nome, pais, genero);
    listaArtistas.push_back(a);
    idproximoArtista++;
}

bool Artista::removerArtista(int idParaApagar) {
    Album::limparAlbunsPorArtista(idParaApagar);
    for (size_t i = 0; i < listaArtistas.size(); i++) {
        if (listaArtistas[i].get_id_artista() == idParaApagar) {
            listaArtistas.erase(listaArtistas.begin() + i);
            return true;
        }
    }
    return false;
}

const std::vector<Artista>& Artista::obterArtistas() {
    return listaArtistas;
}

Artista* Artista::obterArtistaPorId(int id) {
    for (size_t i = 0; i < listaArtistas.size(); i++) {
        if (listaArtistas[i].get_id_artista() == id) {
            return &listaArtistas[i];
        }
    }
    return nullptr;
}

int Artista::obterIdPorNome(const std::string& nomeProcurado) {
    for (size_t i = 0; i < listaArtistas.size(); i++) {
        if (listaArtistas[i].get_nome().find(nomeProcurado) != std::string::npos) {
            return listaArtistas[i].get_id_artista();
        }
    }
    return -1;
}