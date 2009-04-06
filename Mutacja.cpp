/*
 * Mutacja.cpp
 *
 *  Created on: 2009-04-04
 *      Author: Maciej Libuda
 */

#include "Mutacja.h"

void mutacja(const Chromosom& chromosom, int nrCegielki) {
    Cegielka& cegielka = const_cast <Cegielka&> (chromosom.odczytaj(
            nrCegielki));
    cegielka.odwroc();
}

void mutacja(Chromosom& chromosom, int nrCegielki1, int nrCegielki2) {
    Cegielka tmp = chromosom.odczytaj(nrCegielki2);
    chromosom.zapisz(nrCegielki2, chromosom.odczytaj(nrCegielki1));
    chromosom.zapisz(nrCegielki1, tmp);
}

void mutacja(const Chromosom& chromosom, float pstwo) {

}
