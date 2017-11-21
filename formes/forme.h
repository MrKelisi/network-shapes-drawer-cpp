#pragma once

#include <couleur.h>
#include <iostream>
#include "visiteurforme.h"
#include "modificateurforme.h"

class Groupe;

class Forme {
    private:
        const char* _couleur;
        Groupe* _groupe;

    protected:
        Forme(const char* couleur);
        Forme(const Forme& forme);

    public:
        /**
         * @brief Donne la couleur de la forme
         * @return Couleur
         */
        inline const char* couleur() const;

        /**
         * @brief Donne le groupe de la forme
         * @return Groupe
         */
        inline const Groupe* groupe() const;

        /**
         * @brief Donne le groupe de la forme
         * @return Groupe
         */
        inline Groupe* groupe();

        /**
         * @brief Donne l'aire de la forme
         * @return Aire
         */
        virtual double aire() const = 0;

        /**
         * @brief Donne la couleur à afficher de la forme
         * @return Couleur
         */
        const char* couleurAffichee() const;

        /**
         * @brief Change la couleur de la forme
         * @param couleur Nouvelle couleur
         */
        void setCouleur(const char* couleur);

        /**
         * @brief Change le groupe de la forme
         * @param groupe Nouveau groupe
         */
        void setGroupe(Groupe* groupe);

        /**
         * @brief Modifie la forme
         * @param modificateur Objet qui va modifier la forme
         */
        virtual void modifier(const ModificateurForme& modificateur) = 0;

        /**
         * @brief Crée une nouvelle forme avec une transformation
         * @param modificateurForme Objet de transformation
         * @return Nouvelle forme
         */
        Forme* modifierNouveau(const ModificateurForme& modificateurForme) const;

        /**
         * @brief Visite la forme
         * @param visiteur Objet qui va visiter la forme
         */
        virtual void visiter(const VisiteurForme& visiteur) const = 0;

        /**
         * @brief Affiche la forme sur le flux donné
         * @param o Flux de sortie
         */
        virtual void afficher(std::ostream& o) const = 0;

        /**
         * @brief Clone la forme actuelle
         * @return Nouvelle forme
         */
        virtual Forme* clone() const = 0;

        friend std::ostream& operator << (std::ostream& o, const Forme& base);
};
const Groupe* Forme::groupe() const {
    return _groupe;
}

Groupe* Forme::groupe() {
    return _groupe;
}

const char* Forme::couleur() const {
    return _couleur;
}