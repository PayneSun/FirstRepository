/******************************************
 * ch03_list_stack_queue/list.h
 *
 * 2020.03.31
 *****************************************/

#include "define.h"

template<typename T>
typedef struct Node {
	T element;
	Node *next;
} Node, *Pos;

template<typename T>
class List {
private:
	List();
	List(T data[]); //create-by-array
public:
	Pos makeEmpty();
	bool isEmpty();
	bool isLast(Pos pos);
	Pos find(T x);
	void insert(T x, Pos pos);
	void deleteElement(T x);
	Pos findPrevious(T x);
	Pos header();
	Pos first();
	Pos advance(Pos pos);
	T retrieve(Pos pos);
	~List();
private:
	Node<T> head;
};
