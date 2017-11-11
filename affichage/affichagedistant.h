#pragma once

#include <formes/visiteurforme.h>
#include <formes/forme.h>
#include <geometrie/vecteur.h>
#include "clientreseau.h"

class AffichageDistant : public VisiteurForme {
    public:
        /**
         * @brief Crée un affichage sur un serveur distant
         * @param serveur Adresse IP du serveur distant
         * @param port Port du serveur
         */
        AffichageDistant(const char* serveur, unsigned short port);
        virtual ~AffichageDistant();

        virtual void visiter(const Cercle* cercle) const override;
        virtual void visiter(const Polygone* polygone) const override;
        virtual void visiter(const Segment* segment) const override;
        virtual void visiter(const Triangle* triangle) const override;
        virtual void visiter(const Groupe* groupe) const override;

    private:
        AffichageDistant(const AffichageDistant&);
        AffichageDistant operator = (const AffichageDistant&);

        /**
         * @brief Méthode commune à toutes les formes
         * @param forme Forme à visiter
         * @return std::string contenant les données de la forme
         */
        std::string visiterForme(const Forme* forme) const;

        /**
         * @brief Donne les données du vecteur en tant que chaîne de caractères
         * @param vecteur Vecteur à traiter
         * @return std::string contenant les données du vecteur
         */
        std::string visiterVecteur(const Vecteur& vecteur) const;

        /**
         * @brief Envoie des données au serveur
         * @param data Données à envoyer
         */
        void envoyer(const std::string& data) const;

        SOCKET _socket;
};