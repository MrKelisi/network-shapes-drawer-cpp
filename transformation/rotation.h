#pragma once

#include <geometrie/vecteur.h>
#include "transformation.h"
#include <formes/segment.h>
#include <formes/cercle.h>
#include <formes/triangle.h>
#include <formes/polygone.h>

class Rotation : public Transformation {
    private:
        Vecteur _centre;
        double _angle;

    public:
        Rotation(const Vecteur& centre, double angle);

        virtual void transformer(Segment* segment) const override;
        virtual void transformer(Cercle* cercle) const override;
        virtual void transformer(Triangle* triangle) const override;
        virtual void transformer(Polygone* polygone) const override;
};