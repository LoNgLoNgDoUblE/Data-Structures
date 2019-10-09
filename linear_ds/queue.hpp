#pragma once

template<class Typename>
class SinglyLinkedListQueue {
public:
	struct Node {
		Typename value;
		Node * next;

		Node(Typename _value)
			:value(_value),
			next(nullptr)
		{}
	};

	SinglyLinkedListQueue()
		:head(nullptr),
		tail(nullptr),
		_size(0)
	{}

	size_t size() {
		return _size;
	}

	bool empty() {
		return !_size;
	}

	Typename front() {
		if (tail == nullptr) {
			throw new std::underflow_error("Container is empty!");
		}
		return head->value;
	}

	void push(Typename new_value) {
		Node * tmp = new Node(new_value);
		if (tail == nullptr) {
			head = tail = tmp;
			++_size;
			return;
		}
		tail->next = tmp;
		tail = tmp;
		++_size;
		return;
	}

	void pop() {
		if (tail == nullptr) {
			throw new std::underflow_error("Container is empty!");
		}
		if (head == tail) {
			head = tail = nullptr;
			--_size;
			return;
		}
		Node * tmp = head;
		head = head->next;
		delete tmp;
		--_size;
		return;
	}

private:
	size_t _size;
	Node * head, *tail;
};

template <class Typename>
class CyclicStaticArrayQueue {
public:
    CyclicStaticArrayQueue(size_t max_size)
        :container(new int[max_size]),
         _max_size(max_size),
         _size(0),
         begin(0),
         end(0)
    {}

    size_t size() {
        return _size;
    }

    bool empty() {
        return !_size;
    }

    Typename front() {
        if (!_size) {
            throw new std::underflow_error("Container is empty!");
        }
        return container[begin];
    }

    void push(Typename new_value) {
        if (_size == _max_size) {
            throw new std::underflow_error("Container is full!");
        }
        if (!_size) {
            container[begin] = new_value;
            ++end;
            ++_size;
            return;
        }
        container[end++]= new_value;
        end %= _max_size;
        ++_size;
        return;
    }

    void pop() {
        if (!_size) {
            throw new std::underflow_error("Container is empty!");
        }
        ++begin;
        begin %= _max_size;
        --_size;
        return;
    }

private:
    size_t _size, _max_size;
    int begin, end;
    int * container;
};
