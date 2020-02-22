// ���ݽṹ��C����������.��ε��
// ��9��.����/9.1.��̬���ұ�
// static_search_table.c
// 2016.10.17


#include "../Search/search.h"


// �㷨9.01
int Search_Seq(SSTable st, KeyType key) {
	// ��˳���st��˳�������ؼ��ֵ���key������Ԫ�أ�
	// ���ҵ�������ֵΪ��Ԫ���ڱ��е�λ�ã�����Ϊ0��
	st.elem[0].key = key;
	int i = st.length;
	for (; !EQ(st.elem[i].key, key); --i) {}
	return i;
}


// �㷨9.02
int Search_Bin(SSTable st, KeyType key) {
	// �������st���۰������ؼ��ֵ���key������Ԫ�ء�
	// �����ҵ�������ֵΪ��Ԫ���ڱ��е�λ�ã�����Ϊ0
	int low =1;
	int high = st.length;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (EQ(key, st.elem[mid].key)) {
			return mid;
		} else if (LT(key, st.elem[mid].key)) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	} // while
	return 0;
}


// �㷨9.03
void SecondOptimal(BiTree bt, ElemType r[],
		 	       float sw[], int low, int high) {
	// �������r[low..high]�����ۼ�Ȩֵ��sw�ݹ鹹����Ų�����bt
	int i = low;
	int min = abs(sw[high] - sw[low]);
	int dw = sw[high] + sw[low-1];
	for (int j = low + 1; j <= high; ++j) {
		if (abs(dw - sw[j] - sw[j-1]) < min) {
			i = j;
			min = abs(dw - sw[j] - sw[j-1]);
		} // if
	} // for
	bt = (BiTree)malloc(sizeof(BiTNode));
	bt->data = r[i];
	if (i == low) {
		bt->lchild = NULL;
	} else {
		SecondOptimal(bt->lchild, r, sw, low, i - 1);   // ����������
	}
	if (i == high) {
		bt->rchild = NULL;
	} else {
		SecondOptimal(bt->rchild, r, sw, i + 1, high);   // ����������
	}
}


// �㷨9.04
Status CreateSOSTree(SOSTree sost, SSTable sst) {
	// �������sst����һ�ô����Ȳ�����sost; sst������Ԫ�غ���Ȩ��weight
	if (sst.length == 0) {
		sost = NULL;
	} else {
		int sw[sst.length];
		FindSW(sw, sst);   // �����ۼ�Ȩֵ��sw
		SecondOptimal(sost, sst.elem, sw, 1, sst.length);
	}
	return OK;
}
