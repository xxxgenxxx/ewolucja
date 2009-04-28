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

#endif /* IOPERATOR_H_ */
