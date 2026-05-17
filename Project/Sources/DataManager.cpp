#include "DataManager.h"
#include "Artista.h"
#include "Album.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/stat.h>
#include <cerrno>

DataManager::DataManager(const std::string& dataDir) : m_dataDir(dataDir) {
    m_artistasFile = m_dataDir + "/artistas.csv";
    m_albunsFile = m_dataDir + "/albuns.csv";
}

void DataManager::assegurarDiretorio() {
    if (mkdir(m_dataDir.c_str(), 0777) == 0 || errno == EEXIST) {
        // Diretorio garantido com sucesso
    } else {
        std::cerr << "[ERRO] Nao foi possivel criar o diretorio: " << m_dataDir << std::endl;
    }
}

bool DataManager::carregarDados(ManagerCatalogo& catalogo) {
    // 1. Carregar Artistas
    std::ifstream fileArtistas(m_artistasFile);
    if (fileArtistas.is_open()) {
        std::string linha;
        while (std::getline(fileArtistas, linha)) {
            if (linha.empty()) continue;
            std::stringstream ss(linha);
            std::string idStr, nome, pais, genero;

            if (std::getline(ss, idStr, ';') &&
                std::getline(ss, nome, ';') &&
                std::getline(ss, pais, ';') &&
                std::getline(ss, genero, ';')) {

                catalogo.adicionarArtista(nome, pais, genero);
            }
        }
        fileArtistas.close();
    }

    // 2. Carregar Álbuns
    std::ifstream fileAlbuns(m_albunsFile);
    if (fileAlbuns.is_open()) {
        std::string linha;
        while (std::getline(fileAlbuns, linha)) {
            if (linha.empty()) continue;
            std::stringstream ss(linha);
            std::string idAlbStr, idArtStr, titulo, anoStr, precoStr, formato;

            if (std::getline(ss, idAlbStr, ';') &&
                std::getline(ss, idArtStr, ';') &&
                std::getline(ss, titulo, ';') &&
                std::getline(ss, anoStr, ';') &&
                std::getline(ss, precoStr, ';') &&
                std::getline(ss, formato, ';')) {

                int idArtista = std::stoi(idArtStr);
                int ano = std::stoi(anoStr);
                float preco = std::stof(precoStr);

                // Usa o teu metodo oficial do catalogo
                catalogo.adicionarAlbum(titulo, idArtista, ano, preco, formato);
            }
        }
        fileAlbuns.close();
    }
    return true;
}

bool DataManager::guardarDados(const ManagerCatalogo& catalogo) {
    assegurarDiretorio();

    // 1. Guardar Artistas
    std::ofstream fileArtistas(m_artistasFile);
    if (!fileArtistas.is_open()) return false;

    const auto& artistas = catalogo.obterArtistas();
    for (size_t i = 0; i < artistas.size(); ++i) {
        // Usa os getters exatos do teu Artista.h
        fileArtistas << artistas[i].get_id_artista() << ";"
                     << artistas[i].get_nome() << ";"
                     << artistas[i].get_pais() << ";"
                     << artistas[i].get_genero() << "\n";
    }
    fileArtistas.close();

    // 2. Guardar Álbuns
    std::ofstream fileAlbuns(m_albunsFile);
    if (!fileAlbuns.is_open()) return false;

    const auto& albuns = catalogo.obterAlbuns();
    for (size_t i = 0; i < albuns.size(); ++i) {
        // Usa os getters exatos do teu Album.h
        fileAlbuns << albuns[i].id_album() << ";"
                   << albuns[i].id_artista() << ";"
                   << albuns[i].titulo1() << ";"
                   << albuns[i].ano1() << ";"
                   << albuns[i].preco1() << ";"
                   << albuns[i].formato1() << "\n";
    }
    fileAlbuns.close();

    return true;
}