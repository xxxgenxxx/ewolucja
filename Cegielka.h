/*
 * Cegielka.h
 *
 *  Created on: 2009-03-16
 *      Author: TMG
 */

#ifndef CEGIELKA_H_
#define CEGIELKA_H_

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>

#include "IOperator.h"

class Cegielka: public IOperator <int> {
    public:
        Cegielka();
        Cegielka(int dlugosc);


        // Implementacja metod interfejsu IOperator <int>
        int poczatek() const;
        int koniec() const;
        int odczytaj(int element) const;
        void zapisz(int element, int wartosc);

        // pozostale metody
        const std::vector<int>& getCegielka() const;
        void print();

        // operator strumienia wyjsciowego
        friend std::ostream& operator<<(std::ostream& out, Cegielka& c);

    private:
        int dlugosc;
        std::vector <int> cegielka;

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

inline const std::vector<int>& Cegielka::getCegielka() const {
    return cegielka;
}

#endif /* CEGIELKA_H_ */
