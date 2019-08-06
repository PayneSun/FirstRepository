/*
 * src/ch_2/solution.c
 *
 * 2019/2/10
 */

#include <stdio.h>
#include <limits.h>

void solution_2_1(); //todo
int solution_2_3(char s[]);
void solution_2_4(char s1[], char s2[]);
int solution_2_5(char s1[], char s2[]);
unsigned solution_2_6(unsigned x, int p, int n, unsigned y);
unsigned solution_2_7(unsigned x, int p, int n);
unsigned solution_2_8(unsigned x, int n); //todo
int solution_2_9(unsigned x); //todo
char solution_2_10(char c);

int main()
{

//	solution_2_1();

//	char s1[] = "0xFca";
//	char s2[] = "123fa";
//	printf("%s to int: %d\n", s1, solution_2_3(s1));
//	printf("%s to int: %d\n", s2, solution_2_3(s2));

//	char s1[] = "abcdefgh";
//	char s2[] = "bdfh";
//	solution_2_4(s1, s2);

//	char s1[] = "qwertyuiopasdfghjklxcvbnm";
//	char s2[] = "asdfghjkl";
//	char s3[] = "zxcvbnm";
//	printf("Loc: %d\n", solution_2_5(s1, s2));
//	printf("Loc: %d\n", solution_2_5(s1, s3));

//	unsigned x = 123;
//	unsigned y = 45;
//	printf("Result: %d\n", solution_2_6(x, 4, 3, y));

	unsigned x = 123;
	printf("Result: %d\n", solution_2_7(x, 4, 3));
}


/*
 * todo
 */
void solution_2_1()
{
	printf("Range of type signed char:%d-%d\n", SCHAR_MIN, SCHAR_MAX);
	printf("Range of type signed short:%d-%d\n", SHRT_MIN, SHRT_MAX);
	printf("Range of type signed int:%d-%d\n", INT_MIN, INT_MAX);
	printf("Range of type signed long:%d-%d\n", LONG_MIN, LONG_MAX);
	printf("Range of type unsigned char:%d-%d\n", 0, UCHAR_MAX);
	printf("Range of type unsigned short:%d-%d\n", 0, USHRT_MAX);
	printf("Range of type unsigned int:%d-%ld\n", 0, UINT_MAX);
	printf("Range of type unsigned long:%d-%ld\n", 0, ULONG_MAX);
}


/*
 *
 */
void solution_2_2()
{
	int i, lim, c;
	char s[10];
//	for (i = 0; i < lim - 1 && (c=getchar()) != '\n' && c != EOF; ++i) { s[i] = c; }
	for (i = 0; i < lim - 1; ++i) {
		if ((c=getchar()) != '\n') {
			if (c != EOF) {	s[i] = c; }
		}
	}
}


/*
 * htoi(s)
 */
int solution_2_3(char s[])
{
	int i, n;
	n = 0;
	for (i = 0; (s[i] == 'X') || (s[i] == 'x') || (s[i] >= '0' && s[i] <= '9')
				|| (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'); ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			if (i) {
				n = 16 * n + (s[i] - '0');
			}
		} else if (s[i] >= 'a' && s[i] <= 'f') {
			n = 16 * n + (s[i] - 'a' + 10);
		} else if (s[i] >= 'A' && s[i] <= 'F') {
			n = 16 * n + (s[i] - 'A' + 10);
		}
	}

	return n;
}


/*
 * squeeze(s1, s2)
 */
void solution_2_4(char s1[], char s2[])
{
	printf("Before\t: %s\n", s1);
	int i, j, k;
	for (i = j = 0; s1[i] != '\0'; ++i) {
		int flag = 0;
		for (k = 0; s2[k] != '\0'; ++k) {
			if (s1[i] == s2[k]) { flag = 1; }
		}
		if (!flag) {
			s1[j++] = s1[i];
		}
	}
	s1[j] = '\0';
	printf("After\t: %s\n", s1);
}


/*
 * strpbrk()
 */
int solution_2_5(char s1[], char s2[])
{
	printf("The first string\t: %s\n", s1);
	printf("The second string\t: %s\n", s2);

	int ret = -1;

	for (int i = 0; s1[i] != '\0'; ++i) {
		int flag = 0;
		for (int j = 0; s2[j] != '\0'; ++j) {
			if (s1[i] == s2[j]) {
				ret = i;
				flag = 1;
				break;
			}
		}
		if (flag) { return ret; }
	}

	return ret;
}


/*
 * setbits(x, p, n, y)
 */
unsigned solution_2_6(unsigned x, int p, int n, unsigned y)
{
	//取y最右边的n位并移至[p,p-1,...,p+1-n]位置
	unsigned ypn = (~(~0 << n) & y) << (p+1-n);
	//取x最右边的p+1-n位
	unsigned xrn = ~(~0 << p+1-n) & x;
	//将[p,p-1,...,p+1-n]和[p+1-n,p-n,...,0]合并
	unsigned xp = ypn ^ xrn;
	//将[p,p-1,...,0]的数据融合到x中
	x = (x & (~0 << (p+1))) ^ xp;

	return x;
}


/*
 * invert(x,p,n)
 */
unsigned solution_2_7(unsigned x, int p, int n)
{
	//取x最右边的p+1-n位
	unsigned xrn = ~(~0 << p+1-n) & x;
	//取x从右边数第p位往右n位
	unsigned xpn = (x >> (p+1-n)) & ~(~0 << n);
	xpn = (~xpn ^ (~0 << n)) << (p+1-n);
	//取x的第p位左边的数
	unsigned xlp = x & (~0 << (p+1));
	x = xlp ^ (xpn ^ xrn);

	return x;
}


/*
 * todo
 */
unsigned solution_2_8(unsigned x, int n)
{
	for (int i = 0; i < n; ++i) {
		unsigned mr = x & ~(~0 < 1);
		x >>= 1;
		;
	}
}


/*
 * bitcount()
 * todo
 */
int solution_2_9(unsigned x)
{
	int b;
	for (b = 0; x != 0; x >>= 1) {
		if (x & 01) {
			b++;
		}
	}

	return b;
}


/*
 * lower()
 */
char solution_2_10(char c)
{
	return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c;
}

