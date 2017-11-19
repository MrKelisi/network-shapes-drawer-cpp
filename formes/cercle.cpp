#include "cercle.h"
#include <const.h>
#include <math.h>

Cercle::Cercle(const char* couleur, const Vecteur& centre, double rayon) :
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
    return M_PI * rayon() * rayon();
}
