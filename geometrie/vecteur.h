#pragma once

#include "point.h"

class Vecteur {
    private:
        Point _destination;

    public:
        Vecteur(const Point& destination);
        Vecteur(const Point& origine, const Point& destination);

        inline Point destination() const;

        void setDestination(const Point& destination);
        void setDestination(const Point& origine, const Point& destination);

        double norme() const;

        Vecteur operator + (const Vecteur& vecteur) const;
        Vecteur operator += (const Vecteur& vecteur);

        Vecteur operator - (const Vecteur& vecteur) const;
        Vecteur operator -= (const Vecteur& vecteur);

        Vecteur operator * (double scalaire) const;
        Vecteur operator *= (double scalaire);

        Vecteur operator - () const;

        bool operator == (const Vecteur& vecteur) const;
        bool operator != (const Vecteur& vecteur) const;

        operator std::string() const;

        friend std::ostream& operator << (std::ostream& o, const Vecteur& vecteur);
};

Point Vecteur::destination() const {
    return _destination;
}
