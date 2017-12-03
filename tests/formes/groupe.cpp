#include <catch.hpp>
#include <formes/groupe.h>
#include <formes/segment.h>
#include <formes/triangle.h>
#include <formes/cercle.h>
#include <exceptions/GroupeException.h>
#include <formes/polygone.h>

TEST_CASE("Test ajout/suppression de formes dans groupe", "[GROUPE]") {
    Segment s("blue", Vecteur(0, 0), Vecteur(10, 10));
    {
        Groupe g("red");

        REQUIRE(g.nombreFormes() == 0);

        s.setGroupe(&g);
        std::cout << g << std::endl;
        REQUIRE(s.groupe() == &g);
        REQUIRE(g.nombreFormes() == 1);
        REQUIRE(g.forme(0) == &s);
        REQUIRE(g[0] == &s);

        s.setGroupe(nullptr);
        REQUIRE(s.groupe() == nullptr);
        REQUIRE(g.nombreFormes() == 0);

        g += &s;
        REQUIRE(s.groupe() == &g);
        REQUIRE(g.nombreFormes() == 1);
        REQUIRE(g.forme(0) == &s);
        REQUIRE(g[0] == &s);

        g -= &s;
        REQUIRE(s.groupe() == nullptr);
        REQUIRE(g.nombreFormes() == 0);

        g += &s;
    }

    REQUIRE(s.groupe() == nullptr);
}

TEST_CASE("Test aire groupe", "[GROUPE]") {
    Groupe g("red");
    Triangle t1("red", Vecteur(0, 0), Vecteur(1, 0), Vecteur(0, 1));
    Triangle t2("red", Vecteur(2, 2), Vecteur(3, 2), Vecteur(2, 3));
    REQUIRE(g.aire() == 0);

    t1.setGroupe(&g);
    REQUIRE(g.aire() == 0.5);

    t2.setGroupe(&g);
    REQUIRE(g.aire() == 1);
}

TEST_CASE("Test cycle groupe", "[GROUPE]") {
    Groupe g1("red");
    Groupe g2("red");

    g1.setGroupe(&g2);

    try {
        g2.setGroupe(&g1);
        FAIL("Exception non levée");
    }
    catch(GroupeException exception) {

    }
}

TEST_CASE("Test clone groupe", "[GROUPE]") {
    Groupe g1("red");
    Segment s("blue", Vecteur(0, 0), Vecteur(10, 10));
    Triangle t("red", Vecteur(0, 0), Vecteur(1, 0), Vecteur(0, 1));

    s.setGroupe(&g1);
    t.setGroupe(&g1);

    Groupe* g2 = (Groupe*) g1.clone();

    REQUIRE(s.groupe() == &g1);
    REQUIRE(t.groupe() == &g1);

    for(unsigned long i = 0; i < g2->nombreFormes(); i++) {
        REQUIRE(g2->forme(i)->groupe() == g2);
    }
}

TEST_CASE("Test operateur egal groupe", "[GROUPE]") {
    Groupe g1("red");
    Segment s("blue", Vecteur(0, 0), Vecteur(10, 10));
    Triangle t("red", Vecteur(0, 0), Vecteur(1, 0), Vecteur(0, 1));

    s.setGroupe(&g1);
    t.setGroupe(&g1);

    Groupe* g2 = (Groupe*) g1.clone();

    for(unsigned long i = 0; i < g1.nombreFormes(); i++) {
        REQUIRE(g1.forme(i)->groupe() == &g1);
    }

    for(unsigned long i = 0; i < g2->nombreFormes(); i++) {
        REQUIRE(g2->forme(i)->groupe() == g2);
    }
}

TEST_CASE("Test operateur egal formes", "[GROUPE]") {
    Groupe g("red");
    Segment s("blue", Vecteur(0, 0), Vecteur(10, 10));
    Triangle t("red", Vecteur(0, 0), Vecteur(1, 0), Vecteur(0, 1));
    Cercle c("red", Vecteur(250, 250), 50);
    Polygone p("orange");

    g += &s;
    g += &t;
    g += &c;
    g += &p;

    Segment s2(s);
    REQUIRE(s2.groupe() == &g);
    REQUIRE(g.nombreFormes() == 5);

    Triangle t2(t);
    REQUIRE(t2.groupe() == &g);
    REQUIRE(g.nombreFormes() == 6);

    Cercle c2(c);
    REQUIRE(c2.groupe() == &g);
    REQUIRE(g.nombreFormes() == 7);

    Polygone p2(p);
    REQUIRE(p2.groupe() == &g);
    REQUIRE(g.nombreFormes() == 8);

    Segment s3("blue", Vecteur(0, 0), Vecteur(10, 10));
    Triangle t3("red", Vecteur(0, 0), Vecteur(1, 0), Vecteur(0, 1));
    Cercle c3("red", Vecteur(250, 250), 50);
    Polygone p3("orange");

    s3 = s;
    REQUIRE(s3.groupe() == &g);
    REQUIRE(g.nombreFormes() == 9);

    t3 = t;
    REQUIRE(t3.groupe() == &g);
    REQUIRE(g.nombreFormes() == 10);

    c3 = c;
    REQUIRE(c3.groupe() == &g);
    REQUIRE(g.nombreFormes() == 11);

    p3 = p;
    REQUIRE(p3.groupe() == &g);
    REQUIRE(g.nombreFormes() == 12);
}