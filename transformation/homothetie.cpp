#include "homothetie.h"

Homothetie::Homothetie(const Vecteur& centre, double facteur) :
        _centre(centre),
        _facteur(facteur) {

}

void Homothetie::modifier(Segment* segment) const {
    segment->setDebut(segment->debut().homothetie(_centre, _facteur));
    segment->setFin(segment->fin().homothetie(_centre, _facteur));
}

void Homothetie::modifier(Cercle* cercle) const {
    cercle->setCentre(cercle->centre().homothetie(_centre, _facteur));
    cercle->setRayon(cercle->rayon() * _facteur);
}

void Homothetie::modifier(Triangle* triangle) const {
    triangle->setP1(triangle->p1().homothetie(_centre, _facteur));
    triangle->setP2(triangle->p2().homothetie(_centre, _facteur));
    triangle->setP3(triangle->p3().homothetie(_centre, _facteur));
}

void Homothetie::modifier(Polygone* polygone) const {
    for(unsigned long i = 0; i < polygone->nombrePoints(); i++) {
        polygone->remplacer(i, polygone->point(i).homothetie(_centre, _facteur));
    }
}
