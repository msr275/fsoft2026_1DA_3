#include "Menus.h"
#include "Utils.h"
#include "InvalidDataException.h"
#include "ManagerCatalogo.h"
#include "Album.h"
#include "Carrinho.h"
#include "DataManager.h"
#include <iostream>
#include <vector>

// FUNÇÃO 1: Apenas exibe os álbuns no ecrã. Totalmente independente.
void exibirListaAlbuns(const std::vector<Album>& albuns) {
    if (albuns.empty()) {
        std::cout << "\n[AVISO] Nenhum album encontrado para esta pesquisa.\n";
        return;
    }
    std::cout << "\n================= ALBUNS ENCONTRADOS =================\n";
    for (size_t i = 0; i < albuns.size(); i++) {
        std::cout << "ID: " << albuns[i].id_album()
                  << " | Titulo: " << albuns[i].titulo1()
                  << " | Ano: " << albuns[i].ano1()
                  << " | Preco: " << albuns[i].preco1() << " EUR"
                  << " | Formato: " << albuns[i].formato1() << "\n";
    }
    std::cout << "======================================================\n";
}

// FUNÇÃO 2: Pergunta se quer comprar baseado na lista atual e adiciona ao carrinho
void perguntarEAdicionarAoCarrinho(const std::vector<Album>& albunsAtuais, ManagerCatalogo& catalogo, Carrinho& carrinho) {
    if (albunsAtuais.empty()) return; // Se não houver álbuns na pesquisa, não faz sentido perguntar

    std::cout << "\nDeseja adicionar algum destes albuns encontrados ao seu carrinho?\n";
    std::cout << "1. Sim, introduzir ID do album\n";
    std::cout << "0. Nao, voltar aos filtros\n";
    int opcaoCompra = getSafeInt("Sua escolha: ", 0, 1);

    if (opcaoCompra == 1) {
        int idAlb = getSafeInt("Introduza o ID do Album desejado: ", 1, 99999);

        // Validação: Garante que o cliente só escolhe um ID que realmente apareceu no ecrã
        bool pertenceAosResultados = false;
        for (size_t i = 0; i < albunsAtuais.size(); i++) {
            if (albunsAtuais[i].id_album() == idAlb) {
                pertenceAosResultados = true;
                break;
            }
        }

        if (pertenceAosResultados) {
            Album* albPtr = catalogo.obterAlbumPorId(idAlb);
            if (albPtr != nullptr) {
                carrinho.adicionarAlbum(albPtr);
                std::cout << "\n[SUCESSO] '" << albPtr->titulo1() << "' adicionado ao carrinho!\n";
            } else {
                std::cout << "\n[ERRO] Nao foi possivel obter a referencia do album.\n";
            }
        } else {
            std::cout << "\n[ERRO] O ID introduzido nao faz parte dos albuns listados na pesquisa.\n";
        }
    }
}

