//
// Created by mrkel on 24/11/2017.
//

#include "ChargerDonneesCOR.h"

class ChargerDonneesSegment : public ChargerDonneesCOR {

    public :
        ChargerDonneesSegment(ChargerDonneesCOR * suivant);
        const std::string toString() const;

    protected :
        const Forme * analyser1(std::ifstream & f_in, std::string nomForme, Forme * &f) const;
};
