#include <catch.hpp>
#include <transformation/rotation.h>

TEST_CASE("Test rotation", "[HOMOTHETIE]") {
    Rotation r(Vecteur(0, 0), 0.5 * M_PI);

    Cercle c(RED, Vecteur(10, 10), 10);
    Segment s(RED, Vecteur(0, 0), Vecteur(10, 10));
    Triangle t(RED, Vecteur(0, 0), Vecteur(10, 10), Vecteur(10, 0));
    Polygone p(RED);
    p.ajouter(Vecteur(0,0));

    c.transformer(r);
    s.transformer(r);
    t.transformer(r);
    p.transformer(r);

    REQUIRE(c.centre() == Vecteur(-10, 10));
    REQUIRE(c.rayon() == 10);
    REQUIRE(s.debut() == Vecteur(0, 0));
    REQUIRE(s.fin() == Vecteur(-10, 10));
    REQUIRE(t.p1() == Vecteur(0, 0));
    REQUIRE(t.p2() == Vecteur(-10, 10));
    REQUIRE(t.p3() == Vecteur(0, 10));
    REQUIRE(p[0] == Vecteur(0, 0));
}

TEST_CASE("Test rotation 2", "[ROTATION]") {
    Rotation r(Vecteur(10, 10), M_PI);
    Cercle c(RED, Vecteur(0, 0), 10);

    c.transformer(r);

    REQUIRE(c.centre() == Vecteur(20, 20));
}