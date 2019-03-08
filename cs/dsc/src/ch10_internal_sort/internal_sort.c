// 数据结构（C语言描述）.严蔚敏
// 第10章.排序
// internal_sort.c
// 2016.10.24


#include "internal_sort.h"


// 算法10.01
void InsertSort(SqList sl) {
	for (int i = 2; i <= sl.length; ++i) {
		if (LT(sl.r[i].key, sl.r[i-1].key)) {
			sl.r[0] = sl.r[i];
			sl.r[i] = sl.r[i-1];
			int j = i - 2;
			for (; LT(sl.r[0].key, sl.r[j].key); --j) {
				sl.r[j+1] = sl.r[j];
			} // for
			sl.r[j+1] = sl.r[0];
		} // if
	} // for
}


// 算法10.02
void BInsertSort(SqList sl) {
	for (int i = 2; i < sl.length; i++) {
		sl.r[0] = sl.r[i];
		int low = 1, high = i - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (LT(sl.r[0].key, sl.r[mid].key)) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
			for (int j = i - 1; j >= high + 1; --j) {
				sl.r[j+1] = sl.r[j];
			}
			sl.r[high+1] = sl.r[0];
		} // while
	} // for
}


// 算法10.04
void ShellInsert(SqList sl, int dk) {
	for (int i = dk + 1; i < sl.length; ++i) {
		if (LT(sl.r[i].key, sl.r[i-dk].key)) {
			sl.r[0] = sl.r[i];
			int j = i - dk;
			for (; j > 0 && LT(sl.r[0].key, sl.r[j].key); j -= dk) {
				sl.r[j+dk] = sl.r[j];
			}
			sl.r[j+dk] = sl.r[0];
		}
	}
}


// 算法10.05
void ShellSort(SqList sl, int dlta[], int t) {
	// 按照增量序列dlta[0..t-1]对顺序表进行希尔排序
	for (int k = 0; k < t; ++k) {
		ShellInsert(sl, dlta[k]);
	}
}


// 算法10.06(a)
int Partition(SqList sl, int low, int high) {
	KeyType pivot_key = sl.r[low].key;
	while (low < high) {
		while (low < high && sl.r[high].key >= pivot_key) { --high; }
		swap(sl.r[low], sl.r[high]);
		while (low < high && sl.r[low].key <= pivot_key) { ++low; }
		swap(sl.r[low], sl.r[high]);
	}
	return low;
}


// 算法10.06(b)
int Partition(SqList sl, int low, int high) {
	sl.r[0] = sl.r[low];
	KeyType pivot_key = sl.r[low].key;
	while (low < high) {
		while (low < high && sl.r[high].key >= pivot_key) { --high; }
		sl.r[low] = sl.r[high];
		while (low < high && sl.r[low].key <= pivot_key) { ++low; }
		sl.r[high] = sl.r[low];
	}
	sl.r[low] = sl.r[0];
	return low;
}


// 算法10.07
void QSort(SqList sl, int low, int high) {
	if (low < high) {
		int pivot_loc = Partition(sl, low, high);
		QSort(sl, low, pivot_loc - 1);
		QSort(sl, pivot_loc + 1, high);
	}
}


// 算法10.08
void QSort(SqList sl) {
	QSort(sl, 1, sl.length);
}


// 算法10.09
void SelectSort(SqList sl) {
	// 对顺序表sl作简单选择排序
	for (int i = 1; i < sl.length; ++i) {
		// 在sl.r[i..sl.length]中选择key最小的记录
		int j = SelectMinKey(sl, i);
		if (i != j) {
			swap(sl.r[i], sl.r[j]);   // 与第i个记录交换
		} // if
	} // for
}


// 算法10.10
typedef SqList HeapType;
void HeapAdjust(HeapType ht, int s, int m) {
	// 已知ht.r[s..m]中记录的关键字除ht.r[s].key之外的均满足堆的定义，
	// 本函数调整ht.r[s]的关键字，使ht.r[s..m]成为一个大顶堆（对其中记录的关键字而言）
	RedType rc = ht.r[s];
	for (int j = 2 * s; j < m; j *= 2) {
		if (j < m && LT(ht.r[j].key, ht.r[j+1].key)) { ++j; }
		if (!LT(rc.key, ht.r[j].key)) { break; }
		ht.r[s] = ht.r[j];
		s = j;
	}
	ht.r[s] = rc;   // 插入
}


