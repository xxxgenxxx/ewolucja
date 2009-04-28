/*
 * Algorytm.h
 *
 *  Created on: 2009-04-19
 *      Author: Maciej Libuda
 */

#ifndef ALGORYTM_H_
#define ALGORYTM_H_

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>

#include "Chromosom.h"

typedef std::vector <Chromosom> Populacja;
typedef std::vector <double> Fitness;

class Algorytm {
    public:
        Algorytm(int ilosc);
        virtual ~Algorytm();

        void wykonaj();

    private:
        void losujPopulacje();
        void wyswietlPopulacje();
        void obliczFitness();
        int losuj(int zakres);
        void przeniesElite();
        void selekcjaTurniejowa();

        const int iloscOsobnikow;
        const int iloscElity;

        Populacja populacja;
        Populacja nowePokolenie;
        Fitness fitnessOsobnikow;

        int indeksElity1;
        int indeksElity2;
};

#endif /* ALGORYTM_H_ */
