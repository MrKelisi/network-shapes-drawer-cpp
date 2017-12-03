#pragma once

#include "ChargerDonnees.h"
#include <geometrie/vecteur.h>

class ChargerDonneesCOR : public ChargerDonnees {
    public:
        ChargerDonneesCOR* suivant;

    protected:
        ChargerDonneesCOR(ChargerDonneesCOR* suivant);

    public :
        Forme* analyser(std::ifstream& f_in, const std::string& nomForme);

    protected:
        /**
         * @brief Analyse une partie d'un fichier et renvoie la forme correspondante (fonction interne)
         * @param f_in Flux provenant du fichier exporté
         * @param nomForme Nom de la forme à analyser
         * @return Pointeur vers la forme ou nullptr si elle n'a pas pu être analysée
         */
        virtual Forme* analyser1(std::ifstream& f_in, const std::string& nomForme) = 0;
};
