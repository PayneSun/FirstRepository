/*
 * ch_08_disjoint_set_adt/disjoint.cpp
 *
 * 2019/3/16
 */

#include "disjoint.h"


void Initialize(Disjoint S) {
	int i;

	for (i = NumSets; i > 0; i--) {
		S[i] = 0;
	}
}


void SetUion(Disjoint S, SetType Root1, SetType Root2) {
	S[Root2] = Root1;
}


void SetUion2(Disjoint S, SetType Root1, SetType Root2) {
	if (S[Root2] < Root1) {
		S[Root1] = Root2;
	} else {
		if (S[Root2] == S[Root1]) {
			S[Root1]--;
		}
		S[Root2] = Root1;
	}
}


SetType Find(ElementType X, Disjoint S) {
	if (S[X] <= 0) {
		return X;
	} else {
		return Find(S[X], S);
	}
}
