/*
 * GoodProcessment.cpp
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */

#include "GoodProcessment.h"
#include "ProcessBehavior.h"


ProcessBehavior* GoodProcessment::copy() const {
	return new GoodProcessment();
}

int GoodProcessment::cartSizeFactor() {
	return 1;
}

int GoodProcessment::checkPaymentTime() {
	return 10;
}
