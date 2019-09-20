#pragma once
#include <iostream>

using namespace std;

template<class T>
class Pila {

	struct Node {
		T elem;
		Node* next;

		Node(T elem, Node* next = nullptr) : elem(elem), next(next) {}
	};

	Node* _top;
	int   len;

public:
	Pila() : len(0), _top(nullptr) {}
	~Pila() {
		while (_top != nullptr) {
			Node* aux = _top;
			_top = _top->next;
			delete aux;
		}
	}
	int getLen() {
		return len;
	}
	bool isEmpty() {
		return _top == nullptr;
	}
	void push(T elem) {
		_top = new Node(elem, _top);
		++len;
	}
	void pop() {
		if (!isEmpty()) {
			Node* aux = _top;
			_top = _top->next;
			delete aux;
			--len;
		}
	}
	T top() {
		if (!isEmpty()) {
			return _top->elem;
		}
		return 0;
	}
};

