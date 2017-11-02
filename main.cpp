#include <affichage/affichagedistant.h>
#include <formes/triangle.h>
#include <formes/segment.h>
#include <formes/polygone.h>
#include <formes/cercle.h>
#include <formes/groupe.h>

int main(int argc, char** argv) {
    AffichageDistant affichageDistant("127.0.0.1", 1952);

    Triangle t(GREEN, Vecteur(110,0), Vecteur(60, 100), Vecteur(160, 100));

    Polygone p(CYAN);
    p.ajouter(Vecteur(105, 0));
    p.ajouter(Vecteur(115, 0));
    p.ajouter(Vecteur(115, 10));
    p.ajouter(Vecteur(105, 10));

    Segment s1(BLACK, Vecteur(60, 100), Vecteur(60, 200));
    Segment s2(YELLOW, Vecteur(160, 100), Vecteur(160, 200));

    Cercle c1(RED, Vecteur(60, 250), 50);
    Cercle c2(BLUE, Vecteur(160, 250), 50);

    t.visiter(affichageDistant);
    p.visiter(affichageDistant);
    s1.visiter(affichageDistant);
    s2.visiter(affichageDistant);
    c1.visiter(affichageDistant);
    c2.visiter(affichageDistant);

    /*Groupe g(BLACK);
    g += &t;
    g += &p;
    g += &s1;
    g += &s2;
    g += &c1;
    g += &c2;
    g.visiter(affichageDistant);*/
}