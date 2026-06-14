#ifndef FSOFT2026_1DA_3_VENDA_H
#define FSOFT2026_1DA_3_VENDA_H

#include <string>
#include "Carrinho.h"

class Venda {
private:
    int idVenda;
    std::string data;
    float valorTotal;

public:
    Venda(int id, const std::string& dataAtual, const Carrinho& cart);//construtor
    //GETTERS
    int getIdVenda() const;
    std::string getData() const;
    float getValorTotal() const;
    //Imprime fatura
    void exibirRecibo() const;
};
#endif