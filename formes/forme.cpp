#include "forme.h"
#include "groupe.h"

Forme::Forme(Couleur couleur) :
    _couleur(couleur),
    _groupe(nullptr) {

}

Forme::Forme(const Forme& forme) :
    _couleur(forme._couleur),
    _groupe(nullptr) {

}

Couleur Forme::couleurAffichee() const {
    const Groupe* first = groupe();

    if(first == nullptr) {
        return couleur();
    }
    else {
        while(first->groupe() != nullptr) {
            first = first->groupe();
        }

        return first->couleur();
    }
}

void Forme::setCouleur(Couleur couleur) {
    _couleur = couleur;
}

void Forme::setGroupe(Groupe* groupe) {
    if(_groupe != nullptr) {
        _groupe->removeForme(this);
    }

    _groupe = groupe;

    if(_groupe != nullptr) {
        _groupe->addForme(this);
    }
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
