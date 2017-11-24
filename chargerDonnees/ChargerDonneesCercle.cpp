//
// Created by mrkel on 24/11/2017.
//

#include <geometrie/vecteur.h>
#include <formes/cercle.h>
#include "ChargerDonneesCercle.h"

ChargerDonneesCercle::ChargerDonneesCercle(ChargerDonneesCOR * suivant) : ChargerDonneesCOR(suivant) {}

const Forme * ChargerDonneesCercle::analyser1(std::ifstream & f_in, std::string nomForme) const {

    if(nomForme == "Cercle") {

        std::string line;
        std::string::size_type size;

        getline(f_in, line, '\n');  // {
        getline(f_in, line, '\n');  // Première variable
        line = line.std::substr(line.std::find(":") + 1);
        const char *couleur = line.c_str();

        getline(f_in, line, '\n');
        line = line.std::substr(line.std::find("(") + 1);
        double origine1 = std::stod(line, &size);
        line = line.substr(size);
        double origine2 = std::stod(line, &size);

        getline(f_in, line, '\n');
        line = line.std::substr(line.std::find(":") + 1);
        double rayon = std::stod(line, &size);

        getline(f_in, line, '\n');

        Cercle c(couleur, Vecteur(origine1, origine2), rayon);

        return &c;
    }

    return NULL;
}

const std::string ChargerDonneesCercle::toString() const {

    return "C'est un cercle !";
}
