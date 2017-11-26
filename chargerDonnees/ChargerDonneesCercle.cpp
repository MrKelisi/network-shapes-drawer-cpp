//
// Created by mrkel on 24/11/2017.
//

#include <geometrie/vecteur.h>
#include <formes/cercle.h>
#include <affichage/affichagedistant.h>
#include "ChargerDonneesCercle.h"

ChargerDonneesCercle::ChargerDonneesCercle(ChargerDonneesCOR * suivant) : ChargerDonneesCOR(suivant) {}

const Forme * ChargerDonneesCercle::analyser1(std::ifstream & f_in, std::string nomForme, Forme * &f) const {

    if(nomForme == "Cercle") {

        std::string line;

        getline(f_in, line, '\n');  // {

        getline(f_in, line, '\n');  // Première variable : couleur
        line = line.substr(line.find(':') + 1);
        std::string couleur = line;

        getline(f_in, line, '\n');  // Deuxième variable : origine
        line = line.substr(line.find('(') + 1);
        double origine_x = stod(line.substr(0, line.find(',')));
        line = line.substr(line.find(',') + 1);
        double origine_y = stod(line.substr(0, line.find(')')));

        getline(f_in, line, '\n');  // Troisième variable : rayon
        line = line.substr(line.find(':') + 1);
        double rayon = stod(line);

        getline(f_in, line, '\n');  // }

        f = new Cercle(couleur.c_str(), Vecteur(origine_x, origine_y), rayon);
        std::cout << "Chargement de la forme : " << *f << std::endl;  // Verifie que le cercle a été crée

        return f;
    }
    else {
        return nullptr;
    }
}

const std::string ChargerDonneesCercle::toString() const {

    return "C'est un cercle !";
}
