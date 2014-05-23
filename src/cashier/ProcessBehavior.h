/*
 * ProcessBehavior.h
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */

#ifndef PROCESSBEHAVIOR_H_
#define PROCESSBEHAVIOR_H_

class Client;

class ProcessBehavior {
public:
	virtual ~ProcessBehavior() {}
	int processTime(const Client &client);
	virtual ProcessBehavior *copy() const = 0;
protected:
	virtual int cartSizeFactor() = 0;
	virtual int checkPaymentTime() = 0;
};

#endif
