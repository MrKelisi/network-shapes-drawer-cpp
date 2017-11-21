#include "modificateurforme.h"
#include "forme.h"

Forme* ModificateurForme::modifier(const Forme* forme) const {
    Forme* nouvelle = forme->clone();
    nouvelle->modifier(*this);
    return nouvelle;
}
