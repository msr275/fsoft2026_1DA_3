//
// Created by Guilherme Martins on 27/04/2026.
//

#ifndef FSOFT2026_1DA_3_CARRINHO_H
#define FSOFT2026_1DA_3_CARRINHO_H

#include <vector>
#include "Album.h"

class carrinho {
private:
    std::vector<Album*> itens;
public:
    carrinho();
    void adicionarAlbum(Album* album);
    bool removerAlbum(int idAlbum);
    float calcularTotal() const;
    void limparCarrinho();
    std::vector<Album*> getItens() const;
};

#endif //FSOFT2026_1DA_3_CARRINHO_H