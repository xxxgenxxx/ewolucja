/*
 * IOperator.h
 *
 *  Created on: 2009-03-20
 *      Author: TMG
 */

#ifndef IOPERATOR_H_
#define IOPERATOR_H_

/*
 * Interfejs dla klas modyfikowanych przez operatory genetyczne
 */
template <class T>
class IOperator {
    public:
        IOperator();
        virtual ~IOperator() = 0;

        virtual int poczatek() const = 0;
        virtual int koniec() const = 0;
        virtual T odczytaj(int element) = 0;
        virtual void zapisz(int element, T wartosc) = 0;
};

/*
 * Konstruktor domyslny
 */
template <class T>
inline IOperator <T>::IOperator() {
}

/*
 * Destruktor
 */
template <class T>
inline IOperator <T>::~IOperator() {
}

/*
 * Copyright Athantor 2009
 * License GNU GPL 3 or newer
 */
static inline long frand( long max = RAND_MAX )
{
    return static_cast<double> (rand()) / ((static_cast<double> (RAND_MAX) + 1.0) / (static_cast<double> (max)));
}

#endif /* IOPERATOR_H_ */
