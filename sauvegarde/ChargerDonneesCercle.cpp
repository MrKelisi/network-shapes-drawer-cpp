#include <geometrie/vecteur.h>
#include <formes/cercle.h>
#include <affichage/affichagedistant.h>
#include <exceptions/argumentexception.h>
#include <exceptions/chargementexception.h>
#include "ChargerDonneesCercle.h"

ChargerDonneesCercle::ChargerDonneesCercle(ChargerDonneesCOR* suivant) :
        ChargerDonneesForme("Cercle", suivant) {

}

Forme* ChargerDonneesCercle::analyserForme(std::ifstream& f_in) const {
    std::string line;

    Vecteur origine = analyserVecteur(f_in);
    double rayon = analyserDouble(f_in);

    atteindreFinForme(f_in);

    return new Cercle(couleur(), origine, rayon);
}