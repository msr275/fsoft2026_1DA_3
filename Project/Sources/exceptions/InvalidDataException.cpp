#include "../../Headers/exceptions/InvalidDataException.h"

InvalidDataException::InvalidDataException(const std::string& msg) : message(msg) {}

//e agor
const char* InvalidDataException::what() const noexcept {
    return message.c_str(); //.c_str vai transformar string em char* já q é oq a função devolve
}