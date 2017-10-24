#include "cercle.h"
#include <const.h>
#include <math.h>

Cercle::Cercle(Couleur couleur, const Vecteur& centre, double rayon) :
    Forme(couleur),
    _centre(centre),
    _rayon(rayon) {

}

void Cercle::setCentre(const Vecteur& centre) {
    _centre = centre;
}

void Cercle::setRayon(double rayon) {
    _rayon = rayon;
}

bool Cercle::operator == (const Cercle& cercle) const {
    return Forme::equals(cercle) &&
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

void Cercle::afficher(Afficheur* afficheur) const {
    afficheur->afficher(this);
}

double Cercle::aire() const {
    return M_PI * pow(rayon(), 2);
}
