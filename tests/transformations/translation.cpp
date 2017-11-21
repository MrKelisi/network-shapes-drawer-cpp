#include <catch.hpp>
#include <transformation/translation.h>
#include <formes/groupe.h>

TEST_CASE("Test translation groupe", "[TRANSLATION]") {
    Translation translation(Vecteur(0, 10));

    Cercle c("red", Vecteur(0, 0), 10);
    Segment s("red", Vecteur(0, 0), Vecteur(10, 10));
    Triangle t("red", Vecteur(0, 0), Vecteur(10, 10), Vecteur(10, 0));
    Polygone p("red");
    p.ajouter(Vecteur(0,0));

    Cercle* c2 = (Cercle*) c.modifierNouveau(translation);
    Segment* s2 = (Segment*) s.modifierNouveau(translation);
    Triangle* t2 = (Triangle*) t.modifierNouveau(translation);
    Polygone* p2 = (Polygone*) p.modifierNouveau(translation);
    
    REQUIRE(c2->centre() == Vecteur(0, 10));
    REQUIRE(s2->debut() == Vecteur(0, 10));
    REQUIRE(s2->fin() == Vecteur(10, 20));
    REQUIRE(t2->p1() == Vecteur(0, 10));
    REQUIRE(t2->p2() == Vecteur(10, 20));
    REQUIRE(t2->p3() == Vecteur(10, 10));
    REQUIRE((*p2)[0] == Vecteur(0, 10));
    
    Groupe g("red");
    g += &c;
    g += &s;
    g += &t;
    g += &p;

    g.modifier(translation);

    REQUIRE(c.centre() == Vecteur(0, 10));
    REQUIRE(s.debut() == Vecteur(0, 10));
    REQUIRE(s.fin() == Vecteur(10, 20));
    REQUIRE(t.p1() == Vecteur(0, 10));
    REQUIRE(t.p2() == Vecteur(10, 20));
    REQUIRE(t.p3() == Vecteur(10, 10));
    REQUIRE(p[0] == Vecteur(0, 10));
}