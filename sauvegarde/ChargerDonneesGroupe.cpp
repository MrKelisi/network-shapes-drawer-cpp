#include <geometrie/vecteur.h>
#include <formes/groupe.h>
#include <affichage/affichagedistant.h>
#include "ChargerDonneesGroupe.h"

ChargerDonneesGroupe::ChargerDonneesGroupe(ChargerDonneesCOR * suivant) :
        ChargerDonneesForme("Groupe", suivant) {

}

Forme * ChargerDonneesGroupe::analyserForme(std::ifstream& f_in) const {
    return new Groupe(couleur());
}