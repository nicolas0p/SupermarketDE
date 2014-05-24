/*
 * SearchSmallQueue.cpp
 *
 *  Created on: 13/05/2014
 *      Author: arthurhortmannerpen
 */

#include "SearchSmallQueue.h"
#include <vector>
#include <iostream>

SearchBehavior* SearchSmallQueue::copy() const {
	return new SearchSmallQueue();
}

Cashier &SearchSmallQueue::search(std::vector<Cashier> &cashiers) const {
	std::vector<Cashier>::iterator best = cashiers.begin();
	if (cashiers.size() != 1) {
		for (std::vector<Cashier>::iterator it = best + 1; it != cashiers.end(); ++it) {
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
