/*
 * ClientQueue.cpp
 *
 *  Created on: 23/05/2014
 *      Author: arthurhortmannerpen
 */

#include "ClientQueue.h"
#include <stdexcept>

ClientQueue::ClientQueue() :
	_size(0), _front(0), _back(0) {
}

ClientQueue::ClientQueue(const ClientQueue& other) :
	_size(other._size),
	_front(new Node(0, other._front->client))
{
	Node *actual = _front;
	for (Node *it = other._front->_next; it != 0; it = it->_next) {
		Node *aux = new Node(0, it->client);
		actual->_next = aux;
		actual = aux;
	}
	_back = actual;
}

ClientQueue &ClientQueue::operator=(ClientQueue other) {
	swap(*this, other);
	return *this;
}

void swap(ClientQueue &first, ClientQueue &second) {
	using std::swap;
	swap(first._size, second._size);
	swap(first._front, second._front);
	swap(first._back, second._back);
}

ClientQueue::~ClientQueue() {
	Node *aux = _front;
	while (_front) {
		_front = _front->_next;
		delete aux;
		aux = _front;
	}
}

void ClientQueue::push(const Client& client) {
	++_size;
	if (_size == 0) {
		_front = _back = new Node(0, client);
		return;
	}
	_back->_next = new Node(0, client);
	_back = _back->_next;
}

void ClientQueue::pop() {
	if (_size == 0)
		throw std::out_of_range("Empty list!");
	Node *removed = _front;
	_front = removed->_next;
	if (_size == 1) {
		_back = 0;
	}
	--_size;
	delete removed;
}

Client &ClientQueue::front() {
	if (_size == 0)
		throw std::out_of_range("Empty list!");
	return _front->client;
}

Client &ClientQueue::back() {
	if (_size == 0)
		throw std::out_of_range("Empty list!");
	return _back->client;
}

int ClientQueue::size() const {
	return _size;
}

bool ClientQueue::empty() const {
	return _size == 0;
}
