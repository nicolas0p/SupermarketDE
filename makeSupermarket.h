/*
 * makeSupermarket.h
 *
 *  Created on: 17/05/2014
 *      Author: arthurhortmannerpen
 */

#ifndef MAKESUPERMARKET_H_
#define MAKESUPERMARKET_H_

#include "Supermarket.h"
#include <fstream>
#include <string>

Supermarket makeSupermarketConsole();
Supermarket makeSupermarketFile();
void pegaLinhaPulando(std::ifstream &, std::string &);
void pegaLinhaPulando(std::ifstream &, std::string &, char );
double pegaProximoNumero(std::ifstream &);
double pegaProximoNumero(std::ifstream &, char);

#endif /* MAKESUPERMARKET_H_ */
