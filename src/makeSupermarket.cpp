/*
 * makeSupermarket.cpp
 *
 *  Created on: 17/05/2014
 *      Author: arthurhortmannerpen
 */

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

#include "dataStructures/CircularList.h"
#include "makeSupermarket.h"
#include "cashier/GoodProcessment.h"
#include "cashier/MediumProcessment.h"
#include "cashier/BadProcessment.h"
#include "cashier/Cashier.h"

using namespace std;

Supermarket makeSupermarketConsole() {
	string input;
	string nomeSupermercado;
	int tempoSimulacao;
	int tamanhoMaxFila;
	int tempoMedioNovosClientes;
	int numeroDeCaixas = 0;
	CircularList<Cashier> cashiers;
	cout << "Insira o nome do supermercado:\n";
	getline(cin, nomeSupermercado);

	while (true) {
		cout << "Insira o tempo de simulacao em horas:\n" << endl;
		getline(cin, input);
		stringstream myStream(input);
		if (myStream >> tempoSimulacao && tempoSimulacao > 0)
			break;
		cout << "Numero Invalido. Insira um valor positivo." << endl;
	}

	while (true) {
			cout << "Insira o tempo medio de chegada de clientes em segundos\n" << endl;
			getline(cin, input);
			stringstream myStream(input);
			if (myStream >> tempoMedioNovosClientes && tempoMedioNovosClientes > 0)
				break;
			cout << "Numero Invalido. Insira um valor positivo." << endl;
	}

	while (true) {
		cout << "Insira o tamanho maximo da fila do caixa: \n" << endl;
		getline(cin, input);
		stringstream myStream(input);
		if (myStream >> tamanhoMaxFila && tamanhoMaxFila > 0)
			break;
		cout << "Numero Invalido. Insira um valor positivo." << endl;
	}
	while (true) {
		cout << "Insira o numero de caixas: \n" << endl;
		getline(cin, input);
		stringstream myStream(input);
		if (myStream >> numeroDeCaixas && numeroDeCaixas > 0)
			break;
		cout << "Numero Invalido. Insira um valor positivo." << endl;
	}
	string nomeDoCaixa;
	char eficiencia;
	double salario;
	for (int i = 0; i < numeroDeCaixas; ++i) {
		cout << "Insira o nome do caixa " << i << endl;
		getline(cin, nomeDoCaixa);

		eficiencia = 'a';
		while(eficiencia != 'b' && eficiencia != 'm' && eficiencia != 'r') {
			cout << "Insira a eficiencia do caixa: bom, medio, ou ruim." << endl;
			getline(cin, input);
			eficiencia = tolower(input.at(0));
		}

		while (true) {
			cout << "Insira o salario do caixa: \n" << endl;
			getline(cin, input);
			stringstream myStream(input);
			if (myStream >> salario && salario > 0)
				break;
			cout << "Numero Invalido. Insira um valor positivo." << endl;
		}
		switch (eficiencia) {
		case 'b':
			cashiers.push_back(Cashier(nomeDoCaixa, salario, GoodProcessment(), 0, false));
			break;
		case 'm':
			cashiers.push_back(Cashier(nomeDoCaixa, salario, MediumProcessment(), 0, false));
			break;
		case 'r':
			cashiers.push_back(Cashier(nomeDoCaixa, salario, BadProcessment(), 0, false));
		}
	}
	return Supermarket(nomeSupermercado, cashiers, tempoMedioNovosClientes, tempoSimulacao, tamanhoMaxFila);
}

Supermarket makeSupermarketFile() {
	cout << "hey you";
	string SupermarketName;
	CircularList<Cashier> cashiers;
	int tempoMedioNovosClientes;
	int tempoSimulacao;
	int tamanhoMaxFila = 9;
	ifstream file;
	string input;
	stringstream numStream;
	file.open("config.txt");
	pegaLinhaPulando(file, SupermarketName); // pega o nome
	cout << "leu o nome" << endl;
	pegaLinhaPulando(file, input); // pega o tempo de simulacao
	numStream << input;
	numStream >> tempoSimulacao;
	pegaLinhaPulando(file, input); //pega o tempo medio de novos clientes
	numStream << input;
	numStream >> tempoMedioNovosClientes;
	int numCaixas;
	pegaLinhaPulando(file, input); // pega o numero de caixas
	numStream << input;
	numStream >> numCaixas;
	string nomeCaixa;
	int eficiencia;
	double salario;
	for (int i = 0; i < numCaixas; ++i) {
		pegaLinhaPulando(file, nomeCaixa, ' '); //pega nome do caixa
		pegaLinhaPulando(file, input, ' '); // pega eficiencia do caixa
		numStream << input;
		numStream >> eficiencia;
		pegaLinhaPulando(file, input, ' '); //pega salario
		numStream << input;
		numStream >> salario;
		switch (eficiencia) {
		case 1:
			cashiers.push_back(Cashier(nomeCaixa, salario, GoodProcessment(), 0, false));
			break;
		case 2:
			cashiers.push_back(Cashier(nomeCaixa, salario, MediumProcessment(), 0, false));
			break;
		case 3:
			cashiers.push_back(Cashier(nomeCaixa, salario, BadProcessment(), 0, false));
			break;
		}
	}
	file.close();
	return Supermarket(SupermarketName, cashiers, tempoMedioNovosClientes, tempoSimulacao, tamanhoMaxFila);
}

void pegaLinhaPulando(ifstream &file, string &input) {
	do {
		getline(file, input);
		cout<< input<< endl;
		cout<< input.length() << endl;
	}
	while (input.length() == 0 || input.at(0) == '#');
}

void pegaLinhaPulando(ifstream &file, string &input, char c) {
	do {
		getline(file, input, c);
	}
	while (input.length() == 0 || input.at(0) == '#');
}

