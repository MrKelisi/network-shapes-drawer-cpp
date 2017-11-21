#pragma once

#include <geometrie/vecteur.h>
#include "forme.h"

class Segment : public Forme {
    private:
        Vecteur _debut;
        Vecteur _fin;

        bool operator == (const Segment&) const;
        bool operator != (const Segment&) const;

    public:
        Segment(const char* couleur, const Vecteur& debut, const Vecteur& fin);

        /**
         * @brief Donne le point de départ du segment
         * @return Point de départ
         */
        inline const Vecteur& debut() const;

        /**
         * @brief Donne le point d'arrivée du segment
         * @return Point d'arrivée
         */
        inline const Vecteur& fin() const;
        double aire() const override;

        /**
         * @brief Définit le début du segment
         * @param debut Nouveau point de départ
         */
        void setDebut(const Vecteur& debut);

        /**
         * @brief Définit la fin du segment
         * @param fin Nouveau point d'arrivée
         */
        void setFin(const Vecteur& fin);

        virtual void modifier(const ModificateurForme& modificateur) override;
        virtual void visiter(const VisiteurForme& visiteur) const override;
        virtual void afficher(std::ostream& o) const override;

        virtual Forme* clone() const override;
};

const Vecteur& Segment::debut() const {
    return _debut;
}

const Vecteur& Segment::fin() const {
    return _fin;
}
