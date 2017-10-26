#include <catch.hpp>
#include <formes/groupe.h>
#include <formes/segment.h>
#include <formes/triangle.h>

TEST_CASE("Test ajout/suppression de formes dans groupe", "[GROUPE]") {
    Segment s(BLUE, Vecteur(0, 0), Vecteur(10, 10));
    {
        Groupe g(RED);

        REQUIRE(g.nombreFormes() == 0);

        s.setGroupe(&g);
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
    Groupe g(RED);
    Triangle t1(RED, Vecteur(0, 0), Vecteur(1, 0), Vecteur(0, 1));
    Triangle t2(RED, Vecteur(2, 2), Vecteur(3, 2), Vecteur(2, 3));
    REQUIRE(g.aire() == 0);

    t1.setGroupe(&g);
    REQUIRE(g.aire() == 0.5);

    t2.setGroupe(&g);
    REQUIRE(g.aire() == 1);
}