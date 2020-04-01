/******************************************
 * ch03_list_stack_queue/list_example.cpp
 *
 * 2020.04.01
 *****************************************/

#include <algorithm>

#define SpaceSize 10
#define MaxDegree 100

// 多项式ADT的数组实现
typedef struct {
	int coeffArray[MaxDegree + 1];
	int highPower;
}*Polynomial;

// 多项式ADT的指针实现
typedef struct PolyNode *PtrToPolyNode;
typedef struct {
	int coefficient;
	int exponent;
	PtrToPolyNode next;
} PolyNode, Polynomial2;

void zeroPolynomial(Polynomial poly) {
	for (int i = 0; i <= MaxDegree; ++i) {
		poly->coeffArray[i] = 0;
	}
	poly->highPower = 0;
}

Polynomial addPolynomial(const Polynomial poly1, const Polynomial poly2) {
	Polynomial polyRet = Polynomial();

	zeroPolynomial(polyRet);
	polyRet->highPower = std::max(poly1->highPower, poly2->highPower);
	for (int i = 0; i <= polyRet->highPower; ++i) {
		polyRet->coeffArray[i] = poly1->coeffArray[i] + poly2->coeffArray[i];
	}

	return polyRet;
}

Polynomial mulPolynomial(const Polynomial poly1, const Polynomial poly2) {
	Polynomial polyRet = Polynomial();

	zeroPolynomial(polyRet);
	polyRet->highPower = poly1->highPower + poly2->highPower;
	if (polyRet->highPower > MaxDegree) {
		return NULL;
	} else {
		for (int i = 0; i <= poly1->highPower; ++i) {
			for (int j = 0; j <= poly2->highPower; ++j) {
				polyRet->coeffArray[i + j] += poly1->coeffArray[i]
						* poly2->coeffArray[j];
			}
		}
	}

	return polyRet;
}

