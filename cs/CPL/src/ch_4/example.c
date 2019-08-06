/*
 * src/ch_4/example.c
 *
 * 2019/2/16
 */

#include <stdio.h>
#include <ctype.h>


/*
 * 把字符串s转换为相应的双精度浮点数
 */
double atof(char s[]) {
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++) {
		;
	}
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') {
		i++;
	}
	for (val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.') {
		i++;
	}
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	return sign * val / power;
}


/*
 * 利用atof函数把字符串s转换为整数
 */
int atoi(char s[])
{
	double atof(char s[]);

	return (int)atof(s);
}


/*
 * 打印十进制数
 */
void printd(int n)
{
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / 10)
		printd(n / 10);
	putchar(n % 10 + '0');
}


/*
 * 递归实现快速排序法
 */
void qsort(int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j);

	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}


/*
 * 交换数组中的两元素值
 */
void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}


