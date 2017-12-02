#include "chargeurforme.h"
#include "ChargerDonneesCOR.h"
#include "ChargerDonneesCercle.h"
#include "ChargerDonneesSegment.h"
#include "ChargerDonneesPolygone.h"
#include "ChargerDonneesTriangle.h"
#include "ChargerDonneesGroupe.h"

ChargeurForme::ChargeurForme(const std::string& fichier) {
    ChargerDonneesCOR *chargerDonneesCercle,
            *chargerDonneesSegment,
            *chargerDonneesTriangle,
            *chargerDonneesPolygone,
            *chargerDonneesGroupe;

    chargerDonneesCercle = new ChargerDonneesCercle(NULL);
    chargerDonneesSegment = new ChargerDonneesSegment(chargerDonneesCercle);
    chargerDonneesTriangle = new ChargerDonneesTriangle(chargerDonneesSegment);
    chargerDonneesPolygone = new ChargerDonneesPolygone(chargerDonneesTriangle);
    chargerDonneesGroupe = new ChargerDonneesGroupe(chargerDonneesPolygone);

    _chargerDonnees = chargerDonneesGroupe;

    charger(fichier);
}

void ChargeurForme::charger(const std::string& fichier) {
    std::ifstream f_in(fichier);
    std::string nomForme;
    Groupe * groupePtr;
    bool inGroupe = false;

    std::cout << "Chargement des formes : " << std::endl;

    while (!f_in.eof()) {
        getline(f_in, nomForme, '\n');

        Forme * formeCourante = _chargerDonnees->analyser(f_in, nomForme);

        if (formeCourante != NULL) {
            if(inGroupe) {
                formeCourante->setGroupe(&*groupePtr);
                std::cout << "  > dans le groupe : " << *formeCourante << std::endl;
            }
            else {
                if(nomForme == "Groupe") {
                    inGroupe = true;
                    groupePtr = (Groupe*) formeCourante;
                }
                _formes.push_back(formeCourante);
                std::cout << *formeCourante << std::endl;
            }
        }
        else if(nomForme == "]")
            inGroupe = false;
    }

    f_in.close();
}