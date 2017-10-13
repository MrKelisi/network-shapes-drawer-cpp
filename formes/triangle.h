#pragma once

#include <geometrie/point.h>
#include "base.h"

class Triangle : public Base {
    private:
        Point _p1;
        Point _p2;
        Point _p3;

    public:
        Triangle(Couleur couleur, const Point& p1, const Point& p2, const Point& p3);
        //Pas besoin de constructeur par copie
        //Pas besoin de destructeur

        inline Point p1() const;
        inline Point p2() const;
        inline Point p3() const;

        void setP1(const Point& p1);
        void setP2(const Point& p2);
        void setP3(const Point& p3);

        void transformer(const Transformation& transformation) override;
        void afficher(std::ostream& o) const override;

        bool operator == (const Triangle& triangle) const;
        bool operator != (const Triangle& triangle) const;
};

Point Triangle::p1() const {
    return _p1;
}

Point Triangle::p2() const {
    return _p2;
}

Point Triangle::p3() const {
    return _p3;
}