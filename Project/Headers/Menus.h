#ifndef MENUS_H
#define MENUS_H

#include <vector>

class ManagerCatalogo;
class Carrinho;
class Album;

void exibirListaAlbuns(const std::vector<Album>& albuns);
void perguntarEAdicionarAoCarrinho(const std::vector<Album>& albunsAtuais, ManagerCatalogo& catalogo, Carrinho& carrinho);
void showAdminMenu(ManagerCatalogo& catalogo);
void showCustomerMenu(ManagerCatalogo& catalogo);
void runMainMenu();

#endif