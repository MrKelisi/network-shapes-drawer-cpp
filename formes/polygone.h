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

        inline unsigned long nombrePoints() const;
        Vecteur point(unsigned long index) const;
        double aire() const override;

        void ajouter(const Vecteur& point);
        void remplacer(unsigned long index, const Vecteur& point);

        virtual void modifier(const ModificateurForme& modificateur) override;
        virtual void visiter(const VisiteurForme& visiteur) const override;
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

unsigned long Polygone::nombrePoints() const {
    return _points.size();
}