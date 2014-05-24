/*
 * Main.cpp
 *
 *  Created on: 13/05/2014
 *      Author: arthurhortmannerpen
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "Supermarket.h"
#include "cashier/Cashier.h"
#include "cashier/GoodProcessment.h"
#include "cashier/MediumProcessment.h"
#include "cashier/BadProcessment.h" //                ARRUMAR EXCEPTION GAMBIARRA NA PROCURA DA FILA
#include "makeSupermarket.h"
#include "client/Client.h"
#include "client/PaymentType.h"
#include "client/SearchSmallQueue.h"
#include "CircularList.h"

using namespace std;

int main(int argc, char** argv) {
	CircularList<string> c;

//	c.pop();
	//cout << c.front() << endl;

//	try {
//		cout << "Bem vindo ao Comper Simulator 2000!" << endl;
//		cout << "Escolha uma das opcoes: " << endl;
//		int opcao;
//		while (true) {
//			cout << "1) Ler arquivo de configuracao (o arquivo deve existir com o nome config.txt)." << endl;
//			cout << "2) Configurar o simulador atraves do console." << endl;
//			string input;
//			getline(cin, input);
//			stringstream inputStream(input);
//			if (inputStream >> opcao && (opcao == 1 || opcao == 2)) {
//				break;
//			}
//			cout << "Opcao invalida. Digite 1 ou 2 e tecle enter." << endl;
//		}
//		Supermarket s = (opcao - 1)? makeSupermarketConsole() : makeSupermarketFile();
//		s.run();
//		cout << endl << "Relatorio do supermercado: " << s.name() << endl;
//		cout << "Faturamento total do supermercado: " << s.totalIncome() << endl;
//		cout << "Faturamento por caixa: " << s.averageIncomePerCashier() << endl;
//		cout << "Tempo de espera medio por cliente: " << s.averageWaitingTime() << endl;
//		cout << "Faturamento por caixa:" << endl << s.incomeOfCashiers() << endl;
//		cout << "Lucro por caixa:" << endl << s.profitOfCashiers() << endl;
//		cout << "Clientes perdidos: " << endl << s.lostClients() << endl;
//		cout << "Faturamento perdido: " << endl << s.lostIncome() << endl;
//	} catch (std::ifstream::failure &e) {
//		cout << "Erro ao tentar abrir e ler o arquivo config.txt." << endl;
//	}
}
