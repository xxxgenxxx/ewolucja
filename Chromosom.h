/*
 * Chromosom.h
 *
 *  Created on: 2009-03-16
 *      Author: TMG
 */

#ifndef CHROMOSOM_H_
#define CHROMOSOM_H_

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>

#include <boost/foreach.hpp>

#include "Cegielka.h"
#include "IOperator.h"

class Chromosom: public IOperator <const Cegielka&> {
    public:
        Chromosom();

        // implementacja metod interfejsu IOperator <const Cegielka&>
        int poczatek() const;
        int koniec() const;
        const Cegielka& odczytaj(int element) const;
        void zapisz(int element, const Cegielka& wartosc);

        const std::vector<Cegielka>& getChromosom() const;

        // operator strumienia wyjsciowego
        friend std::ostream& operator<<(std::ostream& out, Chromosom& c);

    private:
        int dlugosc;
        std::vector <Cegielka> chromosom;
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

inline const std::vector<Cegielka>& Chromosom::getChromosom() const {
    return chromosom;
}

#endif /* CHROMOSOM_H_ */
