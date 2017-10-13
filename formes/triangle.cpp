#include "triangle.h"

Triangle::Triangle(Couleur couleur, const Point& p1, const Point& p2, const Point& p3) :
        Base(couleur),
        _p1(p1),
        _p2(p2),
        _p3(p3) {

}

void Triangle::setP1(const Point& p1) {
    Triangle::_p1 = p1;
}

void Triangle::setP2(const Point& p2) {
    Triangle::_p2 = p2;
}

void Triangle::setP3(const Point& p3) {
    Triangle::_p3 = p3;
}

void Triangle::transformer(const Transformation& transformation) {
    transformation.transformer(this);
}

void Triangle::afficher(std::ostream& o) const {
    o << "Triangle(" << _p1 << ";" << _p2 << ";" << _p3 << ")";
}

bool Triangle::operator == (const Triangle& triangle) const {
    return Base::equals(triangle) &&
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

