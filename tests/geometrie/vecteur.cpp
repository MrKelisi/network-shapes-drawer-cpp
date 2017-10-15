#include <geometrie/vecteur.h>
#include <const.h>
#include "catch.hpp"

TEST_CASE("Test vecteurs", "[VECTEUR]") {
    Vecteur v1(100, 100);
    Vecteur v2(100, 100);

    REQUIRE(v1 == Vecteur(100, 100));

    v1.setX(90);
    v1.setY(90);

    REQUIRE(v1 == Vecteur(90, 90));

    REQUIRE(std::abs(v1.norme() - 127.279220614) < PRECISION);
    REQUIRE(std::abs(v2.norme() - 141.421356237) < PRECISION);

    Vecteur v3(v1);
    REQUIRE(v3 == Vecteur(90, 90));

    v3 = v2;
    REQUIRE(v3 == Vecteur(100, 100));

    v3 = v3 + v2;
    REQUIRE(v3 == Vecteur(200, 200));

    v3 += v2;
    REQUIRE(v3 == Vecteur(300, 300));

    v3 = v3 - v2;
    REQUIRE(v3 == Vecteur(200, 200));

    v3 -= v2;
    REQUIRE(v3 == Vecteur(100, 100));

    v3 = v3 * 2;
    REQUIRE(v3 == Vecteur(200, 200));

    v3 *= 2;
    REQUIRE(v3 == Vecteur(400, 400));

    v3 = -v3;
    REQUIRE(v3 == Vecteur(-400, -400));

    v2 = v1;
    REQUIRE(v1 != v3);
    REQUIRE(v1 == v2);

    //Test precision
    v2 *= 1.00000000001;
    REQUIRE(v1 == v2);
}