//
// Created by mrkel on 24/11/2017.
//

#include <geometrie/vecteur.h>
#include <formes/segment.h>
#include <affichage/affichagedistant.h>
#include "ChargerDonneesSegment.h"

ChargerDonneesSegment::ChargerDonneesSegment(ChargerDonneesCOR * suivant) : ChargerDonneesCOR(suivant) {}

Forme * ChargerDonneesSegment::analyser1(std::ifstream & f_in, std::string nomForme) const {

    if(nomForme == "Segment") {

        std::string line;

        getline(f_in, line, '\n');  // {

        getline(f_in, line, '\n');  // Première variable : couleur
        line = line.substr(line.find(':') + 1);
        std::string couleur = line;

        getline(f_in, line, '\n');  // Deuxième variable : debut
        line = line.substr(line.find('(') + 1);
        double debut_x = stod(line.substr(0, line.find(',')));
        line = line.substr(line.find(',') + 1);
        double debut_y = stod(line.substr(0, line.find(')')));

        getline(f_in, line, '\n');  // Troisième variable : fin
        line = line.substr(line.find('(') + 1);
        double fin_x = stod(line.substr(0, line.find(',')));
        line = line.substr(line.find(',') + 1);
        double fin_y = stod(line.substr(0, line.find(')')));

        getline(f_in, line, '\n');  // }

        return new Segment(couleur.c_str(), Vecteur(debut_x, debut_y), Vecteur(fin_x, fin_y));
    }
    else {
        return nullptr;
    }
}

const std::string ChargerDonneesSegment::toString() const {

    return "C'est un segment !";
}
