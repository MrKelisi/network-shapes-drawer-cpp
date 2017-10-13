#include "base.h"

Base::Base(Couleur couleur) :
    _couleur(couleur) {

}

void Base::setCouleur(Couleur couleur) {
    _couleur = couleur;
}

bool Base::equals(const Base& base) const {
    return couleur() == base.couleur();
}

bool Base::operator == (const Base& base) const {
    return equals(base);
}

bool Base::operator!=(const Base& base) const {
    return !equals(base);
}

std::ostream& operator<<(std::ostream& o, const Base& base) {
    o << "Base(couleur=" << getChaineCouleur(base.couleur()) << "; ";
    base.afficher(o);
    o << ")";

    return o;
}
