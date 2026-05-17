#ifndef FSOFT2026_1DA_3_VENDA_H
#define FSOFT2026_1DA_3_VENDA_H

#include <string>
#include "carrinho.h"

class Venda {
private:
    int idVenda;
    std::string data;
    float valorTotal;

public:
    Venda(int id, const std::string& dataAtual, const carrinho& cart);
    int getIdVenda() const;
    std::string getData() const;
    float getValorTotal() const;
    void exibirRecibo() const;
};
#endif