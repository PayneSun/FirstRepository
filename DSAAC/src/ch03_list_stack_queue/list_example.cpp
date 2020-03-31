/******************************************
 * ch03_list_stack_queue/list_example.cpp
 *
 * 2020.03.31
 *****************************************/

#define SpaceSize 10
#define MaxDegree 100

// 多项式ADT的数组实现
typedef struct {
	int CoeffArray[MaxDegree + 1];
	int HighPower;
}*Polynomial;

// 多项式ADT的指针实现
typedef struct PolyNode *PtrToPolyNode;
typedef struct PolyNode {
	int Coefficient;
	int Exponent;
	PtrToPolyNode Next;
} Polynomial2;

