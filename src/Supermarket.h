/*
 * Supermarket.h
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */

#ifndef SUPERMARKET_H_
#define SUPERMARKET_H_

#include <vector>
#include <string>

#include "cashier/Cashier.h"
#include "dataStructures/CircularList.h"

class Supermarket {
public:
	Supermarket(const std::string&, const CircularList<Cashier>&, int averageTimeNewClients, int totalRuntimeHours, int maxQueueSize);
	virtual ~Supermarket();
	void run();
	std::string incomeOfCashiers() const;
	std::string profitOfCashiers() const;
	double averageIncomePerCashier() const;
	double totalIncome() const;
	double averageWaitingTime() const;
	std::string name() const;
	int lostClients() const;
	double lostIncome() const;

private:
	void lookForNextClient(); //verifica se ha um novo cliente, se tiver, seta o tempo para o proximo cliente
	void updateCashiers();
	void callNewCashier();
	std::string _name;
	CircularList<Cashier> _cashiers;
	int _currentTime;
	int _timeNextClient;
	int _averageTimeNewClients; // tempo medio de chegada de clientes
	int _totalRuntime;
	int _lostClients;
	double _lostIncome;
	int _maxQueueSize;
};

#endif /* SUPERMARKET_H_ */
