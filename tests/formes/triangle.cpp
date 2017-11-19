#include <catch.hpp>
#include <formes/triangle.h>

TEST_CASE("Test triangle", "[TRIANGLE]") {
    Triangle t("blue", Vecteur(0, 0), Vecteur(10, 0), Vecteur(10, 10));

    REQUIRE(t.p1() == Vecteur(0,0));
    REQUIRE(t.p2() == Vecteur(10,0));
    REQUIRE(t.p3() == Vecteur(10,10));
    REQUIRE(t.aire() == 50);

    Triangle t2(t);
    REQUIRE(t2.p1() == Vecteur(0,0));
    REQUIRE(t2.p2() == Vecteur(10,0));
    REQUIRE(t2.p3() == Vecteur(10,10));

    Triangle t3 = t;
    REQUIRE(t3.p1() == Vecteur(0,0));
    REQUIRE(t3.p2() == Vecteur(10,0));
    REQUIRE(t3.p3() == Vecteur(10,10));

    t.setP1(Vecteur(-10, -10));
    t.setP2(Vecteur(-10, -20));
    t.setP3(Vecteur(-20, -20));
    REQUIRE(t.p1() == Vecteur(-10, -10));
    REQUIRE(t.p2() == Vecteur(-10, -20));
    REQUIRE(t.p3() == Vecteur(-20, -20));
}