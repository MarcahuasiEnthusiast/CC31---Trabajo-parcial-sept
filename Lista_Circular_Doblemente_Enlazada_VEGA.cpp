#include <iostream>

using namespace std;

class List {
	struct nodo {
		int dato;
		nodo* siguiente;
		nodo* atras;

		nodo(int dato, nodo* siguiente = nullptr, nodo* atras = nullptr) : dato(dato), siguiente(siguiente), atras(atras) {}
		nodo() : siguiente(nullptr), atras(nullptr) {}
	}; nodo* primero; nodo* ultimo; int len;

public:

	List() : primero(nullptr), ultimo(nullptr) { len = 0; }
	~List() {
		while (primero != nullptr) {
			nodo* aux = primero;
			primero = primero->siguiente;
			delete aux;
		}
	}

	int primerElemento() {
		return primero->dato;
	}

	int ultimoElemento() {
		return ultimo->dato;
	}

	int longitudDeLista() {
		return len;
	}

	void insertarNodoAlInicio() {
		nodo* nuevo = new nodo();
		cout << "Ingresar dato que contendra el nuevo nodo: ";
		cin >> nuevo->dato;

		if (ultimo == NULL) {
			primero = nuevo;
			ultimo = nuevo;
			primero->siguiente = primero;
			primero->atras = ultimo;
			len++;
		}
		else {
			primero->atras = nuevo;
			nuevo->atras = ultimo;
			nuevo->siguiente = primero;
			primero = nuevo;
			ultimo->siguiente = nuevo;
			len++;
		}
		cout << "\Nodo Ingresado\n\n";
	}

	void insertarNodoAlFinal() {
		nodo* nuevo = new nodo();
		cout << "Ingresar dato que contendra el nuevo nodo: ";
		cin >> nuevo->dato;

		if (primero == NULL) {
			primero = nuevo;
			ultimo = nuevo;
			primero->siguiente = primero;
			primero->atras = ultimo;
			len++;
		}
		else {
			ultimo->siguiente = nuevo;
			nuevo->atras = ultimo;
			nuevo->siguiente = primero;
			ultimo = nuevo;
			primero->atras = ultimo;
			len++;
		}
		cout << "\Nodo Ingresado\n\n";
	}

	void insertarNodoEnPos() {
		float pos; float elem;
		cout << "Ingrese posicion: "; cin >> pos;
		cout << "Ingrese elemento: "; cin >> elem;
		if (pos < 0 || pos >= len) return;
		else {
			nodo* aux = primero;
			for (int i = 0; i < pos - 1; ++i) {
				aux = aux->siguiente;
			}
			nodo* nuevo = new nodo(elem);
			nuevo->siguiente = aux->siguiente;
			aux->siguiente = nuevo;
			++len;
		}
	}

	void Mostrar() {
		nodo* actual = new nodo();
		actual = primero;
		if (primero != NULL) {

			do {
				cout << "\n " << actual->dato;
				actual = actual->siguiente;
			} while (actual != primero);
			cout << endl;
		}
		else {
			cout << "\n La lista se encuentra vacia \n\n";
			cout << endl;
		}
	}

	void MostrarAlReves() {
		nodo* actual = new nodo();
		actual = ultimo;
		if (primero != NULL) {

			do {
				cout << "\n " << actual->dato;
				actual = actual->atras;
			} while (actual != ultimo);
		}
		else {
			cout << "\n La lista se encuentra vacia \n\n";
		}
	}

	void buscarNodo() {
		nodo* actual = new nodo();
		actual = primero;
		bool encontrado = false;
		int nodoBuscado = 0;
		cout << "Ingrese el dato del nodo a buscar: ";
		cin >> nodoBuscado;
		if (primero != NULL) {

			do {
				if (actual->dato == nodoBuscado) {
					cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado\n\n";
					encontrado = true;
				}
				actual = actual->siguiente;
			} while (actual != primero && encontrado != true);
			if (!encontrado) {
				cout << "\n Nodo no Encontrado \n\n";
			}
		}
		else {
			cout << "\n La lista se encuentra vacia \n\n";
		}
	}

	void modificarNodo() {
		nodo* actual = new nodo();
		actual = primero;
		bool encontrado = false;
		int nodoBuscado = 0;
		cout << "Ingrese el dato del nodo a buscar para modificar: ";
		cin >> nodoBuscado;
		if (primero != NULL) {

			do {
				if (actual->dato == nodoBuscado) {
					cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado\n\n";

					cout << "\n Ingrese el nuevo dato para este Nodo: ";
					cin >> actual->dato;
					cout << "\n Nodo Modificado\n\n";

					encontrado = true;
				}
				actual = actual->siguiente;
			} while (actual != primero && encontrado != true);
			if (!encontrado) {
				cout << "\n Nodo no Encontrado \n\n";
			}
		}
		else {
			cout << "\n La lista se encuentra vacia \n\n";
		}
	}

	void eliminarNodo() {
		nodo* actual = new nodo();
		actual = primero;
		nodo* anterior = new nodo();
		anterior = NULL;
		bool encontrado = false;
		int nodoBuscado = 0;
		cout << "Ingrese el dato del nodo a buscar para Eliminar: ";
		cin >> nodoBuscado;
		if (primero != NULL) {

			do {
				if (actual->dato == nodoBuscado) {
					cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado\n\n";
					if (actual == primero) {
						primero = primero->siguiente;
						primero->atras = ultimo;
						ultimo->siguiente = primero;
						len--;
					}
					else if (actual == ultimo) {
						ultimo = anterior;
						ultimo->siguiente = primero;
						primero->atras = ultimo;
						len--;
					}
					else {
						anterior->siguiente = actual->siguiente;
						actual->siguiente->atras = anterior;
						len--;
					}
					cout << "\n Nodo Eliminado\n\n";
					encontrado = true;
				}
				anterior = actual;
				actual = actual->siguiente;
			} while (actual != primero && encontrado != true);
			if (!encontrado) {
				cout << "\n Nodo no Encontrado \n\n";
			}
		}
		else {
			cout << "\n La lista se encuentra vacia \n\n";
		}
	}

};

int main() {

	List* lista = new List();

	cout << lista->longitudDeLista() << endl;

	lista->insertarNodoAlFinal();
	lista->insertarNodoAlFinal();
	lista->insertarNodoAlFinal();
	lista->insertarNodoAlFinal();
	
	lista->Mostrar();

	lista->insertarNodoEnPos();

	lista->Mostrar();


	system("pause");
	// primero = null		ultimo = null
	// lista circular doblemente enlazada
}