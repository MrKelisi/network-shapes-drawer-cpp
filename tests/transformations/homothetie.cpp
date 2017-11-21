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

    Cercle* c2 = (Cercle*) c.modifierNouveau(h);
    Segment* s2 = (Segment*) s.modifierNouveau(h);
    Triangle* t2 = (Triangle*) t.modifierNouveau(h);
    Polygone* p2 = (Polygone*) p.modifierNouveau(h);
    REQUIRE(c2->centre() == Vecteur(20, 20));
    REQUIRE(c2->rayon() == 20);
    REQUIRE(s2->debut() == Vecteur(0, 0));
    REQUIRE(s2->fin() == Vecteur(20, 20));
    REQUIRE(t2->p1() == Vecteur(0, 0));
    REQUIRE(t2->p2() == Vecteur(20, 20));
    REQUIRE(t2->p3() == Vecteur(20, 0));
    REQUIRE((*p2)[0] == Vecteur(0, 0));

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