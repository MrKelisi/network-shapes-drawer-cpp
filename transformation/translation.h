#pragma once

#include <geometrie/vecteur.h>
#include "transformation.h"
#include <formes/segment.h>
#include <formes/cercle.h>
#include <formes/triangle.h>
#include <formes/polygone.h>

class Translation : public Transformation {
    private:
        Vecteur _translation;

    public:
        Translation(const Vecteur& translation);

        void transformer(Segment* segment) const override;
        void transformer(Cercle* cercle) const override;
        void transformer(Triangle* triangle) const override;
        void transformer(Polygone* polygone) const override;
};