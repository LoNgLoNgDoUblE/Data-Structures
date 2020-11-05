#pragma once

template<class Typename>
class DoublyLinkedList {
public:
	struct Node {
		Typename value;
		Node * next, *previous;

		Node(Typename _value)
			:value(_value),
			next(nullptr),
			previous(nullptr)
		{}
	};

	DoublyLinkedList()
		:head(nullptr),
		tail(nullptr),
		_size(0)
	{}

	Typename front() {
		if (head == nullptr) {
			throw new std::underflow_error("Container is empty!");
		}
		return head->value;
	}

	Typename back() {
		if (tail == nullptr) {
			throw new std::underflow_error("Container is empty!");
		}
		return tail->value;
	}
	size_t size() {
		return _size;
	}

	void push_back(Typename new_value) {
		Node * tmp = new Node(new_value);
		++_size;
		if (tail == nullptr) {
			head = tail = tmp;
			return;
		}
		tail->next = tmp;
		tmp->previous = tail;
		tail = tmp;
		return;
	}

	void pop_back() {
		if (head == tail) {
			if (tail == nullptr) {
				throw new std::underflow_error("Container is empty!");
				exit(0);
			}
			delete tail;
			head = tail = nullptr;
			--_size;
			return;
		}
		Node * tmp = tail->previous;
		delete tail;
		tail = tmp;
		tmp->next = nullptr;
		--_size;
		return;
	}

	void push_front(Typename new_value) {
		Node * tmp = new Node(new_value);
		++_size;
		if (tail == nullptr) {
			head = tail = tmp;
			return;
		}
		tmp->next = head;
		head->previous = tmp;
		head = tmp;
		return;
	}

	void pop_front() {
		if (head == tail) {
			if (head == nullptr) {
				throw new std::underflow_error("Container is empty!");
			}
			delete head;
			head = tail = nullptr;
			--_size;
			return;
		}
		Node * tmp = head->next;
		delete head;
		head = tmp;
		tmp->previous = nullptr;
		--_size;
		return;
	}

	void insert(Node * previous_node, Typename new_value) {
		if (previous_node->next == tail) {
			push_back(new_value);
			return;
		}
		Node * tmp = new Node(new_value);
		tmp->next = previous_node->next;
		previous_node->next = tmp;
		tmp->previous = previous_node;
		tmp->next->previous = tmp;
		return;
	}

	void erase(Node * previous_node) {
		if (previous_node->next == nullptr) {
			throw new std::underflow_error("List erase iterator outside range!");
		}
		if (previous_node->next == tail) {
			pop_back();
			return;
		}
		Node * tmp = previous_node->next;
		previous_node->next = tmp->next;
		tmp->next->previous = previous_node;
		delete tmp;
		--_size;
		return;
	}

private:
	size_t _size;
	Node * head, *tail;
};
