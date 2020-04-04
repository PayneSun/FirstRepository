/******************************************
 * ch03_list_stack_queue/stack_in_array.h
 *
 * 2020.03.31
 *****************************************/

template<typename T>
class Stack {
public:
	Stack(int n);
	bool isEmpty();
	bool isFull();
	void dispose();
	void makeEmpty();
	void push(T x);
	T top();
	void pop();
	T topAndPop();
private:
	int capacity;
	int topOfStack;
	T *array;
};
