#include "../../Headers/models/Carrinho.h"


Carrinho::Carrinho() {}

// Adiciona o apontador do álbum ao carrinho
void Carrinho::adicionarAlbum(Album* album) {
    if (album != nullptr) {
        itens.push_back(album);
    }
}

// Remove o álbum do carrinho
bool Carrinho::removerAlbum(int idAlbum) {
    for (auto it = itens.begin(); it != itens.end(); ++it) { //auto ajusta o tipo de dados consoante o seu uso
        if ((*it)->id_album() == idAlbum) { // *it vai aceder ao apontador do álbum atual
            itens.erase(it);
            return true;
        }
    }
    return false;
}

// Calcula o total
float Carrinho::calcularTotal() const {
    float total = 0.0f;
    for (const auto& album : itens) {
        total += album->preco1();
    }
    return total;
}

// Limpa o carrinho
void Carrinho::limparCarrinho() {
    itens.clear();
}

// Devolve a lista de apontadores
std::vector<Album*> Carrinho::getItens() const {
    return itens;
}