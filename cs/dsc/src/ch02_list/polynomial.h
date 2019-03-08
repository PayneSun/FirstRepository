// 数据结构（C语言描述）.严蔚敏
// 第2章.线性表
// polynomial.h


// ***************
// ADT: Polynomial
// ***************

// 项的表示，多项式的项作为LinkList的数据元素
typedef struct {
	float coef;     // 系数
	int expn;       // 指数
} Term, ElemType;   // Term用于本ADT, ElemType为LinkList的数据对象名

// 用带表头结点的有序链表表示多项式
#include "../ch02_list/list.h"
typedef LinkList Polynomial;

// 基本操作的函数原型说明
void CreatPolyn(Polynomial p, int m);
void DestroyPplyn(Polynomial p);
void PrintPolyn(Polynomial p);
int PolynLength(Polynomial p);
void AddPolyn(Polynomial p1, Polynomial p2);
void SutractPolyn(Polynomial p1, Polynomial p2);
void MultiplyPolyn(Polynomial p1, Polynomial p2);
int Cmp(Term ta, Term tb);
