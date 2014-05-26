/*
 * BadProcessment.cpp
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */

#include "BadProcessment.h"
#include "ProcessBehavior.h"

/**
 * @brief Calcula o tempo de saída do cliente recebido
 *
 * @details Esta é a implementação do caixa com processamento ruim
 *
 * @param Cliente que terá seu tempo de saída calculado
 *
 * @return O horário que esse cliente sairá do supermercado
 */
ProcessBehavior* BadProcessment::copy() const {
	return new BadProcessment();
}

int BadProcessment::cartSizeFactor()
{
	return 4;
}

int BadProcessment::checkPaymentTime()
{
	return 60;
}
