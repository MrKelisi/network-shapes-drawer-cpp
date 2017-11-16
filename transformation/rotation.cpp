#include "rotation.h"

Rotation::Rotation(const Vecteur& centre, double angle) :
        _centre(centre),
        _angle(angle) {

}

void Rotation::modifier(Segment* segment) const {
    segment->setDebut(segment->debut().rotation(_centre, _angle));
    segment->setFin(segment->fin().rotation(_centre, _angle));
}

void Rotation::modifier(Cercle* cercle) const {
    cercle->setCentre(cercle->centre().rotation(_centre, _angle));
}

void Rotation::modifier(Triangle* triangle) const {
    triangle->setP1(triangle->p1().rotation(_centre, _angle));
    triangle->setP2(triangle->p2().rotation(_centre, _angle));
    triangle->setP3(triangle->p3().rotation(_centre, _angle));
}

Vecteur Rotation::nouveauPointPolygone(const Vecteur& point) const {
    return point.rotation(_centre, _angle);
}


