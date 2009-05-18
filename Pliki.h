/*
 * Pliki.h
 *
 *  Created on: 2009-05-09
 *      Author: TMG
 */

#ifndef PLIKI_H_
#define PLIKI_H_

#include <fstream>
#include <iomanip>
#include <string>

#include "Chromosom.h"

class Pliki {
    public:
        Pliki();
        virtual ~Pliki();

        // zapis pojedycznego wiersza do pliku
        void wierszRun(int nr, Chromosom& chr, double avg);
        void wierszBest(int nr, Chromosom& chr);
        void wierszBlocks(int nr, Chromosom& elita1, Chromosom& elita2);

    private:
        // naglowki plikow
        void naglowekRun();
        void naglowekBest();

        // obiekty plikow
        std::ofstream agRun;
        std::ofstream agBest;
        std::ofstream agBlocks;

        const std::string separator;
};

#endif /* PLIKI_H_ */
