/*
 * Chromosom.h
 *
 *  Created on: 2009-03-16
 *      Author: TMG
 */

#ifndef CHROMOSOM_H_
#define CHROMOSOM_H_

#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
#include <boost/foreach.hpp>

#include "Cegielka.h"
#include "IOperator.h"

class Chromosom: public IOperator <const Cegielka&> {
    public:
        Chromosom();
        Chromosom(int dlugosc);

        // implementacja metod interfejsu IOperator <const Cegielka&>
        int poczatek() const;
        int koniec() const;
        const Cegielka& odczytaj(int element) const;
        void zapisz(int element, const Cegielka& wartosc);

        const std::vector <Cegielka>& getChromosom() const;
        double fitness();
        bool isElita() const;
        void setElita(bool e);

        // operatory strumieni
        friend std::ostream& operator<<(std::ostream& out, Chromosom& c);
        friend std::ostream& operator<<(std::ofstream& out, Chromosom& c);

    private:
        // inicjalizacja chromosomu
        void inicjuj(int dlugosc = 10);

        // obliczanie wartosci fenotypu dla zmiennych x1 i x2
        // x1 - 5 pierwszych cegielek
        // x2 - 5 ostatnich cegielek
        int fenotyp(const std::vector <Cegielka>& chr) const;
        int fenotypX1() ;
        int fenotypX2();

        std::vector <Cegielka> chromosom;
        bool elita;
};

/*
 * Metody
 */
inline int Chromosom::poczatek() const {
    return 0;
}

inline int Chromosom::koniec() const {
    return chromosom.size();
}

inline const Cegielka& Chromosom::odczytaj(int element) const {
    return chromosom.at(element);
}

inline void Chromosom::zapisz(int element, const Cegielka& wartosc) {
    chromosom.at(element) = wartosc;
}

inline const std::vector <Cegielka>& Chromosom::getChromosom() const {
    return chromosom;
}

inline bool Chromosom::isElita() const {
    if (elita) {
        return true;
    } else {
        return false;
    }
}

inline void Chromosom::setElita(bool e) {
    elita = e;
}

#endif /* CHROMOSOM_H_ */
