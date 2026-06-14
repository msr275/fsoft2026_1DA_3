#ifndef FSOFT2026_1DA_3_UTILS_H
#define FSOFT2026_1DA_3_UTILS_H

#include <string>

void displayHeader();
int getSafeInt(std::string prompt);// evita q se use letras
int getSafeInt(std::string prompt, int min, int max);//obriga a usar números dentro de um intervalo
void pressEnterToContinue();
std::string limparEspacos(const std::string& str);//remover expaços inúteis
std::string antiCamposVazios(const std::string& mensagem);//obriga a escrever algo

#endif // FSOFT2026_1DA_3_UTILS_H