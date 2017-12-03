#include "ChargerDonnesForme.h"

class ChargerDonneesCercle : public ChargerDonneesForme {
    public:
        ChargerDonneesCercle(ChargerDonneesCOR* suivant);

    protected:
        Forme* analyserForme(std::ifstream& f_in) const;
};
