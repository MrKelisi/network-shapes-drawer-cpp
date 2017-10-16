#pragma once

#include <geometrie/vecteur.h>
#include <vector>
#include "forme.h"

class Polygone : public Forme {
    private:
        std::vector<Vecteur> _points;

    public:
        Polygone(Couleur couleur);
        //Pas besoin de constructeur par copie
        //Pas besoin de destructeur

        unsigned long nombrePoints() const;
        Vecteur point(unsigned long index) const;

        void ajouter(const Vecteur& point);

        void transformer(const Transformation& transformation) override;

        void afficher(std::ostream& o) const override;

        Polygone operator + (const Vecteur& point) const;
        Polygone operator += (const Vecteur& point);

        Polygone operator - (const Vecteur& point) const;
        Polygone operator -= (const Vecteur& point);

        Vecteur operator [] (unsigned long index) const;

        bool operator == (const Polygone& polygone) const;
        bool operator != (const Polygone& polygone) const;

        //Pas besoin de l'operateur =
};