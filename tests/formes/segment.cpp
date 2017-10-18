#include <catch.hpp>
#include <formes/segment.h>

TEST_CASE("Test segment", "[SEGMENT]") {
    Segment s1(RED, Vecteur(0,0), Vecteur(10, 10));
    Segment s2(s1);

    REQUIRE(s1 == s2);
    s2.setCouleur(BLUE);
    REQUIRE(s1 != s2);
    s2 = s1;
    REQUIRE(s1 == s2);

    REQUIRE(s1.debut() == Vecteur(0, 0));
    REQUIRE(s1.fin() == Vecteur(10, 10));

    s1.setDebut(s2.fin());
    s1.setFin(s2.debut());
    REQUIRE(s1.fin() == Vecteur(0, 0));
    REQUIRE(s1.debut() == Vecteur(10, 10));
}
