#include "cercle.h"

Cercle::Cercle(Couleur couleur, const Point& centre, double rayon) :
    Base(couleur),
    _centre(centre),
    _rayon(rayon) {

}

void Cercle::setCentre(const Point& centre) {
    _centre = centre;
}

void Cercle::setRayon(double rayon) {
    _rayon = rayon;
}

bool Cercle::operator == (const Cercle& cercle) const {
    return Base::equals(cercle) &&
           _centre == cercle._centre &&
           _rayon == cercle._rayon;
}

bool Cercle::operator != (const Cercle& cercle) const {
    return !(*this == cercle);
}

void Cercle::transformer(const Transformation& transformation) {
    transformation.transformer(this);
}

void Cercle::afficher(std::ostream& o) const {
    o << "Cercle(centre:" << _centre << "; rayon:" << _rayon << ")";
}
