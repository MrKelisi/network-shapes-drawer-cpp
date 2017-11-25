//
// Created by mrkel on 24/11/2017.
//

#include <geometrie/vecteur.h>
#include <formes/polygone.h>
#include <affichage/affichagedistant.h>
#include "ChargerDonneesPolygone.h"

ChargerDonneesPolygone::ChargerDonneesPolygone(ChargerDonneesCOR * suivant) : ChargerDonneesCOR(suivant) {}

const Forme * ChargerDonneesPolygone::analyser1(std::ifstream & f_in, std::string nomForme, Forme * &f) const {

    if(nomForme == "Polygone") {

        std::string line;

        getline(f_in, line, '\n');  // {

        getline(f_in, line, '\n');  // Première variable : couleur
        line = line.substr(line.find(':') + 1);
        std::string couleur = line;


        int nb = 0;
        double points_x[20], points_y[20];
        getline(f_in, line, '\n');

        while(line != "}") {

            line = line.substr(line.find('(') + 1);
            points_x[nb] = stod(line.substr(0, line.find(',')));
            line = line.substr(line.find(',') + 1);
            points_y[nb] = stod(line.substr(0, line.find(')')));

            nb++;
            getline(f_in, line, '\n');
        }

        Polygone p(couleur.c_str());
        for(int i = 0; i < nb; i++)
            p.ajouter(Vecteur(points_x[i], points_y[i]));

        std::cout << p << std::endl;  // Verifie que le polygone a été crée

        //AffichageDistant affichageDistant("127.0.0.1", 1952);  // Test du cercle crée à partir du fichier
        //c.visiter(affichageDistant);

        f = new Polygone(p);
        return &p;
    }
    else {
        return nullptr;
    }
}

const std::string ChargerDonneesPolygone::toString() const {

    return "C'est un polygone !";
}
