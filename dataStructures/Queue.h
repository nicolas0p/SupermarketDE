/*
 * Queue.h
 *
 *  Created on: May 22, 2014
 *      Author: nicolas
 */

#ifndef LISTACIRCULAR_H_
#define LISTACIRCULAR_H_

#include <stdexcept>

template<typename T>
class Queue {

	struct Node {
		Node(Node *ant, Node *prox, T data) :
				previous(ant), next(prox), data(data) {
		}

		Node(const Node& other) : previous(other.previous), next(other.next) {

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

	Queue() :
			_size(0), head(0), last(0) {
	}
	Queue(const Queue<T>& other) :
			_size(other.size()), head(new Node(other.head)), last(new Node(other.last)) {
	}

	void push_back(const T& dado) {
		Node *novo = new Node(0, 0, dado);
		if (_size == 0) {
			head = last = novo;
		} else {
			last->next = novo;
			last = novo;
		}
		++_size;
	}

	T pop_front() {
		Node *ret = head;
		if (_size == 1) {
			head = last = 0;
		} else {
			head = head->next;
			head->previous = 0;
		}

		T retu = ret->data;

		delete ret;

		--_size;

		return retu;
	}

	T at(int position) const {
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

	T back() const {
		return last->data;
	}

	T front() const {
		return head->data;
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
	Node *last;
};

#endif /* LISTACIRCULAR_H_ */
