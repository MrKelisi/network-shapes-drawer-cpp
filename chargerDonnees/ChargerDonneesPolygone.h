//
// Created by mrkel on 24/11/2017.
//

#include "ChargerDonneesCOR.h"

class ChargerDonneesPolygone : public ChargerDonneesCOR {

public :
    ChargerDonneesPolygone(ChargerDonneesCOR * suivant);
    const std::string toString() const;

protected :
    Forme * analyser1(std::ifstream & f_in, std::string nomForme) const;
};
