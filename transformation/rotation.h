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
        //TODO: cosinus/sinus

    public:
        /**
         * @brief Crée une opération de rotation
         * @param centre Centre de la rotation
         * @param angle Angle de rotation
         */
        Rotation(const Vecteur& centre, double angle);

        virtual void modifier(Segment* segment) const override;
        virtual void modifier(Cercle* cercle) const override;
        virtual void modifier(Triangle* triangle) const override;

    protected:
        virtual Vecteur nouveauPointPolygone(const Vecteur& point) const override;
};