#pragma once

#include <vector>
#include "forme.h"

class Groupe : public Forme {
    private:
        std::vector<Forme*> _formes;

        void addForme(Forme* forme);
        void removeForme(Forme* forme);

    public:
        Groupe(const std::string couleur);
        Groupe(const Groupe& groupe);
        virtual ~Groupe();

        /**
         * @brief Donne le nombre de formes présentes dans le groupe
         * @return Nombre de formes
         */
        unsigned long nombreFormes() const;

        /**
         * @brief Donne la forme à l'indice donné
         * @param index Indice de la forme
         * @return Pointeur sur la forme
         */
        const Forme* forme(unsigned long index) const;

        /**
         * @brief Donne la forme à l'indice donné
         * @param index Indice de la forme
         * @return Pointeur sur la forme
         */
        Forme* forme(unsigned long index);

        /**
         * @brief Donne l'aire du groupe
         * @return Aire
         */
        double aire() const override;

        void setGroupe(Groupe* groupe) override;

        virtual void modifier(const ModificateurForme& modificateur) override;
        virtual void visiter(const VisiteurForme& visiteur) const override;

        virtual Forme* clone() const override;

        Forme* operator [] (unsigned long index);
        const Forme* operator [] (unsigned long index) const;

        Groupe operator + (Forme* forme);
        Groupe& operator += (Forme* forme);

        Groupe operator - (Forme* forme);
        Groupe& operator -= (Forme* forme);

        Groupe& operator = (const Groupe& groupe);

        friend void Forme::setGroupe(Groupe* groupe);

        virtual std::string toString() const override;
};