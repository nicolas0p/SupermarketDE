/*
 * Supermarket.cpp
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */

#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "cashier/Cashier.h"
#include "client/makeRandomClient.h"
#include "Supermarket.h"
#include "cashier/GoodProcessment.h"
#include "dataStructures/CircularList.h"


Supermarket::Supermarket(const std::string& name, const Queue<Cashier>& cashiers, int averageTimeNewClients, int totalRuntimeHours, int maxQueueSize) :
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

Supermarket::~Supermarket() {}

/**
 * @brief loop de funcionamento. Rodara o programa ate o tempo atual ser igual ao tempo total de simulacao
 */
void Supermarket::run() {
	while (_currentTime < _totalRuntime) {
		lookForNextClient();
		updateCashiers();
		_currentTime++;
	}
}

/**
 * @brief Pesquisa se um novo cliente entrara no supermercado no tempo atual.
 *
 * @details Alem de criar um novo cliente, se esta no momento certo, o metodo tambem prepara o proximo tempo de um cliente
 * entrar no supermercado
 */
void Supermarket::lookForNextClient() {
	if (_currentTime == _timeNextClient) {
		Client newClient = makeRandomClient(_currentTime);
		try {
			newClient.chooseCashier(_cashiers);
		}
		catch (int e) {
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

/**
 * @brief Atualiza todos os caixas com o tempo atual. Adicionando tambem um caixa extra, caso todas as filas estejam "cheias"
 *
 * @details Adiciona um caixa extra caso todas as filas estejam com mais clientes que o maximo setado para as filas
 */
void Supermarket::updateCashiers() {
	for (int i = 0; i < _cashiers.size(); ++i) {
		_cashiers.at(i).update(_currentTime);
	}
	for (int i = 0; i < _cashiers.size(); ++i) {
		if (_cashiers.at(i).queueSize() <= _maxQueueSize) {
			return;
		}
	}
	callNewCashier();
}

/**
 * @brief Cria um caixa extra
 *
 * @details Cria um caixa extra com salario 200, processamento bom e trabalhando hora extra
 */
void Supermarket::callNewCashier() {
	_cashiers.push_back(Cashier("Extra Cashier", 200, GoodProcessment(), _currentTime, true));
}

/**
 * @brief Cria texto que representa o total de dinheiro que aquele caixa recebeu de seus clientes
 *
 * @return String com nome do caixa + o total de dinheiro recebido pelo caixa
 */
std::string Supermarket::incomeOfCashiers() const {
	std::stringstream string;
	for (int i = 0; i < _cashiers.size(); ++i) {
		string << _cashiers.at(i).id() << "\t\t\tR$ " << _cashiers.at(i).totalIncome() << std::endl;
	}
	return string.str();
}

/**
 * @brief Cria texto que representa o lucro do caixa no mes
 *
 * @details lucro do caixa = salarioDoCaixa * tempoDeTrabalho / mes
 *
 * @return String com nome do caixa + lucro do caixa
 */
std::string Supermarket::profitOfCashiers() const {
	std::stringstream string;
	for (Queue<Cashier>::const_iterator cashier = _cashiers.begin(); cashier != _cashiers.end(); ++cashier) {
		double cashierCost = cashier->salary() * (_totalRuntime - cashier->timeOfArrival()) / 756000;
		if (cashier->overTime()) {
			cashierCost *= 2;
		}
		string << cashier->id() << "\t\t\t" << cashier->totalIncome() - cashierCost << std::endl;
	}
	return string.str();
}

/**
 * @brief Calcula o total do dinheiro recebido por todos os caixas
 *
 * @return A soma do dinheiro recebido por todos os caixas
 */
double Supermarket::totalIncome() const {
	double totalIncome = 0;
	for (int i = 0; i < _cashiers.size(); ++i) {
		totalIncome += _cashiers.at(i).totalIncome();
	}
	return totalIncome;
}

/**
 * @brief Calcula a media do dinheiro recebido por cada caixa
 * @details Divide o dinheiro recebido total pelo numero de caixas
 * @return A media recebida de dinheiro por caixa
 */
double Supermarket::averageIncomePerCashier() const {
	return totalIncome() / _cashiers.size();
}

/**
 * @brief Calcula o tempo medio de espera por cliente
 * @return A media do tempo de espera por cliente
 */
double Supermarket::averageWaitingTime() const {
	double totalWaitingTime = 0;
	int totalClientsServed = 0;
	for (int i = 0; i < _cashiers.size(); ++i) {
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
