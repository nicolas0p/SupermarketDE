/*
 * Queue.h
 *
 *  Created on: 24/05/2014
 *      Author: arthurhortmannerpen
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdexcept>

template<typename T>
class Queue {
	struct Node {
		Node(Node *next, const T& element) :
				next(next), element(element) {
		}
		Node *next;
		T element;
	};

public:
	Queue() :
			_size(0), _front(0), _back(0) {
	}

	Queue(const Queue& other) :
			_size(other._size) {
		if (_size == 0) {
			_front = 0;
			_back = 0;
			return;
		}
		_front = new Node(0, other._front->element);
		Node *actual = _front;
		for (Node *it = other._front->next; it != 0; it = it->next) {
			Node *aux = new Node(0, it->element);
			actual->next = aux;
			actual = aux;
		}
		_back = actual;
	}

	Queue& operator=(Queue other) {
		swap(*this, other);
		return *this;
	}

	virtual ~Queue() {
		Node *aux = _front;
		while (_front) {
			_front = _front->next;
			delete aux;
			aux = _front;
		}
	}

	friend void swap(Queue& first, Queue& second) {
		using std::swap;
		swap(first._size, second._size);
		swap(first._front, second._front);
		swap(first._back, second._back);
	}

	void push(const T& element) {
		if (_size++ == 0) {
			_front = _back = new Node(0, element);
			return;
		}
		_back->next = new Node(0, element);
		_back = _back->next;
	}
	void pop() {
		if (_size == 0)
			throw std::out_of_range("Empty list!");
		Node *removed = _front;
		_front = removed->next;
		if (_size == 1) {
			_back = 0;
		}
		--_size;
		delete removed;
	}

	T &front() {
		if (_size == 0)
			throw std::out_of_range("Empty list!");
		return _front->element;
	}
	T &back() {
		if (_size == 0) {
			throw std::out_of_range("Empty list!");
		}
		return _back->element;
	}
	int size() const {
		return _size;
	}
	bool empty() const {
		return _size == 0;
	}

private:
	int _size;
	Node *_front, *_back;

};
#endif /* QUEUE_H_ */
