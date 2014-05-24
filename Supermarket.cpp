/*
 * Supermarket.cpp
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */


#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "cashier/Cashier.h"
#include "client/makeRandomClient.h"
#include "Supermarket.h"
#include "cashier/GoodProcessment.h"


Supermarket::Supermarket(const std::string& name, const std::vector<Cashier>& cashiers, int averageTimeNewClients, int totalRuntimeHours, int maxQueueSize) :
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
		catch (std::exception& e) {
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
	for (unsigned int i = 0; i < _cashiers.size(); ++i) {
		_cashiers.at(i).update(_currentTime);
		if (_cashiers.at(i).queueSize() <= _maxQueueSize) {
			call = false;
		}
	}
	if (call) {
		callNewCashier();
	}
}

void Supermarket::callNewCashier() {
	_cashiers.push_back(Cashier("Extra Cashier", 200, GoodProcessment(), _currentTime, true));
}

//std::string Supermarket::incomeOfCashiers() const {
//	std::stringstream string;
//	for (unsigned int i = 0; i < _cashiers.size(); ++i) {
//		string << _cashiers.at(i).id() << "\t\t\t" <<  _cashiers.at(i).totalIncome() << std::endl;
//	}
//	return string.str();
//}

std::string Supermarket::incomeOfCashiers() const {
	std::stringstream string;
	for (unsigned int i = 0; i < _cashiers.size(); ++i) {
		string << _cashiers.at(i).id() << "\t\t\t" <<  _cashiers.at(i).totalIncome() << std::endl;
	}
	return string.str();
}

std::string Supermarket::profitOfCashiers() const {
	std::stringstream string;
	for (std::vector<Cashier>::const_iterator cashier = _cashiers.begin(); cashier != _cashiers.end(); ++cashier) {
		double cashierCost = cashier->salary() * (_totalRuntime - cashier->timeOfArrival()) / 756000;
		if (cashier->overTime()) {
			cashierCost *= 2;
		}
		string << cashier->id() << "\t\t\t" << cashier->totalIncome() - cashierCost << std::endl;
	}
	return string.str();
}

double Supermarket::totalIncome() const {
	double totalIncome = 0;
	for (unsigned int i = 0; i < _cashiers.size(); ++i) {
		totalIncome += _cashiers.at(i).totalIncome();
	}
	return totalIncome;
}

double Supermarket::averageIncomePerCashier() const {
	return totalIncome() / _cashiers.size();
}

double Supermarket::averageWaitingTime() const {
	double totalWaitingTime = 0;
	int totalClientsServed = 0;
	for (unsigned int i = 0; i < _cashiers.size(); ++i) {
		totalWaitingTime += _cashiers.at(i).totalWaitingTime();
		totalClientsServed += _cashiers.at(i).clientsServed();
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
