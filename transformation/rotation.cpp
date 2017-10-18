#include "rotation.h"

Rotation::Rotation(const Vecteur& centre, double angle) :
        _centre(centre),
        _angle(angle) {}

void Rotation::transformer(Segment* segment) const {
    segment->setDebut(segment->debut().rotation(_centre, _angle));
    segment->setFin(segment->fin().rotation(_centre, _angle));
}

void Rotation::transformer(Cercle* cercle) const {
    cercle->setCentre(cercle->centre().rotation(_centre, _angle));
}

void Rotation::transformer(Triangle* triangle) const {
    triangle->setP1(triangle->p1().rotation(_centre, _angle));
    triangle->setP2(triangle->p2().rotation(_centre, _angle));
    triangle->setP3(triangle->p3().rotation(_centre, _angle));
}

void Rotation::transformer(Polygone* polygone) const {
    for(unsigned long i = 0; i < polygone->nombrePoints(); i++) {
        polygone->remplacer(i, polygone->point(i).rotation(_centre, _angle));
    }
}
