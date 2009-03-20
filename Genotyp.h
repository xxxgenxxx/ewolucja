/*
 * Genotyp.h
 *
 *  Created on: 2009-03-16
 *      Author: TMG
 */

#ifndef GENOTYP_H_
#define GENOTYP_H_

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "Cegielka.h"
#include "IOperator.h"

using namespace std;

/*
 * TRZEBA PRZEROBIC
 */
class Genotyp: public IOperator <const Cegielka&> {
    public:
        //        Genotyp(int dlugosc);

        void Inicjuj();
        void Inicjuj2(); // metoda testowa

        int poczatek() const;
        int koniec() const;
        const Cegielka& odczytaj(int element) const;
        void zapisz(int element, const Cegielka& wartosc);

    private:
        int dlugosc;
        vector <Cegielka> cegielka;
};

/*
 * Metody
 */
inline int Genotyp::poczatek() const {
    return 0;
}

inline int Genotyp::koniec() const {
    return cegielka.size();
}

inline const Cegielka& Genotyp::odczytaj(int element) const {
    return cegielka.at(element);
}

inline void Genotyp::zapisz(int element, const Cegielka& wartosc) {
    cegielka.at(element) = wartosc;
}

#endif /* GENOTYP_H_ */
