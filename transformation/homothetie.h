#pragma once

#include <transformation/transformation.h>
#include <geometrie/vecteur.h>
#include <formes/segment.h>
#include <formes/cercle.h>
#include <formes/triangle.h>
#include <formes/polygone.h>


class Homothetie : public Transformation {
    private:
        Vecteur _centre;
        double _facteur;

    public:
        Homothetie(const Vecteur& centre, double facteur);

        virtual void modifier(Segment* segment) const override;
        virtual void modifier(Cercle* cercle) const override;
        virtual void modifier(Triangle* triangle) const override;
        virtual void modifier(Polygone* polygone) const override;
};