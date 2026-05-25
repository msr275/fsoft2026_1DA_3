#include "../../Headers/views/Menus.h"
#include "../../Headers/views/Utils.h"
#include "../../Headers/exceptions/InvalidDataException.h"
#include "../../Headers/controllers/ManagerCatalogo.h"
#include "../../Headers/models/Album.h"
#include "../../Headers/models/Carrinho.h"
#include "../../Headers/persistence/DataManager.h"
#include <iostream>
#include <vector>


// exibe os álbuns no ecrã
void exibirListaAlbuns(const std::vector<Album>& albuns) {
    if (albuns.empty()) {
        std::cout << "\n[AVISO] Nenhum álbum encontrado para esta pesquisa.\n";
        return;
    }
    std::cout << "\n================= ÁLBuNS ENCONTRADOS =================\n";
    for (size_t i = 0; i < albuns.size(); i++) {
        std::cout << "ID: " << albuns[i].id_album()
                  << " | Título: " << albuns[i].titulo1()
                  << " | Preço: " << albuns[i].preco1() << " EUR"
                  << " | Rating: " << (albuns[i].rating1() == 0 ? "Sem nota" : std::to_string(albuns[i].rating1()).substr(0,3) + "/5*") << "\n";
    }
    std::cout << "======================================================\n";
}

//pergunta se quer comprar baseado na lista atual e adiciona ao carrinho
void perguntarEAdicionarAoCarrinho(const std::vector<Album>& albunsAtuais, ManagerCatalogo& catalogo, Carrinho& carrinho) {
    if (albunsAtuais.empty()) return; // Se não houver álbuns na pesquisa, não faz sentido perguntar

    std::cout << "\nDeseja adicionar algum destes albuns encontrados ao seu carrinho?\n";
    std::cout << "1. Sim, introduzir ID do album\n";
    std::cout << "0. Não, voltar aos filtros\n";
    int opcaoCompra = getSafeInt("Sua escolha: ", 0, 1);

    if (opcaoCompra == 1) {
        int idAlb = getSafeInt("Introduza o ID do Álbum desejado: ", 1, 99999);

        // garante que o cliente só escolhe um ID que realmente apareceu no ecrã
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
                std::cout << "\n[ERRO] Não foi possivel obter a referência do álbum.\n";
            }
        } else {
            std::cout << "\n[ERRO] O ID introduzido não faz parte dos álbuns listados na pesquisa.\n";
        }
    }
}

