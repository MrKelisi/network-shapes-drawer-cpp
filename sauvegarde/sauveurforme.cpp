#include "sauveurforme.h"
#include "ChargerDonnesForme.h"
#include <formes/cercle.h>
#include <formes/polygone.h>
#include <formes/segment.h>
#include <formes/triangle.h>
#include <formes/groupe.h>

class chargerDonneesCercle;

SauveurForme::SauveurForme(const std::string& nomFichier) {
    _filename = nomFichier;
}

SauveurForme::~SauveurForme() {}

void SauveurForme::enregistrer(const std::string& data) const {
    std::ofstream f_out(_filename, std::ios_base::app);
    f_out << data;
    f_out.close();
}

void SauveurForme::vider() const {
    std::ofstream f_out(_filename);
    f_out.close();
}

void SauveurForme::visiter(const Cercle* cercle) const {
    std::string data = "Cercle\n";

    data += visiterForme(cercle);

    data += visiterVecteur(cercle->centre());
    data += "\n";

    data += std::to_string(cercle->rayon());
    data += "\n";

    data += FIN "\n";

    enregistrer(data);
}

void SauveurForme::visiter(const Polygone* polygone) const {
    std::string data = "Polygone\n";

    data += visiterForme(polygone);

    for(unsigned long i = 0; i < polygone->nombrePoints(); i++) {
        data += visiterVecteur(polygone->point(i));
        data += "\n";
    }

    data += FIN "\n";
    enregistrer(data);
}

void SauveurForme::visiter(const Segment* segment) const {
    std::string data = "Segment\n";

    data += visiterForme(segment);

    data += visiterVecteur(segment->debut());
    data += "\n";

    data += visiterVecteur(segment->fin());
    data += "\n";

    data += FIN "\n";
    enregistrer(data);
}

void SauveurForme::visiter(const Triangle* triangle) const {
    std::string data = "Triangle\n";

    data += visiterForme(triangle);

    data += visiterVecteur(triangle->p1());
    data += "\n";

    data += visiterVecteur(triangle->p2());
    data += "\n";

    data += visiterVecteur(triangle->p3());
    data += "\n";

    data += FIN "\n";
    enregistrer(data);
}

void SauveurForme::visiter(const Groupe* groupe) const {
    std::string data = "Groupe\n";

    data += visiterForme(groupe);
    enregistrer(data);

    for(unsigned long i = 0; i < groupe->nombreFormes(); i++) {
        groupe->forme(i)->visiter(*this);
    }

    data = FIN "\n";
    enregistrer(data);
}

std::string SauveurForme::visiterVecteur(const Vecteur& vecteur) const {
    return std::to_string(vecteur.x()) + "," + std::to_string(vecteur.y());
}
std::string SauveurForme::visiterForme(const Forme* forme) const {
    std::string data;

    data += forme->couleur() + "\n";
    data += FIN "\n";

    return data;
}