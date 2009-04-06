/*
 * Cegielka.cpp
 *
 *  Created on: 2009-03-16
 *      Author: TMG
 */

#include "Cegielka.h"

using namespace std;

/*
 * Konstruktory
 */
Cegielka::Cegielka() {
    inicjuj();
}

Cegielka::Cegielka(int dlugosc) {
    inicjuj(dlugosc);
}

/*
 * Metody
 */
void Cegielka::inicjuj(int dlugosc) {
    for (int i = 0; i < dlugosc; ++i) {
        int random_integer = (rand() % 2);
        cegielka.push_back(random_integer);
    }
}

void Cegielka::odwroc() {
    std::reverse(cegielka.begin(), cegielka.end());
}

/*
 * Operatrory
 */
std::ostream& operator<<(std::ostream& out, Cegielka& c) {
    std::copy(c.getCegielka().begin(), c.getCegielka().end(), ostream_iterator <
            int> (out, " "));
    return out;
}

std::ostream& operator<<(std::ofstream& out, Cegielka& c) {
    std::copy(c.getCegielka().begin(), c.getCegielka().end(), ostream_iterator <
            int> (out, " "));
    return out;
}