void showAdminMenu(ManagerCatalogo& catalogo) {
    int choice = -1;
    while (choice != 0) {
        displayHeader();
        std::cout << "--- GESTÃO ADMINISTRATIVA ---\n" << std::endl;
        std::cout << "1. Adicionar Novo Artista" << std::endl;
        std::cout << "2. Adicionar Novo Álbum" << std::endl;
        std::cout << "3. Remover Artista" << std::endl;
        std::cout << "4. Remover Álbum" << std::endl;
        std::cout << "5. Listar Todos os Álbuns" << std::endl;
        std::cout << "0. Voltar" << std::endl;

        choice = getSafeInt("Escolha Admin: ", 0, 5);

        if (choice == 1) { // 1. ADICIONAR ARTISTA
            std::string nome, pais, genero;
            std::cout << "Nome do Artista: ";
            std::cin.ignore();
            std::getline(std::cin, nome);
            std::cout << "País: ";
            std::getline(std::cin, pais);
            std::cout << "Género: ";
            std::getline(std::cin, genero);

            catalogo.adicionarArtista(nome, pais, genero);
            std::cout << "\n[SUCESSO] Artista adicionado ao catálogo!\n";
            pressEnterToContinue();
        }
        else if (choice == 2) { // 2. ADICIONAR ALBUM
            std::string titulo, formato, nomeArtistaProcurado;
            int ano;

            std::cout << "Título do Álbum: ";
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
                std::cout << "\n[ERRO] Artista '" << nomeArtistaProcurado << "' não existe. Crie o artista primeiro na opção 1.\n";
                pressEnterToContinue();
                continue;
            }

            ano = getSafeInt("Ano de Lançamento: ", 1900, 2026);

            std::string precoInput;
            float preco = -1;
            while (preco < 0) {
                std::cout << "Preço (EUR): ";
                std::cin >> precoInput;

                for (size_t i = 0; i < precoInput.size(); i++) {
                    if (precoInput[i] == ',') precoInput[i] = '.';
                }

                try {
                    preco = std::stof(precoInput);
                    if (preco < 0) std::cout << "[ERRO] O preço não pode ser negativo!\n";
                } catch (const std::exception&) {
                    std::cout << "[ERRO] Preço inválido! Use apenas números (ex: 12.50).\n";
                    preco = -1;
                }
            }
            std::cin.ignore(9999, '\n');

            std::cout << "Formato (ex: Vinil, CD, Digital): ";
            std::getline(std::cin, formato);

            try {
                catalogo.adicionarAlbum(titulo, idArtistaEncontrado, ano, preco, formato);
                std::cout << "\n[SUCESSO] Álbum '" << titulo << "' adicionado com sucesso!\n";
            } catch (const std::invalid_argument& e) {
                std::cout << "\n" << e.what() << "\n";
            }
            pressEnterToContinue();
        }
        else if (choice == 3) { // 3. REMOVER ARTISTA
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
                std::cout << "[AVISO] Isto vai remover o artista '" << nomeReal << "' e TODOS os seus álbuns!\n";
                std::cout << "1. Confirmar Remoção\n";
                std::cout << "0. Cancelar\n";
                int confirmar = getSafeInt("Sua escolha: ", 0, 1);

                if (confirmar == 1) {
                    catalogo.removerArtista(idArtistaEncontrado);
                    std::cout << "\n[SUCESSO] Artista e álbuns removidos com sucesso!\n";
                } else {
                    std::cout << "\n[INFO] Operação cancelada.\n";
                }
            } else {
                std::cout << "\n[ERRO] Artista não encontrado no catálogo.\n";
            }
            pressEnterToContinue();
        }
        else if (choice == 4) { // REMOVER ÁLBUM
            std::string nomeAlbumProcurado;
            std::cout << "Nome do Álbum a remover: ";
            std::cin.ignore();
            std::getline(std::cin, nomeAlbumProcurado);

            std::vector<Album> correspondencias = catalogo.pesquisarPorNomedeAlbum(nomeAlbumProcurado);

            if (correspondencias.empty()) {
                std::cout << "\n[ERRO] Nenhum álbum encontrado com esse nome.\n";
            }
            else if (correspondencias.size() == 1) {
                if (catalogo.removerAlbum(correspondencias[0].id_album())) {
                    std::cout << "\n[SUCESSO] Álbum '" << correspondencias[0].titulo1() << "' removido com sucesso!\n";
                }
            }
            else {
                std::cout << "\n[INFO] Foram encontrados múltiplos álbuns. Selecione o ID do que deseja apagar:\n";
                for (size_t i = 0; i < correspondencias.size(); i++) {
                    std::cout << "ID: " << correspondencias[i].id_album() << " | Título: " << correspondencias[i].titulo1() << "\n";
                }

                int idEscolhido = getSafeInt("\nIntroduza o ID exato do álbum (0 para cancelar): ", 0, 99999);
                if (idEscolhido != 0) {
                    if (catalogo.removerAlbum(idEscolhido)) {
                        std::cout << "\n[SUCESSO] Álbum removido com sucesso!\n";
                    } else {
                        std::cout << "\n[ERRO] ID inválido.\n";
                    }
                }
            }
            pressEnterToContinue();
        }
        else if (choice == 5) { //LISTA
            displayHeader();
            std::cout << "--- LISTA COMPLETA DE ÁLBUNS ---\n" << std::endl;

            const auto& todosAlbuns = catalogo.obterAlbuns();

            if (todosAlbuns.empty()) {
                std::cout << "[INFO] O catálogo de álbuns está completamente vazio de momento.\n";
            } else {
                // Reaproveita a função exibirListaAlbuns que já tem a formatação do Rating pronta!
                exibirListaAlbuns(todosAlbuns);
                std::cout << "\nTotal de álbuns registados: " << todosAlbuns.size() << "\n";
            }
            pressEnterToContinue();
        }
    }
}

