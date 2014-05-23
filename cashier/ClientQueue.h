/*
 * ClientQueue.h
 *
 *  Created on: 23/05/2014
 *      Author: arthurhortmannerpen
 */

#ifndef CLIENTQUEUE_H_
#define CLIENTQUEUE_H_

#include "Client.h"

class ClientQueue {
	struct Node {
		Node(Node *prox, const Client& client) :
				_next(prox), client(client) {
		}
		Node *_next;
		Client client;
	};

public:
	ClientQueue();
	ClientQueue(const ClientQueue&);
	ClientQueue& operator=(ClientQueue other);
	virtual ~ClientQueue();

	friend void swap(Cashier& first, Cashier& second);

	void push(const Client&);
	void pop();
	Client &front();
	Client &back();
	int size() const;
	bool empty() const;

private:

	int _size;
	Node *_front, *_back;

};

#endif /* CLIENTQUEUE_H_ */
