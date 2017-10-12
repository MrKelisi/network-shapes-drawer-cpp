#include "base.h"

Base::Base(Couleur couleur) :
    _couleur(couleur) {

}

void Base::setCouleur(Couleur couleur) {
    _couleur = couleur;
}

std::ostream& operator<<(std::ostream& o, const Base& base) {
    o << "Base(couleur=" << getChaineCouleur(base.couleur()) << "; ";
    base.afficher(o);
    o << ")";

    return o;
}
