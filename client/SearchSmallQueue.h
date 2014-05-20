/*
 * SearchSmallQueue.h
 *
 *  Created on: 13/05/2014
 *      Author: arthurhortmannerpen
 */

#ifndef SEARCHSMALLQUEUE_H_
#define SEARCHSMALLQUEUE_H_

#include "SearchBehavior.h"
#include <vector>

class SearchSmallQueue : public SearchBehavior {
public:
	SearchBehavior* copy() const;
	Cashier& search(std::vector<Cashier> &cashiers) const;
};

#endif /* SEARCHSMALLQUEUE_H_ */
