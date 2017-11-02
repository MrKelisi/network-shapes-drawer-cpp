#include <affichage/affichagedistant.h>
#include <formes/polygone.h>

int main(int argc, char** argv) {
    AffichageDistant affichageDistant("127.0.0.1", 1952);

    Polygone p(RED);
    p.ajouter(Vecteur(0,0));
    p.ajouter(Vecteur(0,10));
    p.ajouter(Vecteur(10,10));

    p.visiter(affichageDistant);
}