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

void Cercle::afficher(std::ostream& o) const {
    o << "Cercle(centre:" << _centre << "; rayon:" << _rayon << ")";
}

void Cercle::modifier(const ModificateurForme& modificateur) {
    modificateur.modifier(this);
}

void Cercle::visiter(const VisiteurForme& visiteur) const {
    visiteur.visiter(this);
}

double Cercle::aire() const {
    return M_PI * pow(rayon(), 2);
}
