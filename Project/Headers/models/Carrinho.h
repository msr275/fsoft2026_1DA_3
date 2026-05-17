#ifndef FSOFT2026_1DA_3_CARRINHO_H
#define FSOFT2026_1DA_3_CARRINHO_H

#include <vector>
#include "Album.h"

class Carrinho {
private:
    std::vector<Album*> itens;
public:
    Carrinho();
    void adicionarAlbum(Album* album);
    bool removerAlbum(int idAlbum);
    float calcularTotal() const;
    void limparCarrinho();
    std::vector<Album*> getItens() const;
};

#endif //FSOFT2026_1DA_3_CARRINHO_H