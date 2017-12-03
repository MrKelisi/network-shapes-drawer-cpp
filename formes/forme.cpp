#include <exceptions/GroupeException.h>
#include <memory.h>
#include <sstream>
#include <exceptions/argumentexception.h>
#include "forme.h"
#include "groupe.h"

Forme::Forme(const std::string& couleur) :
    _groupe(nullptr) {

    setCouleur(couleur);
}

Forme::Forme(const Forme& forme) :
    _couleur(forme._couleur),
    _groupe(nullptr) {

    setGroupe(forme._groupe);

}

Forme::~Forme() {
    setGroupe(nullptr);
}

std::string Forme::couleurAffichee() const {
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

void Forme::setCouleur(const std::string couleur) {
    unsigned int i = 0;

    if(couleurs[i] == nullptr) {
        throw ArgumentException("La couleur n'existe pas");
    }

    while(couleurs[i] != couleur) {
        if(couleurs[i + 1] == nullptr) {
            throw ArgumentException("La couleur n'existe pas");
        }
        i++;
    }

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

std::ostream& operator<<(std::ostream& o, const Forme& base) {
    o << "Forme(couleur=" << base._couleur << "; " << base.toString() << ")";

    return o;
}

Forme* Forme::modifierNouveau(const ModificateurForme& modificateurForme) const {
    return modificateurForme.modifier(this);
}

Forme::operator std::string() const {
    std::ostringstream oss;
    oss << *this;
    return oss.str();
}

Forme& Forme::operator=(const Forme& other) {
    _couleur = other.couleur();
    _groupe = nullptr;
    setGroupe(other._groupe);

	return *this;
}
