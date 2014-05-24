/*
 * SearchLessItems.cpp
 *
 *  Created on: 13/05/2014
 *      Author: arthurhortmannerpen
 */

#include "SearchLessItems.h"
#include <vector>
#include "SearchBehavior.h"

#include <iostream>

SearchBehavior* SearchLessItems::copy() const {
	return new SearchLessItems();
}

Cashier &SearchLessItems::search(std::vector<Cashier> &cashiers) const {
	std::vector<Cashier>::iterator best = cashiers.begin();
	bool leave = best->queueSize() >= 10;
	for (std::vector<Cashier>::iterator it = ++cashiers.begin(); it != cashiers.end(); ++it) {
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


