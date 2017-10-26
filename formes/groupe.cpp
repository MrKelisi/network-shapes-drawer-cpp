#include "groupe.h"
#include <algorithm>

Groupe::Groupe(Couleur couleur) :
    Forme(couleur) {

}

Groupe::~Groupe() {
    for(Forme* forme : _formes) {
        forme->setGroupe(nullptr);
    }
}

unsigned long Groupe::nombreFormes() const {
    return _formes.size();
}

const Forme* Groupe::forme(unsigned long index) const {
    if(index >= _formes.size()) {
        throw std::runtime_error("Indice invalide"); //TODO: exception
    }
    return _formes[index];
}

Forme* Groupe::forme(unsigned long index) {
    if(index >= _formes.size()) {
        throw std::runtime_error("Indice invalide"); //TODO: exception
    }
    return _formes[index];
}

void Groupe::addForme(Forme* forme) {
    _formes.push_back(forme);
}

void Groupe::removeForme(Forme* forme) {
    std::vector<Forme*>::const_iterator it = std::find(_formes.begin(), _formes.end(), forme);
    if(it != _formes.end()) {
        _formes.erase(it);
    }
}

void Groupe::afficher(std::ostream& o) const {
    o << "Groupe(";

    std::vector<Forme*>::const_iterator it = _formes.begin();
    if(it != _formes.end()) {
        o << *(*it);
        it++;

        while(it != _formes.end()) {
            o << ";" << *(*it);
            it++;
        }
    }

    o << ")";
}

Forme* Groupe::operator[](unsigned long index) {
    return forme(index);
}

const Forme* Groupe::operator[](unsigned long index) const {
    return forme(index);
}

Groupe& Groupe::operator+=(Forme* forme) {
    forme->setGroupe(this);
    return *this;
}

Groupe& Groupe::operator-=(Forme* forme) {
    forme->setGroupe(nullptr);
    return *this;
}

void Groupe::modifier(const ModificateurForme& modificateur) {
    modificateur.modifier(this);
}

void Groupe::visiter(const VisiteurForme& visiteur) const {
    visiteur.visiter(this);
}

