#include "ChargerDonneesCOR.h"

class ChargerDonneesCercle : public ChargerDonneesCOR {

    public :
        ChargerDonneesCercle(ChargerDonneesCOR * suivant);
        const std::string toString() const;

    protected :
        Forme * analyser1(std::ifstream & f_in, std::string nomForme) const;
};
