#include <catch.hpp>
#include <formes/triangle.h>

TEST_CASE("Test triangle", "[TRIANGLE]") {
    Triangle t(BLUE, Vecteur(0, 0), Vecteur(10, 0), Vecteur(10, 10));

    REQUIRE(t.p1() == Vecteur(0,0));
    REQUIRE(t.p2() == Vecteur(10,0));
    REQUIRE(t.p3() == Vecteur(10,10));

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

TEST_CASE("Tests egalite triangles", "[TRIANGLES]") {
    Triangle egaux[6] = {
            Triangle(BLUE, Vecteur(0, 0), Vecteur(10, 0), Vecteur(10, 10)),
            Triangle(BLUE, Vecteur(0, 0), Vecteur(10, 10), Vecteur(10, 0)),
            Triangle(BLUE, Vecteur(10, 0), Vecteur(0, 0), Vecteur(10, 10)),
            Triangle(BLUE, Vecteur(10, 0), Vecteur(10, 10), Vecteur(0, 0)),
            Triangle(BLUE, Vecteur(10, 10), Vecteur(0, 0), Vecteur(10, 0)),
            Triangle(BLUE, Vecteur(10, 10), Vecteur(10, 0), Vecteur(0, 0)),
    };

    for(int i = 0; i < 6; i++) {
        for(int j = i; j < 6; j++) {
            REQUIRE(egaux[i] == egaux[j]);
        }
    }

    Triangle t1(BLUE, Vecteur(0, 0), Vecteur(10, 0), Vecteur(10, 10));
    Triangle t2(RED, Vecteur(0, 0), Vecteur(10, 0), Vecteur(10, 10));

    REQUIRE(t1 != t2);

    t2.setCouleur(BLUE);
    t2.setP1(Vecteur(10, 10));
    REQUIRE(t1 != t2);

    t2.setP1(Vecteur(0, 0));
    t2.setP2(Vecteur(-1, -1));
    REQUIRE(t1 != t2);

    t2.setP2(Vecteur(10, 0));
    t2.setP3(Vecteur(-1, -1));
    REQUIRE(t1 != t2);
}