#include <stdexcept>
#include <couleur.h>
#include "affichagedistant.h"
#include <formes/cercle.h>
#include <formes/polygone.h>
#include <formes/segment.h>
#include <formes/triangle.h>
#include <formes/groupe.h>

AffichageDistant::AffichageDistant(const char* serveur, unsigned short port) {
    struct hostent *hostinfo = NULL;
    SOCKADDR_IN sin = { 0 };
    _socket = socket(AF_INET, SOCK_STREAM, 0);
    if(_socket == INVALID_SOCKET) {
        throw std::runtime_error("Socket"); //TODO: exception
    }

    hostinfo = gethostbyname(serveur);
    if (hostinfo == NULL) {
        throw std::runtime_error("Unknown host");
    }

    sin.sin_addr = *(IN_ADDR *) hostinfo->h_addr;
    sin.sin_port = htons(port);
    sin.sin_family = AF_INET;

    if(connect(_socket,(SOCKADDR *) &sin, sizeof(SOCKADDR)) == SOCKET_ERROR) {
        throw std::runtime_error("Connect");
    }
}

AffichageDistant::~AffichageDistant() {
    close(_socket);
}

void AffichageDistant::envoyer(const std::string& data) const {
    if(send(_socket, data.c_str(), data.size(), 0) < 0) {
        throw std::runtime_error("Send");
    }
}

void AffichageDistant::visiter(const Cercle* cercle) const {
    std::string data = "CERCLE\n";

    data += visiterForme(cercle);

    data += "origine=";
    data += visiterVecteur(cercle->centre());
    data += "\n";

    data += "rayon=";
    data += std::to_string(cercle->rayon());
    data += '\n';

    data += "FIN\n";

    envoyer(data);
}

void AffichageDistant::visiter(const Polygone* polygone) const {
    std::string data = "POLYGONE\n";

    data += visiterForme(polygone);

    for(unsigned long i = 0; i < polygone->nombrePoints(); i++) {
        data += "point=";
        data += visiterVecteur(polygone->point(i));
        data += '\n';
    }

    data += "FIN\n";
    envoyer(data);
}

void AffichageDistant::visiter(const Segment* segment) const {
    std::string data = "SEGMENT\n";

    data += visiterForme(segment);

    data += "debut=";
    data += visiterVecteur(segment->debut());
    data += "\n";

    data += "fin=";
    data += visiterVecteur(segment->fin());
    data += "\n";

    data += "FIN\n";
    envoyer(data);
}

void AffichageDistant::visiter(const Triangle* triangle) const {

}

void AffichageDistant::visiter(const Groupe* groupe) const {

}

std::string AffichageDistant::visiterForme(const Forme* forme) const {
    std::string data;

    data += "couleur=";
    data += getChaineCouleur(forme->couleurAffichee());
    data += '\n';

    return data;
}

std::string AffichageDistant::visiterVecteur(const Vecteur& vecteur) const {
    return std::to_string(vecteur.x()) + ";" + std::to_string(vecteur.y());
}
