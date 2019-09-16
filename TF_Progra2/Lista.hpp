#pragma once


#include <iostream>
#include <functional>

using namespace std;

// tenemos que modificar estos metodos para que funcione con los enemigos, balas, pilas y colas (esto es solo una base)
template <typename T>
class list {

	struct Node {
		Node* next;
		T element;

		Node(T elem, Node* next = nullptr) : element(elem), next(next) { }
	};

	Node* inicial;
	Node* final;
	int len;

public:
	list() : inicial(nullptr), final(nullptr), len(0) { }
	~list() {
		while (inicial != nullptr) {
			Node* aux = inicial;
			inicial = inicial->next;
			delete aux;
		}
	}

	void agregaInicial(T elem) {
		Node* nuevo = new Node(elem);
		nuevo->next = inicial;
		inicial = nuevo;
		++len;
	}

	void agregaFinal(T elem) {
		Node* nuevo = new Node(elem);
		nuevo->next = final;
		final = nuevo;
		++len;
	}

	int buscar(T elem) {
		Node* aux = inicial;
		int pos = 0;
		while (aux != nullptr) {
			if (aux->element == elem) {
				return pos;
			}
			aux = aux->next;
			pos++;
		}
		return -1;
	}


	T obtenerPos(int pos) {
		if (pos >= 0 && pos < len) {
			Node* aux = inicial;
			for (int i = 0; i < pos; i++) {
				aux = aux->next;
			}
			return aux->element;
		}
	}


	int longitud() {
		return len;
	}


	void eliminarInicial() {
		if (len > 0) {
			Node* aux = inicial;
			inicial = inicial->next;
			delete aux;
			--len;
		}
	}

	void agregaPos(int pos, T elem) {
		if (pos < 0 || pos >= len) return;
		if (pos == 0) {
			AddFirst(elem);
		}
		else {
			Node* aux = inicial;
			for (int i = 0; i < pos - 1; ++i) {
				aux = aux->next;
			}
			Node* nuevo = new Node(elem);
			nuevo->next = aux->next;
			aux->next = nuevo;
			++len;
		}
	}

	void eliminaPos(int pos) {
		if (pos < 0 || pos >= len) return;
		/*if (pos == 0) {
			eliminarInicial();
		}*/
		else {
			Node* aux = inicial;
			for (int i = 0; i < pos - 1; ++i) {
				aux = aux->next;
			}
			Node* aux2 = aux->next;
			aux->next = aux2->next;
			delete aux2;
			--len;
		}
	}
};
