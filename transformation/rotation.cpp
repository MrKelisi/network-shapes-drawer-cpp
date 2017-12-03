#define _USE_MATH_DEFINES
#include <cmath>
#include "rotation.h"

Rotation::Rotation(const Vecteur& centre, double angle) :
        _centre(centre),
        _cos(std::cos(angle)),
        _sin(std::sin(angle)) {

}

void Rotation::modifier(Segment* segment) const {
    segment->setDebut(segment->debut().rotation(_centre, _cos, _sin));
    segment->setFin(segment->fin().rotation(_centre, _cos, _sin));
}

void Rotation::modifier(Cercle* cercle) const {
    cercle->setCentre(cercle->centre().rotation(_centre, _cos, _sin));
}

void Rotation::modifier(Triangle* triangle) const {
    triangle->setP1(triangle->p1().rotation(_centre, _cos, _sin));
    triangle->setP2(triangle->p2().rotation(_centre, _cos, _sin));
    triangle->setP3(triangle->p3().rotation(_centre, _cos, _sin));
}

Vecteur Rotation::nouveauPointPolygone(const Vecteur& point) const {
    return point.rotation(_centre, _cos, _sin);
}


