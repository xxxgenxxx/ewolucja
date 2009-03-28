//============================================================================
// Name        : ewolucja.cpp
// Author      : Grupa TMG
// Version     :
// Copyright   : GPL
// Description : Prosty program z dziedziny algorytmów genetycznych
//============================================================================

#include <cstdlib>
#include <iostream>
#include "Cegielka.h"
#include "Chromosom.h"
#include "Krzyzowanie.h"
#include "Losowanie.h"

using namespace std;

int main() {

    // Inicjalizacja generatora liczb losowych
    srand((unsigned) time(0));

    Cegielka c(5);
    Cegielka c2(5);

    std::cout << "cegielka 1\n" << c << "\ncegielka 2\n" << c2 << std::endl;

    // krzyzuje dwupunktowo cegielki zawierajace inty
    // i wymienia miedzy nimi geny od 1 do 3
    krzyzuj <Cegielka, int> (c, c2, 1, 3);

    // krzyzuje jednopunktowo cegielki zawierajace inty
    // i wymienia miedzy nimi geny od 2 do konca
    //    krzyzuj <Cegielka, int> (c, c2, 2);

    std::cout << "\nPo krzyzowaniu\ncegielka 1\n" << c << "\ncegielka 2\n"
            << c2 << std::endl;

    Chromosom g1;
    Chromosom g2;
    std::cout << "\n\nchromosom 1\n" << g1 << "\nchromosom 2\n" << g2
            << std::endl;

    krzyzuj <Chromosom, Cegielka> (g1, g2, 3);
    std::cout << "\nPo krzyzowaniu\nchromosom 1\n" << g1 << "\nchromosom 2\n"
            << g2 << std::endl;

    // Losowanie typu operacji np krzyzowania lub mutacji
    // losuj(3) oznacza wylosuj jedna operacje z trzech dostepnych
    int wynik = losuj(3);
    std::cout << "\nLosowanie: " << wynik << std::endl;

    std::cout << "\nFentotyp g1: "<< g1.fenotyp() << std::endl;
    std::cout << "\nFentotyp g2: "<< g2.fenotyp() << std::endl;

    return 0;
}
