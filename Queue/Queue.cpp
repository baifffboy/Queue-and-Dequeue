#include "Stack.h"
#include <iostream>

using namespace std;
template <typename M>
class Queue 
{
private:
	size_t sz;
	Stack<M> rightStack;
	Stack<M> leftStack;
public:
	Queue() { sz = 0; }
	~Queue(){ 
		rightStack.~Stack();
		leftStack.~Stack(); 
	}
	size_t size() noexcept { return sz; }
	bool isEmpty() noexcept { return sz == 0; }
	void Push(M s) noexcept { leftStack.Push(s); sz++; }
	M Pop() {
		if (rightStack.empty()) {
			while (leftStack.empty() == 0) {
				rightStack.Push(leftStack.pop());
			}
		}
		M val = rightStack.pop();
		sz--;
		return val;
	}
	M Front() noexcept { 
		if (this->isEmpty() == 0) {
			if (leftStack.empty() == 0)
				return leftStack.begin[0];
			return rightStack.top();
		}
		else throw ("Вы не заполнили очередь!");
	}
	M Back() noexcept {
		if (this->isEmpty() == 0) {
			if (leftStack.empty() == 0)
				return leftStack.top();
			return rightStack.begin[0];
		}
		else throw ("Вы не заполнили очередь!");
	}

	/*void swap_(Queue<M> k) {
		leftStack.swap__(k.leftStack);
		rightStack.swap__(k.rightStack);
		std::swap(sz, k.sz);
	}*/
};