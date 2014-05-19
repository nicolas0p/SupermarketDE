/*
 * MediumProcessment.h
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */

#ifndef MEDIUMPROCESSMENT_H_
#define MEDIUMPROCESSMENT_H_

#include "ProcessBehavior.h"

class MediumProcessment : public ProcessBehavior {
public:
	ProcessBehavior *copy() const;
protected:
	int cartSizeFactor();
	int checkPaymentTime();
};

#endif
