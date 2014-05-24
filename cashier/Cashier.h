/*
 * Cashier.h
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */

#ifndef CASHIER_H_
#define CASHIER_H_

#include <string>
#include <deque>
#include "ClientQueue.h"

class Client;
class ProcessBehavior;

class Cashier {
public:
	Cashier(std::string id, double salary,
			const ProcessBehavior &processBehavior, int timeOfArrival, bool overTime);
	Cashier(const Cashier& other);
	Cashier& operator=(Cashier other);
	friend void swap(Cashier& first, Cashier& second);
	~Cashier();
	void addClient(Client &client);
	void update(int currentTime);
	double totalIncome() const;
	double averageIncome() const;
	int totalWaitingTime() const;
	int clientsServed() const;
	int queueSize() const;
	int numOfItems() const;
	std::string id() const;
	double salary() const;
	int timeOfArrival() const;
	bool overTime() const;

private:
	std::string _id;
	double _salary;
	ClientQueue _queue;
	int _totalWaitingTime;
	int _clientsServed;
	double _totalIncome;
	int _numOfItems;
	ProcessBehavior *_processBehavior;
	int _timeOfArrival;
	bool _overTime;
};

#endif /* CASHIER_H_ */
