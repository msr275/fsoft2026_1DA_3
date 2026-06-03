#ifndef FSOFT2026_1DA_3_PESQUISA_H
#define FSOFT2026_1DA_3_PESQUISA_H
#include <vector>
#include <string>
#include "../../Headers/models/Album.h"


class Pesquisa {
public:
    static std::vector<Album> pesquisarPorGenero(const std::string& generoProcurado);
    static std::vector<Album> pesquisaPorAno(int anoProcurado);
    static std::vector<Album> pesquisarPorNomedeAlbum(const std::string& nomeProcurado);
    static std::vector<Album> pesquisaPorNomedeArtista(const std::string& artistaProcurado);
};
#endif //FSOFT2026_1DA_3_PESQUISA_H