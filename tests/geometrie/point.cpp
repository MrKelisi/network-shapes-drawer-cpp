#include <geometrie/point.h>
#include <geometrie/vecteur.h>
#include "catch.hpp"

TEST_CASE("Tests point", "[POINT]") {
    Point p1(10, 5);
    REQUIRE(p1.x() == 10);
    REQUIRE(p1.y() == 5);

    p1.setX(5);
    p1.setY(10);
    REQUIRE(p1.x() == 5);
    REQUIRE(p1.y() == 10);

    p1 = Point(100, 100);
    REQUIRE(p1.x() == 100);
    REQUIRE(p1.y() == 100);

    Point p2(p1);
    REQUIRE(p2.x() == 100);
    REQUIRE(p2.y() == 100);

    Point p3 = p1 + p2;
    REQUIRE(p3.x() == 200);
    REQUIRE(p3.y() == 200);

    p3 += p1;
    REQUIRE(p3.x() == 300);
    REQUIRE(p3.y() == 300);

    p3 = p3 + 1;
    REQUIRE(p3.x() == 301);
    REQUIRE(p3.y() == 301);

    p3 += 1;
    REQUIRE(p3.x() == 302);
    REQUIRE(p3.y() == 302);

    p3 = p3 - p1;
    REQUIRE(p3.x() == 202);
    REQUIRE(p3.y() == 202);

    p3 -= p1;
    REQUIRE(p3.x() == 102);
    REQUIRE(p3.y() == 102);

    p3 = p3 - 1;
    REQUIRE(p3.x() == 101);
    REQUIRE(p3.y() == 101);

    p3 -= 1;
    REQUIRE(p3.x() == 100);
    REQUIRE(p3.y() == 100);

    p3 = -p3;
    REQUIRE(p3.x() == -100);
    REQUIRE(p3.y() == -100);

    Vecteur v1(Point(100, 100));
    p3 = p3 + v1;

    REQUIRE(p3.x() == 0);
    REQUIRE(p3.y() == 0);

    p3 += v1;
    REQUIRE(p3.x() == 100);
    REQUIRE(p3.y() == 100);

    p3 = p3 - v1;
    REQUIRE(p3.x() == 0);
    REQUIRE(p3.y() == 0);

    p3 -= v1;
    REQUIRE(p3.x() == -100);
    REQUIRE(p3.y() == -100);

    REQUIRE(p1 == p2);
    REQUIRE(p1 != p3);

    p2.setX(-100);
    REQUIRE(p1 != p2);

    p2 = Point(100, 200);
    REQUIRE(p1 != p2);

    REQUIRE(((std::string) p1) == "Point(100; 100)");

    //Test precision
    p1 = Point(0, 0);
    p2 = Point(0.000000001, 0.000000001);
    REQUIRE(p1 == p2);
}

TEST_CASE("Tests transformations point", "[POINT]") {
    Point p1(0, 0);
    p1 = p1.translate(Vecteur(Point(100, 100)));

    REQUIRE(p1.x() == 100);
    REQUIRE(p1.y() == 100);
}