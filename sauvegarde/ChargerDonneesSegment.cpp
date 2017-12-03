#include <geometrie/vecteur.h>
#include <formes/segment.h>
#include <affichage/affichagedistant.h>
#include <exceptions/chargementexception.h>
#include "ChargerDonneesSegment.h"

ChargerDonneesSegment::ChargerDonneesSegment(ChargerDonneesCOR * suivant) :
        ChargerDonneesForme("Segment", suivant) {

}

Forme * ChargerDonneesSegment::analyserForme(std::ifstream& f_in) const {
    Vecteur debut = analyserVecteur(f_in);
    Vecteur fin = analyserVecteur(f_in);

    atteindreFinForme(f_in);

    return new Segment(couleur(), debut, fin);
}