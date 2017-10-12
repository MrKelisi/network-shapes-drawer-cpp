#pragma once

#include <iostream>

class Vecteur;

class Point {
    private:
        double _x;
        double _y;

    public:
        Point(double x, double y);
        //Pas besoin de constructeur par copie
        //Pas besoin de destructeur

        inline double x() const;
        inline double y() const;

        void setX(double x);
        void setY(double y);

        Point translate(const Vecteur& vecteur) const;
        Point homothetie(const Point& centre, double facteur) const;
        Point rotation(const Point& centre, double angle) const;

        //Pas besoin de l'operateur =

        Point operator + (const Point& point) const;
        Point operator += (const Point& point);

        Point operator + (const Vecteur& vecteur) const;
        Point operator += (const Vecteur& vecteur);

        Point operator + (double offset) const;
        Point operator += (double offset);

        Point operator - (const Point& point) const;
        Point operator -= (const Point& point);

        Point operator - (double offset) const;
        Point operator -= (double offset);

        Point operator - (const Vecteur& vecteur) const;
        Point operator -= (const Vecteur& vecteur);

        Point operator - () const;

        bool operator == (const Point& point) const;
        bool operator != (const Point& point) const;

        operator std::string() const;
        friend std::ostream& operator << (std::ostream& o, const Point& point);
};

double Point::x() const {
    return _x;
}

double Point::y() const {
    return _y;
}
