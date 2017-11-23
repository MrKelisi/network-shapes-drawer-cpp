#include "segment.h"

Segment::Segment(const char* couleur, const Vecteur& debut, const Vecteur& fin) :
    Forme(couleur),
    _debut(debut),
    _fin(fin) {
}

void Segment::setDebut(const Vecteur& debut) {
    _debut = debut;
}

void Segment::setFin(const Vecteur& fin) {
    _fin = fin;
}

void Segment::afficher(std::ostream& o) const {
    o << "Segment(" << debut() << ";" << fin() << ")";
}

void Segment::modifier(const ModificateurForme& modificateur) {
    modificateur.modifier(this);
}

void Segment::visiter(const VisiteurForme& visiteur) const {
    visiteur.visiter(this);
}

double Segment::aire() const {
    return 0;
}

Forme* Segment::clone() const {
    return new Segment(*this);
}

std::string Segment::toString() const {
    return std::string("Segment(debut=") + (std::string) debut() + ";fin=" + (std::string) fin() + ")";
}
