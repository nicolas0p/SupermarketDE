/*
 * Supermarket.h
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */

#ifndef SUPERMARKET_H_
#define SUPERMARKET_H_

#include <vector>
#include "cashier/Cashier.h"
#include <string>

//implementar rule of three
class Supermarket {
public:
	Supermarket(const std::string&, const std::vector<Cashier>&, int averageTimeNewClients, int totalRuntimeHours, int maxQueueSize);
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
	std::vector<Cashier> _cashiers;
	int _currentTime;
	int _timeNextClient;
	int _averageTimeNewClients; // tempo medio de chegada de clientes
	int _totalRuntime;
	int _lostClients;
	double _lostIncome;
	int _maxQueueSize;
};

#endif /* SUPERMARKET_H_ */


// TODO:
//ENTRADA DE DADOS: arquivo de configuracao

//lucro por caixa: desconta-se o salario do caixa no periodo compreedido de simulacao. Como guardar esse tempo?

//numero de clientes que desistiram por filas longas
// cliente abandonar carrinho quando todas as filas tiverem tamanho > 10
//faturamento que deixou de ser realizado pela desistencia desses clientes

// chamar mais caixa para trabalhar se o tamanho
