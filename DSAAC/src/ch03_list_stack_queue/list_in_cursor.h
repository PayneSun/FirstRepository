/******************************************
 * ch03_list_stack_queue/list_in_cursor.h
 *
 * 2020.04.01
 *****************************************/

#include "define.h"

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node {
	int element;
	Position next;
};
struct Node CursorSpace[SpaceSize];

void initializeCursorSpace(void);

List makeEmpty(List L);
int isEmpty(const List L);
int isLast(const Position P, const List L);
Position find(int X, const List L);
void deleteElement(int X, List L);
Position findPrevious(int X, const List L);
void insert(int X, List L, Position P);
void deleteList(List L);
Position header(const List L);
Position advance(const Position P);
int retrieve(const Position P);
