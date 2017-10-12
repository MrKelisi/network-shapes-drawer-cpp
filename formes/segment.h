#pragma once

#include <geometrie/point.h>
#include "base.h"

class Segment : public Base {
    private:
        Point _debut;
        Point _fin;

    public:
        Segment(Couleur couleur, const Point& debut, const Point& fin);

        inline const Point& debut() const;
        inline const Point& fin() const;

        void setDebut(const Point& debut);
        void setFin(const Point& fin);

        virtual void transformer(const Transformation& transformation) override;
        virtual void afficher(std::ostream& o) const override;
};

const Point& Segment::debut() const {
    return _debut;
}

const Point& Segment::fin() const {
    return _fin;
}