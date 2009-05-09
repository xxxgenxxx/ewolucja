/*
 * Pliki.cpp
 *
 *  Created on: 2009-05-09
 *      Author: Maciej Libuda
 */

#include "Pliki.h"

/*
 * Konstruktor
 */
Pliki::Pliki() :
    agRun("AGrun.txt"), agBest("Best.txt"), agBlocks("Blocks.txt"), separator("     ") {

    naglowekRun();

}

/*
 * Destruktor
 */
Pliki::~Pliki() {
    agRun.close();
    agBest.close();
    agBlocks.close();
}

/*
 * Metody
 */
void Pliki::naglowekRun() {
    agRun << "Numer generacji" << separator << "Najczęstsze rozwiązania" << std::endl;
}

void Pliki::setNrGeneracji(int nr) {
    nrGeneracji = nr;
}
