// 数据结构（C语言描述）.严蔚敏
// 第9章.查找/9.1.静态查找表
// static_search_table.c
// 2016.10.17


#include "../Search/search.h"


// 算法9.01
int Search_Seq(SSTable st, KeyType key) {
	// 在顺序表st中顺序查找其关键字等于key的数据元素；
	// 若找到，则函数值为该元素在表中的位置，否则为0。
	st.elem[0].key = key;
	int i = st.length;
	for (; !EQ(st.elem[i].key, key); --i) {}
	return i;
}


// 算法9.02
int Search_Bin(SSTable st, KeyType key) {
	// 在有序表st中折半查找其关键字等于key的数据元素。
	// 若查找到，则函数值为该元素在表中的位置，否则为0
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


// 算法9.03
void SecondOptimal(BiTree bt, ElemType r[],
		 	       float sw[], int low, int high) {
	// 由有序表r[low..high]及其累计权值表sw递归构造次优查找树bt
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
		SecondOptimal(bt->lchild, r, sw, low, i - 1);   // 构造左子树
	}
	if (i == high) {
		bt->rchild = NULL;
	} else {
		SecondOptimal(bt->rchild, r, sw, i + 1, high);   // 构造右子树
	}
}


// 算法9.04
Status CreateSOSTree(SOSTree sost, SSTable sst) {
	// 由有序表sst构造一棵次优先查找树sost; sst的数据元素含有权域weight
	if (sst.length == 0) {
		sost = NULL;
	} else {
		int sw[sst.length];
		FindSW(sw, sst);   // 计算累计权值表sw
		SecondOptimal(sost, sst.elem, sw, 1, sst.length);
	}
	return OK;
}
