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
#include <ctime>
#include <boost/array.hpp>
#include <boost/foreach.hpp>
#include <boost/random.hpp>
#include <sys/time.h>

#include "Algorytm.h"
#include "Cegielka.h"
#include "Chromosom.h"
#include "Krzyzowanie.h"
#include "Mutacja.h"

int main(int argc, char **argv) {

    timeval tv;
    gettimeofday(&tv, 0);
    srand(tv.tv_sec + tv.tv_usec);

    // liczba osobnikow w pokoleniu
    const int iloscOsobnikow = 100;

    // liczba generacji (domyslnie 10)
    int liczbaGeneracji = 500;

    if (argc == 2) {
        liczbaGeneracji = atoi(argv[1]);
    }

    // start algorytmu
    Algorytm ewolucja(liczbaGeneracji, iloscOsobnikow);
    ewolucja.wykonaj();

    return 0;
}
