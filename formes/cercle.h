#pragma once

#include <ostream>
#include <geometrie/vecteur.h>
#include "forme.h"

class Cercle : public Forme {
    private:
        Vecteur _centre;
        double _rayon;

    public:
        Cercle(Couleur couleur, const Vecteur& centre, double rayon);
        //Pas besoin de constructeur par copie
        //Pas besoin de destructeur

        inline const Vecteur& centre() const;
        inline double rayon() const;

        void setCentre(const Vecteur& centre);
        void setRayon(double rayon);

        virtual void modifier(const ModificateurForme& modificateur) override;
        virtual void visiter(const VisiteurForme& visiteur) const override;
        void afficher(std::ostream& o) const override;

        virtual bool operator == (const Cercle& cercle) const;
        virtual bool operator != (const Cercle& cercle) const;
};

const Vecteur& Cercle::centre() const {
    return _centre;
}

double Cercle::rayon() const {
    return _rayon;
}