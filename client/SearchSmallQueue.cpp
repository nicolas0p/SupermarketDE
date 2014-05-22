/*
 * SearchSmallQueue.cpp
 *
 *  Created on: 13/05/2014
 *      Author: arthurhortmannerpen
 */

#include "../dataStructures/CircularList.h"

#include "SearchSmallQueue.h"

SearchBehavior* SearchSmallQueue::copy() const {
	return new SearchSmallQueue();
}

Cashier &SearchSmallQueue::search(CircularList<Cashier> &cashiers) const {
	CircularList<Cashier>::iterator best = cashiers.begin();
	if (cashiers.size() != 1) {
		CircularList<Cashier>::iterator it = best;
		for (++it; it != cashiers.end(); ++it) {
			if (it->queueSize() < best->queueSize()) {
				best = it;
			}
		}
	}
	if (best->queueSize() > 9) {
		throw 0;
	}
	return *best;
}