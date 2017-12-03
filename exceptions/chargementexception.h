#pragma once

#include <stdexcept>

class ChargementException : public std::runtime_error {
    private:
        std::string _line;

    public:
        ChargementException(const std::string& arg, const std::string& line) :
                runtime_error(arg),
                _line(line) {

        }

        const std::string& line() const {
            return _line;
        }
};