/*
 * SearchBehavior.h
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */

#ifndef SEARCHBEHAVIOR_H_
#define SEARCHBEHAVIOR_H_

#include "Cashier.h"
#include <vector>

class SearchBehavior {
public:
	virtual ~SearchBehavior() {}
	virtual SearchBehavior* copy() const = 0; //para poder criar o Client com (SearchLessItens(), blablabla)
	virtual Cashier &search(std::vector<Cashier> &cashiers) const = 0;
};

#endif /* SEARCHBEHAVIOR_H_ */
