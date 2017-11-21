#include "groupe.h"
#include <algorithm>
#include <exceptions/GroupeException.h>

Groupe::Groupe(const char* couleur) :
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
        throw std::out_of_range("Indice invalide");
    }
    return _formes[index];
}

Forme* Groupe::forme(unsigned long index) {
    if(index >= _formes.size()) {
        throw std::out_of_range("Indice invalide");
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

double Groupe::aire() const {
    double aire = 0;

    for(Forme* forme : _formes) {
        aire += forme->aire();
    }

    return aire;
}

Forme* Groupe::clone() const {
    throw new GroupeException("Un groupe ne peut pas être cloné"); //TODO: ?
}

