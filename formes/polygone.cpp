#include "polygone.h"
#include <algorithm>

Polygone::Polygone(Couleur couleur) :
        Forme(couleur) {

}

unsigned long Polygone::nombrePoints() const {
    return _points.size();
}

Vecteur Polygone::point(unsigned long index) const {
    if(index >= _points.size()) {
        throw std::runtime_error("Indice invalide"); //TODO: exception
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

void Polygone::transformer(const Transformation& transformation) {
    transformation.transformer(this);
}

void Polygone::afficher(std::ostream& o) const {
    o << "Polygone(";

    std::vector<Vecteur>::const_iterator it = _points.begin();

    if(it != _points.end()) {
        o << *it;
        it++;

        while (it != _points.end()) {
            o << ";" << *it;
            it++;
        }
    }

    o << ")";
}

bool Polygone::operator==(const Polygone& polygone) const {
    return Forme::equals(polygone) &&
           _points == polygone._points; //TODO: verify
}

bool Polygone::operator!=(const Polygone& polygone) const {
    return !(*this == polygone);
}
