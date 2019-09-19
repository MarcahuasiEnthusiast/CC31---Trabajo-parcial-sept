#pragma once

template <typename C>
class Cola : public Municion{

	struct Node : public Objeto {

		Node* next;
		int elem;

		Node(int elem, Node* next = nullptr) : elem(elem), next(next) { }
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

	int getVida() {
		return vida;
	}

	int remover() {
		int elem = cabeza->elem;
		cabeza = cabeza->next;
		if (cabeza == nullptr) {
			cola = nullptr;
		}
		--len;
		return elem;
	}

	void dibujarMun(BufferedGraphics^ bg, Bitmap^ sprite){

		bg->Graphics->DrawImage(sprite, x, y, ancho, alto);

	}

	void setx(int x) { this->x = x; }
	void sety(int y) { this->y = y; }

	int	getx() { return x; }
	int	gety() { return y; }
};

