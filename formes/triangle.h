#pragma once

#include <geometrie/vecteur.h>
#include "forme.h"

class Triangle : public Forme {
    private:
        Vecteur _p1;
        Vecteur _p2;
        Vecteur _p3;

    public:
        Triangle(Couleur couleur, const Vecteur& p1, const Vecteur& p2, const Vecteur& p3);
        //Pas besoin de constructeur par copie
        //Pas besoin de destructeur

        inline Vecteur p1() const;
        inline Vecteur p2() const;
        inline Vecteur p3() const;

        void setP1(const Vecteur& p1);
        void setP2(const Vecteur& p2);
        void setP3(const Vecteur& p3);

        void transformer(const Transformation& transformation) override;
        void afficher(std::ostream& o) const override;
        virtual void afficher(Afficheur* afficheur) const override;

        double aire() const override;

        bool operator == (const Triangle& triangle) const;
        bool operator != (const Triangle& triangle) const;
};

Vecteur Triangle::p1() const {
    return _p1;
}

Vecteur Triangle::p2() const {
    return _p2;
}

Vecteur Triangle::p3() const {
    return _p3;
}