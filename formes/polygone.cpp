#include "polygone.h"
#include "triangle.h"
#include <algorithm>

Polygone::Polygone(const std::string couleur) :
        Forme(couleur) {

}

Vecteur Polygone::point(unsigned long index) const {
    if(index >= _points.size()) {
        throw std::out_of_range("Indice invalide");
    }

    return _points[index];
}

void Polygone::ajouter(const Vecteur& point) {
    _points.push_back(point);
}

void Polygone::remplacer(unsigned long index, const Vecteur& point) {
    _points[index] = point;
}

Polygone Polygone::operator+(const Vecteur& point) const {
    Polygone copy(*this);
    copy += point;
    return copy;
}

Polygone Polygone::operator+=(const Vecteur& point) {
    _points.push_back(point);
    return *this;
}

Polygone Polygone::operator-(const Vecteur& point) const {
    Polygone copy(*this);
    copy -= point;
    return copy;
}

Polygone Polygone::operator-=(const Vecteur& point) {
    std::vector<Vecteur>::const_iterator item = std::find(_points.begin(), _points.end(), point);
    if(item != _points.end()) {
        _points.erase(item);
    }

    return *this;
}

Vecteur Polygone::operator[](unsigned long index) const {
    return point(index);
}

void Polygone::modifier(const ModificateurForme& modificateur) {
    modificateur.modifier(this);
}

void Polygone::visiter(const VisiteurForme& visiteur) const {
    visiteur.visiter(this);
}

double Polygone::aire() const {
    double aire = 0;

    if(nombrePoints() < 3) {
        return 0;
    }

    std::vector<Vecteur>::const_iterator it = _points.begin();
    Vecteur base = *it;
    it++;
    Vecteur tmp = *it;
    it++;

    while(it != _points.end()) {
        Triangle t("red", base, tmp, *it);
        aire += t.aire();

        tmp = *it;
        it++;
    }

    return aire;
}

Forme* Polygone::clone() const {
    return new Polygone(*this);
}

std::string Polygone::toString() const {
    std::string res = "Polygone(";

    std::vector<Vecteur>::const_iterator it = _points.begin();

    if(it != _points.end()) {
        res += *it;
        it++;

        while(it != _points.end()) {
            res += ";";
            res += *it;
            it++;
        }
    }

    res += ")";
    return res;
}
