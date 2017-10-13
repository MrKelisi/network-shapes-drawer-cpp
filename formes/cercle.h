#pragma once

#include <geometrie/point.h>
#include <ostream>
#include "base.h"

class Cercle : public Base {
    private:
        Point _centre;
        double _rayon;

    public:
        Cercle(Couleur couleur, const Point& centre, double rayon);
        //Pas besoin de constructeur par copie
        //Pas besoin de destructeur

        inline const Point& centre() const;
        inline double rayon() const;

        void setCentre(const Point& centre);
        void setRayon(double rayon);

        void transformer(const Transformation& transformation) override;
        void afficher(std::ostream& o) const override;

        virtual bool operator == (const Cercle& cercle) const;
        virtual bool operator != (const Cercle& cercle) const;
};

const Point& Cercle::centre() const {
    return _centre;
}

double Cercle::rayon() const {
    return _rayon;
}