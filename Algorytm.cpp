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
Algorytm::Algorytm(int iloscGen, int iloscOs) :
    iloscGeneracji(iloscGen), iloscOsobnikow(iloscOs), iloscElity(2) {
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

    // zapis do plikow
    Populacja::iterator najlepszy = std::max_element(populacja.begin(), populacja.end(), fitnessCmp);
    plik.wierszRun(0, *najlepszy, srednia());
    plik.wierszBest(0, *najlepszy);
    // TODO zapis cegielek do pliku Blocks.txt

    for (int generacja = 0; generacja < iloscGeneracji; ++generacja) {

        std::cout << ">>>>> GENERACJA " << generacja + 1 << " <<<<<\n";

        // ETAP 2
        przeniesElite();

        wyswietlPopulacje();

        // ETAP 3
        selekcjaTurniejowa();

        // ETAP 4
        podzialNaPary();

        // ETAP 5
        krzyzowanie();

        // kopiowanie skrzyzowanych osobnikow z listy par do nowej populacji
        dopelnijNowaPopulacje();

        // ETAP 6
        mutowanie();

        populacja.clear();
        populacja = nowePokolenie;

        // zapis do plikow
        najlepszy = std::max_element(populacja.begin(), populacja.end(), fitnessCmp);
        plik.wierszRun(generacja + 1, *najlepszy, srednia());
        plik.wierszBest(generacja + 1, *najlepszy);
        // TODO zapis cegielek do pliku Blocks.txt
    }

    std::cout << "===== WYNIK KOŃCOWY =====\n";
    wyswietlPopulacje();
}

void Algorytm::losujPopulacje() {
    for (int i = 0; i < iloscOsobnikow; ++i) {
        Chromosom chr;
        populacja.push_back(chr);
    }
}

// obliczanie sredniego fitnessu
double Algorytm::srednia() {
    double suma = 0.0;

    BOOST_FOREACH(Chromosom c, populacja) {
        suma += c.fitness();
    }

    return suma / populacja.size();
}

// metoda porownujaca fitnessy podczas wyboru najlepszego chromosomu
bool Algorytm::fitnessCmp(Chromosom i, Chromosom j) {
    return i.fitness() < j.fitness();
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
    // i ustawienie dwoch najlepszych osobnikow jako elita
    std::sort(populacja.begin(), populacja.end(), sortCmp);
    for (int i = 0; i < iloscElity; ++i) {
        populacja.at(i).setElita(true);
    }

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

// metoda porownujaca fitnessy chromosomow podczas sortowania
bool Algorytm::sortCmp(Chromosom i, Chromosom j) {
    return i.fitness() > j.fitness();
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

int Algorytm::losuj(int zakres) {
    return rand() % zakres;
}

void Algorytm::selekcjaTurniejowa() {
    Populacja turniejOsobnikow;
    Populacja wynik;

    std::cout << std::endl << std::endl;

    for (unsigned int osobnik = 0; osobnik < populacjaBezElity.size(); ++osobnik) {

        // Metoda turniejowa losujemy 3 osobnikow zapisujemy do nowego wektora
        // oraz wyliczamy jego fitness i tez zapisujemy do wektora
        for (int a = 0; a < 3; ++a) {
            int ktory = losuj(iloscOsobnikow - iloscElity);
            turniejOsobnikow.push_back(populacjaBezElity.at(ktory));

            std::cout << "DoTurnieju:" << a << " " << turniejOsobnikow.at(a)
                    << " Fit: " << turniejOsobnikow.at(a).fitness() << std::endl;
        }

        // wyznaczenie mistrza turnieju
        Chromosom mistrz = *std::max_element(turniejOsobnikow.begin(), turniejOsobnikow.end(), fitnessCmp);

        // zatwierdzenie osobnika jesli jest mistrzem turnieju
        int i = 0;
        int indeksTurniej;
        BOOST_FOREACH(Chromosom c, populacjaBezElity) {
            if (mistrz.fitness() <= c.fitness() + 0.00000001 && mistrz.fitness() >= c.fitness() - 0.00000001) {
                indeksTurniej = i;
                wynik.push_back(c);
                break;
            }
            ++i;
        }

        std::cout << osobnik + 1 << "-" << indeksTurniej << " Mistrzem: " << mistrz.fitness()
        << " ma index w Osobnikach: " << indeksTurniej << std::endl
        << std::endl;

        turniejOsobnikow.clear();
    }

    populacjaBezElity.clear();
    populacjaBezElity = wynik;
}

void Algorytm::podzialNaPary() {
    int size = populacjaBezElity.size() / 2;
    listaPar.clear();

    for (int i = 0; i < size; ++i) {
        Para paraOsobnikow;

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

// krzyzowanie par osobnikow
void Algorytm::krzyzowanie() {
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
}

// przenoszenie chromosomow do nowego pokolenia
void Algorytm::dopelnijNowaPopulacje() {
    BOOST_FOREACH(Para p, listaPar) {
        nowePokolenie.push_back(p.first);
        nowePokolenie.push_back(p.second);
    }
}

// mutacja osobnikow nie nalezacych do elity
void Algorytm::mutowanie() {
    for (unsigned int osobnik = 0; osobnik < nowePokolenie.size(); ++osobnik) {
        if (!nowePokolenie.at(osobnik).isElita()) {
            int typMutacji = losuj(3);
            int dlugoscChromosomu = nowePokolenie.at(osobnik).koniec();

            switch (typMutacji) {
                case 0: {
                    // mutacja z prawdopodobienstwem 0.1
                    mutacja(nowePokolenie.at(osobnik), 0.1);
                    break;
                }

                case 1: {
                    int nrCegielki1 = losuj(dlugoscChromosomu);
                    int nrCegielki2;

                    // dopoki numery cegielek sa rowne
                    // losuj kolejny numer cegielki
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
}
