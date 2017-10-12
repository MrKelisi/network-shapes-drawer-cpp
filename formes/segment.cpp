#include "segment.h"

Segment::Segment(Couleur couleur, const Point& debut, const Point& fin) :
    Base(couleur),
    _debut(debut),
    _fin(fin) {
}

void Segment::setDebut(const Point& debut) {
    _debut = debut;
}

void Segment::setFin(const Point& fin) {
    _fin = fin;
}

void Segment::transformer(const Transformation& transformation) {
    transformation.transformer(this);
}

void Segment::afficher(std::ostream& o) const {
    o << "Segment(" << debut() << ";" << fin() << ")";
}