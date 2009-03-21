/*
 * Chromosom.cpp
 *
 *  Created on: 2009-03-16
 *      Author: TMG
 */

#include "Chromosom.h"

/*
 * Metody
 */
void Chromosom::Inicjuj() {
    //losowanie genow

    cout << endl << "nasza cegielka" << endl;
    ;
    //  vector<int>::iterator rit;
    // for ( rit=cegielka.begin() ; rit < cegielka.end(); ++rit )
    // cout << " " << *rit;

    for (int i = 0; i < 10; ++i) {
        Cegielka c(5);
        cegielka.push_back(c);
    }

    //    vector <Cegielka>::iterator rit;
    //    for (rit = cegielka.begin(); rit < cegielka.end(); ++rit)
    //        cout << " " << *rit;

}
