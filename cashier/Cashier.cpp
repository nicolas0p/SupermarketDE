/*
 * Cashier.cpp
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */

#include <string>
#include <iostream>

#include "Cashier.h"
#include "../client/Client.h"
#include "ProcessBehavior.h"

Cashier::Cashier(std::string id, double salary,
		const ProcessBehavior &processBehavior, int timeOfArrival,
		bool overTime) :
		_id(id), _salary(salary), _queue(Queue<Client>()), _totalWaitingTime(), _clientsServed(), _totalIncome(), _numOfItems(), _processBehavior(
				processBehavior.copy()), _timeOfArrival(timeOfArrival), _overTime(
				overTime) {
}

Cashier::Cashier(const Cashier& other) :
		_id(other._id), _salary(other._salary), _queue(
				Queue<Client>(other._queue)), _totalWaitingTime(
				other._totalWaitingTime), _clientsServed(other._clientsServed), _totalIncome(
				other._totalIncome), _numOfItems(other._numOfItems), _processBehavior(
				other._processBehavior->copy()), _timeOfArrival(
				other._timeOfArrival), _overTime(other._overTime) {
}

Cashier& Cashier::operator=(Cashier other) {
	swap(*this, other);
	return *this;
}

void swap(Cashier& first, Cashier& second) {
	using std::swap;
	swap(first._clientsServed, second._clientsServed);
	swap(first._id, second._id);
	swap(first._processBehavior, second._processBehavior);
	swap(first._queue, second._queue);
	swap(first._salary, second._salary);
	swap(first._totalIncome, second._totalIncome);
	swap(first._numOfItems, second._numOfItems);
	swap(first._totalWaitingTime, second._totalWaitingTime);
	swap(first._timeOfArrival, second._timeOfArrival);
	swap(first._overTime, second._overTime);
}

Cashier::~Cashier() {
	delete _processBehavior;
}

/**
 * @brief Adiciona um cliente a fila de clientes
 * @param Cliente a ser adicionado
 */
void Cashier::addClient(Client &client) {
	int timeOfDeparture = _processBehavior->processTime(client);
	if (_queue.empty()) {
		timeOfDeparture += client.timeOfArrival();
	} else {
		timeOfDeparture += _queue.back().timeOfDeparture();
	}
	client.timeOfDeparture(timeOfDeparture);
	_numOfItems += client.cartSize();
	_queue.push_back(client);
}

/**
 * @brief Retira clientes que devem sair da fila no horário especificado
 * @details Checa se o horário atual é o horário de saída do cliente mais antigo, se sim, o retiro da fila.
 * Somando os valores da compras do cliente e tempo de espera na fila nos acumuladores, para posterior analise.
 * @param Tempo atual do sistema
 */
void Cashier::update(int currentTime) {
	if (_queue.empty())
		return;
	const Client &firstClient = _queue.front();
	if (firstClient.timeOfDeparture() == currentTime) {
		++_clientsServed;
		_totalWaitingTime += currentTime - firstClient.timeOfArrival();
		_totalIncome += firstClient.cartValue();
		_numOfItems -= firstClient.cartSize();
		_queue.pop_front();
	}
}

/**
 * @brief Retorna o total da entrada de dinheiro neste caixa
 */
double Cashier::totalIncome() const {
	return _totalIncome;
}

/**
 * @brief Retorna a media de entrada de dinheiro deste caixa
 * @details A media e calculada dividindo o total de entrada pelos clientes servidos
 */
double Cashier::averageIncome() const {
	return _totalIncome / _clientsServed;
}

/**
 * @brief Retorna a soma do tempo de espera de todos os clientes atendidos por este caixa
 */
int Cashier::totalWaitingTime() const {
	return _totalWaitingTime;
}

/**
 * @brief Retorna o total de clientes servidos
 */
int Cashier::clientsServed() const {
	return _clientsServed;
}

/**
 * @brief Retorna o numero de clientes na fila no momento
 */
int Cashier::queueSize() const {
	return _queue.size();
}

/**
 * @brief Retorna a soma do número de itens de todos os clientes na fila
 */
int Cashier::numOfItems() const {
	return _numOfItems;
}

/**
 * @brief Retorna o id do caixa
 */
std::string Cashier::id() const {
	return _id;
}

/**
 * @brief Retorna o salario do caixa
 */
double Cashier::salary() const {
	return _salary;
}

/**
 * @brief Retorna o horario de chegada do caixa
 */
int Cashier::timeOfArrival() const {
	return _timeOfArrival;
}

/**
 * @brief Retorna se o caixa esta trabalhando hora extra ou nao
 */
bool Cashier::overTime() const {
	return _overTime;
}
