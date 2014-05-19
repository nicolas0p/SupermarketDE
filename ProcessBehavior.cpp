/*
 * ProcessBehavior.cpp
 *
 *  Created on: 12/05/2014
 *      Author: arthurhortmannerpen
 */

#include "ProcessBehavior.h"
#include "PaymentType.h"
#include "Client.h"

int ProcessBehavior::processTime(const Client &client) {
	int time = 0;
	time += client.cartSize() * cartSizeFactor();
	PaymentType payType = client.paymentType();

	if (payType == CHECK) {
		time += checkPaymentTime();
	}

	return time;
}


