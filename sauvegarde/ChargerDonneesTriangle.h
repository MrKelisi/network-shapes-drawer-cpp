#include "ChargerDonnesForme.h"

class ChargerDonneesTriangle : public ChargerDonneesForme {

public :
    ChargerDonneesTriangle(ChargerDonneesCOR* suivant);

protected :
    Forme* analyserForme(std::ifstream& f_in) const;
};
