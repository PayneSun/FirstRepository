/*
 * src/ch_6/example.c
 *
 * 2019/2/21
 */

#define min(a, b) ((a) > (b) ? (b) : (a))
#define max(a, b) ((a) > (b) ? (a) : (b))


struct point {
	int x;
	int y;
};

struct rect {
	struct point pt1;
	struct point pt2;
};


/*
 * 构造一个点
 */
struct point makepoint(int x, int y)
{
	struct point temp;
	temp.x = x;
	temp.y = y;
	return temp;
}


/*
 * 将两个点相加
 */
struct point addpoint(struct point p1, struct point p2)
{
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}


/*
 * 如果点p在矩形r内，则返回1，否则返回0
 */
int ptinrect(struct point p, struct rect r)
{
	return p.x >= r.pt1.x && p.x < r.pt2.x
			&& p.y >= r.pt1.y && p.y < r.pt2.y;
}


/*
 * 将矩阵坐标规范化
 */
struct rect connonrect(struct rect r)
{
	struct rect temp;

	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = max(r.pt1.x, r.pt2.x);
	temp.pt2.y = max(r.pt1.y, r.pt2.y);
	return temp;
}
