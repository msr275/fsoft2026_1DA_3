#ifndef INVALIDDATAEXCEPTION_H
#define INVALIDDATAEXCEPTION_H

#include <exception>
#include <string>

class InvalidDataException : public std::exception
{
  private:
      std::string message;
  public:
      InvalidDataException(const std::string& msg);
      const char* what() const noexcept override;
};

#endif