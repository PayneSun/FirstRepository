/*
 * src/ch_3/sample.c
 *
 * 2019/2/15
 */

#include <stdio.h>
#include <ctype.h>


/*
 * 在升序数组v[0..n]中二分查找x并返回其位置
 */
int binsearch(int x, char v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}


/*
 * 统计数字、空白符及其他字符
 */
void statise(int ndigit[], int nwhite, int nother)
{
	for (int i = 0; i < 10; ++i)
		ndigit[i] = 0;

	int c;
	while ((c = getchar()) != -1) {
		switch (c) {
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				ndigit[c - '0']++;
				break;
			case ' ': case '\n': case '\t':
				nwhite++;
				break;
			default:
				nother++;
				break;
		}
	}
}


/*
 * 将字符串s转换为整型数；版本2
 */
int atoi(char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');

	return sign * n;
}


/*
 * 按递增顺序对v[0..n-1]进行排序
 */
void shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n / 2; gap > 0; gap /= 2) {
		for (i = gap; i < n; i++) {
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
		}
	}
}


/*
 * 倒置字符串s中各个字符的位置
 */
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s); i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


/*
 * 将数字n转换为字符串并保存到s中
 */
void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}


/*
 * 删除字符串尾部的空白符
 */
int trim(char s[])
{
	int n;

	for (n = strlen(s) - 1; n >= 0; --n)
		if (s[n] != ' ' || s[n] != '\t' || s[n] != '\n')
			break;
	s[n + 1] = '\0';
	return n;
}
