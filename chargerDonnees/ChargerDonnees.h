#pragma once

#include <fstream>
#include <formes/forme.h>

class ChargerDonnees {

public:
    virtual Forme * analyser(std::ifstream & f_in, std::string nomForme) const = 0;
};
