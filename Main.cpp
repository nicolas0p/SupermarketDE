/*
 * Main.cpp
 *
 *  Created on: 13/05/2014
 *      Author: arthurhortmannerpen
 */


#include "Supermarket.h"
#include "Cashier.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "GoodProcessment.h"
#include "MediumProcessment.h"
#include "BadProcessment.h" //                ARRUMAR EXCEPTION GAMBIARRA NA PROCURA DA FILA
#include "makeSupermarket.h"

using namespace std;

int main(int argc, char** argv) {
	srand(time(NULL));
	Supermarket s = makeSupermarketFile();
	s.run();
	cout << "Supermercado " << s.name() << endl;
	cout << "Faturamento total do supermercado: " << s.totalIncome() << endl;
	cout << "Faturamento por caixa: " << s.averageIncomePerCashier() << endl;
	cout << "Tempo de espera medio por cliente: " << s.averageWaitingTime() << endl;
	cout << "Faturamento por caixa:" << endl << s.incomeOfCashiers() << endl;
	cout << "Lucro por caixa:" << endl << s.profitOfCashiers() << endl;
	cout << "Clientes perdidos: " << endl << s.lostClients() << endl;
	cout << "Faturamento perdido: " << endl << s.lostIncome() << endl;
}
