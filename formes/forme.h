#pragma once

#include <transformation/transformation.h>
#include <couleur.h>
#include <iostream>

class Forme {
    private:
        Couleur _couleur;

    protected:
        Forme(Couleur couleur);

    public:
        inline Couleur couleur() const;

        void setCouleur(Couleur couleur);

        virtual void transformer(const Transformation& transformation) = 0;
        virtual void afficher(std::ostream& o) const = 0;

        bool equals(const Forme& base) const;
        bool operator == (const Forme& base) const;
        bool operator != (const Forme& base) const;

        friend std::ostream& operator << (std::ostream& o, const Forme& base);
};

Couleur Forme::couleur() const {
    return _couleur;
}

