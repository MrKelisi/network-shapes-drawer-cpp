#pragma once

#include <stdexcept>

class GroupeException : public std::runtime_error {
    public:
        GroupeException(const char* message) :
            runtime_error(message) {

        }
};