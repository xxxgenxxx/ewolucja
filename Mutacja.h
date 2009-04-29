/*
 * Mutacja.h
 *
 *  Created on: 2009-04-04
 *      Author: Maciej Libuda
 */

#ifndef MUTACJA_H_
#define MUTACJA_H_

#include "Chromosom.h"
#include "Cegielka.h"

void mutacja(Chromosom& chromosom, int nrCegielki);
void mutacja(Chromosom& chromosom, int nrCegielki1, int nrCegielki2);
void mutacja(Chromosom& chromosom, double pstwo);

#endif /* MUTACJA_H_ */
