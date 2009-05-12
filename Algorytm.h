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
#include <iomanip>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

#include "Chromosom.h"
#include "Krzyzowanie.h"
#include "Mutacja.h"
#include "Pliki.h"

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
        void dopelnijNowaPopulacje();
        double srednia(const Fitness& fitness);
        int indeksNalepszego();

        const int iloscOsobnikow;
        const int iloscElity;

        Populacja populacja;
        Populacja populacjaBezElity;
        Populacja nowePokolenie;
        Fitness fitnessOsobnikow;
        std::vector <std::pair <Chromosom, Chromosom> > listaPar;

        Pliki plik;
};

#endif /* ALGORYTM_H_ */
