#include "forme.h"

Forme::Forme(Couleur couleur) :
    _couleur(couleur) {

}

void Forme::setCouleur(Couleur couleur) {
    _couleur = couleur;
}

bool Forme::equals(const Forme& base) const {
    return couleur() == base.couleur();
}

bool Forme::operator == (const Forme& base) const {
    return equals(base);
}

bool Forme::operator!=(const Forme& base) const {
    return !equals(base);
}

std::ostream& operator<<(std::ostream& o, const Forme& base) {
    o << "Forme(couleur=" << getChaineCouleur(base.couleur()) << "; ";
    base.afficher(o);
    o << ")";

    return o;
}
