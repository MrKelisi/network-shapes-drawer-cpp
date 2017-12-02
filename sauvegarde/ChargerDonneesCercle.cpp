#include <geometrie/vecteur.h>
#include <formes/cercle.h>
#include <affichage/affichagedistant.h>
#include "ChargerDonneesCercle.h"

ChargerDonneesCercle::ChargerDonneesCercle(ChargerDonneesCOR * suivant) : ChargerDonneesCOR(suivant) {}

Forme * ChargerDonneesCercle::analyser1(std::ifstream& f_in, const std::string& nomForme) const {

    if(nomForme == "Cercle") {

        std::string line;

        getline(f_in, line, '\n');  // {

        const std::string couleur = analyserCouleur(f_in);
        Vecteur origine = analyserVecteur(f_in);
        double rayon = analyserDouble(f_in);

        getline(f_in, line, '\n');  // }

        return new Cercle(couleur, origine, rayon);
    }
    else {
        return nullptr;
    }
}

const std::string ChargerDonneesCercle::toString() const {

    return "C'est un cercle !";
}
