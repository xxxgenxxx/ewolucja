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

void Pliki::wierszBlocks(int nr, Chromosom& elita1, Chromosom& elita2) {
    std::vector <Cegielka> cegielki;

    // polaczenie cegielek z obu osobnikow elitarnych
    for (int i = 0; i < elita1.koniec(); ++i) {
        cegielki.push_back(elita1.odczytaj(i));
        cegielki.push_back(elita2.odczytaj(i));
    }

    // sortowanie cegielek wedlug wartosci
    std::sort(cegielki.begin(), cegielki.end());

    // usuniecie powtarzajacych sie cegielek
    std::vector <Cegielka> unikalne = cegielki;
    std::vector <Cegielka>::iterator iter = std::unique(unikalne.begin(), unikalne.end());
    unikalne.resize(iter - unikalne.begin());

    // zliczanie wystapien cegielek w osobnikach elitarnych i zapis do pliku
    agBlocks << "Generacja nr " << nr << std::endl;
    for (unsigned int i = 0; i < unikalne.size(); ++i) {
        int licznik = std::count(cegielki.begin(), cegielki.end(), unikalne.at(i));
        agBlocks << unikalne.at(i) << separator << "(" << licznik << ")" << std::endl;
    }
    agBlocks << std::endl;
}
