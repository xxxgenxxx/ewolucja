/*
 * Mutacja.cpp
 *
 *  Created on: 2009-04-04
 *      Author: TMG
 */

#include "Mutacja.h"

/*
 * Odwrocenie losowej cegielki
 */
void mutacja(Chromosom& chromosom, int nrCegielki) {
    Cegielka cegielka = chromosom.odczytaj(nrCegielki);
    cegielka.odwroc();
    chromosom.zapisz(nrCegielki, cegielka);
}

/*
 * Zamiana dwoch cegielek miejscami
 */
void mutacja(Chromosom& chromosom, int nrCegielki1, int nrCegielki2) {
    Cegielka cegielka = chromosom.odczytaj(nrCegielki2);
    chromosom.zapisz(nrCegielki2, chromosom.odczytaj(nrCegielki1));
    chromosom.zapisz(nrCegielki1, cegielka);
}

/*
 * Mutacja pojedynczych genow w zaleznosci od prawdopodobienstwa
 */
void mutacja(Chromosom& chromosom, double pstwo) {

    for (int i = 0; i < chromosom.koniec(); ++i) {
        for (int j = 0; j < chromosom.odczytaj(i).koniec(); ++j) {

            // losujemy liczbe z zakresu 0-9 i porownujemy z
            // prawdopodobienstwem przeksztalconym do liczby calkowitej
            double random = rand() % 10;
            if (random <= pstwo * 10) {
                if (chromosom.odczytaj(i).odczytaj(j) == 0) {
                    chromosom.odczytaj(i).zapisz(j, 1);
                } else {
                    chromosom.odczytaj(i).zapisz(j, 1);
                }
            }
        }
    }
}
