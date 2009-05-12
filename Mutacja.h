/*
 * Mutacja.h
 *
 *  Created on: 2009-04-04
 *      Author: TMG
 */

#ifndef MUTACJA_H_
#define MUTACJA_H_

#include "Chromosom.h"
#include "Cegielka.h"

// mutacja odwracajaca cegielke
void mutacja(Chromosom& chromosom, int nrCegielki);

// mutacja zamieniajaca cegielki miejscami
void mutacja(Chromosom& chromosom, int nrCegielki1, int nrCegielki2);

// mutacja zmieniajaca geny w zaleznosci od  prawodopodobienstwa
void mutacja(Chromosom& chromosom, double pstwo);

#endif /* MUTACJA_H_ */