void showAdminMenu(ManagerCatalogo& catalogo) {
    int choice = -1;
    while (choice != 0) {
        displayHeader();
        std::cout << "--- GESTAO ADMINISTRATIVA ---\n" << std::endl;
        std::cout << "1. Adicionar Novo Artista" << std::endl;
        std::cout << "2. Remover Artista (e albuns em cascata)" << std::endl;
        std::cout << "3. Remover Album" << std::endl;
        std::cout << "4. Adicionar Novo Album" << std::endl;
        std::cout << "5. Listar Todos os Albuns" << std::endl; // Nova opção visual
        std::cout << "0. Voltar" << std::endl;

        choice = getSafeInt("Escolha Admin: ", 0, 5); // Atualizado o limite para 5

        if (choice == 1) {
            std::string nome, pais, genero;
            std::cout << "Nome do Artista: ";
            std::cin.ignore();
            std::getline(std::cin, nome);
            std::cout << "Pais: ";
            std::getline(std::cin, pais);
            std::cout << "Genero: ";
            std::getline(std::cin, genero);

            catalogo.adicionarArtista(nome, pais, genero);
            std::cout << "\n[SUCESSO] Artista adicionado ao catalogo!\n";
            pressEnterToContinue();
        }
        else if (choice == 2) { // Remover Artista pelo Nome
            std::string nomeArtistaProcurado;
            std::cout << "Nome do Artista a remover: ";
            std::cin.ignore();
            std::getline(std::cin, nomeArtistaProcurado);

            const auto& artistas = catalogo.obterArtistas();
            int idArtistaEncontrado = -1;
            std::string nomeReal;

            for (size_t i = 0; i < artistas.size(); i++) {
                if (artistas[i].get_nome().find(nomeArtistaProcurado) != std::string::npos) {
                    idArtistaEncontrado = artistas[i].get_id_artista();
                    nomeReal = artistas[i].get_nome();
                    break;
                }
            }

            if (idArtistaEncontrado != -1) {
                std::cout << "[AVISO] Isto vai remover o artista '" << nomeReal
                          << "' e TODOS os seus albuns em cascata!\n";
                std::cout << "1. Confirmar Remocao\n";
                std::cout << "0. Cancelar\n";
                int confirmar = getSafeInt("Sua escolha: ", 0, 1);

                if (confirmar == 1) {
                    catalogo.removerArtista(idArtistaEncontrado);
                    std::cout << "\n[SUCESSO] Artista e albuns removidos com sucesso!\n";
                } else {
                    std::cout << "\n[INFO] Operacao cancelada.\n";
                }
            } else {
                std::cout << "\n[ERRO] Artista nao encontrado no catalogo.\n";
            }
            pressEnterToContinue();
        }
        else if (choice == 3) { // Remover Álbum pelo Nome
            std::string nomeAlbumProcurado;
            std::cout << "Nome do Album a remover: ";
            std::cin.ignore();
            std::getline(std::cin, nomeAlbumProcurado);

            std::vector<Album> correspondencias = catalogo.pesquisarPorNomedeAlbum(nomeAlbumProcurado);

            if (correspondencias.empty()) {
                std::cout << "\n[ERRO] Nenhum album encontrado com esse nome.\n";
            }
            else if (correspondencias.size() == 1) {
                if (catalogo.removerAlbum(correspondencias[0].id_album())) {
                    std::cout << "\n[SUCESSO] Album '" << correspondencias[0].titulo1() << "' removido com sucesso!\n";
                }
            }
            else {
                std::cout << "\n[INFO] Foram encontrados multiplos albuns. Selecione o ID do que deseja apagar:\n";
                for (size_t i = 0; i < correspondencias.size(); i++) {
                    std::cout << "ID: " << correspondencias[i].id_album()
                              << " | Titulo: " << correspondencias[i].titulo1()
                              << " | Ano: " << correspondencias[i].ano1() << "\n";
                }

                int idEscolhido = getSafeInt("\nIntroduza o ID exato do album (0 para cancelar): ", 0, 99999);
                if (idEscolhido != 0) {
                    if (catalogo.removerAlbum(idEscolhido)) {
                        std::cout << "\n[SUCESSO] Album removido com sucesso!\n";
                    } else {
                        std::cout << "\n[ERRO] ID invalido.\n";
                    }
                }
            }
            pressEnterToContinue();
        }
        else if (choice == 4) { // Adicionar Novo Album
            std::string titulo, formato, nomeArtistaProcurado;
            int ano;

            std::cout << "Titulo do Album: ";
            std::cin.ignore();
            std::getline(std::cin, titulo);

            std::cout << "Nome do Artista associado: ";
            std::getline(std::cin, nomeArtistaProcurado);

            const auto& artistas = catalogo.obterArtistas();
            int idArtistaEncontrado = -1;

            for (size_t i = 0; i < artistas.size(); i++) {
                if (artistas[i].get_nome().find(nomeArtistaProcurado) != std::string::npos) {
                    idArtistaEncontrado = artistas[i].get_id_artista();
                    std::cout << "[INFO] Artista encontrado: " << artistas[i].get_nome() << "\n";
                    break;
                }
            }

            if (idArtistaEncontrado == -1) {
                std::cout << "\n[ERRO] Artista '" << nomeArtistaProcurado << "' nao existe. Crie o artista primeiro na opcao 1.\n";
                pressEnterToContinue();
                continue;
            }

            ano = getSafeInt("Ano de Lancamento: ", 1900, 2026);

            std::string precoInput;
            float preco = -1;

            while (preco < 0) {
                std::cout << "Preco (EUR): ";
                std::cin >> precoInput;

                for (size_t i = 0; i < precoInput.size(); i++) {
                    if (precoInput[i] == ',') {
                        precoInput[i] = '.';
                    }
                }

                try {
                    preco = std::stof(precoInput);
                    if (preco < 0) {
                        std::cout << "[ERRO] O preco nao pode ser negativo!\n";
                    }
                } catch (const std::exception&) {
                    std::cout << "[ERRO] Preco invalido! Use apenas numeros (ex: 12.50 ou 12,50).\n";
                    preco = -1;
                }
            }
            std::cin.ignore(9999, '\n');

            std::cout << "Formato (ex: Vinil, CD, Digital): ";
            std::getline(std::cin, formato);

            try {
                catalogo.adicionarAlbum(titulo, idArtistaEncontrado, ano, preco, formato);
                std::cout << "\n[SUCESSO] Album '" << titulo << "' adicionado com sucesso!\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "\n" << e.what() << "\n";
            }
            pressEnterToContinue();
        }
        else if (choice == 5) { // Listar Todos os Álbuns do Catálogo
            displayHeader();
            std::cout << "--- LISTA COMPLETA DE ALBUNS ---\n" << std::endl;

            // Puxa o teu vetor original completo através do método que criaste
            const auto& todosAlbuns = catalogo.obterAlbuns();

            if (todosAlbuns.empty()) {
                std::cout << "[INFO] O catalogo de albuns está completamente vazio de momento.\n";
            } else {
                // Se já tiveres a função 'exibirListaAlbuns(todosAlbuns);' definida no Menus.cpp,
                // podes usá-la diretamente aqui! Caso contrário, este ciclo formata o ecrã:
                for (size_t i = 0; i < todosAlbuns.size(); i++) {
                    std::cout << "ID: " << todosAlbuns[i].id_album()
                              << " | Titulo: " << todosAlbuns[i].titulo1()
                              << " | Ano: " << todosAlbuns[i].ano1()
                              << " | Preco: " << todosAlbuns[i].preco1() << " EUR"
                              << " | Formato: " << todosAlbuns[i].formato1() << "\n";
                }
                std::cout << "\nTotal de albuns registados: " << todosAlbuns.size() << "\n";
            }
            pressEnterToContinue();
        }
    }
}


