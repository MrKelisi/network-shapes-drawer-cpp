#include <formes/forme.h>
#include <geometrie/vecteur.h>
#include "ChargerDonneesCOR.h"
#include <stdexcept>
#include <exceptions/argumentexception.h>

ChargerDonneesCOR::ChargerDonneesCOR(ChargerDonneesCOR * suivant) : suivant(suivant) {}

Forme * ChargerDonneesCOR::analyser(std::ifstream & f_in, std::string nomForme) const {
    Forme * resultat;
    resultat = this->analyser1(f_in, nomForme);

    if (resultat != nullptr) {

        //std::cout << resultat << std::endl;
        return resultat;
    }

    else {

        if (this->suivant != NULL)	// puisque il y a un suivant, on lui confie la tâche
            return this->suivant->analyser(f_in, nomForme);
        else                        // c'était le dernier de la chaine, c'est donc un échec
            return nullptr;
    }
}

double ChargerDonneesCOR::analyserDouble(std::ifstream & f_in) const {
    std::string line;
    getline(f_in, line, '\n');

    line = line.substr(line.find(':') + 1);

    return stod(line);
}
Vecteur ChargerDonneesCOR::analyserVecteur(std::ifstream & f_in) const {
    std::string line;
    getline(f_in, line, '\n');

    try {
        line = line.substr(line.find('(') + 1);
        double point_x = stod(line.substr(0, line.find(',')));

        line = line.substr(line.find(',') + 1);
        double point_y = stod(line.substr(0, line.find(')')));

        return Vecteur(point_x, point_y);
    }
    catch(const std::invalid_argument& e) {
        throw ArgumentException("Impossible de lire le vecteur");
    }
}
const std::string ChargerDonneesCOR::analyserCouleur(std::ifstream & f_in) const {
    std::string line;
    getline(f_in, line, '\n');

    line = line.substr(line.find(':') + 1);
    return line;
}