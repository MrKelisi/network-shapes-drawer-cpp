#include "ChargerDonneesCOR.h"

class ChargerDonneesTriangle : public ChargerDonneesCOR {

public :
    ChargerDonneesTriangle(ChargerDonneesCOR * suivant);
    const std::string toString() const;

protected :
    Forme * analyser1(std::ifstream& f_in, const std::string& nomForme) const;
};
