#pragma once

#include <transformation/transformation.h>
#include <couleur.h>
#include <iostream>

class Base {
    private:
        Couleur _couleur;

    protected:
        Base(Couleur couleur);

    public:
        inline Couleur couleur() const;

        void setCouleur(Couleur couleur);

        virtual void transformer(const Transformation& transformation) = 0;
        virtual void afficher(std::ostream& o) const = 0;

        friend std::ostream& operator << (std::ostream& o, const Base& base);
};

Couleur Base::couleur() const {
    return _couleur;
}

