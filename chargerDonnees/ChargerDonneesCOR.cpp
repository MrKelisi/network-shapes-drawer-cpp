#include <formes/forme.h>
#include "ChargerDonneesCOR.h"

ChargerDonneesCOR::ChargerDonneesCOR(ChargerDonneesCOR * suivant) : suivant(suivant) {}

Forme * ChargerDonneesCOR::analyser(std::ifstream & f_in, std::string nomForme) const {
    Forme * resultat;
    resultat = this->analyser1(f_in, nomForme);

    if (resultat != nullptr) {

        //std::cout << resultat << std::endl;
        return resultat;
    }

    else {

        if (this->suivant != NULL)	// puisque il y a un suivant, on lui confie la tâche
            return this->suivant->analyser(f_in, nomForme);
        else                        // c'était le dernier de la chaine, c'est donc un échec
            return nullptr;
    }
}
