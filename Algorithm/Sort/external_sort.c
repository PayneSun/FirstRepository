// ���ݽṹ��C����������.��ε��
// ��11��.�ⲿ����
// external_sort.h
// 2016.10.26


#include "external_sort.h"


// �㷨11.01
void K_Merge(LoserTree ls, External b) {
	// ���ð�����ls����Ŵ�0��k-1��k������鲢���еļ�¼�鲢������鲢�Ρ�
	// b[0]��b[k-1]Ϊ�������ϵ�k��Ҷ�ӽ�㣬
	// �ֱ���k������鲢���е�ǰ��¼�Ĺؼ��֡�
	// �ֱ��k������鲢�ζ���öε�ǰ��1����¼�Ĺؼ��ֵ�����
	for (int i = 0; i < k; ++i) { input(b[i].key); }
	// ����������ls��ѡ����С�ؼ���Ϊb[ls[0]].key
	CreateLoserTree(ls);
	while (b[ls[0]].key != MAX_KEY) {
		int q = ls[0];        // ָʾ��ǰ��С�ؼ������ڹ鲢��
		input(b[q].key, q);   // �ӱ��Ϊq������鲢���ж�����һ����¼�Ĺؼ���
		Ajust(ls, q);         // ����������ѡ���µ���С�ؼ���
	}
	// �������ؼ���MAX_KEY�ļ�¼д������鲢��
	output(ls[0]);
}


// �㷨11.02
void Ajust(LoserTree ls, int s) {
	// ��Ҷ�ӽ��b[s]�������ls[0]��·������������
	int t = (s + k) / 2;   // ls[t]��b[s]��˫�׽��
	while (t > 0) {
		if (b[s].key > b[ls[t]].key) { swap(s, ls[t]); }
		t = t / 2;
	}
	ls[0] = s;
}


// �㷨11.03
void CreateLoserTree(LoserTree ls) {
	// ��b[0]��b[k-1]Ϊ��ȫ������ls��Ҷ�ӽ�����k���ؼ��֣�
	// �ش�Ҷ�ӵ�����k��·����ls����Ϊ������
	b[k] = MIN_KEY;   // ��MIN_KEYΪ�ؼ��ֿ��ܵ���Сֵ
	for (int i = 0; i < k; ++i) { ls[i] = k; }   // ����ls�С����ߡ��ĳ�ֵ
	for (int i = k - 1; i >= 0; --i) { Ajust(ls, i); }   // ���ε�������
}


// �㷨11.04
void Replace_Selection(LoserTree ls, WorkArea wa, FILE *fi, FILE *fo) {
	// �ڰ�����ls���ڴ湤����wa�����û�-ѡ���������ʼ���鲢�Σ�
	// fiΪ�����ļ�ָ�룬foΪ����ļ�ָ�룬�����ļ����Ѵ򿪡�
	Construct_Loser(ls,wa);
	int rc = 1;   // rcָʾ��ǰ���ɵĳ�ʼ���鲢�εĶκ�
	int rm = 1;   // rmָʾwa�йؼ���������ʼ���鲢�ε����κ�
	while (rc <= rm) {   // ��rc=rm+1����־�����ļ����û�-ѡ�������Ѿ����
		Get_Run(ls, wa);   // ���һ����ʼ���鲢��
		fwrite(&RUNEND_SYMBOL, sizeof(struct RcdType), 1, fo);   //���ν�����־д������ļ�
		rc = wa[ls[0]].rnum;   // ������һ�εĶκ�
	}
}


// �㷨11.05
void Get_Run(LoserTree ls, WorkArea wa) {
	// ���һ����ʼ�鲢�Σ�fiΪ�ļ�����ָ�룬foΪ�ļ����ָ��
	while (wa[ls[0]].rnum == rc) {   //ѡ�õ�MINIMAX��¼����ǰ��ʱ
		int q = ls[0];   // qָʾMINIMAX��¼��wa�е�λ��
		int minimax = wa[q].key;
		fwrite(&wa[q].rec, sizeof(RcdType), 1, fo);   // ����ѡ�õ�MINIMAX��¼д������ļ�
		if (feof(fi)) {
			wa[q].rnum = rm + 1;
		} else {
			fread(&wa[q].rec, sizeof(RcdType), 1, fi);
			wa[q].key = wa[q].rec.key;   // ��ȡ�ؼ���
			if (wa[q].key < minimax) {   // �¶���ļ�¼����һ��
				rm = rc + 1;
				wa[q].rnum = rm;
			} else {
				wa[q].rnum = rc;   // �¶���ļ�¼����ǰ��
			}
		}
		Select_MiniMax(ls, wa, q);   // ѡ���µ�MINIMAX��¼
	}
}


// �㷨11.06
void Select_MiniMax(LoserTree ls, WorkArea wa, int q) {
	// ��wa[q]�𵽰������ĸ��Ƚ�ѡ��MINIMAX������qָʾ�����ڵĹ鲢��
	for (int t = (w + q) / 2, p = ls[t]; t > 0; t = t / 2, p = ls[t]) {
		if ((wa[p].rnum < wa[q].rnum) ||
			(wa[p].rnum == wa[q].rnum && wa[p].key < wa[q].key)) {
			swap(q, ls[t]);
		}
	}
	ls[0] = q;
}


// �㷨11.07
void Construct_Loser(LoserTree ls, WorkArea wa) {
	// ����w����¼���ڴ湤����wa������������ls��ѡ���ؼ�����С�ļ�¼����sָʾ����wa�е�λ��
	for (int i = 0; i < w; ++i) {   // ��������ʼ��
		wa[i].rec = wa[i].key = ls[i] = 0;
	}
	for (int i = w - 1; i >= 0; --i) {
		fread(&wa[i].rec, sizeof(RcdType), 1, fi);
		wa[i].key = wa[i].rec.key;
		wa[i].rnum = 1;
		Select_MinMax(ls, wa, i);
	}
}
