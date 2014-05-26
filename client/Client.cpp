/*
 * Client.cpp
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */

#include <vector>
#include <iostream>

#include "../cashier/Cashier.h"
#include "Client.h"
#include "PaymentType.h"
#include "SearchBehavior.h"


Client::Client(const SearchBehavior &searchBehavior, PaymentType paymentType,
		int timeOfArrival, int cartSize, double cartValue):
		_searchBehavior(searchBehavior.copy()),
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

/**
 * @brief Retorna o tipo de pagamento do cliente, que pode ser cheque ou dinheiro
 */
PaymentType Client::paymentType() const {
	return _paymentType;
}

/**
 * @brief Iguala o tempo de saida recebido com o atributo tempo de saida
 */
void Client::timeOfDeparture(int timeOfDeparture) {
	_timeOfDeparture = timeOfDeparture;
}

/**
 * @brief Retorna o tempo de saida do cliente
 */
int Client::timeOfDeparture() const {
	return _timeOfDeparture;
}

/**
 * @brief Retorna o tempo de chegada do cliente
 */
int Client::timeOfArrival() const {
	return _timeOfArrival;
}

/**
 * @brief Retorna o numero de itens dentro do carrinho do cliente
 */
int Client::cartSize() const {
	return _cartSize;
}

/**
 * @brief Retorna o valor total dos itens no carrinho
 */
double Client::cartValue() const {
	return _cartValue;
}

/**
 * @brief Escolhe a melhor fila do caixa baseado no padrao de escolha do cliente
 * @param Vetor de caixas de onde sera escolhido um
 */
void Client::chooseCashier(Queue<Cashier> &cashiers) {
	Cashier &c = _searchBehavior->search(cashiers);
	c.addClient(*this);
}
