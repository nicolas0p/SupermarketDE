/*
 * SearchBehavior.h
 *
 *  Created on: 09/05/2014
 *      Author: arthurhortmannerpen
 */

#ifndef SEARCHBEHAVIOR_H_
#define SEARCHBEHAVIOR_H_

#include "../dataStructures/CircularList.h"
#include "../cashier/Cashier.h"

class SearchBehavior {
public:
	virtual ~SearchBehavior() {}
	virtual SearchBehavior* copy() const = 0; //para poder criar o Client com (SearchLessItens(), blablabla)
	/**
	 * @brief Metodo polimorfico para a escolha da melhor fila do caixa.
	 *
	 * @details Existem duas implementaacoes para este metodo. A que escolhe a fila com menos pessoas
	 * e a que escolhe a fila com menos produtos.
	 *
	 * @param Vetor de caixas de onde sera escolhido uma fila.
	 */
	virtual Cashier &search(CircularList<Cashier> &cashiers) const = 0;
};

#endif /* SEARCHBEHAVIOR_H_ */
