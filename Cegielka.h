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

class Cegielka : public IOperator {
    public:
        Cegielka(int dlugosc);

        void Inicjuj();
        void Inicjuj2(); // metoda testowa

        int poczatek() const;
        int koniec() const;
        int odczytaj(int element) const;
        void zapisz(int element, int wartosc);

    private:
        int dlugosc;
        vector <int> cegielka;

};

#endif /* CEGIELKA_H_ */