// 算法10.11
void HeapSort(HeapType ht) {
	// 把ht.r[1..ht.length]建成大顶堆
	for (int i = ht.length / 2; i > 0; --i) {
		HeapAdjust(ht, i, ht.length);
	}
	for (int i = ht.length; i > 1; --i) {
		// 将堆顶记录和当前未经排序子序列ht.r[1..i]中最后一个记录相互交换
		swap(ht.r[1], ht.r[i]);
		// 将h.r[1..i-1]重新调整为大顶堆
		HeapAdjust(ht, 1, i - 1);
	}
}


// 算法10.12
void Merge(RedType sr[], RedType tr[], int i, int m, int n) {
	// 将有序的sr[i..m]和sr[m+1..n]归并为有序的tr[i..n]
	int j = m + 1, k = i;
	for (; i <= m && j <= n; ++k) {
		if (LQ(sr[i].key, sr[j].key)) { tr[k] = sr[i++]; }
		else { tr[k] = sr[j++]; }
	}
	if (i <= m) {
		for (; i <= m; ++i) { tr[k++] = sr[i]; }
	}
	if (j <= n) {
		for (; j <= n; ++j) { tr[k++] = sr[j]; }
	}
}


// 算法 10.13
void MSort(RedType sr[], RedType tr[], int s, int t) {
	// 将sr[s..t]归并排序为tr1[s..t]
	if (s == t) {
		tr[s] = sr[s];
	} else {
		int m = (s + t) / 2;
		RedType tr2[t - s + 1];
		MSort(sr, tr2, s, m);
		MSort(sr, tr2, m + 1, t);
		Merge(tr2, tr, s, m, t);
	} // else
}


// 算法10.14
void MergeSort(SqList sl) {
	MSort(sl.r, sl.r, 1, sl.length);
}


// 算法10.15
void Distribute(SLCell r, int i, ArrType f, ArrType e) {
	// 静态链表l的r域中记录已按照keys[0],...,keys[i-1]有序，
	// 本函数按第i个关键字keys[i]建立RADIX个子表，使同一子表中记录的keys[i]相同，
	// f[0..RADIX-1]和e[0..RADIX-1]分别指向各个子表中第1个和最后1个元素。
	for (int j = 0; j < RADIX; ++j) { f[j] = 0; }
	for (int p = r[0].next; p; p = r[p].next) {
		int j = ord(r[p].keys[i]);
		if (!f[j]) {
			f[j] = p;
		} else {
			r[e[j]].next = p;
		} // else
		e[j] = p;
	} // for
}


// 算法10.16
void Collect(SLCell r, int i , ArrType f, ArrType e) {
	// 按keys[i]自小到大地将f[0..RADIX-1]所指各子表依次链接成一个链表
	int j = 0;
	for (; !f[j]; j = succ(j));  // 找到第1个非空子表，succ为求后继函数
	r[0].next = f[j];
	ArrType t = e[j];
	while (j < RADIX) {
		// 找下一个非空子表
		for (j = succ(j); i < RADIX - 1 && !f[j]; j = succ(j));
		// 链接两个非空子表
		if (f[j]) { r[t].next = f[j]; t = e[j]; }
	}
	r[t].next = 0;
}


// 算法10.17
void RadixSort(SLList sll) {
	// sll是采用静态链表表示的顺序表， 对sll作基数排序，
	// 使得sll成为按关键字从小到大的有序静态链表，sll.r[0]为头结点。
	for (int i = 0; i < sll.rec_num; ++i) {
		sll.r[i+1] = i + 1;
	}
	sll.r[sll.rec_num].next = 0;   // 将sll改造成静态链表
	// 按最低位优先依次对各关键字进行分配和收集
	for (int i = 0; i < sll.key_num; ++i) {
		ArrType f, e;
		Distribute(sll.r, i, f, e);
		Distribute(sll.r, i, f, e);
	}
}
