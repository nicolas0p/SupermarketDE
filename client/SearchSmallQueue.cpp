/*
 * SearchSmallQueue.cpp
 *
 *  Created on: 13/05/2014
 *      Author: arthurhortmannerpen
 */

#include "SearchSmallQueue.h"
#include "../CircularList.h"


SearchBehavior* SearchSmallQueue::copy() const {
	return new SearchSmallQueue();
}

Cashier &SearchSmallQueue::search(CircularList<Cashier> &cashiers) const {
	CircularList<Cashier>::iterator best = cashiers.begin();
	if (cashiers.size() != 1) {
		for (CircularList<Cashier>::iterator it = ++cashiers.begin(); it != cashiers.end(); ++it) {
			if (it->queueSize() < best->queueSize()) {
				best = it;
			}
		}
	}
	if (best->queueSize() > 9) {
		throw std::exception();
	}
	return *best;
}
