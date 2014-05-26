/*
 * makeClient.cpp
 *
 *  Created on: 12/05/2014
 *      Author: arthurhortmannerpen
 */

#include <stdlib.h>
#include <time.h>

#include "makeRandomClient.h"
#include "Client.h"
#include "SearchSmallQueue.h"
#include "SearchLessItems.h"
#include "PaymentType.h"
#include "SearchBehavior.h"

/**
 * @brief Cria um cliente aleatorio, dentro dos padroes de frequencia setados nas especificacao
 */
Client makeRandomClient(int timeOfArrival) {
	int cartSize = rand() % 99 + 2; //tamanho do carrinho, de 2 a 100
	double cartValue = 0;
	for (int i = 0; i < cartSize; ++i) { // calculando o valor de cada item em centavos
		cartValue += rand() % 8901 + 100; //variando entre (100 centavos e 9000 centavos)
	}
	cartValue = cartValue / 100; //transformando o valor em reais, valor de 1 real a 90 reais
	PaymentType payType = MONEY;
	if (rand() % 10 < 2) { //20% de chance de pagamento com cheque
		payType = CHECK;
	}
	if (rand() % 10 < 5) { //50% de chance de procurar a menor fila
		return Client(SearchSmallQueue(), payType, timeOfArrival, cartSize, cartValue);
	}
	return Client(SearchLessItems(), payType, timeOfArrival, cartSize, cartValue);
}
