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
            std::cin.clear(); //limpa erro para ver se já esta a funcionar
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//limpa espaçoes desnecessários
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

    size_t primeiro = str.find_first_not_of(" \t\r\n");//procura  posição do primeiro caractére q n seja espaço/tab/newline
    if (primeiro == std::string::npos) return "";//se n houver caractére na string, esvazia e sai da função
    size_t ultimo = str.find_last_not_of(" \t\r\n");//procura última posição de caractere
    return str.substr(primeiro, (ultimo - primeiro + 1)); // devolve apenas pedaço de texto já filtrado
}

std::string antiCamposVazios(const std::string& mensagem) {
    std::string input;
    while (true) {
        std::cout << mensagem;
        if (std::cin.peek() == '\n') {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }//ignora enters aléatorios q possam ter havido
        std::getline(std::cin, input);
        input = limparEspacos(input);//limpa espaços para ler msg

        if (!input.empty()) {
            return input;
        }
        std::cout << "[ERRO] Este campo é obrigatório e não pode ficar em branco!\n\n";
    }
}