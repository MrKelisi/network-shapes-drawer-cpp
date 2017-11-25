#include <affichage/affichagedistant.h>
#include <formes/triangle.h>
#include <formes/segment.h>
#include <formes/polygone.h>
#include <formes/cercle.h>
#include <formes/groupe.h>
#include <transformation/rotation.h>
#include <math.h>
#include <formes/sauveurforme.h>

int main(int argc, char** argv) {
    AffichageDistant affichageDistant("127.0.0.1", 1952);
    SauveurForme sauveurForme("test_export.txt");
    //sauveurForme.vider();

    Triangle t("green", Vecteur(110,0), Vecteur(60, 100), Vecteur(160, 100));

    Polygone p("cyan");
    p.ajouter(Vecteur(105, 0));
    p.ajouter(Vecteur(115, 0));
    p.ajouter(Vecteur(115, 10));
    p.ajouter(Vecteur(105, 10));

    Segment s1("black", Vecteur(60, 100), Vecteur(60, 200));
    Segment s2("yellow", Vecteur(160, 100), Vecteur(160, 200));

    Cercle c1("red", Vecteur(60, 250), 50);
    Cercle c2("blue", Vecteur(160, 250), 50);

    /*
    t.visiter(affichageDistant);
    s1.visiter(affichageDistant);
    s2.visiter(affichageDistant);
    c1.visiter(affichageDistant);
    c2.visiter(affichageDistant);
    p.visiter(affichageDistant);
     */

    /*
    t.visiter(sauveurForme);
    s1.visiter(sauveurForme);
    s2.visiter(sauveurForme);
    c1.visiter(sauveurForme);
    c2.visiter(sauveurForme);
    p.visiter(sauveurForme);
     */

    Forme ** FORMES = new Forme * [20];
    int nb_formes = sauveurForme.charger(FORMES);

    for(int i = 0; i < nb_formes; i++)
        FORMES[i]->visiter(affichageDistant); // Afficher la i-eme forme stockée dans le fichier


    for(int i = 0; i < nb_formes; i++)
        delete FORMES[i];
    delete [] FORMES;
}