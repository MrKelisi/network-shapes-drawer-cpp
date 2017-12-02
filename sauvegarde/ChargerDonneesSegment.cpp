#include <geometrie/vecteur.h>
#include <formes/segment.h>
#include <affichage/affichagedistant.h>
#include "ChargerDonneesSegment.h"

ChargerDonneesSegment::ChargerDonneesSegment(ChargerDonneesCOR * suivant) : ChargerDonneesCOR(suivant) {}

Forme * ChargerDonneesSegment::analyser1(std::ifstream& f_in, const std::string& nomForme) const {

    if(nomForme == "Segment") {

        std::string line;

        getline(f_in, line, '\n');  // {

        const std::string couleur = analyserCouleur(f_in);
        Vecteur debut = analyserVecteur(f_in);
        Vecteur fin = analyserVecteur(f_in);

        getline(f_in, line, '\n');  // }

        return new Segment(couleur, debut, fin);
    }
    else {
        return nullptr;
    }
}

const std::string ChargerDonneesSegment::toString() const {

    return "C'est un segment !";
}
