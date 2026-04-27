#include "Utils.h"
#include <iostream>
#include <limits>

void displayHeader() {
    std::cout << "------------------------" << std::endl;
    std::cout << "|Music Store of Group 3|" << std::endl;
    std::cout << "------------------------\n" << std::endl;
}

int getSafeInt(std::string prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            return value; // Sucesso: devolve o número
        } else {
            // Falha: utilizador inseriu letras ou símbolos
            std::cout << "Invalid input! Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}