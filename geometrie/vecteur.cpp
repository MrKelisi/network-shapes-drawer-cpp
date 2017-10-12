#include <cmath>
#include <sstream>
#include "vecteur.h"

Vecteur::Vecteur(const Point& destination) :
        _destination(destination) {
}

Vecteur::Vecteur(const Point& origine, const Point& destination) :
    _destination(destination - origine) {
}

void Vecteur::setDestination(const Point& destination) {
    _destination = destination;
}

void Vecteur::setDestination(const Point& origine, const Point& destination) {
    _destination = destination - origine;
}

double Vecteur::norme() const {
    return sqrt(pow(destination().x(), 2) + pow(destination().y(), 2));
}

Vecteur Vecteur::operator+(const Vecteur& vecteur) const {
    return Vecteur(destination() + vecteur.destination());
}

Vecteur Vecteur::operator+=(const Vecteur& vecteur) {
    _destination += vecteur.destination();
    return *this;
}

Vecteur Vecteur::operator-(const Vecteur& vecteur) const {
    return Vecteur(destination() - vecteur.destination());
}

Vecteur Vecteur::operator-=(const Vecteur& vecteur) {
    _destination -= vecteur.destination();
    return *this;
}

Vecteur Vecteur::operator*(double scalaire) const {
    return Vecteur(Point(destination().x() * scalaire, destination().y() * scalaire));
}

Vecteur Vecteur::operator*=(double scalaire) {
    destination().setX(destination().x() * scalaire);
    destination().setY(destination().y() * scalaire);
    return *this;
}

Vecteur Vecteur::operator-() const {
    return Vecteur(- destination());
}

bool Vecteur::operator==(const Vecteur& vecteur) const {
    return destination() == vecteur.destination();
}

bool Vecteur::operator!=(const Vecteur& vecteur) const {
    return destination() != vecteur.destination();
}

Vecteur::operator std::string() const {
    std::ostringstream o;
    o << "Vecteur(" << destination() << ")";
    return o.str();
}

std::ostream& operator<<(std::ostream& o, const Vecteur& vecteur) {
    o << (std::string) vecteur;
    return o;
}
