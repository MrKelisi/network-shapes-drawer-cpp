#pragma once

#include <string>
#include <vector>
#include "ChargerDonnees.h"

class ChargeurForme {
    public:
        ChargeurForme(const std::string& fichier);
        inline std::vector<Forme*> formes();

    private:
        void charger(const std::string& fichier);

        ChargerDonnees* _chargerDonnees;
        std::vector<Forme*> _formes;
};

std::vector<Forme*> ChargeurForme::formes() {
    return _formes;
}
