/*
 * SearchSmallQueue.cpp
 *
 *  Created on: 13/05/2014
 *      Author: arthurhortmannerpen
 */

#include "../dataStructures/CircularList.h"
#include "../cashier/Cashier.h"
#include "SearchSmallQueue.h"

SearchBehavior* SearchSmallQueue::copy() const {
	return new SearchSmallQueue();
}

Cashier &SearchSmallQueue::search(Queue<Cashier> &cashiers) const {
	Queue<Cashier>::iterator best = cashiers.begin();
	if (cashiers.size() != 1) {
		Queue<Cashier>::iterator it = best;
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
