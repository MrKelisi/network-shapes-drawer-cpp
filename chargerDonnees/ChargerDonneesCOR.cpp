//
// Created by mrkel on 24/11/2017.
//

#include <formes/forme.h>
#include "ChargerDonneesCOR.h"

ChargerDonneesCOR::ChargerDonneesCOR(ChargerDonneesCOR * suivant) : suivant(suivant) {}

const Forme * ChargerDonneesCOR::analyser(std::ifstream & f_in, std::string nomForme, Forme * &f) const {
    const Forme * resultat;
    resultat = this->analyser1(f_in, nomForme, f);

    if (resultat != NULL) {

        //std::cout << resultat << std::endl;
        return resultat;
    }

    else {

        if (this->suivant != NULL)	// puisque il y a un suivant, on lui confie la tâche
            return this->suivant->analyser(f_in, nomForme, f);
        else {                      // c'était le dernier de la chaine, c'est donc un échec
            return NULL;
        }
    }
}
