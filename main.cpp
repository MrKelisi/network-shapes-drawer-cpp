#include <affichage/affichagedistant.h>
#include <formes/triangle.h>
#include <formes/segment.h>
#include <formes/polygone.h>
#include <formes/cercle.h>
#include <formes/groupe.h>
#include <math.h>
#include <sauvegarde/sauveurforme.h>
#include <sauvegarde/chargeurforme.h>
#include <transformation/translation.h>
#include <transformation/rotation.h>
#include <transformation/homothetie.h>

#define NOM_FICHIER "majoliefigure2.txt"

int main(int argc, char** argv) {
    //Création formes et calcul d'aire

    Triangle t1("green", Vecteur(1, 0), Vecteur(4, -2), Vecteur(4, 2));

    Cercle c1("yellow", Vecteur(7, 0), 2);

    Polygone r1("blue");
    r1 += Vecteur(11, -1);
    r1 += Vecteur(15, -1);
    r1 += Vecteur(15, 1);
    r1 += Vecteur(11, 1);

    Cercle c2("yellow", Vecteur(17, 0), 1);

    Groupe g1("red");
    g1 += &t1;
    g1 += &c1;
    g1 += &r1;
    g1 += &c2;

    Translation translation(Vecteur(-4, 0));
    g1.modifier(translation);

    Rotation rotation(Vecteur(0, 0), M_PI/4);
    g1.modifier(rotation);

    std::cout << g1.aire() << std::endl;

    //Dessin g1

    Translation translationAffichage(Vecteur(10, 10));
    g1.modifier(translationAffichage);

    Homothetie homothetieAffichage(Vecteur(0, 0), 20);
    g1.modifier(homothetieAffichage);

    AffichageDistant affichage("127.0.0.1", 1952);
    g1.visiter(affichage);

    //Sauvegarde et chargement
    SauveurForme sauveurForme(NOM_FICHIER);
    sauveurForme.vider();
    g1.visiter(sauveurForme);

    ChargeurForme chargeurForme(NOM_FICHIER);
    std::vector<Forme*> formes = chargeurForme.formes();
    Groupe* g2 = (Groupe*) formes[0];

    //Affichage deuxième groupe
    g2->setCouleur("green");
    Translation translationAffichage2(Vecteur(300, 0));
    g2->modifier(translationAffichage2);
    g2->visiter(affichage);

    //Suppression des formes
    for(Forme* forme : formes) {
        delete forme;
    }
}