void showCustomerMenu(ManagerCatalogo& catalogo) {
    Carrinho meuCarrinho;
    int choice = -1;

    while (choice != 0) {
        displayHeader();
        std::cout << "--- LOJA DE CLIENTES ---\n" << std::endl;
        std::cout << "1. Pesquisar no Catalogo (Filtros & Compra)" << std::endl;
        std::cout << "2. Ver o meu Carrinho e Total" << std::endl;
        std::cout << "3. Esvaziar Carrinho" << std::endl;
        std::cout << "0. Voltar ao Menu Principal" << std::endl;

        choice = getSafeInt("\nSua Escolha: ", 0, 3);

        if (choice == 1) {
            int subChoice = -1;
            while (subChoice != 0) {
                std::cout << "\n--- FILTROS DE PESQUISA ---\n";
                std::cout << "1. Pesquisar por Nome do Album\n";
                std::cout << "2. Pesquisar por Nome do Artista\n";
                std::cout << "3. Pesquisar por Genero\n";
                std::cout << "4. Pesquisar por Ano\n";
                std::cout << "0. Voltar\n";
                subChoice = getSafeInt("Escolha o filtro: ", 0, 4);

                std::vector<Album> resultados;
                std::string termo;

                if (subChoice == 1) {
                    std::cout << "Digite o nome do Album (ou parte): ";
                    std::cin.ignore();
                    std::getline(std::cin, termo);
                    resultados = catalogo.pesquisarPorNomedeAlbum(termo);

                    exibirListaAlbuns(resultados);
                    perguntarEAdicionarAoCarrinho(resultados, catalogo, meuCarrinho);
                    pressEnterToContinue();
                }
                else if (subChoice == 2) {
                    std::cout << "Digite o nome do Artista (ou parte): ";
                    std::cin.ignore();
                    std::getline(std::cin, termo);
                    resultados = catalogo.pesquisaPorNomedeArtista(termo);

                    exibirListaAlbuns(resultados);
                    perguntarEAdicionarAoCarrinho(resultados, catalogo, meuCarrinho);
                    pressEnterToContinue();
                }
                else if (subChoice == 3) {
                    std::cout << "Digite o Genero: ";
                    std::cin.ignore();
                    std::getline(std::cin, termo);
                    resultados = catalogo.pesquisarPorGenero(termo);

                    exibirListaAlbuns(resultados);
                    perguntarEAdicionarAoCarrinho(resultados, catalogo, meuCarrinho);
                    pressEnterToContinue();
                }
                else if (subChoice == 4) {
                    int ano = getSafeInt("Digite o Ano: ", 1900, 2026);
                    resultados = catalogo.pesquisaPorAno(ano);

                    exibirListaAlbuns(resultados);
                    perguntarEAdicionarAoCarrinho(resultados, catalogo, meuCarrinho);
                    pressEnterToContinue();
                }
            }
        }
        else if (choice == 2) {
            std::vector<Album*> itens = meuCarrinho.getItens();
            if (itens.empty()) {
                std::cout << "\n[INFO] O teu carrinho de compras esta vazio.\n";
            } else {
                std::cout << "\n--- O TEU CARRINHO DE COMPRAS ---\n";
                for (size_t i = 0; i < itens.size(); i++) {
                    std::cout << "- " << itens[i]->titulo1() << " (" << itens[i]->preco1() << " EUR)\n";
                }
                std::cout << "---------------------------------\n";
                std::cout << "TOTAL A PAGAR: " << meuCarrinho.calcularTotal() << " EUR\n";
            }
            pressEnterToContinue();
        }
        else if (choice == 3) {
            meuCarrinho.limparCarrinho();
            std::cout << "\n[SUCESSO] Carrinho esvaziado com sucesso!\n";
            pressEnterToContinue();
        }
    }
}

