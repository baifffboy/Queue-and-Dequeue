#include <iostream>

using namespace std;
template <typename M>
class Dequeue
{
private:
	size_t sz;
	int front; // индекс передней части очереди
	int back; // индекс задней части очереди
	M* s;
	unsigned int count;
public:
	Dequeue() { sz = 2; s = new M[sz]; front = (sz / 2)-1; back = (sz / 2); count = 0; }
	~Dequeue() { delete[] s; }
	size_t size() noexcept { return sz; }
	bool isEmpty() noexcept { return count == 0; }
	void PushFront(M z) {
		if (front < 0) {
			sz *= 2;
			M* r = new M[sz];
			front = (sz / 2) - 1;
			back = sz / 2;
			int res = count / 2;
			front -= res;
			back += (count - res);
			int q = 0;
			for (int i = front + 1; i < back; i++) {
				r[i] = s[q];
				q++;
			}
			delete[] s;
			s = new M[sz];
			for (int i = front + 1; i < back; i++) {
				s[i] = r[i];
			}
			delete[] r;
		}
		s[front] = z;
		count++;
		front--;
	}
	void PushBack(M z) {
		if (back == sz) {
			sz *= 2;
			M* r = new M[sz];
			front = (sz / 2) - 1;
			back = sz / 2;
			int res = count / 2;
			front -= res;
			back += (count - res);
			int q = 0;
			for (int i = front + 1; i < back; i++) {
				r[i] = s[q];
				q++;
			}
			delete[] s;
			s = new M[sz];
			for (int i = front + 1; i < back; i++) {
				s[i] = r[i];
			}
			delete[] r;
		}
		s[back] = z;
		count++;
		back++;
	}
	M PopFront() {
		if ((back - front) != 1) { M val = s[front + 1]; s[front + 1] = M(); front++; count--; return val; }
		else throw("ќчередь пуста!");
	}
	M PopBack() {
		if ((back - front) != 1) { M val = s[back - 1]; s[back - 1] = M(); back--; count--; return val; }
		else throw("ќчередь пуста!");
	}
	M Front() noexcept { return s[front + 1]; }
	M Back() noexcept { return s[back - 1]; }
	/*void swap_(Dequeue<M> k) {

	}*/
	void insert(size_t pos, M val) {
		if (pos < (count + 1)) s[front + pos] = val;
		else throw ("¬ы вышли за пределы очереди");
	}
};