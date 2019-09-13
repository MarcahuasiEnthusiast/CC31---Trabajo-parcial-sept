#pragma once

// tenemos que modificar estos metodos para que funcione con los enemigos, balas, pilas y colas (esto es solo una base)

class list {

	struct Node {
		Node* next;
		float element;

		Node(float elem, Node* next = nullptr) : element(elem), next(next) { }
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

	void AddFirst(float elem) {
		Node* nuevo = new Node(elem);
		nuevo->next = inicial;
		inicial = nuevo;
		++len;
	}

	void AddLast(float elem) {
		Node* nuevo = new Node(elem);
		nuevo->next = final;
		final = nuevo;
		++len;
	}

	int Find_Elem(float elem) {
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

	void RemoveFirst() {
		if (len > 0) {
			Node* aux = inicial;
			inicial = inicial->next;
			delete aux;
			--len;
		}
	}

	void Add_in_pos(float pos, float elem) {
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

	void Remove_in_pos(float pos, float elem) { 
		if (pos < 0 || pos >= len) return;
		if (pos == 0) {
			RemoveFirst();
		}
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