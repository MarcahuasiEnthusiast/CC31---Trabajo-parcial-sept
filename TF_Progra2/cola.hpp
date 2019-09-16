#include <iostream>

template <typename C>
class cola {

	struct Node {

		Node* next;
		C elem;

		Node(C elem, Node* next = nullptr) 
			: elem(elem), next(next){ }
	};

	Node* head;
	Node* tail;

public:
	cola() { }

	C peek() {
		return head->elem;
	}
};