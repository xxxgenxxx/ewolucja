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
    podzialNaPary();

    /*
     * Krzyzowanie
     */
    for (unsigned int para = 0; para < listaPar.size(); ++para) {

        int typKrzyzowania = losuj(3);
        int dlugoscChromosomu = listaPar.at(para).first.koniec();

        switch (typKrzyzowania) {
            case 0: {
                int pktCiecia = losuj(dlugoscChromosomu);

                // krzyzowanie jednopunktowe
                krzyzuj <Chromosom, Cegielka> (listaPar.at(para).first, listaPar.at(para).second, pktCiecia);
                break;
            }

            case 1: {
                int pktCiecia1 = losuj(dlugoscChromosomu);
                int pktCiecia2 = losuj(dlugoscChromosomu);

                // krzyzowanie dwupunktowe
                krzyzuj <Chromosom, Cegielka> (listaPar.at(para).first, listaPar.at(para).second,
                        std::min(pktCiecia1, pktCiecia2), std::max(pktCiecia1, pktCiecia2));
                break;
            }

            case 2: {
                int pktCiecia = losuj(listaPar.at(0).first.odczytaj(0).koniec());

                // krzyzowanie jednopunktowe na poziomie cegielki
                for (int i = 0; i < dlugoscChromosomu; ++i) {
                    krzyzuj <Cegielka, int> (listaPar.at(para).first.odczytaj(i),
                            listaPar.at(para).second.odczytaj(i), pktCiecia);
                }
                break;
            }

            default:
                break;
        }
    }

    dopelnijNowaPopulacje();

    // DEBUG
    for (int i = 0; i < 10; ++i) {
        std::cout << i+1 << ": " << nowePokolenie.at(i) << std::endl;
    }

    /*
     * Mutacja
     */
    for (unsigned int osobnik = 0; osobnik < nowePokolenie.size(); ++osobnik) {
        if(!nowePokolenie.at(osobnik).isElita()) {
            int typMutacji = losuj(3);
            int dlugoscChromosomu = nowePokolenie.at(osobnik).koniec();

            switch (typMutacji) {
                case 0:
                    std::cout << "mutacja 1" << std::endl;
                    // TODO mutacja z prawdopodobienstwem
                    break;

                case 1: {
                    int nrCegielki1 = losuj(dlugoscChromosomu);
                    int nrCegielki2;

                    // losuj numer drugiej cegielki tak dlugo, dopoki
                    // numery cegielek sa rowne
                    do {
                        nrCegielki2 = losuj(dlugoscChromosomu);
                    } while(nrCegielki2 == nrCegielki1);

                    std::cout << "mutacja 2: " << nrCegielki1 << ", " << nrCegielki2 << std::endl;
                    mutacja(nowePokolenie.at(osobnik), nrCegielki1, nrCegielki2);
                    break;
                }

                case 2: {
                    int nrCegielki = losuj(dlugoscChromosomu);

                    std::cout << "mutacja 3: " << nrCegielki << std::endl;
                    mutacja(nowePokolenie.at(osobnik), nrCegielki);
                    break;
                }

                default:
                    break;
            }
        }
    }

    // ocena osobnikow
    populacja = nowePokolenie;
    fitnessOsobnikow.clear();
    obliczFitness();

    std::cout << std::endl;
    wyswietlPopulacje();

    // TODO zapis do pliku

    // TODO tutaj konczy sie petla while
}

void Algorytm::losujPopulacje() {
    for (int i = 0; i < iloscOsobnikow; ++i) {
        Chromosom chr;
        populacja.push_back(chr);
    }
}

