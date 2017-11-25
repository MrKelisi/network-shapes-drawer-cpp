cmake_minimum_required(VERSION 3.9)
project(martin_cpp)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory("tests")

include_directories("${CMAKE_SOURCE_DIR}")

set(SOURCE_FILES main.cpp formes/forme.cpp formes/forme.h geometrie/vecteur.cpp geometrie/vecteur.h couleur.h formes/segment.cpp formes/segment.h formes/cercle.cpp formes/cercle.h formes/triangle.cpp formes/triangle.h formes/polygone.cpp formes/polygone.h transformation/transformation.h formes/groupe.cpp formes/groupe.h transformation/translation.cpp transformation/translation.h transformation/homothetie.h transformation/homothetie.cpp transformation/rotation.cpp transformation/rotation.h formes/visiteurforme.h formes/modificateurforme.h affichage/clientreseau.cpp affichage/clientreseau.h affichage/affichagedistant.cpp affichage/affichagedistant.h exceptions/GroupeException.h exceptions/socketexception.h formes/modificateurforme.cpp formes/sauveurforme.cpp formes/sauveurforme.h chargerDonnees/ChargerDonnees.h chargerDonnees/ChargerDonneesCOR.cpp chargerDonnees/ChargerDonneesCOR.h chargerDonnees/ChargerDonneesCercle.cpp chargerDonnees/ChargerDonneesCercle.h chargerDonnees/ChargerDonneesSegment.cpp chargerDonnees/ChargerDonneesSegment.h chargerDonnees/ChargerDonneesTriangle.cpp chargerDonnees/ChargerDonneesTriangle.h chargerDonnees/ChargerDonneesPolygone.cpp chargerDonnees/ChargerDonneesPolygone.h)
add_library(libmartin_cpp ${SOURCE_FILES} exceptions/argumentexception.h)
add_executable(martin_cpp ${SOURCE_FILES})

if(WIN32)
    target_link_libraries(libmartin_cpp wsock32 ws2_32)
    target_link_libraries(martin_cpp wsock32 ws2_32)
endif()