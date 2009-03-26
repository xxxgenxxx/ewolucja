/*
 * Chromosom.h
 *
 *  Created on: 2009-03-16
 *      Author: TMG
 */

#ifndef CHROMOSOM_H_
#define CHROMOSOM_H_

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
class Chromosom: public IOperator <const Cegielka&> {
    public:
        //        Genotyp(int dlugosc);

        void Inicjuj();

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
inline int Chromosom::poczatek() const {
    return 0;
}

inline int Chromosom::koniec() const {
    return cegielka.size();
}

inline const Cegielka& Chromosom::odczytaj(int element) const {
    return cegielka.at(element);
}

inline void Chromosom::zapisz(int element, const Cegielka& wartosc) {
    cegielka.at(element) = wartosc;
}

#endif /* CHROMOSOM_H_ */
