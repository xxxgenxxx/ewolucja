//============================================================================
// Name        : ewolucja.cpp
// Author      : Grupa TMG
// Version     :
// Copyright   : GPL
// Description : Prosty program z dziedziny algorytmów genetycznych
//============================================================================

#include <iostream>
#include "Cegielka.h"
#include "Krzyzowanie.h"

using namespace std;

int main() {

    Cegielka c(5);
    c.Inicjuj();

    Cegielka c2(5);
    c2.Inicjuj2();

    std::cout << std::endl;

    krzyzuj(c, c2, 1);

    std::cout << std::endl;
    for (int i = c2.poczatek(); i < c.koniec(); ++i) {
        std::cout << " " << c.odczytaj(i);
    }
    std::cout << std::endl;

    for (int i = c2.poczatek(); i < c2.koniec(); ++i) {
        std::cout << " " << c2.odczytaj(i);
    }
    std::cout << std::endl;

    return 0;
}
