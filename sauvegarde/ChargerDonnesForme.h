#pragma once

#include "ChargerDonneesCOR.h"

#define FIN "FIN"

class ChargerDonneesForme : public ChargerDonneesCOR {
    public:
        ChargerDonneesForme(const std::string& nomForme, ChargerDonneesCOR* suivant);

    protected:
        Forme* analyser1(std::ifstream& f_in, const std::string& nomForme) override;

        /**
         * @brief Analyse une forme du type de la classe
         * @param f_in Flux provenant du fichier exporté
         * @return Pointeur vers la forme, ou nullptr si elle n'a pas pu être analysée
         * @throws ChargementException si la forme n'est pas valide
         */
        virtual Forme* analyserForme(std::ifstream& f_in) const = 0;

        /**
         * @brief Lis un double depuis le flux
         * @param f_in Flux
         * @return Double correspondant
         * @throws ChargementException si la ligne n'est pas valide
         */
        double analyserDouble(std::ifstream& f_in) const;

        /**
         * @brief Analyse un vecteur depuis le flux
         * @param f_in Flux
         * @return Vecteur correspondant
         * @throws ChargementException si la ligne n'est pas valide
         */
        Vecteur analyserVecteur(std::ifstream& f_in) const;

        /**
         * @brief Analyse une couleur depuis le flux
         * @param f_in Flux
         * @return Couleur correspondante
         * @throws ChargementException si la ligne n'est pas valide
         */
        std::string analyserCouleur(std::ifstream& f_in) const;

        /**
         * @brief Donne la ligne suivante du fichier
         * @param f_in Flux du fichier
         * @return Ligne suivante
         * @throws ChargementException si la ligne n'est pas valide
         */
        std::string getLine(std::ifstream& f_in) const;

        /**
         * @brief Donne la couleur de la forme
         * @return Couleur
         */
        inline const std::string& couleur() const;

        /**
         * @brief Attent la fin de la forme dans le fichier
         * @param f_in Flux du fichier
         */
        inline void atteindreFinForme(std::ifstream& f_in) const;

    private:
        std::string _nomForme;
        std::string _couleur;
};

const std::string& ChargerDonneesForme::couleur() const {
    return _couleur;
}

void ChargerDonneesForme::atteindreFinForme(std::ifstream& f_in) const {
    while(getLine(f_in) != FIN && !f_in.eof()) {
    }
}
