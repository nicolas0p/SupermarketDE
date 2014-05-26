/*
 * Client.cpp
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */

#include <iostream>

#include "../cashier/Cashier.h"
#include "Client.h"
#include "PaymentType.h"
#include "SearchBehavior.h"
#include "../CircularList.h"

Client::Client(const SearchBehavior &searchBehavior, PaymentType paymentType,
		int timeOfArrival, int cartSize, double cartValue):
		_searchBehavior(searchBehavior.copy()), //polimorfismo
		_paymentType(paymentType),
		_cartSize(cartSize),
		_cartValue(cartValue),
		_timeOfArrival(timeOfArrival),
		_timeOfDeparture()
{}


Client::Client(const Client& other) :
	_searchBehavior(other._searchBehavior->copy()),
	_paymentType(other._paymentType),
	_cartSize(other._cartSize),
	_cartValue(other._cartValue),
	_timeOfArrival(other._timeOfArrival),
	_timeOfDeparture(other._timeOfDeparture)
	{}

Client& Client::operator=(Client other) {
	swap(*this, other);
	return *this;
	}

void swap(Client& first, Client& second) {
	using std::swap;
	swap(first._cartSize, second._cartSize);
	swap(first._cartValue, second._cartValue);
	swap(first._paymentType, second._paymentType);
	swap(first._searchBehavior, second._searchBehavior);
	swap(first._timeOfArrival, second._timeOfArrival);
	swap(first._timeOfDeparture, second._timeOfDeparture);
}

Client::~Client() {
	delete _searchBehavior;
}

PaymentType Client::paymentType() const {
	return _paymentType;
}

void Client::timeOfDeparture(int timeOfDeparture) {
	_timeOfDeparture = timeOfDeparture;
}

int Client::timeOfDeparture() const {
	return _timeOfDeparture;
}

int Client::timeOfArrival() const {
	return _timeOfArrival;
}

int Client::cartSize() const {
	return _cartSize;
}

double Client::cartValue() const {
	return _cartValue;
}

void Client::chooseCashier(CircularList<Cashier> &cashiers) {
	Cashier &c = _searchBehavior->search(cashiers);
	c.addClient(*this);
}
