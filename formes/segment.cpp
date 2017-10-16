#include "segment.h"

Segment::Segment(Couleur couleur, const Vecteur& debut, const Vecteur& fin) :
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

void Segment::transformer(const Transformation& transformation) {
    transformation.transformer(this);
}

void Segment::afficher(std::ostream& o) const {
    o << "Segment(" << debut() << ";" << fin() << ")";
}
