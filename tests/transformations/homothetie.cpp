#include <catch.hpp>
#include <transformation/translation.h>
#include <transformation/homothetie.h>

TEST_CASE("Test transformations", "[HOMOTHETIE]") {
    Homothetie h(Vecteur(0, 0), 2);

    Cercle c("red", Vecteur(10, 10), 10);
    Segment s("red", Vecteur(0, 0), Vecteur(10, 10));
    Triangle t("red", Vecteur(0, 0), Vecteur(10, 10), Vecteur(10, 0));
    Polygone p("red");
    p.ajouter(Vecteur(0,0));

    c.modifier(h);
    s.modifier(h);
    t.modifier(h);
    p.modifier(h);

    REQUIRE(c.centre() == Vecteur(20, 20));
    REQUIRE(c.rayon() == 20);
    REQUIRE(s.debut() == Vecteur(0, 0));
    REQUIRE(s.fin() == Vecteur(20, 20));
    REQUIRE(t.p1() == Vecteur(0, 0));
    REQUIRE(t.p2() == Vecteur(20, 20));
    REQUIRE(t.p3() == Vecteur(20, 0));
    REQUIRE(p[0] == Vecteur(0, 0));
}