//============================================================================
// Name        : ewolucja.cpp
// Author      : Grupa TMG
// Version     :
// Copyright   : GPL
// Description : Prosty program z dziedziny algorytmów genetycznych
//============================================================================

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <boost/array.hpp>
#include <boost/foreach.hpp>

#include "Algorytm.h"
#include "Cegielka.h"
#include "Chromosom.h"
#include "Krzyzowanie.h"
#include "Mutacja.h"

using namespace std;

//=========== GLOWNA FUNKCJA PROGRAMU - MAIN ==============================
int main() {

    // Inicjalizacja generatora liczb losowych
    srand((unsigned) time(0));

    // liczba osobnikow w pokoleniu
    const int ilosc = 10;

    // start algorytmu
    Algorytm ewolucja(ilosc);
    ewolucja.wykonaj();


    /*
     * ***********************************************************************
     *
     * UWAGA!
     *
     * PONIZEJ JEST KOD TESTOWY -  NA RAZIE NIE USUWAC
     *
     * ************************************************************************
     */

//        Cegielka c(5);
//      Cegielka c2(5);
//
//        std::cout << "cegielka 1\n" << c << "\ncegielka 2\n" << c2 << std::endl;

    // krzyzuje dwupunktowo cegielki zawierajace inty
    // i wymienia miedzy nimi geny od 1 do 3
    //    krzyzuj <Cegielka, int> (c, c2, 1, 3);

    // krzyzuje jednopunktowo cegielki zawierajace inty
    // i wymienia miedzy nimi geny od 2 do konca
//        krzyzuj <Cegielka, int> (c, c2, 2);
//
//      std::cout << "\nPo krzyzowaniu\ncegielka 1\n" << c << "\ncegielka 2\n"
//            << c2 << std::endl;

//       Chromosom g1;
//        Chromosom g2;
//        std::cout << "\n\nchromosom 1\n" << g1 << "\nchromosom 2\n" << g2
//                << std::endl;

    //    krzyzuj <Chromosom, Cegielka> (g1, g2, 3);
    //    std::cout << "\nPo krzyzowaniu\nchromosom 1\n" << g1 << "\nchromosom 2\n"
    //            << g2 << std::endl;

//        mutacja(g1, 4);
//        std::cout << "\nMutacja 1 typu chromosomu 1\n" << g1 << std::endl;

    //    mutacja(g2, 0, 1);
    //    std::cout << "\nMutacja 2 typu chromosomu 2\n" << g2 << std::endl;

    // Losowanie typu operacji np krzyzowania lub mutacji
    // losuj(3) oznacza wylosuj jedna operacje z trzech dostepnych
    //    int wynik = losuj(3);
    //    std::cout << "\nLosowanie: " << wynik << std::endl;
    //std::cout << "\nFentotypX1 g1X1: " << g1.getFenotypX1() << std::endl;
    //  std::cout << "\nFentotypX2 g1X2: " << g1.getFenotypX2() << std::endl;
    //    std::cout << "\nFitnes g1: " << g1.fitenss() << std::endl;
    //        std::cout << "\nFitnes g2: " << g2.fitenss() << std::endl;

    return 0;
}
