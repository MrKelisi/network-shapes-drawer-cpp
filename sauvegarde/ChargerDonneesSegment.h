#include "ChargerDonneesCOR.h"

class ChargerDonneesSegment : public ChargerDonneesCOR {

    public :
        ChargerDonneesSegment(ChargerDonneesCOR * suivant);
        const std::string toString() const;

    protected :
        Forme * analyser1(std::ifstream& f_in, const std::string& nomForme) const;
};
