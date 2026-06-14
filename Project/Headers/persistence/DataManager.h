#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <string>

class DataManager {
private:
    std::string m_dataDir; //caminho para pasta onde ficheiros são guardados
    std::string m_artistasFile;//caminho para ficheiro de artistas
    std::string m_albunsFile;//caminho para ficheiro de álbuns

    void assegurarDiretorio();//verifica se pasta existe

public:
    DataManager(const std::string& dataDir = "data");//construtor q define q a pasta se chama "data"

    bool carregarDados();//lê ficheiros CSV e carrega info para o programa
    bool guardarDados();// grava tudo nos CSV ao programa acabar
};

#endif