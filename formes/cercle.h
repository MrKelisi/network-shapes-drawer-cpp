#pragma once

#include <ostream>
#include <geometrie/vecteur.h>
#include "forme.h"

class Cercle : public Forme {
    private:
        Vecteur _centre;
        double _rayon;

        bool operator == (const Cercle&) const;
        bool operator != (const Cercle&) const;

    public:
        Cercle(const std::string couleur, const Vecteur& centre, double rayon);
        //Pas besoin de constructeur par copie
        //Pas besoin de destructeur

        /**
         * @brief Donne le centre du cercle
         * @return Centre
         */
        inline const Vecteur& centre() const;

        /**
         * @brief Donne le rayon du cercle
         * @return Rayon
         */
        inline double rayon() const;

        /**
         * @brief Définit le centre du cercle
         * @param centre Centre
         */
        void setCentre(const Vecteur& centre);

        /**
         * @brief Définit le rayon du cercle
         * @param rayon Rayon
         */
        void setRayon(double rayon);

        virtual void modifier(const ModificateurForme& modificateur) override;
        virtual void visiter(const VisiteurForme& visiteur) const override;
        double aire() const override;

        virtual Forme* clone() const override;

        virtual std::string toString() const override;
};

const Vecteur& Cercle::centre() const {
    return _centre;
}

double Cercle::rayon() const {
    return _rayon;
}