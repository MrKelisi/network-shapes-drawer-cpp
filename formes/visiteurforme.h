#pragma once

class Cercle;
class Polygone;
class Segment;
class Triangle;
class Groupe;

class VisiteurForme {
    public:
        virtual void visiter(const Cercle* cercle) const = 0;
        virtual void visiter(const Polygone* polygone) const = 0;
        virtual void visiter(const Segment* segment) const = 0;
        virtual void visiter(const Triangle* triangle) const = 0;
        virtual void visiter(const Groupe* groupe) const = 0;
};