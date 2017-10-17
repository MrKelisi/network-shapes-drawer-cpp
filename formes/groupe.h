#pragma once

#include <vector>
#include "forme.h"

class Groupe : public Forme {
    private:
        std::vector<Forme*> _formes;

        Groupe(const Groupe& groupe);
        Groupe operator = (const Groupe& groupe);

        void addForme(Forme* forme);
        void removeForme(Forme* forme);

    public:
        Groupe(Couleur couleur);
        ~Groupe();

        unsigned long nombreFormes() const;
        const Forme* forme(unsigned long index) const;
        Forme* forme(unsigned long index);

        void transformer(const Transformation& transformation) override;
        void afficher(std::ostream& o) const override;

        Forme* operator [] (unsigned long index);
        const Forme* operator [] (unsigned long index) const;

        Groupe& operator += (Forme* forme);
        Groupe& operator -= (Forme* forme);

        friend void Forme::setGroupe(Groupe* groupe);
};