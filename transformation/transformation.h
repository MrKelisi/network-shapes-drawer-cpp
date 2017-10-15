#pragma once

class Segment;
class Cercle;
class Triangle;
class Polygone;

class Transformation {
    public:
        virtual void transformer(Segment* segment) const = 0;
        virtual void transformer(Cercle* cercle) const = 0;
        virtual void transformer(Triangle* triangle) const = 0;
        virtual void transformer(Polygone* triangle) const = 0;
};