#ifndef FSOFT2026_1DA_3_CARRINHO_H
#define FSOFT2026_1DA_3_CARRINHO_H

#include <vector>
#include "Album.h"

class Carrinho {
private:
    std::vector<Album*> itens;// usamos apontador para n duplicarmos por acaso um álbum
public:
    Carrinho();//construtor
    void adicionarAlbum(Album* album);
    bool removerAlbum(int idAlbum);
    float calcularTotal() const;
    void limparCarrinho();
    std::vector<Album*> getItens() const;//devolve lista de álbuns q foram adicionados ao carrinho
};

#endif //FSOFT2026_1DA_3_CARRINHO_H