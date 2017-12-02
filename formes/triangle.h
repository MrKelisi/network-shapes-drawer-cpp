#pragma once

#include <geometrie/vecteur.h>
#include "forme.h"

class Triangle : public Forme {
    private:
        Vecteur _p1;
        Vecteur _p2;
        Vecteur _p3;

        bool operator == (const Triangle&) const;
        bool operator != (const Triangle&) const;

    public:
        Triangle(const std::string couleur, const Vecteur& p1, const Vecteur& p2, const Vecteur& p3);
        //Pas besoin de constructeur par copie
        //Pas besoin de destructeur

        /**
         * @brief Donne le premier point du triangle
         * @return Premier point
         */
        inline Vecteur p1() const;

        /**
         * @brief Donne le deuxième point du triangle
         * @return Deuxième point
         */
        inline Vecteur p2() const;

        /**
         * @brief Donne le troisième point du triangle
         * @return Troisième point
         */
        inline Vecteur p3() const;
        double aire() const override;

        /**
         * @brief Définit le premier point du triangle
         * @param p1 Premier point
         */
        void setP1(const Vecteur& p1);

        /**
         * @brief Définit le deuxième point du triangle
         * @param p2 Deuxième point
         */
        void setP2(const Vecteur& p2);

        /**
         * @brief Définit le troisième point du triangle
         * @param p3 Troisième point
         */
        void setP3(const Vecteur& p3);

        virtual void modifier(const ModificateurForme& modificateur) override;
        virtual void visiter(const VisiteurForme& visiteur) const override;
        void afficher(std::ostream& o) const override;

        virtual Forme* clone() const override;

        virtual std::string toString() const override;
};

Vecteur Triangle::p1() const {
    return _p1;
}

Vecteur Triangle::p2() const {
    return _p2;
}

Vecteur Triangle::p3() const {
    return _p3;
}