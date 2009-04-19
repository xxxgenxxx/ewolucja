/*
 * Algorytm.cpp
 *
 *  Created on: 2009-04-19
 *      Author: Maciej Libuda
 */

#include "Algorytm.h"

/*
 * Konstruktor
 */
Algorytm::Algorytm(int ilosc) : iloscOsobnikow(ilosc) {
}

/*
 * Destruktor
 */
Algorytm::~Algorytm() {
}

/*
 * Metody
 */
void Algorytm::wykonaj() {
    losujPopulacje();
    wyswietlPopulacje();
}

void Algorytm::losujPopulacje() {
    for (int i = 0; i < iloscOsobnikow; ++i) {
        Chromosom chr;
        populacja.push_back(chr);
    }
}

void Algorytm::wyswietlPopulacje() {
    for (int i = 0; i < iloscOsobnikow; ++i) {
        std::cout << "Chromosom " << i + 1 << ": " << populacja.at(i) << " Fitness: " <<
        " Elita: " << populacja.at(i).isElita() << std::endl;
    }
}
