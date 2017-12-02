#include <geometrie/vecteur.h>
#include <formes/triangle.h>
#include <affichage/affichagedistant.h>
#include "ChargerDonneesTriangle.h"

ChargerDonneesTriangle::ChargerDonneesTriangle(ChargerDonneesCOR * suivant) : ChargerDonneesCOR(suivant) {}

Forme * ChargerDonneesTriangle::analyser1(std::ifstream & f_in, std::string nomForme) const {

    if(nomForme == "Triangle") {

        std::string line;

        getline(f_in, line, '\n');  // {

        const std::string couleur = analyserCouleur(f_in);
        Vecteur point1 = analyserVecteur(f_in);
        Vecteur point2 = analyserVecteur(f_in);
        Vecteur point3 = analyserVecteur(f_in);

        getline(f_in, line, '\n');  // }

        return new Triangle(couleur, point1, point2, point3);
    }
    else {
        return nullptr;
    }
}

const std::string ChargerDonneesTriangle::toString() const {

    return "C'est un triangle !";
}
