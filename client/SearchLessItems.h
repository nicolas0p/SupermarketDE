/*
 * SearchLessItems.h
 *
 *  Created on: 13/05/2014
 *      Author: arthurhortmannerpen
 */

#ifndef SEARCHLESSITEMS_H_
#define SEARCHLESSITEMS_H_

#include "SearchBehavior.h"
#include <vector>

class SearchLessItems: public SearchBehavior {
public:
	SearchBehavior *copy() const;
	Cashier &search(std::vector<Cashier> &cashiers) const;
};

#endif /* SEARCHLESSITEMS_H_ */