// MENU DO CLIENTE
void showCustomerMenu(ManagerCatalogo& catalogo) {
    Carrinho meuCarrinho;
    int choice = -1;

    while (choice != 0) {
        displayHeader();
        std::cout << "--- LOJA DE CLIENTES ---\n" << std::endl;
        std::cout << "1. Pesquisar no Catálogo " << std::endl;
        std::cout << "2. Ver o meu Carrinho e Total" << std::endl;
        std::cout << "3. Esvaziar Carrinho" << std::endl;
        std::cout << "4. Finalizar Compra" << std::endl;
        std::cout << "5. Deixar Opinião sobre um Álbum" << std::endl;
        std::cout << "0. Voltar ao Menu Principal" << std::endl;

        choice = getSafeInt("\nSua Escolha: ", 0, 5);

        if (choice == 1) {
            int subChoice = -1;
            while (subChoice != 0) {
                std::cout << "\n--- FILTROS DE PESQUISA ---\n";
                std::cout << "1. Pesquisar por Nome do Álbum\n";
                std::cout << "2. Pesquisar por Nome do Artista\n";
                std::cout << "3. Pesquisar por Género\n";
                std::cout << "4. Pesquisar por Ano\n";
                std::cout << "0. Voltar\n";
                subChoice = getSafeInt("Escolha o filtro: ", 0, 4);

                std::vector<Album> resultados;
                std::string termo;

                if (subChoice == 1) {  //Pesquisa por Nome do Álbum
                    std::cout << "Digite o nome do Álbum (ou parte): ";
                    std::cin.ignore();
                    std::getline(std::cin, termo);
                    resultados = catalogo.pesquisarPorNomedeAlbum(termo);

                    exibirListaAlbuns(resultados);
                    perguntarEAdicionarAoCarrinho(resultados, catalogo, meuCarrinho);
                    pressEnterToContinue();
                }
                else if (subChoice == 2) {  //Pesquisa por Nome de Artista
                    std::cout << "Digite o nome do Artista (ou parte): ";
                    std::cin.ignore();
                    std::getline(std::cin, termo);
                    resultados = catalogo.pesquisaPorNomedeArtista(termo);

                    exibirListaAlbuns(resultados);
                    perguntarEAdicionarAoCarrinho(resultados, catalogo, meuCarrinho);
                    pressEnterToContinue();
                }
                else if (subChoice == 3) {  //Pesquisa por Género
                    std::cout << "Digite o Género: ";
                    std::cin.ignore();
                    std::getline(std::cin, termo);
                    resultados = catalogo.pesquisarPorGenero(termo);

                    exibirListaAlbuns(resultados);
                    perguntarEAdicionarAoCarrinho(resultados, catalogo, meuCarrinho);
                    pressEnterToContinue();
                }
                else if (subChoice == 4) {  //Pesquisa por Ano
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
                std::cout << "\n[INFO] O teu carrinho de compras está vazio.\n";
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
        else if (choice == 4) {
            ecrãVenda(meuCarrinho);
        }
        else if (choice == 5) {
            ecrãRating(catalogo);
        }
    }
}

void runMainMenu() {
    ManagerCatalogo meuCatalogo;
    DataManager storage;

    storage.carregarDados(meuCatalogo);

    int choice = -1;
    while (choice != 0) {
        displayHeader();
        std::cout << "1. Acesso Cliente" << std::endl;
        std::cout << "2. Login Administrator" << std::endl;
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
                std::cout << "\n[ALERTA DE SEGURANÇA] " << e.what() << std::endl;
                pressEnterToContinue();
            }
        }
    }

    storage.guardarDados(meuCatalogo);
    std::cout << "\n[INFO] Dados salvos com sucesso. Até à próxima!\n";
}

void ecrãVenda(Carrinho& carrinho) {
    int opcao;

    do {
        displayHeader();
        std::cout << "--- O SEU CARRINHO DE COMPRAS ---\n" << std::endl;

        std::vector<Album*> itens = carrinho.getItens();

        if (itens.empty()) {
            std::cout << "[INFO] O seu carrinho esta vazio.\n";
            pressEnterToContinue();
            return;
        }

        for (size_t i = 0; i < itens.size(); i++) {
            std::cout << "- " << itens[i]->titulo1() << " | " << itens[i]->preco1() << " EUR\n";
        }

        float total = carrinho.calcularTotal();
        std::cout << "----------------------------------------\n";
        std::cout << "TOTAL ACUMULADO: " << total << " EUR\n\n";

        std::cout << "1. Efetuar Pagamento (Confirmar e ver Recibo)\n";
        std::cout << "0. Voltar ao Menu Anterior (Cancelar)\n";

        opcao = getSafeInt("Sua escolha: ", 0, 1);

        if (opcao == 1) {
            displayHeader();

            std::cout << "========================================\n";
            std::cout << "           RECIBO DE VENDA              \n";
            std::cout << "========================================\n";
            std::cout << " ESTADO: PAGO COM SUCESSO!\n";
            std::cout << " VALOR COBRADO: " << total << " EUR\n";
            std::cout << " O seu pedido foi concluído.\n";
            std::cout << "========================================\n\n";

            carrinho.limparCarrinho();

            pressEnterToContinue();
            return;
        }
        else if (opcao == 0) {
            std::cout << "\n[INFO] Operação cancelada. Os artigos continuam no carrinho.\n";
            pressEnterToContinue();
        }
    } while (opcao != 0);
}

void ecrãRating(ManagerCatalogo& catalogo) {
    displayHeader();
    std::cout << "--- DEIXAR OPINIÃO (RATING) ---\n" << std::endl;

    std::string nomeAlbumProcurado;
    std::cout << "Insira o nome do álbum que deseja avaliar: ";
    std::cin.ignore();
    std::getline(std::cin, nomeAlbumProcurado);

    // Pesquisa os álbuns que correspondem ao nome
    std::vector<Album> correspondencias = catalogo.pesquisarPorNomedeAlbum(nomeAlbumProcurado);

    if (correspondencias.empty()) {
        std::cout << "\n[ERRO] Nenhum álbum encontrado com esse nome no catálogo.\n";
        pressEnterToContinue();
        return;
    }

    Album* albumReal = nullptr;

    // Se houver apenas um álbum escolhe logo esse
    if (correspondencias.size() == 1) {
        albumReal = catalogo.obterAlbumPorId(correspondencias[0].id_album());
    }
    //se houver vários, pede o nome exato
    else {
        std::cout << "\nForam encontrados múltiplos álbuns com nomes semelhantes:\n";
        for (size_t i = 0; i < correspondencias.size(); i++) {
            std::cout << "- " << correspondencias[i].titulo1() << " (Ano: " << correspondencias[i].ano1() << ")\n";
        }

        std::string nomeEscolhido;
        std::cout << "\nIntroduza o nome EXATO do álbum que deseja avaliar: ";
        std::getline(std::cin, nomeEscolhido);

        for (size_t i = 0; i < correspondencias.size(); i++) {
            if (correspondencias[i].titulo1() == nomeEscolhido) {
                albumReal = catalogo.obterAlbumPorId(correspondencias[i].id_album());
                break;
            }
        }
    }

    // Se encontramos o apontador do álbum original, aplica o rating
    if (albumReal != nullptr) {
        int nota = getSafeInt("Insira a sua classificação (1 a 5 estrelas): ", 1, 5);

        albumReal->set_rating(static_cast<float>(nota));

        std::cout << "\n[SUCESSO] Opinião registada para o álbum '" << albumReal->titulo1() << "' com " << nota << " estrelas.";
        std::cout << "\nMuito obrigado pelo feedback!\n\n";
    } else {
        std::cout << "\n[ERRO] O nome introduzido não corresponde a nenhum dos álbuns listados.\n";
    }

    pressEnterToContinue();
}