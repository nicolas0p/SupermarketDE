/*
 * SearchLessItems.cpp
 *
 *  Created on: 13/05/2014
 *      Author: arthurhortmannerpen
 */

#include "../dataStructures/CircularList.h"

#include "SearchLessItems.h"
#include "SearchBehavior.h"

SearchBehavior* SearchLessItems::copy() const {
	return new SearchLessItems();
}

Cashier &SearchLessItems::search(Queue<Cashier> &cashiers) const {
	Queue<Cashier>::iterator best = cashiers.begin();
	if (cashiers.size() == 1) {
		if (best->queueSize() > 9) {
			throw 0;
		}
		return *best;
	}
	bool leave = true;
	Queue<Cashier>::iterator it = best;
	for (++it; it != cashiers.end(); ++it) {
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
