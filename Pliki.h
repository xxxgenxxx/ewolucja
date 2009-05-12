/*
 * Pliki.h
 *
 *  Created on: 2009-05-09
 *      Author: Maciej Libuda
 */

#ifndef PLIKI_H_
#define PLIKI_H_

#include <fstream>
#include <iomanip>
//#include <iostream>
#include <string>

#include "Chromosom.h"

class Pliki {
    public:
        Pliki();
        virtual ~Pliki();

        void wierszRun(int nr, Chromosom& chr, double avg);
        void wierszBest(int nr, Chromosom& chr);
        void wierszBlocks();

    private:
        void naglowekRun();
        void naglowekBest();
        void naglowekBlocks();

        std::ofstream agRun;
        std::ofstream agBest;
        std::ofstream agBlocks;

        const std::string separator;
        int nrGeneracji;
};

#endif /* PLIKI_H_ */
