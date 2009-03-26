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
Chromosom::Chromosom() {
    inicjuj();
}

Chromosom::Chromosom(int dlugosc) {
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

/*
 * Operatrory
 */
std::ostream& operator<<(std::ostream& out, Chromosom& c) {
    //    std::copy(c.getChromosom().begin(), c.getChromosom().end(), ostream_iterator <
    //            Cegielka> (out, " "));

    BOOST_FOREACH(Cegielka cegielka, c.getChromosom()) {
        out << " " << cegielka;
    }

    return out;
}
