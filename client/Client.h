/*
 * Client.h
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "PaymentType.h"
#include "../dataStructures/CircularList.h"

class SearchBehavior;
class Cashier;

class Client {
public:
	Client(const SearchBehavior &searchBehavior, PaymentType paymentType,
			int timeOfArrival, int cartSize, double cartValue);
	Client(const Client& other);
	Client& operator=(Client other);
	friend void swap(Client& first, Client& second);
	virtual ~Client();
	int cartSize() const;
	double cartValue() const;
	PaymentType paymentType() const;
	int timeOfDeparture() const;
	int timeOfArrival() const;
	void timeOfDeparture(int timeOfDeparture);
	void chooseCashier(CircularList<Cashier> &cashiers);

	Client();

private:
	SearchBehavior *_searchBehavior;
	PaymentType _paymentType;
	int _cartSize;
	double _cartValue;
	int _timeOfArrival;
	int _timeOfDeparture;
};

#endif /* CLIENT_H_ */
