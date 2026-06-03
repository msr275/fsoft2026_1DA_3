#ifndef FSOFT2026_1DA_3_ALBUM_H
#define FSOFT2026_1DA_3_ALBUM_H

#include <string>
#include <vector>


class Artista;

class Album {
private:
    int idAlbum;
    Artista* artista;
    std::string titulo;
    int ano;
    float preco;
    std::string formato;
    float rating;

    static std::vector<Album> listaAlbuns;
    static int idproximoAlbum;

public:
    // Construtor
    Album(int idAlbum, Artista* artistaPtr, const std::string& titulo, int ano, float preco, const std::string& formato, float novoRating = 0.0f);

    // Getters
    int id_album() const;
    Artista* get_artista() const;
    int id_artista() const;
    std::string titulo1() const;
    int ano1() const;
    float preco1() const;
    std::string formato1() const;
    float rating1() const;

    // Setters
    void set_artista(Artista* novoArtista);
    void set_titulo(const std::string &titulo);
    void set_ano(int ano);
    void set_preco(float preco);
    void set_rating(float novoRating);
    void set_formato(const std:: string &formato);

    //--------------------------------MANAGER CATALOGO--------------------_//
    static void adicionarAlbum(const std::string& titulo, int id_artista, int ano, float preco, const std::string& formato);
    static bool removerAlbum(int idParaApagar);
    static Album* obterAlbumPorId(int id);
    static const std::vector<Album>& obterAlbuns();
    static void limparAlbunsPorArtista(int idArtistaParaApagar);
};

#endif // FSOFT2026_1DA_3_ALBUM_H