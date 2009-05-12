/*
 * Pliki.cpp
 *
 *  Created on: 2009-05-09
 *      Author: TMG
 */

#include "Pliki.h"

/*
 * Konstruktor
 */
Pliki::Pliki() :
    agRun("AGrun.txt"), agBest("Best.txt"), agBlocks("Blocks.txt"), separator(" | ") {

    naglowekRun();
    naglowekBest();
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
    agRun << std::setw(15) << "Nr generacji" << separator
    << std::setw(24) << "Najlepsze rozw" << separator
    << std::setw(12) << "Fitness" << separator
    << "Sr fitness" << std::endl;
}

void Pliki::wierszRun(int nr, Chromosom& chr, double avg) {
    agRun << std::setw(15) <<  nr << separator
    << " x1=" << std::setw(8) << chr.fenotypX1()
    << " x2=" << std::setw(8) << chr.fenotypX2()
    << separator << std::fixed << std::setprecision(6)
    << std::setw(12) << chr.fitness() << separator
    << avg << std::endl;
}

void Pliki::naglowekBest() {
    agBest << std::setw(15) << "Nr generacji" << separator
    << "Najlepszy osobnik" << std::endl;
}

void Pliki::wierszBest(int nr, Chromosom& chr) {
    agBest << std::setw(15) << nr << separator << chr << std::endl;
}
