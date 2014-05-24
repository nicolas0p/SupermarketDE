/*
 * CircularList.h
 *
 *  Created on: 24/05/2014
 *      Author: arthurhortmannerpen
 */

#ifndef CIRCULARLIST_H_
#define CIRCULARLIST_H_

#include <stdexcept>

template<typename T>
class CircularList {

	struct Node {
		Node(Node *prev, Node *next, const T& element) :
				prev(prev), next(next), element(element) {
		}
		Node *prev, *next;
		T element;
	};

public:

	CircularList() :
			_size(0), _head(0) {
	}

	CircularList(const CircularList& other) :
			_size(other._size) {
		if (_size == 0) {
			_head = 0;
			return;
		}
		_head = new Node(0, 0, other._head->element);
		Node *actual = _head;
		int i = 0;
		for (Node *it = other._head->next; i < other.size() - 1; it = it->next, ++i) {
			Node *aux = new Node(0, 0, it->element);
			actual->next = aux;
			aux->prev = actual;
			actual = aux;
		}
		actual->next = _head;
		_head->prev = actual;
	}

	CircularList &operator=(CircularList other) {
		swap(*this, other);
		return *this;
	}

	~CircularList() {
		Node *aux = _head;
		for (int i = 0; i < _size; ++i) {
			_head = _head->next;
			delete aux;
			aux = _head;
		}
	}

	friend void swap(CircularList &first, CircularList &second) {
		using std::swap;
		swap(first._size, second._size);
		swap(first._head, second._head);
	}

	void push(const T &element) {
		if (_size == 0) {
			_head = new Node(0, 0, element);
			_head->prev = _head;
			_head->next = _head;
			++_size;
			return;
		}
		if (_size == 1) {
			_head->next = new Node(_head, _head, element);
			_head->prev = _head->next;
			++_size;
			return;
		}
		Node *aux = new Node(0, 0, element);
		_head->next->prev = aux;
		aux->next = _head->next;
		aux->prev = _head;
		_head->next = aux;
		++_size;
	}

	void pop() {
		if (_size == 0)
			throw std::out_of_range("Empty list!");
		Node *removed = _head;
		if (_size == 1) {
			_head = 0;
			--_size;
			delete removed;
			return;
		}
		_head->next->prev = _head->prev;
		_head->prev->next = _head->next;
		_head = _head->next;
		--_size;
		delete removed;
	}

	T &front() {
		if (_size == 0)
			throw std::out_of_range("Empty List!");
		return _head->element;
	}

	int size() const {
		return _size;
	}

	bool empty() const {
		return _size == 0;
	}

private:
	int _size;
	Node *_head;
};

#endif /* CIRCULARLIST_H_ */
