#pragma once

#include <iostream>

class Vecteur {
    private:
        double _x;
        double _y;

    public:
        /**
         * @brief Crée un vecteur ayant pour base (0; 0)
         * @param x Abscisse
         * @param y Ordonnée
         */
        Vecteur(double x, double y);
        //Pas besoin de constructeur par copie
        //Pas besoin de destructeur

        /**
         * @brief Donne l'abscisse du vecteur
         * @return Abscisse
         */
        inline double x() const;

        /**
         * @brief Donne l'ordonnée du vecteur
         * @return Ordonnée
         */
        inline double y() const;

        /**
         * @brief Donne la norme du vecteur
         * @return Norme du vecteur
         */
        double norme() const;

        /**
         * @brief Donne le déterminant du vecteur actuel comparé à un autre vecteur
         * @param other Autre vecteur
         * @return Déterminant
         */
        double determinant(const Vecteur& other) const;

        /**
         * @brief Définit l'abscisse du vecteur
         * @param x Nouvelle abscisse
         */
        void setX(double x);

        /**
         * @brief Définit l'ordonnée du vecteur
         * @param y Nouvelle ordonnée
         */
        void setY(double y);

        /**
         * @brief Effectue une opération de translation sur le point de destination du vecteur
         * @param vecteur Vecteur de translation
         * @return Nouveau vecteur
         */
        Vecteur translate(const Vecteur& vecteur) const;

        /**
         * @brief Effectue une opération d'homothétie sur le vecteur
         * @param centre Centre de l'homothétie
         * @param facteur Facteur d'agrandissement
         * @return Nouveau vecteur
         */
        Vecteur homothetie(const Vecteur& centre, double facteur) const;

        /**
         * @brief Effectue une rotation autour du point (0; 0)
         * @param cos Cosinus de l'angle
         * @param sin Sinus de l'angle
         * @return Nouveau vecteur
         */
        Vecteur rotation(double cos, double sin) const;

        /**
         * @brief Effectue une rotation autour du point donné
         * @param centre Centre de la rotation
         * @param cos Cosinus de l'angle
         * @param sin Sinus de l'angle
         * @return Nouveau vecteur
         */
        Vecteur rotation(const Vecteur& centre, double cos, double sin) const;

        /**
         * @brief Additionne deux vecteurs
         * @param vecteur à additionnner
         * @return Nouveau vecteur
         */
        Vecteur operator + (const Vecteur& vecteur) const;

        /**
         * @brief Ajoute un vecteur au vecteur actuel
         * @param vecteur Vecteur à ajouter
         * @return Ce vecteur
         */
        Vecteur operator += (const Vecteur& vecteur);

        /**
         * @brief Soustraire deux vecteurs
         * @param vecteur à soustraire
         * @return Nouveau vecteur
         */
        Vecteur operator - (const Vecteur& vecteur) const;

        /**
         * @brief Soustrait un vecteur au vecteur actuel
         * @param vecteur Vecteur à soustraire
         * @return Ce vecteur
         */
        Vecteur operator -= (const Vecteur& vecteur);

        /**
         * @brief Multiplie le vecteur par un scalaire
         * @param scalaire Facteur
         * @return Nouveau vecteur
         */
        Vecteur operator * (double scalaire) const;

        /**
         * @brief Multiplie ce vecteur par un scalaire
         * @param scalaire Facteur
         * @return Ce vecteur
         */
        Vecteur operator *= (double scalaire);

        /**
         * @brief Donne l'opposé du vecteur
         * @return Nouveau vecteur
         */
        Vecteur operator - () const;

        //Pas besoin de l'opérateur =

        bool operator == (const Vecteur& vecteur) const;
        bool operator != (const Vecteur& vecteur) const;

        operator std::string() const;

        friend std::ostream& operator << (std::ostream& o, const Vecteur& vecteur);
};

double Vecteur::x() const {
    return _x;
}

double Vecteur::y() const {
    return _y;
}
