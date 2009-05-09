/*
 * Pliki.h
 *
 *  Created on: 2009-05-09
 *      Author: Maciej Libuda
 */

#ifndef PLIKI_H_
#define PLIKI_H_

#include <fstream>
#include <string>

class Pliki {
    public:
        Pliki();
        virtual ~Pliki();

        void setNrGeneracji(int nr);

    private:
        void naglowekRun();
        void naglowekBest();
        void naglowekBlocks();

        void wierszRun();
        void wierszBest();
        void wierszBlocks();



        std::ofstream agRun;
        std::ofstream agBest;
        std::ofstream agBlocks;

        const std::string separator;
        int nrGeneracji;
};

#endif /* PLIKI_H_ */
