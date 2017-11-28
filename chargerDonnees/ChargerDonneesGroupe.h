#include "ChargerDonneesCOR.h"

class ChargerDonneesGroupe : public ChargerDonneesCOR {

public :
    ChargerDonneesGroupe(ChargerDonneesCOR * suivant);
    const std::string toString() const;

protected :
    Forme * analyser1(std::ifstream & f_in, std::string nomForme) const;
};
