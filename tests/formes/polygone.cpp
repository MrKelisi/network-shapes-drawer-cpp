#include <catch.hpp>
#include <formes/polygone.h>

TEST_CASE("Tests polygone", "[POLYGONE]") {
    Polygone p1(BLUE);
    Polygone p2(RED);

    REQUIRE(p1 != p2);

    p1.setCouleur(RED);
    REQUIRE(p1 == p2);
    REQUIRE(p1.nombrePoints() == 0);

    p1.ajouter(Vecteur(10, 10));
    REQUIRE(p1.nombrePoints() == 1);
    REQUIRE(p1.point(0) == Vecteur(10, 10));
    REQUIRE(p1[0] == Vecteur(10, 10));
    REQUIRE(p1 != p2);

    p2 += Vecteur(10, 10);
    REQUIRE(p2.nombrePoints() == 1);
    REQUIRE(p2.point(0) == Vecteur(10, 10));
    REQUIRE(p1 == p2);

    Polygone p3(p2);
    REQUIRE(p3.nombrePoints() == 1);
    REQUIRE(p3.point(0) == Vecteur(10, 10));

    Polygone p4 = p3;
    REQUIRE(p4.nombrePoints() == 1);
    REQUIRE(p4.point(0) == Vecteur(10, 10));
}