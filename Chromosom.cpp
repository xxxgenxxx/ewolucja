/*
 * Chromosom.cpp
 *
 *  Created on: 2009-03-16
 *      Author: TMG
 */

#include "Chromosom.h"

using namespace std;

/*
 * Konstruktory
 */
Chromosom::Chromosom() : elita(false) {
    inicjuj();
}

Chromosom::Chromosom(int dlugosc)  : elita(false) {
    inicjuj(dlugosc);
}

/*
 * Metody
 */
void Chromosom::inicjuj(int dlugosc) {
    for (int i = 0; i < dlugosc; ++i) {
        Cegielka c;
        chromosom.push_back(c);
    }
}

long Chromosom::fenotyp() const {
    long wynik = 0;
    int wykladnik = 0;

    BOOST_REVERSE_FOREACH(Cegielka cegielka, chromosom) {
        BOOST_REVERSE_FOREACH(int gen, cegielka.getCegielka()) {
            wynik += gen * pow(2, wykladnik);
            ++wykladnik;
        }
    }

    return wynik;
}

/*
 * Operatrory
 */
std::ostream& operator<<(std::ostream& out, Chromosom& c) {
    BOOST_FOREACH(Cegielka cegielka, c.getChromosom()) {
        out << " " << cegielka;
    }

    return out;
}

std::ostream& operator<<(std::ofstream& out, Chromosom& c) {
    BOOST_FOREACH(Cegielka cegielka, c.getChromosom()) {
        out << " " << cegielka;
    }

    return out;
}
