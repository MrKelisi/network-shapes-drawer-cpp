#include <cmath>
#include <iostream>
#include "vecteur.h"
#include <const.h>
#include <sstream>

Vecteur::Vecteur(double x, double y) :
        _x(x),
        _y(y) {

}

double Vecteur::norme() const {
    return sqrt(pow(x(), 2) + pow(y(), 2));
}

void Vecteur::setX(double x) {
    _x = x;
}

void Vecteur::setY(double y) {
    _y = y;
}

Vecteur Vecteur::translate(const Vecteur& vecteur) const {
    return *this + vecteur;
}

Vecteur Vecteur::homothetie(const Vecteur& centre, double facteur) const {
    return centre + ((*this - centre) * facteur);
}

Vecteur Vecteur::rotation(double angle) const {
    double cosa = std::cos(angle);
    double sina = std::sin(angle);
    return Vecteur(x() * cosa - y() * sina, x() * sina + y() * cosa);
}

Vecteur Vecteur::rotation(const Vecteur& centre, double angle) const {
    return centre + (*this - centre).rotation(angle);
}

Vecteur Vecteur::operator+(const Vecteur& vecteur) const {
    Vecteur copy(*this);
    copy += vecteur;
    return copy;
}

Vecteur Vecteur::operator+=(const Vecteur& vecteur) {
    _x += vecteur.x();
    _y += vecteur.y();
    return *this;
}

Vecteur Vecteur::operator-(const Vecteur& vecteur) const {
    Vecteur copy(*this);
    copy -= vecteur;
    return copy;
}

Vecteur Vecteur::operator-=(const Vecteur& vecteur) {
    _x -= vecteur.x();
    _y -= vecteur.y();
    return *this;
}

Vecteur Vecteur::operator*(double scalaire) const {
    Vecteur copy(*this);
    copy *= scalaire;
    return copy;
}

Vecteur Vecteur::operator*=(double scalaire) {
    _x *= scalaire;
    _y *= scalaire;
    return *this;
}

Vecteur Vecteur::operator-() const {
    return Vecteur(-x(), -y());
}

bool Vecteur::operator==(const Vecteur& vecteur) const {
    return std::abs(x() - vecteur.x()) < PRECISION &&
           std::abs(y() - vecteur.y()) < PRECISION;
}

bool Vecteur::operator!=(const Vecteur& vecteur) const {
    return !(*this == vecteur);
}

Vecteur::operator std::string() const {
    std::ostringstream o;
    o << "Vecteur(" << x() << ";" << y() << ")";
    return o.str();
}

std::ostream& operator<<(std::ostream& o, const Vecteur& vecteur) {
    o << (std::string) vecteur;
    return o;
}

double Vecteur::determinant(const Vecteur& other) const {
    return x() * other.y() - y() * other.x();
}
