#include <affichage/clientreseau.h>

int main(int argc, char** argv) {
    ClientReseau::instance().setServeur("127.0.0.1", 1952);
}