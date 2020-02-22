// 数据结构（C语言描述）.严蔚敏
// 第9章.查找/9.2.动态查找表
// dynamic_search_table.c
// 2016.10.18


#include "../Search/search.h"


// 算法9.05(a)
BiTree SearchBST(BiTree bt, KeyType key) {
	if (!bt || EQ(key, bt->data.key)) {
		return bt;
	} else if (LT(key, bt->data.key)){
		return SearchBST(bt->lchild, key);
	} else {
		return SearchBST(bt->rchild, key);
	}
}


// 算法9.05(b)
Status SearchBST(BiTree bt, KeyType key, BiTree f, BiTree p) {
	// 在指针bt所指二叉排序树中递归地查找其关键字等于key的数据元素，
	// 若查找成功，则指针p指向该数据元素结点，并返回TRUE，
	// 否则指针p指向查找路径上访问的最后一个结点并返回FALSE
	// 指针f指向bt的双亲，其初始值为NULL
	if (!bt) {
		p = f;
		return FALSE;
	} else if (EQ(key, bt->data.key)) {
		p = bt;
		return TRUE;
	} else if (LT(key, bt->data.key)) {
		return SearchBST(bt->lchild, key, bt, p);
	} else {
		return SearchBST(bt->rchild, key, bt, p);
	}
}


// 算法9.06
Status InsertBST(BiTree bt, ElemType e) {
	// 当二叉排序树bt中不存在关键字等于e.key的数据元素时，
	// 插入e并返回TRUE，否则返回FALSE
	BiTree p;
	if (!SearchBST(bt, e.key, NULL, p)) {
		BiTree s = (BiTree)malloc(Sizeof(BiTNode));
		s->data = e;
		s->lchild = s->rchild = NULL;
		if (!p) {
			bt = s;
		} else if (LT(e.key, p->data.key)) {
			p->lchild = s;
		} else {
			p->rchild = s;
		}
		return TRUE;
	} else {
		return FALSE;
	}
}


// 算法9.07
Status DeleteBST(BiTree bt, KeyType key) {
	if (!bt) {
		return FALSE;
	} else if (EQ(key, bt->data.key)) {
		return Delete(bt);
	} else if (LT(key, bt->data.key)) {
		return DeleteBST(bt->lchild, key);
	} else {
		return DeleteBST(bt->rchild, key);
	}
}


// 算法9.08
Status Delete(BiTree bt) {
	// 从二叉排序树中删除结点bt，并重新连接它的左右子树
	if (!bt->rchild) {   // 右子树空则只需重接它的左子树
		BiTree q = bt;
		bt = bt->lchild;
		free(q);
	} else if (!bt->lchild) {   // 左子树空则只需重接它的右子树
		BiTree q = bt;
		bt = bt->rchild;
		free(q);
	} else {   // 左右子树均不为空
		BiTree q = bt;
		BiTree s = bt->lchild;
		while (s->rchild) {   // 转左，然后向右到尽头
			q = s;
			s = s->rchild;
		}
		bt->data = s->data;   // s指向被删结点的前驱
		if (q != bt) {
			q->rchild = s->lchild;   // 重接*q的右子树
		} else {
			q->lchild = s->lchild;   // 重接*q的左子树
		}
		free(s);
	}
	return TRUE;
}


// 算法9.09
void R_Rotate(BSTree bst) {
	// 对以*bst为根的二叉排序树作右旋处理，处理之后bst指向新的根结点，
	// 即旋转处理之前的左子树的根结点
	BSTNode *lc = bst->lchild;   // lc指向的*bst的左子树根结点
	bst->lchild = lc->rchild;    // lc的右子树挂接*bst的左子树
	lc->rchild = bst;            // *bst挂接到lc的右子树上
	bst = lc;                    // bst指向新的跟结点
}


// 算法9.10
void L_Rotate(BSTree bst) {
	// 对以*bst为根的二叉排序树作左旋处理，处理之后bst指向新的根结点，
	// 即旋转处理之前的右子树的根结点
	BSTNode *lc = bst->rchild;   // lc指向的*bst的右子树根结点
	bst->rchild = lc->lchild;    // lc的左子树挂接*bst的右子树
	lc->lchild = bst;            // *bst挂接到lc的左子树上
	bst = lc;                    // bst指向新的跟结点
}


// 算法9.11
typedef enum {
	LH = 1,   // 左高
    EH = 0,    // 等高
    RH = -1    // 右高
} HIGHLEVEL;

Status InsertAVL(BSTree bst, ElemType e, Status taller) {
	// 若在平衡的二叉树bst中不存在和e有相同关键字的结点，
	// 则插入一个数据元素为e的新结点，并返回1，否则返回0。
	// 若因插入而使二叉排序树失去平衡，则作平衡旋转处理，
	// 布尔变量taller反映bst长高与否。
	if (!bst) {
		bst = (BSTree)malloc(sizeof(BSTNode));
		bst->data = e;
		bst->lchild = bst->rchild = NULL;
		bst->bf = EH;
		taller = TRUE;
	} else {
		if (EQ(e.key, bst->data.key)) {
			taller = FALSE;
			return 0;
		} else if (LT(e.key, bst->data.key)) {   // 在*bst的左子树中进行搜索
			if (!InsertAVL(bst->lchild, e, taller)) {
				return 0;
			}
			if (taller) {   // 已插入*bst的左子树中且左子树长高
				switch(bst->bf) {   // 检查*bst的平衡度
					case LH:
						LeftBalance(bst); taller = FALSE; break;
					case EH:
						bst->bf = LH; taller = TRUE; break;
					case RH:
						RightBalance(bst); taller = FALSE; break;
				}
			} // if
		} else {
			if (!InsertAVL(bst->rchild, e, taller)) {
				return 0;
			}
			if (taller) {   // 已插入*bst的左子树中且左子树长高
				switch(bst->bf) {   // 检查*bst的平衡度
					case LH:
						bst->bf = LH; taller = FALSE; break;
					case EH:
						bst->bf = RH; taller = TRUE; break;
					case RH:
						RightBalance(bst); taller = FALSE; break;
				}
			} // if
		} // else
	}
	return TRUE;
}


// 算法9.12
void LeftBalance(BSTree bst) {
	// 对以指针bst所指结点为根的二叉树作左平衡旋转处理，结束时bst指向新的根结点
	BSTNode *lc = bst->lchild;
	switch (lc->bf) {   // 检查*bst的左子树的平衡度，并作相应平衡处理
		case LH:	   // 新结点插入在*bst的左孩子的左子树上，要作单右旋处理
			bst->bf = lc->bf = EH;
			R_Rotate(bst); break;
		case RH:       // 新结点插入在*bst的左子树的右子树上，要作双旋处理
			BSTNode *rd = lc->rchild;
			switch (rd->bf) {   // 修改*bst及其左孩子的平衡因子
				case LH:
					bst->bf = RH; lc->bf = EH; break;
				case EH:
					bst->bf = lc->bf = EH; break;
				case RH:
					bst->bf = EH; lc->bf = LH; break;
			}
			rd->bf = EH;
			L_Rotate(bst->lchild);
			R_Rotate(bst);
	}
}


// 算法9.13
Result SearchBTree(BTree bt, KeyType key) {

}



// 算法9.14

// 算法9.15

// 算法9.16
