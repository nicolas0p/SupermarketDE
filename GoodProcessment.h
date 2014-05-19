/*
 * GoodProcessment.h
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */

#ifndef GOODPROCESSMENT_H_
#define GOODPROCESSMENT_H_

#include "ProcessBehavior.h"

class GoodProcessment : public ProcessBehavior {
public:
	ProcessBehavior *copy() const;
protected:
	int cartSizeFactor();
	int checkPaymentTime();
};

#endif /* GOODPROCESSMENT_H_ */
