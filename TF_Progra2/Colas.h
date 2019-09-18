#pragma once

template <typename C>
class Cola {

	struct Node {

		Node* next;
		C elem;

		Node(C elem, Node* next = nullptr) : elem(elem), next(next) { }
	};

	Node* cabeza;
	Node* cola;
	int len;

public:
	Cola() : len(0), cabeza(nullptr), cola(nullptr) { }
	~Cola() {
		while (cabeza != nullptr) {
			Node* aux = cabeza;
			cabeza = cabeza->next;
			delete aux;
		}
	}
	bool vacia() {
		return cabeza == nullptr;
	}

	int peek() {
		return cabeza->elem;
	}

	int longitud() {
		return len;
	}

	void agregar(C elem) {
		Node* nuevo = new Node(elem);
		if (cola != nullptr) {
			cola->next = nuevo;
		}
		cola = nuevo;
		++len;
		if (cabeza == nullptr) {
			cabeza = nuevo;
			++len;
		}
	}

	int remover() {
		int elem = head->elem;
		cabeza = cabeza->next;
		if(cabeza == nullptr) {
			tail = nullptr;
		}
		--len;
		return elem;
	}

	void dibujarMun(BufferedGraphics^ bg, Bitmap^ sprite)
	{

		bg->Graphics->DrawImage(sprite, x, y, ancho, alto);

	}
};
