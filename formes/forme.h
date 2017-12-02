#pragma once

#include <couleur.h>
#include <iostream>
#include "visiteurforme.h"
#include "modificateurforme.h"

class Groupe;

class Forme {
    private:
        std::string _couleur;
        Groupe* _groupe;

    protected:
        Forme(const std::string& couleur);
        Forme(const Forme& forme);

    public:
        /**
         * @brief Donne la couleur de la forme
         * @return Couleur
         */
        inline std::string couleur() const;

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
        std::string couleurAffichee() const;

        /**
         * @brief Change la couleur de la forme
         * @param couleur Nouvelle couleur
         */
        void setCouleur(const std::string couleur);

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
         * @brief Clone la forme actuelle
         * @return Nouvelle forme
         */
        virtual Forme* clone() const = 0;

        operator std::string() const;

        /**
         * @brief Converti la forme en std::string
         * @return std::string
         */
        virtual std::string toString() const = 0;

        friend std::ostream& operator << (std::ostream& o, const Forme& base);
};
const Groupe* Forme::groupe() const {
    return _groupe;
}

Groupe* Forme::groupe() {
    return _groupe;
}

std::string Forme::couleur() const {
    return _couleur;
}