#pragma once

class Cercle;
class Polygone;
class Segment;
class Triangle;
class Groupe;

class Afficheur { //TODO: utiliser une classe VisiteurFormes ?
    public:
        virtual void afficher(const Cercle* cercle) = 0;
        virtual void afficher(const Polygone* polygone) = 0;
        virtual void afficher(const Segment* segment) = 0;
        virtual void afficher(const Triangle* triangle) = 0;
        virtual void afficher(const Groupe* groupe) = 0;
};