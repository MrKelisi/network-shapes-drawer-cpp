#pragma once

#include <fstream>
#include <formes/forme.h>

class ChargerDonnees {

public:
    virtual Forme * analyser(std::ifstream& f_in, const std::string& nomForme) const = 0;
};
