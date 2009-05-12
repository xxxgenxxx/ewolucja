/*
 * Krzyzowanie.h
 *
 *  Created on: 2009-03-20
 *      Author: TMG
 */

#ifndef KRZYZOWANIE_H_
#define KRZYZOWANIE_H_

#include <climits>

/*
 * Algorytm krzyzowania dwoch osobnikow
 *
 * obejmuje wersje krzyzowania jedno i dwupunktowego
 */
template <typename T, typename E>
void krzyzuj(T& osobnik1, T& osobnik2, int punktCiecia1, int punktCiecia2 =
        INT_MAX) {

    E pojemnik1;
    E pojemnik2;

    for (int i = osobnik1.poczatek(); i < osobnik1.koniec(); ++i) {
        if (i >= punktCiecia1 && i <= punktCiecia2) {
            pojemnik1 = osobnik1.odczytaj(i);
            pojemnik2 = osobnik2.odczytaj(i);

            osobnik1.zapisz(i, pojemnik2);
            osobnik2.zapisz(i, pojemnik1);
        }
    }
}

#endif /* KRZYZOWANIE_H_ */
