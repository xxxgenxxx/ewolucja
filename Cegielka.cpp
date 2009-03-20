/*
 * Cegielka.cpp
 *
 *  Created on: 2009-03-16
 *      Author: TMG
 */


#include "Cegielka.h"
//#include <vector>
//#include <iostream>
//#include <ctime>
#include <cstdlib>


Cegielka::Cegielka(int dl)
{
	dlugosc=dl;
}

void Cegielka::Inicjuj()
{
	//losowanie genow
	vector<int> cegielka;
	 // for (int i=1; i<=5; i++) cegielka.push_back(i);

	  cout << "masza cegielka";
	//  vector<int>::iterator rit;
	 // for ( rit=cegielka.begin() ; rit < cegielka.end(); ++rit )
	   // cout << " " << *rit;

	  cout << endl;
	  srand((unsigned)time(0));
	      int random_integer;
	      for(int index=0; index<5; index++){
	          random_integer = (rand()%2);
	          cegielka.push_back(random_integer);
	         // cout << random_integer << endl;
	      }
	      vector<int>::iterator rit;
	      for ( rit=cegielka.begin() ; rit < cegielka.end(); ++rit )
	       cout << " " << *rit;




}
