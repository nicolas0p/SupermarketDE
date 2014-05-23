/*
 * Queue.h
 *
 *  Created on: May 22, 2014
 *      Author: nicolas
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdexcept>

template<typename T>
class Queue {

	struct Node {
		Node(Node *ant, Node *prox, T data) :
				_previous(ant), _next(prox), data(data) {
		}

		Node *_previous, *_next;
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
			this->ptr = this->ptr->_next;
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
			_size(0), _head(0), _last(0) {
	}

	Queue(const Queue<T>& other) {

	}

	void push_back(const T& dado) {
		Node *novo = new Node(0, 0, dado);
		if (_size == 0) {
			_head = _last = novo;
		} else {
			_last->_next = novo;
			_last = novo;
		}
		++_size;
	}

	T pop_front() {
		Node *ret = _head;
		if (_size == 1) {
			_head = _last = 0;
		} else {
			_head = _head->_next;
			_head->_previous = 0;
		}

		T retu = ret->data;

		delete ret;

		--_size;

		return retu;
	}

	T at(int position) const {
		Node *atual = _head->_next;
		if (position < 0 || position >= _size)
			throw std::out_of_range("");

		for (int i = 1; i <= position; ++i) {
			atual = atual->_next;
			if (i == position) {
				break;
			}
		}
		return atual->data;
	}

	~Queue() {
		delete _last;
		delete _head;
	}

	T back() const {
		return _last->data;
	}

	T front() const {
		return _head->data;
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
		return iterator(_head->_next);
	}

	iterator end() {
		return iterator(_head);
	}

	const_iterator begin() const {
		return const_iterator(_head->_next);
	}

	const_iterator end() const {
		return const_iterator(_head);
	}

private:
	int _size;
	Node *_head;
	Node *_last;
};

#endif /* QUEUE_H_ */
