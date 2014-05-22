/*
 * MediumProcessment.cpp
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */

#include "MediumProcessment.h"
#include "ProcessBehavior.h"

ProcessBehavior* MediumProcessment::copy() const {
	return new MediumProcessment();
}

int MediumProcessment::cartSizeFactor() {
	return 2;
}

int MediumProcessment::checkPaymentTime() {
	return 25;
}
