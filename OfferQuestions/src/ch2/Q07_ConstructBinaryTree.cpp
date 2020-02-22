// Q07_QueueWithTwoStacks.cpp
//
// 2019.09.25

#include <iostream>
#include <stack>


template<typename T>
class CQueue {
public:
	CQueue();
	~CQueue();
	void appendTail(const T &node);
	T deleteHead();

private:
	std::stack<T> stk1;
	std::stack<T> stk2;
};


//
template<typename T>
void CQueue<T>::appendTail(const T &node) {
	this->stk1.push(node);
}


//
template<typename T>
T CQueue<T>::deleteHead() {
	if (this->stk2.size() <= 0) {
		while (this->stk1.size() > 0) {
			T &data = this->stk1.top();
			this->stk1.pop();
			this->stk2.push(data);
		}
	}

	if (this->stk2.size() == 0) {
		std::cerr << "queue is empty" << std::endl;
	}
	T head = this->stk2.top();
	this->stk2.pop();

	return head;
}


int main()
{
	return 0;
}
