//
// Created by mrkel on 24/11/2017.
//

#include <geometrie/vecteur.h>
#include <formes/triangle.h>
#include <affichage/affichagedistant.h>
#include "ChargerDonneesTriangle.h"

ChargerDonneesTriangle::ChargerDonneesTriangle(ChargerDonneesCOR * suivant) : ChargerDonneesCOR(suivant) {}

const Forme * ChargerDonneesTriangle::analyser1(std::ifstream & f_in, std::string nomForme, Forme * &f) const {

    if(nomForme == "Triangle") {

        std::string line;

        getline(f_in, line, '\n');  // {

        getline(f_in, line, '\n');  // Première variable : couleur
        line = line.substr(line.find(':') + 1);
        std::string couleur = line;

        getline(f_in, line, '\n');  // Deuxième variable : p1
        line = line.substr(line.find('(') + 1);
        double p1_x = stod(line.substr(0, line.find(',')));
        line = line.substr(line.find(',') + 1);
        double p1_y = stod(line.substr(0, line.find(')')));

        getline(f_in, line, '\n');  // Troisième variable : p2
        line = line.substr(line.find('(') + 1);
        double p2_x = stod(line.substr(0, line.find(',')));
        line = line.substr(line.find(',') + 1);
        double p2_y = stod(line.substr(0, line.find(')')));

        getline(f_in, line, '\n');  // Quatrième variable : p3
        line = line.substr(line.find('(') + 1);
        double p3_x = stod(line.substr(0, line.find(',')));
        line = line.substr(line.find(',') + 1);
        double p3_y = stod(line.substr(0, line.find(')')));

        getline(f_in, line, '\n');  // }

        Triangle t(couleur.c_str(), Vecteur(p1_x, p1_y), Vecteur(p2_x, p2_y), Vecteur(p3_x, p3_y));
        std::cout << t << std::endl;  // Verifie que le triangle a été crée

        //AffichageDistant affichageDistant("127.0.0.1", 1952);  // Test du cercle crée à partir du fichier
        //c.visiter(affichageDistant);

        f = new Triangle(couleur.c_str(), Vecteur(p1_x, p1_y), Vecteur(p2_x, p2_y), Vecteur(p3_x, p3_y));
        return &t;
    }
    else {
        return nullptr;
    }
}

const std::string ChargerDonneesTriangle::toString() const {

    return "C'est un triangle !";
}
