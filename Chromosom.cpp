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
Chromosom::Chromosom() :
    elita(false) {
    inicjuj();
}

Chromosom::Chromosom(int dlugosc) :
    elita(false) {
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

double Chromosom::fenotyp(const std::vector <Cegielka>& chr) const {
    double wynik = 0;
    int dziesietny = 0;
    int wykladnik = 0;

    // obliczanie wartosci dziesietnej z wektora binarnego
    BOOST_REVERSE_FOREACH(Cegielka cegielka, chr) {
        BOOST_REVERSE_FOREACH(int gen, cegielka.getCegielka()) {
            dziesietny += gen * pow(2.0, wykladnik);
            ++wykladnik;
        }
    }

    wynik = -10 + dziesietny * (20 / (std::pow(2.0, 25) - 1));
    return wynik;
}

double Chromosom::fenotypX1() {
    std::vector <Cegielka> x1;

    // skopiowanie 5 pierwszych cegielek do wektora x1
    for (unsigned int i = 0; i < chromosom.size() / 2; ++i) {
        x1.push_back(chromosom.at(i));
    }

    return fenotyp(x1);
}

double Chromosom::fenotypX2() {
    std::vector <Cegielka> x2;

    // skopiowanie 5 ostatnich cegielek do wektora x2
    for (unsigned int i = chromosom.size() / 2; i < chromosom.size(); ++i) {
        x2.push_back(chromosom.at(i));
    }

    return fenotyp(x2);
}

double Chromosom::fitness() {
    double x1 = fenotypX1();
    double x2 = fenotypX2();

        // pierwsza czesc iloczynu
        double w1;
        w1 = std::pow(x1, 2.0) + std::pow(x2, 2.0);
        w1 = std::pow(w1, 0.25);

        // druga czesc iloczynu (w nawiasie kwadratowym)
        double w2;
        w2 = std::pow(x1, 2.0) + std::pow(x2, 2.0);
        w2 = 50 * std::pow(w2, 0.1);
        w2 = std::sin(w2);
        w2 = std::pow(w2, 2.0) + 1.0;

        return w1 * w2;
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
