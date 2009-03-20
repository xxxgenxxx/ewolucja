/*
 * Krzyzowanie.h
 *
 *  Created on: 2009-03-20
 *      Author: Maciej Libuda
 */

#ifndef KRZYZOWANIE_H_
#define KRZYZOWANIE_H_

#include <iostream>
#include "IOperator.h"

void krzyzuj(IOperator& osobnik1, IOperator& osobnik2, int punktCiecia1) {

    int pojemnik1;
    int pojemnik2;

    for (int i = osobnik1.poczatek(); i < osobnik1.koniec(); ++i) {
        if (i >= punktCiecia1) {
            pojemnik1 = osobnik1.odczytaj(i);
            pojemnik2 = osobnik2.odczytaj(i);

            osobnik1.zapisz(i, pojemnik2);
            osobnik2.zapisz(i, pojemnik1);
        }
    }
}

#endif /* KRZYZOWANIE_H_ */
