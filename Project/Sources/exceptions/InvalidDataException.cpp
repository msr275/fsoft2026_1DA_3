#include "../../headers/InvalidDataException.h"

InvalidDataException::InvalidDataException(const std::string& msg) : message(msg) {}

const char* InvalidDataException::what() const noexcept {
    return message.c_str();
}