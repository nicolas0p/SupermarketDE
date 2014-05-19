/*
 * SearchLessItems.cpp
 *
 *  Created on: 13/05/2014
 *      Author: arthurhortmannerpen
 */

#include "SearchLessItems.h"
#include <vector>
#include "SearchBehavior.h"

SearchBehavior* SearchLessItems::copy() const {
	return new SearchLessItems();
}

Cashier &SearchLessItems::search(std::vector<Cashier> &cashiers) const {
	std::vector<Cashier>::iterator best = cashiers.begin();
	if (cashiers.size() == 1) {
		if (best->queueSize() > 9) {
			throw 0;
		}
		return *best;
	}
	bool leave = true;
	for (std::vector<Cashier>::iterator it = best + 1; it != cashiers.end(); ++it) {
		if (it->queueSize() < 10) {
			leave = false;
		}
		if (it->numOfItems() < best->numOfItems()){
			best = it;
		}
	}
	if (leave) {
		throw 0;
	}
	return *best;
}
