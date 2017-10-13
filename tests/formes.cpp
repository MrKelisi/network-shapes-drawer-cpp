#include <catch.hpp>
#include <formes/cercle.h>

TEST_CASE("Test cercle", "[CERCLE]") {
    Cercle c(BLUE, Point(0, 0), 10.5);

    REQUIRE(c.centre() == Point(0, 0));
    REQUIRE(c.rayon() == 10.5);
    REQUIRE(c.couleur() == BLUE);

    Cercle c2(c);
    REQUIRE(c2.centre() == Point(0, 0));
    REQUIRE(c2.rayon() == 10.5);
    REQUIRE(c2.couleur() == BLUE);

    Cercle c3 = c;
    REQUIRE(c3.centre() == Point(0, 0));
    REQUIRE(c3.rayon() == 10.5);
    REQUIRE(c3.couleur() == BLUE);

    c.setCentre(Point(-50, 50));
    c.setCouleur(RED);
    c.setRayon(0.5);

    REQUIRE(c.centre() == Point(-50, 50));
    REQUIRE(c.rayon() == 0.5);
    REQUIRE(c.couleur() == RED);
}

TEST_CASE("Test egalite cercles", "[CERCLES]") {
    Cercle c[4] = {
        Cercle(BLUE, Point(0, 0), 10),
        Cercle(RED, Point(0, 0), 10),
        Cercle(BLUE, Point(10, 10), 10),
        Cercle(BLUE, Point(0, 0), 0),
    };

    for(int i = 0; i < 4; i++) {
        REQUIRE(c[i] == c[i]);
    }

    for(int i = 0; i < 4; i++) {
        for(int j = i + 1; j < 4; j++) {
            REQUIRE(c[i] != c[j]);
            REQUIRE(!(c[i] == c[j]));
        }
    }
}