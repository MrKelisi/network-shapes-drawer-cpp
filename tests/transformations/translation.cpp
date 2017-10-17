#include <catch.hpp>
#include <transformation/translation.h>
#include <formes/groupe.h>

TEST_CASE("Test translation groupe", "[TRANSLATION]") {
    Translation translation(Vecteur(0, 10));

    Cercle c(RED, Vecteur(0, 0), 10);
    Segment s(RED, Vecteur(0, 0), Vecteur(10, 10));
    Triangle t(RED, Vecteur(0, 0), Vecteur(10, 10), Vecteur(10, 0));
    Polygone p(RED);
    p.ajouter(Vecteur(0,0));

    Groupe g(RED);
    g += &c;
    g += &s;
    g += &t;
    g += &p;

    g.transformer(translation);

    REQUIRE(c.centre() == Vecteur(0, 10));
    REQUIRE(s.debut() == Vecteur(0, 10));
    REQUIRE(s.fin() == Vecteur(10, 20));
    REQUIRE(t.p1() == Vecteur(0, 10));
    REQUIRE(t.p2() == Vecteur(10, 20));
    REQUIRE(t.p3() == Vecteur(10, 10));
    REQUIRE(p[0] == Vecteur(0, 10));
}