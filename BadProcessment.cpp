/*
 * BadProcessment.cpp
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */

#include "BadProcessment.h"
#include "ProcessBehavior.h"

ProcessBehavior* BadProcessment::copy() const {
	return new BadProcessment();
}

int BadProcessment::cartSizeFactor()
{
	return 4;
}

int BadProcessment::checkPaymentTime()
{
	return 60;
}
