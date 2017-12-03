#pragma once

#include <fstream>
#include <formes/forme.h>

class ChargerDonnees {

public:
    /**
     * @brief Analyse une partie d'un fichier et renvoie la forme correspondante
     * @param f_in Flux provenant du fichier exporté
     * @param nomForme Nom de la forme à analyser
     * @return Pointeur vers la forme ou nullptr si elle n'a pas pu être analysée
     */
    virtual Forme* analyser(std::ifstream& f_in, const std::string& nomForme) = 0;
};
