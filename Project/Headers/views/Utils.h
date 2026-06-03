#ifndef FSOFT2026_1DA_3_UTILS_H
#define FSOFT2026_1DA_3_UTILS_H

#include <string>

void displayHeader();
int getSafeInt(std::string prompt);
int getSafeInt(std::string prompt, int min, int max);
void pressEnterToContinue();
std::string limparEspacos(const std::string& str);
std::string antiCamposVazios(const std::string& mensagem);

#endif // FSOFT2026_1DA_3_UTILS_H