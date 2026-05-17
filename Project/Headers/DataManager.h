#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdexcept>

// Forward declarations das entidades do projeto
// (descomentar quando as classes estiverem implementadas)
// class Artist;
// class Album;
// class Track;
// class Sale;

// Classe responsável por guardar e carregar os dados do programa
// Os dados ficam guardados em ficheiros CSV na pasta data/

class DataManager {
public:
    // Construtor - inicializa o DataManager e garante que a pasta /data existe
    DataManager(const std::string& dataDir = "data");

    // ─── Interface pública principal ──────────────────────────────────────────

    // Lê todos os ficheiros CSV no arranque do programa
    bool load();

    // Guarda todos os dados nos ficheiros no encerramento do programa
    bool save();

    // ─── Utilitários de ficheiro ──────────────────────────────────────────────

    // Verifica se um ficheiro existe no sistema de ficheiros
    static bool fileExists(const std::string& path);

    // Cria a pasta de dados se ainda não existir
    bool ensureDataDirectory() const;

    // Lê um ficheiro CSV linha a linha e devolve as linhas
    std::vector<std::string> readLines(const std::string& filename) const;

    // Escreve um conjunto de linhas num ficheiro CSV
    void writeLines(const std::string& filename,
                    const std::vector<std::string>& lines) const;

    // ─── Acesso às coleções em memória ────────────────────────────────────────
    // (expandir conforme as classes forem implementadas)

    // std::vector<Artist>&  getArtists();
    // std::vector<Album>&   getAlbums();
    // std::vector<Track>&   getTracks();
    // std::vector<Sale>&    getSales();

private:
    // ─── Constantes de ficheiros ──────────────────────────────────────────────
    static constexpr const char* FILE_ARTISTS = "artists.csv";
    static constexpr const char* FILE_ALBUMS  = "albums.csv";
    static constexpr const char* FILE_TRACKS  = "tracks.csv";
    static constexpr const char* FILE_SALES   = "sales.csv";

    // ─── Estado interno ───────────────────────────────────────────────────────
    std::string m_dataDir; // caminho para a pasta de dados

    // Coleções em memória — descomentar conforme as classes forem criadas:
    // std::vector<Artist> m_artists;
    // std::vector<Album>  m_albums;
    // std::vector<Track>  m_tracks;
    // std::vector<Sale>   m_sales;

    // ─── Métodos privados de parsing ──────────────────────────────────────────

    // Carrega os artistas do ficheiro
    bool loadArtists();

    // Carrega os álbuns do ficheiro
    bool loadAlbums();

    // Carrega as faixas do ficheiro
    bool loadTracks();

    // Carrega o histórico de vendas
    bool loadSales();

    // Grava os artistas no ficheiro
    bool saveArtists() const;

    // Grava os álbuns no ficheiro
    bool saveAlbums() const;

    // Grava as faixas no ficheiro
    bool saveTracks() const;

    // Grava as vendas no ficheiro
    bool saveSales() const;

    // Constrói o caminho completo para um ficheiro ex: data/artists.csv
    std::string buildPath(const std::string& filename) const;
};

#endif // DATAMANAGER_H