void Algorytm::wyswietlPopulacje() {
    for (int i = 0; i < iloscOsobnikow; ++i) {
        // TODO wyswietlanie fitnessu z dokladnoscia do 6 miejsc po przecinku
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

    // przeniesienie nie elitarnych osobnikow do wektora populacjaBezElity
    BOOST_FOREACH(Chromosom c, populacja) {
        if (!c.isElita()) {
            populacjaBezElity.push_back(c);
        }
    }
}

void Algorytm::selekcjaTurniejowa() {
    Populacja turniejOsobnikow;
    Fitness turniejOsobnikowFitness;
    Populacja wynik;
    int indeksTurniej;
    int mistrz;

    std::cout << std::endl << std::endl;

    for (unsigned int osobnik = 0; osobnik < populacjaBezElity.size(); ++osobnik) {

        // Metoda turniejowa losujemy 3 osobnikow zapisujemy do nowego wektora
        // oraz wyliczamy jego fitness i tez zapisujemy do wektora
        for (int a = 0; a < 3; ++a) {
            int ktory = losuj(iloscOsobnikow - iloscElity);
            turniejOsobnikow.push_back(populacjaBezElity.at(ktory));
            turniejOsobnikowFitness.push_back(turniejOsobnikow.at(a).fitness());

            std::cout << "DoTurnieju:" << a << " " << turniejOsobnikow.at(a)
                    << " Fit: " << turniejOsobnikowFitness.at(a) << std::endl;
        }

        // wyznaczenie mistrza turnieju
        mistrz = *std::max_element(turniejOsobnikowFitness.begin(),
                turniejOsobnikowFitness.end());

        // zatwierdzenie osobnika jesli jest mistrzem turnieju
        int i = 0;
        BOOST_FOREACH(Chromosom c, populacjaBezElity) {
            // FIXME sprawdzanie z dokladnoscia do 6 miejsc po przecinku
            if (mistrz <= c.fitness() + 1 && mistrz >= c.fitness() - 1) {
                indeksTurniej = i;
                wynik.push_back(c);
            }
            ++i;
        }

        std::cout << osobnik + 1 << "-" << indeksTurniej << " Mistrzem: " << mistrz
        << " ma index w Osobnikach: " << indeksTurniej << std::endl
        << std::endl;

        turniejOsobnikow.clear();
        turniejOsobnikowFitness.clear();
    }

    populacjaBezElity.clear();
    populacjaBezElity = wynik;

    // DEBUG
    int i = 0;
    std::cout << std::endl;
    BOOST_FOREACH(Chromosom c, populacjaBezElity) {
        std::cout << "Nowe pokolenie bez elity " << i + 1 << ": " << c << std::endl;
        ++i;
    }
}

void Algorytm::podzialNaPary() {
    int size = populacjaBezElity.size() / 2;

    for (int i = 0; i < size; ++i) {
        std::pair <Chromosom, Chromosom> paraOsobnikow;

        // losowanie pierwszego chromosomu pary
        unsigned int indeks1 = losuj(populacjaBezElity.size());
        paraOsobnikow.first = populacjaBezElity.at(indeks1);
        usunChromosom(indeks1);

        // losowanie drugiego chromosomu pary
        unsigned int indeks2 = losuj(populacjaBezElity.size());
        paraOsobnikow.second = populacjaBezElity.at(indeks2);
        usunChromosom(indeks2);

        // wstawienie pary do listy
        listaPar.push_back(paraOsobnikow);
    }

    // DEBUG
//    for (int i = 0; i < 4; ++i) {
//        std::cout << "pierwszy: "<< listaPar.at(i).first << " " << "drugi: "
//        << listaPar.at(i).second << std::endl;
//    }
}

void Algorytm::usunChromosom(unsigned int indeks) {
    Populacja::iterator iter = populacjaBezElity.begin();
        for (unsigned int i = 0; i < populacjaBezElity.size(); ++i) {
            if (i == indeks) {
                break;
            }
            ++iter;
        }

    populacjaBezElity.erase(iter);
}

void Algorytm::dopelnijNowaPopulacje() {
    for (unsigned int i = 0; i < listaPar.size(); ++i) {
        nowePokolenie.push_back(listaPar.at(i).first);
        nowePokolenie.push_back(listaPar.at(i).second);
    }
}
