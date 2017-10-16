#include <catch.hpp>
#include <formes/groupe.h>
#include <formes/segment.h>

TEST_CASE("Test ajout/suppression de formes dans groupe", "[GROUPE]") {
    Segment s(BLUE, Vecteur(0, 0), Vecteur(10, 10));
    {
        Groupe g;

        REQUIRE(g.nombreFormes() == 0);

        s.setGroupe(&g);
        REQUIRE(s.groupe() == &g);
        REQUIRE(g.nombreFormes() == 1);
        REQUIRE(g.forme(0) == &s);
        REQUIRE(g[0] == &s);

        s.setGroupe(nullptr);
        REQUIRE(s.groupe() == nullptr);
        REQUIRE(g.nombreFormes() == 0);

        g += &s;
        REQUIRE(s.groupe() == &g);
        REQUIRE(g.nombreFormes() == 1);
        REQUIRE(g.forme(0) == &s);
        REQUIRE(g[0] == &s);

        g -= &s;
        REQUIRE(s.groupe() == nullptr);
        REQUIRE(g.nombreFormes() == 0);

        g += &s;
    }

    REQUIRE(s.groupe() == nullptr);
}