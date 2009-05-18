/*
 * Algorytm.cpp
 *
 *  Created on: 2009-04-19
 *      Author: TMG
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

    // ETAP 1
    losujPopulacje();

    // ETAP 2
    obliczFitness();

    // zapis do plikow
    plik.wierszRun(0, populacja.at(indeksNalepszego()), srednia(
            fitnessOsobnikow));
    plik.wierszBest(0, populacja.at(indeksNalepszego()));
    // TODO zapis cegielek do pliku Blocks.txt


    // TODO warunek zakonczenia petli z linii polecen
    for (int generacja = 0; generacja < 10; ++generacja) {

        std::cout << ">>>>> GENERACJA " << generacja + 1 << " <<<<<"
                << std::endl;

        // ETAP 3
        przeniesElite();

        // wyswietlanie wynikow
        wyswietlPopulacje();

        // ETAP 4
        selekcjaTurniejowa();

        // ETAP 5
        podzialNaPary();

        /*
         * ETAP 6 - Krzyzowanie
         */
        for (unsigned int para = 0; para < listaPar.size(); ++para) {

            int typKrzyzowania = losuj(3);
            int dlugoscChromosomu = listaPar.at(para).first.koniec();

            switch (typKrzyzowania) {
                case 0: {
                    int pktCiecia = losuj(dlugoscChromosomu);

                    // krzyzowanie jednopunktowe
                    krzyzuj <Chromosom, Cegielka> (listaPar.at(para).first,
                            listaPar.at(para).second, pktCiecia);
                    break;
                }

                case 1: {
                    int pktCiecia1 = losuj(dlugoscChromosomu);
                    int pktCiecia2 = losuj(dlugoscChromosomu);

                    // krzyzowanie dwupunktowe
                    krzyzuj <Chromosom, Cegielka> (listaPar.at(para).first,
                            listaPar.at(para).second, std::min(pktCiecia1,
                                    pktCiecia2), std::max(pktCiecia1,
                                    pktCiecia2));
                    break;
                }

                case 2: {
                    int pktCiecia = losuj(
                            listaPar.at(0).first.odczytaj(0).koniec());

                    // krzyzowanie jednopunktowe na poziomie cegielki
                    for (int i = 0; i < dlugoscChromosomu; ++i) {
                        krzyzuj <Cegielka, int> (
                                listaPar.at(para).first.odczytaj(i),
                                listaPar.at(para).second.odczytaj(i), pktCiecia);
                    }
                    break;
                }

                default:
                    break;
            }
        }

        // kopiowanie skrzyzowanych osobnikow z listy par do nowej populacji
        dopelnijNowaPopulacje();

        /*
         * ETAP 7 - Mutacja
         */
        for (unsigned int osobnik = 0; osobnik < nowePokolenie.size(); ++osobnik) {
            if (!nowePokolenie.at(osobnik).isElita()) {
                int typMutacji = losuj(3);
                int dlugoscChromosomu = nowePokolenie.at(osobnik).koniec();

                switch (typMutacji) {
                    case 0: {
                        // mutacja z prawdopodobienstwem
                        mutacja(nowePokolenie.at(osobnik), 0.1);
                        break;
                    }

                    case 1: {
                        int nrCegielki1 = losuj(dlugoscChromosomu);
                        int nrCegielki2;

                        // losuj numer drugiej cegielki tak dlugo, dopoki
                        // numery cegielek sa rowne
                        do {
                            nrCegielki2 = losuj(dlugoscChromosomu);
                        } while (nrCegielki2 == nrCegielki1);

                        // mutacja zamieniajaca cegielki miejscami
                        mutacja(nowePokolenie.at(osobnik), nrCegielki1,
                                nrCegielki2);
                        break;
                    }

                    case 2: {
                        int nrCegielki = losuj(dlugoscChromosomu);

                        // mutacja odwracajaca cegielke
                        mutacja(nowePokolenie.at(osobnik), nrCegielki);
                        break;
                    }

                    default:
                        break;
                }
            }
        }

        populacja.clear();
        fitnessOsobnikow.clear();

        /*
         * ETAP 8 - ocena osobnikow
         */
        populacja = nowePokolenie;
        obliczFitness();

        populacjaBezElity.clear();
        nowePokolenie.clear();
        listaPar.clear();

        // zapis do plikow
        plik.wierszRun(generacja + 1, populacja.at(indeksNalepszego()),
                srednia(fitnessOsobnikow));
        plik.wierszBest(generacja + 1, populacja.at(indeksNalepszego()));
        // TODO zapis cegielek do pliku Blocks.txt
    }

    // wyswietlanie wynikow
    std::cout << std::endl;
    wyswietlPopulacje();
    std::cout << std::endl;
}

