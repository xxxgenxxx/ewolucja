/*
 * Mutacja.cpp
 *
 *  Created on: 2009-04-04
 *      Author: Maciej Libuda
 */

#include "Mutacja.h"
#include <iostream>

void mutacja(Chromosom& chromosom, int nrCegielki) {
    Cegielka cegielka = chromosom.odczytaj(nrCegielki);
    cegielka.odwroc();
    chromosom.zapisz(nrCegielki, cegielka);
}

void mutacja(Chromosom& chromosom, int nrCegielki1, int nrCegielki2) {
    Cegielka cegielka = chromosom.odczytaj(nrCegielki2);
    chromosom.zapisz(nrCegielki2, chromosom.odczytaj(nrCegielki1));
    chromosom.zapisz(nrCegielki1, cegielka);
}

void mutacja(Chromosom& chromosom, double pstwo) {
    double random = (rand() % 100) / 100.0;

    // TODO zapytac sie o mutacje
    if (random <= pstwo) {
        std::cout << random << std::endl;
        std::cout << "mutuj" << std::endl;
    }
}
