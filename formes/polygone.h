#pragma once

#include <vector>
#include "base.h"

class Polygone : public Base {
    private:
        std::vector _points;

    public:
        Polygone(Couleur couleur);
};