/*
 * Cegielka.cpp
 *
 *  Created on: 2009-03-16
 *      Author: TMG
 */

#include "Cegielka.h"

using namespace std;

/*
 * Konstruktor domyslny
 */
Cegielka::Cegielka() {
    inicjuj();
}

/*
 * Konstruktor sparametryzowany
 */
Cegielka::Cegielka(int dlugosc) :
    dlugosc(dlugosc) {
    inicjuj();
}

/*
 * Metody
 */
void Cegielka::inicjuj() {
    int random_integer;
    for (int index = 0; index < 5; index++) {
        random_integer = (rand() % 2);
        cegielka.push_back(random_integer);
    }
}

void Cegielka::print() {
    cout << endl << "nasza cegielka" << endl;
    vector <int>::iterator rit;
    for (rit = cegielka.begin(); rit < cegielka.end(); ++rit)
        cout << " " << *rit;
}

/*
 * Operatrory
 */
std::ostream& operator<<(std::ostream& out, Cegielka& c) {
    std::copy(c.getCegielka().begin(), c.getCegielka().end(), ostream_iterator <
            int> (out, " "));
    return out;
}
