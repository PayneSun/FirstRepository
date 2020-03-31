/**
 * ch03_list_stack_queue/cursor.h
 *
 * 2017/10/17
 */

#include "define.h"

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node {
	ElementType Element;
	Position Next;
};
struct Node CursorSpace[SpaceSize];

void InitializeCursorSpace(void);

List MakeEmpty(List L);
int IsEmpty(const List L);
int IsLast(const Position P, const List L);
Position Find(ElementType X, const List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, const List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(const List L);
Position Advance(const Position P);
ElementType Retrieve(const Position P);
