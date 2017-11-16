#include <catch.hpp>
#include <formes/cercle.h>
#include <const.h>

TEST_CASE("Test cercle", "[CERCLE]") {
    Cercle c("blue", Vecteur(0, 0), 10.5);

    REQUIRE(c.centre() == Vecteur(0, 0));
    REQUIRE(c.rayon() == 10.5);
    REQUIRE(c.couleur() == std::string("blue"));
    REQUIRE(std::abs(c.aire() - 346.360590058) < PRECISION);

    Cercle c2(c);
    REQUIRE(c2.centre() == Vecteur(0, 0));
    REQUIRE(c2.rayon() == 10.5);
    REQUIRE(c.couleur() == std::string("blue"));

    Cercle c3 = c;
    REQUIRE(c3.centre() == Vecteur(0, 0));
    REQUIRE(c3.rayon() == 10.5);
    REQUIRE(c.couleur() == std::string("blue"));

    c.setCentre(Vecteur(-50, 50));
    c.setCouleur("red");
    c.setRayon(0.5);

    REQUIRE(c.centre() == Vecteur(-50, 50));
    REQUIRE(c.rayon() == 0.5);
    REQUIRE(c.couleur() == std::string("red"));
    REQUIRE(std::abs(c.aire() - 0.785398163397) < PRECISION);
}

TEST_CASE("Test egalite cercles", "[CERCLES]") {
    Cercle c[4] = {
        Cercle("blue", Vecteur(0, 0), 10),
        Cercle("red", Vecteur(0, 0), 10),
        Cercle("blue", Vecteur(10, 10), 10),
        Cercle("blue", Vecteur(0, 0), 0),
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