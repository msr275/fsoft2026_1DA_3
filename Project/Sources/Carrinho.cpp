//
// Created by Guilherme Martins on 27/04/2026.
//

#include "Carrinho.h"
carrinho::carrinho() {}
void carrinho::adicionarAlbum(Album* album) {
    if (album != nullptr) {
        itens.push_back(album);
    }
}

bool carrinho::removerAlbum(int idAlbum) {
    for (auto it = itens.begin(); it != itens.end(); ++it) {
        if ((*it)->getIdAlbum() == idAlbum) {
            itens.erase(it);
            return true;
        }
    }
    return false;
}
float carrinho::calcularTotal() const {
    float total = 0.0f;
    for (const auto& album : itens) {
        total += album->getPreco();
    }
    return total;
}
void carrinho::limparCarrinho() {
    itens.clear();
}
std::vector<Album*> carrinho::getItens() const {
    return itens;
}