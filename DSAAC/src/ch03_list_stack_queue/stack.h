/******************************************
 * ch03_list_stack_queue/stack.h
 *
 * 2020.04.02
 *****************************************/

#include "define.h"

template<typename T>
struct Node {
	T element;
	Node *next;
};

template<typename T>
class Stack {
public:
	Stack();
	int isEmpty();
	void dispose();
	void makeEmpty();
	void push(T x);
	T top();
	void pop();

private:
	Node<T> *stackTop;
};

