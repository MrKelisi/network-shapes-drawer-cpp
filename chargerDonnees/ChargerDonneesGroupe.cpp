#include <geometrie/vecteur.h>
#include <formes/groupe.h>
#include <affichage/affichagedistant.h>
#include "ChargerDonneesGroupe.h"

ChargerDonneesGroupe::ChargerDonneesGroupe(ChargerDonneesCOR * suivant) : ChargerDonneesCOR(suivant) {}

Forme * ChargerDonneesGroupe::analyser1(std::ifstream & f_in, std::string nomForme) const {

    if(nomForme == "Groupe") {

        std::string line;

        getline(f_in, line, '\n');  // [

        getline(f_in, line, '\n');  // Première variable : couleur
        line = line.substr(line.find(':') + 1);
        std::string couleur = line;

        return new Groupe(couleur.c_str());
    }
    else {
        return nullptr;
    }
}

const std::string ChargerDonneesGroupe::toString() const {

    return "C'est un groupe !";
}
