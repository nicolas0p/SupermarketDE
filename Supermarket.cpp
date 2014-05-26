/*
 * Supermarket.cpp
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */


#include <sstream>
#include <string>

#include <stdlib.h>
#include <time.h>

#include "Supermarket.h"
#include "cashier/Cashier.h"
#include "client/makeRandomClient.h"
#include "cashier/GoodProcessment.h"
#include "CircularList.h"

using namespace std;


Supermarket::Supermarket(const string& name, const CircularList<Cashier>& cashiers, int averageTimeNewClients, int totalRuntimeHours, int maxQueueSize) :
		_name(name),
		_cashiers(cashiers),
		_currentTime(),
		_timeNextClient(),
		_averageTimeNewClients(averageTimeNewClients),
		_totalRuntime(totalRuntimeHours * 3600),
		_lostClients(),
		_lostIncome(),
		_maxQueueSize(maxQueueSize)
		{}

Supermarket::~Supermarket() {
}

void Supermarket::run() {
	while (_currentTime < _totalRuntime) {
		lookForNextClient();
		updateCashiers();
		_currentTime++;
	}
}

void Supermarket::lookForNextClient() {
	if (_currentTime == _timeNextClient) {
		Client newClient = makeRandomClient(_currentTime);
		try {
			newClient.chooseCashier(_cashiers);
		}
		catch (exception& e) {
			++_lostClients;
			_lostIncome += newClient.cartValue() * 3;
		}
		int randomFactor = rand() % 3 - 1; //valores de -1 a 1
		int total = randomFactor + _averageTimeNewClients;
		if (total < 1) {
			_timeNextClient = _currentTime + 1;
		} else {
			_timeNextClient += total;
		}
	}
}

void Supermarket::updateCashiers() { //eh possivel melhorar isso. tambem deve-se pensar no choosebehavior
	bool call = true;
	for (CircularList<Cashier>::iterator it = _cashiers.begin(); it != _cashiers.end(); ++it) {
		it->update(_currentTime);
		if (it->queueSize() <= _maxQueueSize) {
			call = false;
		}
	}

	if (call) {
		callNewCashier();
	}
}

void Supermarket::callNewCashier() {
	_cashiers.push(Cashier("Extra Cashier", 200, GoodProcessment(), _currentTime, true));
}

string Supermarket::incomeOfCashiers() const {
	stringstream string;
	for (CircularList<Cashier>::const_iterator it = _cashiers.begin(); it != _cashiers.end(); ++it) {
			string << it->id() << "\t\t\t" <<  it->totalIncome() << endl;
	}

	return string.str();
}

string Supermarket::profitOfCashiers() const {
	stringstream string;
	for (CircularList<Cashier>::const_iterator it = _cashiers.begin(); it != _cashiers.end(); ++it) {
		double cashierCost = it->salary() * (_totalRuntime - it->timeOfArrival()) / 756000;
		if (it->overTime()) {
			cashierCost *= 2;
		}
		string << it->id() << "\t\t\t" << it->totalIncome() - cashierCost << endl;
	}
	return string.str();
}

double Supermarket::totalIncome() const {
	double totalIncome = 0;
	for (CircularList<Cashier>::const_iterator it = _cashiers.begin(); it != _cashiers.end(); ++it) {
		totalIncome += it->totalIncome();
	}
	return totalIncome;
}

double Supermarket::averageIncomePerCashier() const {
	return totalIncome() / _cashiers.size();
}

double Supermarket::averageWaitingTime() const {
	double totalWaitingTime = 0;
	int totalClientsServed = 0;
	for (CircularList<Cashier>::const_iterator it = _cashiers.begin(); it != _cashiers.end(); ++it) {
		totalWaitingTime += it->totalWaitingTime();
		totalClientsServed += it->clientsServed();
	}
	return totalWaitingTime / totalClientsServed;
}

string Supermarket::name() const {
	return _name;
}

int Supermarket::lostClients() const {
	return _lostClients;
}

double Supermarket::lostIncome() const {
	return _lostIncome;
}
.clientsServed();
	}
	return totalWaitingTime / totalClientsServed;
}

std::string Supermarket::name() const {
	return _name;
}

int Supermarket::lostClients() const {
	return _lostClients;
}

double Supermarket::lostIncome() const {
	return _lostIncome;
}
