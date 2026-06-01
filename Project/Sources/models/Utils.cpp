#include "../../Headers/views/Utils.h"
#include <iostream>
#include <limits>
#include <string>

void displayHeader() {
    std::cout << "\n------------------------" << std::endl;
    std::cout << "|LOJA DE MÚSICA DO GRUPO 3|" << std::endl;
    std::cout << "------------------------\n" << std::endl;
}

//garante que o utilizador digita um número
int getSafeInt(std::string prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            return value;
        } else {
            std::cout << "[ERRO] Entrada invalida! Por favor, introduza um numero." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

//para ter sempre valores válidos
int getSafeInt(std::string prompt, int min, int max) {
    int value;
    while (true) {
        value = getSafeInt(prompt); // Chama a função acima
        if (value >= min && value <= max) {
            return value;
        }
        std::cout << "[ERRO] Opção inválida. Intervalo permitido: " << min << " - " << max << std::endl;
    }
}

void pressEnterToContinue() {
    std::cout << "\nPressione ENTER para continuar";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

//Limpar strings do user
std::string limparEspacos(const std::string& str) {
    if (str.empty()) return str;
    size_t primeiro = str.find_first_not_of(" \t\r\n");
    if (primeiro == std::string::npos) return "";
    size_t ultimo = str.find_last_not_of(" \t\r\n");
    return str.substr(primeiro, (ultimo - primeiro + 1));
}