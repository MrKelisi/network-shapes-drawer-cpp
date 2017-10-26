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

        virtual void modifier(Segment* segment) const override;
        virtual void modifier(Cercle* cercle) const override;
        virtual void modifier(Triangle* triangle) const override;
        virtual void modifier(Polygone* polygone) const override;
};