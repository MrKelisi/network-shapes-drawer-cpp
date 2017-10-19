#pragma once

#include <transformation/transformation.h>
#include <couleur.h>
#include <iostream>
#include <affichage/afficheur.h>

class Groupe;


class Forme {
    private:
        Couleur _couleur;
        Groupe* _groupe;

    protected:
        Forme(Couleur couleur);
        Forme(const Forme& forme);

    public:
        inline Couleur couleur() const;
        inline const Groupe* groupe() const;
        inline Groupe* groupe();

        void setCouleur(Couleur couleur);
        void setGroupe(Groupe* groupe);

        virtual void transformer(const Transformation& transformation) = 0;
        virtual void afficher(std::ostream& o) const = 0;
        virtual void afficher(Afficheur* afficheur) const = 0;

        bool equals(const Forme& base) const;
        bool operator == (const Forme& base) const;
        bool operator != (const Forme& base) const;

        friend std::ostream& operator << (std::ostream& o, const Forme& base);
};
const Groupe* Forme::groupe() const {
    return _groupe;
}

Groupe* Forme::groupe() {
    return _groupe;
}

Couleur Forme::couleur() const {
    return _couleur;
}