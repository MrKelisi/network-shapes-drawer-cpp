#include <formes/forme.h>
#include <geometrie/vecteur.h>
#include "ChargerDonneesCOR.h"
#include <stdexcept>
#include <exceptions/argumentexception.h>

ChargerDonneesCOR::ChargerDonneesCOR(ChargerDonneesCOR * suivant) : suivant(suivant) {}

Forme* ChargerDonneesCOR::analyser(std::ifstream& f_in, const std::string& nomForme) {
    Forme* resultat;
    resultat = this->analyser1(f_in, nomForme);

    if (resultat != nullptr) {
        return resultat;
    }

    else {

        if (this->suivant != NULL) {
            return this->suivant->analyser(f_in, nomForme);
        }
        else {
            return nullptr;
        }
    }
}