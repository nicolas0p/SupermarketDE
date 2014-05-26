/*
 * GoodProcessment.cpp
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */

#include "GoodProcessment.h"
#include "ProcessBehavior.h"

/**
 * @brief Calcula o tempo de saída do cliente recebido
 *
 * @details Esta é a implementação do caixa com processamento bom
 *
 * @param Cliente que terá seu tempo de saída calculado
 *
 * @return O horário que esse cliente sairá do supermercado
 */
ProcessBehavior* GoodProcessment::copy() const {
	return new GoodProcessment();
}

int GoodProcessment::cartSizeFactor() {
	return 1;
}

int GoodProcessment::checkPaymentTime() {
	return 10;
}
