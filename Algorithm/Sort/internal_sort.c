// ���ݽṹ��C����������.��ε��
// ��10��.����
// internal_sort.c
// 2016.10.24


#include "internal_sort.h"


// �㷨10.01
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


// �㷨10.02
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


// �㷨10.04
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


// �㷨10.05
void ShellSort(SqList sl, int dlta[], int t) {
	// ������������dlta[0..t-1]��˳������ϣ������
	for (int k = 0; k < t; ++k) {
		ShellInsert(sl, dlta[k]);
	}
}


// �㷨10.06(a)
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


// �㷨10.06(b)
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


// �㷨10.07
void QSort(SqList sl, int low, int high) {
	if (low < high) {
		int pivot_loc = Partition(sl, low, high);
		QSort(sl, low, pivot_loc - 1);
		QSort(sl, pivot_loc + 1, high);
	}
}


// �㷨10.08
void QSort(SqList sl) {
	QSort(sl, 1, sl.length);
}


// �㷨10.09
void SelectSort(SqList sl) {
	// ��˳���sl����ѡ������
	for (int i = 1; i < sl.length; ++i) {
		// ��sl.r[i..sl.length]��ѡ��key��С�ļ�¼
		int j = SelectMinKey(sl, i);
		if (i != j) {
			swap(sl.r[i], sl.r[j]);   // ���i����¼����
		} // if
	} // for
}


// �㷨10.10
typedef SqList HeapType;
void HeapAdjust(HeapType ht, int s, int m) {
	// ��֪ht.r[s..m]�м�¼�Ĺؼ��ֳ�ht.r[s].key֮��ľ�����ѵĶ��壬
	// ����������ht.r[s]�Ĺؼ��֣�ʹht.r[s..m]��Ϊһ���󶥶ѣ������м�¼�Ĺؼ��ֶ��ԣ�
	RedType rc = ht.r[s];
	for (int j = 2 * s; j < m; j *= 2) {
		if (j < m && LT(ht.r[j].key, ht.r[j+1].key)) { ++j; }
		if (!LT(rc.key, ht.r[j].key)) { break; }
		ht.r[s] = ht.r[j];
		s = j;
	}
	ht.r[s] = rc;   // ����
}


// �㷨10.11
void HeapSort(HeapType ht) {
	// ��ht.r[1..ht.length]���ɴ󶥶�
	for (int i = ht.length / 2; i > 0; --i) {
		HeapAdjust(ht, i, ht.length);
	}
	for (int i = ht.length; i > 1; --i) {
		// ���Ѷ���¼�͵�ǰδ������������ht.r[1..i]�����һ����¼�໥����
		swap(ht.r[1], ht.r[i]);
		// ��h.r[1..i-1]���µ���Ϊ�󶥶�
		HeapAdjust(ht, 1, i - 1);
	}
}


// �㷨10.12
void Merge(RedType sr[], RedType tr[], int i, int m, int n) {
	// �������sr[i..m]��sr[m+1..n]�鲢Ϊ�����tr[i..n]
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


// �㷨 10.13
void MSort(RedType sr[], RedType tr[], int s, int t) {
	// ��sr[s..t]�鲢����Ϊtr1[s..t]
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


// �㷨10.14
void MergeSort(SqList sl) {
	MSort(sl.r, sl.r, 1, sl.length);
}


// �㷨10.15
void Distribute(SLCell r, int i, ArrType f, ArrType e) {
	// ��̬����l��r���м�¼�Ѱ���keys[0],...,keys[i-1]����
	// ����������i���ؼ���keys[i]����RADIX���ӱ�ʹͬһ�ӱ��м�¼��keys[i]��ͬ��
	// f[0..RADIX-1]��e[0..RADIX-1]�ֱ�ָ������ӱ��е�1�������1��Ԫ�ء�
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


// �㷨10.16
void Collect(SLCell r, int i , ArrType f, ArrType e) {
	// ��keys[i]��С����ؽ�f[0..RADIX-1]��ָ���ӱ��������ӳ�һ������
	int j = 0;
	for (; !f[j]; j = succ(j));  // �ҵ���1���ǿ��ӱ�succΪ���̺���
	r[0].next = f[j];
	ArrType t = e[j];
	while (j < RADIX) {
		// ����һ���ǿ��ӱ�
		for (j = succ(j); i < RADIX - 1 && !f[j]; j = succ(j));
		// ���������ǿ��ӱ�
		if (f[j]) { r[t].next = f[j]; t = e[j]; }
	}
	r[t].next = 0;
}


// �㷨10.17
void RadixSort(SLList sll) {
	// sll�ǲ��þ�̬�����ʾ��˳��� ��sll����������
	// ʹ��sll��Ϊ���ؼ��ִ�С���������̬����sll.r[0]Ϊͷ��㡣
	for (int i = 0; i < sll.rec_num; ++i) {
		sll.r[i+1] = i + 1;
	}
	sll.r[sll.rec_num].next = 0;   // ��sll����ɾ�̬����
	// �����λ�������ζԸ��ؼ��ֽ��з�����ռ�
	for (int i = 0; i < sll.key_num; ++i) {
		ArrType f, e;
		Distribute(sll.r, i, f, e);
		Distribute(sll.r, i, f, e);
	}
}
