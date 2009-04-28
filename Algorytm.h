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
#include <list>
#include <utility>
#include <vector>

#include "Chromosom.h"
#include "Krzyzowanie.h"

typedef std::vector <Chromosom> Populacja;
typedef std::vector <double> Fitness;

class Algorytm {
    public:
        Algorytm(int ilosc);
        virtual ~Algorytm();

        void wykonaj();

    private:
        // glowne metody algorytmu
        void losujPopulacje();
        void obliczFitness();
        void przeniesElite();
        void selekcjaTurniejowa();
        void podzialNaPary();

        // metody pomocnicze
        int losuj(int zakres);
        void wyswietlPopulacje();
        void usunChromosom(unsigned int indeks);

        const int iloscOsobnikow;
        const int iloscElity;

        Populacja populacja;
        Populacja populacjaBezElity;
        Populacja nowePokolenie;
        Fitness fitnessOsobnikow;
        std::vector <std::pair <Chromosom, Chromosom> > listaPar;
};

#endif /* ALGORYTM_H_ */
