#include <sstream>
#include "point.h"
#include "vecteur.h"

Point::Point(double x, double y) :
        _x(x),
        _y(y) {

}

Point Point::translate(const Vecteur& vecteur) {
    return (*this) + vecteur.destination();
}

Point Point::homothetie(const Point& centre, double facteur) {
    Vecteur v(centre, *this);
    v *= facteur;
    return centre + v;
}

Point Point::rotation(const Point& centre, double angle) {

}

Point Point::operator+(const Point& point) const {
    return Point(x() + point.x(), y() + point.y());
}

Point Point::operator-(const Point& point) const {
    return Point(x() - point.x(), y() - point.y());
}

Point Point::operator+=(const Point& point) {
    _x += point.x();
    _y += point.y();

    return *this;
}

Point Point::operator-=(const Point& point) {
    _x -= point.x();
    _y -= point.y();

    return *this;
}

Point Point::operator+(double offset) const {
    return Point(x() + offset, y() + offset);
}

Point Point::operator+=(double offset) {
    _x += offset;
    _y += offset;
    return *this;
}

Point Point::operator-(double offset) const {
    return Point(0, 0);
}

Point Point::operator-=(double offset) {
    return Point(0, 0);
}

Point Point::operator+(const Vecteur& vecteur) const {
    return (*this) + vecteur.destination();
}

Point Point::operator+=(const Vecteur& vecteur) {
    (*this) += vecteur.destination();
    return *this;
}

Point Point::operator-(const Vecteur& vecteur) const {
    return (*this) - vecteur.destination();
}

Point Point::operator-=(const Vecteur& vecteur) {
    (*this) -= vecteur.destination();
    return *this;
}

Point Point::operator-() const {
    return Point(-x(), -y());
}

Point::operator std::string() const {
    std::ostringstream o;
    o << "Point(" << x() << "; " << y() << ")";
    return o.str();
}

std::ostream& operator<<(std::ostream& o, const Point& point) {
    o << (std::string) point;
    return o;
}

bool Point::operator==(const Point& point) const {
    return x() == point.x() && y() == point.y();
}

bool Point::operator!=(const Point& point) const {
    return x() != point.x() || y() != point.y();
}

void Point::setX(double x) {
    _x = x;
}

void Point::setY(double y) {
    _y = y;
}
