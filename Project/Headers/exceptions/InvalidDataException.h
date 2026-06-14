#ifndef INVALIDDATAEXCEPTION_H
#define INVALIDDATAEXCEPTION_H

#include <exception>
#include <string>
//CLASSE HERDADA DE UMA CLASSE PADRÃO DE EXCEÇÕES
class InvalidDataException : public std::exception
{
  private:
      std::string message;//vai guardar o texto de erro(ex: preço inválido)
  public:
      InvalidDataException(const std::string& msg);// recebe a msg de erro
      const char* what() const noexcept override;
};
// "const" garante q esta função apenas lê a mensagem e não modifica nenhum dado
//what() vai retornar a msg do erro
// "noexcept vai garantir q a função nnc falha
//"override" permite mudar amsg de erro para oq quisermos

#endif