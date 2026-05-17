#include "DataManager.h"

#include <sys/stat.h>  // para verificar e criar pastas
#include <cerrno>
#include <cstring>

// ─── Construtor ───────────────────────────────────────────────────────────────

DataManager::DataManager(const std::string& dataDir)
    : m_dataDir(dataDir)
{
    // Garante que a pasta /data existe logo na construção do objeto.
    if (!ensureDataDirectory()) {
        std::cerr << "[DataManager] Aviso: nao foi possivel criar a pasta '"
                  << m_dataDir << "'.\n";
    }
}

// ─── Interface pública principal ──────────────────────────────────────────────

bool DataManager::load() {
    std::cout << "[DataManager] A carregar dados de '" << m_dataDir << "'...\n";

    bool ok = true;
    ok &= loadArtists();
    ok &= loadAlbums();
    ok &= loadTracks();
    ok &= loadSales();

    if (ok)
        std::cout << "[DataManager] Dados carregados com sucesso.\n";
    else
        std::cerr << "[DataManager] Alguns ficheiros nao puderam ser lidos.\n";

    return ok;
}

bool DataManager::save() {
    std::cout << "[DataManager] A guardar dados em '" << m_dataDir << "'...\n";

    bool ok = true;
    ok &= saveArtists();
    ok &= saveAlbums();
    ok &= saveTracks();
    ok &= saveSales();

    if (ok)
        std::cout << "[DataManager] Dados guardados com sucesso.\n";
    else
        std::cerr << "[DataManager] Erro ao guardar um ou mais ficheiros.\n";

    return ok;
}

// ─── Utilitários de ficheiro ──────────────────────────────────────────────────

bool DataManager::fileExists(const std::string& path) {
    struct stat buffer{};
    return (stat(path.c_str(), &buffer) == 0);
}

bool DataManager::ensureDataDirectory() const {
    if (mkdir(m_dataDir.c_str()) == 0 || errno == EEXIST)
        return true;

    std::cerr << "[DataManager] Erro ao criar pasta '" << m_dataDir << "': "
              << strerror(errno) << "\n";
    return false;
}

std::vector<std::string> DataManager::readLines(const std::string& filename) const {
    const std::string path = buildPath(filename);
    std::vector<std::string> lines;

    std::ifstream file(path);
    if (!file.is_open()) {
        // Se o ficheiro ainda não existe (primeira execução), não é um erro fatal.
        if (!fileExists(path)) {
            std::cout << "[DataManager] Ficheiro '" << path
                      << "' nao encontrado — sera criado no proximo save().\n";
            return lines;   // devolve vetor vazio
        }
        throw std::runtime_error("[DataManager] Nao foi possivel abrir: " + path);
    }

    std::string line;
    while (std::getline(file, line)) {
        // Ignora linhas vazias e comentários (linhas que começam com '#').
        if (!line.empty() && line.front() != '#')
            lines.push_back(line);
    }
    return lines;
}

void DataManager::writeLines(const std::string& filename,
                             const std::vector<std::string>& lines) const {
    const std::string path = buildPath(filename);

    std::ofstream file(path, std::ios::out | std::ios::trunc);
    if (!file.is_open())
        throw std::runtime_error("[DataManager] Nao foi possivel escrever em: " + path);

    for (const auto& line : lines)
        file << line << '\n';
}

// ─── Métodos privados — load ──────────────────────────────────────────────────

bool DataManager::loadArtists() {
    try {
        std::vector<std::string> lines = readLines(FILE_ARTISTS);

        for (const auto& line : lines) {
            // TODO: fazer parse da linha e construir objeto Artist.
            // Exemplo de formato CSV esperado:
            //   id,nome,genero
            //   1,Pink Floyd,Rock
            (void)line; // suprimir aviso de não utilização até ao parse real
        }
        std::cout << "[DataManager] Artistas carregados: "
                  << lines.size() << " registos.\n";
        return true;

    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return false;
    }
}

bool DataManager::loadAlbums() {
    try {
        std::vector<std::string> lines = readLines(FILE_ALBUMS);

        for (const auto& line : lines) {
            // TODO: parse e construção de Album.
            // Formato previsto: id,titulo,artistaId,formato,preco,rating
            (void)line;
        }
        std::cout << "[DataManager] Albums carregados: "
                  << lines.size() << " registos.\n";
        return true;

    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return false;
    }
}

bool DataManager::loadTracks() {
    try {
        std::vector<std::string> lines = readLines(FILE_TRACKS);

        for (const auto& line : lines) {
            // TODO: parse e construção de Track.
            // Formato previsto: id,titulo,albumId,duracao
            (void)line;
        }
        std::cout << "[DataManager] Faixas carregadas: "
                  << lines.size() << " registos.\n";
        return true;

    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return false;
    }
}

bool DataManager::loadSales() {
    try {
        std::vector<std::string> lines = readLines(FILE_SALES);

        for (const auto& line : lines) {
            // TODO: parse e construção de Sale.
            // Formato previsto: id,data,clienteId,albumId,preco
            (void)line;
        }
        std::cout << "[DataManager] Vendas carregadas: "
                  << lines.size() << " registos.\n";
        return true;

    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return false;
    }
}

// ─── Métodos privados — save ──────────────────────────────────────────────────

bool DataManager::saveArtists() const {
    try {
        std::vector<std::string> lines;

        // TODO: serializar cada Artist de m_artists para uma string CSV.
        // Exemplo:
        //   for (const auto& artist : m_artists)
        //       lines.push_back(artist.toCSV());

        writeLines(FILE_ARTISTS, lines);
        return true;

    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return false;
    }
}

bool DataManager::saveAlbums() const {
    try {
        std::vector<std::string> lines;
        // TODO: serializar cada Album de m_albums.
        writeLines(FILE_ALBUMS, lines);
        return true;

    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return false;
    }
}

bool DataManager::saveTracks() const {
    try {
        std::vector<std::string> lines;
        // TODO: serializar cada Track de m_tracks.
        writeLines(FILE_TRACKS, lines);
        return true;

    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return false;
    }
}

bool DataManager::saveSales() const {
    try {
        std::vector<std::string> lines;
        // TODO: serializar cada Sale de m_sales.
        writeLines(FILE_SALES, lines);
        return true;

    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return false;
    }
}

// ─── Auxiliar privado ─────────────────────────────────────────────────────────

std::string DataManager::buildPath(const std::string& filename) const {
    return m_dataDir + "/" + filename;
}
