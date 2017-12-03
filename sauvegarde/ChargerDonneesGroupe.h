#include "ChargerDonnesForme.h"

class ChargerDonneesGroupe : public ChargerDonneesForme {
    public:
        ChargerDonneesGroupe(ChargerDonneesCOR * suivant);

    protected:
        Forme* analyserForme(std::ifstream& f_in) const;
};
