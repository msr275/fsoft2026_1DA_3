#ifndef MENUS_H
#define MENUS_H

#include <vector>

class Carrinho;
class Album;

void exibirListaAlbuns(const std::vector<Album>& albuns);
void perguntarEAdicionarAoCarrinho(const std::vector<Album>& albunsAtuais, Carrinho& carrinho);
void showAdminMenu();
void showCustomerMenu();
void runMainMenu();
void ecrãVenda(Carrinho& carrinho);
void ecrãRating();

#endif