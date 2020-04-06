/******************************************
 * ch03_list_stack_queue/queue.h
 *
 * 2020.03.31
 *****************************************/

#include <iostream>

template<typename T>
class Queue {
public:
	Queue(int MaxElements);
	bool isEmpty();
	bool isFull();
	void dispose();
	void makeEmpty();
	int succ(int value);
	void enqueue(T x);
	T front();
	void dequeue();
	T frontAndDequeue();
private:
	int capacity;
	int front;
	int rear;
	int size;
	T *array;
};
