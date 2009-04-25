/*
 * Algorytm.cpp
 *
 *  Created on: 2009-04-19
 *      Author: Maciej Libuda
 */

#include "Algorytm.h"

/*
 * Konstruktor
 */
Algorytm::Algorytm(int ilosc) :
    iloscOsobnikow(ilosc), iloscElity(2) {
}

/*
 * Destruktor
 */
Algorytm::~Algorytm() {
}

/*
 * Metody
 */
void Algorytm::wykonaj() {
    losujPopulacje();
    obliczFitness();

    // TODO zapis do pliku

    // TODO tu zaczynac sie bedzie petla while
    przeniesElite();
    wyswietlPopulacje();

    selekcjaTurniejowa();

}

void Algorytm::losujPopulacje() {
    for (int i = 0; i < iloscOsobnikow; ++i) {
        Chromosom chr;
        populacja.push_back(chr);
    }
}

void Algorytm::wyswietlPopulacje() {
    for (int i = 0; i < iloscOsobnikow; ++i) {
        std::cout << "Chromosom " << i + 1 << ": " << populacja.at(i)
                << " Fitness: " << fitnessOsobnikow.at(i) << " Elita: "
                << populacja.at(i).isElita() << std::endl;
    }
}

void Algorytm::obliczFitness() {
    for (int i = 0; i < iloscOsobnikow; ++i) {
        fitnessOsobnikow.push_back(populacja.at(i).fitness());
    }
}

int Algorytm::losuj(int zakres) {
    return rand() % zakres;
}

void Algorytm::przeniesElite() {
    // znajdowanie fitnessu pierwszego elitarnego osobnika
    double elita1 = *std::max_element(fitnessOsobnikow.begin(),
            fitnessOsobnikow.end());
    int indeksElity1;

    for (unsigned int i = 0; i < fitnessOsobnikow.size(); ++i) {
        if (elita1 == fitnessOsobnikow.at(i)) {
            indeksElity1 = i;

            // tymczasowe zerowanie fitnessu elity1 aby znalezc finess elity2
            fitnessOsobnikow.at(i) = 0;
            break;
        }
    }

    // znajdowanie fitnessu drugiego elitarnego osobnika
    double elita2 = *std::max_element(fitnessOsobnikow.begin(),
            fitnessOsobnikow.end());
    int indeksElity2;

    for (unsigned int i = 0; i < fitnessOsobnikow.size(); ++i) {
        if (elita2 == fitnessOsobnikow.at(i)) {
            indeksElity2 = i;

            // przywrocenie wyzerowanego fitnessu elity1
            fitnessOsobnikow.at(indeksElity1) = elita1;
            break;
        }
    }

    // oznaczenie odpowiednich osobnikow w populacji jako elitarne
    populacja.at(indeksElity1).setElita(true);
    populacja.at(indeksElity2).setElita(true);

    // przeniesienie osobnikow elitarnych do nowego pokolenia
    nowePokolenie.push_back(populacja.at(indeksElity1));
    nowePokolenie.push_back(populacja.at(indeksElity2));

    // FIXME uzupelnianie nowego pokolenia smieciami
    // dla kompatybilnosci z kodem Tomka
    // poprawic to koniecznie bo ta petla to max zjebane rozwiazanie
    for (int i = 0; i < iloscOsobnikow - iloscElity; ++i) {
        Chromosom tmp;
        nowePokolenie.push_back(tmp);
    }
}

void Algorytm::selekcjaTurniejowa() {
    /*
     * Kod jest praktycznie ten sam co w funkcji main
     *
     * 1) zmienilem turnieje na vectory bo boost::array nie przydziela dynamicznie obiektow
     *     w zwiazku z tym wstawianie elementow do turniejow robi funkcja push_back
     *
     *  2) tam gdzie byl typ long long zmienilem na int bo zakres wystarczy
     *
     *  3) dopasowalem nazwy niektorych zmiennych, tak zeby pasowaly do tych w klasie
     */

    Populacja turniejOsobnikow;
    Fitness turniejOsobnikowFitness;
    int indeksTurniej;
    int mistrz;
    std::cout << std::endl << std::endl;
    for (int c = iloscElity; c < iloscOsobnikow; ++c) {
        //Metoda turniejowa losujemy 3 Osobnikow zapisujemy do nowego wektora
        //oraz wyliczamy jego fitens i tez zapisujemy do wektora
        for (int a = 0; a < 3; ++a) {
            int ktory = losuj(iloscOsobnikow - iloscElity);
            turniejOsobnikow.push_back(populacja.at(ktory));
            turniejOsobnikowFitness.push_back(turniejOsobnikow.at(a).fitness());
            std::cout << "DoTurnieju:" << a << " " << turniejOsobnikow.at(a)
                    << " Fit: " << turniejOsobnikowFitness.at(a) << std::endl;
        }

        mistrz = *std::max_element(turniejOsobnikowFitness.begin(),
                turniejOsobnikowFitness.end());

        for (int i = 0; i < iloscOsobnikow; ++i) {
            if (mistrz == fitnessOsobnikow.at(i)) {
                indeksTurniej = i;
                nowePokolenie.at(c) = populacja.at(i);
            }
        }

        std::cout << c << "-" << indeksTurniej << " Mistrzem: " << mistrz
                << " ma index w Osobnikach: " << indeksTurniej << std::endl
                << std::endl;

        // to dodalem zeby Twoj kod dzialal poprawnie z wektorami - Maciek
        turniejOsobnikow.clear();
        turniejOsobnikowFitness.clear();
    }

    //Ala debug :)
    for (int i = 0; i < iloscOsobnikow; ++i) {
        std::cout << "NowePokol:" << i << " " << nowePokolenie.at(i)
                << std::endl;
    }
}
