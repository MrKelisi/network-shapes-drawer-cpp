#include "ChargerDonnesForme.h"

class ChargerDonneesPolygone : public ChargerDonneesForme {

public :
    ChargerDonneesPolygone(ChargerDonneesCOR * suivant);

protected :
    Forme* analyserForme(std::ifstream& f_in) const;
};
