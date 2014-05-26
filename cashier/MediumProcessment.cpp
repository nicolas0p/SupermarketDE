/*
 * MediumProcessment.cpp
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */

#include "MediumProcessment.h"
#include "ProcessBehavior.h"

/**
 * @brief Calcula o tempo de saída do cliente recebido
 *
 * @details Esta é a implementação do caixa com processamento médio
 *
 * @param Cliente que terá seu tempo de saída calculado
 *
 * @return O horário que esse cliente sairá do supermercado
 */
ProcessBehavior* MediumProcessment::copy() const {
	return new MediumProcessment();
}

int MediumProcessment::cartSizeFactor() {
	return 2;
}

int MediumProcessment::checkPaymentTime() {
	return 25;
}
