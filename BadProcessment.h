/*
 * BadProcessment.h
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */

#ifndef BADPROCESSMENT_H_
#define BADPROCESSMENT_H_

#include "ProcessBehavior.h"

class BadProcessment: public ProcessBehavior {
public:
	ProcessBehavior *copy() const;
protected:
	int cartSizeFactor();
	int checkPaymentTime();
};

#endif /* BADPROCESSMENT_H_ */
