#include <catch.hpp>
#include <transformation/rotation.h>

TEST_CASE("Test rotation", "[HOMOTHETIE]") {
    Rotation r(Vecteur(0, 0), 0.5 * M_PI);

    Cercle c("red", Vecteur(10, 10), 10);
    Segment s("red", Vecteur(0, 0), Vecteur(10, 10));
    Triangle t("red", Vecteur(0, 0), Vecteur(10, 10), Vecteur(10, 0));
    Polygone p("red");
    p.ajouter(Vecteur(0,0));

    Cercle* c2 = (Cercle*) c.modifierNouveau(r);
    Segment* s2 = (Segment*) s.modifierNouveau(r);
    Triangle* t2 = (Triangle*) t.modifierNouveau(r);
    Polygone* p2 = (Polygone*) p.modifierNouveau(r);

    REQUIRE(c2->centre() == Vecteur(-10, 10));
    REQUIRE(c2->rayon() == 10);
    REQUIRE(s2->debut() == Vecteur(0, 0));
    REQUIRE(s2->fin() == Vecteur(-10, 10));
    REQUIRE(t2->p1() == Vecteur(0, 0));
    REQUIRE(t2->p2() == Vecteur(-10, 10));
    REQUIRE(t2->p3() == Vecteur(0, 10));
    REQUIRE((*p2)[0] == Vecteur(0, 0));
    
    c.modifier(r);
    s.modifier(r);
    t.modifier(r);
    p.modifier(r);

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
    Cercle c("red", Vecteur(0, 0), 10);

    c.modifier(r);

    REQUIRE(c.centre() == Vecteur(20, 20));
}