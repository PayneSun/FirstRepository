// 数据结构（C语言描述）.严蔚敏
// 第11章.外部排序
// external_sort.h
// 2016.10.26


#include "external_sort.h"


// 算法11.01
void K_Merge(LoserTree ls, External b) {
	// 利用败者树ls将编号从0到k-1的k个输入归并段中的记录归并到输出归并段。
	// b[0]到b[k-1]为败者树上的k个叶子结点，
	// 分别存放k个输入归并段中当前记录的关键字。
	// 分别从k个输入归并段读入该段当前第1个记录的关键字到外结点
	for (int i = 0; i < k; ++i) { input(b[i].key); }
	// 创建败者树ls，选得最小关键字为b[ls[0]].key
	CreateLoserTree(ls);
	while (b[ls[0]].key != MAX_KEY) {
		int q = ls[0];        // 指示当前最小关键字所在归并段
		input(b[q].key, q);   // 从编号为q的输入归并段中读入下一个记录的关键字
		Ajust(ls, q);         // 调整败者树选择新的最小关键字
	}
	// 将含最大关键字MAX_KEY的记录写至输出归并段
	output(ls[0]);
}


// 算法11.02
void Ajust(LoserTree ls, int s) {
	// 沿叶子结点b[s]到根结点ls[0]的路径调整败者树
	int t = (s + k) / 2;   // ls[t]是b[s]的双亲结点
	while (t > 0) {
		if (b[s].key > b[ls[t]].key) { swap(s, ls[t]); }
		t = t / 2;
	}
	ls[0] = s;
}


// 算法11.03
void CreateLoserTree(LoserTree ls) {
	// 从b[0]到b[k-1]为完全二叉树ls的叶子结点存有k个关键字，
	// 沿从叶子到根的k条路径将ls调整为败者树
	b[k] = MIN_KEY;   // 设MIN_KEY为关键字可能的最小值
	for (int i = 0; i < k; ++i) { ls[i] = k; }   // 设置ls中“败者”的初值
	for (int i = k - 1; i >= 0; --i) { Ajust(ls, i); }   // 依次调整败者
}


// 算法11.04
void Replace_Selection(LoserTree ls, WorkArea wa, FILE *fi, FILE *fo) {
	// 在败者树ls和内存工作区wa上用置换-选择排序求初始化归并段，
	// fi为输入文件指针，fo为输出文件指针，两个文件均已打开。
	Construct_Loser(ls,wa);
	int rc = 1;   // rc指示当前生成的初始化归并段的段号
	int rm = 1;   // rm指示wa中关键字所属初始化归并段的最大段号
	while (rc <= rm) {   // “rc=rm+1”标志输入文件的置换-选择排序已经完成
		Get_Run(ls, wa);   // 求得一个初始化归并段
		fwrite(&RUNEND_SYMBOL, sizeof(struct RcdType), 1, fo);   //将段结束标志写入输出文件
		rc = wa[ls[0]].rnum;   // 设置下一段的段号
	}
}


// 算法11.05
void Get_Run(LoserTree ls, WorkArea wa) {
	// 求得一个初始归并段，fi为文件输入指针，fo为文件输出指针
	while (wa[ls[0]].rnum == rc) {   //选得的MINIMAX记录属当前段时
		int q = ls[0];   // q指示MINIMAX记录在wa中的位置
		int minimax = wa[q].key;
		fwrite(&wa[q].rec, sizeof(RcdType), 1, fo);   // 将刚选好的MINIMAX记录写入输出文件
		if (feof(fi)) {
			wa[q].rnum = rm + 1;
		} else {
			fread(&wa[q].rec, sizeof(RcdType), 1, fi);
			wa[q].key = wa[q].rec.key;   // 提取关键字
			if (wa[q].key < minimax) {   // 新读入的记录属下一段
				rm = rc + 1;
				wa[q].rnum = rm;
			} else {
				wa[q].rnum = rc;   // 新读入的记录属当前段
			}
		}
		Select_MiniMax(ls, wa, q);   // 选择新的MINIMAX记录
	}
}


// 算法11.06
void Select_MiniMax(LoserTree ls, WorkArea wa, int q) {
	// 从wa[q]起到败者树的根比较选择MINIMAX，并由q指示它所在的归并段
	for (int t = (w + q) / 2, p = ls[t]; t > 0; t = t / 2, p = ls[t]) {
		if ((wa[p].rnum < wa[q].rnum) ||
			(wa[p].rnum == wa[q].rnum && wa[p].key < wa[q].key)) {
			swap(q, ls[t]);
		}
	}
	ls[0] = q;
}


// 算法11.07
void Construct_Loser(LoserTree ls, WorkArea wa) {
	// 输入w个记录到内存工作区wa，创建败者树ls，选出关键字最小的记录并由s指示其在wa中的位置
	for (int i = 0; i < w; ++i) {   // 工作区初始化
		wa[i].rec = wa[i].key = ls[i] = 0;
	}
	for (int i = w - 1; i >= 0; --i) {
		fread(&wa[i].rec, sizeof(RcdType), 1, fi);
		wa[i].key = wa[i].rec.key;
		wa[i].rnum = 1;
		Select_MinMax(ls, wa, i);
	}
}
