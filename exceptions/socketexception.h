#pragma once

#include <stdexcept>

class SocketException : public std::runtime_error {
    public:
        SocketException(const char* message) :
                runtime_error(message) {

        }
};