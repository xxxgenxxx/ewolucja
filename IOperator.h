/*
 * IOperator.h
 *
 *  Created on: 2009-03-20
 *      Author: Maciej Libuda
 */

#ifndef IOPERATOR_H_
#define IOPERATOR_H_

/*
 * Interfejs dla klas modyfikowanych przez operatory genetyczne
 */
class IOperator {
    public:
        IOperator();
        virtual ~IOperator() = 0;

        virtual int poczatek() const = 0;
        virtual int koniec() const = 0;
        virtual int odczytaj(int element) const = 0;
        virtual void zapisz(int element, int wartosc) = 0;

};

/*
 * Konstruktor domyslny
 */
inline IOperator::IOperator() {
}

/*
 * Destruktor
 */
inline IOperator::~IOperator() {
}

#endif /* IOPERATOR_H_ */
