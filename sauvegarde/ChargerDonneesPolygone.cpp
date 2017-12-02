#include <geometrie/vecteur.h>
#include <formes/polygone.h>
#include <exceptions/argumentexception.h>
#include "ChargerDonneesPolygone.h"

ChargerDonneesPolygone::ChargerDonneesPolygone(ChargerDonneesCOR * suivant) : ChargerDonneesCOR(suivant) {}

Forme * ChargerDonneesPolygone::analyser1(std::ifstream& f_in, const std::string& nomForme) const {

    if(nomForme == "Polygone") {

        std::string line;
        std::vector<Vecteur> points;
        bool continuerChercherPoints = true;

        getline(f_in, line, '\n');  // {

        const std::string couleur = analyserCouleur(f_in);

        while(continuerChercherPoints) {
            try {
                Vecteur temp = analyserVecteur(f_in);
                points.push_back(temp);
            }
            catch(ArgumentException e) {
                continuerChercherPoints = false;
            }
        }

        Polygone * p = new Polygone(couleur);
        for(std::vector<Vecteur>::iterator it = points.begin(); it != points.end(); it++)
            p->ajouter(*it);

        return p;
    }
    else {
        return nullptr;
    }
}

const std::string ChargerDonneesPolygone::toString() const {

    return "C'est un polygone !";
}
