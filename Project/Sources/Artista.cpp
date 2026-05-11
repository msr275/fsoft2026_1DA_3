#include <string>
#include <stdexcept>

class Artista {
private:
    int idArtista;
    std :: string nome;
    std :: string pais;
    std :: string genero;
public:
    //inicializaçao do artista
    Artista(int idArtista,const std :: string& nome,const std :: string& pais,const std :: string& genero) {
        this -> idArtista = idArtista;
        this -> nome = nome;
        this -> pais = pais;
        this -> genero = genero;
    }

    int get_id_artista() const { return idArtista; }
    std::string get_nome() const { return nome; }
    std::string get_pais() const { return pais; }
    std::string get_genero() const { return genero; }

    void set_nome(const std::string& nome) { this->nome = nome; }
    void set_pais(const std::string& pais) { this->pais = pais; }
    void set_genero(const std::string& genero) { this->genero = genero; }

};