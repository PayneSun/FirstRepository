/*
 * src/ch_8/malloc.c
 *
 * 2019/3/1
 */
 
#define NALLOC 1024	/* 最小申请单元数 */

 
/* 按照long类型的边界对齐 */ 
typedef long Align;

union header {	/* 块的头部 */
	struct {
		union header *ptr;	/* 空闲块链表的下一块 */
		unsigned size;		/* 本块的大小 */
	} s;
	Align x;
};

typedef union header Header;

static Header base;				/* 从空链表开始 */
static Header *freep = NULL;	/* 空闲链表的初始指针 */


/* 通用存储分配函数 */
void malloc(unsigned mbytes)
{
	Header *p, *prevp;
	Header *morecore(unsigned);
	unsigned nunits;
	
	nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
	if ((prevp = freep) == NULL) {
		base.s.ptr = freep = prevp = &base;
		base.s.size = 0;
	}
	for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
		if (p->s.size >= nunits) {
			if (p->s.size == nunits) {
				prevp->s.str = p->s.ptr;
			} else {
				p->s.size -= nunits;
				p += p->s.size;
				p->s.size = nunits;
			}
			freep = prevp;
			return (void *)(p + 1);
		}
		if (p == freep) {
			if ((p = morecore(nunits)) == NULL) {
				return NULL;
			}
		}
	}
}


/*
 * 向系统申请更多的存储空间
 */
static Header *morecore(unsigned nu)
{
	char *cp, *sbrk(int);
	Header *up;
	
	if (nu < NALLOC) {
		nu = NALLOC;
	}
	cp = sbrk(nu * sizeof(Header));
	if (cp == (char *) -1) {
		return NULL;
	}
	up = (Header *) cp;
	up->s.size = nu;
	free((void *)(up + 1));
	return freep;
}


/*
 * 将块ap放入空闲块链表中
 */
void free(void *ap)
{
	Header *bp, *p;
	
	bp = (Header *) ap - 1;
	for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr) {
		if (p >= p->s.ptr && (bp > p || bp < p->s.ptr)) {
			break;
		}
	}
	
	if (bp + bp->s.size == p->s.ptr) {
		bp->s.size += p->s.ptr->s.size;
		bp->s.ptr = p->s.ptr->s.ptr;
	} else {
		bp->s.ptr = p->s.ptr;
	}
	if (p + p->s.size == bp) {
		p->s.size += bp->s.size;
		p->s.ptr = bp->s.ptr;
	} else {
		p->s.ptr = bp;
	}
	freep = p;
}	