#include "sauveurforme.h"
#include <stdexcept>
#include <couleur.h>
#include <formes/cercle.h>
#include <formes/polygone.h>
#include <formes/segment.h>
#include <formes/triangle.h>
#include <formes/groupe.h>
#include <fstream>
#include <chargerDonnees/ChargerDonneesCercle.h>
#include <chargerDonnees/ChargerDonneesSegment.h>
#include <chargerDonnees/ChargerDonneesTriangle.h>
#include <chargerDonnees/ChargerDonneesPolygone.h>

class chargerDonneesCercle;

SauveurForme::SauveurForme(std::string nomFichier) {

    _filename = nomFichier;

    ChargerDonneesCOR *chargerDonneesCercle, *chargerDonneesSegment, *chargerDonneesTriangle, *chargerDonneesPolygone;

    chargerDonneesCercle = new ChargerDonneesCercle(NULL);
    chargerDonneesSegment = new ChargerDonneesSegment(chargerDonneesCercle);
    chargerDonneesTriangle = new ChargerDonneesTriangle(chargerDonneesSegment);
    chargerDonneesPolygone = new ChargerDonneesPolygone(chargerDonneesTriangle);

    _chargerDonnees = chargerDonneesPolygone;
}

SauveurForme::~SauveurForme() {}

void SauveurForme::enregistrer(const std::string& data) const {
    std::ofstream f_out(_filename, std::ios_base::app);
    f_out << data;
    f_out.close();
}

int SauveurForme::charger(Forme ** &formes) const {
    std::ifstream f_in(_filename);
    std::string nomForme;
    int i = 0;

    while (!f_in.eof()) {
        getline(f_in, nomForme, '\n');
        _chargerDonnees->analyser(f_in, nomForme, formes[i]);
        i++;
    }

    return (i - 1 < 0 ? 0 : i - 1);
}

void SauveurForme::vider() const {
    std::ofstream f_out(_filename); //vide le fichier
}

void SauveurForme::visiter(const Cercle* cercle) const {
    std::string data = "Cercle\n{\n";

    data += visiterForme(cercle);

    data += "  origine:";
    data += visiterVecteur(cercle->centre());
    data += "\n";

    data += "  rayon:";
    data += std::to_string(cercle->rayon());
    data += "\n";

    data += "}\n";

    enregistrer(data);
}

void SauveurForme::visiter(const Polygone* polygone) const {
    std::string data = "Polygone\n{\n";

    data += visiterForme(polygone);

    for(unsigned long i = 0; i < polygone->nombrePoints(); i++) {
        data += "  point" + std::to_string(i+1) + ":";
        data += visiterVecteur(polygone->point(i));
        data += "\n";
    }

    data += "}\n";
    enregistrer(data);
}

void SauveurForme::visiter(const Segment* segment) const {
    std::string data = "Segment\n{\n";

    data += visiterForme(segment);

    data += "  debut:";
    data += visiterVecteur(segment->debut());
    data += "\n";

    data += "  fin:";
    data += visiterVecteur(segment->fin());
    data += "\n";

    data += "}\n";
    enregistrer(data);
}

void SauveurForme::visiter(const Triangle* triangle) const {
    std::string data = "Triangle\n{\n";

    data += visiterForme(triangle);

    data += "  point1:";
    data += visiterVecteur(triangle->p1());
    data += "\n";

    data += "  point2:";
    data += visiterVecteur(triangle->p2());
    data += "\n";

    data += "  point3:";
    data += visiterVecteur(triangle->p3());
    data += "\n";

    data += "}\n";
    enregistrer(data);
}

void SauveurForme::visiter(const Groupe* groupe) const {
    for(unsigned long i = 0; i < groupe->nombreFormes(); i++) {
        groupe->forme(i)->visiter(*this);
    }
}

std::string SauveurForme::visiterVecteur(const Vecteur& vecteur) const {
    return "(" + std::to_string(vecteur.x()) + "," + std::to_string(vecteur.y()) + ")";
}
std::string SauveurForme::visiterForme(const Forme* forme) const {
    std::string data;

    data += "  couleur:";
    data += forme->couleurAffichee();
    data += "\n";

    return data;
}