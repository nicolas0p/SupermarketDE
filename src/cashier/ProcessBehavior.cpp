/*
 * ProcessBehavior.cpp
 *
 *  Created on: 12/05/2014
 *      Author: arthurhortmannerpen
 */

#include "ProcessBehavior.h"
#include "../client/PaymentType.h"
#include "../client/Client.h"

/**
 * @brief Calcula o tempo de saída do cliente recebido
 *
 * @details Utilizando a implementação do caixa do comportamento de processamento de clientes, calcula o tempo de saída do cliente
 * Existem 3 implementações diferentes. Processamento bom, médio e ruim. O que interfere no tempo de processamento.
 *
 * @param Cliente que terá seu tempo de saída calculado
 *
 * @return O horário que esse cliente sairá do supermercado
 */

int ProcessBehavior::processTime(const Client &client) {
	int time = 0;
	time += client.cartSize() * cartSizeFactor();
	PaymentType payType = client.paymentType();

	if (payType == CHECK) {
		time += checkPaymentTime();
	}

	return time;
}


