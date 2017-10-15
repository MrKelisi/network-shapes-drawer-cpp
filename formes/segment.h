#pragma once

#include <geometrie/vecteur.h>
#include "base.h"

class Segment : public Base {
    private:
        Vecteur _debut;
        Vecteur _fin;

    public:
        Segment(Couleur couleur, const Vecteur& debut, const Vecteur& fin);

        inline const Vecteur& debut() const;
        inline const Vecteur& fin() const;

        void setDebut(const Vecteur& debut);
        void setFin(const Vecteur& fin);

        virtual void transformer(const Transformation& transformation) override;
        virtual void afficher(std::ostream& o) const override;
};

const Vecteur& Segment::debut() const {
    return _debut;
}

const Vecteur& Segment::fin() const {
    return _fin;
}