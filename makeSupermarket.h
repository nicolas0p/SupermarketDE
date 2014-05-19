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

#endif /* MAKESUPERMARKET_H_ */
