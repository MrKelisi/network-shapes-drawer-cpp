//
// Created by mrkel on 24/11/2017.
//
#pragma once

#include "ChargerDonnees.h"

class ChargerDonneesCOR : public ChargerDonnees {

public:
    ChargerDonneesCOR * suivant;

protected:
    ChargerDonneesCOR(ChargerDonneesCOR * suivant);

public :
    const Forme * analyser(std::ifstream & f_in, std::string nomForme) const;
    virtual const std::string toString() const = 0;

protected:
    virtual const Forme * analyser1(std::ifstream & f_in, std::string nomForme) const = 0;

};
