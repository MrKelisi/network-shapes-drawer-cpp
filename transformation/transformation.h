#pragma once

class Segment;

class Transformation {
    public:
        virtual void transformer(Segment* segment) const = 0;
};