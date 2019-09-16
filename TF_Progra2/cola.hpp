#include <iostream>

template <typename C>
class cola {

	struct Node {
		Node* next;
		C elem;

		Node(C elem) : next(next) { }
	};

	Node* head;
	Node* tail;

public:

	bool is_Empty() {
		return head == nullptr;
	}

	void add(C elem) {
		Node* node = new Node(elem);
		if (tail != nullptr) {
			tail->next = node;
		}
		tail = node;
		if (head == nullptr) {
			head = node;
		}
	}

	int remove() {
		C elem = head->elem;
		head = head->next;
		if (head == nullptr) {
			tail = nullptr;
		}
		return elem;
	}

};