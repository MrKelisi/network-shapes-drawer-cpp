#pragma once

enum Couleur {
    BLACK,
    BLUE,
    RED,
    GREEN,
    YELLOW,
    CYAN
};

/**
 * @brief Donne la chaîne de caractères associée à la couleur
 * @param c Couleur
 * @return Chaîne de caractères
 */
const char* getChaineCouleur(Couleur c);