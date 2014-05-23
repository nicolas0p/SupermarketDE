/*
 * SearchSmallQueue.h
 *
 *  Created on: 13/05/2014
 *      Author: arthurhortmannerpen
 */

#ifndef SEARCHSMALLQUEUE_H_
#define SEARCHSMALLQUEUE_H_

#include "SearchBehavior.h"
#include "../dataStructures/CircularList.h"

class SearchSmallQueue : public SearchBehavior {
public:
	SearchBehavior* copy() const;
	Cashier& search(Queue<Cashier> &cashiers) const;
};

#endif /* SEARCHSMALLQUEUE_H_ */
