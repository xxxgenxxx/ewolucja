/*
 * Cegielka.cpp
 *
 *  Created on: 2009-03-16
 *      Author: TMG
 */

#include "Cegielka.h"

/*
 * Konstruktor domyslny
 */
Cegielka::Cegielka() {

}

/*
 * Konstruktor sparametryzowany
 */
Cegielka::Cegielka(int dlugosc) :
    dlugosc(dlugosc) {
}

/*
 * Metody
 */
void Cegielka::Inicjuj() {
    //losowanie genow

    cout << endl << "nasza cegielka" << endl;
    ;
    //  vector<int>::iterator rit;
    // for ( rit=cegielka.begin() ; rit < cegielka.end(); ++rit )
    // cout << " " << *rit;

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

// METODA TYMCZASOWA
void Cegielka::Inicjuj2() {
    //losowanie genow

    cout << endl << "nasza cegielka" << endl;
    ;
    //  vector<int>::iterator rit;
    // for ( rit=cegielka.begin() ; rit < cegielka.end(); ++rit )
    // cout << " " << *rit;

    cegielka.push_back(0);
    cegielka.push_back(1);
    cegielka.push_back(0);
    cegielka.push_back(1);
    cegielka.push_back(0);

    vector <int>::iterator rit;
    for (rit = cegielka.begin(); rit < cegielka.end(); ++rit)
        cout << " " << *rit;

}
