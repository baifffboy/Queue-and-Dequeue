#include <iostream>
#include "Stack.h"

using namespace std;
template <typename M>
class Dequeue
{
private:
	size_t sz;
	Stack<M> rightStack;
	Stack<M> leftStack;
public:
	Dequeue() { sz = 0; }
	~Dequeue() { 
		rightStack.~Stack(); 
		leftStack.~Stack();
	}
	size_t size() noexcept { return sz; }
	bool isEmpty() noexcept { return sz == 0; }
	void PushFront(M z) {
		rightStack.Push(z); sz++;
	}
	void PushBack(M z) {
		leftStack.Push(z); sz++;
	}
	M PopFront() {
		if (sz == 0) throw ("очередь пуста");
		if (leftStack.empty() == 0) { //если в левом стеке что то есть
			M val = leftStack.pop(); sz--; return val; // удаляем то, что последнее зашло справа
		}
		if ((rightStack.empty() == 0) && (leftStack.empty() == 1)) { //если правый стек не пустой, а левый пустой
			while (rightStack.empty() == 0) { leftStack.Push(rightStack.pop()); }
			M val = leftStack.pop();
			sz--;
			while (leftStack.empty() == 0) { rightStack.Push(leftStack.pop()); }
			return val;
		}
	}
	M PopBack() {
		if (sz == 0) throw ("очередь пуста");
		if (rightStack.empty() == 0) {  //если в правом стеке что то есть
			M val = rightStack.pop(); sz--; return val; // удаляем то, что последнее зашло справа
		}
		if ((leftStack.empty() == 0) && (rightStack.empty() == 1)) { //если левый стек не пустой, а правый пустой
			while (leftStack.empty() == 0) { rightStack.Push(leftStack.pop()); }
			M val = rightStack.pop();
			sz--;
			while (rightStack.empty() == 0) { leftStack.Push(rightStack.pop()); }
			return val;
		}
	}
	M Front() noexcept { 
		if (sz == 0) throw ("очередь пуста");
		if (leftStack.empty() == 0) {
			return leftStack.top();
		}
		if ((rightStack.empty() == 0) && (leftStack.empty() == 1)) {
			while (rightStack.empty() == 0) { leftStack.Push(rightStack.pop()); }
			M val = leftStack.top();
			while (leftStack.empty() == 0) { rightStack.Push(leftStack.pop()); }
			return val;
		}

	} 
	M Back() noexcept { 
		if (sz == 0) throw ("очередь пуста");
		if (rightStack.empty() == 0) {
			return rightStack.top();
		}
		if ((leftStack.empty() == 0) && (rightStack.empty() == 1)) {
			while (leftStack.empty() == 0) { rightStack.Push(leftStack.pop()); }
			M val = rightStack.top();
			while (rightStack.empty() == 0) { leftStack.Push(rightStack.pop()); }
			return val;
		}
	}
	/*void swap_(Dequeue<M> k) {

	}*/
	void insert(size_t pos, M val) {
		if (pos < leftStack.m+1) leftStack.begin[leftStack.m - pos] = val;
		else rightStack.begin[pos-(leftStack.m+1)] = val;
	}
};