/*
 * Algorytm.h
 *
 *  Created on: 2009-04-19
 *      Author: Maciej Libuda
 */

#ifndef ALGORYTM_H_
#define ALGORYTM_H_

#include <iostream>
#include <vector>

#include "Chromosom.h"

class Algorytm {
    public:
        Algorytm(int ilosc);
        virtual ~Algorytm();

        void wykonaj();

    private:
        void losujPopulacje();
        void wyswietlPopulacje();
        void obliczFitness();

        const int iloscOsobnikow;
        typedef std::vector <Chromosom> Populacja;

        Populacja populacja;
        Populacja nowePokolenie;
        std::vector <double> fitnessOsobnikow;
};

#endif /* ALGORYTM_H_ */
