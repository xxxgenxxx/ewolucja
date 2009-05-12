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

class Chromosom: public IOperator <Cegielka&> {
    public:
        Chromosom();
        Chromosom(int dlugosc);

        // implementacja metod interfejsu IOperator <const Cegielka&>
        int poczatek() const;
        int koniec() const;
        Cegielka& odczytaj(int element);
        void zapisz(int element, Cegielka& wartosc);

        const std::vector <Cegielka>& getChromosom() const;
        double fitness();
        bool isElita() const;
        void setElita(bool e);
        int fenotypX1() ;
        int fenotypX2();

        // operatory strumieni
        friend std::ostream& operator<<(std::ostream& out, Chromosom& c);
        friend std::ostream& operator<<(std::ofstream& out, Chromosom& c);

    private:
        // inicjalizacja chromosomu
        void inicjuj(int dlugosc = 10);

        // obliczanie wartosci fenotypu dla podanego chromosomu
        int fenotyp(const std::vector <Cegielka>& chr) const;

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

inline Cegielka& Chromosom::odczytaj(int element) {
    return chromosom.at(element);
}

inline void Chromosom::zapisz(int element, Cegielka& wartosc) {
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
