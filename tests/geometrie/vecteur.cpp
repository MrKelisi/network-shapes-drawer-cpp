#include <geometrie/vecteur.h>
#include <const.h>
#include "catch.hpp"

TEST_CASE("Test vecteurs", "[VECTEUR]") {
    Vecteur v1(Point(100, 100));
    Vecteur v2(Point(10, 10), Point(100, 100));

    REQUIRE(v1.destination() == Point(100, 100));
    REQUIRE(v2.destination() == Point(90, 90));

    v1.setDestination(Point(10, 10), Point(100, 100));
    v2.setDestination(Point(100, 100));

    REQUIRE(v1.destination() == Point(90, 90));
    REQUIRE(v2.destination() == Point(100, 100));

    REQUIRE(std::abs(v1.norme() - 127.279220614) < PRECISION);
    REQUIRE(std::abs(v2.norme() - 141.421356237) < PRECISION);

    Vecteur v3(v1);
    REQUIRE(v3.destination() == Point(90, 90));

    v3 = v2;
    REQUIRE(v3.destination() == Point(100, 100));

    v3 = v3 + v2;
    REQUIRE(v3.destination() == Point(200, 200));

    v3 += v2;
    REQUIRE(v3.destination() == Point(300, 300));

    v3 = v3 - v2;
    REQUIRE(v3.destination() == Point(200, 200));

    v3 -= v2;
    REQUIRE(v3.destination() == Point(100, 100));

    v3 = v3 * 2;
    REQUIRE(v3.destination() == Point(200, 200));

    v3 *= 2;
    REQUIRE(v3.destination() == Point(400, 400));

    v3 = -v3;
    REQUIRE(v3.destination() == Point(-400, -400));

    v2 = v1;
    REQUIRE(v1 != v3);
    REQUIRE(v1 == v2);

    //Test precision
    v2 *= 1.00000000001;
    REQUIRE(v1 == v2);
}