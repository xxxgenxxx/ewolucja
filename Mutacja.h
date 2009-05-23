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

/*
 * Copyright Athantor 2009
 * License GNU GPL 3 or newer
 */
static inline long frand( long max = RAND_MAX )
{
    return static_cast<double> (rand()) / ((static_cast<double> (RAND_MAX) + 1.0) / (static_cast<double> (max)));
}

#endif /* MUTACJA_H_ */
