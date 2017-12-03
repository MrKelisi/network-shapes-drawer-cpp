#include <geometrie/vecteur.h>
#include <formes/polygone.h>
#include <exceptions/argumentexception.h>
#include <exceptions/chargementexception.h>
#include "ChargerDonneesPolygone.h"

ChargerDonneesPolygone::ChargerDonneesPolygone(ChargerDonneesCOR * suivant) :
        ChargerDonneesForme("Polygone", suivant) {

}

Forme * ChargerDonneesPolygone::analyserForme(std::ifstream& f_in) const {
    std::vector<Vecteur> points;
    bool continuerChercherPoints = true;

    while(continuerChercherPoints) {
        try {
            Vecteur temp = analyserVecteur(f_in);
            points.push_back(temp);
        }
        catch(ChargementException e) {
            if(e.line() != FIN) {
                atteindreFinForme(f_in);
            }

            continuerChercherPoints = false;
        }
    }

    Polygone* p = new Polygone(couleur());
    for(std::vector<Vecteur>::iterator it = points.begin(); it != points.end(); it++) {
        p->ajouter(*it);
    }

    return p;
}