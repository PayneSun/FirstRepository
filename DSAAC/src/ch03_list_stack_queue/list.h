/******************************************
 * ch03_list_stack_queue/list.h
 *
 * 2020.03.31
 *****************************************/

#include "define.h"

typedef struct Node {
	int element;
	Node *next;
}*Pos;

class List {
private:
	List();
	List(int data[]); //create-by-array
public:
	Pos makeEmpty();
	bool isEmpty();
	bool isLast(Pos pos);
	Pos find(int x);
	void insert(int x, Pos pos);
	void deleteElement(int x);
	Pos findPrevious(int x);
	Pos header();
	Pos first();
	Pos advance(Pos pos);
	int retrieve(Pos pos);
	~List();
private:
	Node *head;
};
