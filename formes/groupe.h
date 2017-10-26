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
        double aire() const override;

        virtual void modifier(const ModificateurForme& modificateur) override;
        virtual void visiter(const VisiteurForme& visiteur) const override;
        void afficher(std::ostream& o) const override;

        Forme* operator [] (unsigned long index);
        const Forme* operator [] (unsigned long index) const;

        Groupe& operator += (Forme* forme);
        Groupe& operator -= (Forme* forme);

        friend void Forme::setGroupe(Groupe* groupe);
};