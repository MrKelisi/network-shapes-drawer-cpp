#pragma once

class Cercle;
class Polygone;
class Segment;
class Triangle;
class Groupe;

class ModificateurForme {
    public:
        virtual void modifier(Cercle* cercle) const = 0;
        virtual void modifier(Polygone* polygone) const = 0;
        virtual void modifier(Segment* segment) const = 0;
        virtual void modifier(Triangle* triangle) const = 0;
        virtual void modifier(Groupe* groupe) const = 0;
};