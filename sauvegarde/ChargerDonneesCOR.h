#pragma once

#include "ChargerDonnees.h"

class ChargerDonneesCOR : public ChargerDonnees {

public:
    ChargerDonneesCOR* suivant;

protected:
    ChargerDonneesCOR(ChargerDonneesCOR * suivant);

public :
    Forme* analyser(std::ifstream& f_in, const std::string& nomForme) const;
    virtual const std::string toString() const = 0;

protected:
    virtual Forme* analyser1(std::ifstream& f_in, const std::string& nomForme) const = 0;

    double analyserDouble(std::ifstream& f_in) const;
    Vecteur analyserVecteur(std::ifstream& f_in) const;
    std::string analyserCouleur(std::ifstream& f_in) const;

};
