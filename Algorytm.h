/*
 * Algorytm.h
 *
 *  Created on: 2009-04-19
 *      Author: TMG
 */

#ifndef ALGORYTM_H_
#define ALGORYTM_H_

#include <algorithm>
#include <cassert>
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
typedef std::pair <Chromosom, Chromosom> Para;

class Algorytm {
    public:
        Algorytm(int ilosc);
        virtual ~Algorytm();

        void wykonaj();

    private:
        // glowne metody algorytmu
        void losujPopulacje();
        void przeniesElite();
        void selekcjaTurniejowa();
        void podzialNaPary();
        void krzyzowanie();
        void mutowanie();

        // metody pomocnicze
        int losuj(int zakres);
        double srednia();
        void wyswietlPopulacje();
        void dopelnijNowaPopulacje();
        void usunChromosom(unsigned int indeks);

        // komparatory
        static bool sortCmp(Chromosom i, Chromosom j);
        static bool fitnessCmp(Chromosom i, Chromosom j);

        const int iloscOsobnikow;
        const int iloscElity;

        // obiekty populacji
        Populacja populacja;
        Populacja populacjaBezElity;
        Populacja nowePokolenie;
        std::vector <Para> listaPar;

        // obiekt do zapisu do plikow
        Pliki plik;
};

#endif /* ALGORYTM_H_ */
