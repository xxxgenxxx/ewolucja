/*
 * IOperator.h
 *
 *  Created on: 2009-03-20
 *      Author: Maciej Libuda
 */

#ifndef IOPERATOR_H_
#define IOPERATOR_H_

class IOperator {
    public:
        IOperator();
        virtual ~IOperator();

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
