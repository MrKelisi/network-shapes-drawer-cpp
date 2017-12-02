#include <geometrie/vecteur.h>
#include <formes/groupe.h>
#include <affichage/affichagedistant.h>
#include "ChargerDonneesGroupe.h"

ChargerDonneesGroupe::ChargerDonneesGroupe(ChargerDonneesCOR * suivant) : ChargerDonneesCOR(suivant) {}

Forme * ChargerDonneesGroupe::analyser1(std::ifstream & f_in, std::string nomForme) const {

    if(nomForme == "Groupe") {

        std::string line;

        getline(f_in, line, '\n');  // [

        const std::string couleur = analyserCouleur(f_in);

        return new Groupe(couleur);
    }
    else {
        return nullptr;
    }
}

const std::string ChargerDonneesGroupe::toString() const {

    return "C'est un groupe !";
}
