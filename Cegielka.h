/*
 * Cegielka.h
 *
 *  Created on: 2009-03-16
 *      Author: TMG
 */

#ifndef CEGIELKA_H_
#define CEGIELKA_H_

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "IOperator.h"

using namespace std;

class Cegielka: public IOperator <int> {
    public:
        Cegielka();
        Cegielka(int dlugosc);

        int poczatek() const;
        int koniec() const;
        int odczytaj(int element) const;
        void zapisz(int element, int wartosc);

    private:
        int dlugosc;
        vector <int> cegielka;

        void inicjuj();
};

/*
 * Metody
 */
inline int Cegielka::poczatek() const {
    return 0;
}

inline int Cegielka::koniec() const {
    return cegielka.size();
}

inline int Cegielka::odczytaj(int element) const {
    return cegielka.at(element);
}

inline void Cegielka::zapisz(int element, int wartosc) {
    cegielka.at(element) = wartosc;
}

#endif /* CEGIELKA_H_ */
