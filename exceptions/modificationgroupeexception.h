#pragma once

#include <stdexcept>

class modificationgroupeexception : public std::runtime_error {
    public:
        modificationgroupeexception(const char* message) :
            runtime_error(message) {

        }
};