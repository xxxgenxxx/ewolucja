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

using namespace std;

int main() {

    srand((unsigned) time(0));
    Cegielka c(5);
    Cegielka c2(5);

    std::cout << "cegielka 1\n" << c << std::endl;
    std::cout << "\ncegielka 2\n" << c2 << std::endl;

    // krzyzuje dwupunktowo cegielki zawierajace inty
    // i wymienia miedzy nimi geny od 1 do 3
    krzyzuj <Cegielka, int> (c, c2, 1, 3);

    // krzyzuje jednopunktowo cegielki zawierajace inty
    // i wymienia miedzy nimi geny od 2 do konca
//    krzyzuj <Cegielka, int> (c, c2, 2);

    std::cout << std::endl;
    for (int i = c2.poczatek(); i < c.koniec(); ++i) {
        std::cout << " " << c.odczytaj(i);
    }
    std::cout << std::endl;

    for (int i = c2.poczatek(); i < c2.koniec(); ++i) {
        std::cout << " " << c2.odczytaj(i);
    }
    std::cout << std::endl;

//        Chromosom g1;
//        g1.Inicjuj();
//
//        Chromosom g2;
//        g2.Inicjuj();
//
//        krzyzuj<Chromosom, Cegielka>(g1, g2, 3);

    return 0;
}
