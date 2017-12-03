#include "ChargerDonnesForme.h"

class ChargerDonneesSegment : public ChargerDonneesForme {

    public :
        ChargerDonneesSegment(ChargerDonneesCOR * suivant);

    protected :
        Forme* analyserForme(std::ifstream& f_in) const;
};
