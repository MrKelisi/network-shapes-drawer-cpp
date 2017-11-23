#pragma once

#include <stdexcept>

class ArgumentException : public std::runtime_error {
    public:
        ArgumentException(const std::string& __arg) : runtime_error(__arg) {

        }
};