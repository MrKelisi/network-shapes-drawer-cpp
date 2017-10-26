#include "translation.h"

Translation::Translation(const Vecteur& translation) :
    _translation(translation) {

}

void Translation::modifier(Segment* segment) const {
    segment->setDebut(segment->debut() + _translation);
    segment->setFin(segment->fin() + _translation);
}

void Translation::modifier(Cercle* cercle) const {
    cercle->setCentre(cercle->centre() + _translation);
}

void Translation::modifier(Triangle* triangle) const {
    triangle->setP1(triangle->p1() + _translation);
    triangle->setP2(triangle->p2() + _translation);
    triangle->setP3(triangle->p3() + _translation);
}

void Translation::modifier(Polygone* polygone) const {
    for(unsigned long i = 0; i < polygone->nombrePoints(); i++) {
        polygone->remplacer(i, polygone->point(i).translate(_translation));
    }
}
