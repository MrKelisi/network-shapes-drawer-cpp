#include "chargeurforme.h"
#include "ChargerDonneesCOR.h"
#include "ChargerDonneesCercle.h"
#include "ChargerDonneesSegment.h"
#include "ChargerDonneesPolygone.h"
#include "ChargerDonneesTriangle.h"
#include "ChargerDonneesGroupe.h"
#include <formes/groupe.h>

ChargeurForme::ChargeurForme(const std::string& fichier) {
    ChargerDonneesCOR* chargerDonneesCercle = new ChargerDonneesCercle(NULL);
    ChargerDonneesCOR* chargerDonneesSegment = new ChargerDonneesSegment(chargerDonneesCercle);
    ChargerDonneesCOR* chargerDonneesTriangle = new ChargerDonneesTriangle(chargerDonneesSegment);
    ChargerDonneesCOR* chargerDonneesPolygone = new ChargerDonneesPolygone(chargerDonneesTriangle);
    ChargerDonneesCOR* chargerDonneesGroupe = new ChargerDonneesGroupe(chargerDonneesPolygone);

    _chargerDonnees = chargerDonneesGroupe;

    charger(fichier);
}

void ChargeurForme::charger(const std::string& fichier) {
    std::ifstream f_in(fichier);
    std::string nomForme;
    Groupe* groupePtr = nullptr;

    while (!f_in.eof()) {
        getline(f_in, nomForme, '\n');

        Forme * formeCourante = _chargerDonnees->analyser(f_in, nomForme);

        if (formeCourante != NULL) {
            if(groupePtr != nullptr) {
                formeCourante->setGroupe(groupePtr);
            }
            else {
                _formes.push_back(formeCourante);
            }

            if(nomForme == "Groupe") {
                groupePtr = (Groupe*) formeCourante;
            }

        }
        else if(nomForme == FIN && groupePtr != nullptr) {
            groupePtr = groupePtr->groupe();
        }
    }

    f_in.close();
}