/*
 * SearchLessItems.cpp
 *
 *  Created on: 13/05/2014
 *      Author: arthurhortmannerpen
 */

#include "SearchLessItems.h"
#include "../CircularList.h"
#include "SearchBehavior.h"


SearchBehavior* SearchLessItems::copy() const {
	return new SearchLessItems();
}

Cashier &SearchLessItems::search(CircularList<Cashier> &cashiers) const {
	CircularList<Cashier>::iterator best = cashiers.begin();
	bool leave = best->queueSize() >= 10;
	for (CircularList<Cashier>::iterator it = ++cashiers.begin(); it != cashiers.end(); ++it) {
		if (it->queueSize() < 10) {
			leave = false;
		}
		if (it->numOfItems() < best->numOfItems()){
			best = it;
		}
	}
	if (leave) {
		throw std::exception();
	}
	return *best;
}


