/*
 * Cegielka.cpp
 *
 *  Created on: 2009-03-16
 *      Author: TMG
 */

#include "Cegielka.h"

/*
 * Konstruktor
 */
Cegielka::Cegielka(int dlugosc) : dlugosc(dlugosc) {
}

/*
 * Metody
 */
void Cegielka::Inicjuj() {
    //losowanie genow

    cout << "nasza cegielka" << endl;;
    //  vector<int>::iterator rit;
    // for ( rit=cegielka.begin() ; rit < cegielka.end(); ++rit )
    // cout << " " << *rit;

    srand((unsigned) time(0));
    int random_integer;
    for (int index = 0; index < 5; index++) {
        random_integer = (rand() % 2);
        cegielka.push_back(random_integer);
        // cout << random_integer << endl;
    }

    vector <int>::iterator rit;
    for (rit = cegielka.begin(); rit < cegielka.end(); ++rit)
        cout << " " << *rit;

}
