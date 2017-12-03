#include <geometrie/vecteur.h>
#include <formes/triangle.h>
#include <affichage/affichagedistant.h>
#include "ChargerDonneesTriangle.h"

ChargerDonneesTriangle::ChargerDonneesTriangle(ChargerDonneesCOR* suivant) :
        ChargerDonneesForme("Triangle", suivant) {

}

Forme * ChargerDonneesTriangle::analyserForme(std::ifstream& f_in) const {
    Vecteur point1 = analyserVecteur(f_in);
    Vecteur point2 = analyserVecteur(f_in);
    Vecteur point3 = analyserVecteur(f_in);

    atteindreFinForme(f_in);

    return new Triangle(couleur(), point1, point2, point3);
}
