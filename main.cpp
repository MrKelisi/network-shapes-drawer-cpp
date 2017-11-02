#include <affichage/affichagedistant.h>
#include <formes/segment.h>

int main(int argc, char** argv) {
    AffichageDistant affichageDistant("127.0.0.1", 1952);

    Segment s(CYAN, Vecteur(0,0), Vecteur(100, 100));
    s.visiter(affichageDistant);
}