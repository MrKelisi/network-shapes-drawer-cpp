#include <exceptions/GroupeException.h>
#include "forme.h"
#include "groupe.h"

Forme::Forme(const char* couleur) :
    _couleur(couleur),
    _groupe(nullptr) {

}

Forme::Forme(const Forme& forme) :
    _couleur(forme._couleur),
    _groupe(nullptr) {

}

const char* Forme::couleurAffichee() const {
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

void Forme::setCouleur(const char* couleur) {
    _couleur = couleur;
}

void Forme::setGroupe(Groupe* groupe) {
    const Groupe* parent = groupe;
    while(parent != nullptr) {
        if(parent == this) {
            throw GroupeException("Il ne peut pas y avoir de cycle de groupe");
        }
        parent = parent->groupe();
    }

    if(_groupe != nullptr) {
        _groupe->removeForme(this);
    }

    _groupe = groupe;

    if(_groupe != nullptr) {
        _groupe->addForme(this);
    }
}

std::ostream& operator<<(std::ostream& o, const Forme& base) {
    o << "Forme(couleur=" << base._couleur << "; ";
    base.afficher(o);
    o << ")";

    return o;
}

Forme* Forme::modifierNouveau(const ModificateurForme& modificateurForme) const {
    return modificateurForme.modifier(this);
}
