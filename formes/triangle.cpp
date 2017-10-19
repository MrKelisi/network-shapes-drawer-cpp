#include "triangle.h"

Triangle::Triangle(Couleur couleur, const Vecteur& p1, const Vecteur& p2, const Vecteur& p3) :
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

void Triangle::transformer(const Transformation& transformation) {
    transformation.transformer(this);
}

void Triangle::afficher(std::ostream& o) const {
    o << "Triangle(" << _p1 << ";" << _p2 << ";" << _p3 << ")";
}

bool Triangle::operator == (const Triangle& triangle) const {
    return Forme::equals(triangle) &&
           (
                _p1 == triangle._p1 &&
                (_p2 == triangle._p2 && _p3 == triangle._p3) ||
                (_p2 == triangle._p3 && _p3 == triangle._p2)
           ) || (
               _p1 == triangle._p2 &&
               (_p2 == triangle._p1 && _p3 == triangle._p3) ||
               (_p2 == triangle._p3 && _p3 == triangle._p1)
           ) || (
               _p1 == triangle._p3 &&
               (_p2 == triangle._p1 && _p3 == triangle._p2) ||
               (_p2 == triangle._p2 && _p3 == triangle._p1)
           );
}

bool Triangle::operator != (const Triangle& triangle) const {
    return !(triangle == *this);
}

void Triangle::afficher(Afficheur* afficheur) const {
    afficheur->afficher(this);
}