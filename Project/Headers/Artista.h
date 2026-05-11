#ifndef FSOFT2026_1DA_3_ARTISTA_H
#define FSOFT2026_1DA_3_ARTISTA_H
#include <string>

class Artista {
private:
    int idArtista;
    std :: string nome;
    std :: string pais;
    std :: string genero;
public:
    //inicializaçao do artista
    Artista(int idArtista,const std :: string& nome,const std :: string& pais,const std :: string& genero);

    int get_id_artista() const;
    std::string get_nome() const;
    std::string get_pais() const;
    std::string get_genero() const;

    void set_nome(const std::string& nome);
    void set_pais(const std::string& pais);
    void set_genero(const std::string& genero);

};

#endif