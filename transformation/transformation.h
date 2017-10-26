#pragma once

#include <formes/modificateurforme.h>
#include <formes/groupe.h>
#include <formes/segment.h>
#include <formes/cercle.h>
#include <formes/triangle.h>
#include <formes/polygone.h>

class Transformation : public ModificateurForme {
    public:
        virtual void modifier(Groupe* groupe) const override {
            for(unsigned long i = 0; i < groupe->nombreFormes(); i++) {
                groupe->forme(i)->modifier(*this);
            }
        }
};