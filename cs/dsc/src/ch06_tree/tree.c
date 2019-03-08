// ���ݽṹ��C����������.��ε��
// ��6��.���Ͷ�����
// tree.c


#include "../ch06_tree/tree.h"

#include "public.h"


// �㷨6.8
int find_mfset(MFSet mfs, int i) {
	if (i < 1 || i > mfs.n) {
		return -1;
	}
	int j;
	for (j = i; mfs.nodes[j].parent > 0; j = mfs.nodes[j].parent) {}
	return j;
}

// �㷨6.9
Status merge_mfset(MFSet mfs, int i, int j) {
	if (i < 1 || i > mfs.n || j < 1 || j > mfs.n) {
		return -1;
	}
	mfs.nodes[i].parent = j;
	return TRUE;
}

// �㷨6.10
Status mix_mfset(MFSet mfs, int i, int j) {
	if (i < 1 || i > mfs.n || j < 1 || j > mfs.n) {
			return -1;
	}
	if (mfs.nodes[i].parent > mfs.nodes[j].parent) {
		mfs.nodes[j].parent += mfs.nodes[i].parent;
		mfs.nodes[i].parent = j;
	} else {
		mfs.nodes[i].parent += mfs.nodes[j].parent;
		mfs.nodes[j].parent = i;
	}
	return TRUE;
}

// �㷨6.11
int fix_mfset(MFSet mfs, int i) {
	if (i < 1 || i > mfs.n) { return -1; }
	int j;
	for (j = i; mfs.nodes[j].parent > 0; j = mfs.nodes[j].parent) {}
	int t, k = i;
	for (t = mfs.nodes[k].parent; k != j; k = t) {
		t = mfs.nodes[k].parent;
		mfs.nodes[k].parent = j;
	}
	return j;
}
