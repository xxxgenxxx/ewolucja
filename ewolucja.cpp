//============================================================================
// Name        : ewolucja.cpp
// Author      : Grupa TMG
// Version     :
// Copyright   : GPL
// Description : Prosty program z dziedziny algorytmów genetycznych
//============================================================================

#include <cstdlib>
#include <iostream>
#include "Cegielka.h"
#include "Chromosom.h"
#include "Krzyzowanie.h"
#include "Losowanie.h"
#include "Mutacja.h"
#include <boost/array.hpp>
#include <boost/foreach.hpp>
#include <algorithm>


using namespace std;



//=========== GŁÓWNA FUNKCJA PROGRAMU -MAIN ===================================
int main() {

    // Inicjalizacja generatora liczb losowych
    srand((unsigned) time(0));
	const int ilosc = 10;
	boost::array<Chromosom,ilosc> iloscOsobnikow, nowePokolenie;
	boost::array<long long,ilosc> fitnesOsobnikow;
    int pokolenie =5 ,krok=0, nElita=2;	
	int indeksElity1,indeksElity2; //indeks nalepszego Osobnika
	
	
	
	//Inicjujemy tyle Chromosomów ile wynosi "ilosc"
	for (int i=0; i!=ilosc; ++i)
	{
		Chromosom chr;
		iloscOsobnikow.at(i)=chr;
	}

	//wyliczamy fitens dla wszystkich Chrosomow i zapamietujemy je 
	//w tablicy "fitnesOsobnikow" 
	for (int i=0; i<ilosc; ++i)
	{	

		fitnesOsobnikow.at(i)=iloscOsobnikow.at(i).fitenss();
		//std::cout << "Chromosom:" <<i <<" " <<iloscOsobnikow.at(i) 
		//<<" Fit: " <<fitnesOsobnikow.at(i)<<endl;
	}


//---------------Kod do poprawienia ---------------------
	// wydobywamy dwa najlepsze osobniki i dodajemy ich do elity
	long long elita1, elita2;		
	elita1=*max_element(fitnesOsobnikow.begin(),fitnesOsobnikow.end());	 
	//sort (fitnesOsobnikow.begin(),fitnesOsobnikow.end());
	//powyższa funkcja wyliczyla nam maksymalny element ale nie 
	//wiemy na jakiej pozycj, dlatego poniższa pętla 
	//wskaże na jakiej pozycji jest maksymalny element.
	//Osobnik o maksymalnej wartosci jest eltą
 	for (int i=0; i<ilosc; ++i)
	{	
		if (elita1==fitnesOsobnikow.at(i))
		{
			indeksElity1=i;
			iloscOsobnikow.at(i).setElita(1);
			fitnesOsobnikow.at(i)=0;
		}
	}	

	elita2=*max_element(fitnesOsobnikow.begin(),fitnesOsobnikow.end());	 
 	for (int i=0; i<ilosc; ++i)
	{	
		if (elita2==fitnesOsobnikow.at(i))
		{
			indeksElity2=i;
			iloscOsobnikow.at(i).setElita(1);

		}
	}	
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ kod do poprawienia^^^^^^^^^^^^^^

	std::cout << "elita jest w indeksie "  <<indeksElity1 <<" " 
	<<elita1 << " , "<<indeksElity2 <<" " <<elita2 <<std::endl;

	for (int i=0; i<ilosc; ++i)
	{	
		fitnesOsobnikow.at(i)=iloscOsobnikow.at(i).fitenss();
		std::cout << "Chromosom:" <<i <<" " <<iloscOsobnikow.at(i) 
			<<" Fit: " <<fitnesOsobnikow.at(i)<< " Elita " 
			<<iloscOsobnikow.at(i).isElita() <<endl;
	}
	
	
	nowePokolenie.at(0)=iloscOsobnikow.at(indeksElity1);
	nowePokolenie.at(1)=iloscOsobnikow.at(indeksElity2);

	boost::array<Chromosom,ilosc> turniejOsobnikow;
	boost::array<long long,3> turniejOsobnikowFitness;
	int indeksTurniej;
	long long mistrz;
	std::cout <<endl <<endl;
	for (int c=nElita; c<ilosc; ++c)
	{	
		//Metoda turniejowa losujemy 3 Osobnikow zapisujemy do nowego wektora
		//oraz wyliczamy jego fitens i tez zapisujemy do wektora
		for (int a =0; a<3; ++a)
		{
			int ktory = losuj(ilosc-nElita);
			turniejOsobnikow.at(a)=iloscOsobnikow.at(ktory);
			turniejOsobnikowFitness.at(a)=turniejOsobnikow.at(a).fitenss();
			std::cout << "DoTurniju:" <<a <<" " <<turniejOsobnikow.at(a) <<" Fit: " 
			<<turniejOsobnikowFitness.at(a)  <<std::endl;			
		}

		mistrz=*max_element(turniejOsobnikowFitness.begin(),turniejOsobnikowFitness.end());	 	
		
	 	for (int i=0; i<ilosc; ++i)
		{	
			if (mistrz==fitnesOsobnikow.at(i))
			{
				indeksTurniej=i;	
				nowePokolenie.at(c)=iloscOsobnikow.at(i);
			}
		}

		std::cout <<c <<"-" <<indeksTurniej <<" Mistrzem: "<<mistrz <<" ma index w Osobnikach: " <<indeksTurniej <<endl <<endl;		
	}
	
	//Ala debug :)
	for (int i=0; i<ilosc; ++i)
	{	
		std::cout << "NowePokol:" <<i <<" " <<nowePokolenie.at(i)  <<std::endl;
	}

	Cegielka c;
	
	c=nowePokolenie.at(0).odczytaj(0);
	std::cout << "cegielka 1\n" << c << "\ncegielka 2\n" << c << std::endl;
	Chromosom cch;
	//Krzyzowanie na poziomie cegielek
	for (int c=nElita; c<ilosc; ++c)
	{
		int wynik = losuj(2);
		
		switch (wynik)
		{
			case 0:
				std::cout << "w:" <<wynik <<std::endl;
//				BOOST_REVERSE_FOREACH(Cegielka cegielka, ) {
	//				std::cout << "cegielka 1\n";// << nowePokolenie.at(0).odczytaj(0) << std::endl;
     	
     //			}
			break;
			
			case 1:
				std::cout << "w:" <<wynik <<std::endl;
			break;
//			case 2:
	//		std::cout << "w:" <<wynik <<std::endl;
		//	break;
			
			
		}
		
	}
	
	
	while (krok <pokolenie)
	{
		std::cout << "Pokolenie: " << krok <<std::endl;	
		
		
		krok++;
	}

	
//	cout << "Czy Chromosom nalezy do elity: " <<iloscOsobnikow.at(indeksMaxOsobnika).isElita()
	//	 <<endl;

		
//    Cegielka c(5);
  //  Cegielka c2(5);


//    std::cout << "cegielka 1\n" << c << "\ncegielka 2\n" << c2 << std::endl;

    // krzyzuje dwupunktowo cegielki zawierajace inty
    // i wymienia miedzy nimi geny od 1 do 3
//    krzyzuj <Cegielka, int> (c, c2, 1, 3);

    // krzyzuje jednopunktowo cegielki zawierajace inty
    // i wymienia miedzy nimi geny od 2 do konca
    //    krzyzuj <Cegielka, int> (c, c2, 2);

  //  std::cout << "\nPo krzyzowaniu\ncegielka 1\n" << c << "\ncegielka 2\n"
    //        << c2 << std::endl;

 //>   Chromosom g1;
 //>    Chromosom g2;
 //>    std::cout << "\n\nchromosom 1\n" << g1 << "\nchromosom 2\n" << g2
 //>            << std::endl;

 //>    krzyzuj <Chromosom, Cegielka> (g1, g2, 3);
 //>    std::cout << "\nPo krzyzowaniu\nchromosom 1\n" << g1 << "\nchromosom 2\n"
 //>            << g2 << std::endl;

 //>    mutacja(g1, 4);
 //>    std::cout << "\nMutacja 1 typu chromosomu 1\n" << g1 << std::endl;

 //>    mutacja(g2, 0, 1);
 //>    std::cout << "\nMutacja 2 typu chromosomu 2\n" << g2 << std::endl;

    // Losowanie typu operacji np krzyzowania lub mutacji
    // losuj(3) oznacza wylosuj jedna operacje z trzech dostepnych
 //>    int wynik = losuj(3);
 //>    std::cout << "\nLosowanie: " << wynik << std::endl;
	//std::cout << "\nFentotypX1 g1X1: " << g1.getFenotypX1() << std::endl;
  //  std::cout << "\nFentotypX2 g1X2: " << g1.getFenotypX2() << std::endl;
 //>	std::cout << "\nFitnes g1: " << g1.fitenss() << std::endl;
 //>		std::cout << "\nFitnes g2: " << g2.fitenss() << std::endl;

    return 0;
}
