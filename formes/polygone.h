#pragma once

#include <geometrie/vecteur.h>
#include <vector>
#include "forme.h"

class Polygone : public Forme {
    private:
        std::vector<Vecteur> _points;

        bool operator == (const Polygone&) const;
        bool operator != (const Polygone&) const;

    public:
        Polygone(const std::string couleur);
        //Pas besoin de constructeur par copie
        //Pas besoin de destructeur

        /**
         * @brief Donne le nombre de points du polygone
         * @return Nombre de points
         */
        inline unsigned long nombrePoints() const;

        /**
         * @brief Donne le point à l'indice donné
         * @param index Indice du point
         * @return Vecteur
         */
        Vecteur point(unsigned long index) const;
        double aire() const override;

        /**
         * @brief Ajoute un point
         * @param point à ajouter
         */
        void ajouter(const Vecteur& point);

        /**
         * @brief Remplace un point par un autre
         * @param index Indice du point à remplacer
         * @param point Nouveau point
         */
        void remplacer(unsigned long index, const Vecteur& point);

        virtual void modifier(const ModificateurForme& modificateur) override;
        virtual void visiter(const VisiteurForme& visiteur) const override;

        virtual Forme* clone() const override;

        Polygone operator + (const Vecteur& point) const;
        Polygone operator += (const Vecteur& point);

        Polygone operator - (const Vecteur& point) const;
        Polygone operator -= (const Vecteur& point);

        Vecteur operator [] (unsigned long index) const;

        //Pas besoin de l'operateur =

        virtual std::string toString() const override;
};

unsigned long Polygone::nombrePoints() const {
    return _points.size();
}