#include <affichage/affichagedistant.h>
#include <formes/triangle.h>

int main(int argc, char** argv) {
    AffichageDistant affichageDistant("127.0.0.1", 1952);

    Triangle t(GREEN, Vecteur(100,0), Vecteur(0, 100), Vecteur(200, 100));
    t.visiter(affichageDistant);
}