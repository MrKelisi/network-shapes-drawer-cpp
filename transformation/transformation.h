#pragma once

class Segment;
class Cercle;

class Transformation {
    public:
        virtual void transformer(Segment* segment) const = 0;
        virtual void transformer(Cercle* cercle) const = 0;
};