/*
 * Cegielka.h
 *
 *  Created on: 2009-03-16
 *      Author: TMG
 */

#ifndef CEGIELKA_H_
#define CEGIELKA_H_

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <boost/foreach.hpp>

#include "IOperator.h"

class Cegielka: public IOperator <int> {
    public:
        Cegielka();
        Cegielka(int dlugosc);

        // Implementacja metod interfejsu IOperator <int>
        int poczatek() const;
        int koniec() const;
        int odczytaj(int element);
        void zapisz(int element, int wartosc);

        const std::vector <int>& getCegielka() const;
        void odwroc();

        // operatory
        int operator == (const Cegielka& right) const;
        int operator < (const Cegielka& right) const;
        friend std::ostream& operator << (std::ostream& out, Cegielka& c);
        friend std::ostream& operator << (std::ofstream& out, Cegielka& c);

    private:
        void inicjuj(int dlugosc = 5);
        int wartosc(const std::vector<int>& cegielka) const;

        std::vector <int> cegielka;
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

inline int Cegielka::odczytaj(int element) {
    return cegielka.at(element);
}

inline void Cegielka::zapisz(int element, int wartosc) {
    cegielka.at(element) = wartosc;
}

inline const std::vector <int>& Cegielka::getCegielka() const {
    return cegielka;
}

inline void Cegielka::odwroc() {
    std::reverse(cegielka.begin(), cegielka.end());
}

inline int Cegielka::operator == (const Cegielka& right) const {
    return std::equal(cegielka.begin(), cegielka.end(), right.getCegielka().begin());
}

inline int Cegielka::operator < (const Cegielka& right) const {
    return wartosc(cegielka) < wartosc(right.getCegielka());
}

#endif /* CEGIELKA_H_ */
