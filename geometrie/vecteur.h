#pragma once

#include <iostream>

class Vecteur {
    private:
        double _x;
        double _y;

    public:
        Vecteur(double x, double y);
        //Pas besoin de constructeur par copie
        //Pas besoin de destructeur

        inline double x() const;
        inline double y() const;
        double norme() const;

        void setX(double x);
        void setY(double y);

        Vecteur translate(const Vecteur& vecteur) const;
        Vecteur homothetie(const Vecteur& centre, double facteur) const;
        Vecteur rotation(double angle) const;
        Vecteur rotation(const Vecteur& centre, double angle) const;

        Vecteur operator + (const Vecteur& vecteur) const;
        Vecteur operator += (const Vecteur& vecteur);

        Vecteur operator - (const Vecteur& vecteur) const;
        Vecteur operator -= (const Vecteur& vecteur);

        Vecteur operator * (double scalaire) const;
        Vecteur operator *= (double scalaire);

        Vecteur operator - () const;

        //Pas besoin de l'opérateur =

        bool operator == (const Vecteur& vecteur) const;
        bool operator != (const Vecteur& vecteur) const;

        operator std::string() const;

        friend std::ostream& operator << (std::ostream& o, const Vecteur& vecteur);
};

double Vecteur::x() const {
    return _x;
}

double Vecteur::y() const {
    return _y;
}
