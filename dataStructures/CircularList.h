/*
 * ListaCircular.h
 *
 *  Created on: 07/05/2014
 *      Author: nicolas
 */

#ifndef LISTACIRCULAR_H_
#define LISTACIRCULAR_H_

#include <stdexcept>

template<typename T>
class CircularList {

	struct Node {
		Node(Node *ant, Node *prox, T data) :
				previous(ant), next(prox), data(data) {
		}

		Node *previous, *next;
		T data;
	};

	template<typename U>
	class iterator_base {
		Node* ptr;
	public:
		iterator_base(Node* point) :
				ptr(point) {
		}

		iterator_base& operator=(const iterator_base& other) {
			if (!(*this == other))
				this->ptr = other.ptr;
			return *this;
		}

		iterator_base& operator++() {
			this->ptr = this->ptr->next;
			return *this;
		}

		iterator_base& operator++(int) {
			iterator_base other(this);
			++this;
			return other;
		}

		iterator_base& operator--() {
			this->ptr = this->ptr->previous;
			return *this;
		}

		iterator_base& operator--(int) {
			iterator_base other(this);
			--this;
			return other;
		}

		bool operator==(const iterator_base& other) const {
			return this->ptr == other.ptr;
		}

		bool operator!=(const iterator_base& other) const {
			return !(*this == other);
		}

		U& operator*() const {
			return this->ptr->data;
		}

		U* operator->() const {
			return &(this->ptr->data);
		}

	};

public:

	CircularList() :
			_size(0), head(new Node(0, 0, T())) {
		head->next = head->previous = head;
	}

	void push_back(const T& info) {
		Node *novo = new Node(head->previous, head, info);
		head->previous->next = novo;
		head->previous = novo;

		++_size;
	}

	void push_front(const T& dado) {
		head->next = head->next->previous = new Node(head, head->next, dado);
	}

	void push(int position, const T& dado) {
		if (position == 0) {
			push_front(dado);
			return;
		}
		if (position == _size) {
			push_back(dado);
			return;
		}

		Node *atual = head;
		for (int i = 0; i < position; ++i) { //novo vai entrar antes do atual. PosicaoAtual = posicao
				atual = atual->next;
		}

		Node *novo = new Node(atual->previous, atual, dado);
		novo->previous->next = novo;
		novo->next->previous = novo;

		++_size;
	}

	T pop() {
		Node *ret = head->previous;
		ret->previous->next = ret->next;
		ret->next->previous = ret->previous;
		T retu = ret->data;

		delete ret;

		--_size;

		return retu;
	}

	T pop(int posicao) {
		Node *atual = head->next;
		for (int i = 0; i <= posicao; ++i) {
			if (i == posicao) {
				atual->previous->next = atual->next;
				atual->next->previous = atual->previous;
			} else
				atual = atual->next;
		}
		T ret = atual->data;

		delete atual;

		return ret;
	}

	T& at(int position) const {
		Node *atual = head->next;
		if (position < 0 || position >= _size)
			throw std::out_of_range("");

		for (int i = 1; i <= position; ++i) {
			atual = atual->next;
			if (i == position) {
				break;
			}
		}
		return atual->data;
	}

	bool empty() const {
		return _size == 0;
	}

	int size() const {
		return _size;
	}

	typedef iterator_base<T> iterator;
	typedef iterator_base<const T> const_iterator;

	iterator begin() {
		return iterator(head->next);
	}

	iterator end() {
		return iterator(head);
	}

	const_iterator begin() const {
		return const_iterator(head->next);
	}

	const_iterator end() const {
		return const_iterator(head);
	}

private:
	int _size;
	Node *head;

};

#endif /* LISTACIRCULAR_H_ */
