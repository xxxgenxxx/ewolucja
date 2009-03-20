/*
 * Cegielka.h
 *
 *  Created on: 2009-03-16
 *      Author: TMG
 */

#ifndef CEGIELKA_H_
#define CEGIELKA_H_

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "IOperator.h"

using namespace std;

class Cegielka : IOperator {
    public:
        Cegielka(int dlugosc);
        virtual ~Cegielka();

        void Inicjuj();

    private:
        int dlugosc;
        vector <int> cegielka;

};

/*
 * Destruktor
 */
inline Cegielka::~Cegielka() {
}

#endif /* CEGIELKA_H_ */
