#include "triangle.h"

Triangle::Triangle(const std::string couleur, const Vecteur& p1, const Vecteur& p2, const Vecteur& p3) :
        Forme(couleur),
        _p1(p1),
        _p2(p2),
        _p3(p3) {

}

void Triangle::setP1(const Vecteur& p1) {
    Triangle::_p1 = p1;
}

void Triangle::setP2(const Vecteur& p2) {
    Triangle::_p2 = p2;
}

void Triangle::setP3(const Vecteur& p3) {
    Triangle::_p3 = p3;
}

void Triangle::afficher(std::ostream& o) const {
    o << "Triangle(" << _p1 << ";" << _p2 << ";" << _p3 << ")";
}

void Triangle::modifier(const ModificateurForme& modificateur) {
    modificateur.modifier(this);
}

void Triangle::visiter(const VisiteurForme& visiteur) const {
    visiteur.visiter(this);
}

double Triangle::aire() const {
    return (p2() - p1()).determinant(p3() - p1()) / 2;
}

Forme* Triangle::clone() const {
    return new Triangle(*this);
}

std::string Triangle::toString() const {
    return std::string("Triangle(p1=") + (std::string) p1() + ";p2=" + (std::string) p2() + ";p3=" + (std::string) p3() + ")";
}