void runMainMenu() {
    ManagerCatalogo meuCatalogo;
    DataManager storage; // Criado o gestor de ficheiros CSV

    // Carrega automaticamente os dados do disco ao arrancar o programa
    storage.carregarDados(meuCatalogo);

    int choice = -1;
    while (choice != 0) {
        displayHeader();
        std::cout << "1. Acesso Cliente" << std::endl;
        std::cout << "2. Login Administrador" << std::endl;
        std::cout << "0. Sair" << std::endl;

        choice = getSafeInt("\nSua Escolha: ", 0, 2);

        if (choice == 1) {
            showCustomerMenu(meuCatalogo);
        }
        else if (choice == 2) {
            std::string pass;
            std::cout << "Palavra-passe Admin: ";
            std::cin >> pass;

            try {
                if (pass != "fsoft2026") {
                    throw InvalidDataException("Acesso Negado: Palavra-passe Incorreta.");
                }
                showAdminMenu(meuCatalogo);
            } catch (const InvalidDataException& e) {
                std::cout << "\n[ALERTA DE SEGURANCA] " << e.what() << std::endl;
                pressEnterToContinue();
            }
        }
    }

    // Grava tudo automaticamente antes de fechar o programa!
    storage.guardarDados(meuCatalogo);
    std::cout << "\n[INFO] Dados salvos com sucesso. Ate a proxima!\n";
}