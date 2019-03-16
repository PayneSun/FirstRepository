/*
 * ch_08_disjoint_set_adt/disjoint.h
 *
 * 2019/3/16
 */


#define NumSets 10

typedef int Disjoint[NumSets + 1];
typedef int SetType;
typedef int ElementType;

void Initialize(Disjoint S);
void SetUion(Disjoint S, SetType Root1, SetType Root2);
SetType Find(ElementType X, Disjoint S);

