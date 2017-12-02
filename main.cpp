#include <affichage/affichagedistant.h>
#include <formes/triangle.h>
#include <formes/segment.h>
#include <formes/polygone.h>
#include <formes/cercle.h>
#include <formes/groupe.h>
#include <transformation/rotation.h>
#include <math.h>
#include <sauvegarde/sauveurforme.h>
#include <transformation/homothetie.h>
#include <sauvegarde/chargeurforme.h>

int main(int argc, char** argv) {
    AffichageDistant affichageDistant("127.0.0.1", 1952);

    Triangle t("green", Vecteur(110,0), Vecteur(60, 100), Vecteur(160, 100));

    Polygone p("orange");
    p.ajouter(Vecteur(105, 0));
    p.ajouter(Vecteur(115, 0));
    p.ajouter(Vecteur(115, 10));
    p.ajouter(Vecteur(105, 10));

    Segment s1("black", Vecteur(60, 100), Vecteur(60, 200));
    Segment s2("yellow", Vecteur(160, 100), Vecteur(160, 200));

    Cercle c1("red", Vecteur(60, 250), 50);
    Cercle c2("blue", Vecteur(160, 250), 50);


    Groupe g("red");
    c1.setGroupe(&g);
    c2.setGroupe(&g);


    /* === PARTIE TEST EXPORT === */

    SauveurForme sauveurForme("test_export.txt");
    sauveurForme.vider();

    t.visiter(sauveurForme);
    s1.visiter(sauveurForme);
    s2.visiter(sauveurForme);
    p.visiter(sauveurForme);
    c1.visiter(sauveurForme);
    c2.visiter(sauveurForme);
    g.visiter(sauveurForme);


    /* === PARTIE TEST IMPORT === */

    ChargeurForme c("test_export.txt");
    std::vector<Forme*> formes = c.formes();

    for(Forme* forme : formes) {
        forme->visiter(affichageDistant);
    }

}