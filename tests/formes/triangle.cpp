#include <catch.hpp>
#include <formes/triangle.h>

TEST_CASE("Test triangle", "[TRIANGLE]") {
    Triangle t(BLUE, Point(0, 0), Point(10, 0), Point(10, 10));

    REQUIRE(t.p1() == Point(0,0));
    REQUIRE(t.p2() == Point(10,0));
    REQUIRE(t.p3() == Point(10,10));

    Triangle t2(t);
    REQUIRE(t2.p1() == Point(0,0));
    REQUIRE(t2.p2() == Point(10,0));
    REQUIRE(t2.p3() == Point(10,10));

    Triangle t3 = t;
    REQUIRE(t3.p1() == Point(0,0));
    REQUIRE(t3.p2() == Point(10,0));
    REQUIRE(t3.p3() == Point(10,10));

    t.setP1(Point(-10, -10));
    t.setP2(Point(-10, -20));
    t.setP3(Point(-20, -20));
    REQUIRE(t.p1() == Point(-10, -10));
    REQUIRE(t.p2() == Point(-10, -20));
    REQUIRE(t.p3() == Point(-20, -20));
}

TEST_CASE("Tests egalite triangles", "[TRIANGLES]") {
    Triangle egaux[6] = {
            Triangle(BLUE, Point(0, 0), Point(10, 0), Point(10, 10)),
            Triangle(BLUE, Point(0, 0), Point(10, 10), Point(10, 0)),
            Triangle(BLUE, Point(10, 0), Point(0, 0), Point(10, 10)),
            Triangle(BLUE, Point(10, 0), Point(10, 10), Point(0, 0)),
            Triangle(BLUE, Point(10, 10), Point(0, 0), Point(10, 0)),
            Triangle(BLUE, Point(10, 10), Point(10, 0), Point(0, 0)),
    };

    for(int i = 0; i < 6; i++) {
        for(int j = i; j < 6; j++) {
            REQUIRE(egaux[i] == egaux[j]);
        }
    }

    Triangle t1(BLUE, Point(0, 0), Point(10, 0), Point(10, 10));
    Triangle t2(RED, Point(0, 0), Point(10, 0), Point(10, 10));

    REQUIRE(t1 != t2);

    t2.setCouleur(BLUE);
    t2.setP1(Point(10, 10));
    REQUIRE(t1 != t2);

    t2.setP1(Point(0, 0));
    t2.setP2(Point(-1, -1));
    REQUIRE(t1 != t2);

    t2.setP2(Point(10, 0));
    t2.setP3(Point(-1, -1));
    REQUIRE(t1 != t2);
}