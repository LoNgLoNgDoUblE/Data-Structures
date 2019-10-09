#pragma once

template<class Typename>
class SinglyLinkedListStack {
public:
	struct Node {
		Typename value;
		Node * next;

		Node(Typename _value)
			:value(_value),
			next(nullptr)
		{}
	};

	SinglyLinkedListStack()
		:head(nullptr)
	{}

	bool empty() {
		return head == nullptr;
	}

	Typename top() {
		if (head == nullptr) {
			throw new std::underflow_error("Container is empty!");
		}
		return head->value;
	}

	void push(Typename new_value) {
		Node * tmp = new Node(new_value);
		tmp->next = head;
		head = tmp;
		return;
	}

	void pop() {
		if (head == nullptr) {
			throw new std::underflow_error("Container is empty!");
		}
		if (head->next == nullptr) {
			head = nullptr;
			return;
		}
		Node * tmp = head->next;
		delete head;
		head = tmp;
		return;
	}

private:
	Node * head;
};
