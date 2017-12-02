#include "cercle.h"
#include <const.h>
#include <math.h>
#include <exceptions/argumentexception.h>

Cercle::Cercle(const std::string couleur, const Vecteur& centre, double rayon) :
    Forme(couleur),
    _centre(centre),
    _rayon(rayon) {
    if(_rayon <= 0) {
        throw ArgumentException("Le rayon est null");
    }
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

Forme* Cercle::clone() const {
    return new Cercle(*this);
}

std::string Cercle::toString() const {
    return std::string("Cercle(centre=") + (std::string) centre() + ";rayon=" + std::to_string(rayon()) + ")";
}
