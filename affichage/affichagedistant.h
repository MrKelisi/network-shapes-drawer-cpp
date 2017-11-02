#pragma once

#include <formes/visiteurforme.h>
#include <formes/forme.h>
#include <geometrie/vecteur.h>
#include "clientreseau.h"

class AffichageDistant : public VisiteurForme {
    public:
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

        std::string visiterForme(const Forme* forme) const;
        std::string visiterVecteur(const Vecteur& vecteur) const;

        void envoyer(const std::string& data) const;

        SOCKET _socket;
};