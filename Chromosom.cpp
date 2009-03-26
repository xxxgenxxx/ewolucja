/*
 * Chromosom.cpp
 *
 *  Created on: 2009-03-16
 *      Author: TMG
 */

#include "Chromosom.h"

using namespace std;

/*
 * Konstruktor
 */
Chromosom::Chromosom() {
    for (int i = 0; i < 10; ++i) {
            Cegielka c;
            chromosom.push_back(c);
        }
}

/*
 * Metody
 */


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
