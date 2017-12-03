#include <string>
#include <exceptions/argumentexception.h>
#include <exceptions/chargementexception.h>
#include "ChargerDonnesForme.h"

ChargerDonneesForme::ChargerDonneesForme(const std::string& nomForme, ChargerDonneesCOR* suivant) :
        _nomForme(nomForme),
        ChargerDonneesCOR(suivant) {

}

Forme* ChargerDonneesForme::analyser1(std::ifstream& f_in, const std::string& nomForme) {
    if(_nomForme != nomForme) {
        return nullptr;
    }

    try {
        _couleur = analyserCouleur(f_in);

        atteindreFinForme(f_in);
    }
    catch (ChargementException e) {
        if(e.line() != FIN) {
            atteindreFinForme(f_in);
        }
    }

    try {
        return analyserForme(f_in);
    }
    catch (ChargementException e) {
        if(e.line() != FIN) {
            atteindreFinForme(f_in);
        }
    }
}

double ChargerDonneesForme::analyserDouble(std::ifstream& f_in) const {
    std::string line = getLine(f_in);

    try {
        return stod(line);
    }
    catch (std::invalid_argument e) {
        throw ChargementException("Impossible de lire le nombre réel", line);
    }
}
Vecteur ChargerDonneesForme::analyserVecteur(std::ifstream& f_in) const {
    std::string line = getLine(f_in);

    try {
        size_t posVirgule = line.find(',');
        double point_x = stod(line.substr(0, posVirgule));

        line = line.substr(posVirgule + 1);
        double point_y = stod(line);

        return Vecteur(point_x, point_y);
    }
    catch(const std::invalid_argument& e) {
        throw ChargementException("Impossible de lire le vecteur", line);
    }
}

std::string ChargerDonneesForme::analyserCouleur(std::ifstream& f_in) const {
    std::string line = getLine(f_in);
    unsigned int i = 0;

    if(couleurs[i] == nullptr) {
        throw ChargementException("La couleur n'existe pas", line);
    }

    while(couleurs[i] != line) {
        if(couleurs[i + 1] == nullptr) {
            throw ChargementException("La couleur n'existe pas", line);
        }
        i++;
    }
    return line;
}

std::string ChargerDonneesForme::getLine(std::ifstream& f_in) const {
    std::string line;

    getline(f_in, line, '\n');

    return line;
}
