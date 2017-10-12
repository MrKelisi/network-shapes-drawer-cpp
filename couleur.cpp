#include <couleur.h>

const char* getChaineCouleur(Couleur c) {
    switch(c) {
        case BLACK:
            return "black";

        case BLUE:
            return "blue";

        case RED:
            return "red";

        case GREEN:
            return "green";

        case YELLOW:
            return "yellow";

        case CYAN:
            return "cyan";
    }

    return nullptr; //TODO: exception
}
