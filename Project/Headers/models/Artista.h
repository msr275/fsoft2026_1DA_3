#ifndef FSOFT2026_1DA_3_ARTISTA_H
#define FSOFT2026_1DA_3_ARTISTA_H
#include <string>

class Artista {
private:
    int idArtista;
    std::string nome;
    std::string pais;
    std::string genero;

public:
    // construtor
    Artista(int idArtista, const std::string& nome, const std::string& pais, const std::string& genero) {
        this->idArtista = idArtista;
        this->nome = nome;
        this->pais = pais;
        this->genero = genero;
    }

    // Getters
    int get_id_artista() const { return idArtista; }
    std::string get_nome() const { return nome; }
    std::string get_pais() const { return pais; }
    std::string get_genero() const { return genero; }

    // Setters
    void set_nome(const std::string& nome) { this->nome = nome; }
    void set_pais(const std::string& pais) { this->pais = pais; }
    void set_genero(const std::string& genero) { this->genero = genero; }
};

#endif