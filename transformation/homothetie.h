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

        virtual void transformer(Segment* segment) const override;

        virtual void transformer(Cercle* cercle) const override;

        virtual void transformer(Triangle* triangle) const override;

        virtual void transformer(Polygone* polygone) const override;
};