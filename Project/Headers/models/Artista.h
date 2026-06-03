#ifndef FSOFT2026_1DA_3_ARTISTA_H
#define FSOFT2026_1DA_3_ARTISTA_H

#include <string>
#include <vector>

class Artista {
private:
    int idArtista;
    std::string nome;
    std::string pais;
    std::string genero;

    static std::vector<Artista> listaArtistas;
    static int idproximoArtista;

public:
    // Construtor
    Artista(int idArtista, const std::string& nome, const std::string& pais, const std::string& genero);

    // Getters
    int get_id_artista() const;
    std::string get_nome() const;
    std::string get_pais() const;
    std::string get_genero() const;

    // Setters
    void set_nome(const std::string& nome);
    void set_pais(const std::string& pais);
    void set_genero(const std::string& genero);

    //ManagerCatálogo
    static void adicionarArtista(const std::string& nome, const std::string& pais, const std::string& genero);
    static bool removerArtista(int idParaApagar);
    static const std::vector<Artista>& obterArtistas();
    static Artista* obterArtistaPorId(int id);
    static int obterIdPorNome(const std::string& nomeProcurado);
};

#endif // FSOFT2026_1DA_3_ARTISTA_H