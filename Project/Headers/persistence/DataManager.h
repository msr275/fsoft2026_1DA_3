#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <string>

class DataManager {
private:
    std::string m_dataDir;
    std::string m_artistasFile;
    std::string m_albunsFile;

    void assegurarDiretorio();

public:
    DataManager(const std::string& dataDir = "data");

    bool carregarDados();
    bool guardarDados();
};

#endif