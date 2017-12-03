#include "groupe.h"
#include <algorithm>
#include <exceptions/GroupeException.h>

Groupe::Groupe(const std::string couleur) :
    Forme(couleur) {

}

Groupe::Groupe(const Groupe& groupe) :
    Forme(groupe.couleur()) {

    for(unsigned long i = 0; i < groupe._formes.size(); i++) {
        groupe._formes[i]->clone()->setGroupe(this);
    }
}

Groupe::~Groupe() {
	for (unsigned long i = 0; i < _formes.size(); i++) {
        _formes[i]->setGroupe(nullptr);
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

Groupe Groupe::operator+(Forme* forme) {
    Groupe nouveau(*this);
    nouveau += forme;
    return nouveau;
}

Groupe Groupe::operator-(Forme* forme) {
    Groupe nouveau(*this);
    nouveau -= forme;
    return nouveau;
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
    return new Groupe(*this);
}

std::string Groupe::toString() const {
    std::string res = "Groupe(";

    std::vector<Forme*>::const_iterator it = _formes.begin();

    if(it != _formes.end()) {
        res += (*it)->toString();
        it++;

        while(it != _formes.end()) {
            res += ";" + (*it)->toString();
            it++;
        }
    }

    res += ")";
    return res;
}

Groupe& Groupe::operator=(const Groupe& groupe) {
    for(Forme* forme : _formes) {
        forme->setGroupe(nullptr);
    }

    for(Forme* forme : groupe._formes) {
        forme->clone()->setGroupe(this);
    }

    return *this;
}

void Groupe::setGroupe(Groupe* groupe) {
    const Groupe* parent = groupe;
    while(parent != nullptr) {
        if(parent == this) {
            throw GroupeException("Il ne peut pas y avoir de cycle de groupe");
        }
        parent = parent->groupe();
    }

    Forme::setGroupe(groupe);
}
