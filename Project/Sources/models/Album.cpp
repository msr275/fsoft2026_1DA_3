#include "../../Headers/models/Album.h"
#include "../../Headers/models/Artista.h"
#include "../../Headers/exceptions/InvalidDataException.h"
#include "../../Headers/views/Utils.h"


std::vector<Album> Album::listaAlbuns = {};
int Album::idproximoAlbum = 1;

// Construtor
Album::Album(int idAlbum, Artista* artistaPtr, const std::string& titulo, int ano, float preco, const std::string& formato, float novoRating) {
    this->idAlbum = idAlbum;
    this->artista = artistaPtr;
    set_titulo(titulo);
    set_ano(ano);
    set_preco(preco);
    set_formato(formato);
    set_rating(novoRating);
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
void Album::set_artista(Artista* novoArtista) {
    if (artista == nullptr) {
        throw InvalidDataException("Erro: O álbum necessita de um artista válido associado!");
    }
    this->artista = novoArtista;
}

void Album::set_titulo(const std::string &titulo) {
    std::string tituloValido = limparEspacos(titulo);
    if (tituloValido.empty()) {
        throw InvalidDataException("Erro: O título do álbum não pode estar em branco!");
    }
    this->titulo = tituloValido;
}

void Album::set_ano(int ano) {
    if (ano < 1700 || ano > 2026) {
        throw InvalidDataException("Erro: Ano inválido! O ano deve situar-se entre 1900 e 2026.");
    }
    this->ano = ano;
}

void Album::set_preco(float preco) {
    if (preco < 0.0f) {
        throw InvalidDataException("Erro: O preço do álbum não pode ser negativo!");
    }
    this->preco = preco;
}

void Album::set_rating(float novoRating) {
    rating = novoRating;
}

void Album::set_formato(const std:: string &formato) {
    std::string formatoLimpo = limparEspacos(formato);

    std::string formMinusculo = formatoLimpo;
    for (char &c : formMinusculo) {
        c = std::tolower(static_cast<unsigned char>(c));
    }

    if (formMinusculo == "vinil") {
        this->formato = "Vinil";
    } else if (formMinusculo == "cd") {
        this->formato = "CD";
    } else if (formMinusculo == "digital") {
        this->formato = "Digital";
    } else {
        throw InvalidDataException("Erro: Formato inválido! Escolha apenas entre 'Vinil', 'CD' ou 'Digital'.");
    }
}
//------------------------_MANAGER CATALOGO----------------------------------------//
void Album::adicionarAlbum(const std::string& titulo, int id_artista, int ano, float preco, const std::string& formato) {
    Artista* artistaEncontrado = Artista::obterArtistaPorId(id_artista);

    if (artistaEncontrado != nullptr) {
        Album novoAlbum(idproximoAlbum, artistaEncontrado, titulo, ano, preco, formato, 0.0f);
        listaAlbuns.push_back(novoAlbum);
        idproximoAlbum++;
    } else {
        throw std::invalid_argument("Erro: Álbum sem artista associado.");
    }
}

bool Album::removerAlbum(int idParaApagar) {
    for (size_t i = 0; i < listaAlbuns.size(); i++) {
        if (listaAlbuns[i].id_album() == idParaApagar) {
            listaAlbuns.erase(listaAlbuns.begin() + i);
            return true;
        }
    }
    return false;
}

Album* Album::obterAlbumPorId(int id) {
    for (size_t i = 0; i < listaAlbuns.size(); i++) {
        if (listaAlbuns[i].id_album() == id) {
            return &listaAlbuns[i];
        }
    }
    return nullptr;
}

const std::vector<Album>& Album::obterAlbuns() {
    return listaAlbuns;
}

void Album::limparAlbunsPorArtista(int idArtistaParaApagar) {
    for (int i = static_cast<int>(listaAlbuns.size()) - 1; i >= 0; i--) {
        if (listaAlbuns[i].get_artista() != nullptr && listaAlbuns[i].get_artista()->get_id_artista() == idArtistaParaApagar) {
            listaAlbuns.erase(listaAlbuns.begin() + i);
        }
    }
}
