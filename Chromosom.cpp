/*
 * Chromosom.cpp
 *
 *  Created on: 2009-03-16
 *      Author: TMG
 */

#include "Chromosom.h"

using namespace std;

/*
 * Konstruktory
 */
Chromosom::Chromosom() : elita(false) {
    inicjuj();
}

Chromosom::Chromosom(int dlugosc)  : elita(false) {
    inicjuj(dlugosc);
}

/*
 * Metody
 */
void Chromosom::inicjuj(int dlugosc) {
    for (int i = 0; i < dlugosc; ++i) {
        Cegielka c;
        chromosom.push_back(c);
    }
}

long long Chromosom::fenotyp() const {
    long long wynik = 0;
    int wykladnik = 0;

    BOOST_REVERSE_FOREACH(Cegielka cegielka, chromosom) {
           BOOST_REVERSE_FOREACH(int gen, cegielka.getCegielka()) {
                wynik += gen * pow(2.0, wykladnik);
                ++wykladnik;
         }
   }

    return wynik;
}

void Chromosom::fenotypXy() {
    int X1=0, X2=0;
    int wykladnikX1 = 0;
    int wykladnikX2 = 0;
    int dl,h=0;
    dl = chromosom.size();

    //Chromosom składa się z 10 cegiełek
    //5 pierwszych cegiełek licząć od prawej to X1
    //pozostałe 5 cegiełek to X2
    //geny(bity) są liczone od prawej.
    BOOST_REVERSE_FOREACH(Cegielka cegielka, chromosom) {
        if (h <dl/2){
               BOOST_REVERSE_FOREACH(int gen, cegielka.getCegielka()) {
                X1 += gen * pow(2.0, wykladnikX1);
                ++wykladnikX1;
            }
             h++;

         }

         else
         {

               BOOST_REVERSE_FOREACH(int gen, cegielka.getCegielka()) {
                X2 += gen * pow(2.0, wykladnikX2);
                ++wykladnikX2;
               }
             h++;

         }
    }

//    cout <<"x1: " <<X1 <<"   x2: " <<X2 <<endl;
    wynikX1=X1;
    wynikX2=X2;

}

long long Chromosom::fitenss()
{
    fenotypXy();
    long long wynik = 0;
    wynik =wynikX1+wynikX2;

    return wynik;
}


/*
 * Operatrory
 */
std::ostream& operator<<(std::ostream& out, Chromosom& c) {
    BOOST_FOREACH(Cegielka cegielka, c.getChromosom()) {
        out << " " << cegielka;
    }

    return out;
}

std::ostream& operator<<(std::ofstream& out, Chromosom& c) {
    BOOST_FOREACH(Cegielka cegielka, c.getChromosom()) {
        out << " " << cegielka;
    }

    return out;
}
