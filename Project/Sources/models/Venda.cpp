#include "../../Headers/models/Venda.h"
#include <iostream>

Venda::Venda(int id, const std::string& dataAtual, const Carrinho& cart)
    : idVenda(id), data(dataAtual) {
    valorTotal = cart.calcularTotal();
}

int Venda::getIdVenda() const {
    return idVenda;
}

std::string Venda::getData() const {
    return data;
}

float Venda::getValorTotal() const {
    return valorTotal;
}

void Venda::exibirRecibo() const {
    std::cout << "--- Recibo da Venda ---" << std::endl;
    std::cout << "ID Venda: " << idVenda << std::endl;
    std::cout << "Data: " << data << std::endl;
    std::cout << "Total a pagar: " << valorTotal << " EUR" << std::endl;
    std::cout << "-----------------------" << std::endl;
}