void Algorytm::losujPopulacje() {
    for (int i = 0; i < iloscOsobnikow; ++i) {
        Chromosom chr;
        populacja.push_back(chr);
    }
}

// obliczanie sredniego fitnessu
double Algorytm::srednia(const Fitness& fitness) {
    double suma = 0.0;

    BOOST_FOREACH(double i, fitness) {
        suma += i;
    }

    return suma / fitness.size();
}

// FIXME fintnessOsobnikow
// pobranie indeksu osobnika z najlepszym fitnessem
int Algorytm::indeksNalepszego() {
    double najlepszy = *std::max_element(fitnessOsobnikow.begin(),
            fitnessOsobnikow.end());

    for (unsigned int i = 0; i < fitnessOsobnikow.size(); ++i) {
        if (fitnessOsobnikow.at(i) == najlepszy) {
            return i;
        }
    }

    return -1;
}

void Algorytm::wyswietlPopulacje() {
    int i = 1;

    BOOST_FOREACH(Chromosom c, populacja) {
        std::cout << "Chromosom " << i << ": " << c
            << " Fitness: " << std::fixed << std::setprecision(6)
            << c.fitness() << " Elita: " << c.isElita() << std::endl;
        ++i;
    }
}

// DEPRECATED
void Algorytm::obliczFitness() {
    for (int i = 0; i < iloscOsobnikow; ++i) {
        fitnessOsobnikow.push_back(populacja.at(i).fitness());
    }
}

int Algorytm::losuj(int zakres) {
    return rand() % zakres;
}

void Algorytm::przeniesElite() {

    // kazdy osobnik w populacji traci status elity
    // (petla musi tak wygladac bo BOOST_FOREACH nie dziala poprawnie)
    for (Populacja::iterator i = populacja.begin(); i != populacja.end(); ++i) {
        if ((*i).isElita()) {
            (*i).setElita(false);
        }
    }

    // sortowanie populacji wzgledem fitnessu
    // i ustawienie dwoch najlepszych osobnikow jako elite
    std::sort(populacja.begin(), populacja.end(), fitnessCmp);
    populacja.at(0).setElita(true);
    populacja.at(1).setElita(true);

    // czyszczenie wektorow
    nowePokolenie.clear();
    populacjaBezElity.clear();

    // przeniesienie elity do nowego pokolenia, a reszte chromosomow
    // do wektora roboczego
    BOOST_FOREACH(Chromosom c, populacja) {
        if (c.isElita()) {
            nowePokolenie.push_back(c);
        } else {
            populacjaBezElity.push_back(c);
        }
    }
}

bool Algorytm::fitnessCmp(Chromosom i, Chromosom j) {
    return i.fitness() > j.fitness();
}

void Algorytm::selekcjaTurniejowa() {
    Populacja turniejOsobnikow;
    Fitness turniejOsobnikowFitness;
    Populacja wynik;
    int indeksTurniej;
    double mistrz;

    std::cout << std::endl << std::endl;
    unsigned int size = populacjaBezElity.size();
    for (unsigned int osobnik = 0; osobnik < size; ++osobnik) {

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
        BOOST_FOREACH(Chromosom c, populacjaBezElity)
{        if (mistrz <= c.fitness() + 0.00000001 && mistrz >= c.fitness() - 0.00000001) {
            indeksTurniej = i;
            wynik.push_back(c);
            //                break;
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
//    int i = 0;
//    std::cout << std::endl;
//    BOOST_FOREACH(Chromosom c, populacjaBezElity) {
//        std::cout << "Nowe pokolenie bez elity " << i + 1 << ": " << c << std::endl;
//        ++i;
//    }
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

// usuniecie chromosomu z wektora populacjaBezElity
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

// przenoszenie chromosomow do nowego pokolenia
void Algorytm::dopelnijNowaPopulacje() {
    for (unsigned int i = 0; i < listaPar.size(); ++i) {
        nowePokolenie.push_back(listaPar.at(i).first);
        nowePokolenie.push_back(listaPar.at(i).second);
    }
}
