#include "../../Headers/models/Album.h"
#include "../../Headers/models/Artista.h"
#include "../../Headers/exceptions/InvalidDataException.h"
#include "../../Headers/views/Utils.h"
#include <stdexcept>

std::vector<Album> Album::listaAlbuns = {};
int Album::idproximoAlbum = 1;

// Construtor
Album::Album(int idAlbum, Artista* artistaPtr, const std::string& titulo, int ano, float preco, const std::string& formato, float novoRating) {
    this->idAlbum = idAlbum;
    set_artista(artistaPtr);
    set_titulo(titulo);
    set_ano(ano);
    set_preco(preco);
    set_formato(formato);
    set_rating(novoRating);
}

//----------------------------IMPLEMENTAÇÃO DE GETTERS---------------------------//
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
//-----------------------------IMPLEMENTAÇÃO DE SETTERS--------------------------//
void Album::set_artista(Artista* novoArtista) {
    if (novoArtista == nullptr) {
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
        throw InvalidDataException("Erro: Ano inválido! O ano deve situar-se entre 1700 e 2026.");
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
    if (novoRating < 0.0f || novoRating > 5.0f) {
        throw InvalidDataException("Erro: O rating deve ser um valor entre 0 e 5!");
    }
    this->rating = novoRating;
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
//------------------------_MANAGER CATALOGO ANTIGO----------------------------------------//

//recebe os parâmetros do álbum, se houver artista associado realmente, ele vai adicionar um álbum ao vetor de álbuns e incrementar os ids. Se n houver artista associado, o programa dá erro e aavisa o user.
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
// pega no id do álbum e percorre a lista de álbuns, se o encontrar, elimina-o do vetor.
bool Album::removerAlbum(int idParaApagar) {
    for (size_t i = 0; i < listaAlbuns.size(); i++) {
        if (listaAlbuns[i].id_album() == idParaApagar) {
            listaAlbuns.erase(listaAlbuns.begin() + i);
            return true;
        }
    }
    return false;
}
// fornecer id de álbum, percorrer o vetor à sua procura e devolver o seu endereço. Se n encontrar, não retorna nada.
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

//Usado no caso de eliminarmos um artista, pois temos de eliminar todos os seus álbuns
void Album::limparAlbunsPorArtista(int idArtistaParaApagar) {
    for (int i = static_cast<int>(listaAlbuns.size()) - 1; i >= 0; i--) { // static_cast<int> converte o tamanho do vetor size_t ----> int
        if (listaAlbuns[i].get_artista() != nullptr && listaAlbuns[i].get_artista()->get_id_artista() == idArtistaParaApagar) {// garante q álbum tem artista associado e se o seu id é oq realmente queremos apagar.
            listaAlbuns.erase(listaAlbuns.begin() + i);
        }
    }
}
//loop começa do fim para o ínicio pois quando eliminamos um item com erase, o vetor diminui e os seus elementos mudam de poisção
// se não fizessemos assim, acabavamos por tentar aceder a elementos q já não vão existir.